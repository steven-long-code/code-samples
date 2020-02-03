#include <iostream>
#include <iomanip>      // std::setw
#include <stdlib.h>     /* srand, rand */
#include <time.h>

// --- the program implements a hash table. It does not handle collisions
//      It is based on hash_demo1.cpp
// ---- The program tries to detect collisions by storing both key/value in table


using namespace std;

typedef unsigned int uint;

class MyHashTable
{
    struct KeyValuePair
    {
        uint Key;
        uint Value;
    };

private:
    const uint HASH_TABLE_SIZE = 100;
    KeyValuePair *HashTable;

public:
    MyHashTable();
    ~MyHashTable();
    uint myhash(uint Key);
    virtual void put(uint Key, uint Value);  // store the value to the table
    virtual int get(uint Key);  // return -1 if not found

};

uint MyHashTable::myhash(uint Key)
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
    HashTable = new KeyValuePair[HASH_TABLE_SIZE];
    for (uint i=0; i<HASH_TABLE_SIZE; i++)
        HashTable[i].Key = -1;
}

MyHashTable::~MyHashTable()
{
    delete [] HashTable;

}


void MyHashTable::put(uint Key, uint Value)
{
    int index = myhash(Key);
    HashTable[index].Key = Key;
    HashTable[index].Value = Value;
}


int MyHashTable::get(uint Key)
{
    int index = myhash(Key);
    if (HashTable[index].Key != Key)
        return -1;
    else
        return HashTable[index].Value;

}


int main(int argc, char** argv)
{

    MyHashTable table;

    for (uint i=0; i<20; i++)
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

