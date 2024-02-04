#pragma once
// Node structure for a generic linked list
template<typename T>
struct Node {
    T val;
    Node* next;
};