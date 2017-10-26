/*  NEURO.C 
 *  Contain functions to execute the neuronal network */

#include <stdio.h>
#include <stdlib.h>

#include "neuro.h"

Network *init_neuro_net_1l(List *param, int nbexit)
{
  /* Creation de l'entrée */
  Network *net = malloc(sizeof(Network));
  net->enter=list_init();
  creat_enter(net->enter,param); // changer list_init pour tester
  
  /* Creation de la sortie */
  Neuro *exit = neuro_init(); 
  load_link(exit);  //A condition d'avoir les liens dans un .txt
  printf("%d",nbexit); // A supprimer (supprime une warning xD)


  return net;
}

void creat_enter(List *enter, List *param)
{
  List *tmp = enter;
  while (param->next != NULL)
  {
    tmp->next->val = param->next->val;
    tmp = tmp->next;
    param = param->next;
  }
}

void load_link(Neuro *ner)
{
  FILE* file = NULL;
  file = fopen("link.txt","r+");
  char curent;
  if (file == NULL)
  {
    printf ("Impossible de charger le fichier link.txt");
    return ;
  }
  Neuro *tmp = ner;
  int dot = 0;
  int pow = 0;
  float donne = 0;
  List *tmplnk = list_init();
  do
  {
  curent = fgetc(file);
  if (curent == '|')
  {
    tmp->next = neuro_init();
    tmp = tmp->next;
    tmp->link = list_init();
    tmplnk = tmp->link;
  }
  if (curent == ';')
  {
    tmplnk->next = list_init();
    tmplnk = tmplnk->next;
    tmplnk->val = donne;
    donne = 0;
    dot = 0;
    pow = 10;
  }
  else 
  {
    if (curent == '.')
    {
      dot = 1 ;
      pow = 10;
    }
    else if (dot == 0)
      donne = donne * 10 + (double)curent;
    else
    {
      donne = donne + (double)curent/pow;
      pow = pow * 10;
    }
  }
  }while (curent != EOF);


}

void save_link(Neuro *ner)
{
  FILE* file = NULL;
  file = fopen("link.txt","r+");
  Neuro *tmp = ner;
  while (tmp->next!=NULL)
  {
    fputc('|',file);
    List *lnk = tmp->next->link;
    while (lnk->next!=NULL)
    {
      char rs[15];
      sprintf(rs,"%f;",lnk->next->val);
      fputs(rs,file);
      lnk = lnk->next;
    }
    tmp = tmp->next;
  }
  fclose(file);
}

