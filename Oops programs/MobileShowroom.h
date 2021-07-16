#include <iostream>
#include "Mobile.h"
using namespace std;

class MobileShowroom{
    private:
        int count;
        int capacity;
        Mobile *mobileArray;
    public:
        MobileShowroom(){
            count=0;
            capacity=2;
            mobileArray=new Mobile[capacity];
        }
       
        int numberOfMobiles(){
            return count;
        }
       
        void addMobile(Mobile mobile){
            if(count==capacity){
                Mobile *newMobileArray=new Mobile[2*capacity];
                for(int i=0;i<capacity;i++){
                    newMobileArray[i]=mobileArray[i];
                }
                capacity*=2;
                mobileArray=newMobileArray;
                delete[] newMobileArray;
            }
            mobileArray[count++]=mobile;
            printAllMobileDetails();
        }
       
        Mobile* sort(Mobile *mobileArray,int count){
            Mobile *tempMobileArray=new Mobile[count];
            for(int i=0;i<count;i++){
                tempMobileArray[i]=mobileArray[i];
            }

            for(int i=0;i<count;i++){
                for(int j=i+1;j<count;j++){
                    if(tempMobileArray[i].getModel() >= tempMobileArray[j].getModel()){
                        Mobile temp=tempMobileArray[i];
                        tempMobileArray[i]=tempMobileArray[j];
                        tempMobileArray[j]=temp;
                    }
                }
            }
            return tempMobileArray;
        }

        void printAllMobileDetailsorted(){
            Mobile *tempMobileArray=new Mobile[count];
            tempMobileArray=sort(mobileArray,count);
            for(int i=0;i<count;i++){
                cout<<"*****************************************************************"<<endl;
                cout<<"Mobile ID:                               "<<tempMobileArray[i].getMobileId()<<endl;
                cout<<"Mobile Model:                            "<<tempMobileArray[i].getModel()<<endl;
                cout<<"Date Of Manufacture:                     "<<tempMobileArray[i].getDateOfManufacture()<<endl;
                cout<<"Mobile Price:                            "<<tempMobileArray[i].getPrice()<<endl;
                cout<<"*****************************************************************"<<endl;
            }
        }
       
       
        void printAllMobileDetails(){
            for(int i=0;i<count;i++){
                cout<<"*****************************************************************"<<endl;
                cout<<"Mobile ID:                               "<<mobileArray[i].getMobileId()<<endl;
                cout<<"Mobile Model:                            "<<mobileArray[i].getModel()<<endl;
                cout<<"Date Of Manufacture:                     "<<mobileArray[i].getDateOfManufacture()<<endl;
                cout<<"Mobile Price:                            "<<mobileArray[i].getPrice()<<endl;
                cout<<"*****************************************************************"<<endl;
            }
        }
       
        void displayByPrice(int price){
            bool flag=false;
            for(int i=0;i<count;i++){
                if(mobileArray[i].getPrice()<=price){
                    flag=true;
                    cout<<"*****************************************************************"<<endl;
                    cout<<"Mobile ID:                               "<<mobileArray[i].getMobileId()<<endl;
                    cout<<"Mobile Model:                            "<<mobileArray[i].getModel()<<endl;
                    cout<<"Date Of Manufacture:                     "<<mobileArray[i].getDateOfManufacture()<<endl;
                    cout<<"Mobile Price:                            "<<mobileArray[i].getPrice()<<endl;
                    cout<<"*****************************************************************"<<endl;
                }
            }
            if(flag==false)
                cout<<"No Mobiles available in the Range of given price:"<<endl;
        }
       
        void updatePrice(long mobile_id){
            double price;
            for(int i=0;i<count;i++){
                if(mobileArray[i].getMobileId()==mobile_id){
                    cout<<"*****************************************************************"<<endl;
                    cout<<"Enter Mobile Price: "<<endl;
                    cin>>price;
                    mobileArray[i].setPrice(price);
                    cout<<"*****************************************************************"<<endl;
                    cout<<"Updated results are:"<<endl;
                    cout<<"Mobile Model:                            "<<mobileArray[i].getModel()<<endl;
                    cout<<"Number of Sims Does The Mobile Have? :   "<<mobileArray[i].getDateOfManufacture()<<endl;
                    cout<<"Mobile Price:                            "<<mobileArray[i].getPrice()<<endl;
                    return;
                }
            }
            cout<<"No mobile of id "<<mobile_id<<" found"<<endl;
        }
       
        private:
        int search(int mobile_id){
             for(int i=0;i<count;i++){
                 if(mobileArray[i].getMobileId()==mobile_id){
                     return i;
                 }
             }
             return -1;
        }
        public:
        void deleteMobile(long mobile_id){
            int pos=search(mobile_id);
            if(pos!=-1){
                for(int i=pos;i<count-1;i++){
                    mobileArray[i]=mobileArray[i+1];
                }
                count--;
            }
            else{
                cout<<"Mobile not found"<<endl;
            }
        }
       
       
        ~MobileShowroom(){
            delete[] mobileArray;
        }
};
