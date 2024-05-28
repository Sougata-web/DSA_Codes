#include <stdio.h>
#include <stdlib.h>

#define SIZE 10 // Size of the hash table

// Hash Table structure
struct HashTable
{
    int *keys;
    int *values;
    int capacity;
};

// Function to create a new Hash Table
struct HashTable *createHashTable(int capacity)
{
    struct HashTable *hashTable = (struct HashTable *)malloc(sizeof(struct HashTable));
    if (hashTable == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    hashTable->capacity = capacity;
    hashTable->keys = (int *)malloc(capacity * sizeof(int));
    hashTable->values = (int *)malloc(capacity * sizeof(int));
    if (hashTable->keys == NULL || hashTable->values == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    // Initialize all keys and values to -1 (indicating empty slot)
    for (int i = 0; i < capacity; i++)
    {
        hashTable->keys[i] = -1;
        hashTable->values[i] = -1;
    }
    return hashTable;
}

// Hash function (modulus division)
int hashFunction(int key)
{
    return key % SIZE;
}

// Function to search for a key in the Hash Table
int search(struct HashTable *hashTable, int key)
{
    int index = hashFunction(key);
    int originalIndex = index;
    while (hashTable->keys[index] != -1)
    {
        if (hashTable->keys[index] == key)
        {
            return index; // Key found
        }
        index = (index + 1) % hashTable->capacity; // Move to next slot (linear probing)
        if (index == originalIndex)
        {
            break; // Reached back to original index, table is full
        }
    }
    return -1; // Key not found
}

// Function to insert a key-value pair into the Hash Table
void insert(struct HashTable *hashTable, int key, int value)
{
    int index = hashFunction(key);
    int originalIndex = index;
    while (hashTable->keys[index] != -1 && hashTable->keys[index] != key)
    {
        index = (index + 1) % hashTable->capacity; // Move to next slot (linear probing)
        if (index == originalIndex)
        {
            printf("Hash table is full. Unable to insert.\n");
            return;
        }
    }
    hashTable->keys[index] = key;
    hashTable->values[index] = value;
}

int main()
{
    struct HashTable *hashTable = createHashTable(SIZE);

    // Inserting key-value pairs into the Hash Table
    insert(hashTable, 1, 10);
    insert(hashTable, 2, 20);
    insert(hashTable, 11, 30);
    insert(hashTable, 21, 40);

    // Searching for keys in the Hash Table
    int searchKey = 11;
    int result = search(hashTable, searchKey);
    if (result != -1)
    {
        printf("Key %d found at index %d\n", searchKey, result);
    }
    else
    {
        printf("Key %d not found in the Hash Table\n", searchKey);
    }

    return 0;
}
