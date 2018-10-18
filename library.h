#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "linkedlist.h"

#ifndef LIBRARY_H
#define LIBRARY_H

void add_song(struct song_node* table[27], struct song_node *new_song);

struct song_node* find(struct song_node* table[27], char *name, char *artist);

struct song_node* find_artist_library(struct song_node* table[27], char *artist);

void print_letter(struct song_node* table[27], char letter);

void print_artist_library(struct song_node* table[27], char *artist);

void print_library(struct song_node* table[27]);

void shuffle(struct song_node* table[27]);

void remove_song(struct song_node* table[27], struct song_node *song);

void clear_library(struct song_node* table[27]);

#endif
