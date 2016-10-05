#ifndef _EXCEPTION_H_
# define _EXCEPTION_H_

#include <iostream>
#include <sstream>
#include <exception>

class my_exception : public std::exception
{
  std::string		message;

public:
  my_exception(const char *msg)
  {
    std::ostringstream oss;
    oss << "Error : " << msg;
    this->message = oss.str();
  }

  my_exception(my_exception const &src)
  {
    this->message = src.message;
  }

  virtual ~my_exception() throw()
  {
  }

  my_exception &operator=(my_exception const &src)
  {
    if (this != &src)
      this->message = src.message;
    return (*this);
  }

  virtual const char *what() const throw()
  {
    return this->message.c_str();
  }
};

#endif /* _EXCEPTION_H_ */
