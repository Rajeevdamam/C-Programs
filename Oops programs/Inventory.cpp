#include <iostream>
#include <string>
#include "Product.cpp"

using namespace std;

class Inventory{
    private:
        int size;
        Product *productsArray;
        int capacity;
        public:
            Inventory(){
                size=0;
                capacity=2;
                productsArray=new Product[capacity];
            }

            ~Inventory(){
                delete []productsArray;
            }

            void addProduct(Product product){
                if(size==capacity){
                    Product *tempProductArray=new Product[2*capacity];
                    for(int i=0;i<capacity;i++){
                        tempProductArray[i]=productsArray[i];
                    }
                    capacity*=2;
                    productsArray=tempProductArray;
                    delete []tempProductArray;
                }
                productsArray[size++]=product;
                product.setProductId(size);
            }

            void updateProduct(string name,int quantity){
                for(int i=0;i<size;i++){
                    if(productsArray[i].getProductName()==name){
                        cout<<"***************Before Update******************"<<endl;
                        cout<<"Product Id; "<<productsArray[i].getProductId()<<endl;
                        cout<<"Product Name; "<<productsArray[i].getProductName()<<endl;
                        cout<<"Product Quantity; "<<productsArray[i].getProductQuantity()<<endl;
                        cout<<"Product Price; "<<productsArray[i].getProductPrice()<<endl;
                        productsArray[i].setProductQuantity(quantity);
                        cout<<"***************Updated Results******************"<<endl;
                        cout<<"Product Id; "<<productsArray[i].getProductId()<<endl;
                        cout<<"Product Name; "<<productsArray[i].getProductName()<<endl;
                        cout<<"Product Quantity; "<<productsArray[i].getProductQuantity()<<endl;
                        cout<<"Product Price; "<<productsArray[i].getProductPrice()<<endl;
                        return;
                    }
                }
                cout<<"****************Product Not Found******************"<<endl;
            }

            void displayByQuantity(int quantity){
                for(int i=0;i<size;i++){
                    if(productsArray[i].getProductQuantity()==quantity){
                        cout<<"***************Product whose quantity less than specified******************"<<endl;
                        cout<<"Product Id; "<<productsArray[i].getProductId()<<endl;
                        cout<<"Product Name; "<<productsArray[i].getProductName()<<endl;
                        cout<<"Product Quantity; "<<productsArray[i].getProductQuantity()<<endl;
                        cout<<"Product Price; "<<productsArray[i].getProductPrice()<<endl;
                    }
                }
            } 

            private:
                int search(string productName){
                    for(int i=0;i<size;i++){
                        if(productsArray[i].getProductName()==productName){
                            return i;
                        }
                    }
                    return -1;
                }


                Product *sort(Product *productsArray){
                    Product *tempProductArray=new Product[size];
                    for(int i=0;i<size;i++){
                        tempProductArray[i]=productsArray[i];
                    }
                    for(int i=0;i<size;i++){
                        for(int j=i+1;j<size;j++){
                            if(tempProductArray[i].getProductQuantity()>tempProductArray[j].getProductQuantity()){
                                Product temp=tempProductArray[i];
                                tempProductArray[i]=tempProductArray[j];
                                tempProductArray[j]=temp;
                            }
                        }
                    }
                    return tempProductArray;
                }
            public:
            void displayProductsInSortedManner(){
                Product *tempProductArray=sort(productsArray);
                for(int i=0;i<size;i++){
                        cout<<"***************Product In Sorted manner based on quantity******************"<<endl;
                        cout<<"Product Id; "<<productsArray[i].getProductId()<<endl;
                        cout<<"Product Name; "<<productsArray[i].getProductName()<<endl;
                        cout<<"Product Quantity; "<<productsArray[i].getProductQuantity()<<endl;
                        cout<<"Product Price; "<<productsArray[i].getProductPrice()<<endl;
                }
            }

            void deleteProduct(string productName){
                int searchResult=search(productName);
                if(searchResult!=-1){
                    for(int i=searchResult;i<size-1;i++){
                        productsArray[i]=productsArray[i+1];
                    }
                    size--;
                }else{
                    cout<<"Product Not Found"<<endl;
                }
            }

};