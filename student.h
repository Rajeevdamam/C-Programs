#include <iostream>
#include <string>

using namespace std;

class Student{
    private:
        string studentId;
        string studentName;
        short int age;
        string standard;
        string address;
        public:
            //Default constructor
            Student(){

            }
            // Destructor
            ~Student(){
                
            }

            Student(string studentId,string studentName,short int age,string address,string standard){
                this->studentId=studentId;
                this->studentName=studentName;
                this->age=age;
                this->address=address;
                this->standard=standard;
            }
            //get student Name
            string getStudentName(){
                return studentName;
            }
            //get age of the student 
            short int getAge(){
                return age;
            }
            
            //get address of student
            string getAddress(){
                return address;
            }
            //get student standard
            string getStudentStandard(){
                return standard;
            }

            string getStudentId(){
                return studentId;
            }



            //set student Name
            void setStudentName(string studentName){
                this->studentName=studentName;
            }
            //set age of the student
            void setAge(short int age){
                this->age=age;
            }   
            //set address of student
            void setAddress(string address){
                this->address=address;
            }
            //set student standard
            void setStudentStandard(string standard){
                this->standard=standard;
            }

            void setStudentId(string studentId){
                this->studentId=studentId;
            }


};