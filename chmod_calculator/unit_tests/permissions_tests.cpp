/**
 * @file permissions_tests.cpp
 * @author Jonathan Whitlock (beenencoded@outlook.com)
 * @brief Tests the permissions calculations and data IO
 * @version 0.1
 * @date 2022-10-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <boost/test/unit_test.hpp>
#include <array>
#include <bitset>

#include "data/chmodperms.hpp"

BOOST_AUTO_TEST_SUITE(permissions_data_and_calculations_tests)

BOOST_AUTO_TEST_CASE(basic_modification_test)
{
    using namespace data::chmod;

    permissions perms{};
    std::array<permission_target, 3> targs{OWNER, GROUP, PUBLIC};
    std::array<permission_type, 3> types{READ, WRITE, EXECUTE};
    int tempt;

    for(auto targit{targs.cbegin()}; targit != targs.cend(); ++targit)
    {
        for(int x = 0; x < types.size(); ++x)
        {
            tempt = 0;
            for(int xy = 0; xy <= x; ++xy) tempt |= types[xy];
            BOOST_CHECK(perms.get(*targit, types[x]) == false);
            perms.set(*targit, (permission_type)tempt);
            BOOST_CHECK(perms.get(*targit, types[x]) == true);
        }
    }
}

BOOST_AUTO_TEST_SUITE_END()