#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  TEXTSIZE 21

typedef struct item {
    char   *text;
    struct item *next;
} item_t;

typedef struct hash {
    item_t **table;
    int    size;
    int    hash_key;
} hash_t;

hash_t *init_hashtable(int m,int hash_key)
{
    hash_t *h = (hash_t*)malloc(sizeof(hash_t));
    h->table = (item_t**)malloc(sizeof(item_t*)*m);
    h->size = m;
    h->hash_key = hash_key;
    int i;
    for(i=0;i<m;i++)
        h->table[i] = NULL;
    return h;
}

unsigned int hash(int m,int hash_key,char x[])
{
    int i;
    unsigned int hash_value=0;
    for(i=0;i<strlen(x);i++)
        hash_value = hash_key*hash_value + x[i];
    return hash_value%m;
}

void insert(hash_t *h,char text[])
{
    int index = hash(h->size,h->hash_key,text);
    item_t *a;
    item_t *tmp = (item_t *)malloc(sizeof(item_t));
    tmp->text = (char *)malloc(sizeof(char)*TEXTSIZE);
    strcpy(tmp->text,text);
    if(h->table[index] == NULL)
    {
        tmp->next = NULL;
        h->table[index] = tmp;
    }
    else
    {
        a = h->table[index];
        tmp->next = a;
        h->table[index] = tmp;
    }
}

int search(hash_t *h,char text[])
{
    int index = hash(h->size,h->hash_key,text);
    item_t *run = h->table[index];
    if (h->table[index] == NULL)
        return -1;
    else
    {
        while(run!=NULL)
        {
            if(strcmp(run->text,text)==0)
                return index;
            run = run->next;
        }
        return -1;
    }
}

int main(void) {
    hash_t *hashtable = NULL;
    char   *text = NULL;
    int    m, n, i, hash_key;
    int    command;

    scanf("%d %d %d", &m, &n, &hash_key);
    hashtable = init_hashtable(m, hash_key);
    text = (char *)malloc(sizeof(char)*TEXTSIZE);

    for (i=0; i<n; i++) {
        scanf("%d %s", &command, text);
        switch (command) {
        case 1:
            insert(hashtable, text);
            break;
        case 2:
            printf("%d\n", search(hashtable, text));
            break;
        }
    }
    return 0;
}