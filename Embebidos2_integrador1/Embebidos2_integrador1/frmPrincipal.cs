﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace Embebidos2_integrador1
{
    public partial class frmPrincipal : Form
    {
        public frmPrincipal()
        {
            InitializeComponent();
        }

        int on = 0;
        private void btnOnOff_Click(object sender, EventArgs e)
        {
            if (!arduino.IsOpen)
                arduino.Open();
            if (on.Equals(0))
            {
                lblOnOff.Text = "ON";
                lblOnOff.ForeColor = Color.FromArgb(100, 128, 255, 128);

                on = 1;
                if (sen.Equals(0)) //Izquierda
                {
                    arduino.Write("1");
                } else if (sen.Equals(1)) //Derecha
                {
                    arduino.Write("2");
                }
            } else if (on.Equals(1))
            {
                lblOnOff.Text = "OFF";
                lblOnOff.ForeColor = Color.FromArgb(100, 255, 128, 128);
                arduino.Write("0");
                on = 0;
            }
        }



        private void frmPrincipal_Load(object sender, EventArgs e)
        {
            object[] puertos = SerialPort.GetPortNames();
            cmbPuertos.Items.AddRange(puertos);
            cmbPuertos.SelectedIndex = 0;
            if (arduino.IsOpen)
                arduino.Close();

        }

        private void trkVelocidad_CursorChanged(object sender, EventArgs e)
        {

        }

        private void setVelocity()
        {
            String vi = trkVelocidad.Value.ToString();
            lblV.Text = "V = " + vi;
        }

        private void trkVelocidad_ValueChanged(object sender, EventArgs e)
        {
            setVelocity();
        }

        private void btnAcercaDe_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Me creó el guapo Bryant", "¿Quien me creó", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void btnSalir_Click(object sender, EventArgs e)
        {
            Salir();

        }

        private void Salir()
        {
            DialogResult dr = MessageBox.Show("¿Esta seguo que quiere salir?", "Salir", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
            if (dr == DialogResult.Yes)
            {
                arduino.Close();
                Application.Exit();
            }
        }

        int sen = 0;
        private void lblIzq_Click(object sender, EventArgs e)
        {

        }

        private void btnGiro_Click(object sender, EventArgs e)
        {
            if (!arduino.IsOpen)
                arduino.Open();
            if (sen.Equals(0))
            {
                lblIzq.Text = "DER";
                lblIzq.ForeColor = Color.Yellow;
                sen = 1;
                if (on.Equals(1)) //Derecha
                {
                    arduino.Write("2");
                }
            }
            else if (sen.Equals(1))
            {
                lblIzq.Text = "IZQ";
                lblIzq.ForeColor = Color.Cyan;
                sen = 0;
                if (on.Equals(2)) //Izquierda
                {
                    arduino.Write("1");
                }
            }
        }

        private void cmbPuertos_SelectedIndexChanged(object sender, EventArgs e)
        {

            if (cmbPuertos != null)
            {
                if (arduino.IsOpen)
                {
                    MessageBox.Show("Este puerto esta en uso " + arduino.PortName, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);

                }
                else
                {
                    MessageBox.Show("El arduino se conecto correctamente al puerto " + cmbPuertos.Text, "Arduino conctado", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    arduino.Close();
                    arduino.PortName = cmbPuertos.Text;
                    arduino.Open();
                }

            }
        }

        private void frmPrincipal_FormClosing(object sender, FormClosingEventArgs e)
        {
            try
            {
                arduino.Close();

            }
            catch (Exception ex)
            {
            }
        } 

        private void cmbPuertos_Click(object sender, EventArgs e)
        {
            object[] ob = SerialPort.GetPortNames();
            cmbPuertos.Items.AddRange(ob);
        }

        private void trkVelocidad_MouseUp(object sender, MouseEventArgs e)
        {
            try
            {
                if (!arduino.IsOpen)
                {
                    arduino.Open();
                }
                switch (trkVelocidad.Value)
                {
                    case 0:
                        arduino.Write("a");
                        break;
                    case 1:
                        arduino.Write("b");
                        break;
                    case 2:
                        arduino.Write("c");
                        break;
                    case 3:
                        arduino.Write("d");
                        break;
                    case 4:
                        arduino.Write("e");
                        break;
                    case 5:
                        arduino.Write("f");
                        break;
                    case 6:
                        arduino.Write("g");
                        break;
                    case 7:
                        arduino.Write("h");
                        break;
                    case 8:
                        arduino.Write("i");
                        break;
                    case 9:
                        arduino.Write("j");
                        break;
                }
            } catch (Exception ex)
            {
                MessageBox.Show("No se pudo abrir el puerto de comunicacion " + cmbPuertos.Text,"Error",MessageBoxButtons.OK,MessageBoxIcon.Error);
            }
        }
    }
}
