#include <iostream>
#include <vector>
using namespace std;


void selectionSort(vector<int>& array, int size){

    for (int i = 0; i<size; i++){
        int minIndex = i;

        for (int j=i+1; j<size; j++){
            if (array[minIndex] > array[j]){
                minIndex = j;
            }
        }
        if (minIndex != i){
            swap(array[i], array[minIndex]);
        }
    }
}  

int main(){
    vector<int> array1 = {42, 7, 19, -3, 0, 88, 23, -15, 64, 5};
    int size = array1.size();

    selectionSort(array1, size);

    for (auto x : array1){
        cout << x << " ";
    }

    return 0;
}

