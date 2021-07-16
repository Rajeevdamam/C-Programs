/*
Inventory Management
Write a menu driver program for inventory management where Product(id, name, quantity, price_per_unit).
1. Add new product in inventory.
2. Update the quantity of particular product.
3. Display products where quantity is less than provided by a user.
4. Display product sort on the basis of quantity.
5. Delete a particular product from inventory.
6. Exit
*/


/*
Pseudo Code:
1. create a class called product
2. set up the constructors, getters and setters in product class with given parameters.
3. set up inventory class which will have dynamic array of products.
4. create a method to add the product in inventory array.
    i) ask the details from the user.
    ii)add the product details to the inventory array.
5. create a method to make changes to the quantity of product.
    i) ask the quantity of a particular product that has to be changed in the inventory.
    ii) make the changes and add it to the inventory array.
6. create a method to display a product whose quantity is less provided by user.
    i) ask the user for the quantity of products that has to beek looked on if its is less than provided by the user.
7. Take a temporary array and assign all the products to it then sort(selection sort) the temp array on basis and return it.
8. Display product in sorted manner.
9. ask the user for which data must be deleted and then delete the particular product.

*/

#include<iostream>
#include "Inventory.cpp"
using namespace std;

string productName;
int quantity;
Inventory inventory;
int pricePerUnit;

void addDetails(string productName,int quantity,int price){
    cout<<"********* Add product to the inventory **********"<<endl;
    cout<<"Enter Product Name:"<<endl;
    cin>>productName;
    cout<<"Enter Product quantity:"<<endl;
    cin>>quantity;
    cout<<"Enter Product Price Per Unit:"<<endl;
    cin>>pricePerUnit;
    inventory.addProduct(Product(productName,quantity,pricePerUnit));
    cout<<"*************************************************************"<<endl;
}

void updateDetails(string productName,int quantity){
    cout<<"********* Update particular product by quantity **********"<<endl;
    cout<<"Enter Product Name:"<<endl;
    cin>>productName;
    cout<<"Enter Product quantity:"<<endl;
    cin>>quantity;
    inventory.updateProduct(productName,quantity);
    cout<<"*************************************************************"<<endl;
}

int main(){
    // string productName;
    // int quantity;
    // Inventory inventory;
    int pricePerUnit,ch;
    cout<<"********************************Welcome To Inventory App*****************************"<<endl;
    do{
        cout<<"1. Add product\n2. Upadte quantity of the product\n3. Display Product whose quantity less than specified\n4. Display product based on quantity in sorted manner\n5. Delete product from inventory."<<endl;
        cout<<"Enter your Choice:"<<endl;

        cin>>ch;
        switch(ch){
            case 1: addDetails(productName,quantity,pricePerUnit);
                    break;

            case 2: updateDetails(productName,quantity);
                    break;

            case 3: cout<<"********* Display Product whose quantity less than specified **********"<<endl;
                    cout<<"Enter Product quantity:"<<endl;
                    cin>>quantity;
                    inventory.displayByQuantity(quantity);
                    cout<<"*************************************************************"<<endl;
                    break;

            case 4: cout<<"********* Display Products in sorted manner of quantity **********"<<endl;
                    inventory.displayProductsInSortedManner();
                    cout<<"*************************************************************"<<endl;
                    break;

            case 5: cout<<"********* Delete a Product in an Inventory **********"<<endl;
                    cout<<"Enter Product Name:"<<endl;
                    cin>>productName;
                    inventory.deleteProduct(productName);
                    cout<<"*************************************************************"<<endl;
                    break;

            case 6: cout<<"********************* program exited *************************"<<endl;
                    break;

            default: cout<<"****************** Please Enter the Valid Input *******************"<<endl;
                     break;
        }
    }while(ch!=6);
}
