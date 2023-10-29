#pragma once
#include "framework.h"

class MyList {
public:
    class Node {
    public:
        std::string data;
        Node* next;

        Node(const std::string& value) : data(value), next(nullptr) {}
    };

private:
    Node* head;
    size_t size;

public:
    MyList();
    void push_back(const std::string& value);
    size_t get_size() const;
    Node* at(size_t index);
    void push_front(const std::string& value);
    void insert_after(Node* node, const std::string& value);
    Node* begin();
    Node* end();
    void print();
    void copy_from(const MyList& otherList);
    ~MyList();
};

class Graph {
public:
    int vertices;
    MyList* adjacency;

    Graph(int V);

    void add_edge(int u, int v);
};