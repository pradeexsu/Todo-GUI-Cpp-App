/***************************************************************
 * Name:      todoListApp.cpp
 * Purpose:   Code for Application Class
 * Author:    pradeep (sutharp777@gmail.com)
 * Created:   2021-02-02
 * Copyright: pradeep ()
 * License:
 **************************************************************/

#include "todoListApp.h"

//(*AppHeaders
#include "todoListMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(todoListApp);

bool todoListApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	todoListFrame* Frame = new todoListFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
