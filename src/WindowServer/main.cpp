#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <vector>
#include <thread>

#include "MiniFB.h"

#include "window_server.h"

struct Window {
    struct mfb_window *window;
    unsigned int *buf;
};

void ipc_callback(std::vector<Window> *windows)
{
    Window w {
        .window = NULL,
        .buf = new unsigned int[100*100]
    };

    windows->push_back(w);
    windows->push_back(w);
    std::cout << "hej!" << std::endl;
}

int main(int argc, char const *argv[])
{
    mfb_update_state state;
    std::vector<Window> windows;
    std::thread ipc_thread(ipc_callback, &windows);
    
    while (windows.size() == 0);

    for (int i = 0; i < windows.size(); i++)
        windows[i].window = mfb_open_ex("Hej", 100, 100, 0);

    do {
        for (auto& window : windows) {
            state = mfb_update(window.window, window.buf);

            switch (state) {
                case STATE_OK:
                    continue;

                case STATE_INVALID_BUFFER:
                    exit(EXIT_FAILURE);

                case STATE_INVALID_WINDOW:
                    exit(EXIT_FAILURE);

                case STATE_INTERNAL_ERROR:
                    exit(EXIT_FAILURE);

                case STATE_EXIT:
                    continue;
            }
        }
    } while (mfb_wait_sync(windows[0].window));

    ipc_thread.join();
    return 0;
}
