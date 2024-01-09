#include <iostream>
using namespace std;

    // formal parameters
int add(int a, int b){
    int c;
    c=a+b;
    return c;
}

int main(){
    int num1=10, num2=21, sum;
    
        // actual parameters
    sum=add(num1,num2);
    cout<<"Sum is: "<<sum<<endl;

    return 0;
}