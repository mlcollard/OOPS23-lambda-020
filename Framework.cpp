/*
    Framework.cpp

    Implementation file for Framework class
*/

#include "Framework.hpp"
#include <functional>

// Apply the process to the parameter
int Framework::apply(std::function<int(std::string_view)> process, std::string_view parameter) {

    return process(parameter);
}
