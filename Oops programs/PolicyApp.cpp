// Question 4 :

// Develop a program for an Insurance company
// Create a Menu driven program which takes “N” number of Policy details
// Policy class should have the following


	
//  Id
// 	 Number
// 	 Type
// 	 PremiumFee
// 	 PremiumMode [ Quarterly, Halfyearly, yearly ]


// 1. Add Policy details to the system and display all Policy details present in system
// 2. Display policies whose premium fee is less than or equal to given Amount for given Mode
// Example: If input is given as 5000 and Mode as “Quarterly”, display policies whose Premium Fee is less than or equal to 5000 with Mode as “Quarterly”
// 3. Sort policy details by Number and display all Policy details present in system
// 4. Update Premium Fee details for given Policy Number
// 5. Exit

/*
Pseudo code

1. create a poco for Policy class as a seperate module.
2. create another Policy array class to store dynamic array of objects and implementation of methods of policies.
3 implement add Policies function in Policy array class.
    i)prompt the user for the details of particular policy.
4. use selection sort to sort the array of policy objects.
5. print the policies having if fee less than given amount and mode  ny prompting input from user for fee and mode.
6. create a method to Update Premium Fee details for given Policy Number.
7. exit.

*/

#include <iostream>
#include"policyArray.h"
using namespace std;


long policyId;
string policyNum;
string policyType;
double premiumFee;
string premiumMode;
PolicyArray policyArray;

void addDetails(){
        cout<<"Enter policy ID:"<<endl;
        cin>>policyId;
        cout<<"Enter policy Number:"<<endl;
        cin>>policyNum;
        cout<<"Enter policy type:"<<endl;
        cin>>policyType;
        cout<<"Enter policy fee in INR:"<<endl;
        cin>>premiumFee;
        cout<<"Enter policy fee mode:"<<endl;
        cin>>premiumMode;
        policyArray.addPolicy(Policy(policyId,policyNum,policyType,premiumFee,premiumMode));
}

int main()
{
    int choice=0;
    cout<<"***************************** Welcome to Policy details Application *****************************"<<endl;
    do{
        cout<<"1. Add Policy details to the system and display all Policy details present in system"<<endl;
        cout<<"2. Display policies whose premium fee is less than or equal to given Amount for given Mode"<<endl;
        cout<<"3. Sort policy details by Number and display all Policy details present in system"<<endl;
        cout<<"4. Update Premium Fee details for given Policy Number"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your Choice:"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                addDetails();
                break;
            case 2:
                cout<<"*****************************Search By Price:*****************************"<<endl;
                cout<<"Enter the fee:"<<endl;
                cin>>premiumFee;
                cout<<"Enter the mode"<<endl;
                cin>>premiumMode;
                policyArray.printPolicysHavingLessThanGivenAmount(premiumFee,premiumMode);
                break;
            case 3:
                cout<<"*****************************Display all policies and details in sorted manner:*****************************"<<endl;
                policyArray.printPoliciesInSorted();
                break;
            case 4:
                cout<<"*****************************Update fee By policy Number:*****************************"<<endl;
                cout<<"Enter Policy Num:"<<endl;
                cin>>policyNum;
                cout<<"Enter the fee:"<<endl;
                cin>>premiumFee;
                policyArray.updatePoliciesForGivenNumber(policyNum,premiumFee);
                break;
            case 5:
                cout<<"***************************** Byeee have a great time ************************"<<endl;
                break;
            default:
                cout<<"***************************** Enter valid input ************************"<<endl;
                break;
        }
    }while(choice!=5);
}