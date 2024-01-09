#include <iostream>
using namespace std;

int main(){
     
    int a=10;
    int &r=a;   //'r' is just another name for 'a' (nickname)

    cout<<a<<endl;
    cout<<r<<endl;
    cout<<&a<<endl;
    cout<<&r<<endl;

    r=25;    //when we change 'r', we actually change 'a' bcz 'r' is just another name of 'a'
    cout<<a<<endl;
    cout<<r<<endl;

    return 0;
}