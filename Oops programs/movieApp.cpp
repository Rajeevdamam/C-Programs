// Question 7 :
// Implement a Menu driven program to store Movie details.
// Movie class should have the following
// 1. Id
// 2. Name
// 3. Casting - String[]
// 4. Year of Release
// 5. Rating - Should be from 1 to 5
// 1. Add Movie details to the system and display all Movie details present in system
// 2. Sort Movie details by Year of Release and if the year is same sort by its Name
// 3. Display all the movie details whose Rating is greater than or equal to given value
// a. Example : If the input for Rating is provided as “3”, Display all movies whose rating is greater than or equal to 3
// 4. Display all movie details for the given Casting ( it should match the input in array of String )
// a. Example : If the input is provided as ‘Charlie’ , Search for all movies where Charlie was part of Casting and Display all the movie details
// 5. Update Rating details for given Movie Id
// Step 1: Get the Movie Id and Rating to be updated as an user input
// Step 2: Fetch the movie details for given id and if present, update the Rating details with new value
// Step 3: Display the details
// 6. Delete movie details for given Movie Id
// 7. Exit


#include <iostream>
#include <string>
#include "MovieArray.h"
using namespace std;


long movie_id;
Movie movie;
string movieName,castName;
MovieArray movieArray;
string *casting;
int n;
short int year;
short int rating;

void addDetails(){
        cout<<"Enter Movie ID:"<<endl;
        cin>>movie_id;
        cout<<"Enter Movie name:"<<endl;
        cin>>movieName;
        cout<<"Enter number of cast members"<<endl;
        cin>>n;
        casting=new string[n];
        cout<<"Enter each cast member names by pressing enter after every name:"<<endl;
        for(int i=0;i<n;i++){
            cin>>castName;
            casting[i]=castName;
        }
        cout<<"Enter year in which movie got released:"<<endl;
        cin>>year;
        cout<<"Enter Movie rating:"<<endl;
        cin>>rating;
        if(rating<0 || rating>5){
            cout<<"Enter Movie rating between 1 to 5:"<<endl;
            cin>>rating;
        }
        movieArray.addMovie(Movie(movie_id,movieName,casting,n,year,rating));
        
}

int main()
{
    int choice=0;
    cout<<"***************************** Welcome to Movie Details Application *****************************"<<endl;
    do{
        cout<<"1. Add Movie details to the system and display all Movie details present in system"<<endl;
        cout<<"2. Sort Movie details by Year of Release and if the year is same sort by its Name"<<endl;
        cout<<"3. Display all the movie details whose Rating is greater than or equal to given value"<<endl;
        cout<<"4. Display all movie details for the given Casting ( it should match the input in array of String )"<<endl;
        cout<<"5. Update Rating details for given Movie Id"<<endl;
        cout<<"6. Delete movie details for given Movie Id"<<endl;
        cout<<"Enter your Choice:"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                addDetails();
                break;
            case 2:
                cout<<"*****************************Sort By Year or by Name:*****************************"<<endl;
                movieArray.displayMovieDetailsInSortedManner();
                break;
            case 3:
                cout<<"*****************************Display Rating greater than specified value:*****************************"<<endl;
                cout<<"Enter movie rating:"<<endl;
                cin>>rating;
                movieArray.displayRatings(rating);
                break;
            case 4:
                cout<<"*****************************Display movie according to cast*****************************"<<endl;
                cout<<"Enter movie cast:"<<endl;
                cin>>castName;
                movieArray.displayMovieAccordingToCast(castName);
                break;
            case 5:
                cout<<"*****************************Update rating for given movie id:*****************************"<<endl;
                cout<<"Enter Movie ID:"<<endl;
                cin>>movie_id;
                cout<<"Enter movie rating:"<<endl;
                cin>>rating;
                movieArray.updateRating(movie_id,rating);
                break;
            case 6:
                cout<<"*****************************Delete the movie for particular id:*****************************"<<endl;
                cout<<"Enter Movie ID:"<<endl;
                cin>>movie_id;
                movieArray.deleteMovie(movie_id);
                break;
            case 7:
                cout<<"***************************** Byeee have a great time ************************"<<endl;
                break;
            default:
                cout<<"***************************** Enter valid input ************************"<<endl;
                break;
        }
    }while(choice!=7);
}