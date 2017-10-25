/*		     list.h
 *  all fuctions necessary to use linked lists	*/


typedef struct Neuro{
  struct Neuro *next;
  struct List *link;
  double weight;
}Neuro;

typedef struct List{
  struct List *next;
  double val;
}List;

typedef struct Layer{
  struct Layer *next;
  Neuro *content;
}Layer;


List *list_init();
size_t list_length(List *lst);
double list_get(List *lst);
void list_add(List *lst, double elem);
void list_set(List *lst, double elem);

Layer *layer_init();
Neuro *layer_get_content(Layer *lay);
int layer_is_exit(Layer *lay);
void layer_add(Layer *lay, Neuro *neur);

Neuro *neuro_init();
List *neuro_get_link(Neuro *ner);
double neuro_get_weight(Neuro *ner);
void neuro_set_weight(Neuro *ner, double wei);
void neuro_add(Neuro *ner, List	*link);
