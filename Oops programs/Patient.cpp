#include <iostream>
#include <string>

using namespace std;

class Patient{
    private:
        string patientName;
        short int numOfDaysAdmitted;
        string illness;
        double billAmount;
        string treated;
        public:
            //Default constructor
            Patient(){

            }
            // Destructor
            ~Patient(){
                
            }

            Patient(string patientName,short int numOfDaysAdmitted,string illness,double billAmount,string treated){
                this->patientName=patientName;
                this->numOfDaysAdmitted=numOfDaysAdmitted;
                this->illness=illness;
                this->billAmount=billAmount;
                this->treated=treated;
            }
            //get Patient Name
            string getPatientName(){
                return patientName;
            }
            //get number of days the patient is admitted
            short int getNumOfDaysAdmitted(){
                return numOfDaysAdmitted;
            }
            //get type of illness of Patient
            string getTypeOfIllness(){
                return illness;
            }
            //get Bill amount of patient
            double getBillAmount(){
                return billAmount;
            }
            //get is Patient Treated
            string getIsPatientTreated(){
                return treated;
            }
            //set Patient Name
            void setPatientName(string patientName){
                this->patientName=patientName;
            }
            //set number of days the patient is admitted
            void setNumOfDaysAdmitted(){
                this->numOfDaysAdmitted=numOfDaysAdmitted;
            }   
            //set type of illness of Patient
            void setTypeOfIllness(){
                this->illness=illness;
            }
            //set Bill amount of patient
            void setBillAmount(){
                this->billAmount=billAmount;
            }
            //get is Patient Treated
            void setIsPatientTreated(){
                this->treated=treated;
            }

};