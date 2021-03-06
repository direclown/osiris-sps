<?xml version='1.0' encoding='utf-8'?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" 
                xmlns:lang="http://www.osiris-sps.org/xsl/lang" 
                xmlns:date="http://www.osiris-sps.org/xsl/date" 
                xmlns:system="http://www.osiris-sps.org/xsl/system" 
                xmlns:os="http://www.osiris-sps.org/xhtml/os"
                exclude-result-prefixes="lang date system os"
                version="1.0">

  <xsl:import href="http://www.osiris-sps.org/htdocs/templates/includes/actions.xsl"/>
  <xsl:import href="http://www.osiris-sps.org/htdocs/templates/includes/common.xsl"/>
  <xsl:import href="http://www.osiris-sps.org/htdocs/templates/includes/block.xsl"/>
  <xsl:import href="http://www.osiris-sps.org/htdocs/templates/includes/help.xsl"/>
  
  <xsl:output method="html" indent="yes" omit-xml-declaration="yes"/>

  <xsl:param name="saveCommand"/>

  <xsl:param name="portalName"/>
  <xsl:param name="portalDescription"/>
	<xsl:param name="authorsReputationThreshold"/>
	<xsl:param name="editorsReputationThreshold"/>
	<xsl:param name="povWhiteList"/>
	<xsl:param name="povBlackList"/>

	<xsl:param name="registerTerms"/>
	
	<xsl:param name="layoutComponent"/>
	<xsl:param name="layoutTileImage"/>
	<xsl:param name="layoutTileColorBackground"/>
	<xsl:param name="layoutTileColorForeground"/>
	<xsl:param name="layoutSkinParams"/>
  <xsl:param name="layoutCss"/>
  <xsl:param name="layoutHeader"/>

  <xsl:param name="objectsMaxSize"/>
  <xsl:param name="badWords"/>

  <xsl:param name="allowObjectInFuture"/>
  <xsl:param name="allowObjectUnsigned"/>
  <xsl:param name="objectsPhysicalRemove"/>
  <xsl:param name="objectsPhysicalRemoveDays"/>
  

  
  <xsl:template match="/home">
    <xsl:call-template name="block_big">
      <xsl:with-param name="title" select="lang:text('portal.pages.acp.title')"/>        			
      <xsl:with-param name="content">


				<xsl:if test="//@isUserOfPov = 'false'">					
					<xsl:call-template name="help-box">
						<xsl:with-param name="text" select="lang:text('portal.pages.acp.cannot_edit.help')"/>
					</xsl:call-template>
				</xsl:if>
				
        <xsl:if test="//@isUserOfPov = 'true'">
          <div class="os_commands_right">
            <xsl:value-of select="$saveCommand" disable-output-escaping="yes"/>
          </div>
        </xsl:if>
								

        <div style="clear:both;display:none" data-os-otype="tab" data-os-layout="left" data-os-storage="portal.acp">
					<div data-os-place="below-tabs" style="padding-top:3em;width:400px;">						
						<xsl:call-template name="action-row">
							<xsl:with-param name="prefix" select="'portal.pages'"/>
							<xsl:with-param name="name" select="'stabilization_stats'"/>
							<xsl:with-param name="icon" select="'stats'"/>
							<xsl:with-param name="href" select="@stabilization_stats_href"/>
						</xsl:call-template>
						<xsl:call-template name="action-row">
							<xsl:with-param name="prefix" select="'portal.pages'"/>
							<xsl:with-param name="name" select="'trash'"/>
							<xsl:with-param name="icon" select="'trash'"/>
							<xsl:with-param name="href" select="@trash_href"/>
						</xsl:call-template>
					</div>
					<div data-os-tabType="header">
            <xsl:value-of select="lang:text('portal.pages.acp.main')"/>
          </div>
          <div data-os-tabType="body">
            <table class="os_table_properties">              
              <tr>
                <td>
                  <xsl:value-of select="lang:text('portal.pages.acp.options.portalName')"/>
                  <xsl:text> :</xsl:text>
                </td>
                <td>
                  <xsl:value-of select="$portalName" disable-output-escaping="yes"/>
                </td>
              </tr>
              <tr>
                <td>
                  <xsl:value-of select="lang:text('portal.pages.acp.options.portalDescription')"/>
                  <xsl:text> :</xsl:text>
                </td>
                <td>
                  <xsl:value-of select="$portalDescription" disable-output-escaping="yes"/>
                </td>
              </tr>
              

            </table>

            
          </div>

          <div data-os-tabType="header">
            <xsl:value-of select="lang:text('portal.pages.acp.layout')"/>
          </div>
          <div data-os-tabType="body">
            <table class="os_table_properties">
              <tr>
                <td>
                  <xsl:value-of select="lang:text('portal.pages.acp.options.layoutComponent')"/>
                  <xsl:text> :</xsl:text>
                </td>
                <td>
                  <xsl:value-of select="$layoutComponent" disable-output-escaping="yes"/>
                </td>
              </tr>
							<!--
              <tr>
                <td>
                  <xsl:value-of select="'registerTerms'"/>
                  <xsl:text> :</xsl:text>
                </td>
                <td>
                  <xsl:value-of select="$registerTerms" disable-output-escaping="yes"/>
                </td>
              </tr>
							-->
              <tr>
                <td>
                  <xsl:value-of select="lang:text('portal.pages.acp.options.layoutSkinParams')"/>
                  <xsl:text> :</xsl:text>
                </td>
                <td>
                  <xsl:value-of select="$layoutSkinParams" disable-output-escaping="yes"/>
                </td>
              </tr>
							<tr>
								<td>
									<xsl:value-of select="lang:text('portal.pages.acp.options.tile')"/>
									<xsl:text> :</xsl:text>
								</td>
								<td>
									<xsl:value-of select="$layoutTileImage" disable-output-escaping="yes"/>
									<br/>
									BG: <xsl:value-of select="$layoutTileColorBackground" disable-output-escaping="yes"/>
									FG: <xsl:value-of select="$layoutTileColorForeground" disable-output-escaping="yes"/>									
								</td>
							</tr>
              <tr>
                <td>
                  <xsl:value-of select="lang:text('portal.pages.acp.options.layoutCss')"/>
                  <xsl:text> :</xsl:text>
                </td>
                <td>
                  <xsl:value-of select="$layoutCss" disable-output-escaping="yes"/>
                </td>
              </tr>
              <tr>
                <td>
                  <xsl:value-of select="lang:text('portal.pages.acp.options.layoutHeader')"/>
                  <xsl:text> :</xsl:text>
                </td>
                <td>
                  <xsl:value-of select="$layoutHeader" disable-output-escaping="yes"/>
                </td>
              </tr>
            </table>
          </div>

          <div data-os-tabType="header">
            <xsl:value-of select="lang:text('portal.pages.acp.rules')"/>
          </div>
          <div data-os-tabType="body">
            <table class="os_table_properties">
							
							<tr>
								<td>
									<xsl:value-of select="lang:text('portal.pages.acp.options.authorsReputationThreshold')"/>
									<xsl:text> :</xsl:text>
								</td>
								<td>
									<xsl:value-of select="$authorsReputationThreshold" disable-output-escaping="yes"/>
								</td>
							</tr>
							<tr>
								<td>
									<xsl:value-of select="lang:text('portal.pages.acp.options.editorsReputationThreshold')"/>
									<xsl:text> :</xsl:text>
								</td>
								<td>
									<xsl:value-of select="$editorsReputationThreshold" disable-output-escaping="yes"/>
								</td>
							</tr>
							<tr>
								<td>
									<xsl:value-of select="lang:text('portal.pages.acp.options.povWhiteList')"/>
									<xsl:text> :</xsl:text>
								</td>
								<td>
									<xsl:value-of select="$povWhiteList" disable-output-escaping="yes"/>
								</td>
							</tr>
							<tr>
								<td>
									<xsl:value-of select="lang:text('portal.pages.acp.options.povBlackList')"/>
									<xsl:text> :</xsl:text>
								</td>
								<td>
									<xsl:value-of select="$povBlackList" disable-output-escaping="yes"/>
								</td>
							</tr>
							<tr>
                <td>
                  <xsl:value-of select="lang:text('portal.pages.acp.options.objectsMaxSize')"/>
                  <xsl:text> :</xsl:text>
                </td>
                <td>
                  <xsl:value-of select="$objectsMaxSize" disable-output-escaping="yes"/>
                </td>
              </tr>              
              <tr>
                <td>
                  <xsl:value-of select="lang:text('portal.pages.acp.options.badWords')"/>
                  <xsl:text> :</xsl:text>
                </td>
                <td>
                  <xsl:value-of select="$badWords" disable-output-escaping="yes"/>
                </td>
              </tr>
            </table>
          </div>

          <!-- rules_ex : Rules dedicated to beta-tester or experience users. Defaults for most common use are ok. -->
          <div data-os-tabType="header">
            <xsl:value-of select="lang:text('portal.pages.acp.rules_ex')"/>
          </div>
          <div data-os-tabType="body">
            <table class="os_table_properties">
              <tr>
                <td>
                  <xsl:value-of select="lang:text('portal.pages.acp.options.allowObjectInFuture')"/>
                  <xsl:text> :</xsl:text>
                </td>
                <td>
                  <xsl:value-of select="$allowObjectInFuture" disable-output-escaping="yes"/>
                </td>
              </tr>
              <tr>
                <td>
                  <xsl:value-of select="lang:text('portal.pages.acp.options.allowObjectUnsigned')"/>
                  <xsl:text> :</xsl:text>
                </td>
                <td>
                  <xsl:value-of select="$allowObjectUnsigned" disable-output-escaping="yes"/>
                </td>
              </tr>
              <tr>
                <td>
                  <xsl:value-of select="lang:text('portal.pages.acp.options.objectsPhysicalRemove')"/>
                  <xsl:text> :</xsl:text>
                </td>
                <td>
                  <xsl:value-of select="$objectsPhysicalRemove" disable-output-escaping="yes"/>
                </td>
              </tr>
              <tr>
                <td>
                  <xsl:value-of select="lang:text('portal.pages.acp.options.objectsPhysicalRemoveDays')"/>
                  <xsl:text> :</xsl:text>
                </td>
                <td>
                  <xsl:value-of select="$objectsPhysicalRemoveDays" disable-output-escaping="yes"/>
                </td>
              </tr>
            </table>
          </div>
          
          
          


        </div>


      </xsl:with-param>
    </xsl:call-template>
  </xsl:template>

  
</xsl:stylesheet>