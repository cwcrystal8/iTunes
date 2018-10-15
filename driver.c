#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

int main(){

  struct song_node *ll;
  ll = insert_front(ll, "skr", "skr");
  print_list(ll);
  
  return 0;
}
