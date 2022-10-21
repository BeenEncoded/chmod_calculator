/**
 * @file main.cpp
 * @author Jonathan Whitlock (beenencoded@outlook.com)
 * @brief The Main file for the program.  Does a lot of crazy stuff.
 * @version 0.1
 * @date 2022-10-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <wx/event.h>
#include <wx/wx.h>

#include "gui/MainFrame.hpp"

// declarations
class App;

class App : public wxApp
{
public:
    virtual bool OnInit();
};

//Definitions:
wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    gui::MainFrame *frame = new gui::MainFrame(
        "chmod Perms Calculator", 
        wxPoint(50, 50), 
        wxSize(450, 340));
    
    frame->Show(true);
    return true;
}