#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define INPUT_LENGTH 10
#define MAX_ROWS_LENGTH 10
#define MAX_RUNE_LENGTH 4001

void replace(char *, char *, char *);

int main() {
  int i, j, len;
  char bufstr[5];
  char replacement[5];
  char **input;
  char rows[MAX_ROWS_LENGTH];
  char rune[MAX_RUNE_LENGTH];
  char **fragments;

  fgets(rows, MAX_ROWS_LENGTH, stdin);
  input = calloc(atoi(rows), sizeof(char*));
  for(i=0;i<atoi(rows);i++) {
    input[i] = malloc(INPUT_LENGTH * sizeof(char));
    fgets(input[i], INPUT_LENGTH, stdin);
    strtok(input[i], "\n");
  }
  fgets(rune, MAX_RUNE_LENGTH, stdin);
  len = strlen(rune);
  fragments = malloc(sizeof(*fragments) * len / 4);
  for(i=0;i<(len/4);i++) {
    fragments[i] = strndup(rune + 4 * i, 4);
  }
  for(i=0;i<atoi(rows);i++) {
    memcpy(bufstr, &input[i][2], 4);
    bufstr[4] = '\0';
    for(j=0;j<(len/4);j++) {
      if(strcmp(fragments[j],bufstr)==0) {
        fragments[j][0] = input[i][0];
        fragments[j][1] = '\0';
      }
    }
  }
  for(i=0;i<atoi(rows);i++) {
    free(input[i]);
  }
  free(input);
  for(i=0;i<(len/4);i++) {
    if(strlen(fragments[i])==4) {
      fragments[i][0] = '?';
      fragments[i][1] = '\0';
    }
  }
  for(i=0;i<(len/4);i++) {
    fprintf(stdout, "%s", fragments[i]);
  }
}
