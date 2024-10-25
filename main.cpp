#include "timer.h"
#include <thread>

int main() {
    Timer timer; 
    int duration = 20;
    std::thread timer_thread(&Timer::RunTimer, timer, duration);
   /*  std::cout << "Duration: ";
    std::cin >> duration;
    timer.SetDuration(duration);
*/
    timer_thread.join();

}