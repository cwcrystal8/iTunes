#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

int main(){

  struct song_node *ll;
  ll = insert_front(ll, "skrskr", "shweak");
  ll = insert_front(ll, "xd", "ouch");
  ll = insert_front(ll, "smd", "oof");
  ll = insert_front(ll, "tau", "alpha");

  ll = insert_in_order(ll, "ui", "abs");
  ll = insert_in_order(ll, "qwer", "n0 u");
  ll = insert_in_order(ll, "asdf", "printf");
  ll = insert_in_order(ll, "dfawf", "void");
  print_list(ll);

  struct song_node *target;
  // target = find_node(ll, "qwer", "n0, u");

  printf("LINKED LIST TESTS\n====================================\n\nTesting print_list:\n");
  printf("REPLACE LATER\n");
  printf("====================================\n\n");
  printf("Testing print_node\n");
  printf("REPLACE LATER\n");
  
  printf("====================================\n\n");
  printf("Testing find_node\n");
  printf("REPLACE LATER\n");

  printf("====================================\n\n");
  printf("Testing find_artist\n");
  printf("REPLACE LATER\n");

  printf("====================================\n\n");
  printf("Testing songcmp\n");
  printf("REPLACE LATER\n");

  printf("====================================\n\n");
  printf("Testing random\n");
  printf("REPLACE LATER\n");

  printf("====================================\n\n");
  printf("Testing remove\n");
  printf("REPLACE LATER\n");

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
  printf("Testing shuffle");
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
