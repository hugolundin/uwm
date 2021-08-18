#include <iostream>
#include "rpc/server.h"
#include "readerwriterqueue.h"

int main(int argc, char const *argv[])
{
    moodycamel::ReaderWriterQueue<int> q;
    
    int number;
    q.enqueue(5);
    auto res = q.try_dequeue(number);

    std::cout << number << std::endl;

    // rpc::server server(rpc::constants::DEFAULT_PORT);

    // server.bind("add", [&](int a, int b) {
    //     return a + b;
    // });

    // server.run();
    // return 0;
}
