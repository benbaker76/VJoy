; -- VJoySetup_Key2Joy.iss --

[Setup]
AppName=Key2Joy
AppVerName=Key2Joy 1.0
AppPublisher=Ben Baker
DefaultDirName={pf}\Key2Joy
DefaultGroupName=Key2Joy
UninstallDisplayIcon={app}\Key2Joy.exe
Compression=lzma
SolidCompression=yes
OutputDir=Setup
OutputBaseFilename=VJoySetup_Key2Joy
WizardImageFile=WizardImage.bmp
WizardSmallImageFile=WizardSmallImage.bmp

[Files]
Source: "Key2Joy.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "Key2Joy.ini"; DestDir: "{app}"; Flags: ignoreversion
Source: "ReadMe.pdf"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\..\driver\Install.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\..\driver\DeleteDriver.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\..\driver\install\VJoy.inf"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\..\driver\install\VJoy.cat"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\..\driver\install\amd64\*"; DestDir: "{app}\amd64";   Flags: recursesubdirs createallsubdirs
Source: "..\..\driver\install\i386\*"; DestDir: "{app}\i386"; Flags: recursesubdirs createallsubdirs
Source: "..\..\driver\install\ia64\*"; DestDir: "{app}\ia64"; Flags: recursesubdirs createallsubdirs

[UninstallDelete]
Type: files; Name: "{app}\VJoy.inf"
Type: files; Name: "{app}\VJoy.cat"
Type: files; Name: "{app}\Key2Joy.exe"
Type: files; Name: "{app}\Key2Joy.ini"
Type: files; Name: "{app}\ReadMe.pdf"
Type: files; Name: "{app}\Install.exe"
Type: filesandordirs; Name: "{app}\amd64\*"
Type: filesandordirs; Name: "{app}\i386\*"
Type: filesandordirs; Name: "{app}\ia64\*"

[Run]
Filename: "{app}\DeleteDriver.exe"; WorkingDir: "{app}"; Parameters: """VJoy Virtual Joystick"""
Filename: "{app}\Install.exe"; WorkingDir: "{app}"; Parameters: "devcon.exe remove vjoy.inf VJOY\VID_FEED&PID_FACE"
Filename: "{app}\Install.exe"; WorkingDir: "{app}"; Parameters: "devcon.exe install vjoy.inf VJOY\VID_FEED&PID_FACE"
Filename: "{app}\Key2Joy.exe"; Description: "Launch Key2Joy"; Flags: postinstall nowait skipifsilent

[UninstallRun]
Filename: "{app}\Key2Joy.exe"; Parameters: "-exit"
Filename: "{app}\Install.exe"; WorkingDir: "{app}"; Parameters: "devcon.exe remove vjoy.inf VJOY\VID_FEED&PID_FACE"
Filename: "{app}\DeleteDriver.exe"; WorkingDir: "{app}"; Parameters: """VJoy Virtual Joystick"""

[Icons]
Name: "{group}\Key2Joy"; Filename: "{app}\Key2Joy.exe"
Name: "{group}\Uninstall Key2Joy"; Filename: "{app}\unins000.exe"
