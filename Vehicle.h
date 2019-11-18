// Vehicle.h 
// Created by Robin Rowe 2019-11-18
// License MIT Open Source

#ifndef Vehicle_h
#define Vehicle_h

#include <iostream>

class Vehicle
{	Vehicle(const Vehicle&) = delete;
	void operator=(const Vehicle&) = delete;

public:
	std::ostream& Print(std::ostream& os) const;
	~Vehicle()
	{}
	Vehicle()
	{}
	bool operator!() const
	{	return true;
	}
};

inline
std::ostream& operator<<(std::ostream& os,const Vehicle& vehicle)
{	return vehicle.Print(os);
}

#endif
