#include <err.h>
#include <stdlib.h>

#include <iostream>
#include <sstream>

#include "src/common.h"

using namespace std;

void PrintMessageDieOnError(const string& msg, MSGTYPE msgtype) {
  string typestring = "";
  switch (msgtype) {
  case ERROR:
    typestring = "ERROR: ";
    break;
  case WARNING:
    typestring = "WARNING: ";
    break;
  case PROGRESS:
    typestring = "ProgressMeter: ";
    break;
  case DEBUG:
    typestring = "DEBUG: ";
    break;
  default:
    errx(1, "Invalid message type. This should never happen");
  }
  stringstream ss;
  ss  << "[GangSTR"
      << "-" << _GIT_VERSION << "] " << typestring << msg << endl;
  cerr << ss.str();

  if (msgtype == ERROR) {
    exit(1);
  }
}

void split_by_delim(const std::string &s, char delim, 
		    std::vector<std::string>& substrings){
  std::stringstream ss(s);
  std::string item;
  while (std::getline(ss, item, delim))
    substrings.push_back(item);
}
