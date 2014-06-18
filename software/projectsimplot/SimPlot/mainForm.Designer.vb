<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class mainForm
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
        Me.components = New System.ComponentModel.Container()
        Dim ChartArea1 As System.Windows.Forms.DataVisualization.Charting.ChartArea = New System.Windows.Forms.DataVisualization.Charting.ChartArea()
        Dim Legend1 As System.Windows.Forms.DataVisualization.Charting.Legend = New System.Windows.Forms.DataVisualization.Charting.Legend()
        Dim Series1 As System.Windows.Forms.DataVisualization.Charting.Series = New System.Windows.Forms.DataVisualization.Charting.Series()
        Dim Series2 As System.Windows.Forms.DataVisualization.Charting.Series = New System.Windows.Forms.DataVisualization.Charting.Series()
        Dim Series3 As System.Windows.Forms.DataVisualization.Charting.Series = New System.Windows.Forms.DataVisualization.Charting.Series()
        Dim Series4 As System.Windows.Forms.DataVisualization.Charting.Series = New System.Windows.Forms.DataVisualization.Charting.Series()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(mainForm))
        Me.TableLayoutPanel1 = New System.Windows.Forms.TableLayoutPanel()
        Me.SplitContainer1 = New System.Windows.Forms.SplitContainer()
        Me.Label10 = New System.Windows.Forms.Label()
        Me.TxtBox_Filtro = New System.Windows.Forms.TextBox()
        Me.TxtBox_Qa = New System.Windows.Forms.TextBox()
        Me.TxtBox_Ts = New System.Windows.Forms.TextBox()
        Me.TxtBox_RM = New System.Windows.Forms.TextBox()
        Me.TxtBox_Qb = New System.Windows.Forms.TextBox()
        Me.TxtBox_Bias2 = New System.Windows.Forms.TextBox()
        Me.TxtBox_Ki = New System.Windows.Forms.TextBox()
        Me.TxtBox_Kp = New System.Windows.Forms.TextBox()
        Me.Label9 = New System.Windows.Forms.Label()
        Me.Label8 = New System.Windows.Forms.Label()
        Me.Label7 = New System.Windows.Forms.Label()
        Me.Label6 = New System.Windows.Forms.Label()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.TxtBox_Kd = New System.Windows.Forms.TextBox()
        Me.TxtBox_Bias1 = New System.Windows.Forms.TextBox()
        Me.Chart1 = New System.Windows.Forms.DataVisualization.Charting.Chart()
        Me.SplitContainer2 = New System.Windows.Forms.SplitContainer()
        Me.TerminalWindow = New System.Windows.Forms.RichTextBox()
        Me.textBox = New System.Windows.Forms.RichTextBox()
        Me.FlowLayoutPanel1 = New System.Windows.Forms.FlowLayoutPanel()
        Me.comPortComboBox = New System.Windows.Forms.ComboBox()
        Me.baudRateComboBox = New System.Windows.Forms.ComboBox()
        Me.connectDisconnectButton = New System.Windows.Forms.Button()
        Me.plotSetupBtn = New System.Windows.Forms.Button()
        Me.btn_EnviarPID = New System.Windows.Forms.Button()
        Me.LoadData = New System.Windows.Forms.Button()
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.StatusStrip1 = New System.Windows.Forms.StatusStrip()
        Me.ToolStripStatusLabel1 = New System.Windows.Forms.ToolStripStatusLabel()
        Me.TimerTickLabel = New System.Windows.Forms.ToolStripStatusLabel()
        Me.ToolStripStatusLabel2 = New System.Windows.Forms.ToolStripStatusLabel()
        Me.ToolStripStatusLabel_Version = New System.Windows.Forms.ToolStripStatusLabel()
        Me.SaveDataStatus = New System.Windows.Forms.ToolStripStatusLabel()
        Me.SerialPort1 = New System.IO.Ports.SerialPort(Me.components)
        Me.TableLayoutPanel1.SuspendLayout()
        CType(Me.SplitContainer1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SplitContainer1.Panel1.SuspendLayout()
        Me.SplitContainer1.Panel2.SuspendLayout()
        Me.SplitContainer1.SuspendLayout()
        CType(Me.Chart1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.SplitContainer2, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SplitContainer2.Panel1.SuspendLayout()
        Me.SplitContainer2.Panel2.SuspendLayout()
        Me.SplitContainer2.SuspendLayout()
        Me.FlowLayoutPanel1.SuspendLayout()
        Me.StatusStrip1.SuspendLayout()
        Me.SuspendLayout()
        '
        'TableLayoutPanel1
        '
        Me.TableLayoutPanel1.ColumnCount = 1
        Me.TableLayoutPanel1.ColumnStyles.Add(New System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50.0!))
        Me.TableLayoutPanel1.Controls.Add(Me.SplitContainer1, 0, 1)
        Me.TableLayoutPanel1.Controls.Add(Me.FlowLayoutPanel1, 0, 0)
        Me.TableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill
        Me.TableLayoutPanel1.Location = New System.Drawing.Point(0, 0)
        Me.TableLayoutPanel1.Name = "TableLayoutPanel1"
        Me.TableLayoutPanel1.RowCount = 3
        Me.TableLayoutPanel1.RowStyles.Add(New System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 5.128205!))
        Me.TableLayoutPanel1.RowStyles.Add(New System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 94.8718!))
        Me.TableLayoutPanel1.RowStyles.Add(New System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20.0!))
        Me.TableLayoutPanel1.RowStyles.Add(New System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20.0!))
        Me.TableLayoutPanel1.RowStyles.Add(New System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20.0!))
        Me.TableLayoutPanel1.Size = New System.Drawing.Size(1084, 662)
        Me.TableLayoutPanel1.TabIndex = 0
        '
        'SplitContainer1
        '
        Me.SplitContainer1.BackColor = System.Drawing.SystemColors.Window
        Me.SplitContainer1.Dock = System.Windows.Forms.DockStyle.Fill
        Me.SplitContainer1.Location = New System.Drawing.Point(3, 35)
        Me.SplitContainer1.Name = "SplitContainer1"
        Me.SplitContainer1.Orientation = System.Windows.Forms.Orientation.Horizontal
        '
        'SplitContainer1.Panel1
        '
        Me.SplitContainer1.Panel1.BackColor = System.Drawing.SystemColors.Window
        Me.SplitContainer1.Panel1.Controls.Add(Me.Label10)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Filtro)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Qa)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Ts)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_RM)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Qb)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Bias2)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Ki)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Kp)
        Me.SplitContainer1.Panel1.Controls.Add(Me.Label9)
        Me.SplitContainer1.Panel1.Controls.Add(Me.Label8)
        Me.SplitContainer1.Panel1.Controls.Add(Me.Label7)
        Me.SplitContainer1.Panel1.Controls.Add(Me.Label6)
        Me.SplitContainer1.Panel1.Controls.Add(Me.Label5)
        Me.SplitContainer1.Panel1.Controls.Add(Me.Label4)
        Me.SplitContainer1.Panel1.Controls.Add(Me.Label3)
        Me.SplitContainer1.Panel1.Controls.Add(Me.Label2)
        Me.SplitContainer1.Panel1.Controls.Add(Me.Label1)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Kd)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Bias1)
        Me.SplitContainer1.Panel1.Controls.Add(Me.Chart1)
        '
        'SplitContainer1.Panel2
        '
        Me.SplitContainer1.Panel2.BackColor = System.Drawing.SystemColors.Window
        Me.SplitContainer1.Panel2.Controls.Add(Me.SplitContainer2)
        Me.SplitContainer1.Size = New System.Drawing.Size(1078, 603)
        Me.SplitContainer1.SplitterDistance = 454
        Me.SplitContainer1.TabIndex = 0
        '
        'Label10
        '
        Me.Label10.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.Label10.AutoSize = True
        Me.Label10.Location = New System.Drawing.Point(979, 415)
        Me.Label10.Name = "Label10"
        Me.Label10.Size = New System.Drawing.Size(26, 13)
        Me.Label10.TabIndex = 38
        Me.Label10.Text = "filtro"
        Me.Label10.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'TxtBox_Filtro
        '
        Me.TxtBox_Filtro.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Filtro.Location = New System.Drawing.Point(1011, 415)
        Me.TxtBox_Filtro.Name = "TxtBox_Filtro"
        Me.TxtBox_Filtro.Size = New System.Drawing.Size(57, 20)
        Me.TxtBox_Filtro.TabIndex = 37
        Me.TxtBox_Filtro.Text = "1"
        Me.TxtBox_Filtro.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_Qa
        '
        Me.TxtBox_Qa.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Qa.Location = New System.Drawing.Point(1011, 316)
        Me.TxtBox_Qa.Name = "TxtBox_Qa"
        Me.TxtBox_Qa.Size = New System.Drawing.Size(57, 20)
        Me.TxtBox_Qa.TabIndex = 34
        Me.TxtBox_Qa.Text = "1"
        Me.TxtBox_Qa.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_Ts
        '
        Me.TxtBox_Ts.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Ts.Location = New System.Drawing.Point(1011, 284)
        Me.TxtBox_Ts.Name = "TxtBox_Ts"
        Me.TxtBox_Ts.Size = New System.Drawing.Size(57, 20)
        Me.TxtBox_Ts.TabIndex = 33
        Me.TxtBox_Ts.Text = "1"
        Me.TxtBox_Ts.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_RM
        '
        Me.TxtBox_RM.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_RM.Location = New System.Drawing.Point(1011, 380)
        Me.TxtBox_RM.Name = "TxtBox_RM"
        Me.TxtBox_RM.Size = New System.Drawing.Size(57, 20)
        Me.TxtBox_RM.TabIndex = 36
        Me.TxtBox_RM.Text = "1"
        Me.TxtBox_RM.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_Qb
        '
        Me.TxtBox_Qb.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Qb.Location = New System.Drawing.Point(1011, 348)
        Me.TxtBox_Qb.Name = "TxtBox_Qb"
        Me.TxtBox_Qb.Size = New System.Drawing.Size(57, 20)
        Me.TxtBox_Qb.TabIndex = 35
        Me.TxtBox_Qb.Text = "1"
        Me.TxtBox_Qb.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_Bias2
        '
        Me.TxtBox_Bias2.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Bias2.Location = New System.Drawing.Point(1011, 252)
        Me.TxtBox_Bias2.Name = "TxtBox_Bias2"
        Me.TxtBox_Bias2.Size = New System.Drawing.Size(57, 20)
        Me.TxtBox_Bias2.TabIndex = 32
        Me.TxtBox_Bias2.Text = "1"
        Me.TxtBox_Bias2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_Ki
        '
        Me.TxtBox_Ki.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Ki.Location = New System.Drawing.Point(1011, 156)
        Me.TxtBox_Ki.Name = "TxtBox_Ki"
        Me.TxtBox_Ki.Size = New System.Drawing.Size(57, 20)
        Me.TxtBox_Ki.TabIndex = 29
        Me.TxtBox_Ki.Text = "1"
        Me.TxtBox_Ki.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_Kp
        '
        Me.TxtBox_Kp.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Kp.Location = New System.Drawing.Point(1011, 124)
        Me.TxtBox_Kp.Name = "TxtBox_Kp"
        Me.TxtBox_Kp.Size = New System.Drawing.Size(57, 20)
        Me.TxtBox_Kp.TabIndex = 28
        Me.TxtBox_Kp.Text = "1"
        Me.TxtBox_Kp.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'Label9
        '
        Me.Label9.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.Label9.AutoSize = True
        Me.Label9.Location = New System.Drawing.Point(989, 191)
        Me.Label9.Name = "Label9"
        Me.Label9.Size = New System.Drawing.Size(20, 13)
        Me.Label9.TabIndex = 27
        Me.Label9.Text = "Kd"
        Me.Label9.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label8
        '
        Me.Label8.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.Label8.AutoSize = True
        Me.Label8.Location = New System.Drawing.Point(966, 223)
        Me.Label8.Name = "Label8"
        Me.Label8.Size = New System.Drawing.Size(43, 13)
        Me.Label8.TabIndex = 26
        Me.Label8.Text = "BIAS_1"
        Me.Label8.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label7
        '
        Me.Label7.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.Label7.AutoSize = True
        Me.Label7.Location = New System.Drawing.Point(989, 127)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(20, 13)
        Me.Label7.TabIndex = 25
        Me.Label7.Text = "Kp"
        Me.Label7.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'Label6
        '
        Me.Label6.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.Label6.AutoSize = True
        Me.Label6.Location = New System.Drawing.Point(993, 159)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(16, 13)
        Me.Label6.TabIndex = 24
        Me.Label6.Text = "Ki"
        Me.Label6.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label5
        '
        Me.Label5.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.Label5.AutoSize = True
        Me.Label5.Location = New System.Drawing.Point(966, 255)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(43, 13)
        Me.Label5.TabIndex = 23
        Me.Label5.Text = "BIAS_2"
        Me.Label5.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label4
        '
        Me.Label4.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(933, 351)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(76, 13)
        Me.Label4.TabIndex = 22
        Me.Label4.Text = "Q_Bias(/1000)"
        Me.Label4.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label3
        '
        Me.Label3.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(913, 383)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(96, 13)
        Me.Label3.TabIndex = 21
        Me.Label3.Text = "R_Measure(*1000)"
        Me.Label3.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label2
        '
        Me.Label2.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(954, 287)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(55, 13)
        Me.Label2.TabIndex = 20
        Me.Label2.Text = "T_Sample"
        Me.Label2.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label1
        '
        Me.Label1.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(926, 319)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(83, 13)
        Me.Label1.TabIndex = 19
        Me.Label1.Text = "Q_Angle(/1000)"
        Me.Label1.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'TxtBox_Kd
        '
        Me.TxtBox_Kd.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Kd.Location = New System.Drawing.Point(1011, 188)
        Me.TxtBox_Kd.Name = "TxtBox_Kd"
        Me.TxtBox_Kd.Size = New System.Drawing.Size(57, 20)
        Me.TxtBox_Kd.TabIndex = 30
        Me.TxtBox_Kd.Text = "1"
        Me.TxtBox_Kd.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_Bias1
        '
        Me.TxtBox_Bias1.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Bias1.Location = New System.Drawing.Point(1011, 220)
        Me.TxtBox_Bias1.Name = "TxtBox_Bias1"
        Me.TxtBox_Bias1.Size = New System.Drawing.Size(57, 20)
        Me.TxtBox_Bias1.TabIndex = 31
        Me.TxtBox_Bias1.Text = "1"
        Me.TxtBox_Bias1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'Chart1
        '
        ChartArea1.AxisX.LineColor = System.Drawing.Color.Silver
        ChartArea1.AxisX.MajorGrid.LineColor = System.Drawing.Color.Gainsboro
        ChartArea1.AxisX.MajorTickMark.LineColor = System.Drawing.Color.Gainsboro
        ChartArea1.AxisX.MinorTickMark.Enabled = True
        ChartArea1.AxisX.MinorTickMark.LineColor = System.Drawing.Color.Gainsboro
        ChartArea1.AxisY.LineColor = System.Drawing.Color.Silver
        ChartArea1.AxisY.MajorGrid.LineColor = System.Drawing.Color.Gainsboro
        ChartArea1.AxisY.MajorTickMark.LineColor = System.Drawing.Color.Gainsboro
        ChartArea1.AxisY.MinorTickMark.Enabled = True
        ChartArea1.AxisY.MinorTickMark.LineColor = System.Drawing.Color.Gainsboro
        ChartArea1.BackColor = System.Drawing.Color.Black
        ChartArea1.Name = "ChartArea1"
        Me.Chart1.ChartAreas.Add(ChartArea1)
        Me.Chart1.Dock = System.Windows.Forms.DockStyle.Fill
        Legend1.Name = "Legend1"
        Me.Chart1.Legends.Add(Legend1)
        Me.Chart1.Location = New System.Drawing.Point(0, 0)
        Me.Chart1.Name = "Chart1"
        Series1.BorderWidth = 2
        Series1.ChartArea = "ChartArea1"
        Series1.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.FastLine
        Series1.Color = System.Drawing.Color.Yellow
        Series1.Legend = "Legend1"
        Series1.Name = "Channel 1"
        Series1.ShadowColor = System.Drawing.Color.FromArgb(CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer))
        Series1.ShadowOffset = 1
        Series2.BorderWidth = 2
        Series2.ChartArea = "ChartArea1"
        Series2.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.FastLine
        Series2.Color = System.Drawing.Color.LawnGreen
        Series2.Legend = "Legend1"
        Series2.Name = "Channel 2"
        Series2.ShadowColor = System.Drawing.Color.FromArgb(CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer))
        Series2.ShadowOffset = 1
        Series3.BorderWidth = 2
        Series3.ChartArea = "ChartArea1"
        Series3.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.FastLine
        Series3.Color = System.Drawing.Color.Aqua
        Series3.Legend = "Legend1"
        Series3.Name = "Channel 3"
        Series3.ShadowColor = System.Drawing.Color.FromArgb(CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer))
        Series3.ShadowOffset = 1
        Series4.BorderWidth = 2
        Series4.ChartArea = "ChartArea1"
        Series4.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.FastLine
        Series4.Color = System.Drawing.Color.Magenta
        Series4.Legend = "Legend1"
        Series4.Name = "Channel 4"
        Series4.ShadowColor = System.Drawing.Color.FromArgb(CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer))
        Series4.ShadowOffset = 1
        Me.Chart1.Series.Add(Series1)
        Me.Chart1.Series.Add(Series2)
        Me.Chart1.Series.Add(Series3)
        Me.Chart1.Series.Add(Series4)
        Me.Chart1.Size = New System.Drawing.Size(1078, 454)
        Me.Chart1.TabIndex = 0
        Me.Chart1.Text = "1"
        '
        'SplitContainer2
        '
        Me.SplitContainer2.AccessibleDescription = "Vertical Split for Text boxes"
        Me.SplitContainer2.Dock = System.Windows.Forms.DockStyle.Fill
        Me.SplitContainer2.Location = New System.Drawing.Point(0, 0)
        Me.SplitContainer2.Name = "SplitContainer2"
        '
        'SplitContainer2.Panel1
        '
        Me.SplitContainer2.Panel1.Controls.Add(Me.TerminalWindow)
        '
        'SplitContainer2.Panel2
        '
        Me.SplitContainer2.Panel2.Controls.Add(Me.textBox)
        Me.SplitContainer2.Size = New System.Drawing.Size(1078, 145)
        Me.SplitContainer2.SplitterDistance = 738
        Me.SplitContainer2.TabIndex = 0
        '
        'TerminalWindow
        '
        Me.TerminalWindow.Dock = System.Windows.Forms.DockStyle.Fill
        Me.TerminalWindow.Font = New System.Drawing.Font("Consolas", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TerminalWindow.Location = New System.Drawing.Point(0, 0)
        Me.TerminalWindow.MaxLength = 1000000
        Me.TerminalWindow.Name = "TerminalWindow"
        Me.TerminalWindow.Size = New System.Drawing.Size(738, 145)
        Me.TerminalWindow.TabIndex = 0
        Me.TerminalWindow.Text = ""
        '
        'textBox
        '
        Me.textBox.Dock = System.Windows.Forms.DockStyle.Fill
        Me.textBox.Location = New System.Drawing.Point(0, 0)
        Me.textBox.MaxLength = 100000
        Me.textBox.Name = "textBox"
        Me.textBox.Size = New System.Drawing.Size(336, 145)
        Me.textBox.TabIndex = 0
        Me.textBox.Text = ""
        '
        'FlowLayoutPanel1
        '
        Me.FlowLayoutPanel1.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Left) _
            Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.FlowLayoutPanel1.Controls.Add(Me.comPortComboBox)
        Me.FlowLayoutPanel1.Controls.Add(Me.baudRateComboBox)
        Me.FlowLayoutPanel1.Controls.Add(Me.connectDisconnectButton)
        Me.FlowLayoutPanel1.Controls.Add(Me.plotSetupBtn)
        Me.FlowLayoutPanel1.Controls.Add(Me.btn_EnviarPID)
        Me.FlowLayoutPanel1.Controls.Add(Me.LoadData)
        Me.FlowLayoutPanel1.Location = New System.Drawing.Point(3, 3)
        Me.FlowLayoutPanel1.Name = "FlowLayoutPanel1"
        Me.FlowLayoutPanel1.Size = New System.Drawing.Size(1078, 26)
        Me.FlowLayoutPanel1.TabIndex = 1
        '
        'comPortComboBox
        '
        Me.comPortComboBox.FormattingEnabled = True
        Me.comPortComboBox.Location = New System.Drawing.Point(3, 3)
        Me.comPortComboBox.Name = "comPortComboBox"
        Me.comPortComboBox.Size = New System.Drawing.Size(99, 21)
        Me.comPortComboBox.Sorted = True
        Me.comPortComboBox.TabIndex = 12
        '
        'baudRateComboBox
        '
        Me.baudRateComboBox.FormattingEnabled = True
        Me.baudRateComboBox.Items.AddRange(New Object() {"9600", "19200", "38400", "57600", "115200", "128000", "256000"})
        Me.baudRateComboBox.Location = New System.Drawing.Point(108, 3)
        Me.baudRateComboBox.Name = "baudRateComboBox"
        Me.baudRateComboBox.Size = New System.Drawing.Size(92, 21)
        Me.baudRateComboBox.TabIndex = 13
        '
        'connectDisconnectButton
        '
        Me.connectDisconnectButton.Dock = System.Windows.Forms.DockStyle.Fill
        Me.connectDisconnectButton.Location = New System.Drawing.Point(206, 3)
        Me.connectDisconnectButton.Name = "connectDisconnectButton"
        Me.connectDisconnectButton.Size = New System.Drawing.Size(80, 21)
        Me.connectDisconnectButton.TabIndex = 14
        Me.connectDisconnectButton.Text = "Conectar"
        Me.connectDisconnectButton.UseVisualStyleBackColor = True
        '
        'plotSetupBtn
        '
        Me.plotSetupBtn.Dock = System.Windows.Forms.DockStyle.Fill
        Me.plotSetupBtn.Location = New System.Drawing.Point(292, 3)
        Me.plotSetupBtn.Name = "plotSetupBtn"
        Me.plotSetupBtn.Size = New System.Drawing.Size(87, 21)
        Me.plotSetupBtn.TabIndex = 15
        Me.plotSetupBtn.Text = "Configuración"
        Me.plotSetupBtn.UseVisualStyleBackColor = True
        '
        'btn_EnviarPID
        '
        Me.btn_EnviarPID.Dock = System.Windows.Forms.DockStyle.Fill
        Me.btn_EnviarPID.Location = New System.Drawing.Point(385, 3)
        Me.btn_EnviarPID.Name = "btn_EnviarPID"
        Me.btn_EnviarPID.Size = New System.Drawing.Size(75, 21)
        Me.btn_EnviarPID.TabIndex = 16
        Me.btn_EnviarPID.Text = "Enviar PID"
        Me.btn_EnviarPID.UseVisualStyleBackColor = True
        '
        'LoadData
        '
        Me.LoadData.AutoEllipsis = True
        Me.LoadData.Dock = System.Windows.Forms.DockStyle.Fill
        Me.LoadData.Location = New System.Drawing.Point(503, 3)
        Me.LoadData.Margin = New System.Windows.Forms.Padding(40, 3, 3, 3)
        Me.LoadData.Name = "LoadData"
        Me.LoadData.Size = New System.Drawing.Size(112, 21)
        Me.LoadData.TabIndex = 17
        Me.LoadData.Text = "Cargar Datos"
        Me.LoadData.UseVisualStyleBackColor = True
        '
        'Timer1
        '
        Me.Timer1.Interval = 50
        '
        'StatusStrip1
        '
        Me.StatusStrip1.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.ToolStripStatusLabel1, Me.TimerTickLabel, Me.ToolStripStatusLabel2, Me.ToolStripStatusLabel_Version, Me.SaveDataStatus})
        Me.StatusStrip1.Location = New System.Drawing.Point(0, 637)
        Me.StatusStrip1.Name = "StatusStrip1"
        Me.StatusStrip1.Size = New System.Drawing.Size(1084, 25)
        Me.StatusStrip1.TabIndex = 1
        Me.StatusStrip1.Text = "StatusStrip1"
        '
        'ToolStripStatusLabel1
        '
        Me.ToolStripStatusLabel1.Name = "ToolStripStatusLabel1"
        Me.ToolStripStatusLabel1.Size = New System.Drawing.Size(63, 20)
        Me.ToolStripStatusLabel1.Text = "Timer Tick"
        '
        'TimerTickLabel
        '
        Me.TimerTickLabel.AutoSize = False
        Me.TimerTickLabel.AutoToolTip = True
        Me.TimerTickLabel.Name = "TimerTickLabel"
        Me.TimerTickLabel.Size = New System.Drawing.Size(70, 20)
        Me.TimerTickLabel.ToolTipText = "If the counter is not updating then program has crashed or stuck in loop."
        '
        'ToolStripStatusLabel2
        '
        Me.ToolStripStatusLabel2.AutoSize = False
        Me.ToolStripStatusLabel2.Name = "ToolStripStatusLabel2"
        Me.ToolStripStatusLabel2.Size = New System.Drawing.Size(100, 20)
        Me.ToolStripStatusLabel2.Text = "Version"
        Me.ToolStripStatusLabel2.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'ToolStripStatusLabel_Version
        '
        Me.ToolStripStatusLabel_Version.Name = "ToolStripStatusLabel_Version"
        Me.ToolStripStatusLabel_Version.Size = New System.Drawing.Size(0, 20)
        '
        'SaveDataStatus
        '
        Me.SaveDataStatus.Margin = New System.Windows.Forms.Padding(200, 3, 0, 2)
        Me.SaveDataStatus.Name = "SaveDataStatus"
        Me.SaveDataStatus.Size = New System.Drawing.Size(0, 20)
        '
        'SerialPort1
        '
        Me.SerialPort1.PortName = "COM10"
        '
        'mainForm
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(1084, 662)
        Me.Controls.Add(Me.StatusStrip1)
        Me.Controls.Add(Me.TableLayoutPanel1)
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.MaximizeBox = False
        Me.MinimizeBox = False
        Me.MinimumSize = New System.Drawing.Size(1000, 600)
        Me.Name = "mainForm"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "QuadPablo"
        Me.TableLayoutPanel1.ResumeLayout(False)
        Me.SplitContainer1.Panel1.ResumeLayout(False)
        Me.SplitContainer1.Panel1.PerformLayout()
        Me.SplitContainer1.Panel2.ResumeLayout(False)
        CType(Me.SplitContainer1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.SplitContainer1.ResumeLayout(False)
        CType(Me.Chart1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.SplitContainer2.Panel1.ResumeLayout(False)
        Me.SplitContainer2.Panel2.ResumeLayout(False)
        CType(Me.SplitContainer2, System.ComponentModel.ISupportInitialize).EndInit()
        Me.SplitContainer2.ResumeLayout(False)
        Me.FlowLayoutPanel1.ResumeLayout(False)
        Me.StatusStrip1.ResumeLayout(False)
        Me.StatusStrip1.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents TableLayoutPanel1 As System.Windows.Forms.TableLayoutPanel
    Friend WithEvents SplitContainer1 As System.Windows.Forms.SplitContainer
    Friend WithEvents Chart1 As System.Windows.Forms.DataVisualization.Charting.Chart
    Friend WithEvents textBox As System.Windows.Forms.RichTextBox
    Friend WithEvents Timer1 As System.Windows.Forms.Timer
    Friend WithEvents StatusStrip1 As System.Windows.Forms.StatusStrip
    Friend WithEvents ToolStripStatusLabel1 As System.Windows.Forms.ToolStripStatusLabel
    Friend WithEvents TimerTickLabel As System.Windows.Forms.ToolStripStatusLabel
    Friend WithEvents FlowLayoutPanel1 As System.Windows.Forms.FlowLayoutPanel
    Friend WithEvents comPortComboBox As System.Windows.Forms.ComboBox
    Friend WithEvents baudRateComboBox As System.Windows.Forms.ComboBox
    Friend WithEvents connectDisconnectButton As System.Windows.Forms.Button
    Friend WithEvents SerialPort1 As System.IO.Ports.SerialPort
    Friend WithEvents ToolStripStatusLabel2 As System.Windows.Forms.ToolStripStatusLabel
    Friend WithEvents ToolStripStatusLabel_Version As System.Windows.Forms.ToolStripStatusLabel
    Friend WithEvents plotSetupBtn As System.Windows.Forms.Button
    Friend WithEvents SplitContainer2 As System.Windows.Forms.SplitContainer
    Friend WithEvents TerminalWindow As System.Windows.Forms.RichTextBox
    Friend WithEvents btn_EnviarPID As System.Windows.Forms.Button
    Friend WithEvents TxtBox_Kd As System.Windows.Forms.TextBox
    Friend WithEvents TxtBox_Bias1 As System.Windows.Forms.TextBox
    Friend WithEvents Label9 As System.Windows.Forms.Label
    Friend WithEvents Label8 As System.Windows.Forms.Label
    Friend WithEvents Label7 As System.Windows.Forms.Label
    Friend WithEvents Label6 As System.Windows.Forms.Label
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents TxtBox_Qa As System.Windows.Forms.TextBox
    Friend WithEvents TxtBox_Ts As System.Windows.Forms.TextBox
    Friend WithEvents TxtBox_RM As System.Windows.Forms.TextBox
    Friend WithEvents TxtBox_Qb As System.Windows.Forms.TextBox
    Friend WithEvents TxtBox_Bias2 As System.Windows.Forms.TextBox
    Friend WithEvents TxtBox_Ki As System.Windows.Forms.TextBox
    Friend WithEvents TxtBox_Kp As System.Windows.Forms.TextBox
    Friend WithEvents SaveDataStatus As System.Windows.Forms.ToolStripStatusLabel
    Friend WithEvents LoadData As System.Windows.Forms.Button
    Friend WithEvents Label10 As System.Windows.Forms.Label
    Friend WithEvents TxtBox_Filtro As System.Windows.Forms.TextBox

End Class
