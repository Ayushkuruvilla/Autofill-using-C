typedef struct n 
{// isEnd checks for the end of a word
  struct n *subtrie[26];
  int isEnd;
}trie;
void insert(trie *ele,char *word);
char *append(char *slice,char part);
void recheck(trie *ele,char *slice);
void autofill(trie* ele,char *prefix);
void writ(trie * ele,char *word);
