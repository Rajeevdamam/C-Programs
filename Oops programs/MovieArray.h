#include <iostream>
#include "Movie.h"
using namespace std;


class MovieArray{
    private:
        int size1;
        int capacity1;
        Movie movie;
        Movie *movieArray;
        public:
            MovieArray(){
                size1=0;
                capacity1=2;
                movieArray=new Movie[capacity1];
            }

            ~MovieArray(){
                delete []movieArray;
            }

        int getNumOfMovies(){
            return size1;
        }

        void updateRating(long movie_id,short int rating){
            for(int i=0;i<size1;i++){
                if(movieArray[i].getMovieId()==movie_id){
                    cout<<"*****************************************************************"<<endl;
                    cout<<"rating before:"<<movieArray[i].getMovieRating()<<endl;
                    movieArray[i].setMovieRating(rating);
                    cout<<"************************After Updation*****************************"<<endl;
                    cout<<"Movie Name:                      "<<movieArray[i].getMovieName()<<endl;
                    cout<<"Movie casts:"<<endl;
                    movieArray[i].getMovieCast();
                    cout<<"Movie released in year:          "<<movieArray[i].getMovieYear()<<endl;
                    cout<<"Movi Rating :                    "<<movieArray[i].getMovieRating()<<endl;
                    return;
                }
            }
            cout<<"No movie of id "<<movie_id<<" found"<<endl;
        }

        Movie *sortByYear(){
            Movie* tempArray=new Movie[size1];
            for(int i=0;i<size1;i++){
                tempArray[i]=movieArray[i];
            }
            for(int i=0;i<size1;i++){
                for(int j=i+1;j<size1;j++){
                    if(tempArray[i].getMovieYear() > tempArray[j].getMovieYear()){
                        Movie temp=tempArray[i];
                        tempArray[i]=tempArray[j];
                        tempArray[j]=temp;
                    }
                    else if(tempArray[i].getMovieYear() == tempArray[j].getMovieYear()){
                        return NULL;
                    }
                }
            }
            return tempArray;
        }

        Movie *sortByName(){
            Movie* tempArray=new Movie[size1];
            for(int i=0;i<size1;i++){
                tempArray[i]=movieArray[i];
            }
            for(int i=0;i<size1;i++){
                for(int j=i+1;j<size1;j++){
                    if(tempArray[i].getMovieName() > tempArray[j].getMovieName()){
                        Movie temp=tempArray[i];
                        tempArray[i]=tempArray[j];
                        tempArray[j]=temp;
                    }
                }
            }
            return tempArray;
        }

        void displayMovieDetailsInSortedManner(){
            Movie *temp=sortByYear();
            if(temp!=NULL){
                cout<<"************************ Sorting By Year **********************************"<<endl;
                for(int i=0;i<size1;i++){
                    cout<<"Movie Id:                        "<<temp[i].getMovieId()<<endl;
                    cout<<"Movie Name:                      "<<temp[i].getMovieName()<<endl;
                    cout<<"Movie casts:"<<endl;
                    temp[i].getMovieCast();
                    cout<<"Movie released in year:          "<<temp[i].getMovieYear()<<endl;
                    cout<<"Movie Rating :                    "<<temp[i].getMovieRating()<<endl;
                    cout<<"**********************************************************"<<endl;
                }
            }
            else{
                Movie *temp=sortByName();
                cout<<"************************ Sorting By name **********************************"<<endl;
                for(int i=0;i<size1;i++){
                    cout<<"Movie Id:                        "<<temp[i].getMovieId()<<endl;
                    cout<<"Movie Name:                      "<<temp[i].getMovieName()<<endl;
                    cout<<"Movie casts:"<<endl;
                    temp[i].getMovieCast();
                    cout<<"Movie released in year:          "<<temp[i].getMovieYear()<<endl;
                    cout<<"Movie Rating :                    "<<temp[i].getMovieRating()<<endl;
                    cout<<"**********************************************************"<<endl;
                }
            }
        }

        void displayRatings(short int rating){
            for(int i=0;i<size1;i++){
                if(movieArray[i].getMovieRating()>=rating){
                    cout<<"***************Displaying ratings greater than or equal to: "<<rating<<"******************"<<endl;
                    cout<<"Movie Id:                        "<<movieArray[i].getMovieId()<<endl;
                    cout<<"Movie Name:                      "<<movieArray[i].getMovieName()<<endl;
                    cout<<"Movie casts:"<<endl;
                    movieArray[i].getMovieCast();
                    cout<<"Movie released in year:          "<<movieArray[i].getMovieYear()<<endl;
                    cout<<"Movie Rating :                    "<<movieArray[i].getMovieRating()<<endl;
                    cout<<"**********************************************************"<<endl;
                }
            }
        }

        void displayMovieAccordingToCast(string cast){
            bool found=0;
            for(int i=0;i<size1;i++){
                if(movieArray[i].getParticularMovieCast(cast)){
                    found=1;
                    cout<<"***************Displaying according to cast********************"<<endl;
                    cout<<"Movie Id:                        "<<movieArray[i].getMovieId()<<endl;
                    cout<<"Movie Name:                      "<<movieArray[i].getMovieName()<<endl;
                    cout<<"Movie casts:"<<endl;
                    movieArray[i].getMovieCast();
                    cout<<"Movie released in year:          "<<movieArray[i].getMovieYear()<<endl;
                    cout<<"Movi Rating :                    "<<movieArray[i].getMovieRating()<<endl;
                    cout<<"****************************************************************"<<endl;
                }
            }
            if(found==0){
                cout<<"***************No record found according to cast********************"<<endl;
            }
        }
       
        void addMovie(Movie movie){
            if(size1==capacity1){
                Movie *newMovieArray=new Movie[2*capacity1];
                for(int i=0;i<capacity1;i++){
                    newMovieArray[i]=movieArray[i];
                }
                capacity1*=2;
                movieArray=newMovieArray;
                delete[] newMovieArray;
            }
            movieArray[size1++]=movie;
        }

        private:
        int search(int movie_id){
             for(int i=0;i<size1;i++){
                 if(movieArray[i].getMovieId()==movie_id){
                     return i;
                 }
             }
             return -1;
        }
        public:
        void deleteMovie(long movie_id){
            int pos=search(movie_id);
            if(pos!=-1){
                for(int i=pos;i<size1-1;i++){
                    movieArray[i]=movieArray[i+1];
                }
                size1--;
            }
            else{
                cout<<"Movie not found"<<endl;
            }
        }
};