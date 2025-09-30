#include <iostream>
using namespace std;

int initCycle(int x){
    int last = 0;
    int square = 0;
    while (x>0){
        last = x%10;
        x = x/10;
        square += last*last;
    }
    return square;
}


bool isHappyNumber(int n){
    int s = n;
    int f = n;

    while(true){
        s = initCycle(s);
        f = initCycle(initCycle(f));

        if (f == 1) return true;

        if (f == s) return false;
    }
}


int main(){
    bool isHappy = isHappyNumber(126);

    cout << "Is Happy number?: " << isHappy << endl;
    return 0;
}