Public Partial Class Form1
	Inherits Form
	Private m_button As CheckBox() = Nothing
	Private m_pov As CheckBox() = Nothing
	Private m_vjoy As VJoy = Nothing

	Public Sub New()
		InitializeComponent()
	End Sub

    Private Sub Form1_Load(ByVal sender As Object, ByVal e As EventArgs) Handles MyBase.Load
        CreateButtons()

        m_vjoy = New VJoy()
        m_vjoy.Initialize()
        m_vjoy.Reset()
        m_vjoy.Update(0)
        m_vjoy.Update(1)

        timer1.Start()
    End Sub

    Private Sub Form1_FormClosing(ByVal sender As Object, ByVal e As FormClosingEventArgs) Handles MyBase.FormClosing
        m_vjoy.Shutdown()
    End Sub

	Private Sub Button_CheckedChanged(sender As Object, e As EventArgs)
		Dim chk As CheckBox = DirectCast(sender, CheckBox)

		m_vjoy.SetButton(CInt(nudDevice.Value), Int32.Parse(chk.Text), chk.Checked)
		m_vjoy.Update(CInt(nudDevice.Value))
	End Sub

	Private Sub Pov_CheckedChanged(sender As Object, e As EventArgs)
        Dim chk As CheckBox = DirectCast(sender, CheckBox)

        If chk.Checked Then

            m_vjoy.SetPOV(CInt(nudDevice.Value), chk.Tag, VJoy.POVType.Up)
        Else
            m_vjoy.SetPOV(CInt(nudDevice.Value), chk.Tag, VJoy.POVType.Nil)
        End If
        m_vjoy.Update(CInt(nudDevice.Value))
    End Sub

	Private Sub CreateButtons()
		m_button = New CheckBox(31) {}

		For y As Integer = 0 To 3
			For x As Integer = 0 To 7
				Dim id As Integer = y * 8 + x
				Dim size As New Size(panel1.Width / 8, panel1.Height / 4)

                m_button(id) = New CheckBox()
                m_button(id).Tag = id

				m_button(id).Location = New Point(x * size.Width, y * size.Height)
				m_button(id).Size = size

				m_button(id).Appearance = Appearance.Button

				m_button(id).Text = id.ToString()

                AddHandler m_button(id).CheckedChanged, New EventHandler(AddressOf Button_CheckedChanged)

				panel1.Controls.Add(m_button(id))
			Next
		Next

        m_pov = New CheckBox(4) {}

        For i As Integer = 0 To 4
            Dim size As New Size(panel2.Width / 4, panel2.Height)

            m_pov(i) = New CheckBox()
            m_pov(i).Tag = i

            m_pov(i).Location = New Point(i * size.Width, 0)
            m_pov(i).Size = Size

            m_pov(i).Appearance = Appearance.Button

            m_pov(i).Text = String.Format("POV{0} Up", i)

            AddHandler m_pov(i).CheckedChanged, New EventHandler(AddressOf Pov_CheckedChanged)

            panel2.Controls.Add(m_pov(i))
        Next
	End Sub

    Private Sub trkXAxis_Scroll(ByVal sender As Object, ByVal e As EventArgs) Handles trkXAxis.Scroll
        m_vjoy.SetXAxis(CInt(nudDevice.Value), CShort(trkXAxis.Value))
        m_vjoy.Update(CInt(nudDevice.Value))
    End Sub

    Private Sub trkYAxis_Scroll(ByVal sender As Object, ByVal e As EventArgs) Handles trkYAxis.Scroll
        m_vjoy.SetYAxis(CInt(nudDevice.Value), CShort(trkYAxis.Value))
        m_vjoy.Update(CInt(nudDevice.Value))
    End Sub

    Private Sub trkZAxis_Scroll(ByVal sender As Object, ByVal e As EventArgs) Handles trkZAxis.Scroll
        m_vjoy.SetZAxis(CInt(nudDevice.Value), CShort(trkZAxis.Value))
        m_vjoy.Update(CInt(nudDevice.Value))
    End Sub

    Private Sub trkXRotation_Scroll(ByVal sender As Object, ByVal e As EventArgs) Handles trkXRotation.Scroll
        m_vjoy.SetXRotation(CInt(nudDevice.Value), CShort(trkXRotation.Value))
        m_vjoy.Update(CInt(nudDevice.Value))
    End Sub

    Private Sub trkYRotation_Scroll(ByVal sender As Object, ByVal e As EventArgs) Handles trkYRotation.Scroll
        m_vjoy.SetYRotation(CInt(nudDevice.Value), CShort(trkYRotation.Value))
        m_vjoy.Update(CInt(nudDevice.Value))
    End Sub

    Private Sub trkZRotation_Scroll(ByVal sender As Object, ByVal e As EventArgs) Handles trkZRotation.Scroll
        m_vjoy.SetZRotation(CInt(nudDevice.Value), CShort(trkZRotation.Value))
        m_vjoy.Update(CInt(nudDevice.Value))
    End Sub

    Private Sub trkSlider_Scroll(ByVal sender As Object, ByVal e As EventArgs) Handles trkSlider.Scroll
        m_vjoy.SetSlider(CInt(nudDevice.Value), CShort(trkSlider.Value))
        m_vjoy.Update(CInt(nudDevice.Value))
    End Sub

    Private Sub trkDial_Scroll(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles trkDial.Scroll
        m_vjoy.SetDial(CInt(nudDevice.Value), CShort(trkDial.Value))
        m_vjoy.Update(CInt(nudDevice.Value))
    End Sub

    Private Sub timer1_Tick(ByVal sender As Object, ByVal e As EventArgs) Handles timer1.Tick
        m_vjoy.Update(0)
    End Sub
End Class
