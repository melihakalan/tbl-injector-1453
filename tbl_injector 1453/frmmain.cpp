//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "frmmain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void inject_skillmain()
{
	//	kojd (melih)
	//	ko tbl inject
	//	yeni bir class için malloc alýyorum,
	//	eskisinin yerine yazýyorum,
	//	yeni dosyayý çözerek içerisini dolduruyorum...

	long tblbase = (long)malloc(0x24); memset((void*)tblbase,0,0x24);
	long arg1 = 0, arg2 = 0, arg3 = 0;
	DWORD dwSizeHigh = 0, dwSizeLow = 0;
	DWORD dwReaded = 0;

	asm
	{
		lea eax,&arg1
		mov ecx,tblbase
		add ecx,4
		push eax
		mov eax,0x6B8EA0
		call eax

		lea ecx,&arg2
		lea edx,&arg3
		mov eax,tblbase
		add eax,0x14
		push ecx
		push edx
		mov ecx,eax
		mov eax,0x6B69A0
		call eax

		mov eax,tblbase
		mov [eax],0x76E55C
		mov [0x93C914],eax
	}

	HANDLE	hFile = CreateFile("injectlist\\Skill_Magic_Main_us.tbl", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	dwSizeLow = GetFileSize(hFile, &dwSizeHigh);
	BYTE* pDatas = new BYTE[dwSizeLow];
	ReadFile(hFile,pDatas,dwSizeLow,&dwReaded,0);
	CloseHandle(hFile);

	asm
	{
		mov eax,&pDatas
		mov ecx,dwSizeLow
		push 0x1608
		push 0x6081
		push 0x816
		push ecx
		push eax
		mov eax,0x45A490
		call eax
		add esp,0x14
	}

	hFile = CreateFile("injectlist\\Skill_Magic_Main_us.tbl.tmp",GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	WriteFile(hFile,pDatas,dwSizeLow,&dwReaded,NULL);
	CloseHandle(hFile);
	delete [] pDatas; pDatas = NULL;

	hFile = CreateFile("injectlist\\Skill_Magic_Main_us.tbl.tmp",GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	asm
	{
		mov ecx,tblbase
		mov eax,hFile
		push eax
		mov eax,0x6C9CA0
		call eax
	}

	CloseHandle(hFile);
	DeleteFile("injectlist\\Skill_Magic_Main_us.tbl.tmp");
}

void inject_skill4()
{
	/*
  // dlg + 0x1cc + 0x28

	long tblbase = (long)malloc(0x24); memset((void*)tblbase,0,0x24);
	long arg1 = 0, arg2 = 0, arg3 = 0;
	DWORD dwSizeHigh = 0, dwSizeLow = 0;
	DWORD dwReaded = 0;

	asm
	{
		lea eax,&arg1
		mov ecx,tblbase
		add ecx,4
		push eax
		mov eax,0x6B8EA0
		call eax

		lea ecx,&arg2
		lea edx,&arg3
		mov eax,tblbase
		add eax,0x14
		push ecx
		push edx
		mov ecx,eax
		mov eax,0x618650
		call eax

		mov eax,tblbase
		mov [eax],0x76CE0C
		mov ecx,[0x93CC28]	//dlga
		mov ecx,[ecx + 0x1CC]
		mov [ecx + 0x28], eax
	}

	HANDLE	hFile = CreateFile("injectlist\\Skill_Magic_4.tbl", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	dwSizeLow = GetFileSize(hFile, &dwSizeHigh);
	BYTE* pDatas = new BYTE[dwSizeLow];
	ReadFile(hFile,pDatas,dwSizeLow,&dwReaded,0);
	CloseHandle(hFile);

	asm
	{
		mov eax,&pDatas
		mov ecx,dwSizeLow
		push 0x1608
		push 0x6081
		push 0x816
		push ecx
		push eax
		mov eax,0x45A490
		call eax
		add esp,0x14
	}

	hFile = CreateFile("injectlist\\Skill_Magic_4.tbl.tmp",GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	WriteFile(hFile,pDatas,dwSizeLow,&dwReaded,NULL);
	CloseHandle(hFile);
	delete [] pDatas; pDatas = NULL;

	hFile = CreateFile("injectlist\\Skill_Magic_4.tbl.tmp",GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	asm
	{
		mov ecx,tblbase
		mov eax,hFile
		push eax
		mov eax,0x6C9CA0
		call eax
	}

	CloseHandle(hFile);
	DeleteFile("injectlist\\Skill_Magic_4.tbl.tmp");
	*/
}

void inject_itemorg()
{
	// 0x93C8A8

	//	kojd (melih)
	//	ko tbl inject
	//	yeni bir class için malloc alýyorum,
	//	eskisinin yerine yazýyorum,
	//	yeni dosyayý çözerek içerisini dolduruyorum...

	long tblbase = (long)malloc(0x24); memset((void*)tblbase,0,0x24);
	long arg1 = 0, arg2 = 0, arg3 = 0;
	DWORD dwSizeHigh = 0, dwSizeLow = 0;
	DWORD dwReaded = 0;

	asm
	{
		lea eax,&arg1
		mov ecx,tblbase
		add ecx,4
		push eax
		mov eax,0x6B8EA0
		call eax

		lea ecx,&arg2
		lea edx,&arg3
		mov eax,tblbase
		add eax,0x14
		push ecx
		push edx
		mov ecx,eax
		mov eax,0x6B6560
		call eax

		mov eax,tblbase
		mov [eax],0x76E564
		mov [0x93C8A8],eax
	}

	HANDLE	hFile = CreateFile("injectlist\\item_org_us.tbl", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	dwSizeLow = GetFileSize(hFile, &dwSizeHigh);
	BYTE* pDatas = new BYTE[dwSizeLow];
	ReadFile(hFile,pDatas,dwSizeLow,&dwReaded,0);
	CloseHandle(hFile);

	asm
	{
		mov eax,&pDatas
		mov ecx,dwSizeLow
		push 0x1608
		push 0x6081
		push 0x816
		push ecx
		push eax
		mov eax,0x45A490
		call eax
		add esp,0x14
	}

	hFile = CreateFile("injectlist\\item_org_us.tbl.tmp",GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	WriteFile(hFile,pDatas,dwSizeLow,&dwReaded,NULL);
	CloseHandle(hFile);
	delete [] pDatas; pDatas = NULL;

	hFile = CreateFile("injectlist\\item_org_us.tbl.tmp",GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	asm
	{
		mov ecx,tblbase
		mov eax,hFile
		push eax
		mov eax,0x6C94C0
		call eax
	}

	CloseHandle(hFile);
	DeleteFile("injectlist\\item_org_us.tbl.tmp");
}
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	HMODULE hm;
	GetModuleHandleExA(0, "injector.dll", &hm);
	FreeLibraryAndExitThread(hm,1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int i = ListBox1->ItemIndex;

	if( i == -1)
		return;

	switch(i)
	{
		case 0:
		if( !FileExists("injectlist\\Skill_Magic_Main_us.tbl") )
		{
			MessageBox(this->Handle, "TBL bulunamadi!","Hata", MB_ICONEXCLAMATION);
			return;
        }
		inject_skillmain();
		break;

		case 1:
		if( !FileExists("injectlist\\item_org_us.tbl") )
		{
			MessageBox(this->Handle, "TBL bulunamadi!","Hata", MB_ICONEXCLAMATION);
			return;
        }
		inject_itemorg();
		break;
	}

	MessageBoxA(this->Handle, "TBL inject edildi.","Inject", MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if( !FileExists("injectlist\\Skill_Magic_Main_us.tbl") ||
		!FileExists("injectlist\\item_org_us.tbl") )
	{
		MessageBox(this->Handle, "TBL bulunamadi!","Hata", MB_ICONEXCLAMATION);
		return;
	}

	inject_skillmain();
	inject_itemorg();

	MessageBoxA(this->Handle, "TBL inject edildi.","Inject", MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------

