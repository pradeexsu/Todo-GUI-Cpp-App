/***************************************************************
 * Name:      todoListMain.h
 * Purpose:   Defines Application Frame
 * Author:    pradeep (sutharp777@gmail.com)
 * Created:   2021-02-02
 * Copyright: pradeep ()
 * License:
 **************************************************************/

#ifndef TODOLISTMAIN_H
#define TODOLISTMAIN_H

//(*Headers(todoListFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/grid.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class todoListFrame: public wxFrame
{
    public:

        todoListFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~todoListFrame();

    private:

        //(*Handlers(todoListFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton5Click(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnClose1(wxCloseEvent& event);
        //*)

        //(*Identifiers(todoListFrame)
        static const long ID_GRID1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON5;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(todoListFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxButton* Button5;
        wxGrid* Grid1;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // TODOLISTMAIN_H
