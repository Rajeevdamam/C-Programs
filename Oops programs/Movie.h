#include <iostream>
using namespace std;

class Movie{
    private:
        long movie_id;
        int length;
        string movieName;
        string *casting;
        short int year;
        short int rating;
        public:
            Movie(){
                
                
            }

            ~Movie(){
                
            }

            Movie(long movie_id,string movieName,string *casting,int length,short int year,short int rating){
                this->movie_id=movie_id;
                this->movieName=movieName;
                this->length=length;
                this->casting=new string[length];
                this->casting=casting;
                this->year=year;
                this->rating=rating;
            }


            // int getCastSize(){
            //     return size;
            // }

            long getMovieId(){
                return movie_id;
            }
            string getMovieName(){
                return movieName;
            }
            void getMovieCast(){
                for(int i=0;i<length;i++){
                    cout<<casting[i]<<endl;
                }
            }

            bool getParticularMovieCast(string cast){
                for(int i=0;i<length;i++){
                    if(casting[i]==cast){
                        return true;
                    }
                }
                return false;
            }

            int getLength(){
                return length;
            }

            short int getMovieYear(){
                return year;
            }
            short int getMovieRating(){
                return rating;
            }

            void setMovieId(long movie_id){
                this->movie_id=movie_id;
            }
            void setMovieName(string movieName){
                this->movieName=movieName;
            }
            void setMovieCast(string* casting){
                this->casting=casting;
            }
            void setMovieYear(short int year){
                this->year=year;
            }
            void setMovieRating(short int rating){
                this->rating=rating;
            }
};