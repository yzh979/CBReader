//---------------------------------------------------------------------------

#pragma hdrstop

#include "cbxmltest.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
__fastcall CCBXMLTest::CCBXMLTest(TStringList * slTitle, TStringList * slResult)
{
	Titles = slTitle;
	Results = slResult;

#ifdef _Windows
	MyFullPath = GetCurrentDir();
#else
	MyFullPath = "/Users/heavenchou/PAServer/scratch-dir/Heaven-macos1012/gui-test";
#endif

	MyFullPath += "/";

	CBXMLOption = new CCBXMLOption(); // �g��e�{�]�w��

	CBXML = new CCBXML(MyFullPath + "Bookcase/CBETA/XML/T/T01/T01n0001_001.xml", CBXMLOption);
}
//---------------------------------------------------------------------------
// �����������
void __fastcall CCBXMLTest::RunAllTest()
{
	LogTest(u"�x�s HTML", CBXMLSaveToHTML());
}
//---------------------------------------------------------------------------
// �x�s���յ��G
void __fastcall CCBXMLTest::LogTest(String sTitle, bool bResult)
{
	String s = "0";
	if(bResult) s = "1";
	Titles->Add(sTitle);
	Results->Add(s);
}
//---------------------------------------------------------------------------
bool __fastcall CCBXMLTest::CBXMLSaveToHTML()
{
	String sOutPath = MyFullPath + "Bookcase/Temp";

	if(!TDirectory::Exists(sOutPath))
	{
		TDirectory::CreateDirectory(sOutPath);
	}

	String sOUT = MyFullPath + "Bookcase/Temp/T01n0001_001.htm";

	if(TFile::Exists(sOUT))
	{
		TFile::Delete(sOUT);
	}

	CBXML->SaveToHTML(sOUT);

	if(TFile::Exists(sOUT))
		return true;
	else
		return false;
}
//---------------------------------------------------------------------------