// <osiris_sps_source_header>
// This file is part of Osiris Serverless Portal System.
// Copyright (C)2005-2012 Osiris Team (info@osiris-sps.org) / http://www.osiris-sps.org )
//
// Osiris Serverless Portal System is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Osiris Serverless Portal System is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Osiris Serverless Portal System.  If not, see <http://www.gnu.org/licenses/>.
// </osiris_sps_source_header>

#ifndef _OS_HTML_HTMLCHECKBOX_H
#define _OS_HTML_HTMLCHECKBOX_H

#include "ihtmlinput.h"

//////////////////////////////////////////////////////////////////////

OS_NAMESPACE_BEGIN()

//////////////////////////////////////////////////////////////////////

class WebExport HtmlCheckBox : public IHtmlInput
{
	typedef IHtmlInput ControlBase;

// Construction
public:
	HtmlCheckBox();
	virtual ~HtmlCheckBox();

// Attributes
public:
	inline bool getAutoPostBack() const;
	inline void setAutoPostBack(bool autoPostBack);

	bool getCheck() const;
	void setCheck(bool check);

// IHtmlControl overrides
public:
	virtual void renderAttributes(HtmlWriter &writer);

protected:
	bool m_autoPostBack;
};

//////////////////////////////////////////////////////////////////////

inline bool HtmlCheckBox::getAutoPostBack() const { return m_autoPostBack; }
inline void HtmlCheckBox::setAutoPostBack(bool autoPostBack) { m_autoPostBack = autoPostBack; }

//////////////////////////////////////////////////////////////////////

OS_NAMESPACE_END()

//////////////////////////////////////////////////////////////////////

#endif // _OS_HTML_HTMLCHECKBOX_H
