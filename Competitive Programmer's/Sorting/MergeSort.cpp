#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& array, int leftIndex, int midIndex, int rightIndex){

    int arrayLeftSize = midIndex - leftIndex + 1;
    int arrayRightSize = rightIndex - midIndex;

    vector<int> leftArray(arrayLeftSize);
    vector<int> rightArray(arrayRightSize);

    for(int i=0; i<arrayLeftSize; i++){
        leftArray[i] = array[leftIndex + i];
        rightArray[i] = array[]
    }
}



int main(){

    return 0;
}