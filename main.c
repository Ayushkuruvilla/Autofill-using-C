#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"

int main() 
{
//Creating a root trie and initializing everything to NULL. 
 trie n;
 n.isEnd = 0;
 for (int i = 0; i < 26; i++) 
  n.subtrie[i] = NULL;
 //die.txt is the file that contains some words and to which words can be written so as to access them in the trie  
 FILE *fp = fopen ("die.txt", "r");
 char str[25];
 //reading from a file die.txt and inserting into trie structure.
 while (fscanf (fp, "%s", str)!=EOF) 
 {  
  insert (&n, str);
 }
 fclose (fp);
 char input[100];
 while (1) 
 { 
  printf("Enter the word to be searched:\n");
  printf (">> ");
  scanf ("%s", input);
  autofill(&n, input);
 }
 return 0;
}
