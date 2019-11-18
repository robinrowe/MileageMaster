// UiInDash.h 
// Created by Robin Rowe 2019-11-18
// License MIT Open Source

#ifndef UiInDash_h
#define UiInDash_h

#include <iostream>
#include <memory>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Progress.H>

class UiInDash
:	public Fl_Box
{	UiInDash(const UiInDash&) = delete;
	void operator=(const UiInDash&) = delete;
	std::unique_ptr<Fl_PNG_Image> background; 	
	std::unique_ptr<Fl_Progress> progress; 	
	void DrawBackground()
	{	const Fl_Color backgroundColor = FL_BLUE;
		color(backgroundColor);
	}
	void LoadImage()
	{	background = std::make_unique<Fl_PNG_Image>("../mustang.png");
		image(background.get());  
	}
	void LoadButtons()
	{}
	void LoadMeter()
	{//	Fl_Window *w = (Fl_Window*)this;           // access parent window
	//	w->begin();                                // add progress bar to it..
		progress = std::make_unique<Fl_Progress>(10,100,50,300);
		progress->minimum(0);                      // set progress range to be 0.0 ~ 1.0
		progress->maximum(1);
		progress->color(0x88888800);               // background color
		progress->selection_color(0x4444ff00);     // progress bar color
		progress->labelcolor(FL_WHITE);            // percent text color
	//	w->end();              
	}
public:
	std::ostream& Print(std::ostream& os) const;
	~UiInDash()
	{}
	UiInDash(int dx,int dy,const char* caption)
	:	Fl_Box(0,0,dx,dy,caption)
	{	DrawBackground();
		LoadImage();
		LoadButtons();
		LoadMeter();	
	}
	bool operator!() const
	{	return true;
	}
#if 0
	void draw() 
	{	DrawBackground();
	}
#endif
};

inline
std::ostream& operator<<(std::ostream& os,const UiInDash& uiInDash)
{	return uiInDash.Print(os);
}

#endif
