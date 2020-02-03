#include <iostream>
#include <iomanip>      // std::setw
#include <stdlib.h>     /* srand, rand */
#include <time.h>

//  hash_demo4.cpp
// --- the program implements a hash table. It does  handle collisions
//      by using hash buckets


using namespace std;

typedef unsigned int uint;

class MyHashTable
{
    struct KeyValuePair
    {
        int Key;
        int Value;
        KeyValuePair * Next;
    };

private:
    const uint HASH_TABLE_SIZE = 100;
    KeyValuePair **HashTable;

public:
    MyHashTable();
    ~MyHashTable();
    uint myhash(int Key);
    virtual void put(int Key, int Value);  // store the value to the table
    virtual int get(int Key);  // return -1 if not found

};

uint MyHashTable::myhash(int Key)
{
    uint hashValeu = 0;
    while (Key)
    {
        hashValeu += (Key % 100);
        Key /= 100;
    }
    return hashValeu % HASH_TABLE_SIZE;
}

MyHashTable::MyHashTable()
{
    HashTable = new KeyValuePair*[HASH_TABLE_SIZE];
    for (uint i=0; i<HASH_TABLE_SIZE; i++)
        HashTable[i] = NULL;
}

MyHashTable::~MyHashTable()
{
    // we need to remove all hash chains
    // This portion is not implemented
    delete [] HashTable;
}


void MyHashTable::put(int Key, int Value)
{
    uint index = myhash(Key);
    KeyValuePair *p = HashTable[index];

    if (p != NULL)
        cout << "  put: location = " << index << "  none empty chain\n";

    KeyValuePair *pData = new KeyValuePair;
    pData->Key = Key;
    pData->Value = Value;
    pData->Next = p;

    HashTable[index] = pData;
}


int MyHashTable::get(int Key)
{
    uint index = myhash(Key);

    KeyValuePair *p = HashTable[index];

    if ( p == NULL)
        return -1;

    while (p != NULL)
    {
        if (p->Key == Key)
            return p->Value;
        p = p->Next;
        cout << "  get: location = " << index << "  go to next\n";
    }

    cout << "Error: we should not be here\n";
    exit(1);

}


int main(int argc, char** argv)
{

    MyHashTable table;

    for (uint i=0; i<30; i++)
    {
        int key = rand() % 999999;
        int value = rand() % 9999;
        cout << "Key = " << setw(6) << key
             << "   Hash =  " << setw(3) << table.myhash(key)
             << "     Value = " << setw(5) << value
             << endl;

        table.put(key, value);
    }

    while (1)
    {
        uint k;
        cout << "Please enter a key value:";  // try to enter a key where a collision has occured
        cin >> k;
        int v = table.get(k);

        if ( v == -1 )
            cout << "Not in table\n";
        else
            cout << "The value is " << v << endl;
    }

}

