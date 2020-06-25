#include "processor.h"
#include "linux_parser.h"
#include <vector>
#include <string>
#include <unistd.h>

// TODO: Return the aggregate CPU utilization

float Processor::Utilization() {
    std::string line, cpu, value;
    std::vector<std::string> v = LinuxParser::CpuUtilization();

    float user       = stof(v[0]);
    float nice       = stof(v[1]);
    float system     = stof(v[2]);
    float idle       = stof(v[3]);
    float iowait     = stof(v[4]);
    float irq        = stof(v[5]);
    float softirq    = stof(v[6]);
    float steal      = stof(v[7]);

    float prev_idle_iowait = previdle + previowait;
    float Idle = idle + iowait;
    
    float prev_non_idle = prevuser + prevnice + prevsystem + previrq + prevsoftirq + prevsteal;
    float NonIdle = user + nice + system + irq + softirq + steal;
    
    float prev_total = prev_idle_iowait + prev_non_idle;
    float Total = Idle + NonIdle;
    
    float totald = Total - prev_total;
    float idled = Idle - prev_idle_iowait;
    
    float output = (totald - idled) / totald;
    
    previdle = idle;
    previowait = iowait;
    prevuser = user;
    prevnice = nice;
    prevsystem = system;
    previrq = irq;
    prevsoftirq = softirq;
    prevsteal = steal;
    
    return output; 
}

//     // Guest time is already accounted in usertime, so subtract guest from user time (same with nice)
//     user = user - guest;
//     nice = nice - guest_nice;

//     // ioWait is added in the idleTime
//     float idle_all_time = idle + iowait;
//     float system_all_time = system + irq + softirq;
//     float virtal_ltime = guest + guest_nice;

//     total_time = user + nice + system_all_time + idle_all_time + steal + virtal_ltime;

//     return total_time;
// }