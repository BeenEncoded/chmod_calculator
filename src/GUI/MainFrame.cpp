#include "MainFrame.hpp"

namespace gui
{
    MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
    {
        Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
        wxMenu *menuFile = new wxMenu;
        menuFile->Append(wxID_EXIT);

        wxMenuBar *menuBar = new wxMenuBar;
        menuBar->Append(menuFile, "&File");
        SetMenuBar(menuBar);
        CreateStatusBar();
        SetStatusText("Welcome to wxWidgets!");
    }

    void MainFrame::OnExit(wxCommandEvent& event)
    {
        Close(true);
    }
}