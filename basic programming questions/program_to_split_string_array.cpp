// Question 5 :
// Write a program which take some fruits name as an input array and using binary search verify the given fruit is there or not.
// Input Validations:
// String to be verified (second input) should be in lowercase and it should not be Alphanumeric
// Example1:
// Input1: {apple, mango, banana}
// Input2: mango
// Output: Yes
// Example2:
// Input1: {apple, MANGO, banana}
// Input2: mango
// Output: No

#include<iostream>

using namespace std;

int length(string input){
    int len=1;
    if(input.size()==0){
        return 0;
    }
    for(int i=0;i<input.size()-1;i++){
        if(input[i]==' ' && isalpha(input[i+1])){
            len++;
        }
    }
    return len;
}

string *splitInput(string input){
    int len=length(input),k=0;
    string *out=new string[len];
    string temp;
    for(int i=0;i<input.size();i++){
        while(input[i]!=' ' && i<input.size()){
            temp+=input[i];
            i++;
        }
        out[k++]=temp;
        temp="";
    }
    return out;
}


int main(){
    string input;
    getline(cin,input);
    int len=length(input);
    string *splitArray=new string[len];
    splitArray=splitInput(input);
    for(int i=0;i<len;i++){
        cout<<splitArray[i]<<" ";
    }
}