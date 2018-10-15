struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

void print_list(struct song_node *head_);

struct song_node *insert_front(struct song_node *head, char *new_name, char *new_artist);

struct song_node *insert_in_order(struct song_node *head, char *new_name, char *new_artist);

struct node *find_node(struct node *head, char *artist, char *name);

char *find_song(struct node *head, char *artist);

struct song_node *get_random(struct song_node *head);

struct song_node *remove_node(struct song_node *head, char *name, char *artist);

struct song_node *free_list(struct song_node *head);

//============================helpers============================

int length(struct song_node *head);

struct song_node *get_node(struct song_node *head, int i);

int songcmp(struct song_node *n1, struct song_node *n2);
