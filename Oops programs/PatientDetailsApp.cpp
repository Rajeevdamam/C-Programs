/*

Question 2: 

Write a menu driven program to implement patient Hospital Management system such that each patient will have following attributes: name, age, address, disease and doctor in-charge, room no allocated. 

Implement the below options: 

Add a new Patient Record when admitted. 

Edit/Update Patient Details. 

List all the Patient Records.                                                   

Delete Patient Record when discharged. 

*/

/*

Pseudo Code:
1. Create a patient class that holds the properties/details of patients.
2. Create patients record class which is used to hold the array of patient details.
3. create a method in patients record to add the details of patients who are incoming.
    i) prompt the user for the details of the patients.
4. create a method in patient record that will delete the patient record if he/she is cured.
    i) delete if treated values is "yes" else dont.
5. create a method in patient record that will print all the patients.
6. create a method in patient record that update the details of patient.
    i) take patient name as consideration.
8. exit.




*/


#include<iostream>
#include "PatientNewArray.h"
using namespace std;

string patientName;
short int age;
string address;
string disease;
string doctorAssigned;
short int room_no;
string status;
PatientRecords patientNewArray;

void addDetails(){
    cout<<"********* Add patient details **********"<<endl;
    cout<<"Enter patient Name:"<<endl;
    cin>>patientName;
    cout<<"Enter Patient Age:                     "<<endl;
    cin>>age;
    cout<<"Enter Patient Address:                 "<<endl;
    cin>>address;
    cout<<"Enter Patient Disease:                 "<<endl;
    cin>>disease;
    cout<<"Enter Doctor in charge for a patient:  "<<endl;
    cin>>doctorAssigned;
    cout<<"Enter Room number for patient :        "<<endl;
    cin>>room_no;
    cout<<"Enter patient status:        "<<endl;
    cin>>status;
    if(status!="cured" && status!="ill"){
        cout<<"Enter patient status as 'cured or ill':        "<<endl;
        cin>>status;
    }
    patientNewArray.addPatient(PatientNew(patientName,age,address,disease,doctorAssigned,room_no,status));
    cout<<"*************************************************************"<<endl;
}

int main(){
    int ch=0;
    cout<<"********************************Welcome To Patient Details App*****************************"<<endl;
    do{
        cout<<"1. Add a new Patient Record when admitted. s\n2. Edit/Update Patient Details. \n3. List all the Patient Records.\n4. Delete Patient Record when discharged.\n5. Exit"<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>ch;
        switch(ch){
            case 1: addDetails();
                    break;

            case 2: cout<<"********* Update patient details **********"<<endl;
                    cout<<"Enter patient Name:"<<endl;
                    cin>>patientName;
                    patientNewArray.updatePatientByName(patientName);
                    cout<<"*************************************************************"<<endl;
                    break;

            case 3: cout<<"*********Display all Patients **********"<<endl;
                    patientNewArray.displayAllPatients();
                    cout<<"*************************************************************"<<endl;
                    break;

            case 4: 

                    cout<<"********* Delete outgoing patient record **********"<<endl;
                    patientNewArray.deleteOutGoingPatientRecord();
                    cout<<"******************* Deleted! *********************"<<endl;
                    break;


            case 5: cout<<"************************** program exited ************************"<<endl;
                    break;

            default: cout<<"****************** Please Enter the Valid Input *******************"<<endl;
                     break;
        }

    }while(ch!=5);
}