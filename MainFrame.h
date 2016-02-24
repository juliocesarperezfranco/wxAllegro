#ifndef __MAINFRAME_H__
#define __MAINFRAME_H__

#include <assert.h>
#include "wxAllegro.h"

class MainFrame : public wxFrame
{
  public:
    MainFrame();
    virtual ~MainFrame();

  public:
    void CreateControls();

  private:
    ALLEGRO_DISPLAY *myDisplay;

  private:
    bool SaveBitmap(ALLEGRO_BITMAP * sub, int x, int y, int slice_w, int slice_h, const char * prefix, wxBitmap &returnBitmap);
};

#endif // __MAINFRAME_H__
