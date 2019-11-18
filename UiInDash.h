// UiInDash.h 
// Created by Robin Rowe 2019-11-18
// License MIT Open Source

#ifndef UiInDash_h
#define UiInDash_h

#include <iostream>
#include <string>
#include <memory>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Progress.H>
#include <FL/Fl_Output.H>

class UiInDash
:	public Fl_Box
{	UiInDash(const UiInDash&) = delete;
	void operator=(const UiInDash&) = delete;
	std::unique_ptr<Fl_PNG_Image> background; 	
	std::unique_ptr<Fl_PNG_Image> mapImage; 
	std::unique_ptr<Fl_Progress> meter;
	std::unique_ptr<Fl_Box> mapRoute;
	float discharge;
	unsigned bestMph;
	unsigned timeToLight;
	unsigned range;
	const double delay = 0.25;
	std::string percent;
	std::unique_ptr<Fl_Output> bestMphLabel;
	std::unique_ptr<Fl_Output> timeToLightLabel;
	std::unique_ptr<Fl_Output> rangeLabel;
	void DrawBackground()
	{	const Fl_Color backgroundColor = FL_BLUE;
		color(backgroundColor);
	}
	void LoadImage()
	{	background = std::make_unique<Fl_PNG_Image>("../mustang.png");
		image(background.get()); 
		mapRoute = std::make_unique<Fl_Box>(100,100,200,200);
		mapImage = std::make_unique<Fl_PNG_Image>("../berlin.png");
	//	mapImage.resize(200,200);
		mapRoute.get()->image(mapImage.get()); 
	}
	void LoadButtons()
	{}
	void LoadLabels()
	{	bestMphLabel = std::make_unique<Fl_Output>(200,250,100,400,"bestMphLabel");
		timeToLightLabel = std::make_unique<Fl_Output>(200,250,100,40,"timeToLightLabel");
		rangeLabel = std::make_unique<Fl_Output>(200,350,100,40,"rangeLabel");
		bestMphLabel->textsize(24);
		bestMphLabel->color(FL_WHITE);
	}
	void LoadMeter()
	{//	Fl_Window *w = (Fl_Window*)this;           // access parent window
	//	w->begin();                                // add meter bar to it..
		meter = std::make_unique<Fl_Progress>(10,350,400,50);
		meter->minimum(0);                      // set meter range to be 0.0 ~ 1.0
		meter->maximum(1);
		meter->color(0x88888800);               // background color
		meter->selection_color(0x4444ff00);     // meter bar color
		meter->labelcolor(FL_WHITE);            // percent text color
	//	w->end();              
	}
	void BumpMeter()
	{	float r = (float) rand();
		r /= RAND_MAX;
		discharge = discharge/2 + r/2;
		if(r>0.5)
		{	meter->selection_color(FL_RED); 
		}
		else
		{	meter->selection_color(FL_GREEN);
		} 
        meter->value(discharge);
    }
	void BumpLabel()
	{	
#if 0
float r = (float) rand();
		r /= RAND_MAX;
		r /= 10;
		range = 200 + r;
		
        meter->value(r);
#endif
    }
	static void MeterCallback(void* userdata)
	{	UiInDash* p = (UiInDash*)userdata;
		if(!p)
		{	return;
		}
		p->BumpMeter();
		p->redraw();
		Fl::repeat_timeout(p->delay,MeterCallback,userdata);
	}
	static void LabelCallback(void* userdata)
	{	UiInDash* p = (UiInDash*)userdata;
		if(!p)
		{	return;
		}
		p->BumpLabel();
		p->redraw();
		Fl::repeat_timeout(p->delay*10,LabelCallback,userdata);
	}
public:
	std::ostream& Print(std::ostream& os) const;
	~UiInDash()
	{}
	UiInDash(int dx,int dy,const char* caption)
	:	Fl_Box(0,0,dx,dy,caption)
	,	discharge(0.5)
	,	bestMph(0)
	,	timeToLight(0)
	,	range(0)
	{	DrawBackground();
		LoadImage();
		LoadButtons();
//		LoadLabels();
		LoadMeter();

		Fl::add_timeout(delay,MeterCallback,(void*)this);	
		Fl::add_timeout(delay,LabelCallback,(void*)this);	
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
