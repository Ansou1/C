#include "Buffer.hh"

Buffer::Buffer(const int fd) : fd(fd) {}

Buffer::~Buffer() {}

bool 			Buffer::receive_data(std::string &str)
{
  std::string response;
  char 		buf[50000];
  int 		ret;
  std::size_t l = 0;
  std::size_t old = 0;

  tv.tv_sec = 0;
  tv.tv_usec = 100;
  FD_ZERO(&fd_read);
  FD_SET(this->fd, &fd_read);
  if ((ret = select(fd + 1, &fd_read, NULL, NULL, &tv)) == -1)
    std::cerr << "error select" << std::endl;
  if (FD_ISSET(fd, &fd_read))
    {
      if ((ret = read(fd, buf, 49999)) < 1){
	throw my_exception("Server disconnected");
	return (false);
      }
      buf[ret] = 0;
      response = buf;
      while ((l = response.find("\n", l)) != std::string::npos)
	{
	  std::string *add = new std::string;
	  *add = response.substr(old, l - old);
	  (this->buffer).push_back(add);
	  old = l;
	}
    }
  if (buffer.size() == 0)
    return (false);
  str = *(*(buffer.begin()));
  delete *(buffer.begin());
  return (true);
}
