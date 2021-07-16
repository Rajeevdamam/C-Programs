// Question 1 

 

 

// a.. Every student has following details: id, name, age, standard (i.e., class) and address 

// 2. Update student details  

// a. This option should allow user to update either one of following details: address and age 

// 3. Delete user details 

// a. This option to delete student details from the record 

// 4. Display user details 

// a. Display student details based on ID 

// b. Display student details based on Name  

// d. Display user sorted based on standard 

// e. Display users sorted based on class. 

// 5. Exit 


#include<iostream>
#include "StudentArray.h"
using namespace std;

string studentId;
string studentName;
short int age;
string standard;
string address;
StudentArray studentArray;

void addDetails(){
    cout<<"********* Add patient details **********"<<endl;
    cout<<"Enter Student Id:"<<endl;
    cin>>studentId;
    cout<<"Enter Student Name:"<<endl;
    cin>>studentName;
    cout<<"Enter Student Age:                     "<<endl;
    cin>>age;
    cout<<"Enter Student Address:                 "<<endl;
    cin>>address;
    cout<<"Enter Student standard:                 "<<endl;
    cin>>standard;
    studentArray.addStudent(Student(studentId,studentName,age,address,standard));
    cout<<"*************************************************************"<<endl;
}

int main(){
    int ch=0;
    cout<<"********************************Welcome To Student Details App*****************************"<<endl;
    do{
        cout<<"1. Add a new Student Record. s\n2. Edit/Update Student Details. \n3. Delete user details \n4. 4. Display user details \na. Display student details based on ID \nb. Display student details based on Name  \nd. Display user sorted based on standard \ne. Display users sorted based on class. \n5. Exit"<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>ch;
        switch(ch){
            case 1: addDetails();
                    break;

            case 2: cout<<"********* Update Student details **********"<<endl;
                    char choice='a';
                    case 'a':patientNewArray.updatePatientByName(patientName);
                    
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