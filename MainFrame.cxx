#include "MainFrame.h"

// @brief Constructor
MainFrame::MainFrame() : wxFrame(0L, wxID_ANY, wxT("wxAllegro"), wxDefaultPosition, wxDefaultSize)
{
  this->CreateControls();
}

// @brief Destructor
MainFrame::~MainFrame()
{
}

// @brief Creating the UI controls.
void MainFrame::CreateControls()
{
  wxBoxSizer *mainSizer = new wxBoxSizer(wxHORIZONTAL);
  wxSize size;
  size =   this->GetSize();

  ALLEGRO_BITMAP *myBuffer = al_create_bitmap(size.GetWidth(), size.GetHeight());
  al_set_target_bitmap(myBuffer);

  for(int row = 0; row < 256; row++)
  {
    for(int column = 0; column < 256; column++)
    {
      al_put_pixel(column, row, al_map_rgb(column, row, 128));
    }
  }

  wxBitmap myBitmap;
  SaveBitmap(myBuffer, 0, 0, size.GetWidth(), size.GetHeight(), "bmp", myBitmap);

  wxStaticBitmap *myStaticBitmap = new wxStaticBitmap(this, wxID_ANY, myBitmap, wxPoint(0, 0), wxSize(256, 256), 0);
  mainSizer->Add(myStaticBitmap, 0, wxALL, 5);

  al_destroy_bitmap(myBuffer);

  this->SetSizer(mainSizer);
  this->Layout();
  this->Centre(wxBOTH);
}

// @brief This saves an allegro bitmap into a wxMemoryInputStream an stored in a wxBitmap.
// Taken from the Allegro forum: https://www.allegro.cc/forums/thread/614260
bool MainFrame::SaveBitmap(ALLEGRO_BITMAP * sub, int x, int y, int slice_w, int slice_h, const char * prefix, wxBitmap &returnBitmap)
{
  int size;
  void * buffer;
  int real_size;
  ALLEGRO_FILE * memfile;
  if(!sub)
  {
    return false;
  }
  /* Allocate a buffer that should always be too big.*/
  size = slice_w * slice_h * 4 * 2;
  buffer = calloc(size, 1);
  real_size = 0; if (!buffer)
  {
    fprintf(stderr, "Couldn't allocate the buffer!\n");
    return false;
  }
  /* Open memfile. */
  memfile = al_open_memfile(buffer, size, "rw");
  if (!memfile)
  {
    fprintf(stderr, "Failed to open memfile!\n");
  }
  else
  {
    /* save the bitmap into the memfile. */
    al_save_bitmap_f(memfile, ".bmp", sub);
    /* Get the real size of the bitmap. */
    real_size = al_ftell(memfile);
    if (real_size < 1)
    {
      fprintf(stderr, "Real size is too small!\n");
    }
    else
    {
      /* now, buffer contains the correct bitmap data. Save that to a file
      * (but if could be stored into sqlite as well, if needed).
      */
      wxMemoryInputStream inputStream((void*)buffer, size);
      wxImage image(inputStream, wxBITMAP_TYPE_BMP);
      returnBitmap = wxBitmap(image);
    }
    al_fclose(memfile);
  }
  free(buffer);
};