cmake_minimum_required(VERSION 3.17)
project(wkWormOrder)

set(CMAKE_CXX_STANDARD 20)

add_library(hacklib STATIC
        lib/hacklib/ExeFile.cpp lib/hacklib/ExeFile_WIN32.cpp
        lib/hacklib/PatternScanner.cpp lib/hacklib/Memory_WIN32.cpp)

link_directories(lib)
include_directories(include lib/hacklib)

configure_file(
        resource.rc.in
        resource.rc
)
add_definitions(-DLIBRARY_EXPORTS)

add_library(wkWormOrder SHARED
        src/dllmain.cpp
        src/Config.cpp src/Config.h
        src/Hooks.cpp src/Hooks.h
        src/W2App.cpp src/W2App.h
        src/Utils.cpp src/Utils.h
        src/BitmapImage.h
        src/BitmapTextbox.cpp src/BitmapTextbox.h
        src/Debugf.h
        src/entities/CList.h
        src/entities/CTask.h
        src/entities/CGameTask.h
        src/entities/CTaskWorm.cpp src/entities/CTaskWorm.h

        ${CMAKE_CURRENT_BINARY_DIR}/resource.rc
        src/LobbyScrambler.cpp src/LobbyScrambler.h src/entities/CTaskTeam.cpp)

set_property(TARGET wkWormOrder hacklib PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

target_link_libraries(wkWormOrder hacklib capstone Polyhook_2 version)
