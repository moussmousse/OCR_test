/*		     list.h
 *  all fuctions necessary to use linked lists	*/



typedef struct List{
  struct List *next;
  double val;
}List;

typedef struct Layer{
  struct Layer *next;
  struct Layer *prev;
  List content;
}


List list_init();
size_t list_length(List lst);
double list_get(List lst);
void list_add(List lst, double elem);
void list_set(List lst, double elem);

Layer layer_init();
List layer_get_content(Layer lay);
List layer_get_prev_content(Layer lay);
int layer_is_enter(Layer lay);
int layer_is_exit(Layer lay);
int layer_add(Layer lay, List lst);


