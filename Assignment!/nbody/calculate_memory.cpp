#include <iostream>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#include <psapi.h>
#elif defined(__APPLE__) && defined(__MACH__)
#include <mach/mach.h>
#include <unistd.h>
#endif

class Memory
{
public:
    Memory():
    //placeholder
    exists(true)
    {}
    void caculateMemory() 
    {
        // Simulate some memory allocation
        int *arr = new int[1000000]; // Allocate memory
        // Do something with arr
        delete[] arr; // Free memory
        std::cout << "Memory recording." << std::endl;
    }
    size_t getMemoryUsage() 
    {
        #if defined(_WIN32) || defined(_WIN64)
                return getMemoryUsageWindows();
        #elif defined(__APPLE__) && defined(__MACH__)
                return getMemoryUsageMac();
        #else
                return 0; // Unsupported platform
        #endif
    }
private:
    //palceholder for initial function
    bool exists;

    #if defined(_WIN32) || defined(_WIN64)
    SIZE_T getMemoryUsageWindows() 
    {
        PROCESS_MEMORY_COUNTERS_EX pmc;
        GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *) &pmc, sizeof(pmc));
        std::cout << std::round(pmc.WorkingSetSize / 1000000) << " Megabytes used." << std::endl;
        return 0;
    }
    #elif defined(__APPLE__) && defined(__MACH__)
    size_t getMemoryUsageMac() 
    {
        struct mach_task_basic_info info;
        mach_msg_type_number_t infoCount = MACH_TASK_BASIC_INFO_COUNT;
        if (task_info(mach_task_self(), MACH_TASK_BASIC_INFO, (task_info_t)&info, &infoCount) != KERN_SUCCESS) {
            return 0;
        }
        return info.resident_size;
    }
    #endif
};
