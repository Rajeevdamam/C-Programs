// Question 5: 

// Write a program to find out the largest and smallest word in the string. 

// Example: 

// Input: I am good boy. 

// Output: 

// Largest word is: good 

// Smallest word is: I 

#include<iostream>
#include<climits>

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

string *splitInput(string input,int len){
    int k=0;
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

int getLargestWord(string *splitArray,int len){
    int max=INT_MIN,index=0;
    for(int i=0;i<len;i++){
        int size=splitArray[i].size();
        if(size>max){
            max=splitArray[i].size();
            index=i;
        }
    }
    return index;
}

int getSmallestWord(string *splitArray,int len){
    int min=INT_MAX,index=0;
    for(int i=0;i<len;i++){
        int size=splitArray[i].size();
        if(size<min){
            min=splitArray[i].size();
            index=i;
        }
    }
    return index;
}

int main(){
    string input="";
    cout<<"Enter the sentence:"<<endl;
    getline(cin,input);
    int len=length(input);
    string *splitArray=new string[len];
    splitArray=splitInput(input,len);
    int largestWordIndex=getLargestWord(splitArray,len);
    int smallestWordIndex=getSmallestWord(splitArray,len);
    cout<<"Largest word is:"<<splitArray[largestWordIndex]<<endl;
    cout<<"Smallest word is:"<<splitArray[smallestWordIndex]<<endl;
}