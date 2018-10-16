#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "linkedlist.h"

int main(){

  struct song_node *ll = NULL;
  ll = insert_front(ll, "skrskr", "shweak");
  ll = insert_front(ll, "xd", "ouch");
  ll = insert_front(ll, "smd", "oof");
  ll = insert_front(ll, "tau", "alpha");

  ll = insert_in_order(ll, "ui", "abs");
  ll = insert_in_order(ll, "qwer", "n0 u");
  ll = insert_in_order(ll, "asdf", "printf");
  ll = insert_in_order(ll, "dfawf", "void");

  //char a[] = "sdfawed";
  //printf("%s", strcpy("gaefae", a));

  printf("LINKED LIST TESTS\n====================================\n\nTesting print_list:\n");
  print_list(ll);
  
  printf("====================================\n\n");
  printf("Testing print_node\n");
  print_node(ll);
  
  printf("====================================\n\n");
  printf("Testing find_node\n");
  struct song_node *target;
  target = find_node(ll, "skrskr", "shweak");
  printf("looking for shweak - skrskr(exists): %s - %s\n", target->artist, target->name);

  target = find_node(ll, "qwer", "n0 u");
  printf("looking for n0 u - qwer(exists): %s - %s\n", target->artist, target->name);

  target = find_node(ll, "dfawf", "void");
  printf("looking for void - dfawf(exists): %s - %s\n", target->artist, target->name);

  target = find_node(ll, "ouk", "sde");
  printf("looking for sde - ouk(does not exist): %p\n", target);

  printf("====================================\n\n");
  printf("Testing find_artist\n");
  char *song;
  song = find_artist(ll, "abs");
  printf("looking for first song by abs (ui): %s\n", song);

  song = find_artist(ll, "shweak");
  printf("looking for first song by shweak (skrskr): %s\n", song);

  song = find_artist(ll, "void");
  printf("looking for first song by void (dfawf): %s\n", song);

  song = find_artist(ll, "dgre");
  printf("looking for first song by dgre (does not exist): %p\n", song);
  
  printf("====================================\n\n");
  printf("Testing songcmp (helper function)\n");
  printf("comparing abs - ui to itself: %d\n", songcmp(ll, ll));
  printf("comparing abs - ui to oof - smd: %d\n", songcmp(ll, ll->next->next->next));
  printf("comparing n0 u - qwer to alpha - tau: %d\n", songcmp(ll->next->next, ll->next));
  
  printf("====================================\n\n");
  printf("Testing random\n");
  srand( time(NULL) );
  print_node( get_random(ll) );
  print_node( get_random(ll) );
  print_node( get_random(ll) );

  printf("====================================\n\n");
  printf("Testing remove\n");
  ll = remove_node(ll, "ui", "abs");
  printf("removing abs - ui:\n");
  print_list(ll);

  ll = remove_node(ll, "xd", "ouch");
  printf("removing ouch - xd:\n");
  print_list(ll);

  ll = remove_node(ll, "dfawf", "void");
  printf("removing void - dfawf:\n");
  print_list(ll);

  ll = remove_node(ll, "wefav", "eeeee");
  printf("removing eeeee - wefav (does not exist):\n");
  print_list(ll);

  printf("====================================\n\n");
  printf("Testing remove\n");
  printf("REPLACE LATER\n");

  printf("====================================\n\n");
  printf("Testing free_list\n");
  printf("REPLACE LATER\n");

  printf("====================================\n\n");
  printf("MUSIC LIBRARY TESTS\n");

  printf("====================================\n\n");
  printf("Testing print_library\n");
  printf("REPLACE LATER\n");

  printf("====================================\n\n");
  printf("Testing print_letter\n");
  printf("REPLACE LATER\n");

  printf("====================================\n\n");
  printf("Testing find\n");
  printf("REPLACE LATER\n");

  printf("====================================\n\n");
  printf("Testing find_artist\n");
  printf("REPLACE LATER\n");

  printf("====================================\n\n");
  printf("Testing remove_song\n");
  printf("REPLACE LATER\n");

  printf("====================================\n\n");
  printf("Testing clear_library\n");
  printf("REPLACE LATER\n");

  printf("====================================\n\n");
  printf("Adding songs to empty library\n");
  printf("REPLACE LATER\n");

  printf("====================================\n\n");
  printf("Testing print_arist\n");
  printf("REPLACE LATER\n");

  printf("====================================\n\n");
  printf("Testing shuffle\n");
  printf("REPLACE LATER\n");

  printf("====================================\n\n");

  

  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");

  return 0;
}
