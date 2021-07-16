#include <iostream>
#include <string>

using namespace std;

class Project{
    private:
        string projectId;
        string projectName;
        short int duration;
        public:
            Project(){

            }

            Project(string projectId,string projectName,short int duration){
                this->projectId=projectId;
                this->projectName=projectName;
                this->duration=duration;
            }
            
            //get Id
            string getProjectId(){
                return projectId;
            }
            //get Project name
            string getProjectName(){
                return projectName;
            }
            //get Project department
            short int getProjectDuration(){
                return duration;
            }
            
            //set Id
            void setProjectId(string projectId){
                this->projectId=projectId;
            }
            //set project name
            void setProjectName(string projectName){
                this->projectName=projectName;
            }
            //set project department
            void setProjectDuration(short int duration){
                this->duration=duration;
            }

};