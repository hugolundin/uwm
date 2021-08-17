#include <iostream>
#include "rpc/server.h"

int main(int argc, char const *argv[])
{
    rpc::server server(rpc::constants::DEFAULT_PORT);

    server.bind("add", [&](int a, int b) {
        return a + b;
    });

    server.run();
    return 0;
}
