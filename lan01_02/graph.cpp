#include "graph.h"

MyList::MyList() : head(nullptr), size(0) {}

void MyList::push_back(const std::string& value) {
    if (head == nullptr) {
        head = new Node(value);
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node(value);
    }
    size++;
}

size_t MyList::get_size() const {
    return size;
}

MyList::Node* MyList::at(size_t index) {
    if (index < size) {
        Node* current = head;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    }
    return nullptr;
}

void MyList::push_front(const std::string& value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    size++;
}

MyList::Node* MyList::begin() {
    return head;
}

MyList::Node* MyList::end() {
    return nullptr;
}

void MyList::insert_after(MyList::Node* node, const std::string& value) {
    if (node) {
        Node* newNode = new Node(value);
        newNode->next = node->next;
        node->next = newNode;
        size++;
    }
    else {
        push_back(value);
    }
}

void MyList::print() {
    MyList::Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void MyList::copy_from(const MyList& otherList) {

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* otherCurrent = otherList.head;
    while (otherCurrent != nullptr) {
        push_back(otherCurrent->data);
        otherCurrent = otherCurrent->next;
    }
}

MyList::~MyList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

Graph::Graph(int V) : vertices(V) {
    adjacency = new MyList[V];
}

void Graph::add_edge(int u, int v) {
    adjacency[u].push_back(to_string(v));
}

