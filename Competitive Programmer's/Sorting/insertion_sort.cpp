#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& data){
    if (data.size() <= 1) return;

    for (int i=1; i<data.size(); i++){
        int temp = data[i];
        int j = i-1;
        
        while(j > -1 && temp < data[j]){
            data[j+1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }   

}


int main(){
    vector<int> data = {42, 7, 19, -3, 0, 88, 23, -15, 64, 5};

    insertionSort(data);

    for (auto item : data){
        cout << item << " ";
    }

    return 0;
}