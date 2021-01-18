#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"

void insert(trie *ele, char *word) 
{
 trie *root = ele;
 int len = strlen(word);		
 for (int i = 0; i < len; i++) 
  {
   trie *curr = ele->subtrie[word[i] % 97];
   if (curr == NULL) 
   {
    curr = malloc (sizeof (trie));
    curr->isEnd = 0;
    for(int i = 0; i < 26; i++) 
     curr->subtrie[i] = NULL;
   }
  //puts the isEnd integer as 0 for end of words
   if(i + 1 == len)
    curr->isEnd = 1;
   ele->subtrie[word[i] % 97] = curr;
   ele = ele->subtrie[word[i] % 97];
  }
 ele = root;
}

char *append (char *slice, char part) 
{
 //This function appends the string by a character and passes it back to the recursive statement of recheck 
 
 //printf("%s\n",slice);
 //printf("%c\n",part);
 int length=strlen(slice)+2;
 //printf("%d\n",length);
 char *str = malloc (sizeof(char)*length);
 str[0]='\0';
 int i = length-2;
 strncat(str,slice,i);
 str[i++] = part;
 str[i] = '\0';
 return str;
}

void recheck(trie *ele, char *slice) 
{
 if (ele == NULL) 
  return;
 if (ele->isEnd) 
  printf("%s\n", slice);
 //Finds all the aphabets inside the curr ele and calls recursively if the subtree for that alphabet is not null
 for (int i = 0; i < 26; i++)
  if(ele->subtrie[i] != NULL)
   {char *kill=append(slice, i + 97);
   recheck(ele->subtrie[i],kill);
   free(kill);
   }
}

void autofill(trie *ele, char *pfix) 
{
 int len = strlen (pfix);
 //This if checks if the first character of the word is in the trie structure or not 
 if(ele->subtrie[pfix[0]%97]==NULL)
 {
  writ(ele,pfix);
  return;
 }
 //This checks if each char in the searched word is present and writes the word in the text file if not present 
 for (int i = 0; i < len; i++){
  if(ele->subtrie[pfix[i] % 97] != NULL)
   ele = ele->subtrie[pfix[i] % 97];
  else {
   writ(ele,pfix);
   return;}
  }
 recheck(ele, pfix);
}
void writ(trie *ele,char *word)
{
//This function adds the words that are't present in the trie to the text file and to the trie
printf("This word is added to the text file as it was not present\n");
FILE *fpointer=fopen("die.txt","a");
fprintf(fpointer,"%s\n",word);
insert(ele,word);
fclose(fpointer);
}


