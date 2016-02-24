CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(wxAllegroTest)

FIND_PACKAGE(wxWidgets REQUIRED)
INCLUDE(${wxWidgets_USE_FILE})

FIND_PACKAGE(Allegro51 COMPONENTS allegro_primitives allegro_images allegro_color allegro_memfile REQUIRED)

SET(wxAllegroTestSources
  wxAllegro.h
  TestApp.h
  TestApp.cxx
  MainFrame.h
  MainFrame.cxx
)

ADD_EXECUTABLE(wxAllegroTest WIN32 ${wxAllegroTestSources})

TARGET_INCLUDE_DIRECTORIES(wxAllegroTest
  ${Allegro51_INCLUDE_DIR}
  ${Allegro51_SOURCE_DIR}
  ${Allegro51_BINARY_DIR}
  )
  
TARGET_LINK_LIBRARIES(wxAllegroTest ${wxWidgets_LIBRARIES} ${Allegro51_LIBRARIES})