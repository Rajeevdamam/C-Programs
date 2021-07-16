#include <iostream>
using namespace std;

class Mobile{
    private:
        long mobile_id;
        string model;
        string dateOfManufacture;
        double price;
        public:
            Mobile(){

            }

            Mobile(long mobile_id,string model,string dateOfManufacture,double price){
                this->mobile_id=mobile_id;
                this->model=model;
                this->dateOfManufacture=dateOfManufacture;
                this->price=price;
            }

            long getMobileId(){
                return mobile_id;
            }
            string getModel(){
                return model;
            }
            string getDateOfManufacture(){
                return dateOfManufacture;
            }
            double getPrice(){
                return price;
            }

            void setMobileId(long mobile_id){
                this->mobile_id=mobile_id;
            }
            void setModel(string model){
                this->model=model;
            }
            void setDateOfManufacture(string dateOfManufacture){
                this->dateOfManufacture=dateOfManufacture;
            }
            void setPrice(double price){
                this->price=price;
            }
};