#include <iostream>
using namespace std;

class Node{
    public:
        Node* next;
        Node* prev;
        int value;

        Node(int value){
            this->value = value;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList{
    private:
    int length;
    Node* head;
    Node* tail;

    public:
    DoublyLinkedList(int value){
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void append(int value){
        Node* newNode = new Node(value);

        if (length == 0){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void deleteLast(){
        if (head == nullptr) return;

        Node* temp = tail;
        if (length == 1){
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    void prepend(int value){
        Node* newNode = new Node(value);
        if (head == nullptr){
            head = newNode;
            tail = newNode;
        } else {
              newNode->next = head;
              head->prev = newNode;
              head = newNode;
        }
        length++;
    }

    void deleteFirst(){
        if (head == nullptr) return;

        Node* temp = head;
        if (head == tail){
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
        length--;
    }

    Node* get(int index){
        if (index < 0 || index >= length) return nullptr;


        Node* temp = head;
        
        if (index < length/2){
            for (int i=0; i<index; i++){
                temp = temp->next;
            }
        } else {
            temp = tail;
            for (int i=length - 1; i>index; i--){
                temp = temp->prev;
            }
        }
        return temp;
    }

    bool set(int index, int value){
        Node* temp = get(index);

        if (temp != nullptr){
            temp->value = value;
            return true;
        } else {
            return false;
        }
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
        Node* before = get(index -1);
        Node* after = before->next;

        newNode->prev = before;
        newNode->next = after;
        before->next = newNode;
        after->prev = newNode;

        length++;
        return true;
    }

    void deleteNode(int index){
        if (index < 0 || index > length) return;
        if (index == 0) return deleteFirst();
        if (index == length - 1) return deleteLast();

        Node* temp = get(index);

        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
        length--;
    } 

    void printList(){
        Node* temp = head;

        while (temp != nullptr){
            cout << temp->value << endl;
            temp = temp->next;
        }
    }
};


int main(){
    DoublyLinkedList* myDLL = new DoublyLinkedList(1);
    myDLL->append(2);
    myDLL->append(3);
    myDLL->append(4);
    myDLL->append(5);
    

    /*
    cout << "Test of Delete Last" << endl;

    cout << "First element delete" <<endl;
    myDLL->deleteLast();
    myDLL->printList();

    cout << "Second element delete" << endl;
    myDLL->deleteLast();
    myDLL->printList();

    cout << "Third element delete" << endl;
    myDLL->deleteLast();
    myDLL->printList();

    cout << "4to element delete" << endl;
    myDLL->deleteLast();
    myDLL->printList();
*/

/*
    cout << "-----------------------------------------------Test Method prepend-----------------------------------------------" << endl; 

    myDLL->prepend(6);
    myDLL->prepend(5);
    myDLL->printList();
*/

/*
    cout << "Test Method deleteFirst" << endl;
    myDLL->deleteFirst();
    myDLL->deleteFirst();
    myDLL->printList();
    myDLL->deleteFirst();
    myDLL->printList();
*/

/*
    cout << "----------------------------------------------Test Method get----------------------------------------------"<<endl;
    cout << "Indice [1]: " << myDLL->get(1)->value << endl;
    cout << "Indice [2]: " << myDLL->get(2)->value << endl;

    cout << "----------------------------------------------Test Method set----------------------------------------------"<<endl;
    myDLL->set(0, 10);
    myDLL->set(1, 11);
    myDLL->set(222, 12);
    myDLL->printList();
    return 0;
*/

/*
    cout << "----------------------------------------------Test Method insert----------------------------------------------"<<endl;
    myDLL->insert(1, 1000);

    myDLL->printList();
*/

    cout << "----------------------------------------------Test Method deleteNode----------------------------------------------"<<endl;

    cout << "DLL before deleteNode(): \n";
    myDLL->printList();

    myDLL->deleteNode(2);
    cout << "\nDLL after deleteNode() in middle: \n";
    myDLL->printList();

    myDLL->deleteNode(0);
    cout << "\nDLL after deleteNode() of first Node:\n";
    myDLL->printList();

    myDLL->deleteNode(2);
    cout << "\nDLL after deleteNode() of last Node:\n";
    myDLL->printList();

}