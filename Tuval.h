#pragma once
#include <wx/wx.h>

class Tuval : public wxPanel
{
public:
	Tuval(wxWindow*);
	~Tuval();
	void OnPaint(wxPaintEvent&);
	void SureDoldu(wxTimerEvent&);

private:
	double x, y, dx, dy, ivme;
	wxTimer* zamanlayici;
	int tuvalGenisligi, tuvalYuksekligi;
};

