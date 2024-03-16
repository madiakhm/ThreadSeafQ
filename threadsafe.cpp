#include <iostream>
#include <thread>
#include <mutex>
#include <queue>

class ThreadSafeQ {
private:
    std::queue<int> q;
    std::mutex m;

public:
    ThreadSafeQ() {}

    ThreadSafeQ(std::queue<int>& initialQueue) : q(initialQueue) {}

    int retrieveAndDelete() {
        int front_value = 0;
        m.lock();
        if (!q.empty()) {
            front_value = q.front();
            q.pop();
        }
        m.unlock();
        return front_value;
    }

    void push(int val) {
        m.lock();
        q.push(val);
        m.unlock();
    }

    void print() {
        m.lock();
        std::queue<int> temp = q;
        while (!temp.empty()) {
            int val = temp.front();
            temp.pop();
            std::cout << val << " ";
        }
        std::cout << std::endl;
        m.unlock();
    }
};

int main() {
    std::queue<int> initialQueue;
    initialQueue.push(1);
    initialQueue.push(2);
    initialQueue.push(3);
    ThreadSafeQ q(initialQueue);

    ThreadSafeQ func;
    std::thread push(&ThreadSafeQ::push, &func, 4);

    push.join();

    std::thread function2(&ThreadSafeQ::retrieveAndDelete, &func);
    function2.join();

    func.print();

    return 0;
}
