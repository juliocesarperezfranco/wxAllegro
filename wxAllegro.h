#ifndef __WXALLEGRO_H__
#define __WXALLEGRO_H__

#define ASSERT(_Expression) ((void)0)  // Allegro warns about undefined ASSERT, seems like a Windows only issue.

#define ALLEGRO_NO_MAGIC_MAIN
#define BITMAP AL_BITMAP
#define RGB AL_RGB
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_memfile.h>
#include <allegro5/system.h>
#include <allegro5/internal/aintern.h>
#include <allegro5/internal/aintern_bitmap.h>
#include <allegro5/platform/aintwin.h>
#undef BITMAP
#undef RGB
#include <windows.h> // windows.h, since BITMAP is already taken care of

#include <wx/wx.h>
#include <wx/app.h>
#include <wx/frame.h>
#include <wx/mstream.h>
#include <wx/image.h>
#include <wx/bitmap.h>
#endif // __WXALLEGRO_H__