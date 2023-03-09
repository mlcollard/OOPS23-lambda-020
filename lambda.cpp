/*
    lambda.cpp

    Examples of captures in lambda functions and use of std::function
*/

#include <functional>
#include <string_view>
#include <iostream>
#include <sstream>
#include <cassert>
#include "Framework.hpp"

int add2(std::string_view s) {
    return s.size() + 2;
}

class Application {
public:
    int apply(std::string_view s) {
        return s.size() + 2;
    }

    static int applyApplication(std::string_view s) {
        return s.size() + 2;
    }
};

int main(int argc, char* argv[]) {

    Framework framework;

    // function
    {
        std::function<int(std::string_view)> f = add2;

        if (f) {

            assert(framework.apply(f, "a") == 3);
        }
    }

    // empty capture
    {
        std::function<int(std::string_view)> f = [](std::string_view s) {
            return s.size() + 2;
        };

        if (f) {

            assert(framework.apply(f, "a") == 3);
        }
    }

    // const variable capture reference
    {
        const int INCR = 2;
        std::function<int(std::string_view)> f = [](std::string_view s) {

            return s.size() + INCR;
        };

        if (f) {

            assert(framework.apply(f, "a") == 3);
        }
    }

    // capture variable because not constexpr
    {
        int size = 2;
        const int INCR = size;
        std::function<int(std::string_view)> f = [INCR](std::string_view s) {

            return s.size() + INCR;
        };

        if (f) {

            assert(framework.apply(f, "a") == 3);
        }
    }

    // non-const variable capture value
    {
        int incr = 2;
        std::function<int(std::string_view)> f = [incr](std::string_view s) {

            return s.size() + incr;
        };

        if (f) {

            assert(framework.apply(f, "a") == 3);
        }
    }

    // capture the number of times the function is executed
    {
        int numrun = 0;
        std::function<int(std::string_view)> f = [&numrun](std::string_view s) {

            ++numrun;

            return s.size() + 2;
        };

        if (f) {

            assert(framework.apply(f, "a") == 3);
            assert(numrun == 1);
        }
    }

    // pass complex object and use inside lambda
    {
        std::istringstream input("2");

        std::function<int(std::string_view)> f = [&input](std::string_view s) {

            int incr;
            input >> incr;

            return s.size() + incr;
        };

        if (f) {

            assert(framework.apply(f, "a") == 3);
        }
    }

    // pass static method of a class
    {
        std::function<int(std::string_view)> f = Application::applyApplication;

        if (f) {

            assert(framework.apply(f, "a") == 3);
        }
    }

    // pass non-static method of a class
    {
        Application application;

        std::function<int(std::string_view)> f;

        if (f) {

            assert(framework.apply(f, "a") == 3);
        }
    }

    return 0;
}
