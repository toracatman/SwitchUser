#include <Windows.h>
#include <WtsApi32.h>

#pragma comment(lib, "wtsapi32.lib")

int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	HKEY hKey;
	DWORD dwDisposition;
	int data = 1;
	RegCreateKeyEx(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows\\CurrentVersion\\Authentication\\LogonUI\\UserSwitch", 0, NULL, REG_OPTION_NON_VOLATILE, KEY_SET_VALUE, NULL, &hKey, &dwDisposition);
	RegSetValueEx(hKey, L"Enabled", 0, REG_DWORD, (const BYTE*)&data, (DWORD)sizeof(data));
	RegCloseKey(hKey);
	WTSDisconnectSession(WTS_CURRENT_SERVER_HANDLE, WTS_CURRENT_SESSION, FALSE);

	return 0;
}