#include<stdlib.h>
#include "rt.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
  t_rt	*this;

  this = create_session(argc, argv);
  if (argc > 2)
    render_session(this, argv[2]);
  else
    render_session(this, NULL);
  return (EXIT_SUCCESS);
}
