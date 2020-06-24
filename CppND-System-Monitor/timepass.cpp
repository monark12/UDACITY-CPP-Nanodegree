#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <chrono>
#include <unistd.h>

namespace Format {
std::string ElapsedTime(long times);  // TODO: See src/format.cpp
};   

int main(){

const std::string kProcDirectory{"/proc/"};
const std::string kCmdlineFilename{"/cmdline"};
const std::string kCpuinfoFilename{"/cpuinfo"};
const std::string kStatusFilename{"/status"};
const std::string kStatFilename{"/stat"};
const std::string kUptimeFilename{"/uptime"};
const std::string kMeminfoFilename{"/meminfo"};
const std::string kVersionFilename{"/version"};
const std::string kOSPath{"/etc/os-release"};
const std::string kPasswordPath{"/etc/passwd"};

std::string line;
  std::string state;
  int pid=4825;

  std::ifstream stream(kProcDirectory + std::to_string(pid) + kStatFilename);
  if (stream.is_open()){
    getline(stream, line);
    std::istringstream linestream(line);
    for(int i=0; i<22; i++)
      linestream >> state;
    
    std::cout << "GOOGLE ";
  }
  std::cout << stol(state)/sysconf(_SC_CLK_TCK) << ", " << stol(state) << std::endl;
  return stol(state)/sysconf(_SC_CLK_TCK);

}