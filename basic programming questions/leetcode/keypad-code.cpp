/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

string keys[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

vector<string> keypad(int n){
    if(n==0){
        vector<string> out;
        out.push_back("");
        return out;
    }
    vector<string> smallout=keypad(n/10);
    vector<string> out;
    for(int i=0;i<smallout.size();i++){
        for(int j=0;j<keys[n%10].length();j++){
            out.push_back(smallout[i]+keys[n%10][j]);
        }
    }
    return out;
}

int main()
{
    int num=345;
    vector<string> out=keypad(num);
    for (int i = 0; i < out.size(); i++) {
        cout<<out[i]<<" ";
    }
}
