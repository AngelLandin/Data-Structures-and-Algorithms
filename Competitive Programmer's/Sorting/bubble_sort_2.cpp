#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& nums){
    int size = nums.size() - 1;
    for (int i=size; i>0; i--){
        for (int j=0; j<i; j++){
            if (nums[j] > nums[j+1]){
                swap(nums[j], nums[j+1]);
            }
        }
    }
}

void insertionSort(vector<int>& nums){
    for (int i=1; i<nums.size(); i++){
        int temp = nums[i];
        int j = i-1;

        while (j>-1 && temp < nums[j]){
            nums[j+1] = nums[j];
            nums[j] = temp;
            j--;
        }
    }
}

void selectionSort(vector<int>& nums){
    
    for(int i=0; i<nums.size(); i++){
        int minIndex = i;
        for (int j = i+1; j<nums.size(); j++){
            if (nums[j] < nums[minIndex]){
                minIndex = j;
            }
        }
        if (minIndex != i){
            swap(nums[i], nums[minIndex]);
        }
    }
}


int main(){
    vector<int> nums = {3,5,2,2,54, 1,23, 24, 55, 5};

    insertionSort(nums);

    for (int number : nums){
        cout << number << ", ";
    }

    return 0;
}