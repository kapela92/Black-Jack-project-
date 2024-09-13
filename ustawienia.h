//---------------------------------------------------------------------------

#ifndef ustawieniaH
#define ustawieniaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <mmsystem.h>
#include <ComCtrls.hpp>
#include <MPlayer.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TOknoUstawien : public TForm
{
__published:	// IDE-managed Components
        TTrackBar *TrackBar1;
        TMediaPlayer *MediaPlayer1;
        TMaskEdit *Imie_gracza;
        TStaticText *glosnosc;
        TStaticText *imie_gracza2;
        TButton *Button1;
        TButton *Button2;
        TListBox *ListBox1;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TLabel *Label1;
        TLabel *Label2;
        TStatusBar *StatusBar1;
        void __fastcall TrackBar1Change(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall MediaPlayer1Click(TObject *Sender,
          TMPBtnType Button, bool &DoDefault);
        void __fastcall MediaPlayer1Notify(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TOknoUstawien(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOknoUstawien *OknoUstawien;
//---------------------------------------------------------------------------
#endif
