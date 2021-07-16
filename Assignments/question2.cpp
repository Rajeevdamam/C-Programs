// Online C++ compiler to run C++ program online

// Write a program which takes an array of numbers from user and then sort those numbers using insertion sort and take out prime numbers if it’s there in array.
// Note : The prime numbers in subset should also be in sorted manner.
// Input: {9,2,89,7,15}
// Output: {2,7,9,15,89}
// Prime sorted subset array : {2,7,89}



/*
psuedo code

1. take the size and array input from the user.
2. sort the array using insertion sort.
    i) insertion sort is done by taking one element to compare.
    ii) if the element at index i-1 is greater than the new element to be added then shift that element to right and insert the element and so on.
3. print all the prime numbers in the sorted array.





*/



#include <iostream>
using namespace std;


int *insertionSort(int *a,int n){
    int temp;
    int *output=new int[n];
    for(int i=0;i<n;i++){
        output[i]=a[i];
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

void printPrimeNumbers(int *a,int n){
    int isPrime=0;
    for(int i=0;i<n;i++){
        for(int j=2;j<a[i];j++){
            if(a[i]%j==0){
                isPrime=1;
                break;
            }
        }
        if(isPrime==0){
            cout<<a[i]<<" ";
        }
        isPrime=0;
    }
}



int main2() {
    int arraySize;
    cout<<"enter number of elements you want to store in an array:"<<endl;
    cin>>arraySize;
    int *input=new int[arraySize];
    cout<<"enter elements you want to store in an array:"<<endl;
    for(int i=0;i<arraySize;i++){
        cin>>input[i];
    }
    int *output=insertionSort(input,arraySize);
    for(int i=0;i<arraySize;i++){
        cout<<output[i]<<" ";
    }
    cout<<endl;
    printPrimeNumbers(output,arraySize);
    return 0;
}