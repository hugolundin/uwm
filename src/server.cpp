#include <iostream>

#include "nngpp/nngpp.h"
#include "nngpp/protocol/sub0.h"
#include "nngpp/platform/platform.h"

#include "readerwriterqueue.h"

int main(int argc, char const *argv[])
{
    // moodycamel::ReaderWriterQueue<int> q;
    
    // int number;
    // q.enqueue(5);
    // auto res = q.try_dequeue(number);

    // std::cout << number << std::endl;

    auto s = nng::sub::open();
    s.set_opt_string(NNG_OPT_SUB_SUBSCRIBE, {});
    s.dial("ipc://@pubsub.ipc");

    for (;;) {
        auto message = s.recv(NNG_FLAG_ALLOC);
        nng::msleep(1000);
    }

    // rpc::server server(rpc::constants::DEFAULT_PORT);

    // server.bind("add", [&](int a, int b) {
    //     return a + b;
    // });

    // server.run();
    // return 0;
}
