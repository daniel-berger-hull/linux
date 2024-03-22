add_library(business business.cpp logging.cpp)



option(USE_WIN32 "Using a Win32 implementation" OFF)



if (USE_WIN32)
  target_compile_definitions(business PRIVATE "USE_WIN32")
  message( "The Value of WIN_32 is ON" )
endif()
