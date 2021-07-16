// Question 3: 

// If the input array is [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60], your program should be able to find that the subarray lies between the indexes 3 and 8. Also should print minimum and maximum element of array. 

// Output : [30, 25, 40, 32, 31, 35] 


#include<iostream>
#include<climits>

using namespace std;

int *arrayBetweenRange(int *input,int start,int end){
    int outArraySize=end-start,k=0;
    int *output=new int[outArraySize];
    for(int i=start;i<=end;i++){
        output[k++]=input[i];
    }
    return output;
}

void minAndMaxOfResultantArray(int *input,int size){
    int max=INT_MIN,min=INT_MAX;
    for(int i=0;i<size;i++){
        if(input[i]>max){
            max=input[i];
        }
        if(input[i]<min){
            min=input[i];
        }
    }
    cout<<"Min of resultant Array"<<min<<endl;
    cout<<"Max of resultant Array"<<max<<endl;
}



int main(){
    int numElements=0,start=0,end=0;
    cout<<"enter number of elements in an array:"<<endl;
    cin>>numElements;
    int *input=new int[numElements];
    cout<<"enter elements of the array:"<<endl;
    for(int i=0;i<numElements;i++){
        cin>>input[i];
    }
    cout<<"enter start and end points of the array:"<<endl;
    cin>>start>>end;
    int outArraySize=end-start;
    if(end==numElements){
        end--;
    }
    int *output=new int[outArraySize];
    output=arrayBetweenRange(input,start,end);
    for(int i=0;i<outArraySize;i++){
        cout<<output[i]<<" ";
    }
    minAndMaxOfResultantArray(output,outArraySize);
}