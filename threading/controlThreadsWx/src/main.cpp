
// Simple demo of starting and canceling a thread. A wxWidget been used, as it is easier to demo using button to start/stop thread
// and  having a status bar that identifies is a thread is running or not...

#include <sys/types.h>
#include <wx/wx.h>


const unsigned long int INACTIVE_THREAD = 0;


// Function Thread with No Parameters...
void* thread_noParam (void* unused)
{

    printf("\nStart new thread...\n");
    usleep(100000);         // Wait a bit, as the other thread will also print something, and it will not look pretty on the screen...

     for (int i=0;i<250;i++)
     {
            fputc ('x', stderr);
            usleep(100000);
     }

      printf("\n");

     return NULL;
}

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

    pthread_t thread_id = INACTIVE_THREAD;
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
    EVT_MENU( ID_Hello, MyFrame::OnHello)
    EVT_MENU( wxID_ABOUT, MyFrame::OnAbout)
    EVT_MENU( wxID_EXIT, MyFrame::OnExit)
END_EVENT_TABLE()


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
    // Use this textbox in the future to display some status...
    //textctrl = new wxTextCtrl(panel, -1, wxT(""), wxDefaultPosition, wxSize(250, 150), wxTE_MULTILINE);

    createNewThreadBtn = new wxButton(panel, ID_CREATE_NEW_THREAD_BUTTON, _T("Create New"),wxPoint(30,30), wxSize(120, 30), 0);
    cancelThreadBtn = new wxButton(panel, ID_CANCEL_THREAD_BUTTON, _T("Cancel"),wxPoint(30,70), wxSize(120, 30), 0);

    createNewThreadBtn -> Enable();
    cancelThreadBtn -> Disable();
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
}

void MyFrame::OnCreateNewThread(wxCommandEvent& event)
{

  if (thread_id == INACTIVE_THREAD)
  {
    pthread_create (&thread_id , NULL, &thread_noParam, NULL);
    SetStatusText("Thread in progress...");
    createNewThreadBtn -> Disable();
    cancelThreadBtn -> Enable();
  }
  else
      wxMessageBox("A thread is already active!", "Caution", wxOK | wxICON_EXCLAMATION);
}

void MyFrame::OnCancelThread(wxCommandEvent& event)
{


  if (thread_id != INACTIVE_THREAD)
  {
    pthread_cancel(thread_id );
    thread_id = INACTIVE_THREAD;
    SetStatusText("No Active Thread");
    createNewThreadBtn -> Enable();
    cancelThreadBtn -> Disable();
  }
  else
      wxMessageBox("No thread to stop!", "Caution", wxOK | wxICON_EXCLAMATION);


}


void MyFrame::OnExit(wxCommandEvent& event)
{
  // Make sure to stop the thread before closing the application...
  if (thread_id != INACTIVE_THREAD)
  {
    pthread_cancel(thread_id );
    thread_id = INACTIVE_THREAD;
  }

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



