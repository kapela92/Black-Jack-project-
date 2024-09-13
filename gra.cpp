

#include <vcl.h>
#pragma hdrstop
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <Jpeg.hpp>
#include <fstream.h>
#include <string.h>


#include "menu.h"

#include "ustawienia.h"

#include "gra.h"




//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGra_Blackjack *Gra_Blackjack;
AnsiString karty[52][4];
bool blackjack21=0,blackjack22=0,wygrales=0,przegrales=0,remis=0;
int zawodnik1[52];
int zawodnik2[52];
int punktyzaw=0,punktycomp=0,zamiennik;
char kolory_kart[4]={'T','C','R','P'};
int liczobrot=1;
int lop=0;
int pol=0;

rekordy rekord[10];
rekordy x;
rekordy y;

//---------------------------------------------------------------------------
__fastcall TGra_Blackjack::TGra_Blackjack(TComponent* Owner)
        : TForm(Owner)
{
DoubleBuffered=true;
}
//--------------------------------------------------------------------------
void TGra_Blackjack::Gra()
{lop=1;
pol++;
Karta_comp1->Visible=true;
 Karta_comp_rew->Visible=true;
 blackjack21=0;
 blackjack22=0;
 wygrales=0;
 przegrales=0;
 remis=0;
 liczobrot=1;
 punktyzaw=0;
 punktycomp=0;
 zamiennik;
 time_t t;
 srand((unsigned)time(&t));
 int licznik=0;
 //wype³niania tablicy
 for(int a=0;a<4;a++)
 {
        for(int i=0;i<13;i++)
        {       int i2=i+1;
                zawodnik1[licznik]=666;
                zawodnik2[licznik]=666;
                karty[licznik][3]="0";
                karty[licznik][1]=kolory_kart[a];
                karty[licznik][0]=i2;
                if(i==0)
                {
                        karty[licznik][2]=11;
                }
                if(i==10)
                {
                        karty[licznik][2]=10;
                }
                if(i==11)
                {
                        karty[licznik][2]=10;
                }
                if(i==12)
                {
                        karty[licznik][2]=10;
                }
                if(i>0)
                {
                        if(i<10)
                        {
                                karty[licznik][2]=i+1;
                        }
                }
                licznik=licznik+1;
        }
 }
 //losowanie

        int losuj1;
        int losuj2;
        for(int g=0;g<2;g++)
        {
               do
                {
                        losuj1=rand()%51;
                }
                while(karty[losuj1][3]=="1");
                zawodnik1[g]=losuj1;
                karty[losuj1][3]="1";
                do
                {
                        losuj2=rand()%51;
                }
                while(karty[losuj2][3]=="1");
                zawodnik2[g]=losuj2;
                karty[losuj2][3]="1";
                losuj1=0;
                losuj2=0;
        }
 //Punkty
 for(int g=0;g<2;g++)
 {
 sscanf(karty[zawodnik1[g]][2].c_str(), "%d", &zamiennik);
 punktyzaw=punktyzaw+zamiennik;
 sscanf(karty[zawodnik2[g]][2].c_str(), "%d", &zamiennik);
 punktycomp=punktycomp+zamiennik;
 }

 zaw_punkt->Caption="Wartosc kart: "+String(punktyzaw);
 Karta_gracza1->Picture->LoadFromFile("Bitmap\\"+karty[zawodnik1[0]][0]+karty[zawodnik1[0]][1]+".bmp") ;
 Karta_gracza2->Picture->LoadFromFile("Bitmap\\"+karty[zawodnik1[1]][0]+karty[zawodnik1[1]][1]+".bmp") ;

 Karta_comp_rew->Picture->LoadFromFile("Bitmap\\rewers.bmp") ;

 Karta_comp1->Picture->LoadFromFile("Bitmap\\"+karty[zawodnik2[0]][0]+karty[zawodnik2[0]][1]+".bmp") ;

}

//---------------------------------------------------------------------------
void TGra_Blackjack::Karty_off()
{  Karta_comp1->Visible=false;
 Karta_comp2->Visible=false;
 Karta_comp3->Visible=false;
 Karta_comp4->Visible=false;
 Karta_comp5->Visible=false;
 Karta_comp6->Visible=false;
 Karta_comp7->Visible=false;
 Karta_comp8->Visible=false;
 Karta_comp9->Visible=false;
 Karta_comp10->Visible=false;
  Karta_gracza1->Visible=false;
 Karta_gracza2->Visible=false;
 Karta_gracza3->Visible=false;
 Karta_gracza4->Visible=false;
 Karta_gracza5->Visible=false;
 Karta_gracza6->Visible=false;
 Karta_gracza7->Visible=false;
 Karta_gracza8->Visible=false;
 Karta_gracza9->Visible=false;
 Karta_gracza10->Visible=false;
 comp_punkt->Visible=false;
}
//---------------------------------------------------------------------------

void TGra_Blackjack::Karta_dla_comp()
{
        int b=120;
        Karta_rew_ruch->Picture->LoadFromFile("Bitmap\\rewers.bmp") ;
        Karta_rew_ruch->Visible=true;
        Pas->Visible=false;
                Dobierz_karte->Visible=false;
                zakoncz_gre->Visible=false;
        for(int g=0;g<32;g++)
        {

                Application->ProcessMessages();
                b=b+8;
                Karta_rew_ruch->Left=b;
                Karta_rew_ruch->Top=g;
                Sleep(30);
        }
        Pas->Visible=true;
                Dobierz_karte->Visible=true;
                zakoncz_gre->Visible=true;
        Karta_rew_ruch->Visible=false;
}

//---------------------------------------------------------------------------

void TGra_Blackjack::Karta_dla_zaw()
{
        float b=120;
        Karta_rew_ruch->Picture->LoadFromFile("Bitmap\\rewers.bmp") ;
        Karta_rew_ruch->Visible=true;
        Pas->Visible=false;
        Dobierz_karte->Visible=false;
        zakoncz_gre->Visible=false;
        for(int g=0;g<376;g++)
        {
                Application->ProcessMessages();
                if(g%2==0)
                {
                        b=b+1;
                }
                Karta_rew_ruch->Left=b;
                Karta_rew_ruch->Top=g;
               
        }
        Pas->Visible=true;
                Dobierz_karte->Visible=true;
                zakoncz_gre->Visible=true;
        Karta_rew_ruch->Visible=false;
}

//---------------------------------------------------------------------------

void __fastcall TGra_Blackjack::Dobierz_karteClick(TObject *Sender)
{
if(lop==0)
{if(stawka==0)
 { ShowMessage("Nie b¹dŸ sknera");}
     if(stawka>0)
    {
     Karta_gracza1->Visible=true;
 Karta_gracza2->Visible=true;

    Dobierz_karte->Caption="Dobierz karte";
    pol=1;
 Gra();
} }

else
 {

        int losuj,miejsce=0;
        do
        {
                losuj=rand()%51;
        }
        while(karty[losuj][3]=="1");
        do
        {
                miejsce=miejsce+1;
        }
        while(zawodnik1[miejsce]!=666);
        zawodnik1[miejsce]=losuj;
          if((losuj==0)||(losuj==13)||(losuj==26)||(losuj==39))
        {
                if((punktyzaw+11)>21)
                {
                        punktyzaw=punktyzaw+1;
                }
                else
                {
                        sscanf(karty[zawodnik1[miejsce]][2].c_str(), "%d", &zamiennik);
                        punktyzaw=punktyzaw+zamiennik;
                }
        }
        else
        {
                sscanf(karty[zawodnik1[miejsce]][2].c_str(), "%d", &zamiennik);
                punktyzaw=punktyzaw+zamiennik;
        }
        Karta_dla_zaw();
        zaw_punkt->Caption="Wartosc kart: "+String(punktyzaw);

        if(liczobrot==1)
        {
         Karta_gracza3->Picture->LoadFromFile("Bitmap\\"+karty[zawodnik1[miejsce]][0]+karty[zawodnik1[miejsce]][1]+".bmp") ;
         Karta_gracza3->Visible=true;
        }
        if(liczobrot==2)
        {
         Karta_gracza4->Picture->LoadFromFile("Bitmap\\"+karty[zawodnik1[miejsce]][0]+karty[zawodnik1[miejsce]][1]+".bmp") ;
         Karta_gracza4->Visible=true;
        }
        if(liczobrot==3)
        {
         Karta_gracza5->Picture->LoadFromFile("Bitmap\\"+karty[zawodnik1[miejsce]][0]+karty[zawodnik1[miejsce]][1]+".bmp") ;
         Karta_gracza5->Visible=true;
        }
        if(liczobrot==4)
        {
         Karta_gracza6->Picture->LoadFromFile("Bitmap\\"+karty[zawodnik1[miejsce]][0]+karty[zawodnik1[miejsce]][1]+".bmp") ;
         Karta_gracza6->Visible=true;
        }
        if(liczobrot==5)
        {
         Karta_gracza7->Picture->LoadFromFile("Bitmap\\"+karty[zawodnik1[miejsce]][0]+karty[zawodnik1[miejsce]][1]+".bmp") ;
         Karta_gracza7->Visible=true;
        }
        if(liczobrot==6)
        {
         Karta_gracza8->Picture->LoadFromFile("Bitmap\\"+karty[zawodnik1[miejsce]][0]+karty[zawodnik1[miejsce]][1]+".bmp") ;
         Karta_gracza8->Visible=true;
        }
        if(liczobrot==7)
        {
         Karta_gracza9->Picture->LoadFromFile("Bitmap\\"+karty[zawodnik1[miejsce]][0]+karty[zawodnik1[miejsce]][1]+".bmp") ;
         Karta_gracza9->Visible=true;
        }
        if(liczobrot==8)
        {
         Karta_gracza10->Picture->LoadFromFile("Bitmap\\"+karty[zawodnik1[miejsce]][0]+karty[zawodnik1[miejsce]][1]+".bmp") ;
         Karta_gracza10->Visible=true;
        }
        liczobrot=liczobrot+1;
        if(punktyzaw>21)
        {
         ShowMessage("   Przegra³eœ!   ");
         stawka=0;
         przegrales=1;
         zaw_punkt->Caption=" ";
         Dobierz_karte->Caption="Rozdaj";
         lop=0;
         Karty_off();
          Karta_comp_rew->Visible=false;
        // Gra();
        }}      

}
//---------------------------------------------------------------------------







void __fastcall TGra_Blackjack::PasClick(TObject *Sender)
{
        if(lop!=0)
        {
        int liczobrot2=2;
        Karta_comp_rew->Visible=false;
        Karta_comp2->Picture->LoadFromFile("Bitmap\\"+karty[zawodnik2[1]][0]+karty[zawodnik2[1]][1]+".bmp");
        Karta_comp2->Visible=true;
        comp_punkt->Caption="Wrtosc kart krupiera: "+String(punktycomp);
        comp_punkt->Visible=true;
        //Sprawdzanie podstawowe**************************
        if(punktycomp>16)
        {
                if(punktyzaw==punktycomp)
                {
                        ShowMessage("   Remis   ");
                        remis=1;
                        konto=konto+stawka;
                        Dobierz_karte->Caption="Rozdaj";


                        stawka=0;
                        lop=0;
                        Karty_off();
                      //  Gra();
                        goto koniec;
                }
                if(karty[zawodnik2[0]][2]=="11")
                {
                        if(karty[zawodnik2[1]][2]=="11")
                        {
                                ShowMessage("    Przegra³eœ!    ");
                                blackjack22=1;
                                lop=0;
                                stawka=0;
                                zaw_punkt->Caption=" ";
                                Dobierz_karte->Caption="Rozdaj";

                                Karty_off();
                               // Gra();
                                goto koniec;
                        }
                }
                if(punktycomp>punktyzaw)
                {
                        ShowMessage("   Przegra³eœ!   ");
                        przegrales=1;
                        stawka=0;
                        zaw_punkt->Caption=" ";
                        Dobierz_karte->Caption="Rozdaj";
                        lop=0;
                        Karty_off();
                       // Gra();
                        goto koniec;
                }
        }
        if(punktyzaw==21)
        {
                ShowMessage("    Wygra³eœ!    ");
                konto=konto+2*stawka;
                stawka=0;
                 lop=0;
                 zaw_punkt->Caption=" ";
                 Dobierz_karte->Caption="Rozdaj";
                blackjack21=1;

                Karty_off();
               // Gra();
                goto koniec;
        }
        if(karty[zawodnik1[0]][2]=="11")
        {
                if(karty[zawodnik1[1]][2]=="11")
                {
                        ShowMessage("    Wygra³eœ!    ");
                        blackjack22=1;
                        konto=konto+2*stawka;
                        stawka=0;
                        zaw_punkt->Caption=" ";
                        Dobierz_karte->Caption="Rozdaj";
                        lop=0;
                        Karty_off();
                      //  Gra();
                        goto koniec;
                }
        }
        if(punktycomp==21)
        {
                ShowMessage("   Przegra³eœ!   ");
                przegrales=1;
                stawka=0;
                zaw_punkt->Caption=" ";
                Dobierz_karte->Caption="Rozdaj";
                lop=0;

                Karty_off();
               // Gra();
                goto koniec;
        }
        //losowanie dla krupiera*******************************
        while(punktycomp<18)
        {
                int los,miejsce1=0;
                do
                {
                        los=rand()%51;
                }
                while(karty[los][3]=="1");
                zawodnik2[liczobrot2]=los;
                if((los==0)||(los==13)||(los==26)||(los==39))
                {
                        if((punktycomp+11)>21)
                        {
                                punktycomp=punktycomp+1;
                        }
                        else
                        {
                                sscanf(karty[zawodnik2[liczobrot2]][2].c_str(), "%d", &zamiennik);
                                punktycomp=punktycomp+zamiennik;
                        }
                }
                else
                {
                        sscanf(karty[zawodnik2[liczobrot2]][2].c_str(), "%d", &zamiennik);
                        punktycomp=punktycomp+zamiennik;
                }
                if(liczobrot2==2)
                {
                        Karta_dla_comp();
                        Karta_comp3->Visible=true;
                        Karta_comp3->Picture->LoadFromFile("Bitmap\\"+karty[zawodnik2[2]][0]+karty[zawodnik2[2]][1]+".bmp");

                }
                if(liczobrot2==3)
                {
                        Karta_dla_comp();
                        Karta_comp4->Visible=true;
                        Karta_comp4->Picture->LoadFromFile("Bitmap\\"+karty[zawodnik2[3]][0]+karty[zawodnik2[3]][1]+".bmp");

                }
                if(liczobrot2==4)
                {
                        Karta_dla_comp();
                        Karta_comp5->Visible=true;
                        Karta_comp5->Picture->LoadFromFile("Bitmap\\"+karty[zawodnik2[4]][0]+karty[zawodnik2[4]][1]+".bmp");

                }
                if(liczobrot2==5)
                {
                        Karta_dla_comp();
                        Karta_comp6->Visible=true;
                        Karta_comp6->Picture->LoadFromFile("Bitmap\\"+karty[zawodnik2[5]][0]+karty[zawodnik2[5]][1]+".bmp");

                }
                if(liczobrot2==6)
                {
                        Karta_dla_comp();
                        Karta_comp7->Visible=true;
                        Karta_comp7->Picture->LoadFromFile("Bitmap\\"+karty[zawodnik2[6]][0]+karty[zawodnik2[6]][1]+".bmp");

                }
                if(liczobrot2==7)
                {
                        Karta_dla_comp();
                        Karta_comp8->Visible=true;
                        Karta_comp8->Picture->LoadFromFile("Bitmap\\"+karty[zawodnik2[7]][0]+karty[zawodnik2[7]][1]+".bmp");

                }
                if(liczobrot2==8)
                {
                        Karta_dla_comp();
                        Karta_comp9->Visible=true;
                        Karta_comp9->Picture->LoadFromFile("Bitmap\\"+karty[zawodnik2[8]][0]+karty[zawodnik2[8]][1]+".bmp");

                }
                if(liczobrot2==9)
                {
                        Karta_dla_comp();
                        Karta_comp10->Visible=true;
                        Karta_comp10->Picture->LoadFromFile("Bitmap\\"+karty[zawodnik2[9]][0]+karty[zawodnik2[9]][1]+".bmp");

                }
                if(liczobrot2==10)
                {
                        Karta_dla_comp();
                        Karta_comp10->Visible=true;
                        Karta_comp10->Picture->LoadFromFile("Bitmap\\"+karty[zawodnik2[10]][0]+karty[zawodnik2[10]][1]+".bmp");

                }
                liczobrot2=liczobrot2+1;
                comp_punkt->Caption="Wrtosc kart krupiera: "+String(punktycomp);
        }

        //Sprawdzanie*************************
        if(punktyzaw>punktycomp)
        {
                ShowMessage("    Wygra³eœ!    ");
                wygrales=1;
                konto=konto+2*stawka;
                stawka=0;
                lop=0;
                zaw_punkt->Caption=" ";
                Dobierz_karte->Caption="Rozdaj";

                Karty_off();
              // Gra();
                goto koniec;
        }
        if(punktycomp>punktyzaw)
        {
                if(punktycomp<=21)
                {
                        ShowMessage("   Przegra³eœ!   ");
                        przegrales=1;
                        stawka=0;
                        lop=0;
                         zaw_punkt->Caption=" ";
                         Dobierz_karte->Caption="Rozdaj";
                        Karty_off();
                     //   Gra();
                        goto koniec;
                }
                else
                {
                        ShowMessage("    Wygra³eœ!    ");
                        wygrales=1;
                        konto=konto+2*stawka;
                        stawka=0;
                        zaw_punkt->Caption=" ";
                        Dobierz_karte->Caption="Rozdaj";
                        lop=0;

                        Karty_off();
                    //    Gra();
                        goto koniec;
                }

        } koniec:
        }
        else{ ShowMessage("Nie mo¿esz pasowac bez rozdania");}
}
//---------------------------------------------------------------------------





void __fastcall TGra_Blackjack::Timer1Timer(TObject *Sender)
{
polestawka->Caption="stawka:   "+String(stawka);
polekonto->Caption="stan twojego konta:  "+String(konto);
}
//---------------------------------------------------------------------------

void __fastcall TGra_Blackjack::SpeedButton1Click(TObject *Sender)
{
if(lop==0)
{
if(konto<1) {ShowMessage("Nie masz tyle srodkow na koncie");  }

if (konto>0) {

        if(stawka<500)
        {stawka=stawka+1;
        konto=konto-1;}
        else if(stawka==500)
        {
        ShowMessage("Najwy¿sza stawka to 500$");
        } }  }
        else{ShowMessage("Licytacja zamkniêta");   }
}
//---------------------------------------------------------------------------

void __fastcall TGra_Blackjack::SpeedButton2Click(TObject *Sender)
{ if(lop==0){
if(konto<5) {ShowMessage("Nie masz tyle srodkow na koncie");  }

if (konto>4) {

if(stawka<496)
{stawka=stawka+5;
konto=konto-5;}
else if(stawka>495)
{
ShowMessage("Najwy¿sza stawka to 500$");
 }
}
}
        else{ShowMessage("Licytacja zamkniêta");   }
}
//---------------------------------------------------------------------------

void __fastcall TGra_Blackjack::SpeedButton3Click(TObject *Sender)
{  if(lop==0){
if(konto<25) {ShowMessage("Nie masz tyle srodkow na koncie");  }

if (konto>24) {
if(stawka<476)
{stawka=stawka+25;
konto=konto-25;}
else if(stawka>475)
{
ShowMessage("Najwy¿sza stawka to 500$");
 }
}
}
        else{ShowMessage("Licytacja zamkniêta");   }
}
//---------------------------------------------------------------------------

void __fastcall TGra_Blackjack::SpeedButton4Click(TObject *Sender)
{ if(lop==0){
if(konto<100) {ShowMessage("Nie masz tyle srodkow na koncie");  }

if (konto>99) {
if(stawka<401)
{stawka=stawka+100;
konto=konto-100;}
else if(stawka>400)
{
ShowMessage("Najwy¿sza stawka to 500$");
 }
}
}
        else{ShowMessage("Licytacja zamkniêta");   }
}
//---------------------------------------------------------------------------



void __fastcall TGra_Blackjack::zakoncz_greClick(TObject *Sender)
{

 switch( Application->MessageBox("Czy chcesz zakoñczy grê","Pytanie", MB_YESNO))
 {
 case 7 : {ShowMessage("  Dobry wybor   ") ;
 break;}
 case 6 :{
blad=1;

 fstream rekordy;
 rekordy.open("rekordy.txt" );
  if (!rekordy)
  {blad=2;}

  for (int i=0;i<=9;i++)
  {
  rekordy.getline(rekord[i].imie,30);
  rekordy.getline(rekord[i].punkty,7);

  rekord[i].punkty2= atoi(rekord[i].punkty); }

  rekordy.close();

   fstream nazwa("pomoc.txt",ios::in | ios::out);
  if (!nazwa)
  {blad=2;}
   nazwa.getline(x.imie,15)  ;
   nazwa.close();;




int i=0;
int pomoc=0;

x.punkty2=konto;
sprintf(x.punkty,"%d",x.punkty2)    ;



do{

    if (x.punkty2>rekord[i].punkty2)
         { for (int j=i;j<10;j++)
             { y=rekord[j];
               rekord[j]=x;
                x=y;
              }
         pomoc=2;
         }
    i++;

   }
  while(pomoc!=2);


fstream zapis("rekordy.txt",ios::in | ios::out);
  if (!zapis)
  {blad=2;}

  for (int i=0;i<=9;i++)
  {
  zapis<<rekord[i].imie;
  zapis<<"\n";
  zapis<<rekord[i].punkty;
  zapis<<"\n";
  }

   fstream hhh("rekordy1.txt",ios::trunc |ios::in | ios::out);
   if (!hhh)
   {blad=3;}
   hhh.close();

   fstream zapis1("rekordy1.txt",ios::in | ios::out);
  if (!zapis1)
  {blad=2;}

  for (int i=0;i<=9;i++)
  {
  zapis1<<rekord[i].imie;
  zapis1<<"               ";
  zapis1<<rekord[i].punkty;
  zapis1<<"\n";
  }


   konto=1000;
   stawka=0;

  Gra_Blackjack->Close();}

                     break;    }



}
//---------------------------------------------------------------------------




