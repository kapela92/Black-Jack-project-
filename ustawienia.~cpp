//---------------------------------------------------------------------------

#include <vcl.h>
#include <dir.h>
#include <dos.h>
#include <string.h>
#include <time.h>

#pragma hdrstop

#include "ustawienia.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TOknoUstawien *OknoUstawien;
void DispMode(void)
{
switch(OknoUstawien->MediaPlayer1->Mode)
{
case mpNotReady :OknoUstawien->Label2->Caption="Nie gotowy";break;
case mpStopped  :OknoUstawien->Label2->Caption="Stop";break;
case mpPlaying  :OknoUstawien->Label2->Caption="Odtwarzanie";break;
case mpRecording :OknoUstawien->Label2->Caption="Nagrywanie";break;
case mpSeeking :OknoUstawien->Label2->Caption="Wyszukiwanie";break;
case mpOpen:OknoUstawien->Label2->Caption="Otwieranie";break;
default:OknoUstawien->Label2->Caption="cisza";
}
if(OknoUstawien->MediaPlayer1->Wait) OknoUstawien->Label2->Caption=+"WAIT";
}
//---------------------------------------------------------------------------
__fastcall TOknoUstawien::TOknoUstawien(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------





void __fastcall TOknoUstawien::TrackBar1Change(TObject *Sender)
{
 waveOutSetVolume(0, (TrackBar1->Position * 65536) + TrackBar1->Position);       
}
//---------------------------------------------------------------------------


void __fastcall TOknoUstawien::Button1Click(TObject *Sender)
{
 struct ffblk ffblk;
int done;
TFileName FileName;

ListBox1->Clear();
done=findfirst("*.mp3",&ffblk,0);
while(!done)
{
FileName=ffblk.ff_name;
ListBox1->Items->Add(FileName);
done=findnext(&ffblk);
}
done=findfirst("*.wav",&ffblk,0);
while(!done)
{
FileName=ffblk.ff_name;
ListBox1->Items->Add(FileName);
done=findnext(&ffblk);
}
}

//---------------------------------------------------------------------------

void __fastcall TOknoUstawien::Button2Click(TObject *Sender)
{
Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TOknoUstawien::ListBox1Click(TObject *Sender)
{
int ItemCount,Index;
ItemCount=ListBox1->Items->Count;
if(ItemCount>0)
{
for(Index=0;Index<ItemCount; Index++)
if(ListBox1->Selected[Index])
{
StatusBar1->SimpleText=ListBox1->Items->Strings[Index];
MediaPlayer1->FileName=ListBox1->Items->Strings[Index];
MediaPlayer1->Open();
}
}
}
//---------------------------------------------------------------------------

void __fastcall TOknoUstawien::FormCreate(TObject *Sender)
{
MediaPlayer1->Notify=true;
}
//---------------------------------------------------------------------------

void __fastcall TOknoUstawien::MediaPlayer1Click(TObject *Sender,
      TMPBtnType Button, bool &DoDefault)
{
DispMode();        
}
//---------------------------------------------------------------------------

void __fastcall TOknoUstawien::MediaPlayer1Notify(TObject *Sender)
{
DispMode();        
}
//---------------------------------------------------------------------------

void __fastcall TOknoUstawien::SpeedButton1Click(TObject *Sender)
{
if(ListBox1->ItemIndex>-1)
{
MediaPlayer1->FileName=ListBox1->Items->Strings[ListBox1->ItemIndex];
MediaPlayer1->Open();
MediaPlayer1->Play();
DispMode();
};
}
//---------------------------------------------------------------------------

void __fastcall TOknoUstawien::SpeedButton2Click(TObject *Sender)
{
if(ListBox1->ItemIndex>-1)
{
MediaPlayer1->Stop();
DispMode();
};        
}
//---------------------------------------------------------------------------

