/*  NEURO.H */

#include "list.h"

void creat_enter(List *enter, List *param);
Network *init_neuro_net_1l(List *param, int exit);
void load_link(Neuro *ner);
void save_link(Neuro *ner);
