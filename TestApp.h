#ifndef __TESTAPP_H__
#define __TESTAPP_H__

#include "wxAllegro.h"
#include "MainFrame.h"

class TestApp : public wxApp
{
  public:
    bool OnInit();
    ~TestApp();

  private:
    MainFrame *m_mainFrame;
};

#endif  // __TESTAPP_H__
