#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Message {
    int id;
    string sender;
    string text;
    bool deleted;
};

vector<Message> generateChatHistory(int n) {
    vector<Message> history;
    history.reserve(n);

    vector<string> sampleTexts = {
        "Hola", "¿Cómo estás?", "Todo bien", "Ok", "Nos vemos",
        "¿Dónde estás?", "Manda ubicación", "Ya voy", "Adiós", "👍"
    };

    for (int i = 0; i < n; i++) {
        Message msg;
        msg.id = i + 1;
        msg.sender = (i % 2 == 0 ? "Alice" : "Bob");
        msg.text = sampleTexts[i % sampleTexts.size()];
        msg.deleted = (i % 17 == 0); // cada 17 mensajes, se elimina uno
        history.push_back(msg);
    }
    return history;
}

void compactChat(vector<Message>& chat) {
    //size_t validIndex = 0;

    //for (int i = 0; i < chat.size(); ++i) {
      //  if (!chat[i].deleted) {
        //    swap(chat[i], chat[validIndex]);
          //  validIndex++;
       // }
    //}

    int left =0, right = 0;

    while (right < chat.size() && left <= right){
        if (chat[left].deleted){
            if (!chat[right].deleted){
                swap(chat[left], chat[right]);
                left++;
                right = left;
            } else {
                right++;
            }
        }else{
            left++;
            right = left;
        }
    }


}

int main() {
    vector<Message> chat = generateChatHistory(50);

    // Mostrar solo los primeros 10 
    for (int i = 0; i < 50; i++) {
        cout << chat[i].id << " [" << chat[i].sender << "]: "
             << chat[i].text
             << (chat[i].deleted ? " (deleted)" : "")
             << endl;
    }

    cout << "Total mensajes generados: " << chat.size() << endl;

    compactChat(chat); // Reorganiza el vector


    cout << "DESPUÉS:\n";
    for (size_t i = 0; i < chat.size(); ++i) {
        cout << chat[i].id <<" [" << chat[i].sender << "] " << chat[i].text;
        if (chat[i].deleted) {
            cout << " (deleted)";
        }
        cout << endl;
    }

    cout << "\nTotal mensajes generados: " << chat.size() << endl;


}