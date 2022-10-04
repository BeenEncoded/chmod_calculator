#include <iostream>
#include <wx/event.h>
#include <wx/wx.h>

#include "gui/MainFrame.hpp"

class App;

class App: public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    gui::MainFrame *frame = new gui::MainFrame("Hello World", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    return true;
}