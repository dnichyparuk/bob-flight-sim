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

//------------------------------------------------------------------------------
//Filename       shapes.cpp
//System
//Author         Paul.
//Date           Mon 18 Sep 1995
//Description    Shape loading/unloading/fixup stuff
//
//
// WARNING!!!!!! Shape numbers MUST now start at 1 (NOT 0).
//
//
//------------------------------------------------------------------------------

	#include	"DOSDefs.h"
#define F_GRAFIX												//DAW 05Aug96
#define F_SOUNDS
#define F_BATTLE
	#include	"myerror.H"

	#include	"FileMan.h"
	#include	"myAngles.h"
	#include	"Worldinc.h"
	#include	"AnimData.h"									//RJS 10Feb97

	#include	"shpinstr.h"									//RJS 01Dec97
	#include	"ImageMap.h"
	#include	"shapes.h"

	#include	"shapenum.g"
	#include	"hardpasm.h"
	#include	"bitfield.h"
//DeadCode PD 27Aug96  	MAKEFIELD	(ShapeNum,ShapeNumMIN,ShapeNumMAX);

//DeadCode PD 27Aug96 #pragma dump_object_model ShapeType
//DeadCode PD 27Aug96 #pragma	dump_object_model Shape_Desc
//DeadCode PD 27Aug96 #pragma dump_object_model DOLAUNCHER

	shapestuff	SHAPESTUFF;										//PD 27Aug96

////////////////////////////////////////////////////////////////////////////////
//
//	DEBUGGING CODE!!!!
//
////////////////////////////////////////////////////////////////////////////////

#ifndef	NDEBUG
//#define	_SHAPEBUG_
#endif


#if	DEBUGGING

	const char *inststr[dosetglassrangeno+1] =
				{
				"garbage",
				"dopointno",
				"dopolygonno",
				"dosetlcno",
				"dosetcolourno",
				"dolineno",
				"doretno",
				"doifcrossno",
				"dogosubno",
				"doifeqno",
				"doifneno",
				"donopno",
				"dogroupno",
				"dogotono",
				"doendno",
				"dowindowdialno",								//RJS 07Apr98
				"doattitudeno",								//RJS 01Apr98
				"dodotno",
				"doscalesizeno",								//RJS 03Mar98
				"dogunsightno",								//RJS 04Mar98
				"dowheelsprayno",								//RJS 16Mar98
				"doifbrightno",								//RJS 27Mar98
				"doquikpolyno",
				"dofadeenvelopeno",							//RJS 27Mar98
				"dowhiteoutno",								//RJS 31Mar98
				"donpointsno",
				"don4cmpntsno",
				"do4cmpntno",
				"dondupvecno",								//RJS 29May98
				"dondeltapointsno",							//RJS 02Jun98
				"dodrawsunno",								//RJS 22Jun98
				"dosetcolour256no",
				"doswitchno",
				"dosetcolourallno",
				"dopoint2xno",
				"do4cmpt2xno",
				"doifcaseno",
				"donincpntsno",
				"dotransparentonno",
				"dotransparentoffno",
				"dosphereno",
				"dosmokedonno",
				"dosmokedoffno",
				"donormalno",
				"dosmoothpolyno",
				"dovectorno",
				"dotransformlightno",
				"dolshadeonno",								//RJS 30Apr98
				"dorelpolyno",
				"donspheresno",								//RJS 13Jul98
				"donspheresimapdno",							//RJS 13Jul98
				"doweaponoffno",
				"dodrawreflectpolyno",
				"doresetanimno",								//RJS 13Nov98
				"docaptureno",
				"dosetcolourhno",
				"doquiksmoothpolyno",
				"doreposno",
				"dodepthcolourno",
				"dodepthpolyno",
				"doimagemapno",
				"docreateipolyno",
				"docreateivertno",
				"dodrawipolyno",
				"docopyivertno",
				"dosmthrelpolyno",
				"doquikrelpolyno",
				"donsubsno",
				"dobitsofffxno",								//RJS 15Jan99
				"doondamagedno",								//RJS 18Jan99
				"dosetmipmapno",								//RJS 24May99
				"donvecno",
				"donextvecno",
				"donpoint2xno",
				"dummyentry",
				"docallshapeno",
				"dosmokepntno",
				"dobitsoffno",
				"doplumepntno",
				"doisphereno",
				"dosetaniipolyno",
				"dodrawipolysno",
				"domappolyno",
				"dosetmapmapno",
				"do3dbreakno",
				"docylinderno",
				"dontpointsno",
				"dosetmapoffno",
				"dosetmappingplanerno",
				"dosetmappingtanno",
				"dosmktrailno",
				"dooffsetpntno",
				"doicylinderno",
				"drawbetween",								//MGA 28Nov95
				"docreatebumppolyno",							//PD 15Jan96
				"docopybvertno",								//PD 15Jan96
				"dodrawbpolyno",								//PD 15Jan96
				"dodrawrpoly",								//PD 28Mar96
				"dodrawopoly",								//PD 16Apr96
				"dorealisphereno",							//RJS 16Dec97
				"dolauncherno",								//PD 10Jul96
				"dodialno",									//PD 10Jul96
				"docompassno",								//PD 10Jul96
				"doiswitchno",								//PD 10Jul96
				"doinclnno",									//RJS 17Sep96
				"doanimationno",								//RJS 28Feb97
				"docollisionno",								//RJS 28Feb97
				"doeffectno",									//RJS 28Feb97
				"dodamageno",									//RJS 28Feb97
				"dodrawstationno",							//RJS 28Feb97
				"docaserangeno",								//RJS 03Mar97
				"doifpilotedno",								//RJS 27Mar97
				"donivertsno",								//RJS 27Mar97
				"dotrifanno",									//RJS 27Mar97
				"dotrizagno",									//RJS 27Mar97
				"dotrifanflatno",								//RJS 16Apr97
				"dotrizagflatno",								//RJS 16Apr97
				"dostretchpointno",							//RJS 09Jun97
				"dostretchmapno",								//RJS 09Jun97
				"doflipvectorno",								//RJS 06Aug97
				"doflipnvecno",								//RJS 06Aug97
				"domorphpointno",								//RJS 04Dec97
				"domorphnpointsno",							//RJS 08Dec97
				"douserealtimeno",								//RJS 04Dec97
				"dotimerphaseno",							//RJS 08Dec97
				"dobloblineno",							//RJS 08Dec97
				"dowheeldamageno",
				"dolightno",									//RJS 17Dec97
				"lightdatano",								//RJS 19Dec97
				"dolighttimerno",								//RJS 06Jan98
				"dodigitdialno",								//RJS 08Jan98
				"donianimvertsno",							//RJS 13Jan98
				"dosetluminosityno",							//RJS 20Jan98
				"dobitsoffcockno",							//RJS 23Jan98
				"domorphsphereno",							//RJS 23Jan98
				"domorphsphereimapdno",						//RJS 23Jan98
				"doheathazeno",							//RJS 30Jan98
				"doifhard3dno",								//RJS 04Feb98
				"domorphnsphrsno",
				"domorphnsphrsimapdno",
				"dosetglassrangeno"							//RJS 27Mar97
				};
#endif

//Old_Code PD 27Aug96 //컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Old_Code PD 27Aug96 //Author		Paul.
//Old_Code PD 27Aug96 //Date		Mon 18 Sep 1995
//Old_Code PD 27Aug96 //
//Old_Code PD 27Aug96 //Description
//Old_Code PD 27Aug96 //
//Old_Code PD 27Aug96 //Inputs
//Old_Code PD 27Aug96 //
//Old_Code PD 27Aug96 //Returns
//Old_Code PD 27Aug96 //
//Old_Code PD 27Aug96 //------------------------------------------------------------------------------
//Old_Code PD 27Aug96 shapestuff::shapestuff()
//Old_Code PD 27Aug96 {
//Old_Code PD 27Aug96 	settable();
//Old_Code PD 27Aug96 	glob_list = &gsnf;											//PD 27Aug96
//Old_Code PD 27Aug96 }

#ifdef	_SHAPEBUG_
static	FILE*	fpdeb = NULL;
#endif

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Author		Paul.
//Date			Mon 18 Sep 1995
//LastModified:	PD 27Aug96
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
shapestuff::shapestuff()
{
	settable();

	shapetable = new fileblockptr[list_size = ShapeNumMAX];
	gsnf=0;
	glob_list = &gsnf;

	for (list_index=ShapeNumMIN;list_index<ShapeNumMAX;list_index++)
	{
		shapetable[list_index]=NULL;
		*glob_list %= (ShapeNum)list_index;
	}

	list_index = 0;

#ifdef	_SHAPEBUG_
	fpdeb = fopen("shpbug.txt","wt");
#endif
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Author		Paul.
//Date			Mon 18 Sep 1995
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
shapestuff::~shapestuff()
{
	UWord	index;

	delete [] fixuptable;											//RJS 01Dec97

	for(index=0;index<list_size;index++)
		if(shapetable[index]!=NULL)
		{
#ifdef	_SHAPEBUG_
			fprintf(fpdeb,"DEL: %d\n",index+DIR_SHAPES);
#endif
			delete shapetable[index];
			shapetable[index]=NULL;
		}

	delete [] shapetable;

#ifdef	_SHAPEBUG_
	fclose(fpdeb);
#endif
}

//Old_Code PD 27Aug96 //컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Old_Code PD 27Aug96 //Procedure		AddShapesToGlobList
//Old_Code PD 27Aug96 //LastModified:	PD 27Aug96
//Old_Code PD 27Aug96 //Author		Paul.
//Old_Code PD 27Aug96 //Date			Tue 10 Oct 1995
//Old_Code PD 27Aug96 //
//Old_Code PD 27Aug96 //Description	Takes an array of shape numbers as an input and sets the
//Old_Code PD 27Aug96 //				appropriate bits in a bit table for loading later.
//Old_Code PD 27Aug96 //Inputs
//Old_Code PD 27Aug96 //
//Old_Code PD 27Aug96 //Returns
//Old_Code PD 27Aug96 //
//Old_Code PD 27Aug96 //------------------------------------------------------------------------------
//Old_Code PD 27Aug96 void shapestuff::AddShapesToGlobList(UWord *reqdshps, UWord& count)
//Old_Code PD 27Aug96 {
//Old_Code PD 27Aug96 	UWord	new_shps;
//Old_Code PD 27Aug96
//Old_Code PD 27Aug96 	for(new_shps=0;new_shps<count;new_shps++)
//Old_Code PD 27Aug96 	{
//Old_Code PD 27Aug96 		*glob_list|=(ShapeNum)reqdshps[new_shps];
//Old_Code PD 27Aug96 		reqdshps[new_shps]=NULL;
//Old_Code PD 27Aug96 	}
//Old_Code PD 27Aug96 	count=0;
//Old_Code PD 27Aug96 }

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		AddShapesToGlobList
//LastModified:	PD 27Aug96
//Author		Jim.
//Date			Tue 10 Oct 1995
//
//Description	Takes an array of shape numbers as an input and sets the
//				appropriate bits in a bit table for loading later.
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::AddShapesToGlobList(ShapeNumField* reqdshps)
{
	UWord		new_shps;

	for(new_shps=0;new_shps<reqdshps->MAX;new_shps++)
	{
		if ((*reqdshps)[(ShapeNum)new_shps])
			*glob_list|=(ShapeNum)new_shps;
	}
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		LoadRequiredShapes
//LastModified:	PD 27Aug96
//Author		Paul.
//Date			Tue 10 Oct 1995
//
//Description	Loads in the shapes as requested in the bit table filled in by
//				the above routine.
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::LoadRequiredShapes()
{
	int		index_list;
	Bool	loadedthistime;

	do
	{
		loadedthistime = FALSE;

		for(index_list=ShapeNumMIN;index_list<ShapeNumMAX;index_list++)
		{
			if ((*glob_list)[(ShapeNum)index_list])
				if(LoadShape((ShapeNum)index_list))
					loadedthistime = TRUE;
		}
	}
	while(loadedthistime);
}

//Old_Code PD 27Aug96 //컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Old_Code PD 27Aug96 //Author		Paul.
//Old_Code PD 27Aug96 //Date			Mon 18 Sep 1995
//Old_Code PD 27Aug96 //
//Old_Code PD 27Aug96 //Description
//Old_Code PD 27Aug96 //
//Old_Code PD 27Aug96 //Inputs		shapelist = ptr to a NULL terminated list of shapes
//Old_Code PD 27Aug96 //				to be loaded.
//Old_Code PD 27Aug96 //
//Old_Code PD 27Aug96 //Returns		number of new shapes loaded.
//Old_Code PD 27Aug96 //
//Old_Code PD 27Aug96 //------------------------------------------------------------------------------
//Old_Code PD 27Aug96 UWord shapestuff::LoadShapes(ShapeListPtr shapelist)
//Old_Code PD 27Aug96 {
//Old_Code PD 27Aug96 	UWord	currentshapeno,
//Old_Code PD 27Aug96 			shapesloaded = 0;
//Old_Code PD 27Aug96
//Old_Code PD 27Aug96 	while((currentshapeno = *shapelist)!=NULL)
//Old_Code PD 27Aug96 		if(LoadShape(currentshapeno))	shapesloaded++;
//Old_Code PD 27Aug96
//Old_Code PD 27Aug96 	return(shapesloaded);
//Old_Code PD 27Aug96 }

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Author		Paul.
//Date			Mon 18 Sep 1995
//
//Description	Load and fix up the current shape.
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
Bool shapestuff::LoadShape(ShapeNumber shape_number)
{
	Bool ret_val = FALSE;

//cludge level fix
	if (!shape_number)
	{
		shape_number=EMPTY;						//PD 09Apr96
		INT3;															//RJS 7Nov00
	}

//DeadCode RJS 7Nov00 	if (!shape_number)											//PD 27Mar96
//DeadCode RJS 7Nov00 		_Error.EmitSysErr(__FILE__":Invalid shape number (0)");	//PD 27Mar96

//DeadCode RJS 7Nov00 	FileNum	shapefile = (FileNum )(shape_number + DIR_SHAPES);
	if(shapetable[shape_number]==NULL)
	{
		FileNum	shapefile = FileNum(shape_number + DIR_SHAPES);		//RJS 7Nov00

#ifdef	_SHAPEBUG_
		fprintf(fpdeb,"GET: %d\n",shape_number+DIR_SHAPES);
#endif
		ShapeFixing = (ShapeNum)shape_number;								//RJS 23Apr97
		shapetable[shape_number] = new fileblock(shapefile,FixupShapeFile);
		ret_val = TRUE;
	}
	return(ret_val);
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		UnLoadRequiredShapes
//Author		Paul.
//Date			Tue 10 Oct 1995
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::UnLoadRequiredShapes()
{
	int	index_list;

	for(index_list=ShapeNumMIN;index_list<ShapeNumMAX;index_list++)
	{
		if ((*glob_list)[(ShapeNum)index_list])
		{
			UnLoadShape((ShapeNum)index_list);
			*glob_list %= (ShapeNum)index_list;
		}
	}
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		UnLoadShape
//Author		Paul.
//Date			Mon 9 Oct 1995
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::UnLoadShape(ShapeNumber shape_number)
{
	if (	shape_number												//RJS 7Nov00
		&&	(shapetable[shape_number]!=NULL)	)
	{
#ifdef	_SHAPEBUG_
		fprintf(fpdeb,"DEL: %d\n",shape_number+DIR_SHAPES);
#endif
		delete shapetable[shape_number];
		shapetable[shape_number]=NULL;
	}
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		GetShapePtr
//Author		Paul.
//Date			Mon 9 Oct 1995
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
ShapeDescPtr shapestuff::GetShapePtr(ShapeNumber shape_number)
{
	UByte	*tmp;

	//cludge level fix
	if (!shape_number)
	{
		shape_number=EMPTY;							//RJS 7Nov00
		INT3;										//RJS 7Nov00
	}

	if(shapetable[shape_number]==NULL)
	{
		*glob_list |= (ShapeNum)shape_number;
		(void )LoadShape(shape_number);
	}

	tmp = (UByte *)getdata(shapetable[shape_number]);

	tmp +=2; //Skip size word

	return((ShapeDescPtr )tmp);
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		GetShapeStrength
//Author		Robert Slater
//Date			Tue 3 Sep 1996
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
ULong	shapestuff::GetShapeStrength(ShapeNumber shape_number)
{
	ShapeDescPtr	header_ptr;

	header_ptr = GetShapePtr(shape_number);

 	return(header_ptr->RealVulnerability);						//RJS 22Jan98
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		GetShapeDamageType
//Author		Robert Slater
//Date			Thu 22 Jan 1998
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
ULong	shapestuff::GetShapeDamageType(ShapeNumber shape_number)
{
	ShapeDescPtr	header_ptr;

	header_ptr = GetShapePtr(shape_number);

 	return(header_ptr->RealDamageType);
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		GetShapeDamageStrength
//Author		Robert Slater
//Date			Thu 22 Jan 1998
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
ULong	shapestuff::GetShapeDamageStrength(ShapeNumber shape_number)
{
	ShapeDescPtr	header_ptr;

	header_ptr = GetShapePtr(shape_number);

 	return(header_ptr->RealDamageStrength);						//RJS 22Jan98
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupShape
//Author		Paul.
//Date			Mon 18 Sep 1995
//
//Description	Fixes up various bits of shape instruction data.
//
//Inputs
//
//Returns		TRUE if all okay otherwise returns FALSE.
//
//------------------------------------------------------------------------------
void shapestuff::FixupShape(UByte *shapeptr)
{
	ShapeDescPtr	header_ptr;
	ULong	datalength;

	datalength = (*(UWord *)shapeptr)-2;

	shapeptr += 2;
	header_ptr = (ShapeDescPtr) shapeptr;

	shapeptr+=sizeof(ShapeDesc );

	datalength-=sizeof(ShapeDesc );

	//Fixup instruction data

	FixInstrData(shapeptr,datalength);
}

void	shapestuff::FixupShapeFile(void*	&dataarea,ULong&	datalengthin)
{
	SHAPESTUFF.shp_base_ptr = (UByte *)dataarea;
	SHAPESTUFF.FixupShape((UByte*) dataarea);
}


//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixHeaderData
//Author		Paul.
//Date			Tue 19 Sep 1995
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixHeaderData(ShapeDescPtr shapeptr)
{
//DeadCode PD 10Jul96 	if (shapeptr->LauncherDataSize!=0)
//DeadCode PD 10Jul96 		haslaunchers = TRUE;
//DeadCode PD 10Jul96 	else
//DeadCode PD 10Jul96 		haslaunchers = FALSE;
}

static	int	lastinstr=0;
static	int	instrcnt = 0;
static	int	debugcnt = 0;

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixInstrData
//Author		Paul.
//Date			Tue 19 Sep 1995
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixInstrData(UByte *& ptr, ULong& datalen)
{
	UWord 	instr,
			size;

//	UWord	lastinstr=0;
//	int		instrcnt = 0;										//RJS 23Apr97

	instr = 0;
	lastinstr = 0;
	instrcnt = 0;

	while(datalen)
	{
//DeadCode RJS 03Mar97 		lastinstr++;

		if(((instr = (UWord )*ptr)>dosetglassrangeno)||(instr==0))//RJS 19Dec97
		{
			_Error.EmitSysErr(__FILE__":Bad instruction in shape(%d), line: %d, last: %s\n",ShapeFixing,instrcnt,inststr[lastinstr]);
		}
		else
		{
			instrcnt++;											//RJS 23Apr97
			lastinstr = instr;									//RJS 23Apr97
		}

		ptr++;
		forwardref = FALSE;										//RJS 19Mar97

		(this->*(fixuptable[instr].fixrtn)) (ptr,datalen);

//DeadCode RJS 23Apr97 		lastinstr = instr;

		ptr += (size = fixuptable[instr].skipsize);

		datalen -= (size+1);
	}
}

/////////////////////////////////////////////////////////////////////////////////
//
//					SPECIAL CASE INSTRUCTION FIXUP ROUTINES
//
/////////////////////////////////////////////////////////////////////////////////

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupStubb
//Author		Paul.
//Date			Thu 12 Oct 1995
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupStubb(UByte *&dataptr,ULong &datalen)
{

}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixPolygon
//Author		Paul.
//Date			Tue 10 Oct 1995
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupPolygon(UByte *&dataptr,ULong &datalen)
{
	ULong size;

	DOPOLYGON_PTR ptr = (DOPOLYGON_PTR)dataptr;

	size = ((UWord )ptr->edges)*sizeof(UWord);

	dataptr += size;

	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupSmoothPoly
//Author		Martin Alderton
//Date			Tue 7 Nov 1995
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupSmoothPoly(UByte *&dataptr,ULong &datalen)
{
	ULong size;

	DOSMOOTHPOLY_PTR ptr = (DOSMOOTHPOLY_PTR)dataptr;

	size = ((UWord )ptr->edges)*sizeof(UWord);

	dataptr += size;

	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupCreateIPoly
//Author		Paul.
//Date			Wed 11 Oct 1995
//
//Description	Reads the image map equate from the shape file and adds it
//				to the list of required imagemaps.
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupCreateIPoly(UByte *&dataptr,ULong &)		//PD 29Nov95
{
	DOCREATEIPOLY_PTR	ptr = (DOCREATEIPOLY_PTR )dataptr;

	Image_Map.AddImageMapToGlbList((UWord)ptr->image_no);
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupCreateBPoly
//Author		Paul.
//Date			Mon 15 Jan 1996
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupCreateBPoly(UByte *&dataptr,ULong &)
{
	DOCREATEBUMPPOLY_PTR	ptr =
		(DOCREATEBUMPPOLY_PTR )dataptr;

	Image_Map.AddImageMapToGlbList((UWord)ptr->image_no);
	Image_Map.AddImageMapToGlbList((UWord)ptr->bump_no);
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDrawCloud
//Author		Paul.
//Date			Mon 22 Jan 1996
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDrawCloud(UByteP& dataptr,ULong& )
{
//DeadCode RJS 20Oct00 	SWord	temp;

//DeadCode RJS 20Oct00 	DODRAWCLOUD_PTR	ptr = (DODRAWCLOUD_PTR )dataptr;

/*	temp = ((temp=ptr->image_no)>=0)?temp:-temp;

	Image_Map.AddImageMapToGlbList(temp);

	temp = ((temp=ptr->bump_no)>=0)?temp:-temp;

	Image_Map.AddImageMapToGlbList(temp);*/
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoGroup
//LastModified:	PD 27Aug96
//Author		Paul.
//Date			Wed 11 Oct 1995
//
//Description	Reads the shape number field from the _dogroup instruction
//				and checks to see if the shape has already been requested.
//				If it hasn't then add it to the list to load.
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoGroup(UByte *&dataptr,ULong &)			//PD 29Nov95
{
	DOGROUP_PTR	ptr = (DOGROUP_PTR )dataptr;

	*glob_list|=(ShapeNum)ptr->shapenum;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoNPoints
//Author		Paul.
//Date			Thu 12 Oct 1995
//
//Description	Skips past the following _nnext point instructions
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoNPoints(UByte *&dataptr,ULong &datalen)
{
	ULong	size;

	DONPOINTS_PTR ptr = (DONPOINTS_PTR )dataptr;

	size = sizeof(NNEXT)*(ptr->vertex_count);

	dataptr += size;

	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoNTPoints
//Author		Martin Alderton
//Date			Tue 7 Nov 1995
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoNTPoints(UByte *&dataptr,ULong &datalen)
{
	ULong	size;

	DONTPOINTS_PTR ptr = (DONTPOINTS_PTR )dataptr;

	size = sizeof(NEXTT)*(ptr->count);

	dataptr += size;

	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupGoto
//Author		Paul.
//Date			Mon 16 Oct 1995
//
//Description	Makes offset relative to the start of this shape into an
//				offset relative to the current location in this shape
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupGoto(UByte *&dataptr, ULong &)
{
	SLong	new_off;
	UWord	old_off;

	UByte	*temp;

	DOGOTO_PTR	ptr = (DOGOTO_PTR)dataptr;

	old_off = ptr->offset;

	temp = shp_base_ptr + old_off;

	new_off = temp - dataptr;

	if (forwardref)
	{
		if (	(new_off > 65536)
			||	(new_off < 2)	)
			_Error.EmitSysErr(__FILE__":Bollocks offset!! (%d), shape %d,(%d --> %s)[%d]",new_off,ShapeFixing,instrcnt,inststr[lastinstr],debugcnt);
	}
	else
	{
		if (	(new_off > 32767)
			||	(new_off < -32768)	)
			_Error.EmitSysErr(__FILE__":Bollocks offset!! (%d), shape %d,(%d --> %s)[%d]",new_off,ShapeFixing,instrcnt,inststr[lastinstr],debugcnt);
	}


	ptr->offset = new_off;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupBitsOff
//Author		Paul.
//Date			Wed 17 Apr 1996
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupBitsOff(UByte *&dataptr, ULong&)
{
	SWord	new_off,
			old_off;

	UByte	*temp;

	DOBITSOFF_PTR ptr = (DOBITSOFF_PTR)dataptr;

	old_off = ptr->dam1offset;

	if (old_off)
	{
		temp = shp_base_ptr + old_off;

		new_off = temp - dataptr;

		ptr->dam1offset = new_off - sizeof(DOBITSOFF);				//RJS 17Feb98
	}

	old_off = ptr->dam2offset;

	if (old_off)
	{
		temp = shp_base_ptr + old_off;

		new_off = temp - dataptr;

		ptr->dam2offset = new_off - sizeof(DOBITSOFF);				//RJS 17Feb98
	}

	old_off = ptr->deadoffset;
	if (old_off > 0)											//RJS 10Aug98
	{
		temp = shp_base_ptr + old_off;

		new_off = temp - dataptr;

		ptr->deadoffset = new_off - sizeof(DOBITSOFF);			//RJS 31Mar98
	}
//	else
//		ptr->deadoffset = -1;
//
//	ptr->dummyret = doretno;									//RJS 11Feb98
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupBitsOffCock
//Author		Robert Slater
//Date			Fri 23 Jan 1998
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupBitsOffCock(UByte *&dataptr, ULong&)
{
	SWord	new_off,
			old_off;

	UByte	*temp;

	DOBITSOFFCOCK_PTR ptr = (DOBITSOFFCOCK_PTR)dataptr;

	old_off = ptr->offset;

	if (old_off)
	{
		temp = shp_base_ptr + old_off;

		new_off = temp - dataptr;

		ptr->offset = new_off;
	}
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDrawBetween
//Author		Martin Alderton
//Date			Tue 28 Nov 1995
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDrawBetween(UByte *&dataptr, ULong &)		//PD 29Nov95
{
	SLong	new_off;											//RJS 19Mar97
	UWord	old_off;											//RJS 19Mar97

	UByte	*temp;

	DRAWBETWEEN_PTR	ptr = (DRAWBETWEEN_PTR)dataptr;

	old_off = ptr->offset;

	temp = shp_base_ptr + old_off;

	new_off = temp - dataptr;
	if (new_off < 0)
		_Error.EmitSysErr(__FILE__":Draw-Between offset is negative!!");

	ptr->offset = new_off;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupIfCross
//Author		Paul.
//Date			Tue 17 Oct 1995
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupIfCross(UByte *&dataptr, ULong &)			//PD 29Nov95
{
	SWord	new_off,
			old_off;

	UByte	*temp;

	DOIFCROSS_PTR ptr = (DOIFCROSS_PTR)dataptr;

	old_off = ptr->offset;

	temp = shp_base_ptr + old_off;

	new_off = temp - dataptr;

	ptr->offset = new_off;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoNSubs
//Author		Paul.
//Date			Wed 18 Oct 1995
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoNSubs(UByte *&dataptr, ULong &datalen)
{
	UWord	counter;

	DONSUBS_PTR ptr = (DONSUBS_PTR)dataptr;

	datalen-=sizeof(DONSUBS);

	dataptr+=sizeof(DONSUBS);

	forwardref = TRUE;

	for(counter=0;counter<ptr->count;counter++)
	{
		debugcnt = counter;										//RJS 19May98
		FixupGoto(dataptr,datalen);

		dataptr += sizeof(DOGOTO);
		datalen -= sizeof(DOGOTO);
	}
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupNPoint2X
//Author		Paul.
//Date			Wed 18 Oct 1995
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupNPoint2X(UByte *&dataptr, ULong &datalen)
{
	ULong	size;

	DONPOINT2X_PTR ptr = (DONPOINT2X_PTR)dataptr;

	size = ptr->count * sizeof(NNEXT2X);

	dataptr+=size;

	datalen-=size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupNVec
//Author		Paul.
//Date			Wed 18 Oct 1995
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupNVec(UByte *&dataptr, ULong &datalen)
{
	ULong size;

	DONVEC_PTR ptr = (DONVEC_PTR)dataptr;

	size = ptr->count * sizeof(NEXTVEC);

	dataptr += size;

	datalen -= size;
}

void shapestuff::FixupNAnimVec(UByte *&dataptr, ULong &datalen)
{
	ULong size;

	DONANIMVEC_PTR ptr = (DONANIMVEC_PTR)dataptr;

	size = ptr->count * sizeof(NEXTVEC);

	dataptr += size;

	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoRelpoly
//Author		Paul.
//Date			Wed 18 Oct 1995
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoRelpoly(UByte *&dataptr, ULong &datalen)
{
	ULong size;

	UWord counter;

	DORELPOLY_PTR ptr = (DORELPOLY_PTR)dataptr;

	counter = ((UWord )ptr->edges)-1;

	size = counter * sizeof(SWord);		//RJS 11Feb00

	dataptr += size;

	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupIfCase
//Author		Paul.
//Date			Wed 18 Oct 1995
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupIfCase(UByte *&dataptr, ULong &datalen)
{
	UWord	counter;

	DOIFCASE_PTR ptr = (DOIFCASE_PTR)dataptr;

	datalen-=sizeof(DOIFCASE);

	dataptr+=sizeof(DOIFCASE);

	for(counter=0;counter<(UWord )ptr->count;counter++)
	{
		FixupGoto(dataptr,datalen);

		dataptr += sizeof(DOGOTO);
		datalen -= sizeof(DOGOTO);
	}
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoCollision
//Author		Robert Slater
//Date			Tue 18 Feb 1997
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoCollision(UByte *&dataptr, ULong &datalen)
{
	UWord	counter;
	SWord	oldoff,
			newoff;
	UByteP	temp;


	DOCOLLISION_PTR ptr = (DOCOLLISION_PTR)dataptr;

//DeadCode RJS 16Jun00 	oldoff = ptr->succeed;
//DeadCode RJS 16Jun00
//DeadCode RJS 16Jun00 	if (oldoff)
//DeadCode RJS 16Jun00 	{
//DeadCode RJS 16Jun00 		temp = shp_base_ptr + oldoff;
//DeadCode RJS 16Jun00 		newoff = temp - dataptr;
//DeadCode RJS 16Jun00
//DeadCode RJS 16Jun00 		ptr->succeed = newoff;
//DeadCode RJS 16Jun00 	}

	oldoff = ptr->fail;

	if (oldoff)
	{
		temp = shp_base_ptr + oldoff;
		newoff = temp - dataptr;

		ptr->fail = newoff;
	}
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoCaseRange
//Author		Robert Slater
//Date			Mon 3 Mar 1997
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoCaseRange(UByte *&dataptr, ULong &datalen)
{
	UWord	counter;
	SLong	oldoff,												//RJS 03Sep97
			newoff;
	UByteP	temp;
	UByteP	temp2;
//	int		temp3;
	SLong	sizepoo;

	DOCASERANGE_PTR ptr = (DOCASERANGE_PTR)dataptr;

	sizepoo = sizeof(DOCASERANGE);
	sizepoo += ptr->nofields*2*sizeof(UWord);					//RJS 03Sep97

	temp = (UByteP)ptr + sizeof(DOCASERANGE);
	oldoff = ptr->failjump;
	temp2 = shp_base_ptr + oldoff;
	newoff = temp2 - dataptr;
	ptr->failjump = newoff;

	for(counter=0; counter < ptr->nofields;counter++)
	{
		temp += sizeof(UWord);									//RJS 03Sep97

		oldoff = *((UWord*)temp);
		temp2 = shp_base_ptr + oldoff;
		newoff = temp2 - dataptr;

		*((SWord*)temp) = newoff;								//RJS 03Sep97
		temp += sizeof(UWord);
	}

	dataptr += sizepoo;
	datalen -= sizepoo;

}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoIfPiloted
//Author		Robert Slater
//Date			Fri 7 Mar 1997
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoIfPiloted(UByte *&dataptr, ULong &datalen)
{
	SWord	oldoff,
			newoff;
	UByteP	temp;


	DOIFPILOTED_PTR ptr = (DOIFPILOTED_PTR)dataptr;

	oldoff = ptr->offset;

	temp = shp_base_ptr + oldoff;
	newoff = temp - dataptr;

	ptr->offset = newoff;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoDrawIPoly
//Author		Robert Slater
//Date			Wed 19 Mar 1997
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoDrawIPoly(UByte *&dataptr, ULong &datalen)
{
	ULong size;
	UWord counter;

	DODRAWIPOLY_PTR ptr = (DODRAWIPOLY_PTR)dataptr;

	counter = ptr->nopoints;

	size = counter * sizeof(SWord);		//RJS 11Feb00

	dataptr += size;

	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoNIVerts
//Author		Robert Slater
//Date			Thu 20 Mar 1997
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoNIVerts(UByte *&dataptr, ULong &datalen)
{
	ULong size;
	UWord counter;

	DONIVERTS_PTR ptr = (DONIVERTS_PTR)dataptr;

	counter = ptr->count;

	size = counter * sizeof(NEXTMAP);

	dataptr += size;

	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoTriFan
//Author		Robert Slater
//Date			Thu 27 Mar 1997
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoTriFan(UByte *&dataptr, ULong &datalen)
{
	ULong size;
	UWord counter;

	DOTRIFAN_PTR ptr = (DOTRIFAN_PTR)dataptr;

	counter = ptr->edges;

	size = counter * sizeof(UByte);

	dataptr += size;

	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoTriZag
//Author		Robert Slater
//Date			Thu 27 Mar 1997
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoTriZag(UByte *&dataptr, ULong &datalen)
{
	ULong size;
	UWord counter;

	DOTRIZAG_PTR ptr = (DOTRIZAG_PTR)dataptr;

	counter = ptr->edges;

	size = counter * sizeof(UByte);

	dataptr += size;

	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoTriFanFlat
//Author		Robert Slater
//Date			Wed 16 Apr 1997
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoTriFanFlat(UByte *&dataptr, ULong &datalen)
{
	ULong size;
	UWord counter;

	DOTRIFANFLAT_PTR ptr = (DOTRIFANFLAT_PTR)dataptr;

	counter = ptr->edges;

	size = counter * sizeof(UByte);

	dataptr += size;

	datalen -= size;
}


//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoTriZagFlat
//Author		Robert Slater
//Date			Wed 16 Apr 1997
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoTriZagFlat(UByte *&dataptr, ULong &datalen)
{
	ULong size;
	UWord counter;

	DOTRIZAGFLAT_PTR ptr = (DOTRIZAGFLAT_PTR)dataptr;

	counter = ptr->edges;

	size = counter * sizeof(UByte);

	dataptr += size;

	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoTimerPhase
//Author		Robert Slater
//Date			Wed 10 Dec 1997
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoTimerPhase(UByte *&dataptr, ULong &datalen)
{
	ULong size;
	DOTIMERPHASE_PTR ptr = (DOTIMERPHASE_PTR)dataptr;
	TPHASESTEP_PTR ptr2;
	UWord	oldoff,												//RJS 03Sep97
			newoff;
	UByteP	temp;
	UByteP	temp2;
//	int		temp3;
	int		counter;

	size = sizeof(DOTIMERPHASE);
	temp = dataptr;
	temp += size;

	ptr2 = (TPHASESTEP_PTR) temp;

	for(counter=0; counter < ptr->nophases; counter++)
	{
		oldoff = ptr2->objjump;

		temp2 = shp_base_ptr + oldoff;
		newoff = temp2 - dataptr;

		ptr2->objjump = newoff;
		ptr2++;
	}

	size += (ptr->nophases * sizeof(TPHASESTEP));

	dataptr += size;
	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoAbsoluteTimerPhase
//Author		Robert Slater
//Date			Thu 2 Dec 1999
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoAbsTimerPhase(UByte *&dataptr, ULong &datalen)
{
	ULong size;
	DOABSOLUTETIMERPHASE_PTR ptr = (DOABSOLUTETIMERPHASE_PTR)dataptr;
	TPHASESTEP_PTR ptr2;
	UWord	oldoff,
			newoff;
	UByteP	temp;
	UByteP	temp2;
//	int		temp3;
	int		counter;

	size = sizeof(DOABSOLUTETIMERPHASE);
	temp = dataptr;
	temp += size;

	ptr2 = (TPHASESTEP_PTR) temp;

	for(counter=0; counter < ptr->nophases; counter++)
	{
		oldoff = ptr2->objjump;

		temp2 = shp_base_ptr + oldoff;
		newoff = temp2 - dataptr;

		ptr2->objjump = newoff;
		ptr2++;
	}

	size += (ptr->nophases * sizeof(TPHASESTEP));

	dataptr += size;
	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoMORPHNPoints
//Author		Robert Slater
//Date			Mon 8 Dec 1997
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoMorphNPoints(UByte *&dataptr, ULong &datalen)
{
	ULong size;

	DOMORPHNPOINTS_PTR ptr = (DOMORPHNPOINTS_PTR)dataptr;

	size = sizeof(DOMORPHNPOINTS) + (ptr->nopoints * sizeof(MORPHNNEXT));

	dataptr += size;

	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoNIAnimVerts
//Author		Robert Slater
//Date			Tue 13 Jan 1998
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoNiAnimVerts(UByte *&dataptr, ULong &datalen)
{
	ULong size;
	UWord counter;

	DONIANIMVERTS_PTR ptr = (DONIANIMVERTS_PTR)dataptr;

	counter = ptr->count;

	size = counter * sizeof(NEXTMAP);

	dataptr += size;

	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoIfHard3d
//Author		Robert Slater
//Date			Thu 5 Feb 1998
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoIfHard3d(UByte *&dataptr, ULong &datalen)
{
	SWord	oldoff,
			newoff;
	UByteP	temp;

	DOIFHARD3D_PTR ptr = (DOIFHARD3D_PTR)dataptr;

	oldoff = ptr->offset;

	temp = shp_base_ptr + oldoff;
	newoff = temp - dataptr;

	ptr->offset = newoff;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoMorphNSphrs
//Author		Robert Slater
//Date			Thu 5 Feb 1998
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoMorphNSphrs(UByte *&dataptr, ULong &datalen)
{
	ULong size;

	DOMORPHNSPHRS_PTR ptr = (DOMORPHNSPHRS_PTR)dataptr;

	size = sizeof(DOMORPHNSPHRS) + (ptr->count * sizeof(MORPHSPHNEXT));

	dataptr += size;

	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoMorphNSphrsImapd
//Author		Robert Slater
//Date			Thu 5 Feb 1998
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoMorphNSphrsImapd(UByte *&dataptr, ULong &datalen)
{
	ULong size;

	DOMORPHNSPHRSIMAPD_PTR ptr = (DOMORPHNSPHRSIMAPD_PTR)dataptr;

	Image_Map.AddImageMapToGlbList((UWord)ptr->imagemap);//RJS 03Nov98

	size = sizeof(DOMORPHNSPHRSIMAPD) + (ptr->count * sizeof(MORPHSPHNEXT));

	dataptr += size;

	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoGunSight
//Author		Robert Slater
//Date			Wed 4 Mar 1998
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoGunSight(UByte *&dataptr, ULong &datalen)
{
	ULong size;

	DOGUNSIGHT_PTR ptr = (DOGUNSIGHT_PTR)dataptr;

	size = ptr->nopoints * sizeof(UByte);

	dataptr += size;

	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoIfBright
//Author		Robert Slater
//Date			Fri 20 Mar 1998
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoIfBright(UByte *&dataptr, ULong &datalen)
{
	ULong size;
	SWord	oldoff,
			newoff;
	UByteP	temp;

	DOIFBRIGHT_PTR ptr = (DOIFBRIGHT_PTR)dataptr;

	oldoff = ptr->offset;
	temp = shp_base_ptr + oldoff - sizeof(DOIFBRIGHT);
	newoff = temp - dataptr;

	ptr->offset = newoff;

	size = (ptr->nopoints * sizeof(UWord));	//RJS 11Feb00

	dataptr += size;

	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoNDeltaPoints
//Author		Robert Slater
//Date			Tue 2 Jun 1998
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoNDeltaPoints(UByte *&dataptr,ULong &datalen)
{
	DONDELTAPOINTS_PTR ptr = (DONDELTAPOINTS_PTR )dataptr;
	ULong	size;
	SLong	new_off,
			old_off;
	UByte	*temp;
	UWord	mask = ptr->mask;
	UWord	nobitsset = ((mask&4)>>2)+((mask&2)>>1)+(mask&1);

	old_off = ptr->offset;
	if (old_off)
	{
		temp = shp_base_ptr + old_off;
		ptr->offset = (temp - dataptr) + sizeof(DONPOINTS) + 1;
	}

	if (nobitsset)
	{
		size = sizeof(NDNEXT1) * ptr->count * nobitsset;

		dataptr += size;
		datalen -= size;
	}
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoNSpheres
//Author		Robert Slater
//Date			Mon 13 Jul 1998
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoNSpheres(UByte *&dataptr, ULong &datalen)
{
	ULong size;

	DONSPHERES_PTR ptr = (DONSPHERES_PTR)dataptr;

	size = sizeof(DONSPHERES) + (ptr->count * sizeof(SPHERENEXT));

	dataptr += size;

	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoNSpheresImapd
//Author		Robert Slater
//Date			Mon 13 Jul 1998
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoNSpheresImapd(UByte *&dataptr, ULong &datalen)
{
	ULong size;

	DONSPHERESIMAPD_PTR ptr = (DONSPHERESIMAPD_PTR)dataptr;

	Image_Map.AddImageMapToGlbList((UWord)ptr->imagemap);//RJS 03Nov98

	size = sizeof(DONSPHERESIMAPD) + (ptr->count * sizeof(SPHERENEXT));

	dataptr += size;

	datalen -= size;
}

void shapestuff::FixupDoDrawReflectPoly(UByte *&dataptr, ULong &datalen)
{
	ULong size;
	UWord counter;

	DODRAWREFLECTPOLY_PTR ptr = (DODRAWREFLECTPOLY_PTR)dataptr;

	counter = ptr->nopoints;

	size = counter * sizeof(SWord);		//RJS 11Feb00

	dataptr += size;

	datalen -= size;
}

void shapestuff::FixupDoISphere(UByte *&dataptr, ULong &datalen)
{
	DOISPHERE_PTR ptr = (DOISPHERE_PTR)dataptr;

	Image_Map.AddImageMapToGlbList((UWord)ptr->image);//RJS 03Nov98
}

void shapestuff::FixupDoICylinder(UByte *&dataptr, ULong &datalen)
{
	DOICYLINDER_PTR ptr = (DOICYLINDER_PTR)dataptr;

	Image_Map.AddImageMapToGlbList((UWord)ptr->image);//RJS 03Nov98
}

void shapestuff::FixupDoIncln(UByte *&dataptr, ULong &datalen)
{
	DOINCLN_PTR	ptr = (DOINCLN_PTR)dataptr;
	if (ptr->imagamap)
		Image_Map.AddImageMapToGlbList((UWord)ptr->imagamap);
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoNTriangles
//Author		Robert Slater
//Date			Fri 25 Sep 1998
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoNTriangles(UByte *&dataptr, ULong &datalen)
{
	ULong size;
	UWord counter;

	DONTRIANGLES_PTR ptr = (DONTRIANGLES_PTR)dataptr;

	counter = ptr->count;

	//MapLog[ptr->animoff].GetMaps(ptr->material);

	size = counter * sizeof(TRINEXT);

	dataptr += size;

	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoNMaxPoints
//Author		Robert Slater
//Date			Mon 28 Sep 1998
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoNMaxPoints(UByte *&dataptr, ULong &datalen)
{
	ULong size;
	UWord counter;

	DONMAXPOINTS_PTR ptr = (DONMAXPOINTS_PTR)dataptr;

	counter = ptr->count;

	size = counter * sizeof(NMAXNEXT);

	dataptr += size;

	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoAnimTransform
//Author		Robert Slater
//Date			Wed 10 Nov 1999
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoAnimTransform(UByte *&dataptr, ULong &datalen)
{
	ULong size;
	UWord counter;

	DOANIMTRANSFORM_PTR ptr = (DOANIMTRANSFORM_PTR)dataptr;

	counter = ptr->count;

	size = counter * sizeof(ANIMPOINT);

	dataptr += size;

	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoTMORPHNPoints
//Author		Robert Slater
//Date			Mon 8 Dec 1997
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoTMorphNPoints(UByte *&dataptr, ULong &datalen)
{
	ULong size;

	DOTMORPHNPOINTS_PTR ptr = (DOTMORPHNPOINTS_PTR)dataptr;

	size = sizeof(DOTMORPHNPOINTS) + (ptr->nopoints * sizeof(TMORPHNNEXT));

	dataptr += size;

	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoAnimTransformHP
//Author		Robert Slater
//Date			Fri 3 Dec 1999
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoAnimTransformHP(UByte *&dataptr, ULong &datalen)
{
	ULong size;
	UWord counter;

	DOANIMTRANSFORMHP_PTR ptr = (DOANIMTRANSFORMHP_PTR)dataptr;

	counter = ptr->count;

	size = counter * sizeof(ANIMPOINT);

	dataptr += size;

	datalen -= size;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupBitsOffCockUnSet
//Author		Robert Slater
//Date			Wed 22 Mar 2000
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupBitsOffCockUnSet(UByte *&dataptr, ULong&)
{
	SWord	new_off,
			old_off;

	UByte	*temp;

	DOBITSOFFCOCKUNSET_PTR ptr = (DOBITSOFFCOCKUNSET_PTR)dataptr;

	old_off = ptr->offset;
	if (old_off)
	{
		temp = shp_base_ptr + old_off;

		new_off = temp - dataptr;

		ptr->offset = new_off;
	}
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupCollisionGoto
//Author		Robert Slater
//Date			Thu 21 Sep 2000
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupCollisionGoto(UByte *&dataptr, ULong &)
{
	SLong	new_off;
	UWord	old_off;

	UByte	*temp;

	DOCOLLISIONGOTO_PTR	ptr = (DOCOLLISIONGOTO_PTR)dataptr;

	old_off = ptr->offset;

	temp = shp_base_ptr + old_off;

	new_off = temp - dataptr;

	if (forwardref)
	{
		if (	(new_off > 65536)
			||	(new_off < 2)	)
			_Error.EmitSysErr(__FILE__":Bollocks offset!! (%d), shape %d,(%d --> %s)[%d]",new_off,ShapeFixing,instrcnt,inststr[lastinstr],debugcnt);
	}
	else
	{
		if (	(new_off > 32767)
			||	(new_off < -32768)	)
			_Error.EmitSysErr(__FILE__":Bollocks offset!! (%d), shape %d,(%d --> %s)[%d]",new_off,ShapeFixing,instrcnt,inststr[lastinstr],debugcnt);
	}


	ptr->offset = new_off;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		FixupDoNormal
//Author		Robert Slater
//Date			Thu 28 Sep 2000
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::FixupDoNormal(UByte *&dataptr, ULong &datalen)
{
	DONORMAL_PTR 	ptr = (DONORMAL_PTR)dataptr;
	ULong			size;

	size = ptr->nopoints * sizeof(UWord);

	dataptr += size;

	datalen -= size;
}



//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		settable
//Author		Paul.
//Date			Thu 12 Oct 1995
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
void shapestuff::settable()
{
	fixuptable = (shpinstfixptr) new shpinstfix[dosetglassrangeno+1];//RJS 01Dec97

	if (fixuptable)
	{
		fixuptable[dopointno].skipsize = sizeof(DOPOINT);
		fixuptable[dopolygonno].skipsize = sizeof(DOPOLYGON);
		fixuptable[dosetlcno].skipsize = sizeof(DOSETLC);
		fixuptable[dosetcolourno].skipsize = sizeof(DOSETCOLOUR);
		fixuptable[dolineno].skipsize = sizeof(DOLINE);
		fixuptable[doretno].skipsize = NULL;
		fixuptable[doifcrossno].skipsize = sizeof(DOIFCROSS);
		fixuptable[dogosubno].skipsize = sizeof(DOGOSUB);
		fixuptable[doifeqno].skipsize = sizeof(DOIFEQ);
		fixuptable[doifneno].skipsize = sizeof(DOIFNE);
		fixuptable[donopno].skipsize = sizeof(DONOP);
		fixuptable[dogroupno].skipsize = sizeof(DOGROUP);
		fixuptable[dogotono].skipsize = sizeof(DOGOTO);
		fixuptable[doendno].skipsize = NULL;						//PD 11Mar96
		fixuptable[dowindowdialno].skipsize = sizeof(DOWINDOWDIAL);//RJS 07Apr98
		fixuptable[doattitudeno].skipsize = sizeof(DOATTITUDE);	//RJS 01Apr98
		fixuptable[dodotno].skipsize = sizeof(DODOT);
		fixuptable[doscalesizeno].skipsize = sizeof(DOSCALESIZE);//RJS 03Mar98
		fixuptable[dogunsightno].skipsize = sizeof(DOGUNSIGHT);	//RJS 04Mar98
		fixuptable[dowheelsprayno].skipsize = sizeof(DOWHEELSPRAY);//RJS 16Mar98
		fixuptable[doifbrightno].skipsize = sizeof(DOIFBRIGHT);	//RJS 20Mar98
		fixuptable[doquikpolyno].skipsize = sizeof(DOQUIKPOLY);
		fixuptable[dofadeenvelopeno].skipsize = sizeof(DOFADEENVELOPE);//RJS 27Mar98
		fixuptable[dowhiteoutno].skipsize = sizeof(DOWHITEOUT);	//RJS 31Mar98
		fixuptable[donpointsno].skipsize = sizeof(DONPOINTS);
		fixuptable[don4cmpntsno].skipsize = sizeof(DON4CMPNTS);
		fixuptable[do4cmpntno].skipsize = sizeof(DO4CMPNT);
		fixuptable[dondupvecno].skipsize = sizeof(DONDUPVEC);	//RJS 29May98
		fixuptable[dondeltapointsno].skipsize = sizeof(DONDELTAPOINTS);//RJS 02Jun98
		fixuptable[dodrawsunno].skipsize = sizeof(DODRAWSUN);	//RJS 22Jun98
		fixuptable[dosetcolour256no].skipsize = sizeof(DOSETCOLOUR256);
		fixuptable[doswitchno].skipsize = sizeof(DOSWITCH);
		fixuptable[dosetcolourallno].skipsize = sizeof(DOSETCOLOURALL);
		fixuptable[dopoint2xno].skipsize = sizeof(DOPOINT2X);
		fixuptable[do4cmpt2xno].skipsize = sizeof(DO4CMPT2X);
		fixuptable[doifcaseno].skipsize = NULL;
		fixuptable[donincpntsno].skipsize = sizeof(DONINCPNTS);
		fixuptable[dotransparentonno].skipsize = sizeof(DOTRANSPARENTON);
		fixuptable[dotransparentoffno].skipsize = NULL;				//RJS 23Jun97
		fixuptable[dosphereno].skipsize = sizeof(DOSPHERE);
		fixuptable[dosmokedonno].skipsize = NULL;
		fixuptable[dosmokedoffno].skipsize = NULL;
		fixuptable[donormalno].skipsize = sizeof(DONORMAL);
		fixuptable[dosmoothpolyno].skipsize = sizeof(DOSMOOTHPOLY);
		fixuptable[dovectorno].skipsize = sizeof(DOVECTOR);
		fixuptable[dotransformlightno].skipsize = sizeof(DOTRANSFORMLIGHT);//RJS 27Sep00
		fixuptable[dolshadeonno].skipsize = sizeof(DOLSHADEON);			//RJS 30APR98
		fixuptable[dorelpolyno].skipsize = sizeof(DORELPOLY);
		fixuptable[donspheresno].skipsize = NULL;				//RJS 13Jul98
		fixuptable[donspheresimapdno].skipsize = NULL;			//RJS 13Jul98
		fixuptable[doweaponoffno].skipsize = sizeof(DOWEAPONOFF);
		fixuptable[dodrawreflectpolyno].skipsize = sizeof(DODRAWREFLECTPOLY);
		fixuptable[doresetanimno].skipsize = NULL;				//RJS 13Nov98
		fixuptable[dospinno].skipsize = sizeof(DOSPIN);			//RJS 18Nov98
		fixuptable[dosetcolourhno].skipsize = sizeof(DOSETCOLOURH);
		fixuptable[doquiksmoothpolyno].skipsize = sizeof(DOQUIKSMOOTHPOLY);
		fixuptable[doreposno].skipsize = NULL;
		fixuptable[dodepthcolourno].skipsize = NULL;
		fixuptable[dodepthpolyno].skipsize = NULL;
		fixuptable[doimagemapno].skipsize = NULL;
		fixuptable[docreateipolyno].skipsize = sizeof(DOCREATEIPOLY);
		fixuptable[docreateivertno].skipsize = sizeof(DOCREATEIVERT);
		fixuptable[dodrawipolyno].skipsize = sizeof(DODRAWIPOLY);
		fixuptable[docopyivertno].skipsize = sizeof(DOCOPYIVERT);
		fixuptable[dosmthrelpolyno].skipsize = sizeof(DORELPOLY);
		fixuptable[doquikrelpolyno].skipsize = sizeof(DORELPOLY);
		fixuptable[donsubsno].skipsize = NULL;
		fixuptable[dobitsofffxno].skipsize = sizeof(DOBITSOFFFX);//RJS 15Jan99
		fixuptable[doondamagedno].skipsize = sizeof(DOONDAMAGED);//RJS 18Jan99
		fixuptable[dosetmipmapno].skipsize = sizeof(DOSETMIPMAP);//RJS 24May99
		fixuptable[donvecno].skipsize = sizeof(DONVEC);
		fixuptable[donextvecno].skipsize = sizeof(NEXTVEC);
		fixuptable[donpoint2xno].skipsize = sizeof(DONPOINT2X);
		fixuptable[docallshapeno].skipsize = sizeof(DOCALLSHAPE);
		fixuptable[dosmokepntno].skipsize = sizeof(DOSMOKEPNT);
		fixuptable[dobitsoffno].skipsize = sizeof(DOBITSOFF);
		fixuptable[doplumepntno].skipsize = sizeof(DOPLUMEPNT);
		fixuptable[doisphereno].skipsize = sizeof(DOISPHERE);
		fixuptable[docreaterpolyno].skipsize = sizeof(DOCREATERPOLY);
		fixuptable[dodrawipolysno].skipsize = sizeof(DODRAWIPOLYS);
		fixuptable[domappolyno].skipsize = NULL;
		fixuptable[dosetmapmapno].skipsize = NULL;
		fixuptable[do3dbreakno].skipsize = NULL;
		fixuptable[docylinderno].skipsize = sizeof(DOCYLINDER);
		fixuptable[dontpointsno].skipsize = sizeof(DONTPOINTS);
		fixuptable[dosetmapoffno].skipsize = NULL;
		fixuptable[dosetmappingplanerno].skipsize = sizeof(DOSETMAPPINGPLANER);
		fixuptable[dosetmappingtanno].skipsize = sizeof(DOSETMAPPINGTAN);
		fixuptable[dosmktrailno].skipsize = sizeof(DOSMKTRAIL);		//RJS 20Sep96
		fixuptable[dooffsetpntno].skipsize = sizeof(DOOFFSETPNT);
		fixuptable[doicylinderno].skipsize = sizeof(DOICYLINDER);
		fixuptable[dodrawbetweenno].skipsize = sizeof(DRAWBETWEEN);	//MGA 28Nov95
		fixuptable[docreatebumppolyno].skipsize = sizeof(DOCREATEBUMPPOLY);//PD 15Jan96
		fixuptable[docopybvertno].skipsize = sizeof(DOCOPYBVERT);	//PD 15Jan96
		fixuptable[dodrawbpolyno].skipsize = NULL;
	//DeadCode PD 28Mar96 	fixuptable[dodrawcloudno].skipsize = sizeof(DODRAWCLOUD);	//PD 22Jan96
		fixuptable[dodrawrpolyno].skipsize = sizeof(DODRAWRPOLY);	//PD 28Mar96
		fixuptable[dodrawopolyno].skipsize = NULL;					//PD 16Apr96
		fixuptable[dorealisphereno].skipsize = sizeof(DOREALISPHERE);//RJS 16Dec97
		fixuptable[dolauncherno].skipsize = sizeof(DOLAUNCHER);		//PD 10Jul96
		fixuptable[dodialno].skipsize = sizeof(DODIAL);				//PD 10Jul96
		fixuptable[docompassno].skipsize = sizeof(DOCOMPASS);		//PD 10Jul96
		fixuptable[doiswitchno].skipsize = sizeof(DOISWITCH);		//PD 10Jul96
		fixuptable[doinclnno].skipsize = sizeof(DOINCLN);			//RJS 17Sep96

		fixuptable[docollisionno].skipsize = sizeof(DOCOLLISION);	//RJS 18Feb97
		fixuptable[doanimationno].skipsize = sizeof(DOANIMATION);	//RJS 18Feb97
		fixuptable[dodamageno].skipsize = sizeof(DODAMAGE);			//RJS 18Feb97
		fixuptable[doeffectno].skipsize = sizeof(DOEFFECT);			//RJS 18Feb97
		fixuptable[dodrawstationno].skipsize = sizeof(DODRAWSTATION);//RJS 28Feb97
		fixuptable[docaserangeno].skipsize = NULL;					//RJS 03Mar97
		fixuptable[doifpilotedno].skipsize = sizeof(DOIFPILOTED);	//RJS 07Mar97
		fixuptable[donivertsno].skipsize = sizeof(DONIVERTS);		//RJS 20Mar97

		fixuptable[dotrifanno].skipsize = sizeof(DOTRIFAN);			//RJS 27Mar97
		fixuptable[dotrizagno].skipsize = sizeof(DOTRIZAG);			//RJS 27Mar97

		fixuptable[dotrifanflatno].skipsize = sizeof(DOTRIFANFLAT);	//RJS 16Apr97
		fixuptable[dotrizagflatno].skipsize = sizeof(DOTRIZAGFLAT);	//RJS 16Apr97

		fixuptable[dostretchpointno].skipsize = sizeof(DOSTRETCHPOINT);//RJS 09Jun97
		fixuptable[dostretchmapno].skipsize = sizeof(DOSTRETCHMAP);	//RJS 09Jun97

		fixuptable[doflipvectorno].skipsize = sizeof(DOFLIPVECTOR);	//RJS 06Aug97
		fixuptable[doflipnvecno].skipsize = sizeof(DOFLIPNVEC);		//RJS 06Aug97

		fixuptable[domorphpointno].skipsize = sizeof(DOMORPHPOINT);	//RJS 04Dec97
		fixuptable[domorphnpointsno].skipsize = NULL;				//RJS 08Dec97
		fixuptable[douserealtimeno].skipsize = sizeof(DOUSEREALTIME);//RJS 10Dec97
		fixuptable[dotimerphaseno].skipsize = NULL;					//RJS 10Dec97
		fixuptable[dobloblineno].skipsize = sizeof(DOBLOBLINE);
		fixuptable[dowheeldamageno].skipsize = sizeof(DOWHEELDAMAGE);
		fixuptable[dolightno].skipsize = sizeof(DOLIGHT);
		fixuptable[lightdatano].skipsize = sizeof(LIGHTDATA);		//RJS 19Dec97
		fixuptable[dolighttimerno].skipsize = sizeof(DOLIGHTTIMER);//RJS 06Jan98
		fixuptable[dodigitdialno].skipsize = sizeof(DODIGITDIAL);//RJS 08Jan98
		fixuptable[donianimvertsno].skipsize = sizeof(DONIANIMVERTS);//RJS 13Jan98
		fixuptable[dosetluminosityno].skipsize = sizeof(DOSETLUMINOSITY);//RJS 20Jan98
		fixuptable[dobitsoffcockno].skipsize = sizeof(DOBITSOFFCOCK);//RJS 23Jan98
		fixuptable[domorphsphereno].skipsize = sizeof(DOMORPHSPHERE);//RJS 27Jan98
		fixuptable[domorphcylinderimapdno].skipsize = sizeof(DOMORPHCYLINDERIMAPD);//RJS 19Nov98
		fixuptable[doheathazeno].skipsize = sizeof(DOHEATHAZE);		//RJS 30Jan98

		fixuptable[doifhard3dno].skipsize = sizeof(DOIFHARD3D);		//RJS 04Feb98
		fixuptable[domorphnsphrsno].skipsize = NULL;		//RJS 05Feb98
		fixuptable[domorphnsphrsimapdno].skipsize = NULL;		//RJS 05Feb98

		fixuptable[dosetposeno].skipsize = sizeof(DOSETPOSE);	//RJS 10Nov99
		fixuptable[doenvanimno].skipsize = sizeof(DOENVANIM);	//RJS 10Nov99
		fixuptable[dontrianglesno].skipsize = sizeof(DONTRIANGLES);//RJS 10Nov99
		fixuptable[donmaxpointsno].skipsize = sizeof(DONMAXPOINTS);//RJS 10Nov99
		fixuptable[doanimmatrixno].skipsize = sizeof(DOANIMMATRIX);//RJS 10Nov99

		fixuptable[dobitsoffblokeno].skipsize = sizeof(DOBITSOFFBLOKE);//RJS 10Nov99
		fixuptable[dosetmaterialtypeno].skipsize = sizeof(DOSETMATERIALTYPE);//RJS 10Nov99
		fixuptable[doanimtransformno].skipsize = sizeof(DOANIMTRANSFORM);//RJS 10Nov99
		fixuptable[docreatemirrorno].skipsize = sizeof(DOCREATEMIRROR);//RJS 18Nov99
		fixuptable[dointeractivehitboxno].skipsize = sizeof(DOINTERACTIVEHITBOX);//RJS 19Nov99
		fixuptable[dotmorphnpointsno].skipsize = NULL;			//RJS 01Dec99
		fixuptable[doabsolutetimerphaseno].skipsize = NULL;		//RJS 02Dec99
		fixuptable[doanimtransformhpno].skipsize = sizeof(DOANIMTRANSFORMHP);//RJS 03Dec99
		fixuptable[doontimerno].skipsize = sizeof(DOONTIMER);
		fixuptable[dofingerno].skipsize = sizeof(DOFINGER);		//RJS 13Dec99
		fixuptable[donanimvecno].skipsize = sizeof(DONANIMVEC);	//RJS 17Feb00
		fixuptable[doambientonno].skipsize = sizeof(DOAMBIENTON);//RJS 23Feb00
		fixuptable[doambientoffno].skipsize = sizeof(DOAMBIENTOFF);//RJS 23Feb00
		fixuptable[domovegunno].skipsize = sizeof(DOMOVEGUN);	//RJS 28Feb00
		fixuptable[dobitsoffcockunsetno].skipsize = sizeof(DOBITSOFFCOCKUNSET);//RJS 22Mar00
		fixuptable[doneedleno].skipsize = sizeof(DONEEDLE);		//RJS 12Apr00
		fixuptable[dosetblendtypeno].skipsize = sizeof(DOSETBLENDTYPE);//RJS 16May00
		fixuptable[dousefadeenvelopeno].skipsize = sizeof(DOUSEFADEENVELOPE);//RJS 18May00
		fixuptable[dorestorealphano].skipsize = sizeof(DORESTOREALPHA);//RJS 18May00
		fixuptable[docollisiongotono].skipsize = sizeof(DOCOLLISIONGOTO);//RJS 21Sep00
		fixuptable[dosetzbiasno].skipsize = sizeof(DOSETZBIAS);//RJS 21Sep00

		fixuptable[dosetglassrangeno].skipsize = sizeof(DOSETGLASSRANGE);

		fixuptable[dopointno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dopolygonno].fixrtn = &shapestuff::FixupPolygon;
		fixuptable[dosetlcno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dosetcolourno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dolineno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[doretno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[doifcrossno].fixrtn = &shapestuff::FixupIfCross;
		fixuptable[dogosubno].fixrtn = &shapestuff::FixupGoto;
		fixuptable[doifeqno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[doifneno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[donopno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dogroupno].fixrtn = &shapestuff::FixupDoGroup;
		fixuptable[dogotono].fixrtn = &shapestuff::FixupGoto;
		fixuptable[doendno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dowindowdialno].fixrtn = &shapestuff::FixupStubb;			//RJS 07Apr98
		fixuptable[doattitudeno].fixrtn = &shapestuff::FixupStubb;			//RJS 01Apr98
		fixuptable[dodotno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[doscalesizeno].fixrtn = &shapestuff::FixupStubb;			//RJS 03Mar98
		fixuptable[dogunsightno].fixrtn = &shapestuff::FixupDoGunSight;		//RJS 04Mar98
		fixuptable[dowheelsprayno].fixrtn = &shapestuff::FixupStubb;			//RJS 16Mar98
		fixuptable[doifbrightno].fixrtn = &shapestuff::FixupDoIfBright;		//RJS 20Mar98
		fixuptable[doquikpolyno].fixrtn = &shapestuff::FixupPolygon;
		fixuptable[dofadeenvelopeno].fixrtn = &shapestuff::FixupStubb;		//RJS 27Mar98
		fixuptable[dowhiteoutno].fixrtn = &shapestuff::FixupStubb;			//RJS 31Mar98
		fixuptable[donpointsno].fixrtn = &shapestuff::FixupDoNPoints;
		fixuptable[don4cmpntsno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[do4cmpntno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dondupvecno].fixrtn = &shapestuff::FixupStubb;			//RJS 29May98
		fixuptable[dondeltapointsno].fixrtn = &shapestuff::FixupDoNDeltaPoints;//RJS 02Jun98
		fixuptable[dodrawsunno].fixrtn = &shapestuff::FixupStubb;			//RJS 22Jun98
		fixuptable[dosetcolour256no].fixrtn = &shapestuff::FixupStubb;
		fixuptable[doswitchno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dosetcolourallno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dopoint2xno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[do4cmpt2xno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[doifcaseno].fixrtn = &shapestuff::FixupIfCase;
		fixuptable[donincpntsno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dotransparentonno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dotransparentoffno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dosphereno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dosmokedonno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dosmokedoffno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[donormalno].fixrtn = &shapestuff::FixupDoNormal;			//RJS 28Sep00
		fixuptable[dosmoothpolyno].fixrtn = &shapestuff::FixupSmoothPoly;
		fixuptable[dovectorno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dotransformlightno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dolshadeonno].fixrtn = &shapestuff::FixupStubb;			//RJS 30Apr98
		fixuptable[dorelpolyno].fixrtn = &shapestuff::FixupDoRelpoly;
		fixuptable[donspheresno].fixrtn = &shapestuff::FixupDoNSpheres;		//RJS 13Jul98
		fixuptable[donspheresimapdno].fixrtn = &shapestuff::FixupDoNSpheresImapd;//RJS 13Jul98
		fixuptable[doweaponoffno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dodrawreflectpolyno].fixrtn = &shapestuff::FixupDoDrawReflectPoly;
		fixuptable[doresetanimno].fixrtn = &shapestuff::FixupStubb;			//RJS 13Nov98
		fixuptable[dospinno].fixrtn = &shapestuff::FixupStubb;				//RJS 17Nov98
		fixuptable[dosetcolourhno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[doquiksmoothpolyno].fixrtn = &shapestuff::FixupSmoothPoly;
		fixuptable[doreposno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dodepthcolourno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dodepthpolyno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[doimagemapno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[docreateipolyno].fixrtn = &shapestuff::FixupCreateIPoly;
		fixuptable[docreateivertno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dodrawipolyno].fixrtn = &shapestuff::FixupDoDrawIPoly;
		fixuptable[docopyivertno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dosmthrelpolyno].fixrtn = &shapestuff::FixupDoRelpoly;
		fixuptable[doquikrelpolyno].fixrtn = &shapestuff::FixupDoRelpoly;
		fixuptable[donsubsno].fixrtn = &shapestuff::FixupDoNSubs;
		fixuptable[dobitsofffxno].fixrtn = &shapestuff::FixupStubb;			//RJS 15Jan99
		fixuptable[doondamagedno].fixrtn = &shapestuff::FixupStubb;			//RJS 18Jan99
		fixuptable[dosetmipmapno].fixrtn = &shapestuff::FixupStubb;			//RJS 24May99
		fixuptable[donvecno].fixrtn = &shapestuff::FixupNVec;
		fixuptable[donextvecno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[donpoint2xno].fixrtn = &shapestuff::FixupNPoint2X;
		fixuptable[docallshapeno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dosmokepntno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dobitsoffno].fixrtn = &shapestuff::FixupBitsOff;				//PD 17Apr96
		fixuptable[doplumepntno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[doisphereno].fixrtn = &shapestuff::FixupDoISphere;			//RJS 03Nov98
		fixuptable[docreaterpolyno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dodrawipolysno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[domappolyno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dosetmapmapno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[do3dbreakno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[docylinderno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dontpointsno].fixrtn = &shapestuff::FixupDoNTPoints;
		fixuptable[dosetmapoffno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dosetmappingplanerno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dosetmappingtanno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dosmktrailno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dooffsetpntno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[doicylinderno].fixrtn = &shapestuff::FixupDoICylinder;		//RJS 03Nov98
		fixuptable[dodrawbetweenno].fixrtn = &shapestuff::FixupDrawBetween;		//MGA 28Nov95
		fixuptable[docreatebumppolyno].fixrtn = &shapestuff::FixupCreateBPoly;		//PD 15Jan96
		fixuptable[docopybvertno].fixrtn = &shapestuff::FixupStubb;				//PD 15Jan96
		fixuptable[dodrawbpolyno].fixrtn = &shapestuff::FixupStubb;				//PD 15Jan96
		fixuptable[dodrawrpolyno].fixrtn = &shapestuff::FixupStubb;				//PD 28Mar96
		fixuptable[dodrawopolyno].fixrtn = &shapestuff::FixupStubb;				//PD 16Apr96
	//DeadCode PD 28Mar96 	fixuptable[dodrawcloudno].fixrtn = &shapestuff::FixupDrawCloud;			//PD 22Jan96
		fixuptable[dorealisphereno].fixrtn = &shapestuff::FixupStubb;		//RJS 16Dec97
		fixuptable[dolauncherno].fixrtn = &shapestuff::FixupStubb;				//PD 10Jul96
		fixuptable[dodialno].fixrtn = &shapestuff::FixupStubb;					//PD 10Jul96
		fixuptable[docompassno].fixrtn = &shapestuff::FixupStubb;				//PD 10Jul96
		fixuptable[doiswitchno].fixrtn = &shapestuff::FixupStubb;				//PD 10Jul96
		fixuptable[doinclnno].fixrtn = &shapestuff::FixupDoIncln;				//RJS 06Apr99

		fixuptable[docollisionno].fixrtn = &shapestuff::FixupDoCollision;		//RJS 18Feb97
		fixuptable[doanimationno].fixrtn = &shapestuff::FixupStubb;				//RJS 18Feb97
		fixuptable[dodamageno].fixrtn = &shapestuff::FixupStubb;					//RJS 18Feb97
		fixuptable[doeffectno].fixrtn = &shapestuff::FixupStubb;					//RJS 18Feb97
		fixuptable[dodrawstationno].fixrtn = &shapestuff::FixupStubb;			//RJS 28Feb97
		fixuptable[docaserangeno].fixrtn = &shapestuff::FixupDoCaseRange;		//RJS 03Mar97
		fixuptable[doifpilotedno].fixrtn = &shapestuff::FixupDoIfPiloted;		//RJS 07Mar97
		fixuptable[donivertsno].fixrtn = &shapestuff::FixupDoNIVerts;			//RJS 20Mar97

		fixuptable[dotrifanno].fixrtn = &shapestuff::FixupDoTriFan;				//RJS 27Mar97
		fixuptable[dotrizagno].fixrtn = &shapestuff::FixupDoTriZag;				//RJS 27Mar97

		fixuptable[dotrifanflatno].fixrtn = &shapestuff::FixupDoTriFanFlat;		//RJS 16Apr97
		fixuptable[dotrizagflatno].fixrtn = &shapestuff::FixupDoTriZagFlat;		//RJS 16Apr97

		fixuptable[dostretchpointno].fixrtn = &shapestuff::FixupStubb;			//RJS 09Jun97
		fixuptable[dostretchmapno].fixrtn = &shapestuff::FixupStubb;				//RJS 09Jun97

		fixuptable[doflipvectorno].fixrtn = &shapestuff::FixupStubb;				//RJS 06Aug97
		fixuptable[doflipnvecno].fixrtn = &shapestuff::FixupStubb;				//RJS 06Aug97

		fixuptable[domorphpointno].fixrtn = &shapestuff::FixupStubb;				//RJS 04Dec97
		fixuptable[domorphnpointsno].fixrtn = &shapestuff::FixupDoMorphNPoints;	//RJS 08Dec97
		fixuptable[douserealtimeno].fixrtn = &shapestuff::FixupStubb;			//RJS 10Dec97
		fixuptable[dotimerphaseno].fixrtn = &shapestuff::FixupDoTimerPhase;		//RJS 10Dec97
		fixuptable[dobloblineno].fixrtn = &shapestuff::FixupStubb;				//RJS 15Dec97
		fixuptable[dowheeldamageno].fixrtn = &shapestuff::FixupStubb;
		fixuptable[dolightno].fixrtn = &shapestuff::FixupStubb;				//RJS 17Dec97
		fixuptable[lightdatano].fixrtn = &shapestuff::FixupStubb;			//RJS 19Dec97
		fixuptable[dolighttimerno].fixrtn = &shapestuff::FixupStubb;			//RJS 06Jan98
		fixuptable[dodigitdialno].fixrtn = &shapestuff::FixupStubb;			//RJS 08Jan98
		fixuptable[donianimvertsno].fixrtn = &shapestuff::FixupDoNiAnimVerts;//RJS 13Jan98
		fixuptable[dosetluminosityno].fixrtn = &shapestuff::FixupStubb;		//RJS 20Jan98
		fixuptable[dobitsoffcockno].fixrtn = &shapestuff::FixupBitsOffCock;	//RJS 23Jan98
		fixuptable[domorphsphereno].fixrtn = &shapestuff::FixupStubb;		//RJS 27Jan98
		fixuptable[domorphcylinderimapdno].fixrtn = &shapestuff::FixupStubb;	//RJS 19Nov98
		fixuptable[doheathazeno].fixrtn = &shapestuff::FixupStubb;		//RJS 30Jan98

		fixuptable[doifhard3dno].fixrtn = &shapestuff::FixupDoIfHard3d;		//RJS 04Feb98
		fixuptable[domorphnsphrsno].fixrtn = &shapestuff::FixupDoMorphNSphrs;		//RJS 05Feb98
		fixuptable[domorphnsphrsimapdno].fixrtn = &shapestuff::FixupDoMorphNSphrsImapd;		//RJS 05Feb98

		fixuptable[dosetposeno].fixrtn = &shapestuff::FixupStubb;			//RJS 10Nov99
		fixuptable[doenvanimno].fixrtn = &shapestuff::FixupStubb;			//RJS 10Nov99
		fixuptable[dontrianglesno].fixrtn = &shapestuff::FixupDoNTriangles;	//RJS 10Nov99
		fixuptable[donmaxpointsno].fixrtn = &shapestuff::FixupDoNMaxPoints;	//RJS 10Nov99
		fixuptable[doanimmatrixno].fixrtn = &shapestuff::FixupStubb;			//RJS 10Nov99

		fixuptable[dobitsoffblokeno].fixrtn = &shapestuff::FixupStubb;		//RJS 10Nov99
		fixuptable[dosetmaterialtypeno].fixrtn = &shapestuff::FixupStubb;	//RJS 10Nov99
		fixuptable[doanimtransformno].fixrtn = &shapestuff::FixupDoAnimTransform;//RJS 10Nov99
		fixuptable[docreatemirrorno].fixrtn = &shapestuff::FixupStubb;		//RJS 18Nov99
		fixuptable[dointeractivehitboxno].fixrtn = &shapestuff::FixupStubb;	//RJS 19Nov99
		fixuptable[dotmorphnpointsno].fixrtn = &shapestuff::FixupDoTMorphNPoints;//RJS 01Dec99
		fixuptable[doabsolutetimerphaseno].fixrtn = &shapestuff::FixupDoAbsTimerPhase;//RJS 02Dec99
		fixuptable[doanimtransformhpno].fixrtn = &shapestuff::FixupDoAnimTransformHP;//RJS 03Dec99
		fixuptable[doontimerno].fixrtn = &shapestuff::FixupStubb;			//RJS 10Dec99
		fixuptable[dofingerno].fixrtn = &shapestuff::FixupStubb;				//RJS 13Dec99
		fixuptable[donanimvecno].fixrtn = &shapestuff::FixupNAnimVec;
		fixuptable[doambientonno].fixrtn = &shapestuff::FixupStubb;			//RJS 23Feb00
		fixuptable[doambientoffno].fixrtn = &shapestuff::FixupStubb;			//RJS 23Feb00
		fixuptable[domovegunno].fixrtn = &shapestuff::FixupStubb;			//RJS 28Feb00
		fixuptable[dobitsoffcockunsetno].fixrtn = &shapestuff::FixupBitsOffCockUnSet;//RJS 22Mar00
		fixuptable[doneedleno].fixrtn = &shapestuff::FixupStubb;				//RJS 12Apr00
		fixuptable[dosetblendtypeno].fixrtn = &shapestuff::FixupStubb;		//RJS 16May00
		fixuptable[dousefadeenvelopeno].fixrtn = &shapestuff::FixupStubb;	//RJS 18May00
		fixuptable[dorestorealphano].fixrtn = &shapestuff::FixupStubb;		//RJS 18May00
		fixuptable[docollisiongotono].fixrtn = &shapestuff::FixupCollisionGoto;//RJS 21Sep00
		fixuptable[dosetzbiasno].fixrtn = &shapestuff::FixupStubb;			//RJS 21Sep00

		fixuptable[dosetglassrangeno].fixrtn = &shapestuff::FixupStubb;
	}
	else
		_Error.EmitSysErr(__FILE__":Could not generate FixUpTable!");//RJS 01Dec97

//DeadCode PD 13Mar96 	UWord	tablesize = dosetglassrangeno;
}

//컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
//Procedure		GetShapeScale
//Author		Paul.
//Date			Tue 23 Apr 1996
//
//Description
//
//Inputs
//
//Returns
//
//------------------------------------------------------------------------------
ScaleType shapestuff::GetShapeScale(ShapeDescPtr spdptr)
{
	UWord	retval=(UWord )(spdptr->Type.scaletype);

	retval &= SHP_GRP;

	return (ScaleType )retval;
}
