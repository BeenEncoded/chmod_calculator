set(targ chmod_calc)

if(USE_BOOST)
    find_package(Boost 1.78 REQUIRED COMPONENTS system filesystem)
    if(Boost_FOUND)
        include_directories(${targ} PRIVATE ${Boost_INCLUDE_DIRS})
    endif()
endif()

#add_library(wxcore wxnet)

add_executable(${targ} ${PROJECT_SOURCE_FILES})

target_include_directories(${targ} PUBLIC "../wxWidgets-3.2.1/include")
target_link_libraries(${targ} PUBLIC wxcore wxbase wxxml wxadv wxribbon wxaui wxpropgrid wxrichtext wxnet)

#add folders:
target_sources(${targ} PRIVATE 
    main.cpp
    global_defines.hpp)
add_subdirectory(gui)
add_subdirectory(utilities)
add_subdirectory(data)

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    message("Adding those debug symbols!")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -gdwarf -O0 -Wall")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()

if(USE_BOOST)
    if(Boost_FOUND)
        link_directories(${Boost_LIBRARY_DIRS})
        target_link_libraries(${targ} LINK_PUBLIC Boost::system Boost::filesystem)
    else()
        message("FATAL ERROR: boost library not found!")
    endif()
endif()