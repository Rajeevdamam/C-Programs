#include <iostream>
#include <string>
#include "Policy.h"

using namespace std;

class PolicyArray{
    private:
        int size;
        Policy *policyArray;
        int capacity;
        public:
            PolicyArray(){
                size=0;
                capacity=2;
                policyArray=new Policy[capacity];
            }


            int getPolicyCount(){
                return size;
            }

            ~PolicyArray(){
                delete []policyArray;
            }

            void addPolicy(Policy policy){
                if(size==capacity){
                    Policy *tempPolicyArray=new Policy[2*capacity];
                    for(int i=0;i<capacity;i++){
                        tempPolicyArray[i]=policyArray[i];
                    }
                    capacity*=2;
                    policyArray=tempPolicyArray;
                    delete []tempPolicyArray;
                }
                policyArray[size++]=policy;
            }


            void updatePoliciesForGivenNumber(string number,double fee){
                Policy *tempPolicyArray=sort();
                for(int i=0;i<size;i++){
                    if(policyArray[i].getPolicyNum()==number){
                        cout<<"********* Policies before Update **********"<<endl;
                        cout<<"Policy Id:               "<<tempPolicyArray[i].getPolicyId()<<endl;
                        cout<<"Policy Number:           "<<tempPolicyArray[i].getPolicyNum()<<endl;
                        cout<<"Type of Policy:          "<<tempPolicyArray[i].getPolicyType()<<endl;
                        cout<<"Premium Fee Policy:      "<<tempPolicyArray[i].getPremiumFee()<<endl;
                        cout<<"Premium Mode of Policy:  "<<tempPolicyArray[i].getPremiumMode()<<endl;
                        tempPolicyArray[i].setPremiumFee(fee);
                        cout<<"**************** Policies after Update *************************"<<endl;
                        cout<<"Policy Id:               "<<tempPolicyArray[i].getPolicyId()<<endl;
                        cout<<"Policy Number:           "<<tempPolicyArray[i].getPolicyNum()<<endl;
                        cout<<"Type of Policy:          "<<tempPolicyArray[i].getPolicyType()<<endl;
                        cout<<"Premium Fee Policy:      "<<tempPolicyArray[i].getPremiumFee()<<endl;
                        cout<<"Premium Mode of Policy:  "<<tempPolicyArray[i].getPremiumMode()<<endl;
                    }
                }
            }
            
            void printPolicysHavingLessThanGivenAmount(double fee,string mode){
                Policy *tempPolicyArray=sort();
                for(int i=0;i<size;i++){
                    if(policyArray[i].getPremiumFee()<=fee && policyArray[i].getPremiumMode()==mode){
                        cout<<"********* Policys who have more than 3 projects **********"<<endl;
                        cout<<"Policy Id:               "<<tempPolicyArray[i].getPolicyId()<<endl;
                        cout<<"Policy Number:           "<<tempPolicyArray[i].getPolicyNum()<<endl;
                        cout<<"Type of Policy:          "<<tempPolicyArray[i].getPolicyType()<<endl;
                        cout<<"Premium Fee Policy:      "<<tempPolicyArray[i].getPremiumFee()<<endl;
                        cout<<"Premium Mode of Policy:  "<<tempPolicyArray[i].getPremiumMode()<<endl;
                        cout<<"***********************************************************"<<endl;
                    }
                }
            }

                


                Policy *sort(){
                    Policy *tempPolicyArray=new Policy[size];
                    for(int i=0;i<size;i++){
                        tempPolicyArray[i]=policyArray[i];
                    }
                    for(int i=0;i<size;i++){
                        for(int j=i+1;j<size;j++){
                            if(tempPolicyArray[i].getPolicyNum()>tempPolicyArray[j].getPolicyNum()){
                                Policy temp=tempPolicyArray[i];
                                tempPolicyArray[i]=tempPolicyArray[j];
                                tempPolicyArray[j]=temp;
                            }
                        }
                    }
                    return tempPolicyArray;
                }

                void printPoliciesInSorted(){
                Policy *tempPolicyArray=sort();
                for(int i=0;i<size;i++){
                        cout<<"********* Policys in sorted manner **********"<<endl;
                        cout<<"Policy Id:               "<<tempPolicyArray[i].getPolicyId()<<endl;
                        cout<<"Policy Number:           "<<tempPolicyArray[i].getPolicyNum()<<endl;
                        cout<<"Type of Policy:          "<<tempPolicyArray[i].getPolicyType()<<endl;
                        cout<<"Premium Fee Policy:      "<<tempPolicyArray[i].getPremiumFee()<<endl;
                        cout<<"Premium Mode of Policy:  "<<tempPolicyArray[i].getPremiumMode()<<endl;
                        cout<<"***********************************************************"<<endl;
                }
            }
                
};