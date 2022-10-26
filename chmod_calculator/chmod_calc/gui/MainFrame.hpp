/**
 * @file MainFrame.hpp
 * @author Jonathan Whitlock (beenencoded@outlook.com)
 * @brief The MainFrame declaration header.
 * @version 0.1
 * @date 2022-10-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef MAIN_WINDOW_HPP_INCLUDED
#define MAIN_WINDOW_HPP_INCLUDED
#include <wx/wx.h>

#include "elements/chmod_portion.hpp"

namespace gui
{
    /**
     * @brief The main wxFrame.
     * 
     */
    class MainFrame : public wxFrame
    {
    public:
        MainFrame(const wxString&, const wxPoint&, const wxSize&);
    private:
        void OnExit(wxCommandEvent&);
        void OnCheckAction(wxCommandEvent&);

        //miscellaneous stuff:
        void default_layout();
        void calculate_permissions();

        element::ChmodPTypeCheckbox *ownerp, *groupp, *publicp;
        wxStaticText *output_label;
    };
}

#endif