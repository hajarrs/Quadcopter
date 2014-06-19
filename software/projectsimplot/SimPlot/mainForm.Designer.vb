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
        Me.Label11 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.TxtBox_filter = New System.Windows.Forms.TextBox()
        Me.TxtBox_comp_zx = New System.Windows.Forms.TextBox()
        Me.TxtBox_Bias2_zx = New System.Windows.Forms.TextBox()
        Me.TxtBox_Ki_zx = New System.Windows.Forms.TextBox()
        Me.TxtBox_Kp_zx = New System.Windows.Forms.TextBox()
        Me.TxtBox_Kd_zx = New System.Windows.Forms.TextBox()
        Me.TxtBox_Bias1_zx = New System.Windows.Forms.TextBox()
        Me.TxtBox_Ts = New System.Windows.Forms.TextBox()
        Me.TxtBox_comp_zy = New System.Windows.Forms.TextBox()
        Me.TxtBox_Bias2_zy = New System.Windows.Forms.TextBox()
        Me.TxtBox_Ki_zy = New System.Windows.Forms.TextBox()
        Me.TxtBox_Kp_zy = New System.Windows.Forms.TextBox()
        Me.TxtBox_Kd_zy = New System.Windows.Forms.TextBox()
        Me.TxtBox_Bias1_zy = New System.Windows.Forms.TextBox()
        Me.Label10 = New System.Windows.Forms.Label()
        Me.TxtBox_comp_xy = New System.Windows.Forms.TextBox()
        Me.TxtBox_Bias2_xy = New System.Windows.Forms.TextBox()
        Me.TxtBox_Ki_xy = New System.Windows.Forms.TextBox()
        Me.TxtBox_Kp_xy = New System.Windows.Forms.TextBox()
        Me.Label9 = New System.Windows.Forms.Label()
        Me.Label8 = New System.Windows.Forms.Label()
        Me.Label7 = New System.Windows.Forms.Label()
        Me.Label6 = New System.Windows.Forms.Label()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.TxtBox_Kd_xy = New System.Windows.Forms.TextBox()
        Me.TxtBox_Bias1_xy = New System.Windows.Forms.TextBox()
        Me.Chart1 = New System.Windows.Forms.DataVisualization.Charting.Chart()
        Me.SplitContainer2 = New System.Windows.Forms.SplitContainer()
        Me.TerminalWindow = New System.Windows.Forms.RichTextBox()
        Me.textBox = New System.Windows.Forms.RichTextBox()
        Me.FlowLayoutPanel1 = New System.Windows.Forms.FlowLayoutPanel()
        Me.btn_EnviarPID_ZY = New System.Windows.Forms.Button()
        Me.btn_EnviarPID_XY = New System.Windows.Forms.Button()
        Me.btn_EnviarFILTRO = New System.Windows.Forms.Button()
        Me.connectDisconnectButton = New System.Windows.Forms.Button()
        Me.baudRateComboBox = New System.Windows.Forms.ComboBox()
        Me.comPortComboBox = New System.Windows.Forms.ComboBox()
        Me.LoadData = New System.Windows.Forms.Button()
        Me.plotSetupBtn = New System.Windows.Forms.Button()
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.StatusStrip1 = New System.Windows.Forms.StatusStrip()
        Me.ToolStripStatusLabel1 = New System.Windows.Forms.ToolStripStatusLabel()
        Me.TimerTickLabel = New System.Windows.Forms.ToolStripStatusLabel()
        Me.ToolStripStatusLabel2 = New System.Windows.Forms.ToolStripStatusLabel()
        Me.ToolStripStatusLabel_Version = New System.Windows.Forms.ToolStripStatusLabel()
        Me.SaveDataStatus = New System.Windows.Forms.ToolStripStatusLabel()
        Me.SerialPort1 = New System.IO.Ports.SerialPort(Me.components)
        Me.btn_EnviarPID_ZX = New System.Windows.Forms.Button()
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
        Me.SplitContainer1.Panel1.Controls.Add(Me.Label11)
        Me.SplitContainer1.Panel1.Controls.Add(Me.Label3)
        Me.SplitContainer1.Panel1.Controls.Add(Me.Label1)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_filter)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_comp_zx)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Bias2_zx)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Ki_zx)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Kp_zx)
        Me.SplitContainer1.Panel1.Controls.Add(Me.LoadData)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Kd_zx)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Bias1_zx)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Ts)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_comp_zy)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Bias2_zy)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Ki_zy)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Kp_zy)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Kd_zy)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Bias1_zy)
        Me.SplitContainer1.Panel1.Controls.Add(Me.Label10)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_comp_xy)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Bias2_xy)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Ki_xy)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Kp_xy)
        Me.SplitContainer1.Panel1.Controls.Add(Me.Label9)
        Me.SplitContainer1.Panel1.Controls.Add(Me.Label8)
        Me.SplitContainer1.Panel1.Controls.Add(Me.Label7)
        Me.SplitContainer1.Panel1.Controls.Add(Me.Label6)
        Me.SplitContainer1.Panel1.Controls.Add(Me.Label5)
        Me.SplitContainer1.Panel1.Controls.Add(Me.Label4)
        Me.SplitContainer1.Panel1.Controls.Add(Me.Label2)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Kd_xy)
        Me.SplitContainer1.Panel1.Controls.Add(Me.TxtBox_Bias1_xy)
        Me.SplitContainer1.Panel1.Controls.Add(Me.Chart1)
        '
        'SplitContainer1.Panel2
        '
        Me.SplitContainer1.Panel2.BackColor = System.Drawing.SystemColors.Window
        Me.SplitContainer1.Panel2.Controls.Add(Me.SplitContainer2)
        Me.SplitContainer1.Size = New System.Drawing.Size(1078, 603)
        Me.SplitContainer1.SplitterDistance = 501
        Me.SplitContainer1.TabIndex = 0
        '
        'Label11
        '
        Me.Label11.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.Label11.AutoSize = True
        Me.Label11.Location = New System.Drawing.Point(1037, 164)
        Me.Label11.Name = "Label11"
        Me.Label11.Size = New System.Drawing.Size(17, 13)
        Me.Label11.TabIndex = 57
        Me.Label11.Text = "xy"
        Me.Label11.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'Label3
        '
        Me.Label3.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(994, 164)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(17, 13)
        Me.Label3.TabIndex = 56
        Me.Label3.Text = "zy"
        Me.Label3.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'Label1
        '
        Me.Label1.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(951, 164)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(17, 13)
        Me.Label1.TabIndex = 55
        Me.Label1.Text = "zx"
        Me.Label1.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'TxtBox_filter
        '
        Me.TxtBox_filter.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_filter.BackColor = System.Drawing.Color.Aqua
        Me.TxtBox_filter.Location = New System.Drawing.Point(989, 380)
        Me.TxtBox_filter.Name = "TxtBox_filter"
        Me.TxtBox_filter.Size = New System.Drawing.Size(38, 20)
        Me.TxtBox_filter.TabIndex = 54
        Me.TxtBox_filter.Text = "1"
        Me.TxtBox_filter.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_comp_zx
        '
        Me.TxtBox_comp_zx.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_comp_zx.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(255, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.TxtBox_comp_zx.Location = New System.Drawing.Point(945, 354)
        Me.TxtBox_comp_zx.Name = "TxtBox_comp_zx"
        Me.TxtBox_comp_zx.Size = New System.Drawing.Size(38, 20)
        Me.TxtBox_comp_zx.TabIndex = 53
        Me.TxtBox_comp_zx.Text = "1"
        Me.TxtBox_comp_zx.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_Bias2_zx
        '
        Me.TxtBox_Bias2_zx.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Bias2_zx.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(255, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.TxtBox_Bias2_zx.Location = New System.Drawing.Point(945, 319)
        Me.TxtBox_Bias2_zx.Name = "TxtBox_Bias2_zx"
        Me.TxtBox_Bias2_zx.Size = New System.Drawing.Size(37, 20)
        Me.TxtBox_Bias2_zx.TabIndex = 51
        Me.TxtBox_Bias2_zx.Text = "1"
        Me.TxtBox_Bias2_zx.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_Ki_zx
        '
        Me.TxtBox_Ki_zx.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Ki_zx.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(255, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.TxtBox_Ki_zx.Location = New System.Drawing.Point(945, 223)
        Me.TxtBox_Ki_zx.Name = "TxtBox_Ki_zx"
        Me.TxtBox_Ki_zx.Size = New System.Drawing.Size(37, 20)
        Me.TxtBox_Ki_zx.TabIndex = 48
        Me.TxtBox_Ki_zx.Text = "1"
        Me.TxtBox_Ki_zx.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_Kp_zx
        '
        Me.TxtBox_Kp_zx.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Kp_zx.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(255, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.TxtBox_Kp_zx.Location = New System.Drawing.Point(945, 191)
        Me.TxtBox_Kp_zx.Name = "TxtBox_Kp_zx"
        Me.TxtBox_Kp_zx.Size = New System.Drawing.Size(37, 20)
        Me.TxtBox_Kp_zx.TabIndex = 47
        Me.TxtBox_Kp_zx.Text = "1"
        Me.TxtBox_Kp_zx.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_Kd_zx
        '
        Me.TxtBox_Kd_zx.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Kd_zx.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(255, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.TxtBox_Kd_zx.Location = New System.Drawing.Point(945, 255)
        Me.TxtBox_Kd_zx.Name = "TxtBox_Kd_zx"
        Me.TxtBox_Kd_zx.Size = New System.Drawing.Size(37, 20)
        Me.TxtBox_Kd_zx.TabIndex = 49
        Me.TxtBox_Kd_zx.Text = "1"
        Me.TxtBox_Kd_zx.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_Bias1_zx
        '
        Me.TxtBox_Bias1_zx.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Bias1_zx.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(255, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.TxtBox_Bias1_zx.Location = New System.Drawing.Point(945, 287)
        Me.TxtBox_Bias1_zx.Name = "TxtBox_Bias1_zx"
        Me.TxtBox_Bias1_zx.Size = New System.Drawing.Size(37, 20)
        Me.TxtBox_Bias1_zx.TabIndex = 50
        Me.TxtBox_Bias1_zx.Text = "1"
        Me.TxtBox_Bias1_zx.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_Ts
        '
        Me.TxtBox_Ts.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Ts.BackColor = System.Drawing.Color.Red
        Me.TxtBox_Ts.Location = New System.Drawing.Point(990, 406)
        Me.TxtBox_Ts.Name = "TxtBox_Ts"
        Me.TxtBox_Ts.Size = New System.Drawing.Size(37, 20)
        Me.TxtBox_Ts.TabIndex = 44
        Me.TxtBox_Ts.Text = "1"
        Me.TxtBox_Ts.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_comp_zy
        '
        Me.TxtBox_comp_zy.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_comp_zy.BackColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.TxtBox_comp_zy.Location = New System.Drawing.Point(989, 354)
        Me.TxtBox_comp_zy.Name = "TxtBox_comp_zy"
        Me.TxtBox_comp_zy.Size = New System.Drawing.Size(38, 20)
        Me.TxtBox_comp_zy.TabIndex = 45
        Me.TxtBox_comp_zy.Text = "1"
        Me.TxtBox_comp_zy.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_Bias2_zy
        '
        Me.TxtBox_Bias2_zy.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Bias2_zy.BackColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.TxtBox_Bias2_zy.Location = New System.Drawing.Point(988, 319)
        Me.TxtBox_Bias2_zy.Name = "TxtBox_Bias2_zy"
        Me.TxtBox_Bias2_zy.Size = New System.Drawing.Size(37, 20)
        Me.TxtBox_Bias2_zy.TabIndex = 43
        Me.TxtBox_Bias2_zy.Text = "1"
        Me.TxtBox_Bias2_zy.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_Ki_zy
        '
        Me.TxtBox_Ki_zy.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Ki_zy.BackColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.TxtBox_Ki_zy.Location = New System.Drawing.Point(988, 223)
        Me.TxtBox_Ki_zy.Name = "TxtBox_Ki_zy"
        Me.TxtBox_Ki_zy.Size = New System.Drawing.Size(37, 20)
        Me.TxtBox_Ki_zy.TabIndex = 40
        Me.TxtBox_Ki_zy.Text = "1"
        Me.TxtBox_Ki_zy.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_Kp_zy
        '
        Me.TxtBox_Kp_zy.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Kp_zy.BackColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.TxtBox_Kp_zy.Location = New System.Drawing.Point(988, 191)
        Me.TxtBox_Kp_zy.Name = "TxtBox_Kp_zy"
        Me.TxtBox_Kp_zy.Size = New System.Drawing.Size(37, 20)
        Me.TxtBox_Kp_zy.TabIndex = 39
        Me.TxtBox_Kp_zy.Text = "1"
        Me.TxtBox_Kp_zy.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_Kd_zy
        '
        Me.TxtBox_Kd_zy.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Kd_zy.BackColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.TxtBox_Kd_zy.Location = New System.Drawing.Point(988, 255)
        Me.TxtBox_Kd_zy.Name = "TxtBox_Kd_zy"
        Me.TxtBox_Kd_zy.Size = New System.Drawing.Size(37, 20)
        Me.TxtBox_Kd_zy.TabIndex = 41
        Me.TxtBox_Kd_zy.Text = "1"
        Me.TxtBox_Kd_zy.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_Bias1_zy
        '
        Me.TxtBox_Bias1_zy.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Bias1_zy.BackColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.TxtBox_Bias1_zy.Location = New System.Drawing.Point(988, 287)
        Me.TxtBox_Bias1_zy.Name = "TxtBox_Bias1_zy"
        Me.TxtBox_Bias1_zy.Size = New System.Drawing.Size(37, 20)
        Me.TxtBox_Bias1_zy.TabIndex = 42
        Me.TxtBox_Bias1_zy.Text = "1"
        Me.TxtBox_Bias1_zy.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'Label10
        '
        Me.Label10.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.Label10.AutoSize = True
        Me.Label10.Location = New System.Drawing.Point(957, 387)
        Me.Label10.Name = "Label10"
        Me.Label10.Size = New System.Drawing.Size(26, 13)
        Me.Label10.TabIndex = 38
        Me.Label10.Text = "filtro"
        Me.Label10.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'TxtBox_comp_xy
        '
        Me.TxtBox_comp_xy.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_comp_xy.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.TxtBox_comp_xy.Location = New System.Drawing.Point(1033, 354)
        Me.TxtBox_comp_xy.Name = "TxtBox_comp_xy"
        Me.TxtBox_comp_xy.Size = New System.Drawing.Size(38, 20)
        Me.TxtBox_comp_xy.TabIndex = 35
        Me.TxtBox_comp_xy.Text = "1"
        Me.TxtBox_comp_xy.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_Bias2_xy
        '
        Me.TxtBox_Bias2_xy.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Bias2_xy.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.TxtBox_Bias2_xy.Location = New System.Drawing.Point(1031, 319)
        Me.TxtBox_Bias2_xy.Name = "TxtBox_Bias2_xy"
        Me.TxtBox_Bias2_xy.Size = New System.Drawing.Size(37, 20)
        Me.TxtBox_Bias2_xy.TabIndex = 32
        Me.TxtBox_Bias2_xy.Text = "1"
        Me.TxtBox_Bias2_xy.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_Ki_xy
        '
        Me.TxtBox_Ki_xy.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Ki_xy.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.TxtBox_Ki_xy.Location = New System.Drawing.Point(1031, 223)
        Me.TxtBox_Ki_xy.Name = "TxtBox_Ki_xy"
        Me.TxtBox_Ki_xy.Size = New System.Drawing.Size(37, 20)
        Me.TxtBox_Ki_xy.TabIndex = 29
        Me.TxtBox_Ki_xy.Text = "1"
        Me.TxtBox_Ki_xy.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_Kp_xy
        '
        Me.TxtBox_Kp_xy.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Kp_xy.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.TxtBox_Kp_xy.Location = New System.Drawing.Point(1031, 191)
        Me.TxtBox_Kp_xy.Name = "TxtBox_Kp_xy"
        Me.TxtBox_Kp_xy.Size = New System.Drawing.Size(37, 20)
        Me.TxtBox_Kp_xy.TabIndex = 28
        Me.TxtBox_Kp_xy.Text = "1"
        Me.TxtBox_Kp_xy.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'Label9
        '
        Me.Label9.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.Label9.AutoSize = True
        Me.Label9.Location = New System.Drawing.Point(909, 258)
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
        Me.Label8.Location = New System.Drawing.Point(909, 290)
        Me.Label8.Name = "Label8"
        Me.Label8.Size = New System.Drawing.Size(20, 13)
        Me.Label8.TabIndex = 26
        Me.Label8.Text = "B1"
        Me.Label8.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label7
        '
        Me.Label7.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.Label7.AutoSize = True
        Me.Label7.Location = New System.Drawing.Point(905, 194)
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
        Me.Label6.Location = New System.Drawing.Point(909, 226)
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
        Me.Label5.Location = New System.Drawing.Point(909, 322)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(20, 13)
        Me.Label5.TabIndex = 23
        Me.Label5.Text = "B2"
        Me.Label5.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label4
        '
        Me.Label4.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(905, 354)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(33, 13)
        Me.Label4.TabIndex = 22
        Me.Label4.Text = "comp"
        Me.Label4.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label2
        '
        Me.Label2.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(957, 409)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(27, 13)
        Me.Label2.TabIndex = 20
        Me.Label2.Text = "T_S"
        Me.Label2.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'TxtBox_Kd_xy
        '
        Me.TxtBox_Kd_xy.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Kd_xy.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.TxtBox_Kd_xy.Location = New System.Drawing.Point(1031, 255)
        Me.TxtBox_Kd_xy.Name = "TxtBox_Kd_xy"
        Me.TxtBox_Kd_xy.Size = New System.Drawing.Size(37, 20)
        Me.TxtBox_Kd_xy.TabIndex = 30
        Me.TxtBox_Kd_xy.Text = "1"
        Me.TxtBox_Kd_xy.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TxtBox_Bias1_xy
        '
        Me.TxtBox_Bias1_xy.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.TxtBox_Bias1_xy.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.TxtBox_Bias1_xy.Location = New System.Drawing.Point(1031, 287)
        Me.TxtBox_Bias1_xy.Name = "TxtBox_Bias1_xy"
        Me.TxtBox_Bias1_xy.Size = New System.Drawing.Size(37, 20)
        Me.TxtBox_Bias1_xy.TabIndex = 31
        Me.TxtBox_Bias1_xy.Text = "1"
        Me.TxtBox_Bias1_xy.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
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
        Me.Chart1.Size = New System.Drawing.Size(1078, 501)
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
        Me.SplitContainer2.Size = New System.Drawing.Size(1078, 98)
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
        Me.TerminalWindow.Size = New System.Drawing.Size(738, 98)
        Me.TerminalWindow.TabIndex = 0
        Me.TerminalWindow.Text = ""
        '
        'textBox
        '
        Me.textBox.Dock = System.Windows.Forms.DockStyle.Fill
        Me.textBox.Location = New System.Drawing.Point(0, 0)
        Me.textBox.MaxLength = 100000
        Me.textBox.Name = "textBox"
        Me.textBox.Size = New System.Drawing.Size(336, 98)
        Me.textBox.TabIndex = 0
        Me.textBox.Text = ""
        '
        'FlowLayoutPanel1
        '
        Me.FlowLayoutPanel1.Controls.Add(Me.baudRateComboBox)
        Me.FlowLayoutPanel1.Controls.Add(Me.comPortComboBox)
        Me.FlowLayoutPanel1.Controls.Add(Me.connectDisconnectButton)
        Me.FlowLayoutPanel1.Controls.Add(Me.plotSetupBtn)
        Me.FlowLayoutPanel1.Controls.Add(Me.btn_EnviarPID_ZX)
        Me.FlowLayoutPanel1.Controls.Add(Me.btn_EnviarPID_ZY)
        Me.FlowLayoutPanel1.Controls.Add(Me.btn_EnviarPID_XY)
        Me.FlowLayoutPanel1.Controls.Add(Me.btn_EnviarFILTRO)
        Me.FlowLayoutPanel1.Location = New System.Drawing.Point(3, 3)
        Me.FlowLayoutPanel1.Name = "FlowLayoutPanel1"
        Me.FlowLayoutPanel1.Size = New System.Drawing.Size(1078, 26)
        Me.FlowLayoutPanel1.TabIndex = 1
        '
        'btn_EnviarPID_ZY
        '
        Me.btn_EnviarPID_ZY.BackColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.btn_EnviarPID_ZY.Location = New System.Drawing.Point(481, 3)
        Me.btn_EnviarPID_ZY.Name = "btn_EnviarPID_ZY"
        Me.btn_EnviarPID_ZY.Size = New System.Drawing.Size(90, 21)
        Me.btn_EnviarPID_ZY.TabIndex = 19
        Me.btn_EnviarPID_ZY.Text = "Enviar PID ZY"
        Me.btn_EnviarPID_ZY.UseVisualStyleBackColor = False
        '
        'btn_EnviarPID_XY
        '
        Me.btn_EnviarPID_XY.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.btn_EnviarPID_XY.Location = New System.Drawing.Point(577, 3)
        Me.btn_EnviarPID_XY.Name = "btn_EnviarPID_XY"
        Me.btn_EnviarPID_XY.Size = New System.Drawing.Size(85, 21)
        Me.btn_EnviarPID_XY.TabIndex = 20
        Me.btn_EnviarPID_XY.Text = "Enviar PID XY"
        Me.btn_EnviarPID_XY.UseVisualStyleBackColor = False
        '
        'btn_EnviarFILTRO
        '
        Me.btn_EnviarFILTRO.BackColor = System.Drawing.Color.FromArgb(CType(CType(128, Byte), Integer), CType(CType(255, Byte), Integer), CType(CType(128, Byte), Integer))
        Me.btn_EnviarFILTRO.Location = New System.Drawing.Point(668, 3)
        Me.btn_EnviarFILTRO.Name = "btn_EnviarFILTRO"
        Me.btn_EnviarFILTRO.Size = New System.Drawing.Size(85, 21)
        Me.btn_EnviarFILTRO.TabIndex = 21
        Me.btn_EnviarFILTRO.Text = "Enviar filtro"
        Me.btn_EnviarFILTRO.UseVisualStyleBackColor = False
        '
        'connectDisconnectButton
        '
        Me.connectDisconnectButton.Location = New System.Drawing.Point(206, 3)
        Me.connectDisconnectButton.Name = "connectDisconnectButton"
        Me.connectDisconnectButton.Size = New System.Drawing.Size(80, 21)
        Me.connectDisconnectButton.TabIndex = 14
        Me.connectDisconnectButton.Text = "Conectar"
        Me.connectDisconnectButton.UseVisualStyleBackColor = True
        '
        'baudRateComboBox
        '
        Me.baudRateComboBox.FormattingEnabled = True
        Me.baudRateComboBox.Items.AddRange(New Object() {"9600", "19200", "38400", "57600", "115200", "128000", "256000"})
        Me.baudRateComboBox.Location = New System.Drawing.Point(3, 3)
        Me.baudRateComboBox.Name = "baudRateComboBox"
        Me.baudRateComboBox.Size = New System.Drawing.Size(92, 21)
        Me.baudRateComboBox.TabIndex = 13
        '
        'comPortComboBox
        '
        Me.comPortComboBox.FormattingEnabled = True
        Me.comPortComboBox.Location = New System.Drawing.Point(101, 3)
        Me.comPortComboBox.Name = "comPortComboBox"
        Me.comPortComboBox.Size = New System.Drawing.Size(99, 21)
        Me.comPortComboBox.Sorted = True
        Me.comPortComboBox.TabIndex = 12
        '
        'LoadData
        '
        Me.LoadData.AutoEllipsis = True
        Me.LoadData.Location = New System.Drawing.Point(942, 114)
        Me.LoadData.Margin = New System.Windows.Forms.Padding(40, 3, 3, 3)
        Me.LoadData.Name = "LoadData"
        Me.LoadData.Size = New System.Drawing.Size(112, 21)
        Me.LoadData.TabIndex = 17
        Me.LoadData.Text = "Cargar Datos"
        Me.LoadData.UseVisualStyleBackColor = False
        '
        'plotSetupBtn
        '
        Me.plotSetupBtn.Location = New System.Drawing.Point(292, 3)
        Me.plotSetupBtn.Name = "plotSetupBtn"
        Me.plotSetupBtn.Size = New System.Drawing.Size(87, 21)
        Me.plotSetupBtn.TabIndex = 15
        Me.plotSetupBtn.Text = "Configuración"
        Me.plotSetupBtn.UseVisualStyleBackColor = False
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
        'btn_EnviarPID_ZX
        '
        Me.btn_EnviarPID_ZX.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(255, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.btn_EnviarPID_ZX.Dock = System.Windows.Forms.DockStyle.Fill
        Me.btn_EnviarPID_ZX.Location = New System.Drawing.Point(385, 3)
        Me.btn_EnviarPID_ZX.Name = "btn_EnviarPID_ZX"
        Me.btn_EnviarPID_ZX.Size = New System.Drawing.Size(90, 21)
        Me.btn_EnviarPID_ZX.TabIndex = 22
        Me.btn_EnviarPID_ZX.Text = "Enviar PID ZX"
        Me.btn_EnviarPID_ZX.UseVisualStyleBackColor = False
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
    Friend WithEvents TxtBox_Kd_xy As System.Windows.Forms.TextBox
    Friend WithEvents TxtBox_Bias1_xy As System.Windows.Forms.TextBox
    Friend WithEvents Label9 As System.Windows.Forms.Label
    Friend WithEvents Label8 As System.Windows.Forms.Label
    Friend WithEvents Label7 As System.Windows.Forms.Label
    Friend WithEvents Label6 As System.Windows.Forms.Label
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents TxtBox_comp_xy As System.Windows.Forms.TextBox
    Friend WithEvents TxtBox_Bias2_xy As System.Windows.Forms.TextBox
    Friend WithEvents TxtBox_Ki_xy As System.Windows.Forms.TextBox
    Friend WithEvents TxtBox_Kp_xy As System.Windows.Forms.TextBox
    Friend WithEvents SaveDataStatus As System.Windows.Forms.ToolStripStatusLabel
    Friend WithEvents LoadData As System.Windows.Forms.Button
    Friend WithEvents Label10 As System.Windows.Forms.Label
    Friend WithEvents TxtBox_Ts As System.Windows.Forms.TextBox
    Friend WithEvents TxtBox_comp_zy As System.Windows.Forms.TextBox
    Friend WithEvents TxtBox_Bias2_zy As System.Windows.Forms.TextBox
    Friend WithEvents TxtBox_Ki_zy As System.Windows.Forms.TextBox
    Friend WithEvents TxtBox_Kp_zy As System.Windows.Forms.TextBox
    Friend WithEvents TxtBox_Kd_zy As System.Windows.Forms.TextBox
    Friend WithEvents TxtBox_Bias1_zy As System.Windows.Forms.TextBox
    Friend WithEvents TxtBox_filter As System.Windows.Forms.TextBox
    Friend WithEvents TxtBox_comp_zx As System.Windows.Forms.TextBox
    Friend WithEvents TxtBox_Bias2_zx As System.Windows.Forms.TextBox
    Friend WithEvents TxtBox_Ki_zx As System.Windows.Forms.TextBox
    Friend WithEvents TxtBox_Kp_zx As System.Windows.Forms.TextBox
    Friend WithEvents TxtBox_Kd_zx As System.Windows.Forms.TextBox
    Friend WithEvents TxtBox_Bias1_zx As System.Windows.Forms.TextBox
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Label11 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents btn_EnviarPID_ZY As System.Windows.Forms.Button
    Friend WithEvents btn_EnviarPID_XY As System.Windows.Forms.Button
    Friend WithEvents btn_EnviarFILTRO As System.Windows.Forms.Button
    Friend WithEvents btn_EnviarPID_ZX As System.Windows.Forms.Button

End Class
