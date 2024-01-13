#include <iostream>
using namespace std;

struct Array{
    int A[20];
    int length;
    int size=20;
};

struct Array* merge(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;

    struct Array *arr3 = new Array;

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k]=arr1->A[i];
            i++;
            k++;
        }
        else{
            arr3->A[k]=arr2->A[j];
            j++;
            k++;
        }
    }
    for( ; i<arr1->length ; i++){
        arr3->A[k]=arr1->A[i];
        k++;
    }
    for( ; j<arr2->length ; j++){
        arr3->A[k]=arr2->A[j];
        k++;
    }

    arr3->length = arr1->length + arr2->length ;
    arr3->size = 20;

    return arr3;
}

void display(struct Array arr){
    for(int i=0 ; i<arr.length ; i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}

int main(){
    struct Array arr1={{3,8,16,20,25},5,20};
    struct Array arr2={{4,10,12,22,23},5,20};
    display(arr1);
    display(arr2);

    struct Array *arr3 = merge(&arr1, &arr2);
    display(*arr3);


    return 0;
}