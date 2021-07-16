// Question 1 :
// Take two 1D arrays as user input and subtract the 1st array from 2nd array .
// Create a new array with all the negative numbers from the resultant array
// Input:
// Array 1 : {10,67,1}
// Array 2 : {16,8,90}
// Output:
// Resultant array {-6,59,-89}
// Array with negative numbers {-6,-89}

/*
1. take the array size (n1 and n2) input from the user.
2. take the array inputs for both the arrays.
3. iterate both the arrays at once and subtract.
4. if the sizes are different the take the maximum of two sizes and append zeros to the array which has the lowest size.
5. store the results in resultant array
6. store the negative values in seperate array.
7. return and print the reultant array

*/


#include<iostream>
// #define max(a,b) (a>b)?a:b

using namespace std;

int* negativeValuedArray(int *array1,int n1,int *array2,int n2){
    int maxLength=max(n1,n2);
    int *resultArray=new int[maxLength];
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        resultArray[k++]=(array1[i]-array2[j]);
        i++;j++;
    }
    while(i<n1){
        resultArray[k++]=array1[i];
        i++;
    }
    while(j<n2){
        resultArray[k++]=array2[j];
        j++;
    }
    return resultArray;
}

int main(){
    int n1,n2;
    cout<<"Enter n1 and n2"<<endl;
    cin>>n1>>n2;
    int *array1=new int[n1];
    int *array2=new int[n2];
    cout<<"Enter array1 inputs"<<endl;
    for(int i=0;i<n1;i++){
        cin>>array1[i];
    }
    cout<<"Enter array2 inputs"<<endl;
    for(int i=0;i<n2;i++){
        cin>>array2[i];
    }
    int *res=new int[max(n1,n2)];
    
    res=negativeValuedArray(array1,n1,array2,n2);
    for(int i=0;i<max(n1,n2);i++){
        if(res[i]<0){
            cout<<res[i]<<" ";
        }
    }
    return 0;
}