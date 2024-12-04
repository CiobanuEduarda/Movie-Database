cmake_minimum_required(VERSION 3.27)
project(oop_a10_CiobanuEduarda)

set(CMAKE_CXX_STANDARD 14)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

include_directories(include)
include_directories(src)

file(GLOB_RECURSE SOURCES "src/*.cpp")

file(GLOB_RECURSE HEADERS "includeccmake /*.h")

add_executable(oop_a10_CiobanuEduarda
        src/adminGUI.h
        src/adminGUI.cpp
        src/exceptions.cpp
        src/CSVWatchList.cpp
        src/fileWatchList.cpp
        src/HTMLWatchList.cpp
        src/main.cpp
        src/mainwindow.cpp
        src/movie.cpp
        src/repo.cpp
        src/service.cpp
        src/userGUI.cpp
        src/userGUI.cpp
        src/userGUI.cpp
        src/userGUI.cpp
        src/watchList.cpp
        src/watchListModel.cpp
        include/command.h
        include/add_command.h
        include/remove_command.h
        include/update_command.h
        src/remove_command.cpp
        src/add_command.cpp
        src/update_command.cpp
)
target_link_libraries(oop_a10_CiobanuEduarda
        Qt::Core
        Qt::Gui
        Qt::Widgets
)