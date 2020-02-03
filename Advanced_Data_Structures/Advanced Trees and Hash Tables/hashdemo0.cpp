#include <iostream>
#include <iomanip>      // std::setw
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <set>

// --- the program shows three different hashing functions
// --- it also shows that collision can occur.

using namespace std;

typedef unsigned int uint;

const uint HASH_TABLE_SIZE = 100;

// use this prime value to perform modulus operation
// make sure it is smaller than the hash table size
const uint HASH_TABLE_SIZE_MOD = 97;

uint myhash(uint Key)
{
    return Key % HASH_TABLE_SIZE_MOD;
}


uint myhash2(uint Key)
{
    //const uint D = 57;
    uint hashValeu = 0;

    while (Key)
    {
        hashValeu += (Key % 100);
        Key /= 100;
    }

    return hashValeu % HASH_TABLE_SIZE_MOD;
}

uint djb2_hash(uint Key)
    {
        uint hash = 5381;
        while (Key)
        {
            int c = Key % 10;
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
            Key /= 10;
        }

        return hash % HASH_TABLE_SIZE_MOD;
    }




int main(int argc, char** argv)
{
    set<uint> s1,s2,s3;
    uint h1, h2, h3;
    string conflict1, conflict2, conflict3;

    for (uint i=0; i<40; i++)
    {
        int key = rand() % 999999;

        h1 = myhash(key);
        h2 = myhash2(key);
        h3 = djb2_hash(key);

        conflict1 =  ( s1.find(h1) == s1.end() ? "   " : "(C)" );
        conflict2 =  ( s2.find(h2) == s2.end() ? "   " : "(C)" );
        conflict3 =  ( s3.find(h3) == s3.end() ? "   " : "(C)" );

        s1.insert(h1);
        s2.insert(h2);
        s3.insert(h3);

        cout << setw(6) << key
             << " - " << setw(3) << h1 << conflict1
             << " - " << setw(3) << h2 << conflict2
             << " - " << setw(3) << h3 << conflict3
             << endl;
    }

}
