<?php
/**
* @package Isis
* @copyright Copyright (C) 2008 Kodeware. All rights reserved.
* @license http://www.gnu.org/copyleft/lgpl.html GNU/LGPL, see LICENSE.php
* This program is free software; you can redistribute it and/or modify it under 
* the terms of the GNU Lesser General Public License as published by the Free Software
* Foundation; either version 2 of the License, or (at your option) any later
* version.

* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

* You should have received a copy of the GNU Lesser General Public License along with
* this program; if not, write to the Free Software Foundation, Inc., 59 Temple
* Place - Suite 330, Boston, MA 02111-1307, USA, or go to
* http://www.gnu.org/copyleft/lesser.txt.
*/

defined( '_VALID_ISIS' ) or die( 'Direct Access to this location is not allowed.' );

include("classes/link.php");

function getOptionPortal($name, $id)
{
	$val = getOption("portals." . $id . "." . $name);
	if( ($val == null) || ($val == "") )
		$val = getOption("portals.default." . $name);
	return $val;
}

function getOptionPortalInt($name, $id)
{
	return (int) getOptionPortal($name, $id);
}

function getOptionPortalDouble($name, $id)
{
	return (double) getOptionPortal($name, $id);
}

function getOptionPortalBool($name, $id)
{
	return (getOptionPortal($name, $id) == "1");
}

function matchOptionPortal($name, $value, $id)
{
	$val = getOption("portals." . $id . "." . $name);
	if( ($val == null) || ($val == "") )
		$val = getOption("portals.default." . $name);
	return regex_match($val, $value);
}

function commonPeerChecks($id, $password)
{
	// Checking IP
	$ip = $_SERVER['REMOTE_ADDR'];
	$userAgent = $_SERVER['HTTP_USER_AGENT'];
	
	allowedValueList($ip, "ips.allowed", "ips.blocked", "IP");	
		
	allowedValueListEx($ip, getOptionPortal("isis.peers.ips.allowed", $id), getOptionPortal("isis.peers.ips.blocked", $id), "IP");
	
	if(matchOptionPortal("isis.peers.password", $password, $id) == false)
		throw new Exception("Invalid password.");
	
	allowedValueListEx($userAgent, getOptionPortal("isis.peers.version.allowed", $id), getOptionPortal("isis.peers.version.blocked", $id), "Version");	
}

function allowedPov($povId)
{
	if(validatePovID($povId) == false)
		throw new Exception("Invalid portal.");
		
	allowedValueList($povId, "portals.general.allowed", "portals.general.blocked", "Portal");
	
	ensurePortalDirs($povId, true);	
}

function allowedPortal($portal, $pov) // TOCLEAN
{	
	$povId = composePovId($portal, $pov);
		
	allowedPov($povId);
}

function ensurePortalDirs($povId, $fullCheck = false)
{
	$path_base = getOption("data.path");
	
	ensureDir($path_base, 0777);	
	
	$path_portal = $path_base . "/portal_" . $povId;
	
	if( ($fullCheck == false) && (file_exists($path_portal)) )
		return;
			
	ensureDir($path_portal, 0777);	
	
	ensureDir($path_portal . "/cache_info", 0777);
	ensureDir($path_portal . "/cache_data", 0777);
	ensureDir($path_portal . "/incomings", 0777);
	ensureDir($path_portal . "/requests_realtime", 0777);
	ensureDir($path_portal . "/requests_background", 0777);	
	ensureDir($path_portal . "/accepteds", 0777);
	ensureDir($path_portal . "/responses", 0777);	
	ensureDir($path_portal . "/nodes", 0777);		
}

function needAskToNode($povId, $lastModification, $lastCheck, $priority = "realtime")
{
	$now = time();
	
	$lastModification = (int) $lastModification;
	$lastCheck = (int) $lastCheck;
		
	$cacheForced = getOptionPortalInt("isis.cache." . $priority . ".forced", $povId);
	if( ($cacheForced != 0) && ( ($lastCheck + $cacheForced)>$now ) )
		return false;
		
	$currentDelta = ($lastCheck - $lastModification);
	$currentDelta *= getOptionPortalDouble("isis.cache." . $priority . ".deltaratio", $povId);
	
	$maxDelta = getOptionPortalInt("isis.cache." . $priority . ".deltamax", $povId);
	if( ($maxDelta != 0) && ($currentDelta>$maxDelta) )
		$currentDelta = $maxDelta;
	
	$nextCheck = $lastCheck + $currentDelta;
	
	if($nextCheck > $now)
		return false;
		
	return true;
}

function writeFileHeader($fh, $type)
{
	fwrite($fh, getOption("product.name") . "/" . getOption("product.version") . " " . $type . "\n");
}

function portalsList()
{
	$a = array();
	$path = getOption("data.path") . "/";	
	if ($dh = opendir($path))
	{			
		while (false !== ($file = readdir($dh))) 
		{
			if ($file != "." && $file != ".." && (substr($file,0,7) == "portal_") )
			{	
				$id = substr($file,7);
				$a[] = $id;
			}
		}
	}
	closedir($dh);
		
	return $a;
}

function portalFileList($povId, $type)
{
	$a = array();
	$path = getOption("data.path") . "/portal_" . $povId . "/" . $type;		
	if ($dh = opendir($path))
	{				
		while (false !== ($file = readdir($dh))) 
		{		
			if ($file != "." && $file != ".." && $file != "index.html" && $file != ".htaccess")
			{			
				$fullPath = $path . "/" . $file;
				$a[] = $fullPath;
			}
		}
	}
	closedir($dh);
	return $a;
}

function frameBox($title, $body)
{
	$output = "<fieldset><legend>" . $title . "</legend>";
	$output .= $body;
	$output .= "</fieldset>";
	return $output;
}

function getPortalNodesCount($povId)
{
	// Cleaning nodes zombie.
	// We need these because 'zombie' occur, for example if Apache is restarted: PHP execution was brutaly terminated, so che "request" part don't reach the deletion of file node.
	// We do this here to ensure a correct report visualization, indipendent of accuracy of the 'cron' procedure.
	// This cleaning are also done by a job "cleaning".
	
	$now = time();	
	$count = 0;
	
	$maxOld = getOptionDouble("tuning.request.timeout");
	
	foreach(portalFileList($povId, "nodes") as $file)
	{					
		$howOld = $now - filemtime($file);
					
		if($howOld > $maxOld)
			unlink($file);
		else
			$count++;
	}
	
	return $count;
}

function portalBox($id, $acpDetails = true)
{
	$class = "";
	
	$nNodes = getPortalNodesCount($id);
	
	$portalId = getOptionPortal("portal", $id);
	$povId = getOptionPortal("pov", $id);
		
	$name = getOptionPortal("isis.info.name", $id);		
	$titleName = $name;
	if($titleName == "")
		$titleName = "<no name>";
	
	/*	
	$description = getOptionPortal("isis.info.description", $id);
	$titleDescription = $description;
	if( ($acpDetails) && ($titleDescription == "") )
		$titleDescription = "<no description>";
	*/
	
	/*	
	$monarchist = ereg('.1..............................................',$portalId);
	$public = ereg('0...............................................',$portalId);
	$portalType = "";
	if($monarchist)
		$portalType .= "Monarchist";
	else
		$portalType .= "Anarchist";
	$portalType .= " , ";
	if($public)
		$portalType .= "Public";
	else
		$portalType .= "Private";
	*/
	$basePath = getOption("data.path") . "/portal_" . $id;	
	//$infoNodes = getDirectorySize($basePath . "/nodes/");
	$infoRequestsRealtime = getDirectorySize($basePath . "/requests_realtime/");
	$infoRequestsBackground = getDirectorySize($basePath . "/requests_background/");
		
	//$load = $infoNodes['count']-($infoRequestsRealtime['count']+$infoRequestsBackground['count']);
	$load = $nNodes-($infoRequestsRealtime['count']+$infoRequestsBackground['count']);
	
	$loadColor = iif($load>0,"green","red");
	
	$hidden = getOptionPortalBool("isis.info.hidden", $id);
	$closed = getOptionPortal("isis.closed_message", $id);
		
	$hrefView = getOption("server.virtual_path") . "?/portals/view?portal=" . $id;

	$actions = "";
	$acpActions = "";
	
	if($acpDetails)
	{	
		$hrefStatus = getPhpSelf() . "?page=status&portal=" . $id;
		$hrefSettings = getPhpSelf() . "?page=settings&group=portal&portal=" . $id;
		$hrefRemove = getPhpSelf() . "?page=status&act=remove&portal=" . $id;
		$hrefCacheClear = getPhpSelf() . "?page=status&act=cacheclear&portal=" . $id;
	
		$actions = "<a target=\"_blank\" href=\"" . htmlencode($hrefView) . "\">View in new tab</a>";
		
		$acpActions .= "<a href=\"" . htmlencode($hrefStatus) . "\">Status</a>";		
		$acpActions .= " | ";
		$acpActions .= "<a href=\"" . htmlencode($hrefSettings) . "\">Settings</a>";		
		$acpActions .= " | ";
		$acpActions .= "<a href=\"" . htmlencode($hrefRemove) . "\">Remove</a>";		
		$acpActions .= " | ";
		$acpActions .= "<a href=\"" . htmlencode($hrefCacheClear) . "\">Cache clear</a>";		
	}
	else
	{
		$actions = "<a href=\"" . htmlencode($hrefView) . "\">Enter</a>";
	}
	
	// Osiris subscription link
	// ex.
	// osiris://|portal|0000000197DCF94088CEFBC0D8EBB4995087EE65B4805589|name=Serverless%20News|description=Portale%20dedicato%20a%20notizie%20rilasciate%20sotto%20licenza%20Creative%20Commons|user=010000023CCB3260950B80505CBB062C0B9B65E7028BD53F|	
	
	$link = new Link();
	$link->setParam("type","portal");
	$link->setParam("portal",$portalId);
	$link->setParam("pov",$povId);	
	$link->setParam("name",$name);
	$link->setParam("description",$description);
	
	//$hrefOsirisSubscription = "osiris://|portal|" . urlencode($portalId) . "|name=" . urlencode($name) . "|description=" . urlencode($description) . "";
	
	$hrefOsirisSubscription = $link->export();
	
	$hrefOsirisSubscriptionWithIsis = "invitelink.php?url=" . urlencode($hrefOsirisSubscription);
	
	$actions .= " | ";
	$actions .= "<a href=\"" . htmlencode($hrefOsirisSubscriptionWithIsis) . "\">Subscribe with Osiris</a>";
	
	// Isis subscription link
	// ex.
	// http://isisdev.kodeware.net/invitelink.php?url=osiris://|isis|0000000197DCF94088CEFBC0D8EBB4995087EE65B4805589|name=Isis%20Dev|url=http://isisdev.kodeware.net/|
	$isisVisible = true;
	$customPassword = (getOptionPortal("isis.peers.password", $id) != ".*");
	if($customPassword) // If password are set, link are visible only from acp.
		$isisVisible = $acpDetails;
	if($isisVisible)
	{
		$isisUrl = getOption("server.virtual_path");		
		//$hrefIsisSubscription = "osiris://|isis|" . urlencode($portalId) . "|name=" . urlencode(getOption("server.name")) . "|url=" . urlencode($isisUrl);		
		//$hrefIsisSubscription .= "|";
		$link = new Link();
		$link->setParam("type","isis");
		$link->setParam("portal",$portalId);
		$link->setParam("pov",$povId);	
		$link->setParam("name",getOption("server.name"));
		$link->setParam("url",$isisUrl);
		$hrefIsisSubscription = $link->export();
		
		$hrefIsisSubscriptionWithIsis = "invitelink.php?url=" . urlencode($hrefIsisSubscription);
		
		$actions .= " | ";
		$actions .= "<a href=\"" . htmlencode($hrefIsisSubscriptionWithIsis) . "\">Subscribe to this Isis with Osiris</a>";
		if($customPassword)
			$actions .= "<i> (Warning: password need but not included.)</i>";
		// Password are not included, because in settings we have a regular expression to check multiple passwords.		
	}
	
	$html = "";
	
	$html .= "<div style=\"float:right;\">";
	$html .= "Load: <span style=\"color:" . $loadColor . "\"><b>" . $load . "</b></span><br />";
	$html .= "Waiting nodes: <b>" . $nNodes . "</b><br />";
	$html .= "Waiting requests: <b>" . $infoRequestsRealtime['count'] . "</b> realtime, <b>" . $infoRequestsBackground['count'] . "</b> background.<br />";
	
	if($acpDetails)
	{
		$infoCacheData = getDirectorySize($basePath . "/cache_data/");
		$html .= "Cache: <b>" . convertBytesToString($infoCacheData['size']) . "</b>";
		if(getOptionPortalBool("isis.cache.enabled", $id) == false)
			$html .= " - Not enabled.";
		
		$html .= "<br />Hidden: <b>" . iif($hidden,"true","false") . "</b>";
		
		if($closed != "")
		{
			$class .= " is_portalbox_closed";
			$html .= "<br />Closed: <b><span style=\"color:#AA0000\">" . htmlencode($closed) . "</span></b>";
		}
	}
	$html .= "</div>";
			
	$html .= "<span style=\"font-size:1.3em;font-weight:bold;\">" . htmlencode($titleName) . "</span><br />";
	//$html .= htmlencode($titleDescription) . "<br />";	
	//$html .= "<span style=\"font-size: 0.8em;color:gray;\"><b>" . $portalType . "</b> , Portal ID: <b>" . htmlencode($portalId) . "</b> , Pov ID: <b>" . htmlencode($povId) . "</b></span><br />";
	$html .= "<span style=\"font-size: 0.8em;color:gray;\">Portal ID: <b>" . htmlencode($portalId) . "</b> , Pov ID: <b>" . htmlencode($povId) . "</b></span><br />";
	if($acpDetails)
	{
		$acpNotes = getOptionPortal("isis.info.acp.notes", $id);
		if($acpNotes != "")
			$html .= "<span style=\"color: #DD8800\">" . htmlencode($acpNotes) . "</span><br />";
	}
		
	$html .= "<div style=\"margin:5px;float:left;\">";
	$html .= $actions;
	if($acpActions != "")
		$html .= "<br />" . $acpActions;
	$html .= "</div>";

	if($hidden)
		$class .= " is_portalbox_hidden";	
	if($closed != "")
		$class .= " is_portalbox_closed";
	
	echo dataBox("portal",$html,$class);
}

function cleaningZombieNodes()
{
	
}

function validatePovID($id)
{
	$portal = substr($id,0,40);
	$pov = substr($id,41);
	
	if(validateID($portal) == false)
		return false;
	if(validateID($pov) == false)
		return false;
	
	return true;	
}

function composePovId($portal, $pov)
{
	return $portal . "_" . $pov;
	//return hash("sha1",$portal . $user);
}

function pasteLinks($pasteLinks)
{
	$linksA = array_filter(explode("\r", $pasteLinks));
	foreach($linksA as $link)
	{			
		$link2 = trim($link);			
		if($link2 != "")
		{			
			//$params = osirisLinkParser($link2);
			
			// Detect if is a Isis http link
			if(strpos($link2,"invitelink.php") !== false)
			{
				$link2 = urldecode(substr($link2,4+strpos($link2,"url=")));
			}
						
			$l = new Link($link2);
			
			if( ($l->getParam("type") == "portal") || ($l->getParam("type") == "isis") )
			{
				$portal = $l->getParam("portal");
				$pov = $l->getParam("pov");
				
				$id = composePovId($portal, $pov);
				
				// Checking portal
				allowedPortal($portal, $pov);
				
				if($l->hasParam("name"))
					setOption("portals." . $id . ".isis.info.name", $l->getParam("name"));
				if($l->hasParam("description"))
					setOption("portals." . $id . ".isis.info.description", $l->getParam("description"));				
					
				setOption("portals." . $id . ".portal", $portal);
				setOption("portals." . $id . ".pov", $pov);
	
				settingsSave();
				
				message("info","Portal Imported: " . $l->getParam("name"));
			}
			else
			{
				message("error","Invalid link: " . $link2);
			}
		}				
	}
}

function generateSeoRules() // TODO: sotto in saveSettings, pulire e chiamare questa. Chiamare questa da ACP per nginx.
{
	$format = "nginx";
	
	$output = "";
	
	$output .= "# Generated by Isis ACP\r\n\r\n";
	if($format == "htaccess")
	{
		$output .= "Options +FollowSymLinks\r\n";
		$output .= "RewriteEngine on\r\n";
	}
	
	$output .= "\r\n# Service Link List\r\n";
	$list = getOption("services.link.list");
	$lines = multilineFillArray($list);
	foreach($lines as $line)
	{			
		$values = explode(" ", $line);
					
		$key = trim($values[0]);
		$dest = trim(urldecode($values[1]));
		
		$flags = "";
		if(isset($values[2]))
			$flags = trim($values[2]);
		
		if(strpos($flags,"S"))
			$output .= "RewriteRule ^" . $key . iif($key != "","\/","") . "$ " . $dest . " [NC]\r\n";
	}
	
	$output .= "\r\n# Portals aliases\r\n";
	foreach(portalsList() as $portal)
	{
		$alias = getOptionPortal("isis.info.alias", $portal);
		if($alias != "")
			$output .= "RewriteRule ^portals\/" . strtolower($alias) . "\/(.*?)$ " . $seoPath . "portals/" . $portal . "/$1 [NC]\r\n";
	}
	
	if(getOption("services.link.seo.home_portal") != "")
	{
		$output .= "\r\n# General SEO for portal " . getOption("services.link.seo.home_portal") . "\r\n";			
		$output .= "RewriteRule ^$ " . getCurrentHttpPath(true) . "?/portals/view?portal=" . getOption("services.link.seo.home_portal") . " [NC]\r\n";
		$output .= "RewriteRule ^([a-zA-Z0-9]{48,48}?)\/$ " . getCurrentHttpPath(true) . "?/portals/view?id=$1&portal=" . getOption("services.link.seo.home_portal") . " [NC]\r\n";
		$output .= "RewriteRule ^resources\/([a-zA-Z0-9]{48,48}?)\/$ " . getCurrentHttpPath(true) . "?/main/resources?file=$1&portal=" . getOption("services.link.seo.home_portal") . " [NC]\r\n";
		$output .= "RewriteRule ^users\/([a-zA-Z0-9]{48,48}?)\/$ " . getCurrentHttpPath(true) . "?/portals/user?id=$1&portal=" . getOption("services.link.seo.home_portal") . " [NC]\r\n";
		$output .= "RewriteRule ^(users|changes|latest_discussions|search|edit|about)\/$ " . getCurrentHttpPath(true) . "?/portals/$1?portal=" . getOption("services.link.seo.home_portal") . " [NC]\r\n";
		$output .= "RewriteRule ^htdocs\/(.*?)$ " . getCurrentHttpPath(true) . "?/htdocs/$1?portal=" . getOption("services.link.seo.home_portal") . " [NC]\r\n";
		
		// Commented, for issue with CSS
		//fwrite($fhtaccess, "RewriteRule ^htdocs\/(.*?)$ /isis/?/htdocs/$1?portal=" . getOption("services.link.seo.home_portal") . " [NC]\r\n");
	}
	$output .= "\r\n# General SEO\r\n";
	$output .= "RewriteRule ^portals\/$ " . getCurrentHttpPath(true) . "/home.php [NC]\r\n";
	$output .= "RewriteRule ^portals\/([a-zA-Z0-9]{48,48}?)\/$ " . getCurrentHttpPath(true) . "?/portals/view?portal=$1 [NC]\r\n";
	$output .= "RewriteRule ^portals\/([a-zA-Z0-9]{48,48}?)\/([a-zA-Z0-9]{48,48}?)\/$ " . getCurrentHttpPath(true) . "?/portals/view?id=$2&portal=$1 [NC]\r\n";
	$output .= "RewriteRule ^portals\/([a-zA-Z0-9]{48,48}?)\/resources\/([a-zA-Z0-9]{48,48}?)\/$ " . getCurrentHttpPath(true) . "?/main/resources?file=$2&portal=$1 [NC]\r\n";
	$output .= "RewriteRule ^portals\/([a-zA-Z0-9]{48,48}?)\/users\/([a-zA-Z0-9]{48,48}?)\/$ " . getCurrentHttpPath(true) . "?/portals/user?id=$2&portal=$1 [NC]\r\n";
	$output .= "RewriteRule ^portals\/([a-zA-Z0-9]{48,48}?)\/(users|changes|latest_discussions|search|edit|about)\/$ " . getCurrentHttpPath(true) . "?/portals/$2?portal=$1 [NC]\r\n";
	$output .= "RewriteRule ^portals\/([a-zA-Z0-9]{48,48}?)\/htdocs\/(.*?)$ " . getCurrentHttpPath(true) . "?/htdocs/$2?portal=$1 [NC]\r\n";
	
	// Commented, for issue with CSS
	//fwrite($fhtaccess, "RewriteRule ^([A-Z0-9]*?)\/htdocs\/(.*?)$ /isis/?/htdocs/$2?portal=$1 [NC]\r\n");
	
	$output .= "\r\n# General redirect, if the page name it's written without final slash.\r\n";
	$output .= "RewriteRule ^([a-zA-Z0-9_]+?)$ " . $seoPath . "$1/ [R=301]\r\n";
	if(getOption("services.link.seo.home_portal") != "")		{			
		
		$output .= "RewriteRule ^resources\/([a-zA-Z0-9]{48,48}?)$ " . $seoPath . "resources/$1/ [R=301]\r\n";
		$output .= "RewriteRule ^users\/([a-zA-Z0-9]{48,48}?)$ " . $seoPath . "users/$1/ [R=301]\r\n";
		$output .= "RewriteRule ^(users|changes|latest_discussions|search|edit|about)$ " . $seoPath . "$1/ [R=301]\r\n";
		$output .= "\r\n";
	}
	
	$output .= "RewriteRule ^portals$ " . $seoPath . "portals/ [R=301]\r\n";
	$output .= "RewriteRule ^portals\/([a-zA-Z0-9_]+?)$ " . $seoPath . "portals/$1/ [R=301]\r\n";
	$output .= "RewriteRule ^portals\/([a-zA-Z0-9]{48,48}?)$ " . $seoPath . "portals/$1/ [R=301]\r\n";
	$output .= "RewriteRule ^portals\/([a-zA-Z0-9]{48,48}?)\/([a-zA-Z0-9]{48,48}?)$ " . $seoPath . "portals/$1/$2/ [R=301]\r\n";
	$output .= "RewriteRule ^portals\/([a-zA-Z0-9]{48,48}?)\/resources\/([a-zA-Z0-9]{48,48}?)$ " . $seoPath . "portals/$1/resources/$2/ [R=301]\r\n";
	$output .= "RewriteRule ^portals\/([a-zA-Z0-9]{48,48}?)\/users\/([a-zA-Z0-9]{48,48}?)$ " . $seoPath . "portals/$1/users/$1/ [R=301]\r\n";
	$output .= "RewriteRule ^portals\/([a-zA-Z0-9]{48,48}?)\/(users|changes|latest_discussions|search|edit|about)$ " . $seoPath . "portals/$1/$2/ [R=301]\r\n";
	
	
	$output .= "\r\n# Compatibility rules (with Isis 0.11)\r\n";
	$output .= "RewriteRule ^view\/([a-zA-Z0-9]{48,48}?)\/$ /$1/ [R=301]\r\n";
	$output .= "RewriteRule ^([a-zA-Z0-9]{48,48}?)\/view\/([A-Z0-9]*?)\/$ /portals/$1/$2/ [R=301]\r\n";
	$output .= "RewriteRule ^([a-zA-Z0-9]{48,48}?)\/resources\/([A-Z0-9]*?)\/$ /portals/$1/resources/$2/ [R=301]\r\n";
	
	$output .= "\r\n# Compatibility rules (with Isis 0.11) - General redirect, if the page name it's written without final slash.\r\n";
	$output .= "RewriteRule ^view\/([a-zA-Z0-9]{48,48}?)$ /$1/ [R=301]\r\n";
	$output .= "RewriteRule ^([a-zA-Z0-9]{48,48}?)\/view\/([A-Z0-9]*?)$ /portals/$1/$2/ [R=301]\r\n";
	$output .= "RewriteRule ^([a-zA-Z0-9]{48,48}?)\/resources\/([A-Z0-9]*?)$ /portals/$1/resources/$2/ [R=301]\r\n";
	
	
	if($format == "nginx")
	{
		$output = str_replace("RewriteRule ^", "rewrite \"^/", $output);
		$output = str_replace("$ ", "$\" ", $output);
		$output = str_replace("[NC]", "break;", $output);
		$output = str_replace("[R=301]", "permanent;", $output);
	}	
	
	return $output;
}

function settingsSave()
{
	global $OPTIONS;
	
	//trace($OPTIONS);
	
	setOption("settings.last_modification", time());
	
	// robots.txt generation
	$fh = fopen("robots.txt", 'w');
	fwrite($fh, "User-agent: *\r\n");
	if(getOptionBool("robots.enabled"))
	{
		fwrite($fh, "Disallow: \r\n");		
	}
	else
	{
		fwrite($fh, "Disallow: /\r\n");				
	}
	fclose($fh);
	
	// SEO generation
	if(getOptionBool("services.link.seo.enabled"))
	{
		$seoPath = getOption("services.link.seo.path");
		
		$fhtaccess = fopen(getOption("services.link.seo.htaccess") . ".htaccess", 'w');
		fwrite($fhtaccess, "# Generated by Isis ACP\r\n\r\n");
		fwrite($fhtaccess, "Options +FollowSymLinks\r\n");
		fwrite($fhtaccess, "RewriteEngine on\r\n");
		
		fwrite($fhtaccess, "\r\n# Service Link List\r\n");
		$list = getOption("services.link.list");
		$lines = multilineFillArray($list);
		foreach($lines as $line)
		{
			$values = explode(" ", $line);
			
			$key = trim($values[0]);
			$dest = trim(urldecode($values[1]));
			$flags = "";
			if(isset($values[2]))
			$flags = trim($values[2]);
			
			if(strpos($flags,"S"))
				fwrite($fhtaccess, "RewriteRule ^" . $key . iif($key != "","\/","") . "$ " . $dest . " [NC]\r\n");
		}
		
		fwrite($fhtaccess, "\r\n# Portals aliases\r\n");
		foreach(portalsList() as $portal)
		{
			$alias = getOptionPortal("isis.info.alias", $portal);
			if($alias != "")
				fwrite($fhtaccess, "RewriteRule ^portals\/" . strtolower($alias) . "\/(.*?)$ " . $seoPath . "portals/" . $portal . "/$1 [NC]\r\n");
		}
		
		if(getOption("services.link.seo.home_portal") != "")
		{
			fwrite($fhtaccess, "\r\n# General SEO for portal " . getOption("services.link.seo.home_portal") . "\r\n");			
			fwrite($fhtaccess, "RewriteRule ^$ " . getCurrentHttpPath(true) . "?/portals/view?portal=" . getOption("services.link.seo.home_portal") . " [NC]\r\n");
			fwrite($fhtaccess, "RewriteRule ^([a-zA-Z0-9]{48,48}?)\/$ " . getCurrentHttpPath(true) . "?/portals/view?id=$1&portal=" . getOption("services.link.seo.home_portal") . " [NC]\r\n");
			fwrite($fhtaccess, "RewriteRule ^resources\/([a-zA-Z0-9]{48,48}?)\/$ " . getCurrentHttpPath(true) . "?/main/resources?file=$1&portal=" . getOption("services.link.seo.home_portal") . " [NC]\r\n");
			fwrite($fhtaccess, "RewriteRule ^users\/([a-zA-Z0-9]{48,48}?)\/$ " . getCurrentHttpPath(true) . "?/portals/user?id=$1&portal=" . getOption("services.link.seo.home_portal") . " [NC]\r\n");
			fwrite($fhtaccess, "RewriteRule ^(users|changes|latest_discussions|search|edit|about)\/$ " . getCurrentHttpPath(true) . "?/portals/$1?portal=" . getOption("services.link.seo.home_portal") . " [NC]\r\n");
			fwrite($fhtaccess, "RewriteRule ^htdocs\/(.*?)$ " . getCurrentHttpPath(true) . "?/htdocs/$1?portal=" . getOption("services.link.seo.home_portal") . " [NC]\r\n");
			
			// Commented, for issue with CSS
			//fwrite($fhtaccess, "RewriteRule ^htdocs\/(.*?)$ /isis/?/htdocs/$1?portal=" . getOption("services.link.seo.home_portal") . " [NC]\r\n");
		}
		fwrite($fhtaccess, "\r\n# General SEO\r\n");
		fwrite($fhtaccess, "RewriteRule ^portals\/$ " . getCurrentHttpPath(true) . "/home.php [NC]\r\n");
		fwrite($fhtaccess, "RewriteRule ^portals\/([a-zA-Z0-9]{48,48}?)\/$ " . getCurrentHttpPath(true) . "?/portals/view?portal=$1 [NC]\r\n");
		fwrite($fhtaccess, "RewriteRule ^portals\/([a-zA-Z0-9]{48,48}?)\/([a-zA-Z0-9]{48,48}?)\/$ " . getCurrentHttpPath(true) . "?/portals/view?id=$2&portal=$1 [NC]\r\n");
		fwrite($fhtaccess, "RewriteRule ^portals\/([a-zA-Z0-9]{48,48}?)\/resources\/([a-zA-Z0-9]{48,48}?)\/$ " . getCurrentHttpPath(true) . "?/main/resources?file=$2&portal=$1 [NC]\r\n");
		fwrite($fhtaccess, "RewriteRule ^portals\/([a-zA-Z0-9]{48,48}?)\/users\/([a-zA-Z0-9]{48,48}?)\/$ " . getCurrentHttpPath(true) . "?/portals/user?id=$2&portal=$1 [NC]\r\n");
		fwrite($fhtaccess, "RewriteRule ^portals\/([a-zA-Z0-9]{48,48}?)\/(users|changes|latest_discussions|search|edit|about)\/$ " . getCurrentHttpPath(true) . "?/portals/$2?portal=$1 [NC]\r\n");
		fwrite($fhtaccess, "RewriteRule ^portals\/([a-zA-Z0-9]{48,48}?)\/htdocs\/(.*?)$ " . getCurrentHttpPath(true) . "?/htdocs/$2?portal=$1 [NC]\r\n");
		
		// Commented, for issue with CSS
		//fwrite($fhtaccess, "RewriteRule ^([A-Z0-9]*?)\/htdocs\/(.*?)$ /isis/?/htdocs/$2?portal=$1 [NC]\r\n");
		
		fwrite($fhtaccess, "\r\n# General redirect, if the page name it's written without final slash.\r\n");
		fwrite($fhtaccess, "RewriteRule ^([a-zA-Z0-9_]+?)$ " . $seoPath . "$1/ [R=301]\r\n");
		if(getOption("services.link.seo.home_portal") != "")		{			
			
			fwrite($fhtaccess, "RewriteRule ^resources\/([a-zA-Z0-9]{48,48}?)$ " . $seoPath . "resources/$1/ [R=301]\r\n");
			fwrite($fhtaccess, "RewriteRule ^users\/([a-zA-Z0-9]{48,48}?)$ " . $seoPath . "users/$1/ [R=301]\r\n");
			fwrite($fhtaccess, "RewriteRule ^(users|changes|latest_discussions|search|edit|about)$ " . $seoPath . "$1/ [R=301]\r\n");
			fwrite($fhtaccess, "\r\n");
		}
		
		fwrite($fhtaccess, "RewriteRule ^portals$ " . $seoPath . "portals/ [R=301]\r\n");
		fwrite($fhtaccess, "RewriteRule ^portals\/([a-zA-Z0-9_]+?)$ " . $seoPath . "portals/$1/ [R=301]\r\n");
		fwrite($fhtaccess, "RewriteRule ^portals\/([a-zA-Z0-9]{48,48}?)$ " . $seoPath . "portals/$1/ [R=301]\r\n");
		fwrite($fhtaccess, "RewriteRule ^portals\/([a-zA-Z0-9]{48,48}?)\/([a-zA-Z0-9]{48,48}?)$ " . $seoPath . "portals/$1/$2/ [R=301]\r\n");
		fwrite($fhtaccess, "RewriteRule ^portals\/([a-zA-Z0-9]{48,48}?)\/resources\/([a-zA-Z0-9]{48,48}?)$ " . $seoPath . "portals/$1/resources/$2/ [R=301]\r\n");
		fwrite($fhtaccess, "RewriteRule ^portals\/([a-zA-Z0-9]{48,48}?)\/users\/([a-zA-Z0-9]{48,48}?)$ " . $seoPath . "portals/$1/users/$1/ [R=301]\r\n");
		fwrite($fhtaccess, "RewriteRule ^portals\/([a-zA-Z0-9]{48,48}?)\/(users|changes|latest_discussions|search|edit|about)$ " . $seoPath . "portals/$1/$2/ [R=301]\r\n");
		
		
		fwrite($fhtaccess, "\r\n# Compatibility rules (with Isis 0.11)\r\n");
		fwrite($fhtaccess, "RewriteRule ^view\/([a-zA-Z0-9]{48,48}?)\/$ /$1/ [R=301]\r\n");
		fwrite($fhtaccess, "RewriteRule ^([a-zA-Z0-9]{48,48}?)\/view\/([A-Z0-9]*?)\/$ /portals/$1/$2/ [R=301]\r\n");
		fwrite($fhtaccess, "RewriteRule ^([a-zA-Z0-9]{48,48}?)\/resources\/([A-Z0-9]*?)\/$ /portals/$1/resources/$2/ [R=301]\r\n");
		
		fwrite($fhtaccess, "\r\n# Compatibility rules (with Isis 0.11) - General redirect, if the page name it's written without final slash.\r\n");
		fwrite($fhtaccess, "RewriteRule ^view\/([a-zA-Z0-9]{48,48}?)$ /$1/ [R=301]\r\n");
		fwrite($fhtaccess, "RewriteRule ^([a-zA-Z0-9]{48,48}?)\/view\/([A-Z0-9]*?)$ /portals/$1/$2/ [R=301]\r\n");
		fwrite($fhtaccess, "RewriteRule ^([a-zA-Z0-9]{48,48}?)\/resources\/([A-Z0-9]*?)$ /portals/$1/resources/$2/ [R=301]\r\n");
		
		fclose($fhtaccess);
	}
	else
	{		
		if(file_exists(getOption("services.link.seo.htaccess") . ".htaccess"))
			unlink(getOption("services.link.seo.htaccess") . ".htaccess");
	}
		
	// configuration.php generation
	$fh = fopen("configuration.php", 'w');
	fwrite($fh, "<?php \r\n");
	fwrite($fh, "// This file was automatically generated by Isis ACP. We reccomand to not modify it manually.\r\n");
	fwrite($fh, "defined( '_VALID_ISIS' ) or die( 'Direct Access to this location is not allowed.' );\r\n");
	fwrite($fh, "\r\n");
	
	foreach ($OPTIONS as $option) 
	{		
		//trace($option);
		$key = $option["name"];
		$value = $option["value"];
		$type = $option["type"];
		$custom = $option["custom"];
		$default = $option["default"];		
		
		$skip = false;
		
		// If is a portal settings, ensure that portal still exists.
		if(strpos($key, "portals.") === 0)
		{			
			$posDot = strpos($key, ".", 8);
			if($posDot > 0)
			{
				$portal = substr($key, 8,$posDot-8);
				
				if($portal == "general")
				{
				}
				else if($portal == "default")
				{
				}
				else
				{			
					$exists = file_exists(getOption("data.path") . "/portal_" . $portal . "/");
				
					if($exists == false)
						$skip = true;
				}
			}
		}
		
		if( ($skip == false) && ($custom == true)	)
		{				
			$value2 = null;
			if($type == "string")
			{
				$value2 = "\"" . str_replace("\"", "\\\"", str_replace("\\","\\\\",$value)) . "\"";			
			}
			else if($type == "integer")
			{				
				$value2 = $value;
			}
			else if($type == "double")
			{				
				$value2 = $value;
			}
			else if($type == "boolean")
			{
				$value2 = ($value==1) ? "true" : "false";
			}
			
			$value2 = str_replace("\n","\\n", $value2);
			$value2 = str_replace("\r","\\r", $value2);
			
			if(is_null($value2) == false)
			{
				//echo "save - " . $key . "=" . $value2 . " / " . "<br />";
				fwrite($fh, "setOption(\"" . $key . "\", " . $value2 . ");\r\n");
			}
		}
		
	}
	fwrite($fh, "?>");
	fclose($fh);	
	
	ensureDir(getOption("data.path"));	
	ensureDir(getOption("data.path") . "/logs");	
	
	logMessage("info", "Settings saved.");
}

?>