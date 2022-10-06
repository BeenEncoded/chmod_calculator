/**
 * @file misc_tests.cpp
 * @author Jonathan Whitlock (beenencoded@outlook.com)
 * @brief Basic miscellaneous unit tests.
 * @version 0.1
 * @date 2022-10-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <boost/test/unit_test.hpp>

#include <iostream>

BOOST_AUTO_TEST_SUITE(suite_of_misc_tests)

/**
 * @brief This smoke test simply tests boost's ability to run the test.
 * 
 */
BOOST_AUTO_TEST_CASE(misc_test_case)
{
    std::cout<< "Hello World!"<< std::endl;
    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_SUITE_END()