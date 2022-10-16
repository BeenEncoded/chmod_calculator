/**
 * @file main.cpp
 * @author Jonathan Whitlock (beenencoded@outlook.com)
 * @brief Main entry point for unit testing.
 * @version 0.2
 * @date 2022-10-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
 #define BOOST_TEST_MODULE "Tests for chmod_calculator"
 #include <boost/test/unit_test.hpp>
 #include <stdio.h>
 #include <time.h>

namespace
{
    /**
     * @brief Initializes and uninitializes the test program.
     * 
     */
    struct GlobalInitializationFixture
    {
        GlobalInitializationFixture()
        {
            // seed our pseudo-random number generation
            srand(time(nullptr));
        }

        ~GlobalInitializationFixture()
        {
        }

        void setup()
        {
        }

        void teardown()
        {
        }
    };
}

BOOST_TEST_GLOBAL_FIXTURE(GlobalInitializationFixture);