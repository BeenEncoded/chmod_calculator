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
#include <wx/checkbox.h>
#include <wx/math.h>
#include <wx/sizer.h>

#include "chmod_portion.hpp"

namespace
{
}

namespace ui::element
{
    ChmodPTypeCheckbox::ChmodPTypeCheckbox() : 
            read{nullptr}, write{nullptr}, execute{nullptr}
    {
        this->construct_pane();
    }

    ChmodPTypeCheckbox::ChmodPTypeCheckbox(
              wxWindow*  parent, 
              wxWindowID id =    wxID_ANY, 
        const wxPoint&   pos =   wxDefaultPosition, 
        const wxSize&    size =  wxDefaultSize, 
              long       style = wxTAB_TRAVERSAL, 
        const wxString&  name =  wxPanelNameStr) : 
            read{nullptr}, write{nullptr}, execute{nullptr}
    {
        this->construct_pane();
    }

    ChmodPTypeCheckbox::~ChmodPTypeCheckbox()
    {
    }

    void ChmodPTypeCheckbox::construct_pane()
    {
        wxBoxSizer* layout = new wxBoxSizer(wxVERTICAL);
        this->read = new wxCheckBox(static_cast<wxWindow*>(this), this->GetId(), "Read");
        this->write = new wxCheckBox(static_cast<wxWindow*>(this), this->GetId(), "Write");
        this->execute = new wxCheckBox(static_cast<wxWindow*>(this), this->GetId(), "Execute");

        layout->Add(this->read);
        layout->Add(this->write);
        layout->Add(this->execute);

        this->SetSizer(layout);
    }


}