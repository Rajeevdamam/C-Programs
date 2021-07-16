#include <iostream>
#include <climits>
#include <string>
#include "patientNew.h"

using namespace std;

class PatientRecords{
    private:
        int size;
        PatientNew *patientsArray;  
        int capacity;
        public:
            PatientRecords(){
                size=0;
                capacity=2;
                patientsArray=new PatientNew[capacity];
            }

            ~PatientRecords(){
                delete []patientsArray;
            }

            void addPatient(PatientNew patient){
                if(size==capacity){
                    PatientNew *tempPatientsArray=new PatientNew[2*capacity];
                    for(int i=0;i<capacity;i++){
                        tempPatientsArray[i]=patientsArray[i];
                    }
                    capacity*=2;
                    patientsArray=tempPatientsArray;
                    delete []tempPatientsArray;
                }
                patientsArray[size++]=patient;
            }

            void displayAllPatients(){
                for(int i=0;i<size;i++){
                        cout<<"***************Patient Records******************"<<endl;
                        cout<<"Patient Name:                    "<<patientsArray[i].getPatientName()<<endl;
                        cout<<"Patient Age:                     "<<patientsArray[i].getAge()<<endl;
                        cout<<"Patient Address:                 "<<patientsArray[i].getAddress()<<endl;
                        cout<<"Patient Disease:                 "<<patientsArray[i].getTypeOfDisease()<<endl;
                        cout<<"Doctor in charge for a patient:  "<<patientsArray[i].getPatientDoctorAssigned()<<endl;
                        cout<<"Room number for patient :        "<<patientsArray[i].getPatientRoomNo()<<endl;
                        cout<<"Patient status:                  "<<patientsArray[i].getPatientStatus()<<endl;
                } 
            }

            void updatePatientByName(string name){
                bool flag=0;
                short int age;
                string address;
                string disease;
                string doctorAssigned;
                short int room_no;
                string status;
                for(int i=0;i<size;i++){
                        if(patientsArray[i].getPatientName()== name){
                            flag=1;
                            cout<<"Enter Patient Age:                     "<<endl;
                            cin>>age;
                            patientsArray[i].setAge(age);
                            cout<<"Enter Patient Address:                 "<<endl;
                            cin>>address;
                            patientsArray[i].setAddress(address);
                            cout<<"Enter Patient Disease:                 "<<endl;
                            cin>>disease;
                            patientsArray[i].setTypeOfDisease(disease);
                            cout<<"Enter Doctor in charge for a patient:  "<<endl;
                            cin>>doctorAssigned;
                            patientsArray[i].setPatientDoctorAssigned(doctorAssigned);
                            cout<<"Enter Room number for patient :        "<<endl;
                            cin>>room_no;
                            patientsArray[i].setPatientRoomNo(room_no);
                            cout<<"Enter patient status:        "<<endl;
                            cin>>status;
                            patientsArray[i].setPatientStatus(status);
                            cout<<"***************Patient details after updation******************"<<endl;
                            cout<<"Patient Name:                    "<<patientsArray[i].getPatientName()<<endl;
                            cout<<"Patient Age:                     "<<patientsArray[i].getAge()<<endl;
                            cout<<"Patient Address:                 "<<patientsArray[i].getAddress()<<endl;
                            cout<<"Patient Disease:                 "<<patientsArray[i].getTypeOfDisease()<<endl;
                            cout<<"Doctor in charge for a patient:  "<<patientsArray[i].getPatientDoctorAssigned()<<endl;
                            cout<<"Room number for patient :        "<<patientsArray[i].getPatientRoomNo()<<endl;
                            cout<<"Patient status:                  "<<patientsArray[i].getPatientStatus()<<endl;
                            cout<<"**********************************************************"<<endl;
                        }
                    }
                if(flag==0){
                    cout<<"****************Patient Not Found******************"<<endl;
                }  
            } 

            private:

                int search(){
                    for(int i=0;i<size;i++){
                        if(patientsArray[i].getPatientStatus()=="cured"){
                            return i;
                        }
                    }
                    return -1;
                }


            public:

            void deleteOutGoingPatientRecord(){
                int isPresent=search();
                while(isPresent!=-1){
                    for(int i=isPresent;i<size-1;i++){
                        patientsArray[i]=patientsArray[i+1];
                    }
                    size--;
                }
            }

};