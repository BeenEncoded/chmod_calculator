/**
 * @file chmod_portion.hpp
 * @author Jonathan Whitlock (beenencoded@outlook.com)
 * @brief This represents a portion of the ui with some checkboxes in it.
 *        Mainly serves to centralize repetitive code.
 * @version 0.1
 * @date 2022-10-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CHMOD_PORTION_HPP_DEFINED
#define CHMOD_PORTION_HPP_DEFINED
#include <wx/wx.h>
#include <wx/panel.h>

namespace gui::element
{
    class ChmodPTypeCheckbox;

    class ChmodPTypeCheckbox : public wxPanel
    {
    public:
        ChmodPTypeCheckbox();
        ChmodPTypeCheckbox(
                wxWindow*, 
                wxWindowID = wxID_ANY, 
          const wxPoint& =   wxDefaultPosition, 
          const wxSize&   =  wxDefaultSize, 
                long       = wxTAB_TRAVERSAL, 
          const wxString& =  wxPanelNameStr);
        
        ~ChmodPTypeCheckbox();

        void SetTitle(const std::string& = "NO_NAME");
        void reset_checks();
        void check_all();

        const wxCheckBox* const get_read() const;
        const wxCheckBox* const get_write() const;
        const wxCheckBox* const get_execute() const;

    private:
        void construct_pane();

        wxStaticText* panel_title;
        wxCheckBox *read, *write, *execute;
        bool constructed;
    };


}

#endif