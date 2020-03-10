using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;


namespace Embebidos2_Integrador2
{
    public partial class frmPrincipal : Form
    {
        public frmPrincipal()
        {
            InitializeComponent();
            
        }

        private void BtnExit_Click(object sender, EventArgs e)
        {
            DialogResult dr = MessageBox.Show("¿Desea salir?", "Salir", MessageBoxButtons.YesNo, MessageBoxIcon.Exclamation);
            if(dr == DialogResult.Yes)
            {
                arduino.Close();
                Application.Exit();
            }
            
        }

        private void FrmPrincipal_Load(object sender, EventArgs e)
        {
            cargarMisCosas();
        }

        private void cargarMisCosas()
        {
            object[] puertos = SerialPort.GetPortNames();
            cmbPuertos.Items.AddRange(puertos);
            cmbPuertos.SelectedIndex = 0;
            try
            {
                arduino.PortName = (string)puertos[0];
                //mensaje("Informacion", "El puerto seleccionado es el " + puertos[0]);
                if (!arduino.IsOpen)
                {
                    arduino.Open();
                    //mensaje("Informacion", "El puerto " + puertos[0] + " ha sido abierto");
                }
            }
            catch (Exception ex)
            {
                //mensaje("Error", "El puerto se encuentra en uso");
            }
        }
        private void mensaje(String titulo, String men)
        {
            MessageBox.Show(men, titulo, MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void CmbPuertos_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                if(cmbPuertos.Text != null)
                {
                    if(arduino.PortName == cmbPuertos.Text)
                    {
                        //mensaje("Error", "Puerto actualmente en uso");
                        
                    } else
                    {
                        try
                        {
                            arduino.Close();
                            arduino.PortName = cmbPuertos.Text;
                            arduino.Open();
                            mensaje("Puerto cambiado", "Puerto " + arduino.PortName + " seleccionado con exito");
                        }
                        catch (Exception ex)
                        {
                            mensaje("Error", "Puerto en uso por otro programa");
                        }
                    }
                }
            }catch (Exception ex)
            {

            }
        }

        private void BtnOn_Click(object sender, EventArgs e)
        {
            try
            {
                if (!arduino.IsOpen)
                    arduino.Open();
                arduino.Write("0");
                timer.Start();
                
            }catch(Exception ex)
            {

            }
        }

        String temp = "0";
        private void Timer_Tick(object sender, EventArgs e)
        {
            
                    lblTemp.Text = temp;
           
        }

        private void Arduino_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            if (arduino.IsOpen)
            {
                temp = arduino.ReadLine();
                
            }
        }
    }
}
