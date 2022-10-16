/**
 * @file chmodperms.hpp
 * @author Jonathan Whitlock (beenencoded@outlook.com)
 * @brief Objects and functions related to the calculation, storage, and IO of chmod permissions.
 * @version 0.1
 * @date 2022-10-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CHMOD_PERMS_HPP_DEFINED
#define CHMOD_PERMS_HPP_DEFINED
#include <cstdint>
#include <iostream>
#include <vector>

namespace data::chmod
{
    class permissions;

    enum permission_target : uint16_t
    {
        OWNER = 0,
        GROUP =3,
        PUBLIC = 6
    };

    enum permission_type : uint16_t
    {
        READ = (1<<0),
        WRITE = (1<<1),
        EXECUTE = (1<<2)
    };

    /**
     * @brief Stores and calculates octal permissions for chmod.
     * This is basically a int16_t.
     */
    class permissions
    {
    public:
        permissions(const int16_t&);
        permissions(const permissions&);
        permissions(permissions&&);
        permissions();

        ~permissions();

        bool operator==(permissions) const;
        bool operator!=(permissions) const;

        void set(const permission_target&, const permission_type&);
        bool get(const permission_target&, const permission_type&) const;
        std::vector<int> octal_value(const permission_target&) const;
        std::string to_string() const;

    private:
        int16_t perms;
    };
}

#endif