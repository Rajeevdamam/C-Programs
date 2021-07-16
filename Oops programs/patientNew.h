#include <iostream>
#include <string>

using namespace std;

class PatientNew{
    private:
        string patientName;
        short int age;
        string address;
        string disease;
        string doctorAssigned;
        short int room_no;
        string status;
        public:
            //Default constructor
            PatientNew(){

            }
            // Destructor
            ~PatientNew(){
                
            }

            PatientNew(string patientName,short int age,string disease,string address,string doctorAssigned,short int room_no,string status){
                this->patientName=patientName;
                this->age=age;
                this->disease=disease;
                this->address=address;
                this->doctorAssigned=doctorAssigned;
                this->room_no=room_no;
                this->status=status;
            }
            //get Patient Name
            string getPatientName(){
                return patientName;
            }
            //get age of the patient 
            short int getAge(){
                return age;
            }
            //get type of disease of Patient
            string getTypeOfDisease(){
                return disease;
            }
            //get address of patient
            string getAddress(){
                return address;
            }
            //get Patient doctorAssigned
            string getPatientDoctorAssigned(){
                return doctorAssigned;
            }

            short int getPatientRoomNo(){
                return room_no;
            }

            string getPatientStatus(){
                return status;
            }

            //set Patient Name
            void setPatientName(string patientName){
                this->patientName=patientName;
            }
            //set age of the patient
            void setAge(short int age){
                this->age=age;
            }   
            //set type of disease of Patient
            void setTypeOfDisease(string disease){
                this->disease=disease;
            }
            //set address of patient
            void setAddress(string address){
                this->address=address;
            }
            //set Patient doctorAssigned
            void setPatientDoctorAssigned(string doctorAssigned){
                this->doctorAssigned=doctorAssigned;
            }

            void setPatientRoomNo(short int room_no){
                this->room_no=room_no;
            }

            void setPatientStatus(string status){
                this->status=status;
            }

};