#pragma once
// Queue class implementing a queue using linked list
template<typename T>
class Queue {
    Node<T>* F, * B;  // Front and Back pointers of the queue
    int n;  // Size of the queue

public:
    // Constructor
    Queue() : F(nullptr), B(nullptr), n(0) {}

    // Destructor
    ~Queue() {
        clear();  // Release memory when the queue goes out of scope
    }

    // Returns the size of the queue
    int size() const {
        return n;
    }

    // Checks if the queue is empty
    bool empty() const {
        return n == 0;
    }

    // Add an element to the back of the queue
    void push(const T& val) {
        Node<T>* temp = new Node<T>;  // Create a new node
        temp->val = val;
        temp->next = nullptr;

        if (temp == nullptr) {
            throw "queue overflow";  // Throw exception if memory allocation fails
        }

        if (F == nullptr) {
            F = B = temp;  // If the queue is empty set both front and back to the new node
        }
        else {
            B->next = temp;  //link the new node to the back and update the back pointer
            B = temp;
        }
        n++;
    }

    // Removes the front element from the queue
    void pop() {
        if (empty()) {
            throw "queue underflow";  // Throw exception if pop is called on an empty queue
        }

        Node<T>* temp = F;  // Store the front node
        F = temp->next;  // Move front pointer to the next node
        delete temp;  // Delete the front node
        n--;
    }

    // Removes all elements from the queue
    void clear() {
        while (!empty()) {
            pop();
        }
    }

    // Returns the value of the front element
    T front() {
        if (empty()) {
            throw "queue underflow";  // Throw exception if front is called on an empty queue
        }
        return F->val;
    }

    // Returns the value of the back element
    T back() {
        if (empty()) {
            throw "queue underflow";  // Throw exception if back is called on an empty queue
        }
        return B->val;
    }

    // Overloaded assignment operator for deep copying
    void operator=(const Queue<T>& rhs) {
        clear();  // Clear the current queue
        Node<T>* temp = rhs.F;  // Start from the front of the rhs queue

        // Copy each element from rhs to the current queue
        while (temp != nullptr) {
            push(temp->val);
            temp = temp->next;
        }
    }

    // Display the elements of the queue
    void display() {
        Node<T>* temp = F;

        // Traverse the queue and print each element
        while (temp != nullptr) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};