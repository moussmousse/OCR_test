/*  NEURO.H */

#include "list.h"

void creat_enter(List *enter, List *param);
Network *init_neuro_net_1l(List *param);
void load_link(Neuro *ner);
void save_link(Neuro *ner);
void load_rand_link(Neuro *exit,size_t nbenter, int nbexit);
void calcul_weight(Network *net);
void learn(Network *net, List *target, double pas);
