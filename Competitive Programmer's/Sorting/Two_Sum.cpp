#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int> hashMap;
    for(int i=0; i < nums.size(); i++){
        int complement = target - nums[i];
        if (hashMap.find(complement) != hashMap.end()){
            return {hashMap[complement], i};
        }
        hashMap[nums[i]] = i;
    }
    return {};
}

int main(){

    vector<int> test1 = {3, 2, 4, 6, 10, 1, 5, 3, 4, 6};
    int target = 8;

    vector<int> output = twoSum(test1, target);

    for (int x : output){
        cout << x << " ";
    }

    return 0;
}