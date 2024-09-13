//---------------------------------------------------------------------------

#ifndef wynikiH
#define wynikiH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <IBDatabase.hpp>
//---------------------------------------------------------------------------
class TOknoWynikow : public TForm
{
__published:	// IDE-managed Components
        TMemo *zxc;
        void __fastcall Button1Click(TObject *Sender);
        
private:	// User declarations
public:		// User declarations
        __fastcall TOknoWynikow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOknoWynikow *OknoWynikow;
//---------------------------------------------------------------------------
#endif
