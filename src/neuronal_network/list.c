/* list.c */

#include <stdlib.h>
#include <stdio.h>

#include "list.h"



/*  LIST */

List *list_init()
{
  List *lst = malloc(sizeof(List));
  lst -> next = NULL;
  return lst;
}

size_t list_length(List *lst)
{
  List *tmp = lst;
  size_t res = 0;
  while (tmp->next!=NULL)
  {
    res++;
    tmp = tmp->next;
  }
  return res;
}

double list_get(List *lst)
{
  return lst->val;
}

void list_set(List *lst, double elem)
{
  lst->val = elem;
}

int list_empty(List *lst)
{
  return lst->next == NULL;
}

void list_add(List *lst, double elem)
{
  lst->next = list_init();
  lst->next->val = elem;
}


/*  LAYER */

Layer *layer_init()
{
  Layer *lyr = malloc(sizeof(Layer));
  lyr->next = NULL;
}

Neuro *layer_get_content(Layer *lay)
{
  return lay->content;
}

int layer_is_exit(Layer *lay)
{
  return lay->next == NULL;
}
void layer_add(Layer *lay, Neuro *ner)
{
  lay -> next = layer_init();
  lay->next->content = ner;
}


/*  NEURO */

Neuro *neuro_init()
{
  Neuro *ner = malloc(sizeof(Neuro));
  ner->next = NULL;
  ner->link = NULL;
  return ner;
}

List *neuro_get_link(Neuro *ner)
{
  return ner->link;
}

double neuro_get_weight(Neuro *ner)
{
  return ner->weight;
}

void neuro_set_weight(Neuro *ner,double wei)
{
  ner->weight = wei;
}

void neuro_add(Neuro *ner, List *link)
{
  ner->next = neuro_init();
  ner->next->link = link;
}
