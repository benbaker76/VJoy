<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
 Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container
        Me.lblDevice = New System.Windows.Forms.Label
        Me.nudDevice = New System.Windows.Forms.NumericUpDown
        Me.trkXAxis = New System.Windows.Forms.TrackBar
        Me.lblXAxis = New System.Windows.Forms.Label
        Me.lblZRotation = New System.Windows.Forms.Label
        Me.trkZRotation = New System.Windows.Forms.TrackBar
        Me.lblYAxis = New System.Windows.Forms.Label
        Me.trkYAxis = New System.Windows.Forms.TrackBar
        Me.lblSlider = New System.Windows.Forms.Label
        Me.trkSlider = New System.Windows.Forms.TrackBar
        Me.lblZAxis = New System.Windows.Forms.Label
        Me.trkZAxis = New System.Windows.Forms.TrackBar
        Me.panel1 = New System.Windows.Forms.Panel
        Me.timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.lblYRotation = New System.Windows.Forms.Label
        Me.trkYRotation = New System.Windows.Forms.TrackBar
        Me.lblXRotation = New System.Windows.Forms.Label
        Me.trkXRotation = New System.Windows.Forms.TrackBar
        Me.panel2 = New System.Windows.Forms.Panel
        Me.lblDial = New System.Windows.Forms.Label
        Me.trkDial = New System.Windows.Forms.TrackBar
        CType(Me.nudDevice, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.trkXAxis, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.trkZRotation, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.trkYAxis, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.trkSlider, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.trkZAxis, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.trkYRotation, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.trkXRotation, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.trkDial, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'lblDevice
        '
        Me.lblDevice.AutoSize = True
        Me.lblDevice.Location = New System.Drawing.Point(107, 14)
        Me.lblDevice.Name = "lblDevice"
        Me.lblDevice.Size = New System.Drawing.Size(85, 13)
        Me.lblDevice.TabIndex = 0
        Me.lblDevice.Text = "Joystick Device:"
        '
        'nudDevice
        '
        Me.nudDevice.Location = New System.Drawing.Point(230, 12)
        Me.nudDevice.Maximum = New Decimal(New Integer() {1, 0, 0, 0})
        Me.nudDevice.Name = "nudDevice"
        Me.nudDevice.Size = New System.Drawing.Size(34, 20)
        Me.nudDevice.TabIndex = 1
        '
        'trkXAxis
        '
        Me.trkXAxis.Location = New System.Drawing.Point(21, 77)
        Me.trkXAxis.Maximum = 32767
        Me.trkXAxis.Minimum = -32768
        Me.trkXAxis.Name = "trkXAxis"
        Me.trkXAxis.Size = New System.Drawing.Size(254, 45)
        Me.trkXAxis.TabIndex = 2
        Me.trkXAxis.TickFrequency = 1024
        '
        'lblXAxis
        '
        Me.lblXAxis.AutoSize = True
        Me.lblXAxis.Location = New System.Drawing.Point(30, 61)
        Me.lblXAxis.Name = "lblXAxis"
        Me.lblXAxis.Size = New System.Drawing.Size(36, 13)
        Me.lblXAxis.TabIndex = 3
        Me.lblXAxis.Text = "X Axis"
        '
        'lblZRotation
        '
        Me.lblZRotation.AutoSize = True
        Me.lblZRotation.Location = New System.Drawing.Point(331, 170)
        Me.lblZRotation.Name = "lblZRotation"
        Me.lblZRotation.Size = New System.Drawing.Size(57, 13)
        Me.lblZRotation.TabIndex = 5
        Me.lblZRotation.Text = "Z Rotation"
        '
        'trkZRotation
        '
        Me.trkZRotation.Location = New System.Drawing.Point(322, 186)
        Me.trkZRotation.Maximum = 32767
        Me.trkZRotation.Minimum = -32768
        Me.trkZRotation.Name = "trkZRotation"
        Me.trkZRotation.Size = New System.Drawing.Size(254, 45)
        Me.trkZRotation.TabIndex = 4
        Me.trkZRotation.TickFrequency = 1024
        '
        'lblYAxis
        '
        Me.lblYAxis.AutoSize = True
        Me.lblYAxis.Location = New System.Drawing.Point(30, 112)
        Me.lblYAxis.Name = "lblYAxis"
        Me.lblYAxis.Size = New System.Drawing.Size(36, 13)
        Me.lblYAxis.TabIndex = 7
        Me.lblYAxis.Text = "Y Axis"
        '
        'trkYAxis
        '
        Me.trkYAxis.Location = New System.Drawing.Point(21, 128)
        Me.trkYAxis.Maximum = 32767
        Me.trkYAxis.Minimum = -32768
        Me.trkYAxis.Name = "trkYAxis"
        Me.trkYAxis.Size = New System.Drawing.Size(254, 45)
        Me.trkYAxis.TabIndex = 6
        Me.trkYAxis.TickFrequency = 1024
        '
        'lblSlider
        '
        Me.lblSlider.AutoSize = True
        Me.lblSlider.Location = New System.Drawing.Point(30, 226)
        Me.lblSlider.Name = "lblSlider"
        Me.lblSlider.Size = New System.Drawing.Size(33, 13)
        Me.lblSlider.TabIndex = 9
        Me.lblSlider.Text = "Slider"
        '
        'trkSlider
        '
        Me.trkSlider.Location = New System.Drawing.Point(21, 242)
        Me.trkSlider.Maximum = 32767
        Me.trkSlider.Minimum = -32768
        Me.trkSlider.Name = "trkSlider"
        Me.trkSlider.Size = New System.Drawing.Size(254, 45)
        Me.trkSlider.TabIndex = 8
        Me.trkSlider.TickFrequency = 1024
        '
        'lblZAxis
        '
        Me.lblZAxis.AutoSize = True
        Me.lblZAxis.Location = New System.Drawing.Point(30, 170)
        Me.lblZAxis.Name = "lblZAxis"
        Me.lblZAxis.Size = New System.Drawing.Size(36, 13)
        Me.lblZAxis.TabIndex = 11
        Me.lblZAxis.Text = "Z Axis"
        '
        'trkZAxis
        '
        Me.trkZAxis.Location = New System.Drawing.Point(21, 186)
        Me.trkZAxis.Maximum = 32767
        Me.trkZAxis.Minimum = -32768
        Me.trkZAxis.Name = "trkZAxis"
        Me.trkZAxis.Size = New System.Drawing.Size(254, 45)
        Me.trkZAxis.TabIndex = 10
        Me.trkZAxis.TickFrequency = 1024
        '
        'panel1
        '
        Me.panel1.Location = New System.Drawing.Point(21, 339)
        Me.panel1.Name = "panel1"
        Me.panel1.Size = New System.Drawing.Size(555, 87)
        Me.panel1.TabIndex = 14
        '
        'timer1
        '
        '
        'lblYRotation
        '
        Me.lblYRotation.AutoSize = True
        Me.lblYRotation.Location = New System.Drawing.Point(331, 112)
        Me.lblYRotation.Name = "lblYRotation"
        Me.lblYRotation.Size = New System.Drawing.Size(57, 13)
        Me.lblYRotation.TabIndex = 16
        Me.lblYRotation.Text = "Y Rotation"
        '
        'trkYRotation
        '
        Me.trkYRotation.Location = New System.Drawing.Point(322, 128)
        Me.trkYRotation.Maximum = 32767
        Me.trkYRotation.Minimum = -32768
        Me.trkYRotation.Name = "trkYRotation"
        Me.trkYRotation.Size = New System.Drawing.Size(254, 45)
        Me.trkYRotation.TabIndex = 15
        Me.trkYRotation.TickFrequency = 1024
        '
        'lblXRotation
        '
        Me.lblXRotation.AutoSize = True
        Me.lblXRotation.Location = New System.Drawing.Point(331, 61)
        Me.lblXRotation.Name = "lblXRotation"
        Me.lblXRotation.Size = New System.Drawing.Size(57, 13)
        Me.lblXRotation.TabIndex = 18
        Me.lblXRotation.Text = "X Rotation"
        '
        'trkXRotation
        '
        Me.trkXRotation.Location = New System.Drawing.Point(322, 77)
        Me.trkXRotation.Maximum = 32767
        Me.trkXRotation.Minimum = -32768
        Me.trkXRotation.Name = "trkXRotation"
        Me.trkXRotation.Size = New System.Drawing.Size(254, 45)
        Me.trkXRotation.TabIndex = 17
        Me.trkXRotation.TickFrequency = 1024
        '
        'panel2
        '
        Me.panel2.Location = New System.Drawing.Point(21, 293)
        Me.panel2.Name = "panel2"
        Me.panel2.Size = New System.Drawing.Size(555, 32)
        Me.panel2.TabIndex = 19
        '
        'lblDial
        '
        Me.lblDial.AutoSize = True
        Me.lblDial.Location = New System.Drawing.Point(331, 226)
        Me.lblDial.Name = "lblDial"
        Me.lblDial.Size = New System.Drawing.Size(25, 13)
        Me.lblDial.TabIndex = 21
        Me.lblDial.Text = "Dial"
        '
        'trkDial
        '
        Me.trkDial.Location = New System.Drawing.Point(322, 242)
        Me.trkDial.Maximum = 32767
        Me.trkDial.Minimum = -32768
        Me.trkDial.Name = "trkDial"
        Me.trkDial.Size = New System.Drawing.Size(254, 45)
        Me.trkDial.TabIndex = 20
        Me.trkDial.TickFrequency = 1024
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(603, 450)
        Me.Controls.Add(Me.lblDial)
        Me.Controls.Add(Me.trkDial)
        Me.Controls.Add(Me.panel2)
        Me.Controls.Add(Me.lblSlider)
        Me.Controls.Add(Me.trkZRotation)
        Me.Controls.Add(Me.lblZRotation)
        Me.Controls.Add(Me.trkYRotation)
        Me.Controls.Add(Me.lblYRotation)
        Me.Controls.Add(Me.lblXRotation)
        Me.Controls.Add(Me.trkXRotation)
        Me.Controls.Add(Me.panel1)
        Me.Controls.Add(Me.lblZAxis)
        Me.Controls.Add(Me.trkZAxis)
        Me.Controls.Add(Me.trkSlider)
        Me.Controls.Add(Me.lblYAxis)
        Me.Controls.Add(Me.trkYAxis)
        Me.Controls.Add(Me.lblXAxis)
        Me.Controls.Add(Me.trkXAxis)
        Me.Controls.Add(Me.nudDevice)
        Me.Controls.Add(Me.lblDevice)
        Me.Name = "Form1"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "Form1"
        CType(Me.nudDevice, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.trkXAxis, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.trkZRotation, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.trkYAxis, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.trkSlider, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.trkZAxis, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.trkYRotation, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.trkXRotation, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.trkDial, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Private WithEvents lblDevice As System.Windows.Forms.Label
    Private WithEvents nudDevice As System.Windows.Forms.NumericUpDown
    Private WithEvents trkXAxis As System.Windows.Forms.TrackBar
    Private WithEvents lblXAxis As System.Windows.Forms.Label
    Private WithEvents lblZRotation As System.Windows.Forms.Label
    Private WithEvents trkZRotation As System.Windows.Forms.TrackBar
    Private WithEvents lblYAxis As System.Windows.Forms.Label
    Private WithEvents trkYAxis As System.Windows.Forms.TrackBar
    Private WithEvents lblSlider As System.Windows.Forms.Label
    Private WithEvents trkSlider As System.Windows.Forms.TrackBar
    Private WithEvents lblZAxis As System.Windows.Forms.Label
    Private WithEvents trkZAxis As System.Windows.Forms.TrackBar
    Private WithEvents panel1 As System.Windows.Forms.Panel
    Private WithEvents timer1 As System.Windows.Forms.Timer
    Private WithEvents lblYRotation As System.Windows.Forms.Label
    Private WithEvents trkYRotation As System.Windows.Forms.TrackBar
    Private WithEvents lblXRotation As System.Windows.Forms.Label
    Private WithEvents trkXRotation As System.Windows.Forms.TrackBar
    Private WithEvents panel2 As System.Windows.Forms.Panel
    Private WithEvents lblDial As System.Windows.Forms.Label
    Private WithEvents trkDial As System.Windows.Forms.TrackBar
End Class
