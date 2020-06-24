#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
    
    int hours = seconds/3600;
    int minutes = (seconds/60) - (hours*60);
    int second = seconds % 60;

    return std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(second);
}