/*  NEURO.C 
 *  Contain functions to execute the neuronal network */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "neuro.h"

Network *init_neuro_net_1l(List *param, int nbexit)
{
  /* Creation de l'entrée */
  Network *net = malloc(sizeof(Network));
  net->enter=list_init();
  creat_enter(net->enter,param); // changer list_init pour tester
  size_t lenEnter = list_length(net->enter);

  /* Creation de la sortie */
  Neuro *exit = neuro_init(); 
  load_link(exit);  //A condition d'avoir les liens dans un .txt
  load_rand_link(exit,lenEnter,nbexit); //First use of N.N.
  net->layer->content = exit ; 
  
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
    printf ("Impossible de charger le fichier link.txt\n");
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
  file = fopen("link.txt","w+");
  if (file == NULL){
    printf("Erreur ouverture fichier");
    return;
  }
  printf("File load : OK\n");
  Neuro *tmp = ner;
  while (tmp->next!=NULL)
  {
    printf("try to put | \n");
    fputc('|',file);
    printf ("| puted \n");
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

void load_rand_link (Neuro *exit,size_t nbenter,int nbexit)
{
  Neuro *tmp = exit;
  for (int i = 0 ; i < nbexit ; i++)
  {
    tmp->next = neuro_init();
    tmp = tmp->next;
    tmp->link = list_init();
    List *tmplnk = tmp->link;
    for (size_t j = 0 ; j < nbenter ; j++)
    {
      tmplnk->next = list_init();
      tmplnk = tmplnk->next;
      tmplnk->val = ((float)rand()/(float)(RAND_MAX))*10.0;
    }
  }

}

void calcul_weight(Network *net)
{
  Neuro *tmp = net->layer->content;
  while (tmp->next != NULL)
  {
    tmp = tmp->next;
    List *tmplnk = tmp->link;
    List *tmpent = net->enter;
    double calc = 0;
    while (tmplnk->next != NULL && tmpent->next !=NULL)
    {
      tmplnk=tmplnk->next;
      tmpent=tmpent->next;
      if (tmplnk == NULL || tmpent == NULL)
      {
	printf("Problème: le nombre d'entrée != nombre de lien\n");
	return;
      }
      calc = calc+tmplnk->val*tmpent->val; 
    }
    tmp->weight=1/(1+exp(-calc));
  }
}
