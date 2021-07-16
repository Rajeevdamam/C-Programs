#include <iostream>
#include <string>
#include "student.h"

using namespace std;

class StudentArray{
    private:
        int size;
        Student *studentArray;  
        int capacity;
        public:
            StudentArray(){
                size=0;
                capacity=2;
                studentArray=new Student[capacity];
            }

            ~StudentArray(){
                delete []studentArray;
            }

            void addStudent(Student student){
                if(size==capacity){
                    Student *tempstudentArray=new Student[2*capacity];
                    for(int i=0;i<capacity;i++){
                        tempstudentArray[i]=studentArray[i];
                    }
                    capacity*=2;
                    studentArray=tempstudentArray;
                    delete []tempstudentArray;
                }
                studentArray[size++]=student;
            }

            void displayStudentById(string id){
                for(int i=0;i<size;i++){
                    if(studentArray[i].getStudentId()==id){
                        cout<<"***************Student Records******************"<<endl;
                        cout<<"Student Id:                      "<<studentArray[i].getStudentId()<<endl;
                        cout<<"Student Name:                    "<<studentArray[i].getStudentName()<<endl;
                        cout<<"Student Age:                     "<<studentArray[i].getAge()<<endl;
                        cout<<"Student Address:                 "<<studentArray[i].getAddress()<<endl;
                        cout<<"Student standard:                "<<studentArray[i].getStudentStandard()<<endl;
                    }
                } 
            }

            void displayStudentByName(string name){
                for(int i=0;i<size;i++){
                    if(studentArray[i].getStudentName()==name){
                        cout<<"***************Student Records******************"<<endl;
                        cout<<"Student Id:                      "<<studentArray[i].getStudentId()<<endl;
                        cout<<"Student Name:                    "<<studentArray[i].getStudentName()<<endl;
                        cout<<"Student Age:                     "<<studentArray[i].getAge()<<endl;
                        cout<<"Student Address:                 "<<studentArray[i].getAddress()<<endl;
                        cout<<"Student standard:                "<<studentArray[i].getStudentStandard()<<endl;
                    }
                } 
            }

            void displayStudentByAddress(string address){
                for(int i=0;i<size;i++){
                    if(studentArray[i].getAddress()==address){
                        cout<<"***************Student Records******************"<<endl;
                        cout<<"Student Id:                      "<<studentArray[i].getStudentId()<<endl;
                        cout<<"Student Name:                    "<<studentArray[i].getStudentName()<<endl;
                        cout<<"Student Age:                     "<<studentArray[i].getAge()<<endl;
                        cout<<"Student Address:                 "<<studentArray[i].getAddress()<<endl;
                        cout<<"Student standard:                "<<studentArray[i].getStudentStandard()<<endl;
                    }
                } 
            }

            void displayStudentByStandard(string standard){
                for(int i=0;i<size;i++){
                    if(studentArray[i].getStudentStandard()==standard){
                        cout<<"***************Student Records******************"<<endl;
                        cout<<"Student Id:                      "<<studentArray[i].getStudentId()<<endl;
                        cout<<"Student Name:                    "<<studentArray[i].getStudentName()<<endl;
                        cout<<"Student Age:                     "<<studentArray[i].getAge()<<endl;
                        cout<<"Student Address:                 "<<studentArray[i].getAddress()<<endl;
                        cout<<"Student standard:                "<<studentArray[i].getStudentStandard()<<endl;
                    }
                } 
            }

            void updateStudentAddress(string name,string address){
                bool flag=0;
                for(int i=0;i<size;i++){
                        if(studentArray[i].getStudentName()== name){
                            flag=1;
                            cout<<"***************Student details before updation******************"<<endl;
                            cout<<"Student Id:                      "<<studentArray[i].getStudentId()<<endl;
                            cout<<"Student Name:                    "<<studentArray[i].getStudentName()<<endl;
                            cout<<"Student Age:                     "<<studentArray[i].getAge()<<endl;
                            cout<<"Student Address:                 "<<studentArray[i].getAddress()<<endl;
                            cout<<"Student standard:                "<<studentArray[i].getStudentStandard()<<endl;
                            studentArray[i].setAddress(address);
                            cout<<"***************Student details after updation******************"<<endl;
                            cout<<"Student Id:                      "<<studentArray[i].getStudentId()<<endl;
                            cout<<"Student Name:                    "<<studentArray[i].getStudentName()<<endl;
                            cout<<"Student Age:                     "<<studentArray[i].getAge()<<endl;
                            cout<<"Student Address:                 "<<studentArray[i].getAddress()<<endl;
                            cout<<"Student standard:                "<<studentArray[i].getStudentStandard()<<endl;
                            cout<<"**********************************************************"<<endl;
                        }
                    }
                if(flag==0){
                    cout<<"****************Student Not Found******************"<<endl;
                }  
            }


            void updateStudentAge(string name,short int age){
                bool flag=0;
                for(int i=0;i<size;i++){
                        if(studentArray[i].getStudentName()== name){
                            flag=1;
                            cout<<"***************Student details before updation******************"<<endl;
                            cout<<"Student Id:                      "<<studentArray[i].getStudentId()<<endl;
                            cout<<"Student Name:                    "<<studentArray[i].getStudentName()<<endl;
                            cout<<"Student Age:                     "<<studentArray[i].getAge()<<endl;
                            cout<<"Student Address:                 "<<studentArray[i].getAddress()<<endl;
                            cout<<"Student standard:                "<<studentArray[i].getStudentStandard()<<endl;
                            studentArray[i].setAge(age);
                            cout<<"***************Student details after updation******************"<<endl;
                            cout<<"Student Id:                      "<<studentArray[i].getStudentId()<<endl;
                            cout<<"Student Name:                    "<<studentArray[i].getStudentName()<<endl;
                            cout<<"Student Age:                     "<<studentArray[i].getAge()<<endl;
                            cout<<"Student Address:                 "<<studentArray[i].getAddress()<<endl;
                            cout<<"Student standard:                "<<studentArray[i].getStudentStandard()<<endl;
                            cout<<"**********************************************************"<<endl;
                        }
                    }
                if(flag==0){
                    cout<<"****************Student Not Found******************"<<endl;
                }  
            }

            private:

                int search(string id){
                    for(int i=0;i<size;i++){
                        if(studentArray[i].getStudentId()==id){
                            return i;
                        }
                    }
                    return -1;
                }


            public:

            void deleteStudentDetail(string id){
                int isPresent=search(id);
                if(isPresent!=-1){
                    for(int i=isPresent;i<size-1;i++){
                        studentArray[i]=studentArray[i+1];
                    }
                    size--;
                }
            }

};