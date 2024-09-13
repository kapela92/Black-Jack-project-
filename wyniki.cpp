//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "wyniki.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TOknoWynikow *OknoWynikow;
//---------------------------------------------------------------------------
__fastcall TOknoWynikow::TOknoWynikow(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TOknoWynikow::Button1Click(TObject *Sender)
{
zxc->Lines->LoadFromFile("rekordy.txt");
}
//---------------------------------------------------------------------------



