/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<climits>

using namespace std;

void swap(char &a,char &b){
    char temp=a;
    a=b;
    b=temp;
}

void reverse(string &str,int i,int j){
    while(i<j){
        swap(str[i],str[j]);
        i++;
        j--;
    }
}


string reverseString(string str) {
    int start=0,end=str.size()-1,idx=0;
    reverse(str,start,end);
    int i=0;
    while(i<end){
        if(str[i]==' '){
            i++;
            idx++;
        }
        else if(str[i]!=' ' ){
            i++;
            if(str[i+1]=='\0' || str[i+1]==' '){
                reverse(str,idx,i);
                idx=i+1;
                i++;
            }
        }
    }
    return str;
}

int main()
{   
    string str="     my    name     is          rajeev   ";
    string out=reverseString(str);
    cout<<"\""<<out<<"\"";
}
