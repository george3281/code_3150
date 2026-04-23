#include <iostream>
#include <memory>

class LinkedList {
private:
    struct Node {
        int value;
        std::unique_ptr<Node> next;
        Node(int value) : value(value), next(nullptr) {}
    };

    std::unique_ptr<Node> head_;
    Node* tail_;

public:
    LinkedList() : head_(nullptr), tail_(nullptr) {}
    ~LinkedList() = default;

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void push_back(int value) {
        if (!head_) {
            head_ = std::make_unique<Node>(value);
            tail_ = head_.get();
        } else {
            tail_->next = std::make_unique<Node>(value);
            tail_ = tail_->next.get();
        }
    }

    void print(std::ostream& os) const {
        for (Node* current = head_.get(); current != nullptr;
             current = current->next.get()) {
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
    std::cout << "Finished scope (unique_ptr)\n";
    return 0;
}
