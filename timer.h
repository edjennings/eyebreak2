#include <chrono>
#include <math.h> 
#include <string>
#include <iostream>
#include <condition_variable>
#include <mutex>

class Timer {

public:
    Timer() {
            m_duration = 0;
    }
  
    std::string DisplayTimeLeft(){
        int minutes = floor(m_time_left/60);
        int seconds = m_time_left - (minutes * 60);
        std::string DisplayTimeLeft = std::to_string(minutes) + " m " + std::to_string(seconds) + " s";
        return DisplayTimeLeft;

    } 
    
    void SetDuration(int duration){
        m_duration = duration;
    }

    bool RunTimer(int duration, std::mutex m, std::condition_variable cv, bool pause) {
    
        m_duration = duration;

        std::chrono::time_point<std::chrono::steady_clock> m_timeBegin;
        m_timeBegin = std::chrono::steady_clock::now();
        auto _current_time = std::chrono::steady_clock::now();
        
        m_time_left = m_duration - std::chrono::duration_cast<std::chrono::seconds>(_current_time - m_timeBegin).count();
        
        while(m_time_left > 0) {
            std::unique_lock lk(m);
            cv.wait(lk, [&]{ return pause;});

            _current_time = std::chrono::steady_clock::now();
            m_time_left = m_duration - std::chrono::duration_cast<std::chrono::seconds>(_current_time - m_timeBegin).count();

           //std::cout << m_duration << std::endl;

            cv.notify_one();       
        }
        return true;
    }
     
private:
    int  m_time_left;
    int m_duration;

};