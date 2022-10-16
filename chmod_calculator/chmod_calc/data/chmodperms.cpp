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
#include <bitset>
#include <iostream>

#include "chmodperms.hpp"
#include "../utilities/stream_operations.hpp"
#include "../global_defines.hpp"
#include "../utilities/base_convert.hpp"

namespace data::chmod
{
    permissions::permissions(const permissions& p) : 
        perms{p.perms}{}
    
    permissions::permissions(permissions&& p) : 
        perms{std::move(p.perms)}{}

    permissions::permissions() : 
        perms{0}{}

    permissions::permissions(const int16_t& p) : 
        perms{p}{}

    permissions::~permissions()
    {
    }

    /**
     * @brief This operator allows for implicit comparison using any
     * explicitly defined constructor.
     * 
     * @param p perms
     * @return true if equal
     * @return false if not equal
     */
    bool permissions::operator==(permissions p) const
    {
        return (this->perms == p.perms);
    }

    bool permissions::operator!=(permissions p) const
    {
        return (this->perms != p.perms);
    }

    permissions& permissions::operator=(permissions p)
    {
        this->perms = p.perms;
        return *this;
    }

    /**
     * @brief Sets the permissions for a target.  This will set all 3 types of
     *        permission types.  permission_type is a bitset.  This way, you can
     *        set all of the perms or only some of the perms.
     * 
     * @param targ The target to set permissions for.
     * @param c The permissions to be set for the target.
     */
    void permissions::set(const permission_target& targ, const permission_type& c)
    {
        if((c & READ) == READ) this->perms |= (READ<<targ);
        else this->perms &= ~(READ<<targ);

        if((c & WRITE) == WRITE) this->perms |= (WRITE<<targ);
        else this->perms &= ~(WRITE<<targ);

        if((c & EXECUTE) == EXECUTE) this->perms |= (EXECUTE<<targ);
        else this->perms &= ~(EXECUTE<<targ);
    }

    /**
     * @brief Gets whether the flag for the specified permission type(s) is set.
     * 
     * @param targ The permission target - owner, group, or public.
     * @param ptype The permission type(s)
     * @return true ONLY if all of the asked-for permissions are on.
     * @return false otherwise.
     */
    bool permissions::get(const permission_target& targ, const permission_type& ptype) const
    {
        return ((this->perms & (ptype<<targ)) == (ptype<<targ));
    }

    std::vector<int> permissions::octal_value(const permission_target& targ) const
    {
        using namespace bmap;

        std::vector<int> binaryrep{0, 0, 0};
        if(this->get(targ, READ)) binaryrep[2] = 1;
        if(this->get(targ, WRITE)) binaryrep[1] = 1;
        if(this->get(targ, EXECUTE)) binaryrep[0] = 1;
        return convert_base<2, 8>(binaryrep);
    }

    std::string permissions::to_string() const
    {
        using namespace bmap;
        
        std::vector<int> binary_rep;

        for(int x = 8; x >= 0; --x)
        {
            binary_rep.insert(binary_rep.cbegin(), ((this->perms & (1<<x)) == (1<<x)) ? 1 : 0);
        }
        auto octal_rep{convert_base<2, 8>(binary_rep)};
        std::string temps;
        for(auto it{octal_rep.cbegin()}; it != octal_rep.cend(); ++it)
        {
            temps += std::to_string(*it);
        }
        return temps;
    }

}