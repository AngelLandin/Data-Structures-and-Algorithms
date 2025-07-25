#include <iostream>
using namespace std;

class Node{

public:
    int value;
    Node* next;

    Node(int value){
        this->value = value;
        next = nullptr;

    }
};


class LinkedList{
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList(int value){
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~LinkedList(){
        Node* temp = head;
        while (head) { // while (head) -> while (head != nullptr)
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    //Print all the list
    void printList(){
        Node* temp = head;
        while (temp){
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    // Add Node to the final list
    void append(int value){
        Node* newNode = new Node(value);
        if (length == 0){
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    //Delete last Node of the list
    void deleteLast(){
        if (length == 0) return;

        Node* temp = head;

        if (length == 1){
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node* prev = temp;
            while (temp->next != nullptr){
                prev = temp;
                temp = temp->next;
            }
            tail = prev;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

// Add a new Node in the first position of the Linked List
    void prepend(int value){
        Node* newNode = new Node(value);

        if (length == 0){
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }

        length++;
    }

    // Delete the first Node of the Linked List
    void deleteFirst(){
        if (length == 0) return;

        Node* temp = head;

        if (length == 1){
            head = nullptr;
            tail = nullptr;
        } else{
            head = head->next;
        }
        delete temp;
        length--;
    }


// Getters Functions 
    void getTail(){
        cout << "Tail: " << tail->value << endl;
    }

    void getHead(){
        cout << "Head: " << head->value << endl;
    }

    void getLength(){
        cout << "Length: " << length << endl;
    }

    //Function for get Node in Position input

    Node* get(int index){
        if (index < 0 || index >= length){
            return nullptr;
        } 

        Node* temp = head;

        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    }

    //Function for set a value of Node
    bool set(int index, int value){
        Node* temp = get(index);

        if (temp){
            temp->value = value;
            return true;
        }
        return false;
    }

    //Function for insert a new Node at a index
    bool insert(int index, int value){
        if (index < 0 || index > length) return false;

        if (index == 0) {
            prepend(value);
            return true;
        }

        if (index == length){
            append(value);
            return true;
        }

        Node* newNode = new Node(value);
        Node* temp = get(index-1);

        newNode->next = temp->next;
        temp->next = newNode;
        length++;
        return true;
    }

    //Function for delete a Node
    void deleteNode(int index){
        if (index < 0 || index >= length) return;

        if (index == 0){
            deleteFirst();
            return;
        }

        if (index == length - 1){
            deleteLast();
            return;
        }

        Node* prev = get(index - 1);
        Node* temp = prev->next;

        prev->next = temp->next;
        delete temp;
        length--;
    }
    //Function for reverse the Linked List
    void reverse(){
        Node* temp = head;
        tail = temp;

        Node* before = nullptr;
        Node* after = nullptr;
        while (temp != nullptr){
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
        head = before;
    }

};

int main(){
    LinkedList* newLinkedList = new LinkedList(4);

    newLinkedList->getHead();
    newLinkedList->getTail();
    newLinkedList->getLength();

    newLinkedList->append(5);
    newLinkedList->append(6);

    cout << "----------------------------------PRINT LIST----------------------------------" <<endl;
    newLinkedList->printList();

    cout << "----------------------------------Test of the function deleteLast----------------------------------" << endl;
    newLinkedList->deleteLast();
    newLinkedList->printList();

    cout << "----------------------------------Test of the function prepend----------------------------------" << endl;
    newLinkedList->prepend(7);
    newLinkedList->prepend(5);
    newLinkedList->printList();

    cout << "----------------------------------Test of the function deleteFirst----------------------------------" << endl;
    newLinkedList->deleteFirst();
    newLinkedList->printList();

    cout << "----------------------------------Test of the function Get----------------------------------" << endl;
    cout << newLinkedList->get(1)->value <<endl;

    cout << "----------------------------------Test of the function Set----------------------------------" << endl;
    newLinkedList->set(1, 100);
    newLinkedList->printList();

    cout << "----------------------------------Test of the function insert----------------------------------" << endl;
    newLinkedList->insert(1, 50);
    newLinkedList->printList();

    cout << "----------------------------------Test of the function delete----------------------------------" << endl;
    newLinkedList->deleteNode(1);
    newLinkedList->printList();

    cout << "----------------------------------Test of the function reverse----------------------------------" << endl;
    newLinkedList->reverse();
    newLinkedList->printList();
    

}