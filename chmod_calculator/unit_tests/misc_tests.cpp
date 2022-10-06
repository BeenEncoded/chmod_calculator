#include <boost/test/unit_test.hpp>

#include <iostream>

BOOST_AUTO_TEST_SUITE(suite_of_misc_tests)

BOOST_AUTO_TEST_CASE(misc_test_case)
{
    std::cout<< "Hello World!"<< std::endl;
    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_SUITE_END()