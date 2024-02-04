#include<iostream>
#include"queue.h"
#include"class_queue.h"

int main() {
    Queue<int> q, a;  // Create two queues of integers
    std::cout << "push\n";
    q.push(1);
    q.push(2);
    q.push(3);
    q.display();
    std::cout << "Front = " << q.front() << " Back = " << q.back() << std::endl;

    std::cout << "pop\n";
    q.pop();
    q.pop();
    q.display();
    std::cout << "Front = " << q.front() << " Back = " << q.back() << std::endl;

    try {
        q.push(10);
        q.push(11);
        q.push(12);
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;  // Handle exceptions related to queue overflow
    }
    std::cout << "exception\n";
    q.display();
    std::cout << "Front = " << q.front() << " Back = " << q.back() << std::endl;

    a = q;  // Use the overloaded assignment operator to copy the contents of q to a
    std::cout << "operator\n";
    a.display();
    std::cout << "Front = " << a.front() << " Back = " << a.back() << std::endl;

    return 0;
}
