#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <glib.h>
#include <errno.h>
#include <ctype.h>

#define BUFFER 1024
//Helper function to print the results
void print_results(gpointer key, gpointer value, gpointer usrdata){
  printf(usrdata, key,  GPOINTER_TO_INT(value));
}

/* Finds word - If it exists add 1 to value otherwise add to list */
void update_histogram(GHashTable* hash, char* input){
  gpointer res = g_hash_table_lookup(hash, input);
  if (res != NULL){
    g_hash_table_replace(hash, input, GINT_TO_POINTER(res) + 1);
  } else{
    g_hash_table_insert(hash, input, GINT_TO_POINTER(1));
  }
}

/* Counts word Occurances */
int read(GHashTable* hash, char* input){
  int c;
  FILE *inFile;
  char word[BUFFER];
  int wordlen = 0;

  if ((inFile = fopen(input, "r"))== 0){
    fprintf(stderr, "Cannot open file\n");
    return EXIT_FAILURE;
  }
  else {
    int isWord = 0;
    while ((c=fgetc(inFile)) != EOF){
      if (c == '\n'){
        if (isWord){
          word[wordlen] = '\0';
          wordlen = 0;
          isWord = 0;
        }
        continue;
      }
      if (!isalpha(c)){
        if (isWord){
          word[wordlen] = '\0';
          isWord = 0;
          wordlen = 0;
          update_histogram(hash, strdup(word));
        }
      }
      else {
        isWord = 1;
        word[wordlen++] =(char)(tolower(c));
      }
    }
  }
  return 0;
}

int main(int argc, char** argv){
  char *input = argv[1];
  GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);
  read(hash, input);
  g_hash_table_foreach(hash, (GHFunc)print_results, "%s: %d\n");
}
