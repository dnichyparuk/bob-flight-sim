; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "BoB"
#define MyAppVersion "0.99"
#define MyAppPublisher "Rowan"
#define MyAppURL "http://www.example.com/"
#define MyAppExeName "bob.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{7D41956B-FC8F-4B16-999D-04A51924A68F}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\{#MyAppName}
DefaultGroupName={#MyAppName}
AllowNoIcons=yes
;LicenseFile=C:\Program Files (x86)\Bob Source\SRC\LIC.TXT
InfoBeforeFile=D:\BOB\release\exe\Demo Readme.txt
;InfoAfterFile=D:\BOB\release\exe\readme.txt
OutputBaseFilename=bob_setup
OutputDir=D:\BOB
Compression=lzma2
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked; OnlyBelowVersion: 0,6.1

[Files]
Source: "vcredist_x86.exe"; DestDir: {tmp}; Flags: deleteafterinstall
Source: "D:\BOB\release\exe\bob.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\BOB\release\exe\*.ocx"; DestDir: {app}; Flags: ignoreversion regserver 32bit
Source: "D:\BOB\release\exe\*"; Excludes: "*.suo,*.jpg,*.pdb,*.bsc,*.ilk,*.lib,*.exp,*.lic,*.tlb,*.err,*.bfi,*.lastcodeanalysissucceeded,Docs\*.bmp,*.pcx,*.dds"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent
Filename: "{tmp}\vcredist_x86.exe"; Parameters: "/quiet /norestart";

