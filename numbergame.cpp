#include<iostream>
#include<cstdlib>
#include<ctime>

int main()
{
     std::srand(static_cast<unsigned>(std::time(0)));
     int randomnumber= std::rand()%100+1;
     int userguess=0;

     std::cout<<"Guess the number (between 1 and 100): ";

     while(userguess!=randomnumber){
        std::cin>>userguess;
        if(userguess>randomnumber){
            std::cout<<"Too high! Try again: ";
        }
        else if(userguess<randomnumber){
            std::cout<<"Too low! Try again: ";
        }
        else{
            std::cout<<"Congratulations! You've guessed the correct number.";
        }
     }
     return 0;
}