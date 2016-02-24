
#include "TestApp.h"
#include <wx/sysopt.h>

wxIMPLEMENT_APP(TestApp);

bool TestApp::OnInit()
{
  wxInitAllImageHandlers();

  al_init();
  al_init_primitives_addon();
  al_init_image_addon();
  m_mainFrame = new MainFrame();
  m_mainFrame->Show();

  return true;
}

TestApp::~TestApp(){}