#include <iostream>
using namespace std;

// void swap(int *x, int *y){
//     int temp;
//     temp=*x;
//     *x=*y;
//     *y=temp;

//     // return(x,y);
    
// }

// int main(){
//     int a, b;
//     a=10;
//     b=21;

//     cout<<"a="<<a<<endl;
//     cout<<"b="<<b<<endl;

//     swap(&a,&b);
//     cout<<"a="<<a<<endl;
//     cout<<"b="<<b<<endl;


//     return 0;
// }

void swap(int &x, int &y){
    int temp;
    temp=x;
    x=y;
    y=temp;

    // return(x,y);
    
}

int main(){
    int a, b;
    a=10;
    b=21;

    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;

    swap(a,b);
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;


    return 0;
}