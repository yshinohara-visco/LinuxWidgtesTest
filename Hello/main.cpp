
#include <wx/wx.h>

class myApp : public wxApp
{
public:
	bool OnInit() override
	{
		wxFrame* frame = new wxFrame(NULL, wxID_ANY, "HelloWorld");
		new wxStaticText( frame, -1, "Hello" );
		frame->Show();
		return true;
	}
};

IMPLEMENT_APP( myApp )