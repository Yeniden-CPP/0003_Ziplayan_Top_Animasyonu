#include "Tuval.h"
#include <wx/dcbuffer.h>
#include <wx/graphics.h>

Tuval::Tuval(wxWindow* bu) : wxPanel(bu)
{
	x = y = 100;
	dx = 3;
	dy = 2;
	ivme = 0.2;
	zamanlayici = new wxTimer(this, wxID_ANY);

	this->SetBackgroundStyle(wxBG_STYLE_PAINT);

	this->Bind(wxEVT_PAINT, &Tuval::OnPaint, this);
	this->Bind(wxEVT_TIMER, &Tuval::SureDoldu, this);

	zamanlayici->Start(20);
}

Tuval::~Tuval()
{
	if (zamanlayici)
	{
		zamanlayici->Stop();
		delete zamanlayici;
	}
}

void Tuval::OnPaint(wxPaintEvent& olay)
{
	SetBackgroundColour(wxColor(0, 0, 0));
	wxAutoBufferedPaintDC dc(this);
	dc.Clear();

	wxGraphicsContext* gc = wxGraphicsContext::Create(dc);

	if (gc)
	{
		gc->SetPen(wxPen(wxColor(179, 21, 27)));
		gc->SetBrush(wxBrush(wxColor(237, 28, 36)));
		gc->DrawEllipse(x, y, 50, 50);

		gc->SetPen(wxPen(wxTRANSPARENT));
		gc->SetBrush(wxBrush(wxColor(255, 196, 252)));
		gc->DrawEllipse(x+11, y+10, 10, 10);

		delete gc;
	}
}

void Tuval::SureDoldu(wxTimerEvent& olay)
{
	tuvalGenisligi = this->GetSize().x;
	tuvalYuksekligi = this->GetSize().y;

	x += dx;
	y += dy;
	dy += ivme;

	if (y + 50 >= tuvalYuksekligi)
	{
		y = tuvalYuksekligi - 50;
		dy = -13;
	}

	if (x >= tuvalGenisligi)
	{
		x = 0;
	}

	this->Refresh();
}