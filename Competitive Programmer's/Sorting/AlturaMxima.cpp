#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//Base (b) = Right- Left
//Area = b*h

int maxArea(vector<int>& height) {
    int l = 0;
    int r = height.size() - 1;
    int area = min(height.at(l), height.at(r) * (r-l)); // Area
    int b = r-l;
    while (l<r){
        if (area < b*height.at(r)){
            area = b*height.at(r);
            l++;
        } else{
            r--;
        }
    }

    return area;    
    }

int main(){


    return 0;

}
