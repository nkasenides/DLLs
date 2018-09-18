#include <windows.h> 
#include <iostream>
#include <stdio.h> 
using namespace std;

typedef int(__cdecl *MYPROC)(int a);

int main(void)
{
	HINSTANCE hinstLib;
	MYPROC ProcAdd;
	BOOL fFreeResult, fRunTimeLinkSuccess = FALSE;

	// Get a handle to the DLL module.

	hinstLib = LoadLibrary(L"MathFuncsDll.dll");

	// If the handle is valid, try to get the function address.

	if (hinstLib != NULL)
	{
		ProcAdd = (MYPROC)GetProcAddress(hinstLib, "twice");

		// If the function address is valid, call the function.

		if (NULL != ProcAdd)
		{
			fRunTimeLinkSuccess = TRUE;
			int x = (ProcAdd)(5);
			cout << x << endl;
		}
		else cout << "Failed to load function" << endl;
		// Free the DLL module.

		fFreeResult = FreeLibrary(hinstLib);
	}

	// If unable to call the DLL function, use an alternative.
	if (!fRunTimeLinkSuccess)
		printf("Failed to load DLL\n");

	system("pause");
	return 0;

}