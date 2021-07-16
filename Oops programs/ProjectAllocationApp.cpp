/*
Project Allocation: Write a menu driven program to manage projects and project allocation to different project managers.
Manager:
Id, Name, Department
Project:
Id, Name, Project-Duration
Validations:
1. Manager id will be according to the company standard (Example in Mindtree it must start from M)
2. Project duration must not be more than two years
3. Project id must start from PRJ.
4. Department can be from these 3 only be from (Digital/Testing/Cloud Services)
Operations:
1. Add a new manager to the company
2. Assign a new project to particular manager.
3. Delete the particular project with given project id .
4. Print the manager details having more than 3 projects.
5. Sort the manager list according to the manager name.
6. Exit
*/


/*
Pseudo Code:
1. create a class called Manager and create a POCO(Plain Old C++ object) class and create the getters, setters and Constructors in that class.
2. create a class called Project and create a POCO class getters, setters and Constructors in that class.
3. create a company class to store the projects assigned to a particular manager and manage the operations.
4. create a method in company class to add the Manager (the manager class shoild have his own attributes and also array of projects)
5. create a method to assign a project to a particular manager.
        i)prompt the user for manager name.
        ii)then add the project details to the manager.
6. create a method to delete a particualar project for a manager by project id.
        i)prompt the user for manager name and id.
        ii)then delete the project of that manager.
7. create a method to print manager details who have more than 3 projects.
        i)as we keep count of how many projects allocated to the mager we can print the manager details who has been assigned a project.
8. Sort the manager using selection sort by name.

*/

#include<iostream>
#include"ManagerArray.cpp"
using namespace std;

string managerName,managerId,projectId,projectName,managerDepartment;
short int duration;
Manager manager;
ManagerArray managerArray;

void addManagerDetails(string managerId,string managerName,string managerDepartment){
    cout<<"********* Add manager details **********"<<endl;
    cout<<"Enter manager Id:"<<endl;
    cin>>managerId;
    if(managerId[0]!='M'){
        cout<<"The Manager Id must start with 'M'"<<endl;
        cin>>managerId;
    }
    cout<<"Enter manager Name:"<<endl;
    cin>>managerName;
    cout<<"Enter manager department:"<<endl;
    cin>>managerDepartment;
    managerArray.addManager(Manager(managerId,managerName,managerDepartment));
    cout<<"*************************************************************"<<endl;
}

void addProject(string projectId, string projectName,short int duration){
        
        cout<<"********* Add project details **********"<<endl;

        cout<<"Enter project Id:"<<endl;
        cin>>projectId;
        if(projectId.size()<4 || (projectId[0]!='P' || projectId[1]!='R' || projectId[2]!='J')){
                cout<<"The Project Id must start with 'PRJ'"<<endl;
                cin>>projectId;
        }
        cout<<"Enter projectName:"<<endl;
        cin>>projectName;
        cout<<"Enter project duration:"<<endl;
        cin>>duration;
        managerArray.assignProjectToManager(Project(projectId,projectName,duration),managerName);
        cout<<"*************************************************************"<<endl;
}

int main(){
    int ch=0;
    cout<<"********************************Welcome To Comapny*****************************"<<endl;
    do{
        cout<<"1. Add a new manager to the company\n2. Assign a new project to particular manager.\n3. Delete the particular project with given project id .\n4. Print the manager details having more than 3 projects.\n5. Sort the manager list according to the manager name.\n6. Exit"<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>ch;
        switch(ch){
            case 1: addManagerDetails(managerId,managerName,managerDepartment);
                    break;

            case 2: cout<<"********* Assign project to Manager **********"<<endl;
                    addProject(projectId,projectName,duration);
                    cout<<"******************* Assigned! *********************"<<endl;
                    break;

            case 3: cout<<"********* Delete the particular project with given project id  **********"<<endl;
                    cout<<"Enter project Id:"<<endl;
                    cin>>projectId;
                    manager.deleteProject(projectId);
                    cout<<"*************************************************************"<<endl;
                    break;

            case 4: cout<<"********* Manager details having more than 3 project **********"<<endl;
                    managerArray.printManagersHavingMoreThanThreeProjects();
                    cout<<"*************************************************************"<<endl;
                    break;

            case 5: cout<<"********* Sort the manager list according to the manager name **********"<<endl;
                    Manager *tempManagerArray=managerArray.sort();
                    for(int i=0;i<managerArray.getManagerCount();i++){
                        cout<<"Manager Id:             "<<tempManagerArray[i].getManagerId()<<endl;
                        cout<<"Manager Name:           "<<tempManagerArray[i].getManagerName()<<endl;
                        cout<<"Department of Manager:  "<<tempManagerArray[i].getManagerDepartment()<<endl;
                        for(int j=0;j<manager.getNumOfProjects();j++){
                                cout<<"Project Id:             "<<tempManagerArray[i].getManagerId()<<endl;
                                cout<<"Project Name:           "<<tempManagerArray[i].getManagerName()<<endl;
                                cout<<"Project Duration of Manager:  "<<tempManagerArray[i].getManagerDepartment()<<endl;
                        }
                    }
                    cout<<"*************************************************************"<<endl;
                    break;

            case 6: cout<<"************************** program exited ************************"<<endl;
                    break;

            default: cout<<"****************** Please Enter the Valid Input *******************"<<endl;
                     break;
        }

    }while(ch!=6);
}

