#include <iostream>
#include <windows.h>
#include "GraphicsEngine/GraphicsEngine.h"

// Implicit load.
extern "C"
{
	__declspec(dllimport) void saluda(const char*);
}

int main()
{
	/*HINSTANCE dll = LoadLibrary(L"DLL"); // Load the DLL.

	if (!dll)
	{
		std::cout << "No se ha podido cargar la DLL :(\n";
		return -1;
	}

	using fPointerSaluda = void (*)(const char*);
	fPointerSaluda saluda = (fPointerSaluda)GetProcAddress(dll, "saluda"); // Create the pointer to the function.

	if (!saluda)
	{
		std::cout << "Saluda no encontrado.\n";
		FreeLibrary(dll);
		return -1;
	}

	saluda("Mercos"); // Call the function.

	// saluda("Mercos");

 	return 0;*/

	saluda("Oablo");
}