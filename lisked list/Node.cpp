#include <iostream>
using namespace std;

class Node {
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
            Node* newNode = new Node(value); // Puntero a un nuevo nodo
            head = newNode; // El puntero head apunta al nuevo nodo creado
            tail = newNode; // El puntero tail apunta al nuevo nodo creado
            length = 1;
        }

        void printList(){
            Node* temp = head;
            while(temp != nullptr){
                cout << temp->value <<endl;
                temp = temp->next;
            }
        }

        void getHead(){
            cout << "Head: " << head->value << endl;
        }

        void getTail(){
            cout << "Tail: " << tail->value << endl;
        }

        void getLength(){
            cout << "Length: " << length <<endl;
        }

        ~LinkedList(){
            Node* temp = head;
            while(temp != nullptr){
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void append(int value){
            Node* newNode = new Node(value);

            if(!head){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }

            length++;
        }

        void deleteLast(){
            if(length == 0) return;

            Node* temp = head;
            if(length == 1){
                head = nullptr;
                tail = nullptr;
            }

            else {
                Node* pre = head;
                while(temp->next){
                    pre = temp;
                    temp = temp->next;
                }

                tail = pre;
                tail->next = nullptr;

                delete temp;
                length--;

            }
        }

        void prepend(int value){
            Node* newNode = new Node(value);
            if (length == 0){
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
            if (!head) return; //Tambien se podria con if(length == 0)
            
            Node* temp = head;
            if (length == 1){
                head = nullptr;
                tail = nullptr;
            }
            else {
                head = head->next;
            }

            delete temp;
            length--;
        }

        Node* get(int index){
            if (index < 0 || index >= length){
                return nullptr;
            }

            Node* temp = head;

            for (int i = 0; i < index; i++){
                temp = temp->next;
            }

            return temp;
        }

        
        bool set(int index, int value){
            Node* temp = get(index);

            if(temp){
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
            if(index < 0 || index >= length) return;

            if(index == 0){
                return deleteFirst();
            }

            if (index == length -1 ){
                return deleteLast();
            }
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

            Node* before = nullptr;
            Node* after = temp->next;

            for (int i=0; i < length; i++){
                after = temp->next;
                temp->next = before;
                before = temp;
                temp = after;
            }
        }



};

int main(){
    LinkedList* myLinkedList = new LinkedList(1);    
    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(4);
    myLinkedList->append(5);

    myLinkedList->printList();

    cout << "------------------INVERTIMOS LA LISTA ENLAZADA--------------"<<endl;
    myLinkedList->reverse();
    myLinkedList->printList();


    return 0;
}
