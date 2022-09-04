cmake_minimum_required(VERSION 3.24.1 FATAL_ERROR)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_C_COMPILER "/usr/bin/clang")

#Some Settings:
set(PROJECT_SOURCE_FILES 
    main.cpp)
set(targ calc_chmod)
set(RELEASE false)
set(USE_BOOST false)

#the build:
project(calc_chmod)

if(USE_BOOST)
    find_package(Boost 1.78 REQUIRED COMPONENTS system)
    if(Boost_FOUND)
        include_directories(${targ} PRIVATE ${Boost_INCLUDE_DIRS})
    endif()
endif()

add_executable(${targ} ${PROJECT_SOURCE_FILES})

if(RELEASE)
    add_compile_options(-O3)
endif()

if(USE_BOOST)
    if(Boost_FOUND)
        link_directories(${Boost_LIBRARY_DIRS})
        target_link_libraries(${targ} LINK_PUBLIC Boost::system)
    else()
        message("FATAL ERROR: boost library not found!")
    endif()
endif()