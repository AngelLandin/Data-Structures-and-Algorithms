#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Node{
    public:
        string key; // Atribute key
        int value; // Atribute value
        bool isDeleted; //Flag que indica si el Nodo esta borrado
    public:
        Node(string key, int value){
            this->key = key;
            this->value = value;
            this->isDeleted = false; // Por defecto, no esta borrado
        }
};


class HashTable{
    private:
        static const int SIZE = 13;
        Node* dataMap[SIZE] = {}; // Array of LinkedList type Node*
    public:
        HashTable(){}

        ~HashTable(){
            for (int i=0; i< SIZE; i++){
                if (dataMap[i] != nullptr){
                    delete dataMap[i];
                }
            }
        }


        void printTable(){
            for (int i=0; i<SIZE; i++){
                cout << i << ": ";

                if (dataMap[i] != nullptr && !dataMap[i]->isDeleted){ 
                    cout << "{" << dataMap[i]->key << ", " << dataMap[i]->value << " }" << endl;
                } else if (dataMap[i] != nullptr && dataMap[i]->isDeleted == true){
                    cout << "{" << "Eliminado, " << "0 }" << endl;
                }
                else {
                    cout << "{" << "Null, " << "-1 }" << endl;
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
            int originalHash = hash(key);
            int i = 0;
            int tombstoneIndex = -1; // Inicializado en -1 para indicar que "Todavia no se ha encontrado ningun Nodo borrada (Tombstone)"

            while (i < SIZE) {
                int index = (originalHash + i*i) % SIZE;

                // Caso 1: Nodo vacío, la clave no existe
                if (dataMap[index] == nullptr){
                    // Usamos el Nodo borrada si la encontramos antes, si no, la actual.
                    int finalIndex = (tombstoneIndex != -1) ? tombstoneIndex : index; // if tombstoneIndex != -1 entonces finalIndex = tombstoneIndex, de lo contrario finalIndex = index
                    if (dataMap[finalIndex] != nullptr){ // Si es un tombstone, borramos el nodo viejo
                        delete dataMap[finalIndex];
                    }
                    dataMap[finalIndex] = new Node(key, value);
                    return;
                }

                // Caso 2: Nodo borrado ('tombstone')
                if (dataMap[index]->isDeleted == true){
                    // Guardamos la posición del primer 'tombstone' encontrado.
                    if (tombstoneIndex == -1){
                        tombstoneIndex = index;
                    }
                }
                // Caso 3: El nodo esta ocupado, verifica si es la misma clave
                else if(dataMap[index]->key == key){ // Verificamos si la clave ya existe
                    dataMap[index]->value = value; // Si existe, solo actualizamos el valor.
                    return;
                }
                i++;
            }

            // Si salimos del bucle y encontramos un 'tombstone', podemos usarlo para insertar
            if (tombstoneIndex != -1){
                delete dataMap[tombstoneIndex]; // Liberamos el Nodo borrado antes de almacenar el nuevo
                dataMap[tombstoneIndex] = new Node(key, value); // Insertamos el nuevo Nodo
            }
            else {
                cout << "Error: HashTable llena, no se pudo insertar -> " << key << endl;
            }
            
    }

        int get(string key){
            int index = hash(key);

            int newIndex = 0;
            int i =0;
            while (i<SIZE){
                newIndex = (index + (i*i)) % SIZE;
                if (dataMap[newIndex] == nullptr){
                return -1;
                }
                if (!dataMap[newIndex]->isDeleted && dataMap[newIndex]->key == key){
                    return dataMap[newIndex]->value;
                }
                i++;
            }

            return -1;
            
        }

        void remove(string key){
            int index = hash(key);
            int newIndex = 0;
            int i =0;

            // Recorremos la tabla con quadratic probing
            while (i<SIZE){
                newIndex = (index + (i*i)) % SIZE;
                if (dataMap[newIndex] == nullptr){ // Si se cumple, no hay nada que eliminar
                    return;

                }
                // Si encontramos la clave y no está borrada -> marcamos como borrada
                if (!dataMap[newIndex]->isDeleted && dataMap[newIndex]->key == key){
                    dataMap[newIndex]->isDeleted = true; // Lo marcamos como borrado -> true
                    return;

                }

                // Si es slot está ocupado pero es diferente a la clave que vamos a eliminar seguimos buscando con el quadratic probing
                i++;
            }
        }

        //Función extra que agregue 
        vector<string> keys(){
            vector<string> allKeys = {};
            for (int i =0; i<SIZE; i++){

                if(dataMap[i] != nullptr && !dataMap[i]->isDeleted){
                    allKeys.push_back(dataMap[i]->key);
                }
            }
            return allKeys;
        }

        // utilidad para pruebas: obtener el índice base (hash)  Nota: Solo para pruebas.
        int getHashIndex(string key){
            return hash(key);
        }

    
};


// ------------------------------------------------------------------
// MAIN: Casos de prueba (sin asserts)
// ------------------------------------------------------------------
int main() {
    HashTable* ht = new HashTable();

    cout << "=== Inserciones iniciales (Moni, Aaron, Olivia) ===\n";
    ht->set("Moni", 100);
    ht->set("Aaron", 50);
    ht->set("Olivia", 80);
    ht->printTable();

    cout << "Gets:\n";
    cout << "Moni: " << ht->get("Moni") << "\n";
    cout << "Aaron: " << ht->get("Aaron") << "\n";
    cout << "Olivia: " << ht->get("Olivia") << "\n";
    cout << "Ferrari (no existe): " << ht->get("Ferrari") << "\n\n";

    // Forzar/observar colisiones
    cout << "Índices base (hash) para colisiones:\n";
    cout << "hash('A') = " << ht->getHashIndex("A") << "\n";
    cout << "hash('H') = " << ht->getHashIndex("H") << "\n";
    cout << "hash('O') = " << ht->getHashIndex("O") << "\n\n";

    cout << "=== Insertando claves que colisionan: A, H, O ===\n";
    ht->set("A", 1);
    ht->set("H", 2);
    ht->set("O", 3); // puede fallar si probing no encuentra hueco
    ht->printTable();

    cout << "Nota: la inserción de 'O' puede fallar (mensaje de 'tabla llena') dependiendo del probing y del tamaño del Hash Table.\n\n";

    // Actualizar valor existente
    cout << "=== Actualizar Aaron -> 500 ===\n";
    ht->set("Aaron", 500);
    cout << "Aaron ahora: " << ht->get("Aaron") << "\n\n";

    // Borrar y reutilización tombstone
    cout << "=== Borrar 'Moni' (tombstone) y luego insertar 'Nueva' ===\n";
    ht->remove("Moni");
    cout << "Después de remove('Moni'), get('Moni') = " << ht->get("Moni") << " (esperado -1)\n";
    ht->printTable();

    ht->set("Nueva", 999);
    cout << "Después de insertar 'Nueva', get('Nueva') = " << ht->get("Nueva") << "\n";
    ht->printTable();
    cout << "Reutilización/tombstone comprobada (según política de probing)\n\n";

    // Llenar la tabla para provocar 'tabla llena' en algunas inserciones
    cout << "=== Intento de llenar la tabla con K1..K4 ===\n";
    ht->set("K1", 10);
    ht->set("K2", 11);
    ht->set("K3", 12);
    ht->set("K4", 13); // algunas inserciones pueden printar "tabla llena"
    ht->printTable();

    cout << "=== Intentar eliminar clave inexistente 'Ferrari' (no debe cambiar nada) ===\n";
    ht->remove("Ferrari"); // no debe crash
    ht->printTable();
    cout << "Eliminar inexistente OK\n\n";

    // Listar keys activas
    cout << "=== Keys activas ===\n";
    vector<string> allKeys = ht->keys();
    for (auto &k : allKeys){
        cout << k << " ";
    }
    cout << "\n\n";

    delete ht;
    return 0;
}