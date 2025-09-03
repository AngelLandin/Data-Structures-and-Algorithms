#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
        int Cero =0;

        for (int number=0; number<nums.size(); number++){

            if (nums.at(number) != 0){
                swap(nums.at(Cero), nums.at(number));
                Cero++;
            }
        }
}


int main(){
    vector<int> test = {4, 23, 0, 0, 1,3,4,0,1,0,3,12};

    moveZeroes(test);

    for (int x : test){
        cout << x << " ";
    }
}