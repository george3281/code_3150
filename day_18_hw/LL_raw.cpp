#include <iostream>

class LinkedList {
private:
    struct Node {
        int value;
        Node* next;
        Node(int v) : value(v), next(nullptr) {}
    };

    Node* head_;
    Node* tail_;

public:
    LinkedList() : head_(nullptr), tail_(nullptr) {}
    ~LinkedList() {
        Node* current = head_;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void push_back(int value) {
        Node* node = new Node(value);
        if (head_ == nullptr) {
            head_ = tail_ = node;
        } else {
            tail_->next = node;
            tail_ = node;
        }
    }

    void print(std::ostream& os) const {
        for (Node* current = head_; current != nullptr; current = current->next) {
            os << current->value;
            if (current->next != nullptr) {
                os << " -> ";
            }
        }
        os << '\n';
    }
};

int main() {
    {
        LinkedList list;
        list.push_back(10);
        list.push_back(20);
        list.push_back(30);
        list.print(std::cout);
    }
    std::cout << "Finished scope (raw)\n";
    return 0;
}
