#include <chrono>
#include <math.h> 
#include <string>
#include <iostream>
#include <condition_variable>
#include <thread>

class Timer {

public:
    Timer() {
            m_duration = 0;
            m_time_left = 0;
            m_pause = false;
    }
  
    std::string DisplayTimeLeft(){
        int minutes = floor(m_time_left/60);
        int seconds = m_time_left - (minutes * 60);
        std::string DisplayTimeLeft = std::to_string(minutes) + " m " + std::to_string(seconds) + " s";
        return DisplayTimeLeft;

    } 

    int GetDuration(){
        return m_duration;
    }
    
    void SetDuration(int duration){
        m_duration = duration;
    }

    void SetPause(bool pause){
        m_pause = pause;
    }

    bool RunTimer(int duration) {
    
        m_duration = duration;

        // std::chrono::time_point<std::chrono::steady_clock> m_timeBegin;
        // m_timeBegin = std::chrono::steady_clock::now();
        // auto _current_time = std::chrono::steady_clock::now();
        
        m_time_left = m_duration;
        
        while(m_time_left > 0) {
            if(m_pause != true){
            // _current_time = std::chrono::steady_clock::now();
            // m_time_left = m_time_left - std::chrono::duration_cast<std::chrono::seconds>(_current_time - m_timeBegin).count();
            std::this_thread::sleep_for(std::chrono::seconds(1));
            m_time_left--;
            //std::cout << DisplayTimeLeft() << std::endl;
            }
            else{
             std::this_thread::sleep_for(std::chrono::seconds(1));
            }
       }
        return true;
    }
     
private:
    int m_duration;
    int m_time_left;
    bool m_pause;
};