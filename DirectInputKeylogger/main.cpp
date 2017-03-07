#include "stdafx.h"
#include "dxlog.h"
 
#pragma comment(lib, "dinput8")
#pragma comment(lib, "dxguid")
 
LPDIRECTINPUT8 din;
LPDIRECTINPUTDEVICE8 dinkbd;
BYTE keystate[256];
DIDATAFORMAT dfi;
 
void init_dinput(HINSTANCE hInst, HWND hWnd)
{
	HRESULT hr;
	hr = DirectInput8Create(hInst, DIRECTINPUT_VERSION, IID_IDirectInput8, (void **)&din, NULL);
	hr = din->CreateDevice(GUID_SysKeyboard, &dinkbd, NULL);
	hr = dinkbd->SetDataFormat(&c_dfDIKeyboard);
	// share the keybdb and collect even when not the active application
	hr = dinkbd->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);
}
 
void detect_input(void)
{
	dinkbd->Acquire();
	dinkbd->GetDeviceState(256, keystate);
}
 
void clean_dinput(void)
{
	dinkbd->Unacquire();
	din->Release();
}
 
void print_state()
{
	WCHAR pState[4096] = L"";
	WCHAR temp[32];
 
	for (int i = 0; i < 256; i++)
	{
		if (keystate[i] != 0)
		{
			wsprintf (temp, L"%d(%d) ", i, keystate[i]);
			lstrcat(pState, temp);
		}
	}
	if (lstrlen(pState) != 0)
	{
		lstrcat(pState, L"\n");
		OutputDebugString(pState);
	}
}
