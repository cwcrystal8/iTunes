#ifndef LIBRARY_H
#define LIBRARY_H

struct song_node* add_song(struct song_node *start, struct song_node *new_song);

struct song_node* find_song(struct song_node *start, struct song_node *search_song);

struct song_node* find_artist(struct song_node *start, char artist[]);

void print_letter(struct song_node *start);

void print_artist(struct song_node *start);

void print_library(struct song_node *start);

void shuffle(struct song_node *start);

void delete_song(struct song_node *start, struct song_node *song);

struct song_node* free_list(struct song_node *start);

#endif
