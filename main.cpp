#include "timer.h"

char UserInput = 'r';

int main() {
    Timer timer; 

   std::thread timer_thread(&Timer::RunTimer, &timer, 15);

    while(UserInput!= 'x' || timer_thread.joinable() != true){
      //std::cout << timer.GetDuration() << " " << timer.DisplayTimeLeft() << " Pause? ";
    std::cout << " pause ?";
      std::cin >> UserInput;
      
     if (UserInput == 'p'){
       timer.SetPause(true);
      }
      else if(UserInput == 'u'){
        timer.SetPause(false);
        std::cout << timer.DisplayTimeLeft();
        

      }
     
     
    }

    timer_thread.join();
       

}