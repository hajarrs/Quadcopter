using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;
using System.IO.Ports;
using System.IO;

namespace ModifPIDOnFly
{
    /// <summary>
    /// Lógica de interacción para MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        SerialPort puerto = new SerialPort();

        public MainWindow()
        {
            InitializeComponent();
            AddSerialPorts();
        }

        
        public void AddSerialPorts()
        {
            string[] strNamePorts = SerialPort.GetPortNames();
            for (int i = 0; i < strNamePorts.Length; i++)
            {
                this.cmb_puertoSerie.Items.Add(strNamePorts[i]);
            }
            if (this.cmb_puertoSerie.Items.IsEmpty == false)
            {
                this.btn_refresh.IsEnabled = false;
                this.btn_refresh.Visibility = System.Windows.Visibility.Hidden;
                this.btn_connect.Visibility = System.Windows.Visibility.Visible;
                this.btn_connect.IsEnabled = true;
                
            }
            else
            {
                this.btn_connect.IsEnabled = false;
                this.btn_connect.Visibility = System.Windows.Visibility.Hidden;
                this.btn_refresh.Visibility = System.Windows.Visibility.Visible;
                this.btn_refresh.IsEnabled = true;
            }

        }


        private void btn_refresh_Click(object sender, RoutedEventArgs e)
        {
            AddSerialPorts();
        }

        private void btn_connect_Click(object sender, RoutedEventArgs e)
        {
            puerto.BaudRate = 115200;
            puerto.Parity = Parity.None;
            puerto.StopBits = StopBits.One;
            puerto.DataBits = 8;
            puerto.Handshake = Handshake.None;
            puerto.ReadTimeout = 10000;
            puerto.WriteTimeout = 10000;
            puerto.WriteBufferSize = 4096;
            puerto.NewLine = "\r";
            puerto.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);

            try
            {
                puerto.Open();
            }
            catch
            {
                e.Handled = true;
                btn_Enviar.IsEnabled = false;
            }
            if (puerto.IsOpen)
            {
                cmb_puertoSerie.IsEnabled = false;
                btn_connect.IsEnabled = false;
                btn_Enviar.IsEnabled = true;
                btn_connect.Visibility = Visibility.Hidden;
                btn_disconnect.Visibility = Visibility.Visible;
                btn_disconnect.IsEnabled = true;
                txt_StatusComPort.Text = "Conectado a:  " + puerto.PortName;             
            }
        }


        public delegate void exec_ActTxtSerialPortRecepcion(string texto);
        public void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
        {
            try
            {
                byte[] mybyte = new byte[] {};
                SerialPort sp = sender as SerialPort;
//                sp.NewLine = "#";
                string indata = sp.ReadLine();
                //indata = indata.Trim();

                string textoSerial = indata;// Convert.ToString(mybyte);
                textoSerial = indata ;
/*                foreach (char c in textoSerial)
                {
                    int tmp = c;
                    hex += String.Format("{0}", (uint)System.Convert.ToUInt32(tmp.ToString()));
                    hex += "-";
                }
                hex += "\r";
                Dispatcher.Invoke(DispatcherPriority.Normal, new exec_ActTxtSerialPortRecepcion(ActualizarTextoDelPuertoSerieRecepcion), hex);
                textoSerial = indata;
                hex = "";
                foreach (char c in textoSerial)
                {
                    int tmp = c;
                    hex += c;
                    hex += "-";
                }
  */
                Dispatcher.Invoke(DispatcherPriority.Normal, new exec_ActTxtSerialPortRecepcion(ActualizarTextoDelPuertoSerieRecepcion), textoSerial);

            }
            catch
            {
                string Texto;
                Texto = "Error al recibir datos.\r";
                ActualizarTextoDelPuertoSerie(Texto);
            }
        }

        private void btn_disconnect_Click(object sender, RoutedEventArgs e)
        {
            if (puerto.IsOpen)
            {
                puerto.ReadExisting();
                puerto.Close();
            }
            txt_StatusComPort.Text = "Desconectado";
            btn_disconnect.IsEnabled = false;
            btn_disconnect.Visibility = Visibility.Hidden;
            btn_connect.Visibility = Visibility.Visible;
            btn_connect.IsEnabled = true;
            cmb_puertoSerie.IsEnabled = true;
            btn_Enviar.IsEnabled = false;
        }

        private void cmb_puertoSerie_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            object puertoSeleccionado = this.cmb_puertoSerie.SelectedItem;
            if (puertoSeleccionado != null)
            {
                btn_connect.IsEnabled = true;
                puerto.PortName = puertoSeleccionado.ToString();
            }
        }

        private void btn_Enviar_Click(object sender, RoutedEventArgs e)
        {
            string Texto;
            if (puerto.IsOpen == true)
            {
                Texto = "Enviando Texto....\r";
                ActualizarTextoDelPuertoSerie(Texto);

                try
                {
                    //puerto.Write(new byte[] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255 }, 0, 256);
                    
                    // Formato - $-PP-II-DD-B1-B2-Ts-QA-QB-RM-#
                    Texto = "Enviando Texto....\r";
                    Texto = "$" + txt_P_value.Text + ","
                        + txt_D_value.Text + ","
                        + txt_I_value.Text + ","
                        + txt_BM1_value.Text + ","
                        + txt_BM2_value.Text + ","
                        + txt_TS_value.Text + ","
                        + txt_QA_value.Text + ","
                        + txt_QB_value.Text + ","
                        + txt_RM_value.Text + "#";

                    puerto.WriteLine(Texto);


                    ActualizarTextoDelPuertoSerie(Texto);
                }
                catch
                {
                    ActualizarTextoDelPuertoSerie("Error al enviar los datos\r");
                    e.Handled = true;
                }
            }
            else
            {
                ActualizarTextoDelPuertoSerie("No hay conexion con el dispositivo.\r");
            }
            

        }

        public void ActualizarTextoDelPuertoSerie(string Texto)
        {
            SerialPortDlgText.AppendText(Texto);
            SerialPortDlgText.ScrollToEnd();
        }

        public void ActualizarTextoDelPuertoSerieRecepcion(string Texto)
        {
            TextoRecibido.AppendText(Texto);
            TextoRecibido.ScrollToEnd();
        }


        private void DebugPlaca_Pc_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                puerto.Write(new byte[] {36, 68, 33, 5, 4, 82, 65, 85, 76 ,50, 35  }, 0, 11);   // $D!54RAUL2#
                ActualizarTextoDelPuertoSerie("< $D!54RAUL2#\r");
                // $D!54RAUL3#
            }
            catch
            { }
        }


    }
}
