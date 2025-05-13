#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert at front
    void insertFront(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at position (1-based index)
    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Invalid position\n";
            return;
        }

        if (position == 1) {
            insertFront(value);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of bounds\n";
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete from front
    void deleteFront() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete from end
    void deleteEnd() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    // Delete at position (1-based index)
    void deleteAtPosition(int position) {
        if (position < 1 || head == nullptr) {
            cout << "Invalid position or empty list\n";
            return;
        }

        if (position == 1) {
            deleteFront();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp->next != nullptr; ++i) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Position out of bounds\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    // Display the list
    void display() {
        Node* temp = head;
        cout << "List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertFront(5);
    list.insertAtPosition(15, 3); // Between 10 and 20

    list.display(); // 5 -> 10 -> 15 -> 20 -> NULL

    list.deleteFront();
    list.display(); // 10 -> 15 -> 20 -> NULL

    list.deleteEnd();
    list.display(); // 10 -> 15 -> NULL

    list.deleteAtPosition(2);
    list.display(); // 10 -> NULL

    return 0;
}
