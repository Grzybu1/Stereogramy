#include "Stereograms_Frame.h"
#include <wx/wx.h>
#include <memory>


class MyApp : public wxApp {
public:

	virtual bool OnInit();
	virtual int OnExit() { return 0; }
};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	wxFrame *mainFrame = new Stereograms_Frame(NULL);

	wxInitAllImageHandlers();

	mainFrame->Show(true);
	SetTopWindow(mainFrame);
	return true;
}