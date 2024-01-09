#include <iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

int area(struct Rectangle r1){
    return(r1.length*r1.breadth);
}

void changeLength(struct Rectangle *p, int l){
    p ->length = l;
}

int main(){
    struct Rectangle r={10,5};
    cout<<area(r)<<endl;
    changeLength(&r,20);
    cout<<r.length<<" "<<r.breadth<<endl;
    return 0;
}