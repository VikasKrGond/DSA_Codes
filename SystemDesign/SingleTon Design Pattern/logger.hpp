#ifndef logger_h
#define logger_h

#include<string>
using namespace std;

class Logger{
  static int cnt;
  static Logger *loggerInstance;
  Logger();
  public:
  static Logger *getLogger();
  void Log(string msg);
};