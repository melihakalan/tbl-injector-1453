//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form.h"
#include "windows.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void acmetest(PROCESS_INFORMATION pi)
{
	ResumeThread(pi.hThread);
	BYTE r = 0;
	while(r != 0xE9)
	{
		ReadProcessMemory(pi.hProcess,(void*)0x728EDC,&r,1,0);
	}
	SuspendThread(pi.hThread);

	//BYTE ptest[] = {0x68,0x87,0xdb,0x69,0x00,0xc3};
	//WriteProcessMemory(pi.hProcess,(void*)0x69dae3,ptest,6,0);

	//MessageBoxA(Form1->Handle,"asdasd",0,0);


	Sleep(100);

	DWORD dw1 = (DWORD)GetProcAddress(GetModuleHandle("kernel32.dll"),"GetCommandLineA");
	WriteProcessMemory(pi.hProcess,(void*)0x765188,&dw1,4,0);
	BYTE p1[] = {0xff,0x15,0x88,0x51,0x76,0x0};
	WriteProcessMemory(pi.hProcess,(void*)0x728F62,p1,6,0);

	DWORD dw2 = (DWORD)GetProcAddress(GetModuleHandle("kernel32.dll"),"GetVersion");
	WriteProcessMemory(pi.hProcess,(void*)0x7651B4,&dw2,4,0);
	BYTE p2[] = {0xff,0x15,0xb4,0x51,0x76,0x0};
	WriteProcessMemory(pi.hProcess,(void*)0x728F02,p2,6,0);

	DWORD dw3 = (DWORD)GetProcAddress(GetModuleHandle("kernel32.dll"),"GetStartupInfoA");
	WriteProcessMemory(pi.hProcess,(void*)0x76518C,&dw3,4,0);
	BYTE p3[] = {0xff,0x15,0x8c,0x51,0x76,0x0};
	WriteProcessMemory(pi.hProcess,(void*)0x728f8d,p3,6,0);

	DWORD dw4 = (DWORD)GetProcAddress(GetModuleHandle("kernel32.dll"),"GetModuleHandleA");
	WriteProcessMemory(pi.hProcess,(void*)0x765278,&dw4,4,0);
	BYTE p4[] = {0xff,0x15,0x78,0x52,0x76,0x0};
	WriteProcessMemory(pi.hProcess,(void*)0x728fb0,p4,6,0);

	DWORD dw5 = (DWORD)GetProcAddress(GetModuleHandle("kernel32.dll"),"GlobalMemoryStatus");
	WriteProcessMemory(pi.hProcess,(void*)0x7650D8,&dw5,4,0);
	BYTE p5[] = {0xff,0x15,0xd8,0x50,0x76,0x0};
	WriteProcessMemory(pi.hProcess,(void*)0x6ff67b,p5,6,0);

	DWORD dw6 = (DWORD)GetProcAddress(GetModuleHandle("kernel32.dll"),"CreateMutexA");
	WriteProcessMemory(pi.hProcess,(void*)0x7650D4,&dw6,4,0);
	BYTE p6[] = {0xff,0x15,0xd4,0x50,0x76,0x0};
	BYTE pmtx[] = {0xb8,0x01,0,0,0,0xc2,0x0c,0};
	WriteProcessMemory(pi.hProcess,(void*)0x6ff6a1,p6,6,0);
	//WriteProcessMemory(pi.hProcess,(void*)dw6,pmtx,sizeof(pmtx),0);

	DWORD dw7 = (DWORD)GetProcAddress(GetModuleHandle("kernel32.dll"),"HeapCreate");
	WriteProcessMemory(pi.hProcess,(void*)0x76511C,&dw7,4,0);
	BYTE p7[] = {0xff,0x15,0x1c,0x51,0x76,0x0};
	WriteProcessMemory(pi.hProcess,(void*)0x72f394,p7,6,0);

	DWORD dw8 = (DWORD)GetProcAddress(GetModuleHandle("kernel32.dll"),"HeapDestroy");
	WriteProcessMemory(pi.hProcess,(void*)0x765120,&dw8,4,0);
	BYTE p8[] = {0xff,0x15,0x20,0x51,0x76,0x0};
	WriteProcessMemory(pi.hProcess,(void*)0x72f3d3,p8,6,0);

	DWORD dw9 = (DWORD)GetProcAddress(GetModuleHandle("kernel32.dll"),"GetModuleFileNameA");
	WriteProcessMemory(pi.hProcess,(void*)0x765244,&dw9,4,0);
	BYTE p9[] = {0xff,0x15,0x44,0x52,0x76,0x0};
	WriteProcessMemory(pi.hProcess,(void*)0x72ecf6,p9,6,0);

	DWORD dw10 = (DWORD)GetProcAddress(GetModuleHandle("kernel32.dll"),"GetCurrentDirectoryA");
	WriteProcessMemory(pi.hProcess,(void*)0x765204,&dw10,4,0);
	BYTE p10[] = {0xff,0x15,0x04,0x52,0x76,0x0};
	WriteProcessMemory(pi.hProcess,(void*)0x6ff6fe,p10,6,0);

	DWORD dw11 = (DWORD)GetProcAddress(GetModuleHandle("User32.dll"),"CreateWindowExA");
	WriteProcessMemory(pi.hProcess,(void*)0x765320,&dw11,4,0);
	BYTE p11[] = {0xff,0x15,0x20,0x53,0x76,0x0};
	WriteProcessMemory(pi.hProcess,(void*)0x6ffc83,p11,6,0);

	DWORD dw12 = (DWORD)GetProcAddress(GetModuleHandle("kernel32.dll"),"LoadLibraryA");
	WriteProcessMemory(pi.hProcess,(void*)0x7651E0,&dw12,4,0);
	BYTE p12[] = {0xff,0x15,0xe0,0x51,0x76,0x0};
	WriteProcessMemory(pi.hProcess,(void*)0x69db81,p12,6,0);
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	ZeroMemory( &pi, sizeof(pi) );

	char* cmd = " USA_KnightOnline";
	CreateProcess("KnightOnline.exe",cmd,NULL,NULL,true,NULL,NULL,GetCurrentDir().c_str(),&si,&pi);

	SuspendThread(pi.hThread);
	Sleep(100);

	//acmetest(pi);

	HMODULE hKernel32 = GetModuleHandle("kernel32.dll");
	FARPROC hLoadLibrary = GetProcAddress(hKernel32, "LoadLibraryA");

	int iMemSize = strlen("injector.dll") + 1;

	LPVOID lpVirtualMem = VirtualAllocEx(pi.hProcess, NULL, iMemSize, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if(!lpVirtualMem){
		MessageBox(0,"Hafiza acilamadi!","Hata",MB_ICONEXCLAMATION);
		TerminateProcess(pi.hProcess,0);
		return;
	}

	WriteProcessMemory(pi.hProcess,lpVirtualMem,"injector.dll",iMemSize - 1,NULL);
	HANDLE hBotThread = CreateRemoteThread(pi.hProcess,NULL,NULL,(LPTHREAD_START_ROUTINE)hLoadLibrary,lpVirtualMem,NULL,NULL);

	CloseHandle(hBotThread);
	VirtualFreeEx(pi.hProcess, lpVirtualMem, iMemSize, MEM_RELEASE);

	ResumeThread(pi.hThread);

	WaitForInputIdle(pi.hProcess,INFINITE);

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	Application->Terminate();
}
//---------------------------------------------------------------------------
