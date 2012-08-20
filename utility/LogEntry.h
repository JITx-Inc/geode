//#####################################################################
// Class LogEntry
//#####################################################################
#pragma once

#include <other/core/utility/Log.h>
#include <other/core/utility/time.h>
#include <other/core/utility/config.h>
#include <boost/noncopyable.hpp>
#include <string>
#include <cstdio>
namespace other {

using std::string;

class LogEntry : public boost::noncopyable {
public:
  LogEntry* parent;
  int depth;
  double time;
  double timer_start_time;
  string name;
  bool end_on_separate_line,log_file_end_on_separate_line;
  static bool start_on_separate_line,log_file_start_on_separate_line;
  static bool needs_indent,log_file_needs_indent;
  int& verbosity_level;

  LogEntry(LogEntry* parent, const int depth, const string& name, int& verbosity_level);
  virtual ~LogEntry();

  void start(FILE* log_file);
  void stop(FILE* log_file);
  virtual LogEntry* get_stop_time(FILE* log_file);
  virtual LogEntry* get_new_scope(FILE* log_file,const string& new_name);
  virtual LogEntry* get_new_item(FILE* log_file,const string& new_name);
  virtual LogEntry* get_pop_scope(FILE* log_file);
  virtual void dump_log(FILE* output);
  virtual void dump_names(FILE* output);
};

}
