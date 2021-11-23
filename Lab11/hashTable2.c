#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  TEXTSIZE 21

typedef char* item_t;

typedef struct hash {
    item_t *table;
    int    size;
    int    hash_key;
} hash_t;

hash_t *init_hashtable(int m,int hash_key)
{
    hash_t *h = (hash_t*)malloc(sizeof(hash_t));
    h->table = (item_t *)malloc(sizeof(item_t)*m);
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
    int i,index = hash(h->size,h->hash_key,text);
    item_t tmp = (char *)malloc(sizeof(char)*TEXTSIZE);
    strcpy(tmp,text);
    for(i=0;i<h->size;i++)
    {
        if (h->table[(index+(i+i*i)/2)%h->size] == NULL)
        {
            h->table[(index+(i+i*i)/2)%h->size] = tmp;
            break;
        }    
    }
}

int search(hash_t *h,char text[])
{
    int i,index = hash(h->size,h->hash_key,text);
    for(i=0;i<h->size;i++)
    {
        // printf("hash:%d\n",(index + (i + i*i)/2) % h->size);
        if (h->table[(index+(i+i*i)/2)%h->size] == NULL)
            return -1;
        if(strcmp(h->table[(index+(i+i*i)/2)%h->size],text)==0)
            return (index+(i+i*i)/2)%h->size;
    }
    return -1;
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