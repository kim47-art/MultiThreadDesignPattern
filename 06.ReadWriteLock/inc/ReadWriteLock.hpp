#ifndef READWRITELOCK
#define READWRITELOCK
#include <thread>
#include <condition_variable>
#include <mutex>

class ReadWriteLock {
private:
    int readingReaders = 0; // (A) 実際に読んでいる最中のスレッドの数
    int waitingWriters = 0; // (B) 書くのを待っているスレッドの数
    int writingWriters = 0; // (C) 実際に書いている最中のスレッドの数
    bool preferWriter = true; // 書くのを優先するならtrue
    std::mutex mtx_;
    std::condition_variable cv;

public:
    void readLock(){
        std::unique_lock<std::mutex> lk(this->mtx_);
        while (writingWriters > 0 || (preferWriter && waitingWriters > 0)) {
             cv.wait(lk);
        }
        readingReaders++;                       // (A) 実際に読んでいるスレッドの数を1増やす
    }

    void readUnlock() {
        std::unique_lock<std::mutex> lk(this->mtx_);
        readingReaders--;                       // (A) 実際に読んでいるスレッドの数を1減らす
        preferWriter = true;
        cv.notify_all();
    }

    void writeLock() {
        std::unique_lock<std::mutex> lk(this->mtx_);        
        waitingWriters++;                       // (B) 書くのを待っているスレッドの数を1増やす
        while (readingReaders > 0 || writingWriters > 0) {
            cv.wait(lk);
        }
        waitingWriters--;                   // (B) 書くのを待っているスレッドの数を1減らす
        writingWriters++;                       // (C) 実際に書いているスレッドの数を1増やす
    }

    void writeUnlock() {
        std::unique_lock<std::mutex> lk(this->mtx_);
        writingWriters--;                       // (C) 実際に書いているスレッドの数を1減らす
        preferWriter = false;
        cv.notify_all();
    }
};
#endif