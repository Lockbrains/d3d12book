#include "d3dApp.h"
#include "MyD3DApp.h"

/// <summary>
/// The main function called in a Windows system application.
/// </summary>
/// <param name="hInstance"> The handle for the current application instance.</param>
/// <param name="prevInstance"> Always NULL after win95. Used for shared memory before. </param>
/// <param name="cmdLine"> PSTR(Pointer to String), the commandline passed to the program.</param>
/// <param name="showCmd"> Tell how to display, minimize, maximize the windows.</param>
/// <returns></returns>
/// WINAPI: the access point for Windows application GUIs
/// Windows system requires GUI to start with WinMain().
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MyD3DApp theApp(hInstance);

	if (!theApp.Initialize()) return 0;

	return theApp.Run();
}