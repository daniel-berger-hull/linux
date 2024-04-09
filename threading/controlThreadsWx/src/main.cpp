// Start of wxWidgets "Hello World" Program

#include <sys/types.h>

#include <wx/wx.h>

class MyApp : public wxApp
{
public:
    bool OnInit() override;
};

wxIMPLEMENT_APP(MyApp);

class MyFrame : public wxFrame
{
public:
    MyFrame();

     DECLARE_EVENT_TABLE()

private:
    void OnHello(wxCommandEvent& event);

    void OnCreateNewThread(wxCommandEvent& event);
    void OnCancelThread(wxCommandEvent& event);

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    void buildMenu();
    void buildMainPanel(wxWindow *parent);

    wxButton *createNewThreadBtn;
    wxButton *cancelThreadBtn;

    wxTextCtrl *textctrl;
};

enum
{
    ID_Hello                        = 1,
    ID_CREATE_NEW_THREAD_BUTTON     = 3,
    ID_CANCEL_THREAD_BUTTON         = 4
};


  BEGIN_EVENT_TABLE ( MyFrame, wxFrame )
    EVT_BUTTON ( ID_CREATE_NEW_THREAD_BUTTON, MyFrame::OnCreateNewThread ) // Tell the OS to run MainFrame::OnExit when
    EVT_BUTTON ( ID_CANCEL_THREAD_BUTTON, MyFrame::OnCancelThread ) // Tell the OS to run MainFrame::OnExit when
  END_EVENT_TABLE() // The button is pressed */

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    return true;
}

MyFrame::MyFrame()  : wxFrame(nullptr, wxID_ANY, "Threads Text App",wxDefaultPosition,wxSize(400, 250))
{
    buildMenu();

    CreateStatusBar();
    SetStatusText("No thread created...");

    buildMainPanel(this);

}

void MyFrame::buildMainPanel(wxWindow *parent)
{
    wxPanel *panel = new wxPanel(parent, -1);
    //textctrl = new wxTextCtrl(panel, -1, wxT(""), wxDefaultPosition, wxSize(250, 150), wxTE_MULTILINE);

    createNewThreadBtn = new wxButton(panel, ID_CREATE_NEW_THREAD_BUTTON, _T("Create New"),wxPoint(30,30), wxSize(120, 30), 0);
    cancelThreadBtn = new wxButton(panel, ID_CANCEL_THREAD_BUTTON, _T("Cancel"),wxPoint(30,70), wxSize(120, 30), 0);

}


void MyFrame::buildMenu()
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",  "string shown in status bar for this menu item");

    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar( menuBar );

    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}

void MyFrame::OnCreateNewThread(wxCommandEvent& event)
{
 //wxMessageBox("OnCreateNewThread", ello World", wxOK | wxICON_INFORMATION);
  SetStatusText("Sub Thread in progress...");
}

void MyFrame::OnCancelThread(wxCommandEvent& event)
{
 /*  wxMessageBox("OnCancelThread",
                 "About Hello World", wxOK | wxICON_INFORMATION); */
 SetStatusText("No Active Thread");
}


void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}



