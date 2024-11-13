#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };
    Node* frontNode;
    Node* rearNode;
    int count;

public:
    Queue() : frontNode(nullptr), rearNode(nullptr), count(0) {}

    void push(T value) {
        Node* newNode = new Node(value);
        if (empty()) {
            frontNode = rearNode = newNode;
        }
        else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        count++;
    }

    void pop() {
        if (empty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        count--;
    }

    T front() {
        if (empty()) {
            throw runtime_error("Queue is empty");
        }
        return frontNode->data;
    }

    int size() const {
        return count;
    }

    bool empty() const {
        return count == 0;
    }

    void move_to_rear() {
        if (!empty()) {
            T temp = front();
            pop();
            push(temp);
        }
    }

    void display() {
        while (!empty()) {
            cout << front() << " ";
            pop();
        }
        cout << endl;
    }
};

// Main function to test the Queue
int main() {
    Queue<int> q;

    // Pushing 10 values into the queue
    for (int i = 1; i <= 10; i++) {
        q.push(i);
    }

    // Display elements in queue
    q.display();

    // Refill queue to demonstrate move_to_rear function
    for (int i = 1; i <= 10; i++) {
        q.push(i);
    }
    q.move_to_rear(); // Move front element to the rear
    q.display();       // Display elements after moving front to rear

    return 0;
}
