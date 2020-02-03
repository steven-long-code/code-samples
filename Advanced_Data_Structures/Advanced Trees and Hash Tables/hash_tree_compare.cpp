#include <iostream>
#include <map>
#include <unordered_map>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std;

// comment out the next line if you want to use map
//#define USING_HASHING

const int TABLE_SIZE = 1000000;

string getRandomString()
{
    string s = "012345678901234567890123456789";
    for (unsigned int i=0; i<s.length(); i++)
    {
        int c = rand() % 26;
        s[i] = 'a' + c;
    }
    return s;
}

int main(int argc, char** argv)
{

#ifdef USING_HASHING
    unordered_map<string,int> words;
    cout << "Using hash table\n";
#else
    map<string,int> words;
    cout << "Using map (red-black tree)\n";
#endif


    string WordToFind = getRandomString();
    ++ words[WordToFind];

    for (int i=0; i< TABLE_SIZE; i++)
    {
        string s = getRandomString();
        ++ words[s];
    }
    cout << "Table filled. ";



    cout << "Now start timing searching performance - find a word in the table\n";

    clock_t tStart = clock();

    for (int i = 0; i< 10000; i++)
        for (int j = 0; j< 1000; j++)
            words.find(WordToFind);
    cout << "  Execution Time: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << " sec" << endl;



    cout << "\nNow start timing searching performance - find a word NOT in the table\n";

    tStart = clock();

    WordToFind = "_QQQ_";
    for (int i = 0; i< 10000; i++)
        for (int j = 0; j< 1000; j++)
            words.find(WordToFind);
    cout << "  Execution Time: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << " sec" << endl;

}
