#ifndef BUFFER_HH
#define BUFFER_HH

#include <sys/select.h>
#include <list>
#include <unistd.h>
#include "Exception.hpp"


class				Buffer
{
private:
  const int 			fd;
  std::list<std::string *> 	buffer;
  fd_set			fd_read;
  struct timeval 		tv;

public:
  Buffer(const int fd);
  ~Buffer();

  bool				receive_data(std::string &str);
};

#endif
