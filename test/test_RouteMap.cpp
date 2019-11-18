// test_RouteMap.cpp 
// Created by Robin Rowe 2019-11-18
// License MIT Open Source

#include <iostream>
#include "../RouteMap.h"
using namespace std;

int main(int argc,char* argv[])
{	cout << "Testing RouteMap" << endl;
	RouteMap routeMap;
	if(!routeMap)
	{	cout << "RouteMap failed, operator! == true" << endl;
		return 1;
	}
	cout << routeMap << endl << "Done!" << endl;
	return 0;
}
