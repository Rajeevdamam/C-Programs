#include <iostream>
#include <string>
#include "Project.cpp"

using namespace std;

class Manager{
    private:
        int size;
        string managerId;
        string managerName;
        string department;
        Project projectDetails;
        Project *projectsArray;
        int capacity;
        public:
            Manager(){
                size=0;
                capacity=2;
                projectsArray=new Project[capacity];
            }

            Manager(string managerId,string managerName,string department){
                this->managerId=managerId;
                this->managerName=managerName;
                this->department=department;
            }

            //get Id
            string getManagerId(){
                return managerId;
            }
            //get Manager name
            string getManagerName(){
                return managerName;
            }
            //get Manager duration
            string getManagerDepartment(){
                return department;
            }
            
            //set Id
            void setManagerId(string projectId){
                this->managerId=managerId;
            }
            //set Manager name
            void setManagerName(string managerName){
                this->managerName=managerName;;
            }
            //set Manager duration
            void setManagerDepartment(string department){
                this->department=department;
            }

            ~Manager(){
                delete []projectsArray;
            }

            int getNumOfProjects(){
                return size;
            }

            void addProject(Project project){
                if(size==capacity){
                    Project *tempProjectArray=new Project[2*capacity];
                    for(int i=0;i<capacity;i++){
                        tempProjectArray[i]=projectsArray[i];
                    }
                    capacity*=2;
                    projectsArray=tempProjectArray;
                    delete []tempProjectArray;
                }
                projectsArray[size++]=project;
            }

            
            
            

            private:
                int search(string projectId){
                    for(int i=0;i<size;i++){
                        if(projectsArray[i].getProjectId()==projectId){
                            return i;
                        }
                    }
                    return -1;
                }


            public:

            void deleteProject(string projectId){
                int searchResult=search(projectId);
                if(searchResult!=-1){
                    for(int i=searchResult;i<size-1;i++){
                        projectsArray[i]=projectsArray[i+1];
                    }
                    size--;
                }else{
                    cout<<"Product Not Found"<<endl;
                }
            }

};