#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node {
  char name[100];
  char artist[100];
  struct song_node *next;
};

//============================helpers============================

int length(struct song_node *head){
  if (!head)
    return 0;
  return 1 + length(head->next);
}

struct song_node *get_node(struct song_node *head, int i){
  if (!i)
    return head;
  return get_node(head->next, i - 1);
}

int songcmp(struct song_node *n1, struct song_node *n2){
  int val = strcmp(n1->artist, n2->artist);
  if (val)
    return val;
  return strcmp(n1->name, n2->name);
}

//============================functions============================

void print_node(struct song_node *n){
  printf("%s - %s\n", n->artist, n->name);
}

void print_list(struct song_node *head){

  if (!head)
    printf("\n");
  else {
    print_node(head);
    print_list(head->next);
    //head = head->next;
  }

}

struct song_node *insert_front(struct song_node *head, char *new_name, char *new_artist){

  struct song_node *new_node = malloc( sizeof(struct song_node) );
  strcpy(new_node->name, new_name);
  strcpy(new_node->artist, new_artist);
  new_node->next = head;

  return new_node;
}

struct song_node *insert_in_order(struct song_node *head, char *new_name, char *new_artist){

  struct song_node *new_node = malloc( sizeof(struct song_node) );
  strcpy(new_node->name, new_name);
  strcpy(new_node->artist, new_artist);

  // printf("%d", songcmp(new_node, current));
  if (songcmp(new_node, head) < 0){
    new_node->next = head;
    return new_node;
  }

  struct song_node *current = head;

  while (current->next && songcmp(new_node, current->next) > 0)
    current = current->next;

  if (!current->next){
    current->next = new_node;
    return head;
  }

  new_node->next = current->next;
  current->next = new_node;
  return head;
}

struct song_node *find_node(struct song_node *head, char *name, char *artist){

  
  while (head){
    if (!strcmp(name, head->name) &&
        !strcmp(artist, head->artist))
      return head;
    head = head->next;
  }
  return head;
}

char *find_artist(struct song_node *head, char *artist){
  while (head){
    if (!strcmp(artist, head->artist))
      return head->name;
    head = head->next;
  }
  return NULL;
}

struct song_node *get_random(struct song_node *head){
  return get_node(head, rand() % length(head));
}

struct song_node *remove_node(struct song_node *head, char *name, char *artist){
  struct song_node *target;
  strcpy(target->name, name);
  strcpy(target->artist, artist);

  struct song_node *temp;
  if (!songcmp(target, head)){
    temp = head->next;
    free(head);
    return temp;
  }

  struct song_node *current = head;
  while (current->next && songcmp(target, current->next))
    current = current->next;

  if (!current->next)
    return head;

  temp = current->next;
  current->next = current->next->next;
  free(temp);
  return head;
}

struct song_node *free_list(struct song_node *head){

  if (head){
    free_list( head->next );
    free(head);
  }

  return NULL;
}
