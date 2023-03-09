/*
    Framework.hpp

    Include file for Framework class
*/

#ifndef INCLUDED_FRAMEWORK_HPP
#define INCLUDED_FRAMEWORK_HPP

#include <functional>
#include <string_view>

class Framework {
public:

    // Apply the process to the parameter
    int apply(std::function<int(std::string_view)> process, std::string_view parameter);
};

#endif
