#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "linkedlist.h"
#include "library.h"

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
  song = find_artist(ll, "abs") -> name;
  printf("looking for first song by abs (ui): %s\n", song);

  song = find_artist(ll, "shweak") -> name;
  printf("looking for first song by shweak (skrskr): %s\n", song);

  song = find_artist(ll, "void") -> name;
  printf("looking for first song by void (dfawf): %s\n", song);

  song = find_artist(ll, "dgre") -> name;
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
  printf("Testing free_list\n");
  ll = free_list(ll);
  printf("list after free_list: \n");
  print_list(ll);

  printf("====================================\n\n");
  printf("MUSIC LIBRARY TESTS\n");

  struct song_node *node = NULL;
  node = insert_front(node, "demons", "imagine dragons");
  struct song_node *node_one = NULL;
  node_one = insert_front(node_one, "crystalize", "lindsey stirling");
  struct song_node *node_two = NULL;
  node_two = insert_front(node_two, "bohemian rhapsody", "queen");
  struct song_node *node_three = NULL;
  node_three = insert_front(node_three, "hips don't lie", "shakira");
  struct song_node *node_four = NULL;
  node_four = insert_front(node_four, "sound of silence", "simon and garfunkel");
  struct song_node *node_five = NULL;
  node_five = insert_front(node_five, "hey jude", "the beatles");
  struct song_node *node_six = NULL;
  node_six = insert_front(node_six, "chandelier","sia");
  struct song_node *node_seven = NULL;
  node_seven = insert_front(node_seven, "cheap thrills","sia");
  struct song_node *node_eight = NULL;
  node_eight = insert_front(node_eight, "we will rock you", "queen");


  struct song_node *table[27];
  int i;
  for(i = 0; i < 27; i++){
    table[i] = NULL;
  }
  add_song(table, node);
  add_song(table, node_one);
  add_song(table, node_two);
  add_song(table, node_three);
  add_song(table, node_four);
  add_song(table, node_five);
  add_song(table, node_six);
  add_song(table, node_seven);
  add_song(table, node_eight);

  printf("====================================\n\n");
  printf("Testing print_library\n");
  print_library(table);

  printf("====================================\n\n");
  printf("Testing print_letter\n");
  printf("s list\n");
  print_letter(table, 's');
  printf("k list\n");
  print_letter(table, 'k');


  printf("====================================\n\n");
  printf("Testing find\n");
  printf("Finding [queen - we will rock you]\n");
  find(table, "we will rock you","queen");
  printf("Finding [the beatles - twist and shout]\n");
  find(table, "twist and shout","the beatles");


  printf("====================================\n\n");
  printf("Testing find_artist\n");
  printf("looking for [sia]\n");
  find_artist_library(table, "sia");
  printf("looking for [maroon five]\n");
  find_artist_library(table, "maroon five");


  printf("====================================\n\n");
  printf("Testing remove_song\n");
  printf("removing: queen - bohemian rhapsody\n");
  remove_song(table, node_two);
  print_library(table);
  printf("\nremoving: sia - chandelier\n");
  remove_song(table, node_six);
  print_library(table);


  printf("====================================\n\n");
  printf("Testing clear_library\n");
  clear_library(table);


  printf("====================================\n\n");
  printf("Adding songs to empty library\n");
  struct song_node *a_node = NULL;
  a_node = insert_front(a_node, "demons", "imagine dragons");
  struct song_node *a_node_one = NULL;
  a_node_one = insert_front(a_node_one, "maybe it's time", "bradley cooper");
  struct song_node *a_node_two = NULL;
  a_node_two = insert_front(a_node_two, "bohemian rhapsody", "queen");
  struct song_node *a_node_three = NULL;
  a_node_three = insert_front(a_node_three, "hips don't lie", "shakira");
  struct song_node *a_node_four = NULL;
  a_node_four = insert_front(a_node_four, "shallow", "lady gaga");
  struct song_node *a_node_five = NULL;
  a_node_five = insert_front(a_node_five, "hey jude", "the beatles");
  struct song_node *a_node_six = NULL;
  a_node_six = insert_front(a_node_six, "without me","halsey");
  struct song_node *a_node_seven = NULL;
  a_node_seven = insert_front(a_node_seven, "cheap thrills","sia");
  struct song_node *a_node_eight = NULL;
  a_node_eight = insert_front(a_node_eight, "real friends", "camila cabello");
  struct song_node *a_node_nine = NULL;
  a_node_nine = insert_front(a_node_nine, "dancing queen","abba");
  struct song_node *a_node_ten = NULL;
  a_node_ten = insert_front(a_node_ten, "hotline bling","drake");
  struct song_node *a_node_eleven = NULL;
  a_node_eleven = insert_front(a_node_eleven, "not afraid","eminem");
  struct song_node *a_node_twelve = NULL;
  a_node_twelve = insert_front(a_node_twelve, "centuries","fall out boy");
  struct song_node *a_node_thirteen = NULL;
  a_node_thirteen = insert_front(a_node_thirteen, "whoa whoa whoa","george watsky");
  struct song_node *a_node_fourteen = NULL;
  a_node_fourteen = insert_front(a_node_fourteen, "trumpet","jason derulo");
  struct song_node *a_node_fifteen = NULL;
  a_node_fifteen = insert_front(a_node_fifteen, "because of you","kelly clarkson");
  struct song_node *a_node_sixteen = NULL;
  a_node_sixteen = insert_front(a_node_sixteen, "happier","marshmello");
  struct song_node *a_node_seventeen = NULL;
  a_node_seventeen = insert_front(a_node_seventeen, "adam and eve","nas");
  struct song_node *a_node_eighteen = NULL;
  a_node_eighteen= insert_front(a_node_eighteen, "apologize","onerepublic");
  struct song_node *a_node_nineteen = NULL;
  a_node_nineteen= insert_front(a_node_nineteen, "what about us","pink");
  struct song_node *a_node_twenty = NULL;
  a_node_twenty= insert_front(a_node_twenty, "stay","rihanna");
  struct song_node *a_node_twentyone = NULL;
  a_node_twentyone= insert_front(a_node_twentyone, "yeah","usher");
  struct song_node *a_node_twentytwo = NULL;
  a_node_twentytwo = insert_front(a_node_twentytwo, "riptide","vance joy");
  struct song_node *a_node_twentythree = NULL;
  a_node_twentythree = insert_front(a_node_twentythree,"see you again", "wiz khalifa");
  struct song_node *a_node_twentyfour = NULL;
  a_node_twentyfour = insert_front(a_node_twentyfour, "river flows in you","yiruma");
  struct song_node *a_node_twentyfive = NULL;
  a_node_twentyfive = insert_front(a_node_twentyfive, "dusk till dawn","zayn");
  struct song_node *a_node_twentysix = NULL;
  a_node_twentysix = insert_front(a_node_twentysix, "dollhouse","melanie martinez");


  add_song(table, a_node);
  add_song(table, a_node_one);
  add_song(table, a_node_two);
  add_song(table, a_node_three);
  add_song(table, a_node_four);
  add_song(table, a_node_five);
  add_song(table, a_node_six);
  add_song(table, a_node_seven);
  add_song(table, a_node_eight);
  add_song(table, a_node_nine);
  add_song(table, a_node_ten);
  add_song(table, a_node_eleven);
  add_song(table, a_node_twelve);
  add_song(table, a_node_thirteen);
  add_song(table, a_node_fourteen);
  add_song(table, a_node_fifteen);
  add_song(table, a_node_sixteen);
  add_song(table, a_node_seventeen);
  add_song(table, a_node_eighteen);
  add_song(table, a_node_nineteen);
  add_song(table, a_node_twenty);
  add_song(table, a_node_twentyone);
  add_song(table, a_node_twentytwo);
  add_song(table, a_node_twentythree);
  add_song(table, a_node_twentyfour);
  add_song(table, a_node_twentyfive);
  add_song(table, a_node_twentysix);


  print_library(table);

  printf("====================================\n\n");
  printf("Testing print_arist\n");
  printf("Printing [queen]\n");
  print_artist_library(table,"queen");
  printf("\nPrinting [imagine dragons]\n");
  print_artist_library(table, "imagine dragons");


  printf("====================================\n\n");
  printf("Testing shuffle\n");
  shuffle(table);

  printf("====================================\n\n");


  return 0;
}
