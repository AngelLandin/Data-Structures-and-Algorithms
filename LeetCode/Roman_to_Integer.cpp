#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int romanToInt(string s) {
        unordered_map<char, int> numberRoman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
    
        int number = 0;
        for (int i=1; i<=s.size(); i++){
            if (i>0 && i<s.size() && numberRoman.at(s.at(i-1)) < numberRoman.at(s.at(i))){
                number = number + (numberRoman.at(s.at(i)) - numberRoman.at(s.at(i-1)));
                i++;
                
                
            }
            else {
                number += numberRoman.at(s.at(i-1));
            
            }
        }

        return number;
        
    }

int main(){
    string s1 = "III";
    string s = "MCMXCIV";
    string s3 = "LVIII";

    int number = romanToInt(s);
    int number2 = romanToInt(s1); 
    int number3 = romanToInt(s3); 

    cout << s << ": " << number <<endl;
    
    cout << s1 << ": " << number2 <<endl;

    cout << s3 << ": " << number3 <<endl;

    return 0;
}