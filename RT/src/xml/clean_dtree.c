#include <stdlib.h>

#include "rt.h"

void free_dtree(t_node *node)
{
  if (node == 0)
    return ;
  free_dtree(node->fils);
  free_dtree(node->next);
  (void)free(node);
}
