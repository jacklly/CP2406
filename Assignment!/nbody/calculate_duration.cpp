#include <iostream>
#include <chrono>
#include <thread>

float currentTime = 0;

//class setup timer
class Timer
{
    //sets
    public:
        Timer():

        //default states
        running(false)
        {}

        //start function
        void startTimer()
        {
            if (!running)
            {
                running = true;
                //grab start time
                startTick = std::chrono::steady_clock::now();
                std::cout << "\nStarted timer." << std::endl;
            }
            else
            {
                std::cout << "Timer already running!" << std::endl;
            }
        }

        //stop and reset function
        void stopTimer()
        {
            if (running)
            {
                running = false;
                //grab end time
                stopTick = std::chrono::steady_clock::now();

                //output final time
                auto elapsedTick = std::chrono::duration_cast<std::chrono::milliseconds>(stopTick - startTick).count();
                std::cout << "Duration of calculation: " << elapsedTick << " milliseconds" << std::endl;
            }
        }

    //startpoints
    private:
        bool running;
        std::chrono::steady_clock::time_point startTick;
        std::chrono::steady_clock::time_point stopTick;
        
};