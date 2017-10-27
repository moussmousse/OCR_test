/* USE_NEURO.c
 * Contain function tu use the neuronal netword */

#include <stdio.h>
#include <stdlib.h>

#include "use_neuro.h"


/* Information : 
 * On souhait que le réseau de neuronne soit capable de reconaitre
 * tout les caractère ASCII codés de 40 à 176 soit 136 sorties.
 *
 * On applique le réseau de neuronne sur des matrices 16x16.
 * soit une list binaire de 256 éléments.
 */

/*Work 1c prend en paramètre une matrice 16x16 sous forme de list*/
char work_1c(List *enter)
{
  Network *net = init_neuro_net_1l(enter);
  load_rand_link (net->layer->content,256,136);
  return 'a';
}


