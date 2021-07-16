// Question 5 : 

// Implement menu driven program for tracking the Assets allotted
// Asset class should have the following


	
//  Sno
// 	 Model [ HP , Lenovo , Dell ]
// 	 AllottedMonth -> Should be taken 3 letter word Eg : JAN/FEB ..
// 	 Quantity


// 1. Add asset details to the system and display all asset details
// 2. Search assets for given Month and sort the data by Model
// Example : If input is provided as FEB, it should display details of all assets allotted in the month of FEB sorted by Model
// 3. Display total quantity allotted for given Model
// Example : If input is provided as ‘HP’ display total quantity allotted by summing up all months
// 4. Update Quantity for given Model and display the updated details
// 5. Exit


/*

1. create a class asset using poco format with all its attributes, getters and setters.
2. create another class called asset array to store array of assets using dynamic array concept and also to implement various methods.
3. create a method to add all the asset details into object array.
    i) prompt the user for details of assets and then add it to asset array.
4. create a method to sort the assets accoring to month and model specified by the suer using selevtion sort.
5. create a method to print the sum of the quantity of models for a given model.
6. create a method to update the quantity of a given model and display the changes.



*/

#include <iostream>
#include"AssetArray.h"
using namespace std;


long serialNo;
string assetModel;
string assetAlloted;
short int assetQuantity;
AssetArray assetArray;

bool validateModel(string model){
    if(model=="HP" ||model=="Lenovo" || model=="Dell"){
        return true;
    }
    return false;
}

void addDetails(){
        cout<<"Enter Asset Serial Number:"<<endl;
        cin>>serialNo;
        cout<<"Enter Asset model:"<<endl;
        cin>>assetModel;
        if(!validateModel(assetModel)){
            cout<<"Asset model should be either [ HP , Lenovo , Dell ]:"<<endl;
            cin>>assetModel;
        }
        cout<<"Enter when the asset was alloted:"<<endl;
        cin>>assetAlloted;
        if(assetAlloted.size()<3 || assetAlloted.size()>3){
            cout<<"Enter valid asset alloted(should contain 3 letter word such as jan feb):"<<endl;
            cin>>assetAlloted;
        }
        cout<<"Enter asset quantity:"<<endl;
        cin>>assetQuantity;
        assetArray.addAsset(Asset(serialNo,assetModel,assetAlloted,assetQuantity));
}

int main()
{
    int choice=0;
    cout<<"***************************** Welcome to Asset details Application *****************************"<<endl;
    do{
        cout<<"1. Add asset details to the system and display all asset details"<<endl;
        cout<<"2. Search assets for given Month and sort the data by Model"<<endl;
        cout<<"3. Display total quantity allotted for given Model"<<endl;
        cout<<"4. Update Quantity for given Model and display the updated details"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your Choice:"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                addDetails();
                break;
            case 2:
                cout<<"*****************************Search Asset By Month:*****************************"<<endl;
                cout<<"Enter the asset month alloted"<<endl;
                cin>>assetAlloted;
                assetArray.searchAndPrintInSortedManner(assetAlloted);
                break;
            case 3:
                cout<<"*****************************Display total quantity of assets for model:*****************************"<<endl;
                cout<<"Enter Asset model:"<<endl;
                cin>>assetModel;
                assetArray.printTotalQuantityAllotedForModel(assetModel);
                break;
            case 4:
                cout<<"*****************************Update asset quantity By Asset model:*****************************"<<endl;
                cout<<"Enter Asset Serial Number:"<<endl;
                cin>>serialNo;
                cout<<"Enter Asset model:"<<endl;
                cin>>assetModel;
                cout<<"Enter asset quantity:"<<endl;
                cin>>assetQuantity;
                assetArray.updateAssetForGivenModel(serialNo,assetModel,assetQuantity);
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