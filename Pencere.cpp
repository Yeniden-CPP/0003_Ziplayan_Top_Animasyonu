#include "Pencere.h"
#include "Tuval.h"

Pencere::Pencere()
	: wxFrame(nullptr, wxID_ANY, L"Zıplayan Top", wxDefaultPosition, wxSize(800, 600),
		wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))
{
	this->Center();
	Tuval* cizimAlani = new Tuval(this);
}
