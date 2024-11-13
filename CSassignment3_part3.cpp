#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Helper function to insert a node in a sorted list
Node* sortedInsert(Node* head, Node* newNode) {
    if (!head || newNode->data < head->data) {
        newNode->next = head;
        return newNode;
    }
    Node* current = head;
    while (current->next && current->next->data < newNode->data) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to sort the linked list using insertion sort
Node* insertionSortLinkedList(Node* head) {
    Node* sorted = nullptr;
    Node* current = head;
    while (current) {
        Node* next = current->next;
        sorted = sortedInsert(sorted, current);
        current = next;
    }
    return sorted;
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the insertion sort on linked list
int main() {
    Node* head = new Node(4);
    head->next = new Node(3);
    head->next->next = new Node(5);
    head->next->next->next = new Node(1);

    cout << "Original List: ";
    printList(head);

    head = insertionSortLinkedList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
