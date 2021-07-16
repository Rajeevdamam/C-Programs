#include <iostream>
#include <string>

using namespace std;

class Product{
    private:
        long productId;
        string productName;
        int quantity;
        int price;
        public:
            Product(){

            }

            Product(string productName,int quantity,int price){
                this->productId=0;
                this->productName=productName;
                this->quantity=quantity;
                this->price=price;
            }
            
            // Product(long productId,string productName,int quantity,int price){
            //     this->productId=productId;
            //     this->productName=productName;
            //     this->quantity=quantity;
            //     this->price=price;
            // }
            //get Id
            long getProductId(){
                return productId;
            }
            //get product name
            string getProductName(){
                return productName;
            }
            //get product quantity
            int getProductQuantity(){
                return quantity;
            }
            //get product price
            int getProductPrice(){
                return price;
            }
            //set Id
            void setProductId(long productId){
                this->productId=productId;
            }
            //set product name
            void setProductName(string productName){
                this->productName=productName;
            }
            //set product quantity
            void setProductQuantity(int quantity){
                this->quantity=quantity;
            }
            //get product price
            void setProductPrice(int price){
                this->price=price;
            }

};