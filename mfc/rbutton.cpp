/*
	 Battle of Britain
	 Copyright (C) 2000, 2001 Empire Interactive (Europe) Ltd,
	 677 High Road, North Finchley, London N12 0DA

	 Please see the document licence.doc for the full licence agreement

2. LICENCE
 2.1
 	Subject to the provisions of this Agreement we now grant to you the
 	following rights in respect of the Source Code:
  2.1.1
  	the non-exclusive right to Exploit  the Source Code and Executable
  	Code on any medium; and
  2.1.2
  	the non-exclusive right to create and distribute Derivative Works.
 2.2
 	Subject to the provisions of this Agreement we now grant you the
	following rights in respect of the Object Code:
  2.2.1
	the non-exclusive right to Exploit the Object Code on the same
	terms and conditions set out in clause 3, provided that any
	distribution is done so on the terms of this Agreement and is
	accompanied by the Source Code and Executable Code (as
	applicable).

3. GENERAL OBLIGATIONS
 3.1
 	In consideration of the licence granted in clause 2.1 you now agree:
  3.1.1
	that when you distribute the Source Code or Executable Code or
	any Derivative Works to Recipients you will also include the
	terms of this Agreement;
  3.1.2
	that when you make the Source Code, Executable Code or any
	Derivative Works ("Materials") available to download, you will
	ensure that Recipients must accept the terms of this Agreement
	before being allowed to download such Materials;
  3.1.3
	that by Exploiting the Source Code or Executable Code you may
	not impose any further restrictions on a Recipient's subsequent
	Exploitation of the Source Code or Executable Code other than
	those contained in the terms and conditions of this Agreement;
  3.1.4
	not (and not to allow any third party) to profit or make any
	charge for the Source Code, or Executable Code, any
	Exploitation of the Source Code or Executable Code, or for any
	Derivative Works;
  3.1.5
	not to place any restrictions on the operability of the Source
	Code;
  3.1.6
	to attach prominent notices to any Derivative Works stating
	that you have changed the Source Code or Executable Code and to
	include the details anddate of such change; and
  3.1.7
  	not to Exploit the Source Code or Executable Code otherwise than
	as expressly permitted by  this Agreement.

questions about this file may be asked at bob@rowansoftware.com a
better place to ask is http://www.simhq.com/ or even :-
http://www.simhq.com/cgi-bin/boards/cgi-bin/forumdisplay.cgi?action=topics&forum=Battle+of+Britain&number=40&DaysPrune=20&LastLogin=
*/

// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "rbutton.h"

/////////////////////////////////////////////////////////////////////////////
// CRButton

IMPLEMENT_DYNCREATE(CRButton, CWnd)

/////////////////////////////////////////////////////////////////////////////
// CRButton properties

OLE_COLOR CRButton::GetForeColor()
{
	OLE_COLOR result;
	GetProperty(DISPID_FORECOLOR, VT_I4, (void*)&result);
	return result;
}

void CRButton::SetForeColor(OLE_COLOR propVal)
{
	SetProperty(DISPID_FORECOLOR, VT_I4, propVal);
}

CString CRButton::GetCaption()
{
	CString result;
	GetProperty(DISPID_CAPTION, VT_BSTR, (void*)&result);
	return result;
}

void CRButton::SetCaption(LPCTSTR propVal)
{
	SetProperty(DISPID_CAPTION, VT_BSTR, propVal);
}

BOOL CRButton::GetMovesParent()
{
	BOOL result;
	GetProperty(0x2, VT_BOOL, (void*)&result);
	return result;
}

void CRButton::SetMovesParent(BOOL propVal)
{
	SetProperty(0x2, VT_BOOL, propVal);
}

long CRButton::GetFontNum()
{
	long result;
	GetProperty(0x3, VT_I4, (void*)&result);
	return result;
}

void CRButton::SetFontNum(long propVal)
{
	SetProperty(0x3, VT_I4, propVal);
}

BOOL CRButton::GetCloseButton()
{
	BOOL result;
	GetProperty(0x4, VT_BOOL, (void*)&result);
	return result;
}

void CRButton::SetCloseButton(BOOL propVal)
{
	SetProperty(0x4, VT_BOOL, propVal);
}

BOOL CRButton::GetTickButton()
{
	BOOL result;
	GetProperty(0x5, VT_BOOL, (void*)&result);
	return result;
}

void CRButton::SetTickButton(BOOL propVal)
{
	SetProperty(0x5, VT_BOOL, propVal);
}

BOOL CRButton::GetShowShadow()
{
	BOOL result;
	GetProperty(0x6, VT_BOOL, (void*)&result);
	return result;
}

void CRButton::SetShowShadow(BOOL propVal)
{
	SetProperty(0x6, VT_BOOL, propVal);
}

unsigned long CRButton::GetShadowColor()
{
	unsigned long result;
	GetProperty(0x7, VT_I4, (void*)&result);
	return result;
}

void CRButton::SetShadowColor(unsigned long propVal)
{
	SetProperty(0x7, VT_I4, propVal);
}

CString CRButton::GetString()
{
	CString result;
	GetProperty(0x8, VT_BSTR, (void*)&result);
	return result;
}

void CRButton::SetString(LPCTSTR propVal)
{
	SetProperty(0x8, VT_BSTR, propVal);
}

long CRButton::GetResourceNumber()
{
	long result;
	GetProperty(0x9, VT_I4, (void*)&result);
	return result;
}

void CRButton::SetResourceNumber(long propVal)
{
	SetProperty(0x9, VT_I4, propVal);
}

long CRButton::GetNormalFileNum()
{
	long result;
	GetProperty(0xa, VT_I4, (void*)&result);
	return result;
}

void CRButton::SetNormalFileNum(long propVal)
{
	SetProperty(0xa, VT_I4, propVal);
}

long CRButton::GetPressedFileNum()
{
	long result;
	GetProperty(0xb, VT_I4, (void*)&result);
	return result;
}

void CRButton::SetPressedFileNum(long propVal)
{
	SetProperty(0xb, VT_I4, propVal);
}

CString CRButton::GetNormalFileNumString()
{
	CString result;
	GetProperty(0xc, VT_BSTR, (void*)&result);
	return result;
}

void CRButton::SetNormalFileNumString(LPCTSTR propVal)
{
	SetProperty(0xc, VT_BSTR, propVal);
}

CString CRButton::GetPressedFileNumString()
{
	CString result;
	GetProperty(0xd, VT_BSTR, (void*)&result);
	return result;
}

void CRButton::SetPressedFileNumString(LPCTSTR propVal)
{
	SetProperty(0xd, VT_BSTR, propVal);
}

BOOL CRButton::GetUpdateCaption()
{
	BOOL result;
	GetProperty(0x1, VT_BOOL, (void*)&result);
	return result;
}

void CRButton::SetUpdateCaption(BOOL propVal)
{
	SetProperty(0x1, VT_BOOL, propVal);
}

BOOL CRButton::GetPressed()
{
	BOOL result;
	GetProperty(0xe, VT_BOOL, (void*)&result);
	return result;
}

void CRButton::SetPressed(BOOL propVal)
{
	SetProperty(0xe, VT_BOOL, propVal);
}

BOOL CRButton::GetDisabled()
{
	BOOL result;
	GetProperty(0xf, VT_BOOL, (void*)&result);
	return result;
}

void CRButton::SetDisabled(BOOL propVal)
{
	SetProperty(0xf, VT_BOOL, propVal);
}

BOOL CRButton::GetTransparency()
{
	BOOL result;
	GetProperty(0x12, VT_BOOL, (void*)&result);
	return result;
}

void CRButton::SetTransparency(BOOL propVal)
{
	SetProperty(0x12, VT_BOOL, propVal);
}

long CRButton::GetTransparentFileNum()
{
	long result;
	GetProperty(0x13, VT_I4, (void*)&result);
	return result;
}

void CRButton::SetTransparentFileNum(long propVal)
{
	SetProperty(0x13, VT_I4, propVal);
}

BOOL CRButton::GetHelpButton()
{
	BOOL result;
	GetProperty(0x14, VT_BOOL, (void*)&result);
	return result;
}

void CRButton::SetHelpButton(BOOL propVal)
{
	SetProperty(0x14, VT_BOOL, propVal);
}

CString CRButton::GetHintString()
{
	CString result;
	GetProperty(0x15, VT_BSTR, (void*)&result);
	return result;
}

void CRButton::SetHintString(LPCTSTR propVal)
{
	SetProperty(0x15, VT_BSTR, propVal);
}

OLE_COLOR CRButton::GetBackColor()
{
	OLE_COLOR result;
	GetProperty(DISPID_BACKCOLOR, VT_I4, (void*)&result);
	return result;
}

void CRButton::SetBackColor(OLE_COLOR propVal)
{
	SetProperty(DISPID_BACKCOLOR, VT_I4, propVal);
}

/////////////////////////////////////////////////////////////////////////////
// CRButton operations

