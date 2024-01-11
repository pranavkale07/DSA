#include <iostream>
using namespace std;

int fact(int n){
    if(n==0){
        return 1;
    }
    else{
        return(fact(n-1)*n);
    }
}

int main(){
    int r;
    r=fact(6);
    cout<<r;
    return 0;
}