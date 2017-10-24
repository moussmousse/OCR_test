/* list.c */

#include <stdlib.h>
#include <stdih.h>

#include "list.h"



List list_init()
{
  List lst = Malloc(sizeof(List));
  lst -> next = NULL;
  return lst;
}

size_t list_length(List lst)
{

}

double list_get(List lst)
{

}

void list_add(List lst, double elem)
{

}

Layer layer_init()
{

}

List layer_get_content(Layer lay)
{

}

List layer_get_prev_content(Layer lay)
{

}

int layer_is_enter(Layer lay)
{

}

int layer_is_exit(Layer lay)
{

}
int layer_add(Layer lay, List lst)
{

}
