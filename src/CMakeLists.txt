cmake_minimum_required(VERSION 3.24.1 FATAL_ERROR)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_C_COMPILER "/usr/bin/clang")

set(targ calc_chmod)
set(RELEASE false)
set(USE_BOOST false)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#the build:
project(calc_chmod)

if(USE_BOOST)
    find_package(Boost 1.78 REQUIRED COMPONENTS system)
    if(Boost_FOUND)
        include_directories(${targ} PRIVATE ${Boost_INCLUDE_DIRS})
    endif()
endif()

find_package(wxWidgets COMPONENTS gl core base REQUIRED)
include(${wxWidgets_USE_FILE})

add_executable(${targ} ${PROJECT_SOURCE_FILES})

#add folders:
target_sources(${targ} PRIVATE main.cpp)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/gui")

if(RELEASE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
else()
    message("Adding those debug symbols!")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -gdwarf -O0 -Wall")
endif()

target_link_libraries(${targ} LINK_PUBLIC ${wxWidgets_LIBRARIES})

if(USE_BOOST)
    if(Boost_FOUND)
        link_directories(${Boost_LIBRARY_DIRS})
        target_link_libraries(${targ} LINK_PUBLIC Boost::system)
    else()
        message("FATAL ERROR: boost library not found!")
    endif()
endif()