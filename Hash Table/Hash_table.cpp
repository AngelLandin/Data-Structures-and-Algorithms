#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Node{
    public:
        string key; // Atribute key
        int value; // Atribute value
        Node* next; // next pointer
    public:
        Node(string key, int value){
            this->key = key;
            this->value = value;
            this->next = nullptr;
        }
};

class HashTable{
    private:
        static const int SIZE = 7;
        Node* dataMap[SIZE]; // Array of LinkedList type Node*
    public:

        void printTable(){
            for (int i=0; i<SIZE; i++){
                cout << i << ": " <<endl;

                if (dataMap[i]){ // if the Linked List != nullptr (preguntas si la lista enlazada no esta vacía)
                    Node* temp = dataMap[i]; // Guardamos el puntero de la Linked List
                
                    while(temp != nullptr){
                        cout << "{" << temp->key << ", " << temp->value << " }" << endl; // Imprime todo lo que contiene la Linked List
                        temp = temp->next;
                    }
                }
            }
         }

        int hash(string key){
            int hash = 0;
            int prime = 23;
            for (int i=0; i<key.length(); i++){
                int ascciValue = int(key[i]);
                hash = (hash + ascciValue*prime) % SIZE; //This function the value or return is 0 < hash < SIZE 
            }
            return hash;

        }

        void set(string key, int value){
            int index = hash(key);

            Node* newNode = new Node(key, value);
            
            if(dataMap[index] == nullptr){
                dataMap[index] = newNode;
            }
            else {
                Node* temp = dataMap[index];
                while (temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        int get(string key){
            int index = hash(key);
            Node* temp = dataMap[index];

            while (temp != nullptr){
                if (temp->key == key){
                    return temp->value;
                }
                else {
                    temp = temp->next;
                }
            }
            return 0;
        }
       
        vector<string> keys(){
            vector<string> allKeys = {};
            for (int i =0; i<SIZE; i++){
                Node* temp = dataMap[i];

                while(temp != nullptr){
                    allKeys.push_back(temp->key);
                    temp = temp->next;
                }
            }
            return allKeys;
        }

        bool itemInCommon(vector<int> vect1, vector<int> vect2) {
            unordered_map<int, bool> vector1 = {};
            for (int i=0; i<vect1.size(); i++){
                vector1[vect1.at(i)] = true;
            }
            
            for (int i=0; i<vect2.size(); i++){
                if (vector1.find(vect2.at(i)) != vector1.end()){
                    return vector1.at(vect2.at(i));
                }
            }
            return false;
        }
};

int main(){
    HashTable* myHashTable = new HashTable();

    myHashTable->set("nails", 100);
    myHashTable->set("tile", 50);
    myHashTable->set("lumber", 80);

    cout << "lumber: " << myHashTable->get("lumber") << endl;

    cout << "Bolts: " << myHashTable->get("bolts") << endl;

    cout << "------------------------------------ ALL KEYS ------------------------------------" <<endl;\
    vector<string> allKeys = myHashTable->keys();
    for (auto key : allKeys){
        cout << key << ", ";
    }
    cout <<endl;

    //myHashTable->printTable();

    vector<int> vect1 = {1, 2, 3, 4, 5};
    vector<int> vect2 = {6, 7, 3, 9, 10};

    bool result = myHashTable->itemInCommon(vect1, vect2);
    cout << result <<endl;

    return 0;
}