// Question 6 :
// Write a program to implement menu driven program for mobile store with the following attributes:
// Id, Model, Price, DateOfManufacture
// 1. Add Mobile details to the system and display all Mobile details present in system
// 2. Sort all the mobiles based on Model and display the details
// 3. Update Price for given mobile id and display the details
// 4. Delete mobile details for given mobile id
// 5. Exit
// Note : Model will be unique

/*
Pseudo code

1. create a poco for mobile class as a seperate module.
2. create another mobile showroon class to store dynamic array of objects of mobiles.
3 implement add mobiles function in MobileShowroom class.
    i)prompt the user for the details of particular mobile.
4. use selection sort to sort the array of mobile objects.
5. update the price of given mobile by id
6. delete the mobile by its id.
7. exit.


*/

#include <iostream>
#include "MobileShowroom.h"
using namespace std;


long mobile_id;
string dateOfManufacture;
double price;
string model;
MobileShowroom mobile;

void addDetails(){
        cout<<"Enter Mobile ID:"<<endl;
        cin>>mobile_id;
        cout<<"Enter Mobile Model:"<<endl;
        cin>>model;
        cout<<"Enter date of manufacture of Mobile:"<<endl;
        cin>>dateOfManufacture;
        cout<<"Enter Mobile Price in INR:"<<endl;
        cin>>price;
        mobile.addMobile(Mobile(mobile_id,model,dateOfManufacture,price));
}

int main()
{
    int choice=0;
    cout<<"***************************** Welcome to Mobile Application *****************************"<<endl;
    do{

        cout<<"Enter your Choice:"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                addDetails();
                break;
            case 2:
                cout<<"*****************************Search By Price:*****************************"<<endl;
                cout<<"Enter the price:"<<endl;
                double price;
                cin>>price;
                mobile.displayByPrice(price);
                break;
            case 3:
                cout<<"*****************************Update price By mobile ID:*****************************"<<endl;
                cout<<"Enter mobile ID:"<<endl;
                cin>>mobile_id;
                mobile.updatePrice(mobile_id);
                break;
            case 4:
                cout<<"*****************************Delete by mobile ID:*****************************"<<endl;
                cout<<"Enter mobile ID:"<<endl;
                cin>>mobile_id;
                mobile.deleteMobile(mobile_id);
                break;
            case 5:
                cout<<"*****************************Display all Phone and details in sorted manner:*****************************"<<endl;
                mobile.printAllMobileDetailsorted();
                break;
            case 6:
                cout<<"*****************************NO of Mobile phones avalilable:*****************************"<<endl;
                cout<<mobile.numberOfMobiles()<<endl;
                break;
            case 7:
                cout<<"***************************** Byeee have a great time ************************"<<endl;
                break;
            default:
                cout<<"***************************** Enter valid input ************************"<<endl;
                break;
        }
    }while(choice!=7);
}