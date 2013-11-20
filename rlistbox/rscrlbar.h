// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CRScrlBar wrapper class
#ifndef rscrlbar_INCLUDED
#pragma once
#define rscrlbar_INCLUDED

class CRScrlBar : public CWnd
{
protected:
	DECLARE_DYNCREATE(CRScrlBar)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x505aee46, 0x6a66, 0x11d6, { 0xa1, 0xf0, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); }

// Attributes
public:
	long GetMinValue();
	void SetMinValue(long);
	long GetMaxValue();
	void SetMaxValue(long);
	long GetStepSize();
	void SetStepSize(long);
	BOOL GetHorzAlign();
	void SetHorzAlign(BOOL);
	long GetParentPointer();
	void SetParentPointer(long);
	long GetPageSize();
	void SetPageSize(long);
	long GetScrollPos();
	void SetScrollPos(long);
	BOOL GetUseMessagesInsteadOfEvents();
	void SetUseMessagesInsteadOfEvents(BOOL);
	long GetFileNumOffset();
	void SetFileNumOffset(long);

// Operations
public:
	void Move(long left, long top, long right, long bottom);
};
#endif