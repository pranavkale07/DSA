#include <iostream>
using namespace std;

struct Array{
    int A[20];
    int length;
    int size=20;
};

void display(struct Array arr){
    for(int i=0 ; i<arr.length ; i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}

struct Array * unsortedUnion(struct Array *arr1, struct Array *arr2){
    int i,j;
    i=j=0;
    
    struct Array *arr3 = new Array;
    arr3->length = 0;
    for (int i = 0; i < arr1->length; i++) {
        arr3->A[arr3->length] = arr1->A[i];
        arr3->length++;
    }
    for (int i = 0; i < arr2->length; i++) {
        bool found = false;
        for (int j = 0; j < arr1->length; j++) {
            if (arr2->A[i] == arr1->A[j]) {
                found = true;
                break;
            }
        }

        if (!found) {
            arr3->A[arr3->length] = arr2->A[i];
            arr3->length++;
        }
    }
    return arr3;
};

struct Array * sortedUnion(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    
    struct Array *arr3 = new Array;
    arr3->length = 0;
    
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k]=arr1->A[i];
            i++;k++;
        }
        else if(arr2->A[j]<arr1->A[i]){
            arr3->A[k]=arr2->A[j];
            j++;k++;
        }
        else{
            arr3->A[k]=arr1->A[i];
            i++; j++;
            k++;
        }
    }
    while (i < arr1->length) {
        arr3->A[k] = arr1->A[i];
        i++;
        k++;
    }

    while (j < arr2->length) {
        arr3->A[k] = arr2->A[j];
        j++;
        k++;
    }
    arr3->length = k;
    arr3->size = 20;
    return arr3;
};

struct Array * intersection(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    
    struct Array *arr3 = new Array;
    arr3->length = 0;
    
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            i++;
        }
        else if(arr2->A[j]<arr1->A[i]){
            j++;
        }
        else if(arr2->A[j]==arr1->A[i]){
            arr3->A[k]=arr1->A[i];
            i++; j++;
            k++;
        }
    }
    arr3->length = k;
    arr3->size = 20;
    return arr3;
};

struct Array * difference(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    
    struct Array *arr3 = new Array;
    arr3->length = 0;
    
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k]=arr1->A[i];
            i++;k++;
        }
        else if(arr2->A[j]<arr1->A[i]){
            j++;
        }
        else{
            i++; j++;
        }
    }
    while (i < arr1->length) {
        arr3->A[k] = arr1->A[i];
        i++;
        k++;
    }

    while (j < arr2->length) {
        arr3->A[k] = arr2->A[j];
        j++;
        k++;
    }
    arr3->length = k;
    arr3->size = 20;
    return arr3;
};



int main(){
    struct Array arr1={{2,4,6,8,10,12},6,20};
    struct Array arr2={{3,4,5,6,7,8},6,20};
    display(arr1);
    display(arr2);

    struct Array *arr3 = unsortedUnion(&arr1, &arr2);
    display(*arr3);

    struct Array *arr4 = sortedUnion(&arr1, &arr2);
    display(*arr4);

    struct Array *arr5 = intersection(&arr1, &arr2);
    display(*arr5);

    struct Array *arr6 = difference(&arr1, &arr2);
    display(*arr6);

    return 0;;
}