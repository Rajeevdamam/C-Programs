/*

Hospital record: 
Create a patients record which includes name, number of days admitted, illness occurred, bill amount, doctor treated.
1. Add incoming patients
2. Delete outgoing patients
3. Display patients treated by particular illness
4. Display patients having same illness.
5. Display patient name who have billed lowest.
6. Exit


*/

/*

Pseudo Code:
1. Create a patient class that holds the properties/details of patients.
2. Create patients record class which is used to hold the array of patient details.
3. create a method in patients record to add the details of patients who are incoming.
    i) prompt the user for the details of the patients.
4. create a method in patient record that will delete the patient record if he/she is treated.
    i) delete if treated values is "yes" else dont.
5. create a method in patient record that will print all the patients who have been treated.
6. create a method in patient record that will print all the patients who have same illness.
    i) compare the illness of one parent with illness of another patient
7. create a method to find out the minimum billed patient and then print the details of that particular patient.
8. exit.




*/


#include<iostream>
#include "PatientRecords.cpp"
using namespace std;

string patientName,illness,treated;
short int numOfDaysAdmitted;
double billAmount;
PatientRecords patientRecords;

void addDetails(string patientName,short int numOfDaysAdmitted,string illness,double billAmount,string treated){
    cout<<"********* Add patient details **********"<<endl;
    cout<<"Enter patient Name:"<<endl;
    cin>>patientName;
    cout<<"Enter number of days Admitted:"<<endl;
    cin>>numOfDaysAdmitted;
    cout<<"Enter type of illness:"<<endl;
    cin>>illness;
    cout<<"Enter bill amount of patient:"<<endl;
    cin>>billAmount;
    cout<<"Is illness treated? "<<endl;
    cin>>treated;
    patientRecords.addPatient(Patient(patientName,numOfDaysAdmitted,illness,billAmount,treated));
    cout<<"*************************************************************"<<endl;
}

int main(){
    // string patientName,illness,treated;
    // short int numOfDaysAdmitted;
    // double billAmount;
    // PatientRecords patientRecords;
    int ch=0;
    cout<<"********************************Welcome To Hospital App*****************************"<<endl;
    do{
        cout<<"1. Add patient details\n2. Delete outgoing patients\n3. Display patients treated by particular illness\n4. Display patients having same illness\n5. Display patient name who have billed lowest.\n6. Exit"<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>ch;
        switch(ch){
            case 1: addDetails(patientName,numOfDaysAdmitted,illness,billAmount,treated);
                    break;

            case 2: cout<<"********* Delete outgoing patient record **********"<<endl;
                    patientRecords.deleteOutGoingPatientRecord();
                    cout<<"******************* Deleted! *********************"<<endl;
                    break;

            case 3: cout<<"********* Patients treated by particular illness **********"<<endl;
                    cout<<"Enter patient illness:"<<endl;
                    cin>>illness;
                    patientRecords.displayPatientTreatedByParticularIllness(illness);
                    cout<<"*************************************************************"<<endl;
                    break;

            case 4: cout<<"********* Patients having same illness **********"<<endl;
                    patientRecords.displayPatientHavingSameIllness();
                    cout<<"*************************************************************"<<endl;
                    break;

            case 5: cout<<"********* Patient who is being billed the lowest **********"<<endl;
                    patientRecords.displayPatientBilledLowest();
                    cout<<"*************************************************************"<<endl;
                    break;

            case 6: cout<<"************************** program exited ************************"<<endl;
                    break;

            default: cout<<"****************** Please Enter the Valid Input *******************"<<endl;
                     break;
        }

    }while(ch!=6);
}