/***************************************************************
 * Name:      todoListApp.h
 * Purpose:   Defines Application Class
 * Author:    pradeep (sutharp777@gmail.com)
 * Created:   2021-02-02
 * Copyright: pradeep ()
 * License:
 **************************************************************/

#ifndef TODOLISTAPP_H
#define TODOLISTAPP_H

#include <wx/app.h>

class todoListApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // TODOLISTAPP_H
