#include <iostream>
#include <vector>
using namespace std;
#define ln "\n"

int main(){
    vector<int> array1 = {1, 3, 8, 2, 9, 2, 5, 6};
    int size = array1.size();

    for (int a=0; a<size-1; a++){
        for(int b=0; b<size-a-1; b++){
            if (array1[b] > array1[b+1]){
                swap(array1[b], array1[b+1]);
            }
        }
    }

    for (int valor : array1) {
        cout << valor << " ";
    }



    return 0;
}