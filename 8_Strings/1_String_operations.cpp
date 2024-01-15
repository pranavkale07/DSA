#include <iostream>
#include <String>
using namespace std;


int length(string s){
    int i;
    for(i=0 ; s[i]!='\0' ; i++){

    }
    return i;
}

void toLower(string &s){
    for (int i = 0; i < s.length(); i++) {
        // Convert uppercase to lowercase by adding 32
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
    }
}

void toUpper(string &s){
    for (int i = 0; i < s.length(); i++) {
        // Convert uppercase to lowercase by adding 32
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= 32;
        }
    }
}

void switchCase(string &s){
    for (int i = 0; i < s.length(); i++) {
        // Convert uppercase to lowercase by adding 32
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= 32;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
    }
}

int wordCount(string s){
    int wCount=1;
    for(int i=0 ; i<s.length() ; i++){
        if(s[i]==' ' && s[i-1]!=' '){
            wCount++;
        }
    }
    return wCount;
}

int vowelCount(string s){
    int vCount=0;
    for(int i=0 ; i<s.length() ; i++){
        if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' ||
           s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            vCount++;
        }
    }
    return vCount;
}

int consonantCount(string s){
    int x = vowelCount(s);
    int cCount=0;
    for(int i=0 ; i<s.length() ; i++){
        if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)){
            cCount++;
        }
    }
    return cCount-x;
}

int validateString(string s){
    for(int i=0 ; i<s.length() ; i++){
        if(s[i]<65 || (s[i]>90 && s[i]<97) || s[i]>122){
            return 0;
        }
    }
    return 1;
}

string reverseString(string s){
    string rev= s;
    int i=0, j=rev.length()-1;
    while(i<j){
        swap(rev[i], rev[j]);
        i++;
        j--;
    }
    return rev;
}

bool isPalindrome(string s){
    toLower(s);
    if(s==reverseString(s)){
        return 1;
    }
    return 0;
}

int main(){
    char str1[]="Absolutely";
    string str2="PROGRAMMING";
    string str3="wElComE";
    string str4="Hello my name is elon";
    string str5="Malayalam";

    // cout<<"Length: "<<length(str1)<<endl;
    // toLower(str2);
    // cout<<str2<<endl;
    // toUpper(str2);
    // cout<<str2<<endl;
    // switchCase(str3);
    // cout<<str3<<endl;
    // cout<<wordCount(str4)<<endl;
    // cout<<vowelCount(str4)<<endl;
    // cout<<consonantCount(str4)<<endl;
    // cout<<validateString(str3)<<endl;
    cout<<reverseString(str3)<<endl;
    cout<<isPalindrome(str5)<<endl;

    return 0;
}