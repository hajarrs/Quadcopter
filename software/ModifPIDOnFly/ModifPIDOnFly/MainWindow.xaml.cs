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
        string PuertoAnterior;
        string VelocidadAnterior;
        bool flg_recibirDatos = false;

        public MainWindow()
        {
            InitializeComponent();
            AddSerialPorts();
            LoadPIDData();
            TextBox_P.Focus();
        }

        
        public void AddSerialPorts()
        {
            LoadConectionData();
            string[] strNamePorts = SerialPort.GetPortNames();
            for (int i = 0; i < strNamePorts.Length; i++)
            {
                this.cmb_puertoSerie.Items.Add(strNamePorts[i]);
                if(strNamePorts[i] == PuertoAnterior)
                    this.cmb_puertoSerie.SelectedIndex = i;
            }
            this.cmb_v_puertoSerie.Visibility = Visibility.Visible;
            this.cmb_v_puertoSerie.Items.Clear();
            this.cmb_v_puertoSerie.Items.Add("9600");
            this.cmb_v_puertoSerie.Items.Add("115200");
            this.cmb_v_puertoSerie.SelectedIndex = 1;
            if(VelocidadAnterior == "9600")
                this.cmb_v_puertoSerie.SelectedIndex = 0;
            if (VelocidadAnterior == "115200")
                this.cmb_v_puertoSerie.SelectedIndex = 1;

            if (this.cmb_puertoSerie.Items.IsEmpty == false && this.cmb_v_puertoSerie.Items.IsEmpty == false)
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
                this.cmb_v_puertoSerie.Items.Clear();
            }

        }

        private void SaveConectionData()
        {
            try
            {
                string fichero = Directory.GetCurrentDirectory() + "\\Config\\Config.conf";
                System.IO.StreamWriter sr = new System.IO.StreamWriter(fichero);
                sr.WriteLine(puerto.PortName);
                sr.WriteLine(puerto.BaudRate);
                sr.Close();
            }
            catch { }
        }

        private void LoadConectionData()
        {
            try
            {
                string fichero = Directory.GetCurrentDirectory() + "\\Config\\Config.conf";
                System.IO.StreamReader sr = new System.IO.StreamReader(fichero);
                PuertoAnterior = sr.ReadLine();
                VelocidadAnterior = sr.ReadLine();
                sr.Close();
            }
            catch
            {
                PuertoAnterior = "NULL";
                VelocidadAnterior = "NULL";
            }
        }

        private void btn_refresh_Click(object sender, RoutedEventArgs e)
        {
            AddSerialPorts();
        }

        private void btn_connect_Click(object sender, RoutedEventArgs e)
        {
            string baudios = cmb_v_puertoSerie.SelectedValue.ToString();
            if (baudios == "9600")
                puerto.BaudRate = 9600;
            else
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
                cmb_v_puertoSerie.IsEnabled = false;
                btn_connect.IsEnabled = false;
                btn_Enviar.IsEnabled = true;
                btn_connect.Visibility = Visibility.Hidden;
                btn_disconnect.Visibility = Visibility.Visible;
                btn_disconnect.IsEnabled = true;
                txt_StatusComPort.Text = "Conectado a:  " + puerto.PortName;
                SaveConectionData();                
            }
        }


        public void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
        {
            try
            {

                SerialPort sp = sender as SerialPort;
                string indata = sp.ReadLine();
                indata = indata.Trim();

                string textoSerial;
                textoSerial = indata + "\r";
                if (flg_recibirDatos)
                {

                }
            }
            catch
            {
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
            cmb_v_puertoSerie.IsEnabled = true;
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
                Texto = "@PID" + TextBox_P.Text + "&" + TextBox_I.Text + "&" + TextBox_D.Text + "&" + TextBox_BM1.Text + "&" + TextBox_BM2.Text + "#\r\n";
                ActualizarTextoDelPuertoSerie(Texto);
                try
                {
                    puerto.WriteLine(Texto);
                    ActualizarFicheroHistory(Texto);
                    Texto = "OK!\r";
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

        public void ActualizarFicheroHistory(string Texto)
        {
            try
            {
                DateTime fecha = DateTime.Now;
                string Escritura;
                string fichero = Directory.GetCurrentDirectory() + "\\history\\history.his";
                System.IO.StreamWriter sr = new System.IO.StreamWriter(fichero,true);
                Escritura = fecha.ToString() + Texto;
                sr.Write(Escritura);
                sr.Close();
            }
            catch { }
        }

        private void LoadPIDData()
        {
            try
            {
                string Linea;
                string fichero = Directory.GetCurrentDirectory() + "\\history\\history.his";
                System.IO.StreamReader sr = new System.IO.StreamReader(fichero);
                do
                {
                    Linea = sr.ReadLine();
                } while (!sr.EndOfStream);
                if (Linea != null)
                {
                    ActualizarDatosPID(Linea);
                }
                sr.Close();
            }
            catch
            {}
        }

        private void ActualizarDatosPID(string Linea)
        {
            string _textoPID = Linea.Remove(0, Linea.IndexOf("@PID")+4);
            _textoPID = _textoPID.Remove(_textoPID.Length-1);
            string [] Valores = _textoPID.Split('&');
            TextBox_P.Text = Valores[0].ToString();
            TextBox_I.Text = Valores[1].ToString();
            TextBox_D.Text = Valores[2].ToString();
            TextBox_BM1.Text = Valores[3].ToString();
            TextBox_BM2.Text = Valores[4].ToString();
        }

        private void TextBox_P_GotFocus(object sender, RoutedEventArgs e)
        {
            TextBox_P.SelectAll();
        }

        private void TextBox_I_GotFocus(object sender, RoutedEventArgs e)
        {
            TextBox_I.SelectAll();
        }

        private void TextBox_D_GotFocus(object sender, RoutedEventArgs e)
        {
            TextBox_D.SelectAll();
        }

        private void TextBox_BM1_GotFocus(object sender, RoutedEventArgs e)
        {
            TextBox_BM1.SelectAll();
        }

        private void TextBox_BM2_GotFocus(object sender, RoutedEventArgs e)
        {
            TextBox_BM2.SelectAll();
        }

        private void textBox1_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void SerialPortDlgText_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

    }
}
