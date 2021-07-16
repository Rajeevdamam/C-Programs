// Question 4 :
// Take sentence as an user input and find the vowels in the sentence and replace the next consonant letter of the vowels with its next ASCII character.
// Example1:
// Input: I am good boy
// Output: I an gooe boz
// Example2:
// Input: I an gooe boz
// Output: I ao goof boa

#include<iostream>
#include <string>
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

bool isVowel(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
        return true;
    }
    return false;
}

string *replaceConsonant(string input,int len){
    string *output=new string[len];
    string temp;
    int k=0;
    for(int i=0;i<input.size();i++){
        while(input[i]!=' ' && i<input.size()-1){
            temp+=input[i];
            if(isVowel(input[i]) && input[i+1]!=' ' && !isVowel(input[i+1])){
                int chr=input[i+1];
                if(chr%122==0){
                    chr=97;
                }
                else if(chr%90==0){
                    chr=65;
                }
                else{
                    chr+=1;
                }
                temp+=(char)chr;
                i++;
            }
            i++;
        }
        output[k++]=temp;
        temp="";
    }
    return output;
}



int main(){
    string input;
    getline(cin,input);
    int len=length(input);
    string *output=new string[len];
    output=replaceConsonant(input,len);
    for(int i=0;i<len;i++){
        cout<<output[i]<<endl;
    }
}