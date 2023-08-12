namespace VJoyDemo
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
			this.components = new System.ComponentModel.Container();
			this.lblDevice = new System.Windows.Forms.Label();
			this.nudDevice = new System.Windows.Forms.NumericUpDown();
			this.trkXAxis = new System.Windows.Forms.TrackBar();
			this.lblXAxis = new System.Windows.Forms.Label();
			this.lblZRotation = new System.Windows.Forms.Label();
			this.trkZRotation = new System.Windows.Forms.TrackBar();
			this.lblYAxis = new System.Windows.Forms.Label();
			this.trkYAxis = new System.Windows.Forms.TrackBar();
			this.lblSlider = new System.Windows.Forms.Label();
			this.trkSlider = new System.Windows.Forms.TrackBar();
			this.lblZAxis = new System.Windows.Forms.Label();
			this.trkZAxis = new System.Windows.Forms.TrackBar();
			this.panel1 = new System.Windows.Forms.Panel();
			this.timer1 = new System.Windows.Forms.Timer(this.components);
			this.lblYRotation = new System.Windows.Forms.Label();
			this.trkYRotation = new System.Windows.Forms.TrackBar();
			this.lblXRotation = new System.Windows.Forms.Label();
			this.trkXRotation = new System.Windows.Forms.TrackBar();
			this.panel2 = new System.Windows.Forms.Panel();
			this.lblDial = new System.Windows.Forms.Label();
			this.trkDial = new System.Windows.Forms.TrackBar();
			((System.ComponentModel.ISupportInitialize)(this.nudDevice)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.trkXAxis)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.trkZRotation)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.trkYAxis)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.trkSlider)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.trkZAxis)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.trkYRotation)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.trkXRotation)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.trkDial)).BeginInit();
			this.SuspendLayout();
			// 
			// lblDevice
			// 
			this.lblDevice.AutoSize = true;
			this.lblDevice.Location = new System.Drawing.Point(107, 14);
			this.lblDevice.Name = "lblDevice";
			this.lblDevice.Size = new System.Drawing.Size(85, 13);
			this.lblDevice.TabIndex = 0;
			this.lblDevice.Text = "Joystick Device:";
			// 
			// nudDevice
			// 
			this.nudDevice.Location = new System.Drawing.Point(230, 12);
			this.nudDevice.Maximum = new decimal(new int[] {
            1,
            0,
            0,
            0});
			this.nudDevice.Name = "nudDevice";
			this.nudDevice.Size = new System.Drawing.Size(34, 20);
			this.nudDevice.TabIndex = 1;
			// 
			// trkXAxis
			// 
			this.trkXAxis.Location = new System.Drawing.Point(21, 77);
			this.trkXAxis.Maximum = 32767;
			this.trkXAxis.Minimum = -32768;
			this.trkXAxis.Name = "trkXAxis";
			this.trkXAxis.Size = new System.Drawing.Size(254, 45);
			this.trkXAxis.TabIndex = 2;
			this.trkXAxis.TickFrequency = 1024;
			this.trkXAxis.Scroll += new System.EventHandler(this.trkXAxis_Scroll);
			// 
			// lblXAxis
			// 
			this.lblXAxis.AutoSize = true;
			this.lblXAxis.Location = new System.Drawing.Point(30, 61);
			this.lblXAxis.Name = "lblXAxis";
			this.lblXAxis.Size = new System.Drawing.Size(36, 13);
			this.lblXAxis.TabIndex = 3;
			this.lblXAxis.Text = "X Axis";
			// 
			// lblZRotation
			// 
			this.lblZRotation.AutoSize = true;
			this.lblZRotation.Location = new System.Drawing.Point(331, 170);
			this.lblZRotation.Name = "lblZRotation";
			this.lblZRotation.Size = new System.Drawing.Size(57, 13);
			this.lblZRotation.TabIndex = 5;
			this.lblZRotation.Text = "Z Rotation";
			// 
			// trkZRotation
			// 
			this.trkZRotation.Location = new System.Drawing.Point(322, 186);
			this.trkZRotation.Maximum = 32767;
			this.trkZRotation.Minimum = -32768;
			this.trkZRotation.Name = "trkZRotation";
			this.trkZRotation.Size = new System.Drawing.Size(254, 45);
			this.trkZRotation.TabIndex = 4;
			this.trkZRotation.TickFrequency = 1024;
			this.trkZRotation.Scroll += new System.EventHandler(this.trkZRotation_Scroll);
			// 
			// lblYAxis
			// 
			this.lblYAxis.AutoSize = true;
			this.lblYAxis.Location = new System.Drawing.Point(30, 112);
			this.lblYAxis.Name = "lblYAxis";
			this.lblYAxis.Size = new System.Drawing.Size(36, 13);
			this.lblYAxis.TabIndex = 7;
			this.lblYAxis.Text = "Y Axis";
			// 
			// trkYAxis
			// 
			this.trkYAxis.Location = new System.Drawing.Point(21, 128);
			this.trkYAxis.Maximum = 32767;
			this.trkYAxis.Minimum = -32768;
			this.trkYAxis.Name = "trkYAxis";
			this.trkYAxis.Size = new System.Drawing.Size(254, 45);
			this.trkYAxis.TabIndex = 6;
			this.trkYAxis.TickFrequency = 1024;
			this.trkYAxis.Scroll += new System.EventHandler(this.trkYAxis_Scroll);
			// 
			// lblSlider
			// 
			this.lblSlider.AutoSize = true;
			this.lblSlider.Location = new System.Drawing.Point(30, 226);
			this.lblSlider.Name = "lblSlider";
			this.lblSlider.Size = new System.Drawing.Size(33, 13);
			this.lblSlider.TabIndex = 9;
			this.lblSlider.Text = "Slider";
			// 
			// trkSlider
			// 
			this.trkSlider.Location = new System.Drawing.Point(21, 242);
			this.trkSlider.Maximum = 32767;
			this.trkSlider.Minimum = -32768;
			this.trkSlider.Name = "trkSlider";
			this.trkSlider.Size = new System.Drawing.Size(254, 45);
			this.trkSlider.TabIndex = 8;
			this.trkSlider.TickFrequency = 1024;
			this.trkSlider.Scroll += new System.EventHandler(this.trkSlider_Scroll);
			// 
			// lblZAxis
			// 
			this.lblZAxis.AutoSize = true;
			this.lblZAxis.Location = new System.Drawing.Point(30, 170);
			this.lblZAxis.Name = "lblZAxis";
			this.lblZAxis.Size = new System.Drawing.Size(36, 13);
			this.lblZAxis.TabIndex = 11;
			this.lblZAxis.Text = "Z Axis";
			// 
			// trkZAxis
			// 
			this.trkZAxis.Location = new System.Drawing.Point(21, 186);
			this.trkZAxis.Maximum = 32767;
			this.trkZAxis.Minimum = -32768;
			this.trkZAxis.Name = "trkZAxis";
			this.trkZAxis.Size = new System.Drawing.Size(254, 45);
			this.trkZAxis.TabIndex = 10;
			this.trkZAxis.TickFrequency = 1024;
			this.trkZAxis.Scroll += new System.EventHandler(this.trkZAxis_Scroll);
			// 
			// panel1
			// 
			this.panel1.Location = new System.Drawing.Point(21, 339);
			this.panel1.Name = "panel1";
			this.panel1.Size = new System.Drawing.Size(555, 87);
			this.panel1.TabIndex = 14;
			// 
			// timer1
			// 
			this.timer1.Interval = 60000;
			this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
			// 
			// lblYRotation
			// 
			this.lblYRotation.AutoSize = true;
			this.lblYRotation.Location = new System.Drawing.Point(331, 112);
			this.lblYRotation.Name = "lblYRotation";
			this.lblYRotation.Size = new System.Drawing.Size(57, 13);
			this.lblYRotation.TabIndex = 16;
			this.lblYRotation.Text = "Y Rotation";
			// 
			// trkYRotation
			// 
			this.trkYRotation.Location = new System.Drawing.Point(322, 128);
			this.trkYRotation.Maximum = 32767;
			this.trkYRotation.Minimum = -32768;
			this.trkYRotation.Name = "trkYRotation";
			this.trkYRotation.Size = new System.Drawing.Size(254, 45);
			this.trkYRotation.TabIndex = 15;
			this.trkYRotation.TickFrequency = 1024;
			this.trkYRotation.Scroll += new System.EventHandler(this.trkYRotation_Scroll);
			// 
			// lblXRotation
			// 
			this.lblXRotation.AutoSize = true;
			this.lblXRotation.Location = new System.Drawing.Point(331, 61);
			this.lblXRotation.Name = "lblXRotation";
			this.lblXRotation.Size = new System.Drawing.Size(57, 13);
			this.lblXRotation.TabIndex = 18;
			this.lblXRotation.Text = "X Rotation";
			// 
			// trkXRotation
			// 
			this.trkXRotation.Location = new System.Drawing.Point(322, 77);
			this.trkXRotation.Maximum = 32767;
			this.trkXRotation.Minimum = -32768;
			this.trkXRotation.Name = "trkXRotation";
			this.trkXRotation.Size = new System.Drawing.Size(254, 45);
			this.trkXRotation.TabIndex = 17;
			this.trkXRotation.TickFrequency = 1024;
			this.trkXRotation.Scroll += new System.EventHandler(this.trkXRotation_Scroll);
			// 
			// panel2
			// 
			this.panel2.Location = new System.Drawing.Point(21, 293);
			this.panel2.Name = "panel2";
			this.panel2.Size = new System.Drawing.Size(555, 32);
			this.panel2.TabIndex = 19;
			// 
			// lblDial
			// 
			this.lblDial.AutoSize = true;
			this.lblDial.Location = new System.Drawing.Point(331, 226);
			this.lblDial.Name = "lblDial";
			this.lblDial.Size = new System.Drawing.Size(25, 13);
			this.lblDial.TabIndex = 21;
			this.lblDial.Text = "Dial";
			// 
			// trkDial
			// 
			this.trkDial.Location = new System.Drawing.Point(322, 242);
			this.trkDial.Maximum = 32767;
			this.trkDial.Minimum = -32768;
			this.trkDial.Name = "trkDial";
			this.trkDial.Size = new System.Drawing.Size(254, 45);
			this.trkDial.TabIndex = 20;
			this.trkDial.TickFrequency = 1024;
			this.trkDial.Scroll += new System.EventHandler(this.trkDial_Scroll);
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(603, 450);
			this.Controls.Add(this.lblDial);
			this.Controls.Add(this.trkDial);
			this.Controls.Add(this.panel2);
			this.Controls.Add(this.lblSlider);
			this.Controls.Add(this.trkZRotation);
			this.Controls.Add(this.lblZRotation);
			this.Controls.Add(this.trkYRotation);
			this.Controls.Add(this.lblYRotation);
			this.Controls.Add(this.lblXRotation);
			this.Controls.Add(this.trkXRotation);
			this.Controls.Add(this.panel1);
			this.Controls.Add(this.lblZAxis);
			this.Controls.Add(this.trkZAxis);
			this.Controls.Add(this.trkSlider);
			this.Controls.Add(this.lblYAxis);
			this.Controls.Add(this.trkYAxis);
			this.Controls.Add(this.lblXAxis);
			this.Controls.Add(this.trkXAxis);
			this.Controls.Add(this.nudDevice);
			this.Controls.Add(this.lblDevice);
			this.Name = "Form1";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Form1";
			this.Load += new System.EventHandler(this.Form1_Load);
			this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
			((System.ComponentModel.ISupportInitialize)(this.nudDevice)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.trkXAxis)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.trkZRotation)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.trkYAxis)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.trkSlider)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.trkZAxis)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.trkYRotation)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.trkXRotation)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.trkDial)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblDevice;
        private System.Windows.Forms.NumericUpDown nudDevice;
        private System.Windows.Forms.TrackBar trkXAxis;
        private System.Windows.Forms.Label lblXAxis;
        private System.Windows.Forms.Label lblZRotation;
        private System.Windows.Forms.TrackBar trkZRotation;
        private System.Windows.Forms.Label lblYAxis;
        private System.Windows.Forms.TrackBar trkYAxis;
        private System.Windows.Forms.Label lblSlider;
        private System.Windows.Forms.TrackBar trkSlider;
        private System.Windows.Forms.Label lblZAxis;
        private System.Windows.Forms.TrackBar trkZAxis;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Label lblYRotation;
        private System.Windows.Forms.TrackBar trkYRotation;
        private System.Windows.Forms.Label lblXRotation;
        private System.Windows.Forms.TrackBar trkXRotation;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Label lblDial;
        private System.Windows.Forms.TrackBar trkDial;
    }
}

