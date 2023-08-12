# Key2Joy

## Introduction

Key2Joy is a software application and virtual driver system that allows input to be translated from keyboard to joystick input.

## Features

- 2 Joysticks
- 8 Axes with a range of -32768 to 32767
- 32 Buttons
- 4 POV's
- 64-bit support
- Key blocking (unfortunately doesn\'t work in Vista and Windows 7 due to changes in these OS's)

## System Requirements

Key2Joy supports the following Operating Systems.

- Windows 2000
- Windows XP (x86 / x64)
- Windows Server 2008 (x86 / x64)
- Windows Vista (x86 / x64)
- Windows 7 (x86 / x64)
- Windows 8 (x86 / x64)

## Installation

Run `VJoySetup_Key2Joy.exe` to install Key2Joy. Once installed select to launch Key2Joy or launch it from the Start menu. When you launch Key2Joy it will start minimized to the Icon Tray.

![](/images/Key2Joy01.png)

Figure 1. Key2Joy Install Wizard

![](/images/Key2Joy02.png)

Figure 2. Key2Joy Running in the Icon Tray.

To configure Key2Joy double click on the joystick icon or right-click it and select Open.

![](/images/Key2Joy03.png)

Figure 3. Key2Joy Main Configuration Window

### Configuration

Key2Joy provides two virtual joysticks that can be configured with 30 inputs each. A button can be assigned to each type of joystick input. To configure a joystick function either select the key to assign from the combo box or use the ![](/images/Key2Joy05.png) button to input the key from the keyboard.

![](/images/Key2Joy04.png)

Figure 4. Input a key using the keyboard

### Enabled

This option toggles the Key2Joy functionality.

### Joystick Device

This allows you to select which joystick you want to configure.

### Block Keys

When a key is pressed on the keyboard without the block keys option set Windows will register a key press as well as joystick input the key is assigned to. To block the keyboard input turn this option on and the key input will not reach a Windows application. Only key inputs that are assigned to joystick input will be blocked.

### Launch on Startup

This allows Key2Joy to start when Windows is launched.

### Open / Save Ini

This allows you to load and save configuration files used in Key2Joy.

### Exiting

Key2Joy is designed to run in the Icon Tray. When you close the configuration window it will minimize to the Icon Tray. To exit Key2Joy and remove it from memory, either right-click the joystick icon in the Icon Tray and select Close or use the [X] button and accept the dialog prompt to close.

## Command Line Options

Key2Joy supports command line arguments sent to it either while running from the Icon Tray or as a stand-alone application. Sending command line arguments allows you to configure Key2Joy for application specific tasks. You can also send commands to toggle options or close Key2Joy.

`USAGE: Key2Joy.exe -options`

|Parameter|Description|
|---|---|
|-file|Ini file to load|
|-enable|Enable or disable program|
|-blockkeys|Block key presses|
|-autocenter <1 \| 0>|Auto center on key up|
|-exit|Exit program|
|-help|Displays this Message Box|

## Uninstallation

To uninstall Key2Joy select the Key2Joy Uninstall icon from the start menu.

## Compiling

### Compile the VJoy Virtual Joystick Driver:

1. Download [6.1.6001.18002.081017-1400_wdksp-WDK18002SP_EN_DVD.iso](https://baker76.com/download/pc/6.1.6001.18002.081017-1400_wdksp-WDK18002SP_EN_DVD.iso)
2. Mount the iso and install WDK 6001.18002 to (Eg. `C:\WinDDK`) by running KitSetup.exe
3. Start Menu > Programs > Windows Driver Kits > WDK 6001.18002 > Build Environments > Windows Vista and Windows Server 2008
- Launch the following:
    - `Windows Vista and Windows Server 2008 ia64 Free Build Environment`
    - `Windows Vista and Windows Server 2008 x64 Free Build Environment`
    - `Windows Vista and Windows Server 2008 x86 Free Build Environment`

It will open a command prompt and you can cd into the source folder.

eg. `C:\WinDDK\6001.18002>cd C:\VJoy\driver`

4. Type `build` to compile the driver and example source. You should get the following output:

```sh
C:\VJoy\driver>build
BUILD: Compile and Link for AMD64
BUILD: Loading c:\winddk\6001.18002\build.dat...
BUILD: Computing Include file dependencies:
BUILD: Start time: Wed Mar 20 02:16:07 2013
BUILD: Examining c:\vjoy\driver directory tree for files to compile.
BUILD: Saving c:\winddk\6001.18002\build.dat...
1>BUILD: Compiling and Linking c:\vjoy\driver\exe directory
2>BUILD: Compiling and Linking c:\vjoy\driver\sys directory
1>_NT_TARGET_VERSION SET TO WS03
2>Compiling - sys\vjoy.c
2>Linking Executable - sys\sys\objfre_wlh_amd64\amd64\vjoy.sys
BUILD: Finish time: Wed Mar 20 02:16:09 2013
BUILD: Done

    3 files compiled - 5 Warnings
    1 executable built
```

5. Type `install.bat` to install the driver and `uninstall.bat` to uninstall the driver
6. Type `test.bat` to run `testvjoy.exe` to test the driver
7. Run `Poswdm.exe` from the `utilities` folder to view joystick data in real time

### Compile the Key2Joy Application:

1. Install Visual Studio 2008 and make sure you tick the following:
- Select features to install:
    - Microsoft Visual Studio 2008 Professional Edition > Language Tools > Visual C++ > X64 Compilers and Tools
2. Once done install Visual Studio 2008 SP1
3. In Tools > Options > Projects and Solutions > VC++ Directories
    - Include Files (Win32)
        - C:\WinDDK\6001.18002\inc\api
    - Library Files (Win32)
        - C:\WinDDKK\6001.18002\lib\wlh\i386
    - Include Files (x64)
        - C:\WinDDK\6001.18002\inc\api
    - Library Files (x64)
        - C:\WinDDK\6001.18002\lib\wlh\amd64
4. Open the project in the `Key2Joy` directory in Visual Studio 2008 and compile it

### Packaging

To package the drivers up for end-user installation you should do the following:

1. Run `testsign_on.bat` or [Sign the drivers](http://www.digicert.com/code-signing/driver-signing-certificates.htm)
2. Download and install [InnoSetup](http://www.jrsoftware.org/isdl.php)
3. Run `VJoySetup_Key2Joy.iss` or `VJoySetup_DriverOnly.iss` from the `Key2Joy\Release` folder
4. Select the `Run` button to compile the script and create an executable in the `Setup` folder:
    - `VJoySetup_Key2Joy.exe`
    - `VJoySetup_DriverOnly.exe`

## VJoy API

The VJoy API allows you to inject your own input data into the VJoy Virtual Joystick drivers using a variety of languages. Examples include C/C++, C#, VB.NET, VB6 and Delphi.

### Structure

```c
struct JOYSTICK_STATE
{
   unsigned char ReportId;
   short XAxis;
   short YAxis;
   short ZAxis;
   short XRotation;
   short YRotation;
   short ZRotation;
   short Slider;
   short Dial;
   unsigned short POV;
   unsigned int Buttons;
};
```

### Functions

`bool VJoy_Initialize()`

- Initialize the VJoy driver
- Returns true for success and false for failure

`void VJoy_Shutdown()`

- Shutdown the VJoy driver
- No return value

`bool VJoy_UpdateJoyState(int id, JOYSTICK_STATE* pJoyState)`

- Update the current joystick state specified by id
- Returns true for success and false for failure
- Axis range is -32768 to 32767
- There are 4 POV’s each taking 4 bits of the 32 bit integer
- POV values are Up = 0, Right = 1, Down = 2, Left = 3, Nil = 4

### Examples in C++

- Send some data to the first joystick

```c
JOYSTICK_STATE m_joyState[2] = { 0 };

int main(int argc, char* argv[])
{
	VJoy_Initialize();

	m_joyState[0].XAxis = 32767;
	m_joyState[0].YAxis = 32767;
	m_joyState[0].ZAxis = 32767;
	m_joyState[0].Buttons = 0xAAAAAAAA;
	m_joyState[0].POV = (4 << 12) | (4 << 8) | (4 << 4) | 4;

	VJoy_UpdateJoyState(0, &m_joyState[0]);

	VJoy_Shutdown();

	return 0;
}
```
