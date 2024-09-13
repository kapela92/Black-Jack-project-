//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Buttons.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
struct rekordy
{
char imie[15];
char punkty[6];
int punkty2;
};
class TGra_Blackjack : public TForm
{
__published:	// IDE-managed Components
        TImage *stol;
        TImage *Karta_gracza1;
        TImage *Karta_comp_rew;
        TImage *Karta_comp1;
        TImage *Karta_gracza2;
        TLabel *zaw_punkt;
        TImage *Karta_gracza3;
        TImage *Karta_gracza9;
        TImage *Karta_gracza8;
        TImage *Karta_gracza7;
        TImage *Karta_gracza6;
        TImage *Karta_gracza5;
        TImage *Karta_gracza10;
        TImage *Karta_gracza4;
        TSpeedButton *Pas;
        TImage *Karta_comp2;
        TImage *Karta_comp6;
        TImage *Karta_comp3;
        TImage *Karta_comp7;
        TImage *Karta_comp4;
        TImage *Karta_comp8;
        TImage *Karta_comp5;
        TImage *Karta_comp10;
        TImage *Karta_comp9;
        TLabel *comp_punkt;
        TImage *Karta_rew_ruch;
        TTimer *Timer1;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton4;
        TSpeedButton *zakoncz_gre;
        TStaticText *polenazwagracza;
        TStaticText *polestawka;
        TStaticText *polekonto;
        TSpeedButton *Dobierz_karte;
        void __fastcall Dobierz_karteClick(TObject *Sender);
        void __fastcall PasClick(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall SpeedButton3Click(TObject *Sender);
        void __fastcall SpeedButton4Click(TObject *Sender);
        void __fastcall zakoncz_greClick(TObject *Sender);
private:	// User declarations
	void Gra();
	void Karty_off();
	void Karta_dla_zaw();
	void Karta_dla_comp();
public:		// User declarations
        __fastcall TGra_Blackjack(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGra_Blackjack *Gra_Blackjack;
//---------------------------------------------------------------------------
#endif
