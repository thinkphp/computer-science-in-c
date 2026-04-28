#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // pentru SIZE_MAX
#include <string.h>

#define EMPTY 0
#define TOMBSTONE -1
#define HASH_SIZE 1062599

struct Entry
{
    int value;
};

struct Hash
{
    struct Entry *list;
    int size;
};

struct Hash *createHash(int hashSize)
{
    struct Hash *newHash = (struct Hash *)malloc(sizeof(struct Hash));
    newHash->list = (struct Entry *)calloc(hashSize, sizeof(struct Entry));
    newHash->size = hashSize;

    return newHash;
}

void hashInsert(struct Hash *hash, int num)
{
    int index = num % HASH_SIZE;
    struct Entry *list = hash->list;
    while (list[index].value > 0 && list[index].value != num)
    {
        ++index;
        index %= HASH_SIZE;
    }

    hash->list[index].value = num;
}

void hashErase(struct Hash *hash, int num)
{
    int index = num % HASH_SIZE;
    struct Entry *list = hash->list;
    while ((list[index].value > 0 || list[index].value == TOMBSTONE) && list[index].value != num)
    {
        ++index;
        index %= HASH_SIZE;
    }

    if ((hash->list)[index].value == num)
    {
        hash->list[index].value = TOMBSTONE;
    }
}

int hashFind(struct Hash *hash, int num)
{
    int index = num % HASH_SIZE;
    struct Entry *list = hash->list;
    while ((list[index].value > 0 || list[index].value == TOMBSTONE) && list[index].value != num)
    {
        ++index;
        index %= HASH_SIZE;
    }

    return ((hash->list)[index].value == num) ? 1 : 0;
}
int main()
{
    FILE *in = fopen("hashuri.in", "r"), *out = fopen("hashuri.out", "w");
    int type;
    int number;
    int N;
    struct Hash *hashTable = createHash(HASH_SIZE);

    fscanf(in, "%d", &N);
    for (int i = 0; i < N; ++i)
    {
        fscanf(in, "%d %d", &type, &number);
        if (type == 1)
        {
            hashInsert(hashTable, number);
        }
        else
        {
            if (type == 2)
            {
                hashErase(hashTable, number);
            }
            else
            {
                if (type == 3)
                {
                    fprintf(out, "%d\n", hashFind(hashTable, number));
                }
            }
        }
    }

    fclose(in);
    fclose(out);
    return 0;
}
