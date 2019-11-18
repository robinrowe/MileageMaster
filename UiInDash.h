// UiInDash.h 
// Created by Robin Rowe 2019-11-18
// License MIT Open Source

#ifndef UiInDash_h
#define UiInDash_h

#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>

class UiInDash
{	UiInDash(const UiInDash&) = delete;
	void operator=(const UiInDash&) = delete;

public:
	std::ostream& Print(std::ostream& os) const;
	~UiInDash()
	{}
	UiInDash()
	{	Fl_Double_Window window(220, 220, "Mileage Master");
		window.resizable(window);
		window.show();
	}
	bool operator!() const
	{	return true;
	}
};

inline
std::ostream& operator<<(std::ostream& os,const UiInDash& uiInDash)
{	return uiInDash.Print(os);
}

#endif
