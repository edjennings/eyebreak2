#include "timer.h"
#include <thread>

std::mutex m;
std::condition_variable cv;
bool pause = false;
char UserInput = 'r';


int main() {
    Timer timer; 
    int duration = 10;
    std::thread timer_thread(&Timer::RunTimer, timer, std::ref(duration), std::ref(m), std::ref(cv), std::ref(pause));

    while(pause != true)
    {
      std::cout << "Pause?";
      std::cin >> UserInput;

      std::lock_guard lk(m);
      if (UserInput == 'p'){
        pause = true;
        cv.notify_one();
      }

    }
    timer_thread.join();

}