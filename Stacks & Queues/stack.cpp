#include <iostream>
using namespace std;

class Node{
    public:
        Node* next;
        int value;

        Node (int value){
            this->value = value;
            this->next = nullptr;
        }
};

class Stack {
    private:
        Node* top;
        int height;
        
    public:
        Stack(int value){
            Node* newNode = new Node(value);
            top = newNode;
            height = 1;
        }

        void getTop(){
            cout << "Top: " << top->value << "\n";
        }

        void getHeight(){
            cout << "Height: " << height << "\n";
        }

        void printStack(){
            Node* temp = top;

            while (temp != nullptr){
                cout << temp->value << "\n";
                temp = temp->next;
            }
        }

        void push(int value){
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            height++;
        }

        int pop(){
            if (top == nullptr){
                return INT_MIN;
            }
            Node* temp = top;
            int poppedValue = top->value;
            top = top->next;
            delete temp;
            height--;

            return poppedValue;
        }
};


int main(){
    Stack* myStack = new Stack(1);
    myStack->push(2);

    /*
    myStack->getHeight();
    myStack->getTop();
    myStack->printStack();

    myStack->push(2);

    myStack->printStack();
    */
    cout << "-------------------------------------------Stack-------------------------------------------\n";
    myStack->printStack();

    cout << "-------------------------------------------Test pop()-------------------------------------------\n";
    myStack->pop();

    cout << "-------------------------------------------Stack-------------------------------------------\n";
    myStack->printStack();


}