#include "header.h"

int *fileHandle(char *path) {
  FILE *fptr;
  fptr = fopen(path, "r");
  if (!fptr) {
    printf("File doesnt work\n");
    return(0);
  }
  char ch, ch2;
  char *str, *token;
  int i = 0, j = 0, aux;
  int *arr;
  arr = malloc(sizeof(int) * 64);
  ch = fgetc(fptr);
  while (ch != EOF) {
    ch = fgetc(fptr);
    i++;
  }
  str = malloc(sizeof(char) * i);
  rewind(fptr);
  ch = fgetc(fptr);
  i = 0;
  while (ch != EOF) {
    str[i] = ch;
    i++;
    ch = fgetc(fptr);
  }
  int k = 0;
  while (str[k]) {
    if (str[k] == '\n') {
      str[k] = ' ';
    }
    k++;
  }
  k = 0;
  token = strtok(str, " ");
  while (token) {
    aux = atoi(token);
    arr[k] = aux;
    token = strtok(NULL, " ");
    k++;
  }
  free(str);
  fclose(fptr);
  return(arr);
}
