#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert at the end
    void insert(int value){
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Display all nodes
    void display() {
        Node* temp = head;
        cout << "List: ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Print nodes with even data
    void printEvenNodes() {
        Node* temp = head;
        cout << "Even nodes: ";
        bool found = false;
        while (temp != nullptr) {
            if (temp->data % 2 == 0) {
                cout << temp->data << " ";
                found = true;
            }
            temp = temp->next;
        }
        if (!found)
            cout << "None";
        cout << "\n";
    }
};

int main() {
    DoublyLinkedList list;

    list.insert(11);
    list.insert(24);
    list.insert(36);
    list.insert(7);
    list.insert(9);
    list.insert(40);

    list.display();         // Display the whole list
    list.printEvenNodes();  // Print only even elements

    return 0;
}
