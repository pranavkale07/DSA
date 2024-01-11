#include <iostream>
using namespace std;

int pow(int m, int n){
    if(n==0){
        return 1;
    }
    else{
        return(pow(m, n-1)*m);
    }
}

// We can write optimized power function (Consumes less time)
int pow1(int m, int n){
    if(n==0){
        return 1;
    }
    else if(n%2==0){
        return(pow1(m*m,(n/2)));
    }
    else{
        return(m*pow1(m*m,(n-1)/2));
    }
}

int main(){
    int r, r1;
    r=pow(2,5);
    cout<<r<<endl;

    r1=pow1(2,9);
    cout<<r1<<endl;
    return 0;
}