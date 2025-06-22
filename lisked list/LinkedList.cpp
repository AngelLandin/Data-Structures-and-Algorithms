#include <iostream>
using namespace std;

class Node{
    public:
        int value;
        Node* next;

        Node(int value){
            this->value = value;
            this->next = nullptr;
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
    this->head = newNode;
    this->tail = newNode;
    this->length = 1;
    }

    ~LinkedList(){
        Node* temp = head;
        while(head){ //Mientras head no sea nullptr
            head = head->next;
            delete temp;
            temp = head;
        } 
    }

    void append(int value){
        Node* newNode = new Node(value);
        if (head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        length++;

    }

    

    void printList(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void deleteLast(){
        if (length == 0){
            return;
        }

        Node* temp = head;
        if (length == 1){
            head = nullptr;
            tail = nullptr;
        }
        else{
            Node* prev = head;
            while(temp->next != nullptr){
                prev = temp;
                temp = temp->next;
            }
            tail = prev;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    void prepend(int value){
        Node* newNode = new Node(value);
        if(length == 0){
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void deleteFirst(){
        if (length == 0) return;
        Node* temp = head;
        if (length == 1){
            head = nullptr;
            tail = nullptr;
        }
        else{
            head = head->next;
        }
        delete temp;
        length--;
    }

    Node* get(int index){
        if (index < 0 || index >= length) return nullptr;

        Node* temp = head;

        for (int i=0; i < index; i++){
            temp = temp->next;
        }
        return temp;
    }

    bool set(int index, int value){
        Node* temp = get(index);
        if (temp != nullptr){
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value){
        if (index < 0 || index > length) return false;

        if (index == 0){
            prepend(value);
            return true;
        }
        
        if (index == length){
            append(value);
            return true;
        }
        Node* newNode = new Node(value);
        Node* temp = get(index - 1);

        newNode->next = temp->next;
        temp->next = newNode;
        length++;
        return true;
    }

    void deleteNode(int index){
        if (index < 0 || index >= length) return;

        if (index == 0) return deleteFirst();

        if (index == length-1) return deleteLast();

        Node* prev = get(index - 1);
        Node* temp = prev->next;

        prev->next = temp->next;
        delete temp;
        length--;
    }
    void reverse(){
        Node* temp = head;
        head = tail;
        tail = temp;

        Node* after = temp->next;
        Node* before = nullptr;
        
        for (int i=0; i<length; i++){
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
    }

};

int main(){
    LinkedList* newLinkedlist = new LinkedList(4);

    newLinkedlist->prepend(3);
    newLinkedlist->prepend(2);
    newLinkedlist->prepend(1);

    newLinkedlist->reverse();
    newLinkedlist->printList();


}