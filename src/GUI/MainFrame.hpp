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

namespace gui
{
    /**
     * @brief The main wxFrame.
     * 
     */
    class MainFrame : public wxFrame
    {
    public:
        MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    private:
        void OnExit(wxCommandEvent& event);
    };
}

#endif