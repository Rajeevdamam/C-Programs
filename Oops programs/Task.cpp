#include <iostream>
#include <string>

using namespace std;

class Task{
    private:
        long id;
        string description;
        string assignedTo;
        string status;
        public:
            Task(long id,string description,string assignedTo,string status){
                this->id=id;
                this->description=description;
                this->assignedTo=assignedTo;
                this->status=status;
                // cout<<"Values assigned:"<<this->id<<endl;
                // cout<<"Values assigned:"<<this->description<<endl;
                // cout<<"Values assigned:"<<this->assignedTo<<endl;
                // cout<<"Values assigned:"<<this->status<<endl;
            }
            Task(){
                
            }
            void setId(long id){
                this->id=id;
            }
            void setDescription(string description){
                this->description=description;
            }
            void setAssignedTo(string assignedTo){
                this->assignedTo=assignedTo;
            }
            void setStatus(string status){
                this->status=status;
            }
            
            long getId(){
                return id;
            }
            string getDescription(){
                return description;
            }
            string getAssignedTo(){
                return assignedTo;
            }
            string getStatus(){
                return status;
            } 
            
};