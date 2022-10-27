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

namespace gui::element
{
    ChmodPTypeCheckbox::ChmodPTypeCheckbox() : wxPanel(),
            panel_title{nullptr},
            read{nullptr}, 
            write{nullptr}, 
            execute{nullptr}, 
            constructed{false}
    {
        this->construct_pane();
    }

    ChmodPTypeCheckbox::ChmodPTypeCheckbox(
              wxWindow*  parent, 
              wxWindowID id, 
        const wxPoint&   pos, 
        const wxSize&    size, 
              long       style, 
        const wxString&  name) : wxPanel(parent, id, pos, size, style, name),
            panel_title{nullptr},
            read{nullptr}, 
            write{nullptr}, 
            execute{nullptr}, 
            constructed{false}
    {
        this->construct_pane();
    }

    ChmodPTypeCheckbox::~ChmodPTypeCheckbox()
    {
    }

    /**
     * @brief Sets the title for this panel.  This is a static label that's
     * shown to the user -- it indicates what this checkbox-group is for.
     * 
     * @param newtitle The new title to set this ui element to.  Defaults to "NO_NAME"
     */
    void ChmodPTypeCheckbox::SetTitle(const std::string& newtitle)
    {
        if(this->panel_title != nullptr)
        {
            this->panel_title->SetLabel(newtitle);
        }
    }

    const wxCheckBox* const ChmodPTypeCheckbox::get_read() const
    {
        return this->read;
    }

    const wxCheckBox* const ChmodPTypeCheckbox::get_write() const
    {
        return this->write;
    }

    const wxCheckBox* const ChmodPTypeCheckbox::get_execute() const
    {
        return this->execute;
    }

    void ChmodPTypeCheckbox::construct_pane()
    {
        if(!this->constructed)
        {
            this->constructed = true;
            wxBoxSizer* layout = new wxBoxSizer(wxVERTICAL);
            this->read = new wxCheckBox(static_cast<wxWindow*>(this), this->GetId(), "Read");
            this->write = new wxCheckBox(static_cast<wxWindow*>(this), this->GetId(), "Write");
            this->execute = new wxCheckBox(static_cast<wxWindow*>(this), this->GetId(), "Execute");
            this->panel_title = new wxStaticText(this, this->GetId(), "NO_NAME");

            layout->Add(this->panel_title);
            layout->Add(this->read);
            layout->Add(this->write);
            layout->Add(this->execute);

            this->SetSizer(layout);
        }
    }

    void ChmodPTypeCheckbox::check_all()
    {
        this->read->SetValue(true);
        this->write->SetValue(true);
        this->execute->SetValue(true);
    }

    void ChmodPTypeCheckbox::reset_checks()
    {
        this->read->SetValue(false);
        this->write->SetValue(false);
        this->execute->SetValue(false);
    }


}