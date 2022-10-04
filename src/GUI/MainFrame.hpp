#ifndef MAIN_WINDOW_HPP_INCLUDED
#define MAIN_WINDOW_HPP_INCLUDED
#include <wx/wx.h>

namespace gui
{
    class MainFrame : public wxFrame
    {
    public:
        MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    private:
        void OnExit(wxCommandEvent& event);
    };
}

#endif