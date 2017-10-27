#include <stdlib.h>
#include <stdio.h>

//#include "neuronal_network/list.h"
#include "neuronal_network/neuro.h"


void test_save(){
  Neuro *n = neuro_init();
  printf("Exit OK. \n");
  load_rand_link(n,81,56);
  printf("Random link OK.\n");
  save_link(n);
  printf("Sauvegarde OK.\n");
}


int main ()
{
  test_save();
}
