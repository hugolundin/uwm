#define _POSIX_C_SOURCE  200809L
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#include <iterator>
#include <memory>
#include <string>
#include <vector>

#include <MiniFB.h>

#include "window_server.h"

namespace WindowServer {
    
WindowServer::WindowServer(std::string title, int width, int height):
    m_title(std::move(title)),
    m_width(width),
    m_height(height),
    m_buf(std::make_unique<unsigned int[]>(width*height))
{
    m_window = mfb_open_ex(
         /* title = */ m_title.c_str(),
         /* width = */  m_width,
         /* height = */ m_height,
         /* flags = */ 0
     );
}

WindowServer::~WindowServer()
{
    m_window = 0x0;
}

void WindowServer::run()
{
    pid_t pid = fork();

    if (pid < 0) {
        return;
    } else if (pid == 0) {
        ipc_thread_run();
        exit(0);
    }

    mfb_update_state state;

    do {
        state = mfb_update(m_window, m_buf.get());

        switch (state) {
            case STATE_OK:
                continue;

            case STATE_INVALID_BUFFER:
                return;

            case STATE_INVALID_WINDOW:
                return;

            case STATE_INTERNAL_ERROR:
                return;

            case STATE_EXIT:
                return;
        }
    } while(mfb_wait_sync(m_window));
}

void WindowServer::ipc_thread_run()
{
    
}

}
