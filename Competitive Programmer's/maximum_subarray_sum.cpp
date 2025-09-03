#include <iostream>
#include <vector>
using namespace std;
#define ln "\n";

int main(){
    vector<int> array1 = {-1, 2, 4, -3, 5, 2, -5, 2};
    int n = array1.size();
    int best = 0, sum = 0;
    for (int k=0; k<n; k++){
        sum = max(array1[k], sum+array1[k]);
        best = max(best, sum);
    }

    cout << "The maximum sum of subarray is: " << best << ln;

    return 0;
}