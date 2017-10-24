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
  List tmp = lst;
  size_t res = 0;
  while (tmp->next!=NULL)
  {
    size_t++;
    tmp = tmp->next;
  }
  return res;
}

double list_get(List lst)
{
  return lst->val;
}

void list_set(List lst, double elem)
{
  lst->val = elem;
}

int list_empty(List lst)
{
  return lst->next == NULL;
}

void list_add(List lst, double elem)
{
  lst->next = list_init();
  lst->next->val = elem;
}

Layer layer_init()
{
  Layer lyr = malloc(sizeof(Layer));
  lyr->next = NULL;
  lyr->pref = NULL;
}

List layer_get_content(Layer lay)
{
  return lay->content;
}

List layer_get_prev_content(Layer lay)
{
  return (layer->prev != NULL)?layer->prev->content:list_init();
}

int layer_is_enter(Layer lay)
{
  return lay->prev == NULL;
}

int layer_is_exit(Layer lay)
{
  return lay->next == NULL;
}
void layer_add(Layer lay, List lst)
{
  l
}
