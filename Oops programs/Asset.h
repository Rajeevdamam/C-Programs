#include <iostream>
#include <string>

using namespace std;

class Asset{
    private:
        long serialNo;
        string assetModel;
        string assetAlloted;
        short int assetQuantity;
        
        public:
            Asset(){

            }

            Asset(long serialNo,string assetModel,string assetAlloted,short int assetQuantity ){
                this->serialNo=serialNo;
                this->assetModel=assetModel;
                this->assetAlloted=assetAlloted;
                this->assetQuantity=assetQuantity;
            }
            
            long getSerialNo(){
                return serialNo;
            }
            string getAssetModel(){
                return assetModel;
            }
            string getAssetAlloted(){
                return assetAlloted;
            }

            short int getAssetQuantity(){
                return assetQuantity;
            }

            
            void setSerialNo(long serialNo){
                this->serialNo=serialNo;
            }
            void setAssetModel(string assetModel){
                this->assetModel=assetModel;
            }
            void setAssetAlloted(string assetAlloted){
                this->assetAlloted=assetAlloted;
            }

            void setAssetQuantity(short int assetQuantity){
                this->assetQuantity=assetQuantity;
            }


};