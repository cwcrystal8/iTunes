#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

void print_list(struct song_node *head){

  if (head){
    printf("%s - %s\n", head->artist, head->name);
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

  struct node *new_node = malloc( sizeof(struct song_node) );
  strcpy(new_node->name, new_name);
  strcpy(new_node->artist, new_artist);

  struct song_node *current = head;

  if (songcmp(new_node, current) < 0){
    new_node->next = current;
    return new_node;
  }

  while (songcmp(new_node, current) > 0 && current->next)
    current = current->next;

  if (songcmp(new_node, current) < 0){
    new_node->next = current->next;
    current->next = new_node;
    return head;
  }

  current->next = new_node;
  return head;
}

struct node *find_node(struct node *head, char *artist, char *name){
  struct node *target;
  target->artist = artist;
  target->name = name;

  while(songcmp(target, head) && head)
    head = head->next;

  return head;
}

char *find_song(struct node *head, char *artist){
  while (head){
    if (!strcmp(artist, head->artist))
      return head->name;
    head = head->next;
  }
  return NULL;
}

struct song_node *get_random(struct node *head){
  srand( time(NULL) );
  return get(head, rand() % length(head));
}

struct song_node * free_list(struct song_node *head){

  if (head){
    free_list( head->next );
    free(head);
  }

  return NULL;
}

//============================helpers============================

int length(struct song_node *head){
  if (!head)
    return 0;
  return 1 + length(head->next);
}

struct song_node *get(struct song_node *head, int i){
  if (!i)
    return head;
  return get(head->next, i - 1);
}

int songcmp(struct song_node *n1, struct song_node *n2){
  int val = strcmp(n1->artist, n1->artist);
  if (val)
    return val;
  return strcmp(n1->name, n2->name);
}
