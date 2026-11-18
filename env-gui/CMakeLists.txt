cmake_minimum_required(VERSION 3.16)

project(EnvGui LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(EnvGui
    main.cpp
    EnvGui.h
    EnvGui.cpp
    envgui.ui
    envgui.ui
)

target_link_libraries(EnvGui PRIVATE 
    Qt6::Widgets 
)