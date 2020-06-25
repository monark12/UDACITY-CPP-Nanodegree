#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
 float previdle=0.0;
 float previowait=0.0;
 float prevuser=0.0;
 float prevnice=0.0;
 float prevsystem=0.0;
 float previrq=0.0;
 float prevsoftirq=0.0;
 float prevsteal=0.0;

};

#endif