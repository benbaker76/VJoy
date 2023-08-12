unit SDIMAIN;

interface

uses Windows, Classes, Graphics, Forms, Controls, Menus,
  Dialogs, StdCtrls, Buttons, ExtCtrls, ComCtrls, ImgList, StdActns,
  ActnList, ToolWin, SysUtils;

type JOYSTICK_STATE = packed record
	ReportId:Byte;
	XAxis:SmallInt;
	YAxis:SmallInt;
	ZAxis:SmallInt;
	XRotation:SmallInt;
	YRotation:SmallInt;
	ZRotation:SmallInt;
	Slider:SmallInt;
	Dial:SmallInt;
	POV:Word;
	Buttons:Integer;
end;
PJOYSTICK_STATE = ^JOYSTICK_STATE;

type
  TSDIAppForm = class(TForm)
    procedure FormShow(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

Function VJoy_Initialize() : Boolean; stdcall; external 'VJoy32.dll';
Procedure VJoy_Shutdown() stdcall; external 'VJoy32.dll';
Function VJoy_UpdateJoyState(id: Integer; joyState: PJOYSTICK_STATE) : Boolean; stdcall; external 'VJoy32.dll';

var
  SDIAppForm: TSDIAppForm;

implementation

{$R *.dfm}

procedure TSDIAppForm.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  VJoy_Shutdown();
end;

procedure TSDIAppForm.FormShow(Sender: TObject);
var
  joyState: JOYSTICK_STATE;
begin
  VJoy_Initialize();

  joyState.XAxis := 32767;
  joyState.YAxis := 32767;
  joyState.ZAxis := 32767;
  joyState.Buttons := StrToInt('$AAAA');
  
  VJoy_UpdateJoyState(0, @joyState);

  VJoy_Shutdown();
end;

end.

