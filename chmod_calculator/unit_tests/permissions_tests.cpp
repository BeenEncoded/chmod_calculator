/**
 * @file permissions_tests.cpp
 * @author Jonathan Whitlock (beenencoded@outlook.com)
 * @brief Tests the permissions calculations and data IO
 * @version 0.2
 * @date 2022-10-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <boost/test/unit_test.hpp>
#include <array>
#include <bitset>
#include <iostream>

#include "test_utilities/common_test_util.hpp"
#include "data/chmodperms.hpp"

namespace
{
    void set_manually(data::chmod::permissions&, const int16_t&);

    inline void set_manually(data::chmod::permissions& perms, const int16_t& bitset)
    {
        using namespace data::chmod;

        std::array<permission_target, 3> targs{OWNER, GROUP, PUBLIC};
        std::array<permission_type, 3> types{READ, WRITE, EXECUTE};
        int16_t bit{0}, tempt;

        //std::clog<< "Argument passed: "<< std::bitset<9>(bitset)<< std::endl;
        for(auto it{targs.cbegin()}; it != targs.cend(); ++it)
        {
            tempt = 0;
            for(int16_t xy = 0; xy < 3; ++xy)
            {
                if((bitset & (1<<(bit + xy))) == (1<<(bit + xy)))
                {
                    tempt |= types[xy];
                }
            }
            //std::clog<< "Applying: "<< std::bitset<3>(tempt)<< std::endl;
            perms.set(*it, (permission_type)tempt);
            bit += 3;
        }
    }


}

BOOST_AUTO_TEST_SUITE(permissions_data_and_calculations_tests)

/**
 * @brief Tests basic modification and retrieval of ther information
 * that the permissions object is supposed to store.
 */
BOOST_AUTO_TEST_CASE(basic_modification_test)
{
    using namespace data::chmod;

    permissions perms{0};
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

/**
 * @brief Tests assignment and comparison of the permissions object.
 */
BOOST_AUTO_TEST_CASE(assignment_and_comparison)
{
    using namespace data::chmod;
    using test::common::random_number;

    permissions perms{0};
    int16_t tempint{0};

    for(unsigned int repeats{0}; repeats < 20; ++repeats)
    {
        tempint = 0;
        for(unsigned int x{0}; x < 4; ++x) tempint |= (1<<random_number(0, 8));
        set_manually(perms, tempint);

        BOOST_CHECK(perms == tempint);
    }
}

BOOST_AUTO_TEST_SUITE_END()