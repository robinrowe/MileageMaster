// test_Vehicle.cpp 
// Created by Robin Rowe 2019-11-18
// License MIT Open Source

#include <iostream>
#include "../Vehicle.h"
using namespace std;

int main(int argc,char* argv[])
{	cout << "Testing Vehicle" << endl;
	Vehicle vehicle;
	if(!vehicle)
	{	cout << "Vehicle failed, operator! == true" << endl;
		return 1;
	}
	cout << vehicle << endl << "Done!" << endl;
	return 0;
}
