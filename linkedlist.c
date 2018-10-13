#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

void print_list(struct song_node *head){

  if (head == NULL)
    printf("NULL\n");
  else{
    printf("Song: %s Artist: %s\n", head->name, head->artist);
    print_list(head->next);
  }

}

struct song_node *insert_front(struct song_node *head, char *new_name, char *new_artist){

  struct node *new_node = malloc( sizeof(struct song_node) );
  strcpy(new_node->name, new_name);
  strcpy(new_node->artist, new_artist);
  new_node->next = head;

  return new_node;
}

struct song_node *insert_in_order(struct song_node *head, char *new_name, char *new_artist){
// binary add not done
  struct node *new_node = malloc( sizeof(struct song_node) );
  strcpy(new_node->name, new_name);
  strcpy(new_node->artist, new_artist);

  int lo = 0, med, hi = length(head) - 1;
  while (lo <= hi){
    med = (lo + hi) / 2;
    int cmp_artist = strcmp(new_artist, get(head, med)->artist);

    if (!cmp_artist){
      int cmp_name = strcmp(new_name, get(head, med)->name);
      if (!cmp_name){
        new_node->next = get(head, med);
        get(head, med - 1)->next = new_node;
        return new_node;
      }
    }

  }
}

int length(struct song_node *head){
  if (head == NULL)
    return 0;
  return 1 + length(head->next);
}

struct song_node *get(struct song_node *head, int i){
  if (!i)
    return head;
  return get(head->next, i - 1);
}

struct node * free_list(struct node *head){

  //print_list(head);
  if (head != NULL){
    free(head);
    free_list( head->next );
  }

  return NULL;
}
