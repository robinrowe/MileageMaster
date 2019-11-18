// test_Traffic.cpp 
// Created by Robin Rowe 2019-11-18
// License MIT Open Source

#include <iostream>
#include "../Traffic.h"
using namespace std;

int main(int argc,char* argv[])
{	cout << "Testing Traffic" << endl;
	Traffic traffic;
	if(!traffic)
	{	cout << "Traffic failed, operator! == true" << endl;
		return 1;
	}
	cout << traffic << endl << "Done!" << endl;
	return 0;
}
