#pragma once

#include <iterator>
#include <memory>
#include <string>
#include <vector>

struct mfb_window;

namespace WindowServer {
class WindowServer {
public:
    WindowServer(std::string title, int width, int height);
    ~WindowServer();
    void run();
private:
    void ipc_thread_run();
    const int m_width;
    const int m_height;
    std::string m_title;
    struct mfb_window *m_window;
    std::unique_ptr<unsigned int[]> m_buf;
};

}
