#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct song_node {
  char name[100];
  char artist[100];
  struct song_node *next;
};

//============================helpers============================

int length(struct song_node *head);

struct song_node *get_node(struct song_node *head, int i);

int songcmp(struct song_node *n1, struct song_node *n2);

//============================functions============================

void print_node(struct song_node *n);

void print_list(struct song_node *head_);

struct song_node *insert_front(struct song_node *head, char *new_name, char *new_artist);

struct song_node *insert_in_order(struct song_node *head, char *new_name, char *new_artist);

struct song_node *find_node(struct song_node *head, char *name, char *artist);

struct song_node *find_artist(struct song_node *head, char *artist);

struct song_node *get_random(struct song_node *head);

struct song_node *remove_node(struct song_node *head, char *name, char *artist);

struct song_node *free_list(struct song_node *head);

#endif
