// Traffic.h 
// Created by Robin Rowe 2019-11-18
// License MIT Open Source

#ifndef Traffic_h
#define Traffic_h

#include <iostream>

class Traffic
{	Traffic(const Traffic&) = delete;
	void operator=(const Traffic&) = delete;

public:
	std::ostream& Print(std::ostream& os) const;
	~Traffic()
	{}
	Traffic()
	{}
	bool operator!() const
	{	return true;
	}
};

inline
std::ostream& operator<<(std::ostream& os,const Traffic& traffic)
{	return traffic.Print(os);
}

#endif
