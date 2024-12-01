#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* head;
    Node* tail;
    int count;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (tail) {
            tail->next = newNode;
        }
        tail = newNode;
        if (!head) {
            head = newNode;
        }
        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty!");
        }
        Node* temp = head;
        int value = temp->data;
        head = head->next;
        if (!head) {
            tail = nullptr;
        }
        delete temp;
        count--;
        return value;s
    }

    int peek() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty!");
        }
        return head->data;
    }

    int size() {
        return count;
    }
};

int main() {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Peek: " << queue.peek() << endl;
    cout << "Dequeue: " << queue.dequeue() << endl;
    cout << "Size: " << queue.size() << endl;
    cout << "Queue is empty: " << (queue.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
