#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frecuencia = {};

        for(int i=0; i<nums.size(); i++){
            frecuencia[nums.at(i)] += 1;
        }

        vector<pair<int, int>> frent = {};
        for(auto it = frecuencia.begin(); it != frecuencia.end(); it++ ){
            frent.push_back({it->first, it->second});
        }
        // Ordena de mayor a menor usando una función lambda
        //sort(frent.begin(), frent.end(), [](int a, int b) {
        //return a > b;});

        // Ordenar de mayor a menor por frecuencia
        sort(frent.begin(), frent.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });


        vector<int> result = {};

        for (int i=0; i<k; i++){
            result.push_back(frent.at(i).first);
        }
    

        return result;
    }

int main(){
    vector<int> nums = {1,1,1,2,2,3}; //output [1,2]

    vector<int> resultado = topKFrequent(nums, 2);

    for (int number : resultado){
        cout << number << " ";
    }


    return 0;
}


