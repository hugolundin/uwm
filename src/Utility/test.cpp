#include <iostream>

#include "Result.h"

using Utility::Result;

struct Error {

};

int main(int argc, char const *argv[])
{
    Result<int, Error> result(5);
    if (!result.is_error()) {
        std::cout << result.value() << std::endl;
    }

    Result<int, Error> result2({});
    if (!result.is_error()) {
        std::cout << result2.value() << std::endl;
    }

    return 0;
}
