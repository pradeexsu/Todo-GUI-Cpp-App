/***************************************************************
 * Name:      todoListMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    pradeep (sutharp777@gmail.com)
 * Created:   2021-02-02
 * Copyright: pradeep ()
 * License:
 **************************************************************/

#include "todoListMain.h"
#include <wx/msgdlg.h>
#include <bits/stdc++.h>


//(*InternalHeaders(todoListFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(todoListFrame)
const long todoListFrame::ID_GRID1 = wxNewId();
const long todoListFrame::ID_BUTTON1 = wxNewId();
const long todoListFrame::ID_BUTTON2 = wxNewId();
const long todoListFrame::ID_BUTTON3 = wxNewId();
const long todoListFrame::ID_BUTTON5 = wxNewId();
const long todoListFrame::idMenuQuit = wxNewId();
const long todoListFrame::idMenuAbout = wxNewId();
const long todoListFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(todoListFrame,wxFrame)
    //(*EventTable(todoListFrame)
    //*)
END_EVENT_TABLE()

todoListFrame::todoListFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(todoListFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, _("My Todo List"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxTRANSPARENT_WINDOW, _T("wxID_ANY"));
    SetClientSize(wxSize(454,401));
    SetMinSize(wxSize(-1,-1));
    SetBackgroundColour(wxColour(175,171,192));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("/home/pradeep/Documents/project/todoList/icon.png"))));
    	SetIcon(FrameIcon);
    }
    Grid1 = new wxGrid(this, ID_GRID1, wxPoint(8,8), wxSize(440,248), wxTRANSPARENT_WINDOW, _T("ID_GRID1"));
    Grid1->CreateGrid(2,1);
    Grid1->SetFocus();
    Grid1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DDKSHADOW));
    Grid1->SetBackgroundColour(wxColour(232,224,255));
    wxFont Grid1Font(15,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sawasdee"),wxFONTENCODING_DEFAULT);
    Grid1->SetFont(Grid1Font);
    Grid1->EnableEditing(true);
    Grid1->EnableGridLines(true);
    Grid1->SetRowLabelSize(40);
    Grid1->SetDefaultRowSize(40, true);
    Grid1->SetDefaultColSize(400, true);
    Grid1->SetLabelTextColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWTEXT));
    wxFont GridLabelFont_1(15,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sawasdee"),wxFONTENCODING_DEFAULT);
    Grid1->SetLabelFont(GridLabelFont_1);
    Grid1->SetColLabelValue(0, _("Tasks"));
    Grid1->SetRowLabelValue(0, _("1"));
    Grid1->SetRowLabelValue(1, _("2"));
    Grid1->SetDefaultCellFont( Grid1->GetFont() );
    Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
    Button1 = new wxButton(this, ID_BUTTON1, _("Remove Task"), wxPoint(264,280), wxSize(160,30), wxBORDER_NONE, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DDKSHADOW));
    wxFont Button1Font(15,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sawasdee"),wxFONTENCODING_DEFAULT);
    Button1->SetFont(Button1Font);
    Button1->SetToolTip(_("remove last task"));
    Button2 = new wxButton(this, ID_BUTTON2, _("Add Task"), wxPoint(96,280), wxSize(128,30), wxBORDER_NONE, wxDefaultValidator, _T("ID_BUTTON2"));
    Button2->SetForegroundColour(wxColour(0,0,0));
    wxFont Button2Font(15,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sawasdee"),wxFONTENCODING_DEFAULT);
    Button2->SetFont(Button2Font);
    Button2->SetToolTip(_("add new row"));
    Button3 = new wxButton(this, ID_BUTTON3, _("Move to Top"), wxPoint(96,320), wxSize(128,30), wxBORDER_NONE, wxDefaultValidator, _T("ID_BUTTON3"));
    Button3->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWTEXT));
    wxFont Button3Font(15,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sawasdee"),wxFONTENCODING_DEFAULT);
    Button3->SetFont(Button3Font);
    Button3->SetToolTip(_("move all the task up, and first to the last."));
    Button5 = new wxButton(this, ID_BUTTON5, _("Exit"), wxPoint(264,320), wxSize(160,32), wxBORDER_NONE, wxDefaultValidator, _T("ID_BUTTON5"));
    Button5->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWTEXT));
    wxFont Button5Font(15,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sawasdee"),wxFONTENCODING_DEFAULT);
    Button5->SetFont(Button5Font);
    Button5->SetToolTip(_("exit the application"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&todoListFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&todoListFrame::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&todoListFrame::OnButton3Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&todoListFrame::OnButton5Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&todoListFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&todoListFrame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&todoListFrame::OnClose1);
    //*)
}

todoListFrame::~todoListFrame()
{
    //(*Destroy(todoListFrame)
    //*)
}

void todoListFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void todoListFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to todo List App"));
}


void todoListFrame::OnButton2Click(wxCommandEvent& event)
{
    Grid1->AppendRows();
}

void todoListFrame::OnButton3Click(wxCommandEvent& event)
{
    try{
        if(Grid1->GetNumberRows()<=0)
            return;
        wxString task = Grid1->GetCellValue(0,0);
        Grid1->DeleteRows(0);
        Grid1->AppendRows();
        Grid1->SetCellValue(task,Grid1->GetNumberRows()-1,0);
    }catch(...){
        std::cout<<"exception cought\n";
    }


}

void todoListFrame::OnButton1Click(wxCommandEvent& event)
{
        try{
        int i = Grid1->GetNumberRows()-1;
        if (i>=0)
            Grid1->DeleteRows(0);
    }catch(...){
        std::cout<<"exception cought\n";
    }
}


void todoListFrame::OnButton5Click(wxCommandEvent& event)
{
    exit(0);
}

void todoListFrame::OnButton4Click(wxCommandEvent& event)
{
    int i = Grid1->GetNumberRows()-1;
    if(i>=0)
        Grid1->DeleteRows(i);
}

void todoListFrame::OnClose(wxCloseEvent& event)
{
        exit(0);
}

void todoListFrame::OnClose1(wxCloseEvent& event)
{
    Close();
}

