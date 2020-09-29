# Microsoft Developer Studio Project File - Name="BoxManagerService" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=BoxManagerService - Win32 Debug for Oracle10g
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "BoxManagerService.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "BoxManagerService.mak" CFG="BoxManagerService - Win32 Debug for Oracle10g"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "BoxManagerService - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "BoxManagerService - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "BoxManagerService - Win32 Release for Oracle8i" (based on "Win32 (x86) Application")
!MESSAGE "BoxManagerService - Win32 Debug for Oracle8i" (based on "Win32 (x86) Application")
!MESSAGE "BoxManagerService - Win32 Release for Oracle9i" (based on "Win32 (x86) Application")
!MESSAGE "BoxManagerService - Win32 Debug for Oracle9i" (based on "Win32 (x86) Application")
!MESSAGE "BoxManagerService - Win32 Release for Oracle10g" (based on "Win32 (x86) Application")
!MESSAGE "BoxManagerService - Win32 Debug for Oracle10g" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/Pantheon/Pandora/BoxManagerService", TBZDAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "BoxManagerService - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../Runtime"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../../../../Lib/INFINITT_LIB/INFINITT_LIB36" /I "D:\oracle\ora805\PRO80\C\INCLUDE" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /FR /YX"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 BoxManagerConfig.lib LIBGEN.lib sqllib80.lib netapi32.lib dunzip32.lib IRSCipherLib.lib /nologo /subsystem:windows /machine:I386 /out:"../Runtime/BoxManagerService.exe" /libpath:"../../../../Lib/INFINITT_LIB/INFINITT_LIB36" /libpath:"D:\oracle\ora805\PRO80\LIB\MSVC" /libpath:"../Runtime" /libpath:"../../../../Lib/INFINITT_LIB/Cipher/Cipher1.1"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "BoxManagerService - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../Runtime"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../../../../Lib/INFINITT_LIB/INFINITT_LIB36" /I "D:\oracle\ora805\PRO80\C\INCLUDE" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 BoxManagerConfigD.lib LIBGEND.lib sqllib80.lib netapi32.lib dunzip32.lib IRSCipherLibD.lib /nologo /subsystem:windows /debug /machine:I386 /out:"../Runtime/BoxManagerServiceD.exe" /pdbtype:sept /libpath:"../../../../Lib/INFINITT_LIB/INFINITT_LIB36" /libpath:"D:\oracle\ora805\PRO80\LIB\MSVC" /libpath:"../Runtime" /libpath:"../../../../Lib/INFINITT_LIB/Cipher/Cipher1.1"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "BoxManagerService - Win32 Release for Oracle8i"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "BoxManagerService___Win32_Release_for_Oracle8i"
# PROP BASE Intermediate_Dir "BoxManagerService___Win32_Release_for_Oracle8i"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../Runtime"
# PROP Intermediate_Dir "Release8i"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /YX"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../../../../Lib/INFINITT_LIB/INFINITT_LIB36" /I "D:\oracle\ora817\precomp\public" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /YX"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 ../Release/PandoraConfig.lib LIBGEN.lib orasql8.lib netapi32.lib dunzip32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 BoxManagerConfig.lib LIBGEN.lib orasql8.lib netapi32.lib dunzip32.lib IRSCipherLib.lib mpr.lib /nologo /subsystem:windows /machine:I386 /out:"../Runtime/BoxManagerService8i.exe" /libpath:"../../../../Lib/INFINITT_LIB/INFINITT_LIB36" /libpath:"D:\oracle\ora817\precomp\lib\msvc" /libpath:"../Runtime" /libpath:"../../../../Lib/INFINITT_LIB/SecureDll/Cipher1002"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "BoxManagerService - Win32 Debug for Oracle8i"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "BoxManagerService___Win32_Debug_for_Oracle8i"
# PROP BASE Intermediate_Dir "BoxManagerService___Win32_Debug_for_Oracle8i"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../Runtime"
# PROP Intermediate_Dir "Debug8i"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /FR /YX"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../../../../Lib/INFINITT_LIB/INFINITT_LIB36" /I "D:\oracle\ora817\precomp\public" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 ../Debug/PandoraConfigD.lib LIBGEND.lib orasql8.lib netapi32.lib dunzip32.lib /nologo /subsystem:windows /debug /machine:I386 /out:"../Debug/BoxManagerServiceD.exe" /pdbtype:sept
# ADD LINK32 BoxManagerConfigD.lib LIBGEND.lib orasql8.lib netapi32.lib dunzip32.lib IRSCipherLib.lib mpr.lib /nologo /subsystem:windows /debug /machine:I386 /out:"../Runtime/BoxManagerService8iD.exe" /pdbtype:sept /libpath:"../../../../Lib/INFINITT_LIB/INFINITT_LIB36" /libpath:"D:\oracle\ora817\precomp\lib\msvc" /libpath:"../Runtime" /libpath:"../../../../Lib/INFINITT_LIB/SecureDll/Cipher1002"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "BoxManagerService - Win32 Release for Oracle9i"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "BoxManagerService___Win32_Release_for_Oracle9i"
# PROP BASE Intermediate_Dir "BoxManagerService___Win32_Release_for_Oracle9i"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../Runtime"
# PROP Intermediate_Dir "Release9i"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /YX"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../../../../Lib/INFINITT_LIB/INFINITT_LIB36" /I "D:\oracle\ora920\precomp\public" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /FR /YX"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 ../Release/PandoraConfig.lib LIBGEN.lib sqllib80.lib netapi32.lib dunzip32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 BoxManagerConfig.lib LIBGEN.lib orasql9.lib netapi32.lib dunzip32.lib IRSCipherLib.lib mpr.lib /nologo /subsystem:windows /machine:I386 /out:"../Runtime/BoxManagerService9i.exe" /libpath:"../../../../Lib/INFINITT_LIB/INFINITT_LIB36" /libpath:"D:\oracle\ora920\precomp\lib\msvc" /libpath:"D:\oracle\ora102\precomp\LIB" /libpath:"../Runtime" /libpath:"../../../../Lib/INFINITT_LIB/SecureDll/Cipher1002"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "BoxManagerService - Win32 Debug for Oracle9i"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "BoxManagerService___Win32_Debug_for_Oracle9i"
# PROP BASE Intermediate_Dir "BoxManagerService___Win32_Debug_for_Oracle9i"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../Runtime"
# PROP Intermediate_Dir "Debug9i"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /FR /YX"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../../../../Lib/INFINITT_LIB/INFINITT_LIB36" /I "D:\oracle\ora920\precomp\public" /I "D:\Develop\Source\G3\Tools\zlibtool\zlib" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 ../Debug/PandoraConfigD.lib LIBGEND.lib sqllib80.lib netapi32.lib dunzip32.lib /nologo /subsystem:windows /debug /machine:I386 /out:"../Debug/BoxManagerServiceD.exe" /pdbtype:sept
# ADD LINK32 BoxManagerConfigD.lib dunzip32.lib LIBGEND.lib orasql9.lib netapi32.lib dunzip32.lib IRSCipherLib.lib mpr.lib /nologo /subsystem:windows /debug /machine:I386 /out:"../Runtime/BoxManagerService9iD.exe" /pdbtype:sept /libpath:"../../../../Lib/INFINITT_LIB/INFINITT_LIB36" /libpath:"D:\oracle\ora920\precomp\lib\msvc" /libpath:"../Runtime" /libpath:"../../../../Lib/INFINITT_LIB/SecureDll/Cipher1002"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "BoxManagerService - Win32 Release for Oracle10g"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "BoxManagerService___Win32_Release_for_Oracle10g"
# PROP BASE Intermediate_Dir "BoxManagerService___Win32_Release_for_Oracle10g"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../Runtime"
# PROP Intermediate_Dir "Release10g"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "../../../../Lib/INFINITT_LIB/INFINITT_LIB351" /I "D:\oracle\ora920\precomp\public" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /FR /YX"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../../../../Lib/INFINITT_LIB/INFINITT_LIB36" /I "D:\oracle\ora920\precomp\public" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /FR /YX"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 PandoraConfig.lib LIBGEN.lib orasql9.lib netapi32.lib dunzip32.lib IRSCipherLib.lib mpr.lib zdll.lib /nologo /subsystem:windows /machine:I386 /out:"../Runtime/BoxManagerService9i.exe" /libpath:"../../../../Lib/INFINITT_LIB/INFINITT_LIB36" /libpath:"D:\oracle\ora920\precomp\lib\msvc" /libpath:"../Runtime" /libpath:"../../../../Lib/INFINITT_LIB/Cipher/Cipher1.1"
# ADD LINK32 BoxManagerConfig.lib LIBGEN.lib orasql10.lib netapi32.lib dunzip32.lib IRSCipherLib.lib mpr.lib /nologo /subsystem:windows /machine:I386 /out:"../Runtime/BoxManagerService10g.exe" /libpath:"../../../../Lib/INFINITT_LIB/INFINITT_LIB36" /libpath:"D:\oracle\ora102\precomp\LIB" /libpath:"D:\oracle\ora102\precomp\lib\msvc" /libpath:"../Runtime" /libpath:"../../../../Lib/INFINITT_LIB/SecureDll/Cipher1002"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "BoxManagerService - Win32 Debug for Oracle10g"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "BoxManagerService___Win32_Debug_for_Oracle10g"
# PROP BASE Intermediate_Dir "BoxManagerService___Win32_Debug_for_Oracle10g"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../Runtime"
# PROP Intermediate_Dir "Debug10g"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../../../../Lib/INFINITT_LIB/INFINITT_LIB36" /I "D:\oracle\ora920\precomp\public" /I "D:\Develop\Source\G3\Tools\zlibtool\zlib" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /YX"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../../../../Lib/INFINITT_LIB/INFINITT_LIB36" /I "D:\oracle\ora920\precomp\public" /I "D:\Develop\Source\G3\Tools\zlibtool\zlib" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 PandoraConfigD.lib dunzip32.lib LIBGEND.lib orasql9.lib netapi32.lib IRSCipherLib.lib mpr.lib zdll.lib /nologo /subsystem:windows /debug /machine:I386 /out:"../Runtime/BoxManagerService9iD.exe" /pdbtype:sept /libpath:"D:\Develop\Source\LIB\INFINITT_LIB\INFINITT_LIB36" /libpath:"D:\oracle\ora920\precomp\lib\msvc" /libpath:"../Runtime" /libpath:"D:\Develop\Source\LIB\ServerDll\Server36"
# SUBTRACT BASE LINK32 /map
# ADD LINK32 BoxManagerConfigD.lib dunzip32.lib LIBGEND.lib orasql10.lib netapi32.lib IRSCipherLib.lib mpr.lib /nologo /subsystem:windows /pdb:"Debug10g/BoxManagerService10gD.pdb" /debug /machine:I386 /out:"../Runtime/BoxManagerService10gD.exe" /pdbtype:sept /libpath:"D:\oracle\ora102\precomp\LIB" /libpath:"D:\oracle\ora102\precomp\lib\msvc" /libpath:"../Runtime" /libpath:"../../../../Lib/INFINITT_LIB/SecureDll/Cipher1002" /libpath:"../../../../Lib/INFINITT_LIB/INFINITT_LIB36"
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "BoxManagerService - Win32 Release"
# Name "BoxManagerService - Win32 Debug"
# Name "BoxManagerService - Win32 Release for Oracle8i"
# Name "BoxManagerService - Win32 Debug for Oracle8i"
# Name "BoxManagerService - Win32 Release for Oracle9i"
# Name "BoxManagerService - Win32 Debug for Oracle9i"
# Name "BoxManagerService - Win32 Release for Oracle10g"
# Name "BoxManagerService - Win32 Debug for Oracle10g"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BoxManagerDatabase.cpp
# End Source File
# Begin Source File

SOURCE=.\BoxManagerDatabase.pc

!IF  "$(CFG)" == "BoxManagerService - Win32 Release"

!ELSEIF  "$(CFG)" == "BoxManagerService - Win32 Debug"

!ELSEIF  "$(CFG)" == "BoxManagerService - Win32 Release for Oracle8i"

# Begin Custom Build
InputPath=.\BoxManagerDatabase.pc

"BoxManagerDatabase.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	D:\ORACLE\ORA805\BIN\proc.exe userid=spectra/artceps@U920 iname=BoxManagerDatabase.pc       oname=BoxManagerDatabase.cpp threads=yes code=cpp sqlcheck=semantics

# End Custom Build

!ELSEIF  "$(CFG)" == "BoxManagerService - Win32 Debug for Oracle8i"

# Begin Custom Build
InputPath=.\BoxManagerDatabase.pc

"BoxManagerDatabase.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	D:\ORACLE\ORA805\BIN\proc.exe userid=spectra/artceps@U920 iname=BoxManagerDatabase.pc       oname=BoxManagerDatabase.cpp threads=yes code=cpp sqlcheck=semantics

# End Custom Build

!ELSEIF  "$(CFG)" == "BoxManagerService - Win32 Release for Oracle9i"

# Begin Custom Build
InputPath=.\BoxManagerDatabase.pc

"BoxManagerDatabase.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	D:\ORACLE\ORA805\BIN\proc.exe userid=spectra/artceps@U920 iname=BoxManagerDatabase.pc       oname=BoxManagerDatabase.cpp threads=yes code=cpp sqlcheck=semantics

# End Custom Build

!ELSEIF  "$(CFG)" == "BoxManagerService - Win32 Debug for Oracle9i"

# Begin Custom Build
InputPath=.\BoxManagerDatabase.pc

"BoxManagerDatabase.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	D:\ORACLE\ORA805\BIN\proc.exe userid=spectra/artceps@U920 iname=BoxManagerDatabase.pc       oname=BoxManagerDatabase.cpp threads=yes code=cpp sqlcheck=semantics

# End Custom Build

!ELSEIF  "$(CFG)" == "BoxManagerService - Win32 Release for Oracle10g"

# Begin Custom Build
InputPath=.\BoxManagerDatabase.pc

"BoxManagerDatabase.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	D:\ORACLE\ORA805\BIN\proc.exe userid=spectra/artceps@U920 iname=BoxManagerDatabase.pc       oname=BoxManagerDatabase.cpp threads=yes code=cpp sqlcheck=semantics

# End Custom Build

!ELSEIF  "$(CFG)" == "BoxManagerService - Win32 Debug for Oracle10g"

# Begin Custom Build
InputPath=.\BoxManagerDatabase.pc

"BoxManagerDatabase.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	D:\ORACLE\ORA805\BIN\proc.exe userid=spectra/artceps@U920 iname=BoxManagerDatabase.pc       oname=BoxManagerDatabase.cpp threads=yes code=cpp sqlcheck=semantics

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\BoxManagerPutter.cpp
# End Source File
# Begin Source File

SOURCE=.\BoxManagerService.cpp
# End Source File
# Begin Source File

SOURCE=.\BoxManagerServiceConfig.cpp
# End Source File
# Begin Source File

SOURCE=.\NTService.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\SystemInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\XMLWrapper.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\BoxManagerDatabase.h
# End Source File
# Begin Source File

SOURCE=.\BoxManagerPutter.h
# End Source File
# Begin Source File

SOURCE=.\BoxManagerService.h
# End Source File
# Begin Source File

SOURCE=.\BoxManagerServiceConfig.h
# End Source File
# Begin Source File

SOURCE=.\BoxManagerServiceVersion.h
# End Source File
# Begin Source File

SOURCE=.\NTService.h
# End Source File
# Begin Source File

SOURCE=.\NTServiceEventLogMsg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\SystemInfo.h
# End Source File
# Begin Source File

SOURCE=.\XMLWrapper.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\NTServiceEventLogMsg.mc

!IF  "$(CFG)" == "BoxManagerService - Win32 Release"

# Begin Custom Build
InputPath=.\NTServiceEventLogMsg.mc

BuildCmds= \
	mc -c -v NTServiceEventLogMsg.mc

"NTServiceEventLogMsg.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"NTServiceEventLogMsg.rc" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "BoxManagerService - Win32 Debug"

# Begin Custom Build
InputPath=.\NTServiceEventLogMsg.mc

BuildCmds= \
	mc -c -v NTServiceEventLogMsg.mc

"NTServiceEventLogMsg.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"NTServiceEventLogMsg.rc" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "BoxManagerService - Win32 Release for Oracle8i"

# Begin Custom Build
InputPath=.\NTServiceEventLogMsg.mc

BuildCmds= \
	mc -c -v NTServiceEventLogMsg.mc

"NTServiceEventLogMsg.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"NTServiceEventLogMsg.rc" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "BoxManagerService - Win32 Debug for Oracle8i"

# Begin Custom Build
InputPath=.\NTServiceEventLogMsg.mc

BuildCmds= \
	mc -c -v NTServiceEventLogMsg.mc

"NTServiceEventLogMsg.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"NTServiceEventLogMsg.rc" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "BoxManagerService - Win32 Release for Oracle9i"

# Begin Custom Build
InputPath=.\NTServiceEventLogMsg.mc

BuildCmds= \
	mc -c -v NTServiceEventLogMsg.mc

"NTServiceEventLogMsg.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"NTServiceEventLogMsg.rc" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "BoxManagerService - Win32 Debug for Oracle9i"

# Begin Custom Build
InputPath=.\NTServiceEventLogMsg.mc

BuildCmds= \
	mc -c -v NTServiceEventLogMsg.mc

"NTServiceEventLogMsg.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"NTServiceEventLogMsg.rc" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "BoxManagerService - Win32 Release for Oracle10g"

# Begin Custom Build
InputPath=.\NTServiceEventLogMsg.mc

BuildCmds= \
	mc -c -v NTServiceEventLogMsg.mc

"NTServiceEventLogMsg.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"NTServiceEventLogMsg.rc" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "BoxManagerService - Win32 Debug for Oracle10g"

# Begin Custom Build
InputPath=.\NTServiceEventLogMsg.mc

BuildCmds= \
	mc -c -v NTServiceEventLogMsg.mc

"NTServiceEventLogMsg.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"NTServiceEventLogMsg.rc" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NTServiceEventLogMsg.rc
# End Source File
# End Group
# Begin Source File

SOURCE=.\BoxManagerReleaseNote.txt
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
