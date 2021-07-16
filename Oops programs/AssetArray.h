#include <iostream>
#include <string>
#include "Asset.h"

using namespace std;

class AssetArray{
    private:
        int size;
        Asset *assetArray;
        int capacity;
        public:
            AssetArray(){
                size=0;
                capacity=2;
                assetArray=new Asset[capacity];
            }


            int getAssetCount(){
                return size;
            }

            ~AssetArray(){
                delete []assetArray;
            }

            void addAsset(Asset asset){
                if(size==capacity){
                    Asset *tempAssetArray=new Asset[2*capacity];
                    for(int i=0;i<capacity;i++){
                        tempAssetArray[i]=assetArray[i];
                    }
                    capacity*=2;
                    assetArray=tempAssetArray;
                    delete []tempAssetArray;
                }
                assetArray[size++]=asset;
            }


            void updateAssetForGivenModel(long serialNo,string model,short int quantity){
                for(int i=0;i<size;i++){
                    if(assetArray[i].getAssetModel()==model && assetArray[i].getSerialNo()==serialNo){
                        cout<<"********* Assets before Update **********"<<endl;
                        cout<<"Asset serial Number:               "<<assetArray[i].getSerialNo()<<endl;
                        cout<<"Asset Model:                       "<<assetArray[i].getAssetModel()<<endl;
                        cout<<"When was the asset alloted:        "<<assetArray[i].getAssetAlloted()<<endl;
                        cout<<"Asset quantity:                    "<<assetArray[i].getAssetQuantity()<<endl;
                        assetArray[i].setAssetQuantity(quantity);
                        cout<<"**************** Policies after Update *************************"<<endl;
                        cout<<"Asset serial Number:               "<<assetArray[i].getSerialNo()<<endl;
                        cout<<"Asset Model:                       "<<assetArray[i].getAssetModel()<<endl;
                        cout<<"When was the asset alloted:        "<<assetArray[i].getAssetAlloted()<<endl;
                        cout<<"Asset quantity:                    "<<assetArray[i].getAssetQuantity()<<endl;
                    }
                }
            }
            
            void printTotalQuantityAllotedForModel(string model){
                int totalQuantity=0;
                for(int i=0;i<size;i++){
                    if(assetArray[i].getAssetModel()==model){
                        totalQuantity+=assetArray[i].getAssetQuantity();
                    }
                }
                cout<<"Total quantity for a model: "<<model<<" is:"<<totalQuantity<<endl;
            }

                


                Asset *sort(string month){
                    Asset *tempAssetArray=new Asset[size];
                    for(int i=0;i<size;i++){
                        tempAssetArray[i]=assetArray[i];
                    }
                    for(int i=0;i<size;i++){
                        for(int j=i+1;j<size;j++){
                            if(tempAssetArray[i].getAssetModel()>tempAssetArray[j].getAssetModel() && tempAssetArray[i].getAssetAlloted()==month){
                                Asset temp=tempAssetArray[i];
                                tempAssetArray[i]=tempAssetArray[j];
                                tempAssetArray[j]=temp;
                            }
                        }
                    }
                    return tempAssetArray;
                }

                void searchAndPrintInSortedManner(string month){
                    printAllAssetsInSorted(month);
                }


                private:
                void printAllAssetsInSorted(string month){
                    Asset *tempAssetArray=sort(month);
                    for(int i=0;i<size;i++){
                        cout<<"********* Assets details **********"<<endl;
                        cout<<"Asset serial Number:               "<<tempAssetArray[i].getSerialNo()<<endl;
                        cout<<"Asset Model:                       "<<tempAssetArray[i].getAssetModel()<<endl;
                        cout<<"When was the asset alloted:        "<<tempAssetArray[i].getAssetAlloted()<<endl;
                        cout<<"Asset quantity:                    "<<tempAssetArray[i].getAssetQuantity()<<endl;
                        cout<<"***********************************************************"<<endl;
                    }
                }

                public:
                void printAllAssets(){
                    for(int i=0;i<size;i++){
                        cout<<"********* Assets details **********"<<endl;
                        cout<<"Asset serial Number:               "<<assetArray[i].getSerialNo()<<endl;
                        cout<<"Asset Model:                       "<<assetArray[i].getAssetModel()<<endl;
                        cout<<"When was the asset alloted:        "<<assetArray[i].getAssetAlloted()<<endl;
                        cout<<"Asset quantity:                    "<<assetArray[i].getAssetQuantity()<<endl;
                        cout<<"***********************************************************"<<endl;
                    }
                }
                
};