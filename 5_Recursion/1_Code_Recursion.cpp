#include <iostream>
using namespace std;

void fun(int n){

    if(n>0){
        // cout<<n<<" ";          //executed at calling time 
        fun(n-1);
        cout<<n<<" ";            //executedd at returning time
    }
}

int main(){

    int x=3;
    fun(x);
    return 0;

}