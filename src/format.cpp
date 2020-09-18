#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
  long HH{seconds/3600};
  long H_{seconds%3600};
  long MM{H_/60};
  long SS{H_%60};
  string HH_{std::to_string(HH)};
  string MM_{std::to_string(MM)};
  string SS_{std::to_string(SS)};
  string time{HH_+':'+MM_+':'+SS_};
  return time;
}
