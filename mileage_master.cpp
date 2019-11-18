// mileage_master.cpp 
// Created by Robin Rowe 2019-11-18
// License MIT Open Source

#include <iostream>
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
	UiInDash uiInDash;
	return Fl::run();
	cout << "mileage_master done!" << endl;
	return ok;
}
