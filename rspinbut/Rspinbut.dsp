# Microsoft Developer Studio Project File - Name="RSpinBut" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=RSpinBut - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Rspinbut.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Rspinbut.mak" CFG="RSpinBut - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "RSpinBut - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "RSpinBut - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "RSpinBut - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "RSpinBut - Win32 Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "RSpinBut - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "\BOB\Release\exe"
# PROP Intermediate_Dir "\BOB\Release\RspinBut"
# PROP Target_Ext "ocx"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /Z7 /O2 /I "..\h" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x809 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /base:"0x10800000" /subsystem:windows /dll /debug /machine:I386
# Begin Custom Build - Registering ActiveX Control...
OutDir=\BOB\Release\exe
TargetPath=\BOB\Release\exe\Rspinbut.ocx
InputPath=\BOB\Release\exe\Rspinbut.ocx
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "RSpinBut - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "\bob\Debug\exe"
# PROP Intermediate_Dir "\bob\Debug\Rspinbut"
# PROP Target_Ext "ocx"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\h" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x809 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /base:"0x10800000" /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# SUBTRACT LINK32 /map
# Begin Custom Build - Registering ActiveX Control...
OutDir=\bob\Debug\exe
TargetPath=\bob\Debug\exe\Rspinbut.ocx
InputPath=\bob\Debug\exe\Rspinbut.ocx
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "RSpinBut - Win32 Unicode Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugU"
# PROP BASE Intermediate_Dir "DebugU"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugU"
# PROP Intermediate_Dir "DebugU"
# PROP Target_Ext "ocx"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x809 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /base:"0x10800000" /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# Begin Custom Build - Registering ActiveX Control...
OutDir=.\DebugU
TargetPath=.\DebugU\Rspinbut.ocx
InputPath=.\DebugU\Rspinbut.ocx
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "RSpinBut - Win32 Unicode Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseU"
# PROP BASE Intermediate_Dir "ReleaseU"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "\Mig\Release\exe"
# PROP Intermediate_Dir "\Mig\Release\RspinBut"
# PROP Target_Ext "ocx"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\h" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x809 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /base:"0x10800000" /subsystem:windows /dll /machine:I386
# Begin Custom Build - Registering ActiveX Control...
OutDir=\Mig\Release\exe
TargetPath=\Mig\Release\exe\Rspinbut.ocx
InputPath=\Mig\Release\exe\Rspinbut.ocx
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "RSpinBut - Win32 Release"
# Name "RSpinBut - Win32 Debug"
# Name "RSpinBut - Win32 Unicode Debug"
# Name "RSpinBut - Win32 Unicode Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\Mfc\Getshadw.cpp

!IF  "$(CFG)" == "RSpinBut - Win32 Release"

!ELSEIF  "$(CFG)" == "RSpinBut - Win32 Debug"

!ELSEIF  "$(CFG)" == "RSpinBut - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "RSpinBut - Win32 Unicode Release"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Rspinbtc.cpp

!IF  "$(CFG)" == "RSpinBut - Win32 Release"

!ELSEIF  "$(CFG)" == "RSpinBut - Win32 Debug"

!ELSEIF  "$(CFG)" == "RSpinBut - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "RSpinBut - Win32 Unicode Release"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Rspinbtp.cpp

!IF  "$(CFG)" == "RSpinBut - Win32 Release"

!ELSEIF  "$(CFG)" == "RSpinBut - Win32 Debug"

!ELSEIF  "$(CFG)" == "RSpinBut - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "RSpinBut - Win32 Unicode Release"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RSpinBut.cpp

!IF  "$(CFG)" == "RSpinBut - Win32 Release"

!ELSEIF  "$(CFG)" == "RSpinBut - Win32 Debug"

!ELSEIF  "$(CFG)" == "RSpinBut - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "RSpinBut - Win32 Unicode Release"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RSpinBut.def
# End Source File
# Begin Source File

SOURCE=.\RSpinBut.odl
# End Source File
# Begin Source File

SOURCE=.\RSpinBut.rc
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\font.h
# End Source File
# Begin Source File

SOURCE=.\picture.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\rspinbtc.h
# End Source File
# Begin Source File

SOURCE=.\rspinbtp.h
# End Source File
# Begin Source File

SOURCE=.\RSpinBut.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\down.bmp
# End Source File
# Begin Source File

SOURCE=.\Rspinbtc.bmp
# End Source File
# Begin Source File

SOURCE=.\RSpinButCtl.bmp
# End Source File
# Begin Source File

SOURCE=.\up.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\RSpinBut.lic

!IF  "$(CFG)" == "RSpinBut - Win32 Release"

# Begin Custom Build - Copying license file...
OutDir=\BOB\Release\exe
ProjDir=.
TargetName=Rspinbut
InputPath=.\RSpinBut.lic

"$(OutDir)\$(TargetName).lic" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(ProjDir)\$(TargetName).lic" "$(OutDir)"

# End Custom Build

!ELSEIF  "$(CFG)" == "RSpinBut - Win32 Debug"

# Begin Custom Build - Copying license file...
OutDir=\bob\Debug\exe
ProjDir=.
TargetName=Rspinbut
InputPath=.\RSpinBut.lic

"$(OutDir)\$(TargetName).lic" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(ProjDir)\$(TargetName).lic" "$(OutDir)"

# End Custom Build

!ELSEIF  "$(CFG)" == "RSpinBut - Win32 Unicode Debug"

# Begin Custom Build - Copying license file...
OutDir=.\DebugU
ProjDir=.
TargetName=Rspinbut
InputPath=.\RSpinBut.lic

"$(OutDir)\$(TargetName).lic" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(ProjDir)\$(TargetName).lic" "$(OutDir)"

# End Custom Build

!ELSEIF  "$(CFG)" == "RSpinBut - Win32 Unicode Release"

# Begin Custom Build - Copying license file...
OutDir=\Mig\Release\exe
ProjDir=.
TargetName=Rspinbut
InputPath=.\RSpinBut.lic

"$(OutDir)\$(TargetName).lic" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(ProjDir)\$(TargetName).lic" "$(OutDir)"

# End Custom Build

!ENDIF 

# End Source File
# End Target
# End Project
# Section RSpinBut : {C3270E64-6D6B-11d6-A1F0-444553540000}
# 	2:5:Class:CRSpinBut
# 	2:10:HeaderFile:rspinbut1.h
# 	2:8:ImplFile:rspinbut1.cpp
# End Section
# Section RSpinBut : {BEF6E003-A874-101A-8BBA-00AA00300CAB}
# 	2:5:Class:COleFont
# 	2:10:HeaderFile:font.h
# 	2:8:ImplFile:font.cpp
# End Section
# Section RSpinBut : {7BF80981-BF32-101A-8BBB-00AA00300CAB}
# 	2:5:Class:CPicture
# 	2:10:HeaderFile:picture.h
# 	2:8:ImplFile:picture.cpp
# End Section
# Section RSpinBut : {C3270E66-6D6B-11d6-A1F0-444553540000}
# 	2:21:DefaultSinkHeaderFile:rspinbut1.h
# 	2:16:DefaultSinkClass:CRSpinBut
# End Section
