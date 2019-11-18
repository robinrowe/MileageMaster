// mileage_master.cpp 
// Created by Robin Rowe 2019-11-18
// License MIT Open Source

#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include "UiInDash.h"
using namespace std;

void Usage()
{	cout << "Usage: mileage_master " << endl;
}

enum
{	ok,
	invalid_args

};

int main(int argc,char* argv[])
{	cout << "mileage_master starting..." << endl;
#if 0
	if(argc < 1)
	{	Usage();
		return invalid_args;
	}
#endif
	const int dx = 400;
	const int dy = 420;
	const char* caption = "Mileage Master";
	Fl_Double_Window mainWindow(dx,dy,caption);
	UiInDash uiInDash(dx,dy,caption);
	mainWindow.resizable(mainWindow);
	mainWindow.show();
	return Fl::run();
	cout << "mileage_master done!" << endl;
	return ok;
}
