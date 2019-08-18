// PlantillaCLR.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include "Form1.h"
//#include <stdlib.h>

using namespace PlantillaCLR;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Habilitar los efectos visuales de Windows XP antes de crear ningún control
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Crear la ventana principal y ejecutarla
	Application::Run(gcnew Form1());
	return 0;
}
