#include <iostream>
#include "Task.cpp"
using namespace std;



class System{
    
    private:
        int capacity;
        int size;
        Task *taskArray;
        public:
            System(){
                capacity=2;
                size=0;
                taskArray=new Task[capacity];
            }
            
            int getSize(){
                return size;
            }

            void addTask(Task task){
                taskArray[size++]=task;
            }
            

            
            Task *sort(Task *taskArray){
                Task *tempArray=new Task[capacity];
                for(int i=0;i<size;i++){
                    tempArray[i]=taskArray[i];
                }
                for(int i=0;i<size;i++){
                    for(int j=i+1;j<size;j++){
                        if(tempArray[i].getAssignedTo() > tempArray[j].getAssignedTo()){
                            Task temp=tempArray[i];
                            tempArray[i]=tempArray[j];
                            tempArray[j]=temp;
                        }
                    }
                }
                return tempArray;
            }
            
            void display(){
                Task *tempArray=sort(taskArray);
                for(int i=0;i<size;i++){
                    cout<<"The details of the Task for a system are:"<<endl;
                    cout<<"******************************************************************"<<endl;
                    cout<<"Task Id:          "<<tempArray[i].getId()<<endl;
                    cout<<"Task description: "<<tempArray[i].getDescription()<<endl;
                    cout<<"Task assignedTo:  "<<tempArray[i].getAssignedTo()<<endl;
                    cout<<"Task status:      "<<tempArray[i].getStatus()<<endl;
                    cout<<"******************************************************************"<<endl;
                }
                cout<<"All the details are displayed:"<<endl;
            }
};



int main()
{
    int id;
    string description,assignedTo,status;
    System systemDetails;
    for(int i=0;i<2;i++){
        cout<<"Enter Task Id:          "<<endl;
        cin>>id;
        cout<<"Enter Task description: "<<endl;
        cin>>description;
        cout<<"Enter Task assignedTo:  "<<endl;
        cin>>assignedTo;
        cout<<"Enter Task status:      "<<endl;
        cin>>status;
        systemDetails.addTask(Task(id,description,assignedTo,status));
    }
    cout<<"size:"<<systemDetails.getSize()<<endl;
    systemDetails.display();
}


/*
Inventory Management
Write a menu driver program for inventory management where Product(id, name, quantity, price_per_unit).
1. Add new product in inventory.
2. Update the quantity of particular product.
3. Display products where quantity is less than provided by a user.
4. Display product sort on the basis of quantity.
5. Delete a particular product from inventory.
6. Exit




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



Hospital record: 
Create a patients record which includes name, number of days admitted, illness occurred, bill amount, doctor treated.
1. Add incoming patients
2. Delete outgoing patients
3. Display patients treated by particular illness
4. Display patients having same illness.
5. Display patient name who have billed lowest.
6. Exit



*/