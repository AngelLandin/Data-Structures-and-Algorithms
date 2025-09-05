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


int main(){
    vector<int> nums = {3,5,2,2,54, 1,23, 24, 55, 5};

    bubbleSort(nums);

    for (int number : nums){
        cout << number << ", ";
    }

    return 0;
}