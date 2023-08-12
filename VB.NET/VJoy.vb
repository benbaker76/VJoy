Imports System.Collections.Generic
Imports System.Linq
Imports System.Text
Imports System.Runtime.InteropServices

Class VJoy
    Private m_mode64 As Boolean = False

    Public Enum POVType
        Up = 0
        Right = 1
        Down = 2
        Left = 3
        Nil = 4
    End Enum

    <StructLayout(LayoutKind.Sequential, Pack:=1, CharSet:=CharSet.Ansi)> _
    Public Structure JoystickState
        Public ReportId As Byte
        Public XAxis As Short
        Public YAxis As Short
        Public ZAxis As Short
        Public XRotation As Short
        Public YRotation As Short
        Public ZRotation As Short
        Public Slider As Short
        Public Dial As Short
        Public POV As UShort
        Public Buttons As UInteger
    End Structure

    <DllImport("VJoy32.dll", EntryPoint:="VJoy_Initialize", CallingConvention:=CallingConvention.Cdecl)> _
    Private Shared Function VJoy_Initialize32() As <MarshalAs(UnmanagedType.Bool)> Boolean
    End Function

    <DllImport("VJoy32.dll", EntryPoint:="VJoy_Shutdown", CallingConvention:=CallingConvention.Cdecl)> _
    Private Shared Sub VJoy_Shutdown32()
    End Sub

    <DllImport("VJoy32.dll", EntryPoint:="VJoy_UpdateJoyState", CallingConvention:=CallingConvention.Cdecl)> _
    Private Shared Function VJoy_UpdateJoyState32(ByVal id As Integer, ByRef joyState As JoystickState) As <MarshalAs(UnmanagedType.Bool)> Boolean
    End Function

    <DllImport("VJoy64.dll", EntryPoint:="VJoy_Initialize", CallingConvention:=CallingConvention.Cdecl)> _
    Private Shared Function VJoy_Initialize64() As <MarshalAs(UnmanagedType.Bool)> Boolean
    End Function

    <DllImport("VJoy64.dll", EntryPoint:="VJoy_Shutdown", CallingConvention:=CallingConvention.Cdecl)> _
    Private Shared Sub VJoy_Shutdown64()
    End Sub

    <DllImport("VJoy64.dll", EntryPoint:="VJoy_UpdateJoyState", CallingConvention:=CallingConvention.Cdecl)> _
    Private Shared Function VJoy_UpdateJoyState64(ByVal id As Integer, ByRef joyState As JoystickState) As <MarshalAs(UnmanagedType.Bool)> Boolean
    End Function

    Private m_joyState As JoystickState()

    Public Sub New()
        m_mode64 = Is64BitMode()
    End Sub

    Public Function Initialize() As Boolean
        m_joyState = New JoystickState(1) {}

        m_joyState(0) = New JoystickState()
        m_joyState(1) = New JoystickState()

        If m_mode64 Then
            Return VJoy_Initialize64()
        Else
            Return VJoy_Initialize32()
        End If
    End Function

    Public Sub Shutdown()
        If m_mode64 Then
            VJoy_Shutdown64()
        Else
            VJoy_Shutdown32()
        End If
    End Sub

    Public Function Update(ByVal id As Integer) As Boolean
        If m_mode64 Then
            Return VJoy_UpdateJoyState64(id, m_joyState(id))
        Else
            Return VJoy_UpdateJoyState32(id, m_joyState(id))
        End If
    End Function

    Public Sub Reset()
        m_joyState(0).ReportId = 0
        m_joyState(0).XAxis = 0
        m_joyState(0).YAxis = 0
        m_joyState(0).ZAxis = 0
        m_joyState(0).XRotation = 0
        m_joyState(0).YRotation = 0
        m_joyState(0).ZRotation = 0
        m_joyState(0).Slider = 0
        m_joyState(0).Dial = 0
        m_joyState(0).POV = (CInt(POVType.Nil) << 12) Or (CInt(POVType.Nil) << 8) Or (CInt(POVType.Nil) << 4) Or CInt(POVType.Nil)
        m_joyState(0).Buttons = 0

        m_joyState(1).ReportId = 0
        m_joyState(1).XAxis = 0
        m_joyState(1).YAxis = 0
        m_joyState(1).ZAxis = 0
        m_joyState(1).XRotation = 0
        m_joyState(1).YRotation = 0
        m_joyState(1).ZRotation = 0
        m_joyState(1).Slider = 0
        m_joyState(1).Dial = 0
        m_joyState(1).POV = (CInt(POVType.Nil) << 12) Or (CInt(POVType.Nil) << 8) Or (CInt(POVType.Nil) << 4) Or CInt(POVType.Nil)
        m_joyState(1).Buttons = 0
    End Sub

    Public Function GetXAxis(ByVal index As Integer) As Short
        Return m_joyState(index).XAxis
    End Function

    Public Sub SetXAxis(ByVal index As Integer, ByVal value As Short)
        m_joyState(index).XAxis = value
    End Sub

    Public Function GetYAxis(ByVal index As Integer) As Short
        Return m_joyState(index).YAxis
    End Function

    Public Sub SetYAxis(ByVal index As Integer, ByVal value As Short)
        m_joyState(index).YAxis = value
    End Sub

    Public Function GetZAxis(ByVal index As Integer) As Short
        Return m_joyState(index).ZAxis
    End Function

    Public Sub SetZAxis(ByVal index As Integer, ByVal value As Short)
        m_joyState(index).ZAxis = value
    End Sub

    Public Function GetXRotation(ByVal index As Integer) As Short
        Return m_joyState(index).XRotation
    End Function

    Public Sub SetXRotation(ByVal index As Integer, ByVal value As Short)
        m_joyState(index).XRotation = value
    End Sub

    Public Function GetYRotation(ByVal index As Integer) As Short
        Return m_joyState(index).YRotation
    End Function

    Public Sub SetYRotation(ByVal index As Integer, ByVal value As Short)
        m_joyState(index).YRotation = value
    End Sub

    Public Function GetZRotation(ByVal index As Integer) As Short
        Return m_joyState(index).ZRotation
    End Function

    Public Sub SetZRotation(ByVal index As Integer, ByVal value As Short)
        m_joyState(index).ZRotation = value
    End Sub

    Public Function GetSlider(ByVal index As Integer) As Short
        Return m_joyState(index).Slider
    End Function

    Public Sub SetSlider(ByVal index As Integer, ByVal value As Short)
        m_joyState(index).Slider = value
    End Sub

    Public Function GetDial(ByVal index As Integer) As Short
        Return m_joyState(index).Dial
    End Function

    Public Sub SetDial(ByVal index As Integer, ByVal value As Short)
        m_joyState(index).Dial = value
    End Sub

    Public Sub SetPOV(ByVal index As Integer, ByVal pov As Integer, ByVal value As POVType)
        m_joyState(index).POV = m_joyState(index).POV And Not CUShort(&HF << ((3 - pov) * 4))
        m_joyState(index).POV = m_joyState(index).POV Or CUShort(CInt(value) << ((3 - pov) * 4))
    End Sub

    Public Function GetPOV(ByVal index As Integer, ByVal pov As Integer) As POVType
        Return CType((m_joyState(index).POV >> ((3 - pov) * 4)) And &HF, POVType)
    End Function

    Public Sub SetButton(ByVal index As Integer, ByVal button As Integer, ByVal value As Boolean)
        If value Then
            m_joyState(index).Buttons = m_joyState(index).Buttons Or CUInt(1UI << button)
        Else
            m_joyState(index).Buttons = m_joyState(index).Buttons And CUInt(Not (1UI << button))
        End If
    End Sub

    Public Function GetButton(ByVal index As Integer, ByVal button As Integer) As Boolean
        Return ((m_joyState(index).Buttons And (1 << button)) = 1)
    End Function

    Private Function Is64BitMode() As Boolean
        Return Marshal.SizeOf(GetType(IntPtr)) = 8
    End Function
End Class