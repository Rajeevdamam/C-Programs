#include <iostream>
#include <climits>
#include <string>
#include "Patient.cpp"

using namespace std;

class PatientRecords{
    private:
        int size;
        Patient *patientsArray;
        int capacity;
        public:
            PatientRecords(){
                size=0;
                capacity=2;
                patientsArray=new Patient[capacity];
            }

            ~PatientRecords(){
                delete []patientsArray;
            }

            void addPatient(Patient patient){
                if(size==capacity){
                    Patient *tempPatientsArray=new Patient[2*capacity];
                    for(int i=0;i<capacity;i++){
                        tempPatientsArray[i]=patientsArray[i];
                    }
                    capacity*=2;
                    patientsArray=tempPatientsArray;
                    delete []tempPatientsArray;
                }
                patientsArray[size++]=patient;
            }

            void displayPatientTreatedByParticularIllness(string illness){
                bool flag=0;
                for(int i=0;i<size;i++){
                    if(patientsArray[i].getTypeOfIllness()==illness && patientsArray[i].getIsPatientTreated()=="yes"){
                        flag=1;
                        cout<<"***************Patient Treated******************"<<endl;
                        cout<<"Patient Name:                        "<<patientsArray[i].getPatientName()<<endl;
                        cout<<"Number of Days Patient Admitted:     "<<patientsArray[i].getNumOfDaysAdmitted()<<endl;
                        cout<<"Patient Illness:                     "<<patientsArray[i].getTypeOfIllness()<<endl;
                        cout<<"Bill Amount of Patient:              "<<patientsArray[i].getBillAmount()<<endl;
                        cout<<"Is Patient Treated? :                "<<patientsArray[i].getIsPatientTreated()<<endl;
                    }
                }
                if(flag==0){
                    cout<<"****************Patient Not Found******************"<<endl;
                }  
            }

            void displayPatientHavingSameIllness(){
                bool flag=0;
                for(int i=0;i<size;i++){
                    for(int j=i+1;j<size;j++){
                        if(patientsArray[i].getTypeOfIllness()== patientsArray[j].getIsPatientTreated()){
                            flag=1;
                            cout<<"***************Patient 1 of same Illness******************"<<endl;
                            cout<<"Patient Name:                        "<<patientsArray[i].getPatientName()<<endl;
                            cout<<"Number of Days Patient Admitted:     "<<patientsArray[i].getNumOfDaysAdmitted()<<endl;
                            cout<<"Patient Illness:                     "<<patientsArray[i].getTypeOfIllness()<<endl;
                            cout<<"Bill Amount of Patient:              "<<patientsArray[i].getBillAmount()<<endl;
                            cout<<"Is Patient Treated? :                "<<patientsArray[i].getIsPatientTreated()<<endl;
                            cout<<"***************Patient 2 of same Illness******************"<<endl;
                            cout<<"Patient Name:                        "<<patientsArray[j].getPatientName()<<endl;
                            cout<<"Number of Days Patient Admitted:     "<<patientsArray[j].getNumOfDaysAdmitted()<<endl;
                            cout<<"Patient Illness:                     "<<patientsArray[j].getTypeOfIllness()<<endl;
                            cout<<"Bill Amount of Patient:              "<<patientsArray[j].getBillAmount()<<endl;
                            cout<<"Is Patient Treated? :                "<<patientsArray[j].getIsPatientTreated()<<endl;
                            cout<<"**********************************************************"<<endl;
                        }
                    }
                }
                if(flag==0){
                    cout<<"****************Patient Not Found******************"<<endl;
                }  
            } 

            private:
                int searchMin(){
                    int min=INT_MAX,index;
                    for(int i=0;i<size;i++){
                        if(patientsArray[i].getBillAmount()<min){
                            min=patientsArray[i].getBillAmount();
                            index=i;
                        }
                    }
                    return index;
                }

                int searchTreated(){
                    for(int i=0;i<size;i++){
                        if(patientsArray[i].getIsPatientTreated()=="yes"){
                            return i;
                        }
                    }
                    return -1;
                }


            public:
            void displayPatientBilledLowest(){
                int index= searchMin();
                cout<<"***************Bill of Patient who is being charged least******************"<<endl;
                cout<<"Patient Name:                        "<<patientsArray[index].getPatientName()<<endl;
                cout<<"Number of Days Patient Admitted:     "<<patientsArray[index].getNumOfDaysAdmitted()<<endl;
                cout<<"Patient Illness:                     "<<patientsArray[index].getTypeOfIllness()<<endl;
                cout<<"Bill Amount of Patient:              "<<patientsArray[index].getBillAmount()<<endl;
                cout<<"Is Patient Treated? :                "<<patientsArray[index].getIsPatientTreated()<<endl;
                cout<<"**********************************************************"<<endl;
            }

            void deleteOutGoingPatientRecord(){
                int isPresent=searchTreated();
                while(isPresent!=-1){
                    for(int i=isPresent;i<size-1;i++){
                        patientsArray[i]=patientsArray[i+1];
                    }
                    size--;
                    isPresent=searchTreated();
                }
            }

};