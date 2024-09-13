object OknoPomocy: TOknoPomocy
  Left = 306
  Top = 269
  Width = 635
  Height = 288
  Caption = 'Pomoc'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    627
    254)
  PixelsPerInch = 96
  TextHeight = 13
  object RichEdit1: TRichEdit
    Left = 0
    Top = 8
    Width = 625
    Height = 233
    Anchors = [akLeft, akTop, akRight]
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Blackjack '#8211' kasynowa gra karciana, w kt'#243'rej gracz stara si'#281' '
      'pokona'#263' krupiera poprzez uzyskanie sumy jak najbli'#380'szej 21 '
      'punkt'#243'w w kartach jednak nie przekraczaj'#261'c 21. Najwy'#380'szym '
      'uk'#322'adem kart jest tzw. Blackjack, czyli as i 10 lub figura  '
      'Punktacja kart w blackjacku:  Karty 2 do 9 maj'#261' warto'#347#263' '
      'r'#243'wn'#261' warto'#347'ci karty (3 karo ma warto'#347#263' 3 itd).  10, Walet, '
      'Dama i Kr'#243'l maj'#261' warto'#347#263' r'#243'wn'#261' 10 punkt'#243'w.    As ma '
      
        'warto'#347#263' r'#243'wn'#261' 1 lub 11, w zale'#380'no'#347'ci, co jest lepsze dla gracza.' +
        ' ')
    ParentFont = False
    ReadOnly = True
    TabOrder = 0
  end
end
