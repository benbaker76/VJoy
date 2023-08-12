; -- VJoySetup_DriverOnly.iss --

[Setup]
AppName=VJoy Virtual Joystick Driver
AppVerName=VJoy Virtual Joystick Driver 1.2
AppPublisher=Ben Baker
DefaultDirName={pf}\VJoy Virtual Joystick Driver
DefaultGroupName=VJoy Virtual Joystick Driver
Compression=lzma
SolidCompression=yes
OutputDir=Setup
OutputBaseFilename=VJoySetup_DriverOnly
WizardImageFile=WizardImage.bmp
WizardSmallImageFile=WizardSmallImage.bmp

[Files]
Source: "..\..\driver\install\VJoy.inf"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\..\driver\install\VJoy.cat"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\..\driver\Install.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\..\driver\DeleteDriver.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\..\driver\install\amd64\*"; DestDir: "{app}\amd64";   Flags: recursesubdirs createallsubdirs
Source: "..\..\driver\install\i386\*"; DestDir: "{app}\i386"; Flags: recursesubdirs createallsubdirs
Source: "..\..\driver\install\ia64\*"; DestDir: "{app}\ia64"; Flags: recursesubdirs createallsubdirs

[UninstallDelete]
Type: files; Name: "{app}\VJoy.inf"
Type: files; Name: "{app}\VJoy.cat"
Type: files; Name: "{app}\install.exe"
Type: filesandordirs; Name: "{app}\amd64\*"
Type: filesandordirs; Name: "{app}\i386\*"
Type: filesandordirs; Name: "{app}\ia64\*"

[Run]
Filename: "{app}\DeleteDriver.exe"; WorkingDir: "{app}"; Parameters: """VJoy Virtual Joystick"""
Filename: "{app}\Install.exe"; WorkingDir: "{app}"; Parameters: "devcon.exe remove vjoy.inf VJOY\VID_FEED&PID_FACE"
Filename: "{app}\Install.exe"; WorkingDir: "{app}"; Parameters: "devcon.exe install vjoy.inf VJOY\VID_FEED&PID_FACE"

[UninstallRun]
Filename: "{app}\Install.exe"; WorkingDir: "{app}"; Parameters: "devcon.exe remove vjoy.inf VJOY\VID_FEED&PID_FACE"
Filename: "{app}\DeleteDriver.exe"; WorkingDir: "{app}"; Parameters: """VJoy Virtual Joystick"""

[Icons]
Name: "{group}\Uninstall VJoy"; Filename: "{app}\unins000.exe"
