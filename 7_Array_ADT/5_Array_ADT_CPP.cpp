#include <iostream>
using namespace std;

class Array{
    private:
        int *A;             // Pointer to the dynamic array
        int size;           // Capacity of the array
        int length;         // Number of elements present in the array

    public:
        Array(){                    // Default constructor
            size=10;
            length=0;
            A = new int[size];      // Dynamically allocate memory for the array
        }
        Array(int sz){              // Parameterized constructor
            size=sz;
            length=0;
            A = new int[size];      // Dynamically allocate memory for the array
        }
        ~Array(){
            delete []A;             // Destructor to free the dynamically allocated memory
        }
        int getLength() const {     // Getter function for the length of the array
            return length;          // Need this for getting length to use it in main function
        }
        void displayArray();                     // Display the elements of the array
        void append(int x);                 // Append an element to the end of the array
        void insert(int index, int x);      // Insert an element at a specified index in the array
        int Delete(int index);              // Delete an element at a specified index in the array
        int linearSearch(int key);          // Linear search for an element in the array
        int iterativeBinarySearch(int key);     // Iterative binary search for an element in the array
        int recursiveBinarySearch(int key, int l, int h);       // Recursive binary search for an element in the array
        int get(int index);                 // Get the element at a specified index in the array
        void set(int index, int a);         // Set the value of an element at a specified index in the array
        int max();                          // Find the maximum element in the array
        int min();                          // Find the minimum element in the array
        int sum();                          // Calculate the sum of all elements in the array
        double avg();                       // Calculate the average of all elements in the array
        void reverse();                     // Reverse the elements of the array
        void leftShift();                   // Shift all elements to the left (First Element is lost and last element is 0)
        void rightShift();                  // Shift all elements to the right (Last Element is lost and first element is 0)
        void leftRotate();                  // Rotate the array to the left
        void rightRotate();                 // Rotate the array to the right
        int isSorted();                     // Check if the array is sorted
        void insertInSortedArray(int a);    // Insert an element in a sorted array while maintaining the sorted order
};

void Array :: displayArray(){
    cout<<"\nArray: ";
    for(int i=0 ; i<length ; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void Array :: append(int x){
    if((length)<(size)){
        A[length]=x;
        length++;
    }
    else{
        cout<<"Array is full"<<endl;
    }
}

void Array :: Array :: insert(int index, int x){
    if(index>=0 && index<=(length)){  
        for(int i=(length) ; i>index ; i--){
            A[i]=A[i-1];
        }
        A[index]=x;
        length++;
    }
}

int Array :: Delete(int index){
    if(index>=0 && index<length){
        int a = A[index];
        for(int i= index; i<(length); i++){
            A[i]=A[i+1];
        }
        length--;

        return a;
    }
}

int Array :: linearSearch(int key){
    for(int i=0 ; i<length ; i++){
        if(A[i]==key){
            return i;
        }
    }
    return -1;
}

int Array :: iterativeBinarySearch(int key){
    int l=0, h=length-1;
    
    while(l<=h){
        int mid = (l+h)/2;

        if(A[mid]==key){
            return mid;
        }
        else if(key<A[mid]){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}

int Array :: recursiveBinarySearch(int key, int l, int h){
    // int l=0, h=length-1;
    if(l<=h){
        int mid = (l+h)/2;

        if(key==A[mid]){
            return mid;
        }
        else if(key<A[mid]){
            return recursiveBinarySearch(key, l, mid-1);
        }
        else{
            return recursiveBinarySearch(key, mid+1, h);
        }
        return -1;
    }
    return -1;
}

int Array :: get(int index){
    if(index>=0 && index<length){
        return A[index];
    }
    return -1;
}

void Array :: set(int index, int a){
    if(index>=0 && index<length){
        A[index]=a;
    }
}

int Array :: max(){
    int m = A[0];
    for(int i=1 ; i<length; i++){
        if(A[i]>m){
            m= A[i];
        }
    }
    return m;
}

int Array :: min(){
    int m = A[0];
    for(int i=1 ; i<length; i++){
        if(A[i]<m){
            m= A[i];
        }
    }
    return m;
}

int Array :: sum(){
    int sum=0;
    for(int i=0 ; i<length ; i++){
        sum+=A[i];
    }
    return sum;
}

double Array :: avg(){
    double sum=0;
    for(int i=0 ; i<length ; i++){
        sum+=A[i];
    }
    return (sum/length);
}

void Array :: reverse(){
    //two pointer method to reverse an array
    int i=0, j=length-1;
    while(i<j){
        swap(A[i], A[j]);
        i++;
        j--;
    }
}

void Array :: leftShift(){
    for(int i=0 ; i<length-1 ; i++){
        A[i]=A[i+1];
    }
    A[length-1]=0;
}

void Array :: rightShift(){
    for(int i=length-1 ; i>0 ; i--){
        A[i]=A[i-1];
    }
    A[0]=0;
}

void Array :: leftRotate(){
    int temp = A[0];
    for(int i=0 ; i<length-1 ; i++){
        A[i]=A[i+1];
    }
    A[length-1]=temp;
}

void Array :: rightRotate(){
    int temp = A[length-1];
    for(int i=length-1 ; i>0 ; i--){
        A[i]=A[i-1];
    }
    A[0]=temp;
}

void Array :: insertInSortedArray(int a){
    int i= length-1 ;
    while(A[i]>a){
        A[i+1]=A[i];
        i--;
    }
    A[i+1]=a;
    length++;
}

int Array :: isSorted(){
    for(int i=0 ; i<length-1 ; i++){
        if(A[i]>A[i+1]){
            return false;
        }
    }
    return true;
}

void displayMenu(){
        cout << "\n==========================================================================" << endl;
        cout << "                             MENU" << endl;
        cout << "==========================================================================" << endl;
        cout << "1. Display                         12. Sum" << endl;
        cout << "2. Append                          13. Average" << endl;
        cout << "3. Insert                          14. Reverse Array" << endl;
        cout << "4. Delete                          15. Left Shift" << endl;
        cout << "5. Linear Search                   16. Right Shift" << endl;
        cout << "6. Binary Search (Iterative)       17. Left Rotate" << endl;
        cout << "7. Binary Search (Recursive)       18. Right Rotate" << endl;
        cout << "8. Get                             19. Is Sorted" << endl;
        cout << "9. Set                             20. Insert in Sorted Array" << endl;
        cout << "10. Max                            21. EXIT" << endl;
        cout << "11. Min" << endl;
        // cout << "12. Sum" << endl;
        // cout << "13. Average" << endl;
        // cout << "14. Reverse Array" << endl;
        // cout << "15. Left Shift" << endl;
        // cout << "16. Right Shift" << endl;
        // cout << "17. Left Rotate" << endl;
        // cout << "18. Right Rotate" << endl;
        // cout << "19. Is Sorted" << endl;
        // cout << "20. Insert in Sorted Array" << endl;
        // cout << "21. EXIT" << endl;
        cout << "==========================================================================\n" << endl;
}

int main(){
    cout<<"\n---------------------------------------------"<<endl;
    cout<<"             ARRAY OPERATIONS"<<endl;
    cout<<"---------------------------------------------\n"<<endl;
    // Array arr1;
    int sz;
    cout<<"Enter the size of array: ";
    cin>>sz;
    Array arr1(sz);                     // Create an object of the Array class using parametrized constructor
    // arr1 = new Array(sz);

    int i,a,x;
    i=a=x=0;
    int choice;

    // Display the menu and handle user choices
    do{
        displayMenu();
        cout<<"Enter choice: ";
        cin>>choice;
        
        switch (choice)
        {
        case 1:
            arr1.displayArray();
            break;

        case 2:
            cout<<"Enter Element to append: ";
            cin>>a;
            arr1.append(a);
            arr1.displayArray();
            break;

        case 3:
            cout<<"Enter Element to insert: ";
            cin>>a;
            cout<<"Enter index: ";
            cin>>i;
            arr1.insert(i, a);
            arr1.displayArray();
            break;

        case 4:       
            cout<<"Enter index : ";
            cin>>i;
            x = arr1.Delete(i);
            cout<<"Deleted element is "<<x<<endl;
            arr1.displayArray();
            break;

        case 5:
            cout<<"Enter Element to search: ";
            cin>>a;
            x = arr1.linearSearch(a);
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
            x = arr1.iterativeBinarySearch(a);
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
            x = arr1.recursiveBinarySearch(a, 0, arr1.getLength()-1);
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
            cout<<"Element at index "<<i<<": "<<arr1.get(i);
            break;

        case 9:
            cout<<"Enter index to set: ";
            cin>>i;
            cout<<"Enter element: ";
            cin>>a;
            arr1.set(i,a);
            arr1.displayArray();
            break;

        case 10:
            cout<<"Maximum: "<<arr1.max();
            break;
            

        case 11:
            cout<<"Minimum: "<<arr1.min();
            break;

        case 12:
            cout<<"Sum: "<<arr1.sum();
            break;

        case 13:
            cout<<"Average: "<<arr1.avg();
            break;

        case 14:
            arr1.reverse();
            arr1.displayArray();
            break;

        case 15:
            arr1.leftShift();
            arr1.displayArray();
            break;

        case 16:
            arr1.rightShift();
            arr1.displayArray();
            break;

        case 17:
            arr1.leftRotate();
            arr1.displayArray();
            break;

        case 18:
            arr1.rightRotate();
            arr1.displayArray();
            break;

        case 19:
            if(arr1.isSorted())
                cout<<"Array  is sorted"<<endl;
            else
                cout<<"Array is not sorted"<<endl;
            break;
        case 20:
            if(arr1.isSorted()){
                cout<<"Enter element to insert: ";
                cin>>a;
                arr1.insertInSortedArray(a);
                arr1.displayArray();
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
    
    arr1.~Array();              // Calling the destructor to free the dynamically allocated memory
    
    return 0;
}