#include <iostream>
#include "rpc/client.h"

int main(int argc, char const *argv[])
{
    rpc::client client("localhost", rpc::constants::DEFAULT_PORT);
    auto result = client.call("add", 2, 3).as<int>();
    std::cout << "Result was " << result << std::endl;
}
