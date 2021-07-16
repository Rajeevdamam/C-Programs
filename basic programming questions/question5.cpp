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

/*

1. prompt the user for input sentence from the user without asking the length
2. prompt the user for input word to be searched
3. first find the number of words in the sentence.
4. split the sentence into array of strings and return the array
5. then write a function to search whether input 2 is present in the output array or not.


*/

#include<iostream>
#include <string>

using namespace std;

int length(string input) {
    int len = 1;
    if (input.size() == 0) {
        return 0;
    }
    for (int i = 0; i < input.size() - 1; i++) {
        if (input[i] == ' ' && isalpha(input[i + 1])) {
            len++;
        }
    }
    return len;
}



string* splitInput(string input) {
    int len = length(input), k = 0;
    string* out = new string[len];
    string temp;
    for (int i = 0; i < input.size(); i++) {
        while (input[i] != ' ' && i < input.size()) {
            temp += input[i];
            i++;
        }
        out[k++] = temp;
        temp = "";
    }
    return out;
}

string *insertionSort(string *input,int n){
    string temp="";
    string *output=new string[n];
    for(int i=0;i<n;i++){
        output[i]=input[i];
    }
    for(int i=1;i<n;i++){
        temp=output[i];
        for(int j=i-1;j>=0 && output[j]>temp;j--){
            output[j+1]=output[j];
            output[j]=temp;
        }
    }
    return output;
}

bool search(string* input, int arrayLen, string input2) {
    int low = 0, high = arrayLen - 1, mid = 0;
    while (low < high) {
        mid = ((low + high) + 1) / 2;
        if (input[mid] == input2) {
            return true;
        }
        else if (input2 > input[mid]) {
            low = mid + 1;
        }
        else if (input2 < input[mid]) {
            high = mid - 1;
        }
    }
    return false;
}


int main() {
    string input1, input2;
    cout<<"Enter the names of fruits "<<endl;
    getline(cin, input1);
    cout<<"Enter name of fruit you want to search "<<endl;
    cin >> input2;
    int arrayLen = length(input1);
    string* splitArray = new string[arrayLen];
    splitArray = splitInput(input1);

    if (search(splitArray, arrayLen, input2)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}