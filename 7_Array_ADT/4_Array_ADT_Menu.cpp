#include <iostream>
using namespace std;

struct Array{
    int *A;
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

int Delete(struct Array *arr, int index){
    if(index>=0 && index<arr->length){
        int a = arr->A[index];
        for(int i= index; i<(arr->length); i++){
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;

        return a;
    }
}

int linearSearch(struct Array arr, int key){
    for(int i=0 ; i<arr.length ; i++){
        if(arr.A[i]==key){
            return i;
        }
    }
    return -1;
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
    return -1;
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

int isSorted(struct Array arr){
    for(int i=0 ; i<arr.length-1 ; i++){
        if(arr.A[i]>arr.A[i+1]){
            return false;
        }
    }
    return true;
}

int main(){

    struct Array arr ;
    cout<<"Enter the size of array: ";
    cin>>arr.size;
    arr.A = new int[arr.size];
    arr.length=0;
    // arr.A=(int*)malloc(arr.size*sizeof(int));


    int choice;
    do{
        cout<<"\n------------------------------------------------------------"<<endl;
        cout<<"MENU:"<<endl;
        cout<<"1)Display"<<endl;
        cout<<"2)Append"<<endl;
        cout<<"3)Insert"<<endl;
        cout<<"4)Delete"<<endl;
        cout<<"5)Linear Search"<<endl;
        cout<<"6)Binary Search (Iterative)"<<endl;
        cout<<"7)Binary Search(Recursive)"<<endl;
        cout<<"8)Get"<<endl;
        cout<<"9)Set"<<endl;
        cout<<"10)Max"<<endl;
        cout<<"11)Min"<<endl;
        cout<<"12)Sum"<<endl;
        cout<<"13)Average"<<endl;
        cout<<"14)Reverse Array"<<endl;
        cout<<"15)Leftshift"<<endl;
        cout<<"16)Rightshift"<<endl;
        cout<<"17)Leftrotate"<<endl;
        cout<<"18)Rightrotate"<<endl;
        cout<<"19)IsSorted"<<endl;
        cout<<"20)Insert in Sorted Array"<<endl;
        cout<<"------------------------------------------------------------\n"<<endl;

        cout<<"Enter choice: ";
        cin>>choice;
        int i,a,x;
        i=a=x=0;
        switch (choice)
        {
        case 1:
            display(arr);
            break;

        case 2:
            cout<<"Enter Element to append: ";
            cin>>a;
            append(&arr, a);
            display(arr);
            break;

        case 3:
            cout<<"Enter Element to insert: ";
            cin>>a;
            cout<<"Enter index: ";
            cin>>i;
            insert(&arr, i, a);
            display(arr);
            break;

        case 4:       
            cout<<"Enter index : ";
            cin>>i;
            x = Delete(&arr,i);
            cout<<"Deleted element is "<<x<<endl;
            display(arr);
            break;

        case 5:
            cout<<"Enter Element to search: ";
            cin>>a;
            x = linearSearch(arr, a);
            if(x!=-1){
                cout<<"Element found at index "<<x<<endl;
            }
            else{
                cout<<"Element not found"<<endl;
            }
            break;

        case 6:
            cout<<"Enter Element to search: ";
            cin>>a;
            x = iterativeBinarySearch(arr, a);
            if(x!=-1){
                cout<<"Element found at index "<<x<<endl;
            }
            else{
                cout<<"Element not found"<<endl;
            }
            break;

        case 7:
            cout<<"Enter Element to search: ";
            cin>>a;
            x = recursiveBinarySearch(arr, a, 0, arr.length-1);
            if(x!=-1){
                cout<<"Element found at index "<<x<<endl;
            }
            else{
                cout<<"Element not found"<<endl;
            }
            break;

        case 8:
            cout<<"Enter index to get: ";
            cin>>i;
            cout<<"Element at index "<<i<<": "<<get(arr, i);
            break;

        case 9:
            cout<<"Enter index to set: ";
            cin>>i;
            cout<<"Enter element: ";
            cin>>a;
            set(&arr, i,a);
            display(arr);
            break;

        case 10:
            cout<<"Maximum: "<<max(arr);
            break;
            

        case 11:
            cout<<"Minimum: "<<min(arr);
            break;

        case 12:
            cout<<"Sum: "<<sum(arr);
            break;

        case 13:
            cout<<"Average: "<<avg(arr);
            break;

        case 14:
            reverse(&arr);
            display(arr);
            break;

        case 15:
            leftShift(&arr);
            display(arr);
            break;

        case 16:
            rightShift(&arr);
            display(arr);
            break;

        case 17:
            leftRotate(&arr);
            display(arr);
            break;

        case 18:
            rightRotate(&arr);
            display(arr);
            break;

        case 19:
            if(isSorted(arr))
                cout<<"Array  is sorted"<<endl;
            else
                cout<<"Array is not sorted"<<endl;
            break;
        case 20:
            if(isSorted(arr)){
                cout<<"Enter element to insert: ";
                cin>>a;
                insertInSortedArray(&arr, a);
                display(arr);
            }     
            else
                cout<<"Array is not sorted"<<endl;
            break;

        case 21:
            cout<<"PROGRAM TERMINATED"<<endl;
            break;

        default:
            cout<<"Invalid choice"<<endl;
            cout<<"Please enter a valid choice"<<endl;
            break;
        }
    }while(choice!=21);
    
    delete[] arr.A;
    
    return 0;
}