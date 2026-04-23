#include <iostream>
#include <memory>

class DoublyLinkedList {
private:
    struct Node {
        int value;
        std::shared_ptr<Node> next;
        std::weak_ptr<Node> prev;
        Node(int value) : value(value), next(nullptr), prev() {}
    };

    std::shared_ptr<Node> head_;
    std::shared_ptr<Node> tail_;

public:
    DoublyLinkedList() = default;
    ~DoublyLinkedList() = default;

    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

    void push_back(int value) {
        auto new_node = std::make_shared<Node>(value);
        if (!head_) {
            head_ = new_node;
            tail_ = new_node;
        } else {
            new_node->prev = tail_;
            tail_->next = new_node;
            tail_ = new_node;
        }
    }

    void print_forward(std::ostream& os) const {
        for (Node* current = head_.get(); current != nullptr;
             current = current->next.get()) {
            os << current->value;
            if (current->next) {
                os << " -> ";
            }
        }
        os << '\n';
    }

    void print_backward(std::ostream& os) const {
        for (Node* current = tail_.get(); current != nullptr; ) {
            os << current->value;
            std::shared_ptr<Node> pred = current->prev.lock();
            if (pred) {
                os << " -> ";
            }
            current = pred.get();
        }
        os << '\n';
    }
};

int main() {
    {
        DoublyLinkedList list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        list.print_forward(std::cout);
    }
    std::cout << "Finished scope\n";
    return 0;
}
