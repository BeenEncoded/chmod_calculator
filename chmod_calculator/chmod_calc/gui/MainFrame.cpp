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
#include "elements/chmod_portion.hpp"

namespace gui
{
    MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    {
        wxMenu *menuFile = new wxMenu;
        menuFile->Append(wxID_EXIT);

        wxMenuBar *menuBar = new wxMenuBar;
        menuBar->Append(menuFile, "&File");

        // this->ownerp = new element::ChmodPTypeCheckbox(this);
        // this->groupp = new element::ChmodPTypeCheckbox(this);
        // this->publicp = new element::ChmodPTypeCheckbox(this);

        // wxBoxSizer* permslayout = new wxBoxSizer(wxHORIZONTAL);
        // permslayout->Add(this->ownerp);
        // permslayout->Add(this->groupp);
        // permslayout->Add(this->publicp);

        //this->SetSizer(permslayout);

        this->SetMenuBar(menuBar);
        this->CreateStatusBar();
        this->SetStatusText("Test");
        Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
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