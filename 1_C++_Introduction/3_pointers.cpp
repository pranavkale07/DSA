#include <iostream>
using namespace std;

int main(){
    
    int a=10;
    // int *p;
    // p=&a;


    // cout<<a<<endl;
    // cout<<&a<<endl;
    // cout<<p<<endl;
    // cout<<*p<<endl;
    // cout<<&p<<endl;

    // int A[5]={1,2,3,4,5};
    // int *p;
    // p=A;
    // //p=&A[0]     (same)

    // for (int i = 0; i < 5; i++)
    // {
    //     // cout<<A[i]<<endl;
    //     cout<<p[i]<<endl;
    // }

    int *p;
    p=new int[5]; //memory in heap (i.e the array is created in heap)

    p[0]=7;
    p[1]=9;
    p[2]=14;
    p[3]=12;
    p[4]=21;

    for (int i = 0; i < 5; i++)
    {
        cout<<p[i]<<endl;
    }

    delete [] p;    //releasing the memory allocated in heap


    return 0;
}