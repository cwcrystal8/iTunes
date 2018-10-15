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
  target = find_node(ll, "qwer", "n0, u");

  return 0;
}
