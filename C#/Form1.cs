using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace VJoyDemo
{
    public partial class Form1 : Form
    {
        CheckBox[] m_button = null;
        CheckBox[] m_pov = null;
        private VJoy m_vjoy = null;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            CreateButtons();

            m_vjoy = new VJoy();
            m_vjoy.Initialize();
            m_vjoy.Reset();
            m_vjoy.Update(0);
            m_vjoy.Update(1);

            timer1.Start();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            m_vjoy.Shutdown();
        }

        private void Button_CheckedChanged(object sender, EventArgs e)
        {
            CheckBox chk = (CheckBox)sender;

            m_vjoy.SetButton((int)nudDevice.Value, Int32.Parse(chk.Text), chk.Checked);
            m_vjoy.Update((int)nudDevice.Value);
        }

        private void Pov_CheckedChanged(object sender, EventArgs e)
        {
            CheckBox chk = (CheckBox)sender;

            m_vjoy.SetPOV((int)nudDevice.Value, (int)chk.Tag, chk.Checked ? VJoy.POVType.Up : VJoy.POVType.Nil);
            m_vjoy.Update((int)nudDevice.Value);
        }

        private void CreateButtons()
        {
            m_button = new CheckBox[32];

            for (int y = 0; y < 4; y++)
            {
                for (int x = 0; x < 8; x++)
                {
                    int id = y * 8 + x;
                    Size size = new Size(panel1.Width / 8, panel1.Height / 4);

                    m_button[id] = new CheckBox();
                    m_button[id].Tag = id;

                    m_button[id].Location = new Point(x * size.Width, y * size.Height);
                    m_button[id].Size = size;

                    m_button[id].Appearance = Appearance.Button;

                    m_button[id].Text = id.ToString();

                    m_button[id].CheckedChanged += new EventHandler(Button_CheckedChanged);

                    panel1.Controls.Add(m_button[id]);
                }
            }

            m_pov = new CheckBox[4];

            for (int i = 0; i < 4; i++)
            {
                Size size = new Size(panel2.Width / 4, panel2.Height);

                m_pov[i] = new CheckBox();
                m_pov[i].Tag = i;

                m_pov[i].Location = new Point(i * size.Width, 0);
                m_pov[i].Size = size;

                m_pov[i].Appearance = Appearance.Button;

                m_pov[i].Text = String.Format("POV{0} Up", i);

                m_pov[i].CheckedChanged += new EventHandler(Pov_CheckedChanged);

                panel2.Controls.Add(m_pov[i]);
            }
        }

        private void trkXAxis_Scroll(object sender, EventArgs e)
        {
            m_vjoy.SetXAxis((int)nudDevice.Value, (short)trkXAxis.Value);
            m_vjoy.Update((int)nudDevice.Value);
        }

        private void trkYAxis_Scroll(object sender, EventArgs e)
        {
            m_vjoy.SetYAxis((int)nudDevice.Value, (short)trkYAxis.Value);
            m_vjoy.Update((int)nudDevice.Value);
        }

        private void trkZAxis_Scroll(object sender, EventArgs e)
        {
            m_vjoy.SetZAxis((int)nudDevice.Value, (short)trkZAxis.Value);
            m_vjoy.Update((int)nudDevice.Value);
        }

        private void trkXRotation_Scroll(object sender, EventArgs e)
        {
            m_vjoy.SetXRotation((int)nudDevice.Value, (short)trkXRotation.Value);
            m_vjoy.Update((int)nudDevice.Value);
        }

        private void trkYRotation_Scroll(object sender, EventArgs e)
        {
            m_vjoy.SetYRotation((int)nudDevice.Value, (short)trkYRotation.Value);
            m_vjoy.Update((int)nudDevice.Value);
        }

        private void trkZRotation_Scroll(object sender, EventArgs e)
        {
            m_vjoy.SetZRotation((int)nudDevice.Value, (short)trkZRotation.Value);
            m_vjoy.Update((int)nudDevice.Value);
        }

        private void trkSlider_Scroll(object sender, EventArgs e)
        {
            m_vjoy.SetSlider((int)nudDevice.Value, (short)trkSlider.Value);
            m_vjoy.Update((int)nudDevice.Value);
        }

        private void trkDial_Scroll(object sender, EventArgs e)
        {
            m_vjoy.SetDial((int)nudDevice.Value, (short)trkDial.Value);
            m_vjoy.Update((int)nudDevice.Value);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
			m_vjoy.Initialize();
            m_vjoy.Update(0);
        }
    }
}
