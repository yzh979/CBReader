//---------------------------------------------------------------------------

#pragma hdrstop

#include "bookcase.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall CBookcase::CBookcase()		// 建構式
{
	BookcaseDir = "./Bookcase";  // 書櫃的目錄
}
//---------------------------------------------------------------------------
__fastcall CBookcase::~CBookcase(void)
{

}
