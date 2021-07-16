#include <iostream>
#include <string>

using namespace std;

class Policy{
    private:
        long policyId;
        string policyNum;
        string policyType;
        double premiumFee;
        string premiumMode;
        public:
            Policy(){

            }

            Policy(long policyId,string policyNum,string policyType,double premiumFee,string premiumMode){
                this->policyId=policyId;
                this->policyNum=policyNum;
                this->policyType=policyType;
                this->premiumFee=premiumFee;
                this->premiumMode=premiumMode;
            }
            
            long getPolicyId(){
                return policyId;
            }
            string getPolicyNum(){
                return policyNum;
            }
            string getPolicyType(){
                return policyType;
            }

            double getPremiumFee(){
                return premiumFee;
            }

            string getPremiumMode(){
                return premiumMode;
            }
            
            void setPolicyId(long policyId){
                this->policyId=policyId;
            }
            void setPolicyNum(string policyNum){
                this->policyNum=policyNum;
            }
            void setPolicyType(string policyType){
                this->policyType=policyType;
            }

            void setPremiumFee(double premiumFee){
                this->premiumFee=premiumFee;
            }

            void setPremiumMode(string premiumMode){
                this->premiumMode=premiumMode;
            }

};