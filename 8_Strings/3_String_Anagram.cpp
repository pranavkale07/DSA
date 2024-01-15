#include <iostream>
using namespace std;

// Basic approach of comparing if the character is present in other string
// Case-sensitive: The case of the character should be same
// Time-complexity : O(n^2)
// Doesn't work if duplicate letters present
bool isAnagram(string a, string b){
    if(a.length()!=b.length()){
        return false;
    }
    else{
        for(int i=0 ; i<a.length() ; i++){
            bool found = false;
            for(int j=0 ; j<b.length() ; j++){
                if(a[i]==b[j]){
                    found = true;
                    break;
                }
            }
            if(!found){
                return false;
            }
        }
        return true;
    }
}

// Optimized solition
// Time-complexity: O(n)
// Using hash table 
// Works even if duplicate letters present
bool isAnagram2(string a, string b){
    if(a.length()!=b.length()){
        return false;
    }
    else{
        int H[26]={0};
        for(int i=0 ; i<a.length() ; i++){
            H[a[i]-'a']+=1;
        }
        for(int j=0 ; j<b.length() ; j++){
            H[b[j]-'a']-=1;
            if(H[b[j]-'a']<0){
                return false;
            }
        }
        for(int k=0 ; k<26 ; k++){
            if(H[k]!=0){
                return false;
            }
        }
        return true;
    }
}

int main(){
    string s1="malayalam";
    string s2="laymamamm";

    if(isAnagram(s1, s2)){
        cout << "The strings are anagrams." << endl;
    }
    else{
        cout << "The strings are not anagrams." << endl;
    }

    if(isAnagram2(s1, s2)){
        cout << "The strings are anagrams." << endl;
    }
    else{
        cout << "The strings are not anagrams." << endl;
    }
    
    return 0;
}