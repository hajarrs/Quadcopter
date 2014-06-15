Public Class mainForm

    Private pktSize As Integer = 0
    Private pktBuf(1000) As Byte
    Private TickNumberForClearToolbar As Integer = 0
    Private RealSize As Int16

    Private points As New ArrayList
    Private pointsArray As New ArrayList


    Private Sub updateComPortList()

        comPortComboBox.Items.Clear()
        comPortComboBox.Items.Add("None")

        Dim s As String
        For Each s In IO.Ports.SerialPort.GetPortNames()
            comPortComboBox.Items.Add(s)
        Next s

        comPortComboBox.SelectedIndex = 0
        baudRateComboBox.SelectedIndex = 0
    End Sub


    Public Sub New()

        ' This call is required by the designer.
        InitializeComponent()

        'NOTE: The version info does not come out correctly when debugging inside Visual Studio. It comes out correctly
        'when installed and run from using the Click-once generated setup files.
        If (System.Deployment.Application.ApplicationDeployment.IsNetworkDeployed) Then
            With System.Deployment.Application.ApplicationDeployment.CurrentDeployment.CurrentVersion
                ToolStripStatusLabel_Version.Text = .Major & "." & .Minor
            End With
        End If

        updateComPortList()
        ''''''Chart Setup'''''''
        Chart1.ChartAreas(0).AxisX.Maximum = plotSetup.xAxisNumPoints
        Chart1.ChartAreas(0).AxisY.Minimum = plotSetup.yAxisMinVal
        Chart1.ChartAreas(0).AxisY.Maximum = plotSetup.yAxisMaxVal

        ' Adjust Y & X axis scale
        Chart1.ResetAutoValues()
        Chart1.Series(0).Name = plotSetup.Ch1LegendTxtBox.Text
        Chart1.Series(1).Name = plotSetup.Ch2LegendTxtBox.Text
        Chart1.Series(2).Name = plotSetup.Ch3LegendTxtBox.Text
        Chart1.Series(3).Name = plotSetup.Ch4LegendTxtBox.Text

        ' Add any initialization after the InitializeComponent() call.
        Timer1.Start()
        CargarDatos()
        RealSize = Width
        Dim sistema As System.Windows.Forms.Padding
        sistema.Left = 490
        LoadData.Margin = sistema
        TickNumberForClearToolbar = 50
    End Sub

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        Static Dim tickCount As UShort = 0

        'integer overflow generates an exception in .net
        If tickCount = UShort.MaxValue Then
            tickCount = 0
            SaveDataStatus.Text = ""
        Else
            tickCount += 1
            If (tickCount > (TickNumberForClearToolbar + 40)) Then
                SaveDataStatus.Text = ""

            End If
        End If

        TimerTickLabel.Text = tickCount

        If connectDisconnectButton.Text = "Desconectar" Then

            'Parse the data from serial port and store all the packets in a collection data type.
            parseData()        'RAUL

        End If



        ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
        ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
        'Serial port loop back test. Transmitting a packet that is meant to be looped back into serial port. 
        'Short the Tx pin to Rx pin externally.

        Dim txBuffer(100) As Byte
        Dim byteArray As Byte()
        Static Dim ANGLE As Double = 0

        txBuffer(0) = &HAB      'Header byte1
        txBuffer(1) = &HCD      'Header byte2
        txBuffer(2) = 6         'Packet size high byte
        txBuffer(3) = 0         'Packet side low byte

        ANGLE += Math.PI / 53

        byteArray = BitConverter.GetBytes(CShort(100 * Math.Cos(ANGLE)))
        txBuffer(4) = byteArray(0)
        txBuffer(5) = byteArray(1)

        byteArray = BitConverter.GetBytes(CShort(100 * Math.Sin(ANGLE)))
        txBuffer(6) = byteArray(0)
        txBuffer(7) = byteArray(1)

        byteArray = BitConverter.GetBytes(CShort(100 * Math.Sin(ANGLE) / 2))
        txBuffer(8) = byteArray(0)
        txBuffer(9) = byteArray(1)


        If connectDisconnectButton.Text = "Desconectar" Then

            'SerialPort1.Write(txBuffer, 0, (2 + 2 + 6))    'RAUL   

            '            If (tickCount Mod 10 = 0) Then 'RAUL
            'SerialPort1.WriteLine("hello") 'RAUL
            'End If 'RAUL
        End If




        ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
        ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''



        ' '''''''''''''''Simulating data '''''''''''''''''''''''
        'Static Dim ANGLE As Double = 0

        'ANGLE += Math.PI / 53
        'points.Add(1000 * Math.Cos(ANGLE))
        'points.Add(1000 * Math.Sin(ANGLE))
        'points.Add(1000 * Math.Cos(ANGLE) / 2)
        'If Chart1.Series(0).Points.Count = plotSetup.xAxisNumPoints Then
        '    points.Add(1000 * Math.Sin(ANGLE) / 2)
        'End If


        'pointsArray.Add(New ArrayList(points))
        'points.Clear()

        'ANGLE += Math.PI / 53
        'points.Add(1000 * Math.Cos(ANGLE))
        'points.Add(1000 * Math.Sin(ANGLE))
        'points.Add(1000 * Math.Cos(ANGLE) / 2)
        'If Chart1.Series(0).Points.Count = plotSetup.xAxisNumPoints Then
        '    points.Add(1000 * Math.Sin(ANGLE) / 2)
        'End If


        'pointsArray.Add(New ArrayList(points))
        'points.Clear()

        'ANGLE += Math.PI / 53
        'points.Add(1000 * Math.Cos(ANGLE))
        'points.Add(1000 * Math.Sin(ANGLE))
        'points.Add(1000 * Math.Cos(ANGLE) / 2)
        'If Chart1.Series(0).Points.Count = plotSetup.xAxisNumPoints Then
        '    points.Add(1000 * Math.Sin(ANGLE) / 2)
        'End If

        'pointsArray.Add(New ArrayList(points))
        'points.Clear()

        'ANGLE += Math.PI / 53
        'points.Add(1000 * Math.Cos(ANGLE))
        'points.Add(1000 * Math.Sin(ANGLE))
        'points.Add(1000 * Math.Cos(ANGLE) / 2)
        'If Chart1.Series(0).Points.Count = plotSetup.xAxisNumPoints Then
        '    points.Add(1000 * Math.Sin(ANGLE) / 2)
        'End If

        'pointsArray.Add(New ArrayList(points))
        'points.Clear()
        ' '''''''''''''''end of Simulating data '''''''''''''''''''''''


        '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
        ' At this stage pointsArray contains the new samples obtained from the serial port.
        ' pointsArray is an array of arrays.
        ' Perform any filtering or signal processing on the samples at this point.
        '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''



        'Copy new samples from pointsArray into the plot array
        'check if there is something to plot
        If pointsArray.Count > 0 Then
            Chart1.Series.SuspendUpdates()

            'Outer for loop, cycles through the array containing samples from different sampling instants
            For Each i In pointsArray
                'inner loops cycles through the samples of data from different channels at a given sampling instant.
                For j As Integer = 0 To plotSetup.MAX_DATA_SERIES - 1 Step 1

                    'the number of channels on chart and number of channels in the packet may not match
                    If j < i.count Then
                        'add the samples to the chart that were got from serial port
                        Chart1.Series(j).Points.AddY(i.item(j))
                    Else
                        'if less number of samples than number of channels were got, then add "nothing" data points to remaining channels 
                        'so that they are in sync with other channels
                        Chart1.Series(j).Points.AddY(0.0)
                        Chart1.Series(j).Points(Chart1.Series(j).Points.Count - 1).IsEmpty = True

                    End If
                Next
            Next

            While Chart1.Series(0).Points.Count > plotSetup.xAxisNumPoints
                For Each i In Chart1.Series
                    i.Points.RemoveAt(0)
                Next
            End While

            Chart1.Series.ResumeUpdates()
            ' Adjust Y & X axis scale
            Chart1.ResetAutoValues()

            ''House keeping jobs perform periodically but at low frequency
            If (tickCount Mod 10 = 0) Then
                If (TerminalWindow.Lines.Length > 2100) Then
                    Array.Resize(TerminalWindow.Lines, 2000)
                    TerminalWindow.AppendText(vbNewLine)
                End If
                If (textBox.Lines.Length > 2100) Then
                    Array.Resize(textBox.Lines, 2000)
                    textBox.AppendText(vbNewLine)
                End If

            End If
        End If

    End Sub

    Private Sub connectDisconnectButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles connectDisconnectButton.Click

        If connectDisconnectButton.Text = "Conectar" Then
            If comPortOpen() Then
                connectDisconnectButton.Text = "Desconectar"
            Else
                textBox.AppendText("Error: No se ha podido abrir el puerto seleccionado.")
            End If
        Else
            SerialPort1.Close()
            connectDisconnectButton.Text = "Conectar"
        End If

    End Sub

    Private Function comPortOpen() As Boolean
        Dim portName As String = Nothing
        Dim baudRate As Integer

        portName = comPortComboBox.Text
        baudRate = Convert.ToInt32(baudRateComboBox.Text)

        textBox.AppendText("Port Name :" & portName & vbCrLf)
        textBox.AppendText("Baud Rate :" & baudRate & vbCrLf)

        SerialPort1.PortName = portName
        SerialPort1.BaudRate = baudRate
        Try
            SerialPort1.Open()
        Catch
        End Try

        If SerialPort1.IsOpen Then
            textBox.AppendText("Serial Port Opened")
            textBox.AppendText(Environment.NewLine)
            Return True
        End If


        Return False
    End Function

    Public Enum ParseState_MC
        IDLE
        HEADER1
        HEADER2
        PKT_SIZE
        PAYLOAD
    End Enum

    Private Function parseData() As Boolean
        Dim tempByte As Byte
        Static Dim tempBuf(2) As Byte
        Static Dim asciBuf As New List(Of String)

        Dim byteCount As Integer = 0

        Static Dim parseState As ParseState_MC = ParseState_MC.IDLE

        points.Clear()
        pointsArray.Clear()
        byteCount = SerialPort1.BytesToRead

        While byteCount > 0
            Select Case parseState
                Case ParseState_MC.IDLE
                    pktSize = 0
                    tempByte = SerialPort1.ReadByte()
                    byteCount -= 1
                    '171 = hex AB
                    If tempByte = &HAB Then
                        parseState = ParseState_MC.HEADER1
                    Else
                        asciBuf.Add(CChar(ChrW(tempByte)))
                        parseState = ParseState_MC.IDLE
                    End If

                Case ParseState_MC.HEADER1
                    tempByte = SerialPort1.ReadByte()
                    byteCount -= 1
                    '205 = hex CD
                    If tempByte = &HCD Then
                        parseState = ParseState_MC.HEADER2
                    Else
                        asciBuf.Add(CChar(ChrW(tempByte)))
                        parseState = ParseState_MC.IDLE
                    End If

                Case ParseState_MC.HEADER2
                    tempBuf(0) = SerialPort1.ReadByte()
                    byteCount -= 1
                    parseState = ParseState_MC.PKT_SIZE

                Case ParseState_MC.PKT_SIZE
                    tempBuf(1) = SerialPort1.ReadByte()
                    byteCount -= 1
                    parseState = ParseState_MC.PAYLOAD
                    pktSize = BitConverter.ToUInt16(tempBuf, 0)

                Case ParseState_MC.PAYLOAD
                    ''IMPORTANT : buffer size is only 1000.
                    If byteCount >= pktSize Then
                        SerialPort1.Read(pktBuf, 0, pktSize)
                        byteCount -= pktSize
                        parseState = ParseState_MC.IDLE

                        points = byteArrayToInt16(pktBuf, pktSize)
                        pointsArray.Add(points)

                        ''ToArray function: converts the ArrayList collection to Array type
                        '' CType type casting function is used here to convert the Array collection to string array
                        ''Dim arr() As String = CType(tempArray.ToArray(Type.GetType("System.String")), String())
                        'tempstr = String.Join("", CType(asciBuf.ToArray(GetType(String)), String()))
                        'textBox.AppendText(tempstr)
                        'textBox.AppendText(tempstr)
                    Else
                        'Full packet not arrived yet, try in the next iteration
                        byteCount = 0
                        parseState = ParseState_MC.IDLE
                    End If

            End Select
        End While

        'Dim text As String() = CType(asciBuf.ToArray(GetType(String)), String())
        'tempstr = String.Join("", CType(asciBuf.ToArray(GetType(String)), String()))
        'textBox.AppendText(tempstr)
        'textBox.AppendText(tempstr)
        Dim text As String = String.Join("", asciBuf)
        TerminalWindow.AppendText(text)



        Try
            If text > 0 Then
                TerminalWindow.ScrollToCaret()
            End If
        Catch

        End Try

        asciBuf.Clear()

        If pointsArray.Count > 0 Then
            Return True
        Else
            Return False
        End If

    End Function

    Private Function byteArrayToInt16(ByVal buf() As Byte, ByVal len As Integer) As ArrayList
        Dim myAL As New ArrayList()

        For i As Integer = 0 To len - 1 Step 2
            If i + 2 > len Then
                Exit For
            End If
            myAL.Add(BitConverter.ToInt16(buf, i))
        Next

        Return myAL

    End Function

    Private Sub comPortComboBox_DropDown(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles comPortComboBox.DropDown
        updateComPortList()
    End Sub

    Private Sub plotSetupBtn_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles plotSetupBtn.Click
        If plotSetup.ShowDialog() = Windows.Forms.DialogResult.OK Then

            Chart1.Series.SuspendUpdates()
            Chart1.ChartAreas(0).AxisX.Maximum = plotSetup.xAxisNumPoints
            Chart1.ChartAreas(0).AxisY.Minimum = plotSetup.yAxisMinVal
            Chart1.ChartAreas(0).AxisY.Maximum = plotSetup.yAxisMaxVal

            Chart1.Series(0).Name = plotSetup.Ch1LegendTxtBox.Text
            Chart1.Series(1).Name = plotSetup.Ch2LegendTxtBox.Text
            Chart1.Series(2).Name = plotSetup.Ch3LegendTxtBox.Text
            Chart1.Series(3).Name = plotSetup.Ch4LegendTxtBox.Text

            Chart1.Series(0).Enabled = plotSetup.Ch1EnChkBox.Checked
            Chart1.Series(1).Enabled = plotSetup.Ch2EnChkBox.Checked
            Chart1.Series(2).Enabled = plotSetup.Ch3EnChkBox.Checked
            Chart1.Series(3).Enabled = plotSetup.Ch4EnChkBox.Checked

            ' Adjust Y & X axis scale
            Chart1.ResetAutoValues()
            Chart1.Series.ResumeUpdates()
        End If
    End Sub

    Private Sub btn_EnviarPID_Click(sender As System.Object, e As System.EventArgs) Handles btn_EnviarPID.Click
        Enviar_Datos()
    End Sub


    Private Sub TxtBox_Kp_PreviewKeyDown(sender As System.Object, e As System.Windows.Forms.PreviewKeyDownEventArgs) Handles TxtBox_Kp.PreviewKeyDown
        If e.KeyValue.ToString() = 13 Then
            Enviar_Datos()
        End If
    End Sub

    Private Sub Enviar_Datos()
        If SerialPort1.IsOpen Then
            Dim number As Integer
            Try

                number = Int32.Parse(TxtBox_Kp.Text)
                number = Int32.Parse(TxtBox_Kd.Text)
                number = Int32.Parse(TxtBox_Ki.Text)
                number = Int32.Parse(TxtBox_Bias1.Text)
                number = Int32.Parse(TxtBox_Bias2.Text)
                number = Int32.Parse(TxtBox_Ts.Text)
                number = Int32.Parse(TxtBox_Qa.Text)
                number = Int32.Parse(TxtBox_Qb.Text)
                number = Int32.Parse(TxtBox_RM.Text)
                Dim TxtPID As String = "$" + TxtBox_Kp.Text + "," + TxtBox_Ki.Text + "," + TxtBox_Kd.Text + "," + TxtBox_Bias1.Text + "," + TxtBox_Bias2.Text + "," + TxtBox_Ts.Text + "," + TxtBox_Qa.Text + "," + TxtBox_Qb.Text + "," + TxtBox_RM.Text + "#"
                SerialPort1.WriteLine(TxtPID)
            Catch
                MessageBox.Show("Hay letras en los valores de los parámetros", "Error en los parámetros", MessageBoxButtons.OK, MessageBoxIcon.Error)
            End Try
            Try
                TickNumberForClearToolbar = Convert.ToInt64(TimerTickLabel.Text)
                Dim Ruta = My.Computer.FileSystem.CurrentDirectory & "\\Datos.txt"
                Dim TxtToSave As String = TxtBox_Kp.Text + vbCrLf + TxtBox_Ki.Text + vbCrLf + TxtBox_Kd.Text + vbCrLf + TxtBox_Bias1.Text + vbCrLf + TxtBox_Bias2.Text + vbCrLf + TxtBox_Ts.Text + vbCrLf + TxtBox_Qa.Text + vbCrLf + TxtBox_Qb.Text + vbCrLf + TxtBox_RM.Text
                My.Computer.FileSystem.WriteAllText(Ruta, TxtToSave, False)
                SaveDataStatus.Text = "Los datos se han guardado correctamente"
            Catch
                SaveDataStatus.Text = "Error al guardar los datos"
            End Try
        Else
            MessageBox.Show("No estas conectado a ningún dispositivo.", "Error de conexión", MessageBoxButtons.OK, MessageBoxIcon.Error)
        End If
    End Sub

    Private Sub TxtBox_Ki_PreviewKeyDown(sender As System.Object, e As System.Windows.Forms.PreviewKeyDownEventArgs) Handles TxtBox_Ki.PreviewKeyDown
        If e.KeyValue.ToString() = 13 Then
            Enviar_Datos()
        End If
    End Sub

    Private Sub TxtBox_Kd_PreviewKeyDown(sender As System.Object, e As System.Windows.Forms.PreviewKeyDownEventArgs) Handles TxtBox_Kd.PreviewKeyDown
        If e.KeyValue.ToString() = 13 Then
            Enviar_Datos()
        End If
    End Sub

    Private Sub TxtBox_Bias1_PreviewKeyDown(sender As System.Object, e As System.Windows.Forms.PreviewKeyDownEventArgs) Handles TxtBox_Bias1.PreviewKeyDown
        If e.KeyValue.ToString() = 13 Then
            Enviar_Datos()
        End If
    End Sub

    Private Sub TxtBox_Bias2_PreviewKeyDown(sender As System.Object, e As System.Windows.Forms.PreviewKeyDownEventArgs) Handles TxtBox_Bias2.PreviewKeyDown
        If e.KeyValue.ToString() = 13 Then
            Enviar_Datos()
        End If
    End Sub

    Private Sub TxtBox_Ts_PreviewKeyDown(sender As System.Object, e As System.Windows.Forms.PreviewKeyDownEventArgs) Handles TxtBox_Ts.PreviewKeyDown
        If e.KeyValue.ToString() = 13 Then
            Enviar_Datos()
        End If
    End Sub

    Private Sub TxtBox_Qa_PreviewKeyDown(sender As System.Object, e As System.Windows.Forms.PreviewKeyDownEventArgs) Handles TxtBox_Qa.PreviewKeyDown
        If e.KeyValue.ToString() = 13 Then
            Enviar_Datos()
        End If
    End Sub

    Private Sub TxtBox_Qb_PreviewKeyDown(sender As System.Object, e As System.Windows.Forms.PreviewKeyDownEventArgs) Handles TxtBox_Qb.PreviewKeyDown
        If e.KeyValue.ToString() = 13 Then
            Enviar_Datos()
        End If
    End Sub

    Private Sub TxtBox_RM_PreviewKeyDown(sender As System.Object, e As System.Windows.Forms.PreviewKeyDownEventArgs) Handles TxtBox_RM.PreviewKeyDown
        If e.KeyValue.ToString() = 13 Then
            Enviar_Datos()
        End If
    End Sub


    Private Sub LoadData_Click(sender As System.Object, e As System.EventArgs) Handles LoadData.Click
        CargarDatos()
    End Sub

    Private Sub CargarDatos()
        Try
            Dim Lectura As New IO.StreamReader(My.Computer.FileSystem.CurrentDirectory & "\\Datos.txt")
            For j As Integer = 1 To 10 Step 1
                Dim linea As String = Lectura.ReadLine()
                Select Case j
                    Case 1
                        TxtBox_Kp.Text = linea
                    Case 2
                        TxtBox_Ki.Text = linea
                    Case 3
                        TxtBox_Kd.Text = linea
                    Case 4
                        TxtBox_Bias1.Text = linea
                    Case 5
                        TxtBox_Bias2.Text = linea
                    Case 6
                        TxtBox_Ts.Text = linea
                    Case 7
                        TxtBox_Qa.Text = linea
                    Case 8
                        TxtBox_Qb.Text = linea
                    Case 9
                        TxtBox_RM.Text = linea
                End Select
            Next
            Lectura.Close()
            SaveDataStatus.Text = "Datos cargados correctamente."
        Catch
            Try
                SaveDataStatus.Text = "No se han podido cargar los datos."
            Catch
            End Try
        End Try
        Try
            TickNumberForClearToolbar = Convert.ToInt64(TimerTickLabel.Text)
        Catch
        End Try
    End Sub

    Private Sub mainForm_SizeChanged(sender As System.Object, e As System.EventArgs) Handles MyBase.SizeChanged
        Dim Movimiento As Int16 = RealSize - MyBase.Width

        TickNumberForClearToolbar = 50
        Dim sistema As System.Windows.Forms.Padding
        sistema = LoadData.Margin
        sistema.Left -= Movimiento
        LoadData.Margin = sistema
        RealSize = MyBase.Width
    End Sub
End Class

