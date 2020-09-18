#include "processor.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() { 
  
  std::vector<std::string> fies_list = LinuxParser::CpuUtilization();
  
  for (size_t i{0}; i<fies_list.size();i++){
    if (i!=LinuxParser::kGuest_ and i!=LinuxParser::kGuestNice_){
    	total_fies += std::stof(fies_list[i]);
    }
    if (i==LinuxParser::kIdle_ or i==LinuxParser::kIOwait_){
    	idle_fies += std::stof(fies_list[i]);
    }
  }
  util_fies = total_fies - idle_fies;
  
  bool curr_util = true;
  if (curr_util){
   usage = (util_fies-util_fies_pre)/(total_fies-total_fies_pre);
    total_fies_pre = total_fies;
    util_fies_pre = util_fies;
  }
  else{
    usage = util_fies/total_fies;
  }
  
  return usage; 
}}
