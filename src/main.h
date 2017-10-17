// ---------------------------------------------------------------------------

#ifndef mainH
#define mainH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Menus.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.WebBrowser.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.TreeView.hpp>

#include "setting.h"
#include "bookcase.h"
#include "series.h"
#include "navtree.h"
#include "cbxml.h"
#include <FMX.ActnList.hpp>
#include <FMX.StdActns.hpp>
#include <System.Actions.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Controls3D.hpp>
#include <FMX.Layers3D.hpp>
#include <FMX.Viewport3D.hpp>
#include <System.Math.Vectors.hpp>
// ---------------------------------------------------------------------------

class TfmMain : public TForm
{
__published: // IDE-managed Components
	TMainMenu *MainMenu1;
	TPanel *Panel1;
	TTabControl *TabControl1;
	TPanel *Panel2;
	TTabItem *TabItem1;
	TWebBrowser *WebBrowser;
	TToolBar *ToolBar1;
	TCornerButton *CornerButton1;
	TMenuItem *MenuItem3;
	TMenuItem *MenuItem4;
	TTreeView *tvNavTree;
	TSplitter *Splitter1;
	TEdit *edBookcasePath;
	TCornerButton *btSetBookcasePath;
	TCheckBox *CheckBox1;
	TCornerButton *CornerButton2;
	TCornerButton *CornerButton3;

	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall CornerButton1Click(TObject *Sender);
	void __fastcall btSetBookcasePathClick(TObject *Sender);
	void __fastcall CheckBox1Change(TObject *Sender);
	void __fastcall CornerButton2Click(TObject *Sender);
	void __fastcall CornerButton3Click(TObject *Sender);

private: // User declarations

	void __fastcall SetPermissions(); // 設定 TWebBrowser 的 IE 版本
	void __fastcall NavTreeItemClick(TObject *Sender); // NavTree Item 點二下的作用

public: // User declarations


    int SelectedBook;   // 目前選中的書, -1 表示還沒選
	String SettingFile;
	String MyFullPath;

	CSetting * Setting; // 設定檔
	CBookcase * Bookcase; // 書櫃
	CNavTree * NavTree; // 導覽文件 (暫時的, 日後會放在 Serial 物件中 ???)


	// 開啟指定的書櫃
	void __fastcall OpenBookcase(int iId);

	__fastcall TfmMain(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TfmMain *fmMain;
// ---------------------------------------------------------------------------
#endif
