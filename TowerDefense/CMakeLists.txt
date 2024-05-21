cmake_minimum_required(VERSION 3.5)

project(TowerDefense LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TowerDefense main.cpp
    menu.cpp)

include(GNUInstallDirs)
install(TARGETS TowerDefense
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
