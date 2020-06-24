#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

// TODO: Return this process's ID
int Process::Pid() { return process_ID; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() const{
    float sys_uptime = (float)LinuxParser::UpTime();
    float total_time, seconds;
    string line;
    string value;
    float utime, stime, cutime, cstime, t1, t2, t3, t4, starttime;
    
    std::ifstream stream(LinuxParser::kProcDirectory + to_string(this->process_ID) + LinuxParser::kStatFilename);
    std::getline(stream, line);
    std::istringstream linestream(line);
    for (int i=0; i<13; i++)
        linestream >> value;
    linestream >> utime >> stime >> cutime >> cstime >> t1 >> t2 >> t3 >> t4 >> starttime;

    total_time = utime + stime;
    total_time = total_time + cutime + cstime;

    seconds = sys_uptime - (starttime / sysconf(_SC_CLK_TCK));
    return 100 * ((total_time / sysconf(_SC_CLK_TCK)) / seconds);
}

// TODO: Return the command that generated this process
string Process::Command() {return LinuxParser::Command(process_ID);}

// TODO: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(process_ID); }

// TODO: Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(process_ID); }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(process_ID); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const {
    return this->CpuUtilization() < a.CpuUtilization();
}