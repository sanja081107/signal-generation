object Form1: TForm1
  Left = 533
  Top = 121
  Width = 670
  Height = 547
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 32
    Top = 344
    Width = 148
    Height = 20
    Caption = #1042#1099#1073#1088#1080#1090#1077' '#1080#1085#1090#1077#1088#1074#1072#1083':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 400
    Top = 296
    Width = 55
    Height = 13
    Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090':'
  end
  object Label5: TLabel
    Left = 56
    Top = 288
    Width = 44
    Height = 13
    Caption = 'Series1 - '
  end
  object Label6: TLabel
    Left = 104
    Top = 288
    Width = 98
    Height = 13
    Caption = #1050#1091#1073#1080#1095#1077#1089#1082#1080#1081' '#1089#1087#1083#1072#1081#1085
  end
  object Label7: TLabel
    Left = 56
    Top = 304
    Width = 44
    Height = 13
    Caption = 'Series2 - '
  end
  object Label8: TLabel
    Left = 104
    Top = 304
    Width = 96
    Height = 13
    Caption = #1051#1080#1085#1077#1081#1085#1072#1103' '#1092#1091#1085#1082#1094#1080#1103
  end
  object Label9: TLabel
    Left = 216
    Top = 288
    Width = 44
    Height = 13
    Caption = 'Series3 - '
  end
  object Label10: TLabel
    Left = 264
    Top = 288
    Width = 108
    Height = 13
    Caption = #1060#1091#1085#1082#1094#1080#1103' '#1084#1080#1085#1080#1084#1091#1084#1086#1074
  end
  object Label11: TLabel
    Left = 216
    Top = 304
    Width = 44
    Height = 13
    Caption = 'Series4 - '
  end
  object Label12: TLabel
    Left = 264
    Top = 304
    Width = 115
    Height = 13
    Caption = #1060#1091#1085#1082#1094#1080#1103' '#1087#1086#1075#1088#1077#1096#1085#1086#1089#1090#1080
  end
  object Chart1: TChart
    Left = 16
    Top = 16
    Width = 449
    Height = 265
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    Title.Text.Strings = (
      'TChart')
    View3D = False
    TabOrder = 0
    object Label3: TLabel
      Left = 368
      Top = 144
      Width = 76
      Height = 13
      Caption = #1047#1085#1072#1095#1077#1085#1080#1077' '#1087#1086' Y:'
    end
    object Label4: TLabel
      Left = 368
      Top = 104
      Width = 76
      Height = 13
      Caption = #1047#1085#1072#1095#1077#1085#1080#1077' '#1087#1086' X:'
    end
    object ScaleY: TEdit
      Left = 408
      Top = 160
      Width = 41
      Height = 21
      TabOrder = 0
    end
    object ScaleX: TEdit
      Left = 408
      Top = 120
      Width = 41
      Height = 21
      TabOrder = 1
    end
    object Button8: TButton
      Left = 376
      Top = 184
      Width = 67
      Height = 25
      Caption = #1052#1072#1089#1096#1090#1072#1073
      TabOrder = 2
      OnClick = Button8Click
    end
    object ScaleXmin: TEdit
      Left = 368
      Top = 120
      Width = 41
      Height = 21
      TabOrder = 3
    end
    object ScaleYmin: TEdit
      Left = 368
      Top = 160
      Width = 41
      Height = 21
      TabOrder = 4
    end
    object Series1: TFastLineSeries
      Marks.ArrowLength = 30
      Marks.Visible = False
      SeriesColor = clRed
      LinePen.Color = clRed
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
    object Series2: TFastLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clGreen
      LinePen.Color = clGreen
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
    object Series3: TFastLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clBlack
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
    object Series4: TFastLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clBlue
      LinePen.Color = clBlue
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
  end
  object Button1: TBitBtn
    Left = 32
    Top = 448
    Width = 97
    Height = 25
    Caption = #1056#1072'c'#1089#1095#1080#1090#1072#1090#1100
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TBitBtn
    Left = 496
    Top = 16
    Width = 137
    Height = 25
    Caption = #1056#1072'c'#1089#1095#1080#1090#1072#1090#1100' '#1087#1086#1075#1088#1077#1096#1085#1086#1089#1090#1100
    TabOrder = 2
    OnClick = Button2Click
  end
  object FoEdit: TLabeledEdit
    Left = 496
    Top = 64
    Width = 121
    Height = 21
    EditLabel.Width = 12
    EditLabel.Height = 13
    EditLabel.Caption = 'Fo'
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 3
  end
  object PogrechnostEdit: TLabeledEdit
    Left = 496
    Top = 104
    Width = 121
    Height = 21
    EditLabel.Width = 68
    EditLabel.Height = 13
    EditLabel.Caption = #1055#1086#1075#1088#1077#1096#1085#1086#1089#1090#1100
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 4
  end
  object ApogrEdit: TLabeledEdit
    Left = 496
    Top = 144
    Width = 121
    Height = 21
    EditLabel.Width = 28
    EditLabel.Height = 13
    EditLabel.Caption = 'Apogr'
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 5
  end
  object WpogrEdit: TLabeledEdit
    Left = 496
    Top = 184
    Width = 121
    Height = 21
    EditLabel.Width = 32
    EditLabel.Height = 13
    EditLabel.Caption = 'Wpogr'
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 6
  end
  object VpogrEdit: TLabeledEdit
    Left = 496
    Top = 224
    Width = 121
    Height = 21
    EditLabel.Width = 28
    EditLabel.Height = 13
    EditLabel.Caption = 'Vpogr'
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 7
  end
  object RadioButton1: TRadioButton
    Left = 32
    Top = 376
    Width = 113
    Height = 17
    Caption = '0.0375...0.0425'
    TabOrder = 8
    OnClick = RadioButton1Click
  end
  object RadioButton2: TRadioButton
    Left = 136
    Top = 376
    Width = 113
    Height = 17
    Caption = '0.025...0.035'
    TabOrder = 9
    OnClick = RadioButton2Click
  end
  object RadioButton3: TRadioButton
    Left = 240
    Top = 376
    Width = 113
    Height = 17
    Caption = '0.0275...0.0325'
    TabOrder = 10
    OnClick = RadioButton3Click
  end
  object RadioButton4: TRadioButton
    Left = 32
    Top = 408
    Width = 113
    Height = 17
    Caption = '0.03...0.05'
    TabOrder = 11
    OnClick = RadioButton4Click
  end
  object RadioButton5: TRadioButton
    Left = 136
    Top = 408
    Width = 113
    Height = 17
    Caption = '0.035...0.045'
    TabOrder = 12
    OnClick = RadioButton5Click
  end
  object RadioButton6: TRadioButton
    Left = 240
    Top = 408
    Width = 113
    Height = 17
    Caption = '0.02...0.04'
    TabOrder = 13
    OnClick = RadioButton6Click
  end
  object Button3: TButton
    Left = 144
    Top = 448
    Width = 97
    Height = 25
    Caption = #1057#1073#1088#1086#1089' '#1079#1085#1072#1095#1085#1080#1081
    TabOrder = 14
    OnClick = Button3Click
  end
  object ListBox1: TListBox
    Left = 400
    Top = 320
    Width = 225
    Height = 169
    ItemHeight = 13
    TabOrder = 15
  end
  object Button4: TButton
    Left = 464
    Top = 288
    Width = 75
    Height = 25
    Caption = #1055#1086#1082#1072#1079#1072#1090#1100
    TabOrder = 16
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 256
    Top = 448
    Width = 97
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1082#1101#1096
    TabOrder = 17
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 544
    Top = 288
    Width = 75
    Height = 25
    Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 18
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 392
    Top = 248
    Width = 65
    Height = 25
    Caption = #1057#1087#1083#1072#1081#1085
    TabOrder = 19
    OnClick = Button7Click
  end
  object StaticText1: TStaticText
    Left = 32
    Top = 280
    Width = 4
    Height = 4
    TabOrder = 20
  end
  object StaticText2: TStaticText
    Left = 176
    Top = 344
    Width = 7
    Height = 17
    Caption = '.'
    TabOrder = 21
  end
end
