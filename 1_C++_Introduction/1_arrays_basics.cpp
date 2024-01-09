#include <iostream>
using namespace std;

int main(){    

    int A[5]={7,9,5,4,3};

    cout<<sizeof(A)<<endl;
    cout<<A[0]<<endl;
    cout<<A[1]<<endl;
    cout<<A[2]<<endl;
    printf("%d",A[2]);
    cout<<endl;


    //********Printing the array using for loop************
    for(int i=0; i<5; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

    //*********Printing the array using for-each loop***********
    for(int x:A){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}