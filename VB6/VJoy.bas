Attribute VB_Name = "VJoy"
Public Type JoystickState
    ReportId As Byte
    XAxis As Integer
    YAxis As Integer
    ZAxis As Integer
    XRotation As Integer
    YRotation As Integer
    ZRotation As Integer
    Slider As Integer
    Dial As Integer
    POV As Integer
    Buttons As Long
End Type

Public Declare Function VJoy_Initialize Lib "VJoy32" () As Integer
Public Declare Sub VJoy_Shutdown Lib "VJoy32" ()
Public Declare Function VJoy_UpdateJoyState Lib "VJoy32" (ByVal id As Integer, ByRef joyState As JoystickState) As Boolean

