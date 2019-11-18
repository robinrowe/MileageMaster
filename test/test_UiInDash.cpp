// test_UiInDash.cpp 
// Created by Robin Rowe 2019-11-18
// License MIT Open Source

#include <iostream>
#include "../UiInDash.h"
using namespace std;

int main(int argc,char* argv[])
{	cout << "Testing UiInDash" << endl;
	UiInDash uiInDash;
	if(!uiInDash)
	{	cout << "UiInDash failed, operator! == true" << endl;
		return 1;
	}
	cout << uiInDash << endl << "Done!" << endl;
	return 0;
}
