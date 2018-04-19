//---------------------------------------------------------------------------

#ifndef optionH
#define optionH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.TreeView.hpp>
#include <FMX.Types.hpp>
#include "main.h"
#include "setting.h"
//---------------------------------------------------------------------------
class TfmOption : public TForm
{
__published:	// IDE-managed Components
	TTabControl *TabControl1;
	TTabItem *TabItem1;
	TTabItem *TabItem2;
	TTabItem *TabItem3;
	TPanel *Panel1;
	TGroupBox *gbSutraFormat;
	TCheckBox *cbShowLineFormat;
	TCheckBox *cbShowLineHead;
	TCheckBox *cbShowPunc;
	TCheckBox *cbNoShowLgPunc;
	TCheckBox *cbVerticalMode;
	TButton *btOK;
	TButton *btCancel;
	TGroupBox *gbCollationType;
	TGroupBox *GroupBox1;
	TCheckBox *cbGaijiUseUniExt;
	TCheckBox *cbGaijiUseNormal;
	TGroupBox *GroupBox2;
	TRadioButton *rbGaijiUniExtFirst;
	TRadioButton *rbGaijiNormalFirst;
	TGroupBox *GroupBox3;
	TRadioButton *rbGaijiDesFirst;
	TRadioButton *rbGaijiImageFirst;
	TButton *btSave;
	TGroupBox *GroupBox4;
	TCheckBox *cbShowCollation;
	TRadioButton *rbCBETACollation;
	TRadioButton *rbOrigCollation;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btOKClick(TObject *Sender);
	void __fastcall btCancelClick(TObject *Sender);
	void __fastcall btSaveClick(TObject *Sender);
	void __fastcall cbShowPuncChange(TObject *Sender);
private:	// User declarations
public:		// User declarations

	CSetting * Setting; // �]�w��

	void __fastcall LoadFromSetting();  // �ѳ]�w���J
	void __fastcall SaveToSetting();  	// �ѳ]�w���J

	__fastcall TfmOption(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmOption *fmOption;
//---------------------------------------------------------------------------
#endif