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

namespace ui::element
{
    class ChmodPTypeCheckbox;

    class ChmodPTypeCheckbox : public wxPanel
    {
    public:
        ChmodPTypeCheckbox();
        ChmodPTypeCheckbox(
                  wxWindow*, 
                  wxWindowID, 
            const wxPoint&, 
            const wxSize&, 
                  long, 
            const wxString&);
        
        ~ChmodPTypeCheckbox();

    private:
        void construct_pane();

        wxCheckBox *read, *write, *execute;
    };


}

#endif