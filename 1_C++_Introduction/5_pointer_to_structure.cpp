#include <iostream>
using namespace std;

struct rectangle
{
    int length;
    int breadth;
};


int main(){

    // struct rectangle r={10,5};
    // rectangle r={10,5};     // in c++, we can define without writing 'struct'
    
    // cout<<r.length<<endl;
    // cout<<r.breadth<<endl;

    // rectangle *p = &r;

    rectangle *p;
    // p=(struct rectangle *)malloc(sizeof(struct rectangle)); // in c
    p=new rectangle;      // in c++

    p->length=21;
    p->breadth=7;

    cout<<p->length<<endl;
    cout<<p->breadth<<endl;

    return 0;
}