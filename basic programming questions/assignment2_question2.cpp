// Given two input alphanumeric strings, write a program to segregate the strings into two separate strings with numbers in 1st string and characters in 2nd string removing duplicates. 

// Example:

// Input:

// String1 = Wel123come, String2 = 2Goodbye45

// Output:
// String1 = 12345, String2 = WelcomGdby

//  Pseudo code
//  First we are getting 2 strings as input
//  Concatenate them
//  Then take a temporary string variable
//  Iterate the loop until the length of concatenated string
//  Then check that particular character isdigit or ischar or not
//  If true then if the temporary string length is 0 then append it
//  Else iterate the temporary string to check if that element is already present
//  Keep the count
//  If the count is 0 after it has completed checking then append it

class person{
    string name;
    int height;
    int age;
};



#include<iostream>

using namespace std;

bool isNumber(char c){
    if((int)c>=48 && (int)c<=57){
        return true;
    }
    return false;
}

bool isChar(char c){
    if(((int)c>=65 && (int)c<=90) || ((int)c>=97 && (int)c<=122)){
        return true;
    }
    return false;
}

string stringNumberSegregate(string str1,string str2){
    str1+=str2;
    int count=0;
    // double conversion=(double)count;
    string output="";
    for(int i=0;i<str1.size();i++){
        if(isNumber(str1[i])){
            if(output.size()==0){
                output+=str1[i];
            }
            else{
                for(int j=0;j<output.size();j++){
                    if(str1[i]==output[j]){
                        count++;
                    }
                }
                if(count==0){
                    output+=str1[i];
                }
                count=0;
            }
        }
    }
    return output;
}

string stringCharacterSegregate(string str1,string str2){
    str1+=str2;
    int count=0;
    string output="";
    for(int i=0;i<str1.size();i++){
        if(isChar(str1[i])){
            if(output.size()==0){
                output+=str1[i];
            }
            else{
                for(int j=0;j<output.size();j++){
                    if(str1[i]==output[j]){
                        count++;
                    }
                }
                if(count==0){
                    output+=str1[i];
                }
                count=0;
            }
        }
    }
    return output;
}


int main(){ 
    string str1,str2,output1,output2;
    cout<<"enter string 1:"<<endl;
    cin>>str1;
    cout<<"enter string 2:"<<endl;
    cin>>str2;
    output1=stringNumberSegregate(str1,str2);
    cout<<"********************************"<<endl;
    output2=stringCharacterSegregate(str1,str2);

    cout<<output1<<" "<<output2<<endl;

    return 0;
}