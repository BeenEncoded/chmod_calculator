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
#include "wx/event.h"
#include "../data/chmodperms.hpp"

namespace
{
    short get_perm_flags(const gui::element::ChmodPTypeCheckbox&);

    /**
     * @brief Amalgumates the permission bits into 1 bitset.
     * 
     * @param box The wxPanel object with the checkboxes.
     * @return short The bitset representing what boxes were checked.
     */
    inline short get_perm_flags(const gui::element::ChmodPTypeCheckbox& box)
    {
        using namespace data::chmod;
        short ptypes{0};

        if(box.get_execute()->IsChecked()) ptypes |= permission_type::EXECUTE;
        if(box.get_read()->IsChecked()) ptypes |= permission_type::READ;
        if(box.get_write()->IsChecked()) ptypes |= permission_type::WRITE;
        return ptypes;
    }

    enum
    {
        ID_CLEAR_CHECKBOXES = 1
    };

}

namespace gui
{
    MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : 
        wxFrame(NULL, wxID_ANY, title, pos, size)
    {
        wxMenu *menuFile = new wxMenu;
        menuFile->Append(wxID_EXIT);

        wxMenuBar *menuBar = new wxMenuBar;
        menuBar->Append(menuFile, "&File");

        this->ownerp = new element::ChmodPTypeCheckbox(this);
        this->groupp = new element::ChmodPTypeCheckbox(this);
        this->publicp = new element::ChmodPTypeCheckbox(this);
        this->clear_button = new wxButton(this, ID_CLEAR_CHECKBOXES, "Clear");

        this->default_layout();

        this->SetMenuBar(menuBar);
        this->CreateStatusBar();
        Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
        Bind(wxEVT_CHECKBOX, &MainFrame::OnCheckAction, this, wxID_ANY);
        Bind(wxEVT_BUTTON, &MainFrame::OnClearSelection, this, ID_CLEAR_CHECKBOXES);
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

    void MainFrame::OnCheckAction(wxCommandEvent& event)
    {
        this->calculate_permissions();
    }

    void MainFrame::OnClearSelection(wxCommandEvent& event)
    {
        this->groupp->reset_checks();
        this->publicp->reset_checks();
        this->ownerp->reset_checks();
        this->calculate_permissions();
    }

    void MainFrame::calculate_permissions()
    {
        using namespace data::chmod;

        permissions perms{0};
        
        perms.set(GROUP, (permission_type)get_perm_flags(*(this->groupp)));
        perms.set(OWNER, (permission_type)get_perm_flags(*(this->ownerp)));
        perms.set(PUBLIC, (permission_type)get_perm_flags(*(this->publicp)));

        this->output_label->SetLabel(std::to_string(perms.octal_value(OWNER)) + std::to_string(perms.octal_value(GROUP)) + std::to_string(perms.octal_value(PUBLIC)));
    }

    void MainFrame::default_layout()
    {
        wxBoxSizer *permslayout = new wxBoxSizer(wxHORIZONTAL), 
            *labellayout = new wxBoxSizer(wxHORIZONTAL);

        this->SetSizer(new wxBoxSizer(wxVERTICAL));

        permslayout->AddStretchSpacer();
        permslayout->Add(this->ownerp);
        permslayout->AddStretchSpacer();
        permslayout->Add(this->groupp);
        permslayout->AddStretchSpacer();
        permslayout->Add(this->publicp);
        permslayout->AddStretchSpacer();
        this->ownerp->SetTitle("OWNER");
        this->groupp->SetTitle("GROUP");
        this->publicp->SetTitle("PUBLIC");

        this->output_label = new wxStaticText(this, this->GetId(), "000");
        labellayout->AddStretchSpacer();
        labellayout->Add(this->output_label);
        labellayout->AddStretchSpacer();

        this->GetSizer()->Add(permslayout, 1, wxEXPAND);
        this->GetSizer()->Add(labellayout, 1, wxEXPAND);
        this->GetSizer()->Add(this->clear_button, 1, wxALIGN_CENTER_HORIZONTAL);
    }

}