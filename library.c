#include "linkedlist.h"
#include "library.h"

void add_song(struct song_node* table[27], struct song_node *new_song){
  int artist = (new_song -> artist)[0] - 'a';
  if(artist > 25){
    artist = 26;
  }
  if(table[artist]){
    table[artist] = insert_in_order(table[artist],new_song->name, new_song->artist);
  }
  else{
    table[artist] = new_song;
  }
}

struct song_node* find(struct song_node* table[27], char *name, char *artist){
  int position = artist[0] - 'a';
  if(position > 25){
    position = 26;
  }
  if(table[position]){
    struct song_node* location = find_node(table[position], name, artist);
    if(location){
      printf("song found! ");
      print_node(location);
      return location;
    }
  }
  printf("song not found\n");
  return NULL;

}

struct song_node* find_artist_library(struct song_node* table[27], char *artist){
  int index = artist[0] - 'a';
  if(index > 25){
    index = 26;
  }
  struct song_node* head = find_artist(table[index], artist);
  if(head){
    printf("artist found! \n");
    print_artist_library(table, artist);
    return head;
  }
  printf("artist not found \n");

}

void print_letter(struct song_node* table[27], char letter){
  int index = letter - 'a';
  if(table[index]){
    print_list(table[index]);
  }
  else{
    printf("no songs found\n");
  }
}

void print_artist_library(struct song_node* table[27], char *artist){
  int index = artist[0] - 'a';
  if(index > 25){
    index = 26;
  }
  struct song_node* head = find_artist(table[index], artist);
  while(head && !strcmp(head->artist,artist)){
    print_node(head);
    head = head->next;
  }
  printf("\n");
}

void print_library(struct song_node* table[27]){
  int i;
  for(i = 0; i < 26; i++){
    if(table[i]){
      printf("%c list\n",i+'a');
      print_list(table[i]);
    }
  }
  if(table[26]){
    printf("symbol list\n");
    table[26];
  }
}

void shuffle(struct song_node* table[27]){
  int indices[9];
  for (int i = 0; i < 9; i ++)
    indices[i] = rand();
  int i = 0;
  while(i < 9){
    int letter = (indices[i] % 26);
    if(table[letter]){
      print_node(get_random(table[letter]));
      //printf("%d ", rand());
    }
    i++;
  }

}

void remove_song(struct song_node* table[27], struct song_node *song){
  int artist = (song -> artist)[0] - 'a';
  if(artist > 25){
    artist = 26;
  }
  struct song_node *location = find_node(table[artist], song -> name, song -> artist);
  if(location){
    table[artist] = remove_node(table[artist], song -> name, song -> artist);
  }
}

void clear_library(struct song_node* table[27]){
  int i;
  for(i = 0; i < 27; i++){
    table[i] = free_list(table[i]);
  }
}
