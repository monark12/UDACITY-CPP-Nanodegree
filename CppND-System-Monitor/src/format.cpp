#include <string>
#include <iomanip>
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
    
    std::ostringstream stream;
    stream << std::setw(2) << std::setfill('0') << hours << ":" 
           << std::setw(2) << std::setfill('0') << minutes << ":"
           << std::setw(2) << std::setfill('0') << second;
    return stream.str();

    // return std::to_string(std::_Setw(2)<<hours) + ":" + std::to_string(minutes) + ":" + std::to_string(second);
}