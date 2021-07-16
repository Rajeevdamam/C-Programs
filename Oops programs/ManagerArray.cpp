#include <iostream>
#include <string>
#include "Manager.cpp"

using namespace std;

class ManagerArray{
    private:
        int size1;
        Project projectDetails;
        Manager *managerArray;
        int capacity;
        public:
            ManagerArray(){
                size1=0;
                capacity=2;
                managerArray=new Manager[capacity];
            }


            int getManagerCount(){
                return size1;
            }

            ~ManagerArray(){
                delete []managerArray;
            }

            void addManager(Manager manager){
                if(size1==capacity){
                    Manager *tempManagerArray=new Manager[2*capacity];
                    for(int i=0;i<capacity;i++){
                        tempManagerArray[i]=managerArray[i];
                    }
                    capacity*=2;
                    managerArray=tempManagerArray;
                    delete []tempManagerArray;
                }
                managerArray[size1++]=manager;
            }

            

            void assignProjectToManager(Project project,string managerName){
                for(int i=0;i<size1;i++){
                    if(managerArray[i].getManagerName()==managerName){
                        managerArray[i].addProject(project);
                    }
                }
            }
            
            void printManagersHavingMoreThanThreeProjects(){
                Manager *tempManagerArray=sort();
                for(int i=0;i<size1;i++){
                    if(managerArray[i].getNumOfProjects()>3){
                        cout<<"********* Managers who have more than 3 projects **********"<<endl;
                        cout<<"Manager Id:             "<<tempManagerArray[i].getManagerId()<<endl;
                        cout<<"Manager Name:           "<<tempManagerArray[i].getManagerName()<<endl;
                        cout<<"Department of Manager:  "<<tempManagerArray[i].getManagerDepartment()<<endl;
                        cout<<"***********************************************************"<<endl;
                    }
                }
            }

                // int search(string projectId){
                //     for(int i=0;i<size;i++){
                //         if(projectsArray[i].getProjectId()==projectId){
                //             return i;
                //         }
                //     }
                //     return -1;
                // }


                Manager *sort(){
                    Manager *tempManagerArray=new Manager[size1];
                    for(int i=0;i<size1;i++){
                        tempManagerArray[i]=managerArray[i];
                    }
                    for(int i=0;i<size1;i++){
                        for(int j=i+1;j<size1;j++){
                            if(tempManagerArray[i].getManagerName()>tempManagerArray[j].getManagerName()){
                                Manager temp=tempManagerArray[i];
                                tempManagerArray[i]=tempManagerArray[j];
                                tempManagerArray[j]=temp;
                            }
                        }
                    }
                    return tempManagerArray;
                }

                
};