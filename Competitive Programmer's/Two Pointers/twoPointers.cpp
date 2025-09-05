#include <iostream>
using namespace std;
#include <vector>


vector<int> sem(vector<int>& nums, int target){
    vector<int> result = {};
    int i = 0;
    int r = nums.size() - 1;

    while (i < r){
        int op = nums.at(i) + nums.at(r);

        if (op == target){
            result.push_back(i);
            result.push_back(r);
            return result;
        }

        if (op < target){
            i++; 
        } 
        else {
            r--;
        }
    }
    return result;
}

//Funcion con complexity O(n^2)
/*
vector<int> semTwo(vector<int>& numeros, int target){
    int size = numeros.size();
    vector<int> resultado = {};
    for (int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            int op = numeros.at(i) + numeros.at(j);
            if (op == target){
                resultado.push_back(i);
                resultado.push_back(j);
                return resultado;
            }
        }
    }
    return resultado;
}
*/

int main(){
    vector<int> nums = {-5, 2, 3, 4, 6};
    int target = 7;
    vector<int> resultado = sem(nums, target);

    for (int x : resultado){
        cout << x << " ";
    }

    return 0;
}