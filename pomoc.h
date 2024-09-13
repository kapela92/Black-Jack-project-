//---------------------------------------------------------------------------

#ifndef pomocH
#define pomocH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TOknoPomocy : public TForm
{
__published:	// IDE-managed Components
        TRichEdit *RichEdit1;
private:	// User declarations
public:		// User declarations
        __fastcall TOknoPomocy(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOknoPomocy *OknoPomocy;
//---------------------------------------------------------------------------
#endif
