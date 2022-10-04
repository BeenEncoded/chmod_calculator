/**
 * @file MainFrame.cpp
 * @author Jonathan Whitlock (beenencoded@outlook.com)
 * @brief MainFrame implimentation file.
 * @version 0.1
 * @date 2022-10-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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

    /**
     * @brief OnExit event Handler handles the wxID_EXIT event for this frame.
     * 
     * @param event The event intercepted.
     */
    void MainFrame::OnExit(wxCommandEvent& event)
    {
        Close(true);
    }
}