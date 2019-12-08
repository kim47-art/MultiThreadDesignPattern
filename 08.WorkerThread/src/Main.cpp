#include <thread>
#include <future>
#include "Channel.hpp"
#include "ClientThread.hpp"
int main() {
    Channel* channel = new Channel(5);
    channel->startWorkers();
    auto t0 = std::thread([channel]{
        ClientThread* c0 = new ClientThread("Alice", channel);
        c0 -> run();
    });
    auto t1 = std::thread([channel]{
        ClientThread* c1 = new ClientThread("Bobby", channel);
        c1 -> run();
    });
    auto t2 = std::thread([channel]{
        ClientThread* c2 = new ClientThread("Chris", channel);
        c2 -> run();
    });
    t0.detach();
    t1.detach();
    t2.detach();
    sleep(40);
    return 0;
}
