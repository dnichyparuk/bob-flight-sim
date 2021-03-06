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

// RowanDialog: // Radio.cpp : implementation file
//

#include "stdafx.h"
#include "mig.h"
#include "Radio.h"
#include	"winmove.h"
#include	"comms.h"

#ifdef _DEBUG
//#define new DEBUG_NEW
#ifndef THIS_FILE_DEFINED
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif

/////////////////////////////////////////////////////////////////////////////
// CRadio dialog


CRadio::CRadio(CWnd* pParent /*=NULL*/)
	: RowanDialog(CRadio::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRadio)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CRadio::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRadio)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	DDX_Control(pDX,IDC_PLAYERMESSAGE1,m_IDC_PLAYERMESSAGE1);
	DDX_Control(pDX,IDC_PLAYERMESSAGE2,m_IDC_PLAYERMESSAGE2);
	DDX_Control(pDX,IDC_PLAYERMESSAGE3,m_IDC_PLAYERMESSAGE3);
	DDX_Control(pDX,IDC_PLAYERMESSAGE4,m_IDC_PLAYERMESSAGE4);
	DDX_Control(pDX,IDC_PLAYERMESSAGE5,m_IDC_PLAYERMESSAGE5);
	DDX_Control(pDX,IDC_PLAYERMESSAGE6,m_IDC_PLAYERMESSAGE6);
	DDX_Control(pDX,IDC_PLAYERMESSAGE7,m_IDC_PLAYERMESSAGE7);
	DDX_Control(pDX,IDC_PLAYERMESSAGE8,m_IDC_PLAYERMESSAGE8);
	DDX_Control(pDX,IDC_CURRENTAC, m_IDC_CURRENTAC);
	DDX_Control(pDX,IDC_CURRENTAIRCRAFT, m_IDC_CURRENTAIRCRAFT); 
//DEADCODE DAW 23/11/99 	DDX_Control(pDX,IDC_PLAYERMESSAGE9,m_IDC_PLAYERMESSAGE9);
//DEADCODE DAW 23/11/99 	DDX_Control(pDX,IDC_PLAYERMESSAGE10,m_IDC_PLAYERMESSAGE10);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRadio, CDialog)
	//{{AFX_MSG_MAP(CRadio)
	ON_WM_TIMER()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRadio message handlers

void CRadio::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent==radio_timer && _DPlay.PlayerCreated)
	{
		_DPlay.UIUpdateMainSheet();
	}

	CDialog::OnTimer(nIDEvent);
}

BOOL CRadio::OnInitDialog() 
{
	CREdit* editbox;
	CDialog::OnInitDialog();
	
	editbox=GetDlgItem(IDC_PLAYERMESSAGE1);
	editbox->SetCaption(_DPlay.Messages[_DPlay.mySlot][0]);

	editbox=GetDlgItem(IDC_PLAYERMESSAGE2);
	editbox->SetCaption(_DPlay.Messages[_DPlay.mySlot][1]);

	editbox=GetDlgItem(IDC_PLAYERMESSAGE3);
	editbox->SetCaption(_DPlay.Messages[_DPlay.mySlot][2]);

	editbox=GetDlgItem(IDC_PLAYERMESSAGE4);
	editbox->SetCaption(_DPlay.Messages[_DPlay.mySlot][3]);

	editbox=GetDlgItem(IDC_PLAYERMESSAGE5);
	editbox->SetCaption(_DPlay.Messages[_DPlay.mySlot][4]);

	editbox=GetDlgItem(IDC_PLAYERMESSAGE6);
	editbox->SetCaption(_DPlay.Messages[_DPlay.mySlot][5]);

	editbox=GetDlgItem(IDC_PLAYERMESSAGE7);
	editbox->SetCaption(_DPlay.Messages[_DPlay.mySlot][6]);

	editbox=GetDlgItem(IDC_PLAYERMESSAGE8);
	editbox->SetCaption(_DPlay.Messages[_DPlay.mySlot][7]);

//	editbox=GetDlgItem(IDC_PLAYERMESSAGE9);
//	editbox->SetCaption(_DPlay.Messages[_DPlay.mySlot][8]);
  
//	editbox=GetDlgItem(IDC_PLAYERMESSAGE10);
//	editbox->SetCaption(_DPlay.Messages[_DPlay.mySlot][9]);

	CRStatic* st=GETDLGITEM(IDC_CURRENTAIRCRAFT);
	CRCombo* combo=GETDLGITEM(IDC_CURRENTAC);
	
	int index;
	int maxindex = 0;
	
	if	(_DPlay.GameType == DPlay::COMMSQUICKMISSION)
	{
		combo->ShowWindow(false);
		st->ShowWindow(false);

	}else
	{
		combo->ShowWindow(true);
		st->ShowWindow(true);
		if	(_DPlay.GameType == DPlay::DEATHMATCH)
		{
			{
			for (char i = 0; i < PT_BRIT_NONFLY;i++)
				combo->AddString(RESLIST(MK_SPIT_A,i));
			}
			for (char i = PT_GER_FLYABLE; i < PT_GER_NONFLY;i++)
				combo->AddString(RESLIST(MK_SPIT_A,i));

			maxindex = PT_BRIT_NONFLY + PT_GER_NONFLY - PT_GER_FLYABLE - 1;

			index = DPlay::H2H_Player[_DPlay.mySlot].squadron;
			if (index >= PT_BRIT_NONFLY)
				index -=  (PT_GER_FLYABLE-PT_BRIT_NONFLY);
			if (index > maxindex)
				index = 0;

			if (index<0)
				index=0;

			combo->SetIndex(index);
		}
		else if (_DPlay.GameType==DPlay::TEAMPLAY)
		{
			if(_DPlay.Side)
			{
				for (char i = 0; i < PT_BRIT_NONFLY;i++)
					combo->AddString(RESLIST(MK_SPIT_A,i));
				index = DPlay::H2H_Player[_DPlay.mySlot].squadron;
				if (index >= PT_BRIT_NONFLY)
					index =  0;
			}else
			{
				for (char i = PT_GER_FLYABLE; i < PT_GER_NONFLY;i++)
					combo->AddString(RESLIST(MK_SPIT_A,i));
				index = DPlay::H2H_Player[_DPlay.mySlot].squadron;
				if (index >= PT_GER_FLYABLE)
					index -=  (PT_GER_FLYABLE); //-SQ_B_NONFLYABLE);
				else 
					index = 0;
				if (index >=  (PT_GER_NONFLY - PT_GER_FLYABLE))
					index = 0;

			}

			if (index<0)
				index=0;

			combo->SetIndex(index);
		}
	}
//DEADCODE RDH 09/03/00 	else
//DEADCODE RDH 09/03/00 	{
//DEADCODE RDH 09/03/00 // in quick mission dont want to select AC here
//DEADCODE RDH 09/03/00 
//DEADCODE RDH 09/03/00 		combo->SetEnabled(false);
//DEADCODE RDH 09/03/00 	}

	radio_timer=SetTimer(DPlay::TIMER_RADIO,0,NULL);

//DeadCode AMM 16Nov99 	_DPlay.SendInRadioMessage();
//DeadCode AMM 16Nov99 	DPlay::H2H_Player[_DPlay.mySlot].status=CPS_RADIO;
	_DPlay.SendStatusChange(DPlay::CPS_RADIO);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CRadio::OnOK() 
{
#ifndef	BOB_DEMO_VER

// get messages and put into comms text

	CREdit* editbox;
	CString	buffer;

	editbox=GetDlgItem(IDC_PLAYERMESSAGE1);
	buffer = editbox->GetCaption();
	strcpy(_DPlay.Messages[_DPlay.mySlot][0],buffer);

	editbox=GetDlgItem(IDC_PLAYERMESSAGE2);
	buffer = editbox->GetCaption();
	strcpy(_DPlay.Messages[_DPlay.mySlot][1],buffer);

	editbox=GetDlgItem(IDC_PLAYERMESSAGE3);
	buffer = editbox->GetCaption();
	strcpy(_DPlay.Messages[_DPlay.mySlot][2],buffer);

	editbox=GetDlgItem(IDC_PLAYERMESSAGE4);
	buffer = editbox->GetCaption();
	strcpy(_DPlay.Messages[_DPlay.mySlot][3],buffer);

	editbox=GetDlgItem(IDC_PLAYERMESSAGE5);
	buffer = editbox->GetCaption();
	strcpy(_DPlay.Messages[_DPlay.mySlot][4],buffer);

	editbox=GetDlgItem(IDC_PLAYERMESSAGE6);
	buffer = editbox->GetCaption();
	strcpy(_DPlay.Messages[_DPlay.mySlot][5],buffer);

	editbox=GetDlgItem(IDC_PLAYERMESSAGE7);
	buffer = editbox->GetCaption();
	strcpy(_DPlay.Messages[_DPlay.mySlot][6],buffer);

	editbox=GetDlgItem(IDC_PLAYERMESSAGE8);
	buffer = editbox->GetCaption();
	strcpy(_DPlay.Messages[_DPlay.mySlot][7],buffer);

//	editbox=GetDlgItem(IDC_PLAYERMESSAGE9);
//	buffer = editbox->GetCaption();
//	strcpy(_DPlay.Messages[_DPlay.mySlot][8],buffer);

//	editbox=GetDlgItem(IDC_PLAYERMESSAGE10);
//	buffer = editbox->GetCaption();
//	strcpy(_DPlay.Messages[_DPlay.mySlot][9],buffer);

//DeadCode  26Oct00   	CRCombo* combo;
//DeadCode  26Oct00 	combo=GETDLGITEM(IDC_CURRENTAC);
//DeadCode  26Oct00 	int index = combo->GetIndex();	
//DeadCode  26Oct00 	if	(_DPlay.GameType == DPlay::DEATHMATCH)
//DeadCode  26Oct00 	{
//DeadCode  26Oct00 		if (index >= PT_BRIT_NONFLY)
//DeadCode  26Oct00 			index +=  (PT_GER_FLYABLE-PT_BRIT_NONFLY);
//DeadCode  26Oct00 		DPlay::H2H_Player[_DPlay.mySlot].squadron = index;	
//DeadCode  26Oct00 	}
//DeadCode  26Oct00 	else if (_DPlay.GameType==DPlay::TEAMPLAY)
//DeadCode  26Oct00 	{
//DeadCode  26Oct00 		if (_DPlay.Side)
//DeadCode  26Oct00 			DPlay::H2H_Player[_DPlay.mySlot].squadron = index;	
//DeadCode  26Oct00 		else
//DeadCode  26Oct00 			DPlay::H2H_Player[_DPlay.mySlot].squadron = index + PT_GER_FLYABLE;	
//DeadCode  26Oct00 	}

// dont need this csquick set up when game is launched

//DeadCode AMM 23Oct00 	if (_DPlay.GameType<DPlay::COMMSQUICKMISSION)
//DeadCode AMM 23Oct00 	{
//DeadCode AMM 23Oct00 		CSQuick1::quickdef.UpdateAcType();
//DeadCode AMM 23Oct00 	}
//DeadCode AMM 27Oct00 
//DeadCode AMM 27Oct00 	_DPlay.SendMyPlayerInfo(false);										// AMM 23Jun00
//DeadCode AMM 27Oct00 
//DeadCode AMM 27Oct00 	_DPlay.SaveRadioMessages();
#endif
}
void CRadio::OnDestroy() 
{
// need to do this here because for some reason when a player wants to reset the 
// radio messages the whole dialog is refreshed and so the info for ac is not 
// obtained and therefore any ac change is lost, sheesh we know who did this eh?

#ifndef	BOB_DEMO_VER
  	CRCombo* combo;
	combo=GETDLGITEM(IDC_CURRENTAC);
	int index = combo->GetIndex();	
	if	(_DPlay.GameType == DPlay::DEATHMATCH)
	{
		if (index >= PT_BRIT_NONFLY)
			index +=  (PT_GER_FLYABLE-PT_BRIT_NONFLY);
		DPlay::H2H_Player[_DPlay.mySlot].squadron = index;	
	}
	else if (_DPlay.GameType==DPlay::TEAMPLAY)
	{
		if (_DPlay.Side)
			DPlay::H2H_Player[_DPlay.mySlot].squadron = index;	
		else
			DPlay::H2H_Player[_DPlay.mySlot].squadron = index + PT_GER_FLYABLE;	
	}

	_DPlay.SendMyPlayerInfo(false);	

	_DPlay.SaveRadioMessages();

#endif
	KillTimer(radio_timer);
	CDialog::OnDestroy();
}

BEGIN_EVENTSINK_MAP(CRadio, CDialog)
    //{{AFX_EVENTSINK_MAP(CRadio)
//DEADCODE DAW 24/11/99 	ON_EVENT(CRadio, IDC_PLAYERMESSAGE10, 2 /* TextChanged */, OnTextChangedPlayermessage10, VTS_I4)
	ON_EVENT(CRadio, IDC_PLAYERMESSAGE1, 2 /* TextChanged */, OnTextChangedPlayermessage1, VTS_I4)
	ON_EVENT(CRadio, IDC_PLAYERMESSAGE2, 2 /* TextChanged */, OnTextChangedPlayermessage2, VTS_I4)
	ON_EVENT(CRadio, IDC_PLAYERMESSAGE3, 2 /* TextChanged */, OnTextChangedPlayermessage3, VTS_I4)
	ON_EVENT(CRadio, IDC_PLAYERMESSAGE4, 2 /* TextChanged */, OnTextChangedPlayermessage4, VTS_I4)
	ON_EVENT(CRadio, IDC_PLAYERMESSAGE5, 2 /* TextChanged */, OnTextChangedPlayermessage5, VTS_I4)
	ON_EVENT(CRadio, IDC_PLAYERMESSAGE6, 2 /* TextChanged */, OnTextChangedPlayermessage6, VTS_I4)
	ON_EVENT(CRadio, IDC_PLAYERMESSAGE7, 2 /* TextChanged */, OnTextChangedPlayermessage7, VTS_I4)
	ON_EVENT(CRadio, IDC_PLAYERMESSAGE8, 2 /* TextChanged */, OnTextChangedPlayermessage8, VTS_I4)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

//DeadCode  26Oct00 void CRadio::OnTextChangedPlayermessage10(LPTSTR text) 
//DeadCode  26Oct00 {
//DeadCode  26Oct00 	// TODO: Add your control notification handler code here
//DeadCode  26Oct00 	
//DeadCode  26Oct00 }

void	DPlay::InitMessages()
{
	for (int n=0;n<NUMRADIOMESSAGES;n++)
		strcpy(Messages[mySlot][n],RESSTRING(L_RADIOMSG0+n));
}

void CRadio::OnTextChangedPlayermessage1(LPTSTR text) 
{
		trunc(text,RADIOMESSAGELEN - 1);
}

void CRadio::OnTextChangedPlayermessage2(LPTSTR text) 
{
		trunc(text,RADIOMESSAGELEN - 1);
}

void CRadio::OnTextChangedPlayermessage3(LPTSTR text) 
{
		trunc(text,RADIOMESSAGELEN - 1);
	
}

void CRadio::OnTextChangedPlayermessage4(LPTSTR text) 
{
		trunc(text,RADIOMESSAGELEN - 1);
	
}

void CRadio::OnTextChangedPlayermessage5(LPTSTR text) 
{
		trunc(text,RADIOMESSAGELEN - 1);
	
}

void CRadio::OnTextChangedPlayermessage6(LPTSTR text) 
{
		trunc(text,RADIOMESSAGELEN - 1);
	
}

void CRadio::OnTextChangedPlayermessage7(LPTSTR text) 
{
		trunc(text,RADIOMESSAGELEN - 1);
	
}

void CRadio::OnTextChangedPlayermessage8(LPTSTR text) 
{
		trunc(text,RADIOMESSAGELEN - 1);
	
}
