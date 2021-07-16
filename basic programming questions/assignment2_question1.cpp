
// Question 1 :

// Write a program to read sentence as an user input and find the number of occurrence of a given string in the sentence.(Ignore the case sensitive) 

// Input : "Today is sunday, Its holiday"

// Substring : Day

// Output : 3


/*

pseudo code:

1. first take the input sentence from the user.
2. take the substring input from the user.
3. write a function to ignore case sensitive in a sentence and substring.
4. write a function to check number of times the substring is repeated in a string.
5. return the count and print it in main function.

*/

#include <iostream>
#include <string>
using namespace std;

int countTheOccurenceOfSubString(string input,string substr){
    int count=0,j=0,i=0;
    while(i<input.size()){
        while(substr[j]==input[i]){
            j++;
            i++;
            if(j==substr.size()){ 
                count++;
                break;
            }
        }
        if(j>0 && substr[j]!=input[i]  && i<input.size()){
            j=0;
        }
        i++;
    }
    return count;
}

string convertToLower(string input){
    string output="";
    for(int i=0;i<input.size();i++){
        if((int)input[i]>=65 && (int)input[i]<=90){
            output+=(input[i]+32);
        }
        else{
            output+=input[i];
        }
    }
    return output;
}

int main(){
    string input="",substr="";
    cout<<"Enter the sentence:"<<endl;
    getline(cin,input);
    cout<<"Enter the sub string:"<<endl;
    cin>>substr;
    input=convertToLower(input);
    substr=convertToLower(substr);
    cout<<countTheOccurenceOfSubString(input,substr);
    return 0;
}