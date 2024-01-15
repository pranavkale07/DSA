//Finding duplicate elements in a string using bitwise operations
//Masking - Checking if a particular bit is on or off.
#include <iostream>
using namespace std;

int main(){
    string s="finding";
    int H=0, x=0;

    for(int i=0 ; i<s.length() ; i++){
        x=1;
        x=x<<(s[i]-'a');

        if((H & x)>0){                                          // (H & x) - Masking
            cout<<"Duplicate element: "<<s[i]<<endl;
        }
        else{
            H = H | x ;                                         // (H | x) - Merging
        }
    }
    return 0;
}