#include <iostream>
using namespace std;

struct Array{
    int A[20];
    int size;
    int length;
};

void display(struct Array arr){
    for(int i=0 ; i<arr.length ; i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}

void append(struct Array *arr, int x){
    if((arr->length)<(arr->size)){
        arr->A[arr->length]=x;
        arr->length++;
    }
    else{
        cout<<"Array is full"<<endl;
    }
}

void insert(struct Array *arr, int index, int x){
    if(index>=0 && index<=(arr->length)){  
        for(int i=(arr->length) ; i>index ; i--){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
}

void Delete(struct Array *arr, int index){
    if(index>=0 && index<arr->length){
        int a = arr->A[index];
        for(int i= index; i<(arr->length); i++){
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
    }
}

int linearSearch(struct Array arr, int key){
    for(int i=0 ; i<arr.length ; i++){
        if(arr.A[i]==key){
            return i;
        }
    }
}

int iterativeBinarySearch(struct Array arr, int key){
    int l=0, h=arr.length-1;
    
    while(l<=h){
        int mid = (l+h)/2;

        if(arr.A[mid]==key){
            return mid;
        }
        else if(key<arr.A[mid]){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}

int recursiveBinarySearch(struct Array arr, int key, int l, int h){
    // int l=0, h=arr.length-1;
    if(l<=h){
        int mid = (l+h)/2;

        if(key==arr.A[mid]){
            return mid;
        }
        else if(key<arr.A[mid]){
            return recursiveBinarySearch(arr, key, l, mid-1);
        }
        else{
            return recursiveBinarySearch(arr, key, mid+1, h);
        }
        return -1;
    }
}

int get(struct Array arr, int index){
    if(index>=0 && index<arr.length){
        return arr.A[index];
    }
    return -1;
}

void set(struct Array *arr, int index, int a){
    if(index>=0 && index<arr->length){
        arr->A[index]=a;
    }
}

int max(struct Array arr){
    int m = arr.A[0];
    for(int i=1 ; i<arr.length; i++){
        if(arr.A[i]>m){
            m= arr.A[i];
        }
    }
    return m;
}

int min(struct Array arr){
    int m = arr.A[0];
    for(int i=1 ; i<arr.length; i++){
        if(arr.A[i]<m){
            m= arr.A[i];
        }
    }
    return m;
}

int sum(struct Array arr){
    int sum=0;
    for(int i=0 ; i<arr.length ; i++){
        sum+=arr.A[i];
    }
    return sum;
}

double avg(struct Array arr){
    double sum=0;
    for(int i=0 ; i<arr.length ; i++){
        sum+=arr.A[i];
    }
    return (sum/arr.length);
}

void reverse(struct Array *arr){
    //two pointer method to reverse an array
    int i=0, j=arr->length-1;
    while(i<j){
        swap(arr->A[i], arr->A[j]);
        i++;
        j--;
    }
}

void leftShift(struct Array *arr){
    for(int i=0 ; i<arr->length-1 ; i++){
        arr->A[i]=arr->A[i+1];
    }
    arr->A[arr->length-1]=0;
}

void rightShift(struct Array *arr){
    for(int i=arr->length-1 ; i>0 ; i--){
        arr->A[i]=arr->A[i-1];
    }
    arr->A[0]=0;
}

void leftRotate(struct Array *arr){
    int temp = arr->A[0];
    for(int i=0 ; i<arr->length-1 ; i++){
        arr->A[i]=arr->A[i+1];
    }
    arr->A[arr->length-1]=temp;
}

void rightRotate(struct Array *arr){
    int temp = arr->A[arr->length-1];
    for(int i=arr->length-1 ; i>0 ; i--){
        arr->A[i]=arr->A[i-1];
    }
    arr->A[0]=temp;
}

void insertInSortedArray(struct Array *arr, int a){
    int i= arr->length-1 ;
    while(arr->A[i]>a){
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=a;
    arr->length++;
}

bool isSorted(struct Array arr){
    for(int i=0 ; i<arr.length-1 ; i++){
        if(arr.A[i]>arr.A[i+1]){
            return false;
        }
    }
    return true;
}

int main(){

    struct Array arr = {{2,4,6,8,10},20,5};

    display(arr);
    append(&arr, 69);
    display(arr);
    insert(&arr, 5, 37);
    display(arr);
    Delete(&arr, 2);
    display(arr);
    cout<<linearSearch(arr, 37)<<endl;           
    cout<<iterativeBinarySearch(arr, 4)<<endl;           //NOTE: Array must be sorted
    cout<<recursiveBinarySearch(arr, 69, 0, 6)<<endl;    //NOTE: Array must be sorted
    cout<<get(arr, 3)<<endl;
    set(&arr, 3, 11);
    display(arr);
    cout<<max(arr)<<endl;
    cout<<min(arr)<<endl;
    cout<<sum(arr)<<endl;
    cout<<avg(arr)<<endl;
    reverse(&arr);
    display(arr);
    leftShift(&arr);
    display(arr);
    rightShift(&arr);
    display(arr);
    leftRotate(&arr);
    display(arr);
    struct Array arr2 = {{2,4,6,8,10},20,5};
    display(arr2);
    insertInSortedArray(&arr2, 7);
    display(arr2);
    cout<<isSorted(arr)<<endl;
    cout<<isSorted(arr2)<<endl;
    return 0;
}