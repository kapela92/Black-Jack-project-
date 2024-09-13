
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("menu.cpp", Form1);
USEFORM("pomoc.cpp", OknoPomocy);
USEFORM("ustawienia.cpp", OknoUstawien);
USEFORM("wyniki.cpp", OknoWynikow);
USEFORM("gra.cpp", Gra_Blackjack);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->CreateForm(__classid(TGra_Blackjack), &Gra_Blackjack);
                 Application->CreateForm(__classid(TOknoPomocy), &OknoPomocy);
                 Application->CreateForm(__classid(TOknoUstawien), &OknoUstawien);
                 Application->CreateForm(__classid(TOknoWynikow), &OknoWynikow);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
