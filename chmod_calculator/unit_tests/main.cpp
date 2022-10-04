/**
 * @file main.cpp
 * @author Jonathan Whitlock (beenencoded@outlook.com)
 * @brief Main entry point for unit testing.
 * @version 0.1
 * @date 2022-10-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <boost/version.hpp>

int main(int, char**)
{
    std::cout<< "Test: "<< BOOST_LIB_VERSION<< std::endl;
}