#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int maxSubstring(string a){
    int low = 0;
    int hight = 0;
    int i = 0;
    unordered_set<char> windows = {};

    while (i<a.size()){

        windows.insert(a[i]);
        hight;

        while (low < hight){
            if (windows.find(a[low]) != windows.end()){
                windows.erase(a[low]);
                low++;
            } else {
                break;
            }
        }
        i++;
    }
    return windows.size();
}

int main(){
    string a = "pwwkew";
    cout << maxSubstring(a) << endl;
}