// RouteMap.h 
// Created by Robin Rowe 2019-11-18
// License MIT Open Source

#ifndef RouteMap_h
#define RouteMap_h

#include <iostream>

class RouteMap
{	RouteMap(const RouteMap&) = delete;
	void operator=(const RouteMap&) = delete;

public:
	std::ostream& Print(std::ostream& os) const;
	~RouteMap()
	{}
	RouteMap()
	{}
	bool operator!() const
	{	return true;
	}
};

inline
std::ostream& operator<<(std::ostream& os,const RouteMap& routeMap)
{	return routeMap.Print(os);
}

#endif
