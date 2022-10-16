set(targ unit_tests)

if(USE_BOOST)
    find_package(Boost 1.78 REQUIRED COMPONENTS system unit_test_framework filesystem)
    if(Boost_FOUND)
        include_directories(${targ} PRIVATE ${Boost_INCLUDE_DIRS})
    endif()
endif()

find_package(wxWidgets COMPONENTS gl core base REQUIRED)
include(${wxWidgets_USE_FILE})

add_executable(${targ} ${PROJECT_SOURCE_FILES})
include_directories("../chmod_calc")

#add folders:
target_sources(${targ} PRIVATE 
    runner.cpp
    misc_tests.cpp
    permissions_tests.cpp
    ../chmod_calc/data/chmodperms.cpp
    ../chmod_calc/data/chmodperms.hpp
    ../chmod_calc/global_defines.hpp)
add_subdirectory(test_utilities)

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    message("Adding those debug symbols!")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -gdwarf -O0 -Wall")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()

target_link_libraries(${targ} LINK_PUBLIC ${wxWidgets_LIBRARIES})

if(USE_BOOST)
    if(Boost_FOUND)
        link_directories(${Boost_LIBRARY_DIRS})
        target_link_libraries(${targ} LINK_PUBLIC Boost::system Boost::filesystem ${Boost_LIBRARIES})
    else()
        message("FATAL ERROR: boost library not found!")
    endif()
endif()