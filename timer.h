#include <chrono>
#include <math.h> 
#include <string>
#include <iostream>
#include <atomic>

class Timer {

public:
    bool is_paused;
        std::atomic<int>  m_duration{0};

    
    Timer() {
            is_paused = false;
          //  m_duration = 0;
    }
  
    std::string DisplayTimeLeft(){
        int minutes = floor(m_time_left/60);
        int seconds = m_time_left - (minutes * 60);
        std::string DisplayTimeLeft = std::to_string(minutes) + " m " + std::to_string(seconds) + " s";
        return DisplayTimeLeft;

    } 
    
/*     void SetDuration(int duration){
        m_duration.store(duration);
    }
 */
    bool RunTimer(int duration) {
    
        //m_duration.store(duration); 

        std::chrono::time_point<std::chrono::steady_clock> m_timeBegin;
        m_timeBegin = std::chrono::steady_clock::now();
        auto _current_time = std::chrono::steady_clock::now();
        
        m_time_left = duration - std::chrono::duration_cast<std::chrono::seconds>(_current_time - m_timeBegin).count();
        
        while(m_time_left > 0) {
            
            _current_time = std::chrono::steady_clock::now();
            m_time_left = duration - std::chrono::duration_cast<std::chrono::seconds>(_current_time - m_timeBegin).count();

          //  std::cout << DisplayTimeLeft() << std::endl;
        
        }
        return true;
    }
     
private:
    int  m_time_left;

};