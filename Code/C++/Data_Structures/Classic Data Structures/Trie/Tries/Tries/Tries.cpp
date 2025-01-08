// Tries.cpp | https://www.youtube.com/watch?v=3CbFFVHQrk4&list=PLm0fFUL4gEt_iadS0BdsMaLNUpATpjD-9&index=7 | https://www.youtube.com/watch?v=dOXfffhl4uI
// Gale from HackerRank | https://www.youtube.com/watch?v=zIjfhVPRZCg&list=PLm0fFUL4gEt_iadS0BdsMaLNUpATpjD-9&index=5
// CS50x | https://www.youtube.com/watch?v=X8h4dq9Hzq8 | 02:04:00 mark
// Trie is a tree and a lookup table in one, 
// Used for retrieving strings or sequence of symbols (ASCII)
// A Trie is often called a Prefix trees or Digital trees.
// Allow us to efficiently check if a specific string is in our set of strings.
// Conceptually: trie is a tree, nodes, each node is a symbol in trie, bold a terminal node, last node in a string.
// 

#include <iostream>
#include <string>
#include <vector>

#define NUM_CHARS 256 // ASCII symbols

// Trie::node() class
typedef struct trienode
{
public:
    bool end; // often called terminal
    trienode* next[NUM_CHARS];
    // children are an array of trienode ptrs, used as a lookup table, put the value of the char array, and instantly know if it's a child of that node (lots of space)
    // don't have to search through list of children to see if a particular letter is there.

    trienode()
    {
        end = false;
        for (int i = 0; i < NUM_CHARS; i++)
        {
            next[i] = nullptr;
        }
    }
};

class Trie
{
public:
    // Trie.trienode element call *trie;
    trienode* trie;

    // TRIE CONSTRUCTOR
    Trie()
    {
        trie = new trienode();
        for (int i = 0; i < NUM_CHARS; i++)
        {
            trie->next[i] = NULL;
        }
        
        trie->end = false;
    }

    /*void insert(std::string word)
    {
        int i = 0;
        trienode* it = trie;

        while (i < word.size())
        {
            if (it->next[word[i] - 'a'] == NULL)
                it->next[word[i] - 'a'] = new trienode();
            it = it->next[word[i] - 'a'];
            i++;
        }

        it->end = true;
    }*/

    // passing it as signed, for reminders sake, that you need to check that it doesn't have a negative value, ascii char don't have negative values.
    bool trieinsert(trienode** root, char* signedtext)
    {
        if (root == NULL)
        {
            trienode* tmp = new trienode();
            *root = tmp;
        }

        unsigned char* text = (unsigned char*)signedtext; // prevents negative index into our lookup table.
        trienode* tmp = *root;
        int length = strlen(signedtext);

        for (int i = 0; i < length; i++)
        {
            if (tmp->next[text[i]] == NULL)
            {
                trienode* t = new trienode();
                tmp->next[text[i]] = t;
            }

            tmp = tmp->next[text[i]];
        }

        // check the internal value of node
        if (tmp->end == true)
            return false;
        else
            tmp->end = true;

        return true;
    }

    bool search(std::string word)
    {
        int i = 0;
        trienode* it = trie;
        while (i < word.size())
        {
            if (it->next[word[i] - 'a'] == NULL)
                return false;
            it = it->next[word[i] - 'a'];
            it++;
        }
        return it->end;
    }
};

int main()
{
    Trie* myTrie = new Trie();
    std::vector<std::string> words = { "ayush", "daasi" };

    for (auto w : words)
    {
        //myTrie->insert(w);
    }

    if (myTrie->search("daasi"))
        std::cout << "Found!" << std::endl;
    else
        std::cout << "Not Found!" << std::endl;
    
    system("pause");
}

// TRIES NOTES:
// Type of Tree Data Structure used to store chars
// Each trienode stores a char as it's data
// Very quick lookups of a particular kind.
// Follow a path from Root trienode to Dest trienode, the path forms a word.
// The destination trienode itself (via path from Root) represents a word (or part of a word).

// TRIE Implementation
// class Node
// {
//      std::unordered_map<char, *Node> children; 
//      bool isCompleteWord;
// }

// Do you have a child that's an 'a'?  Great, give me that immediately.
// And, do you also have an 'r' that's a child of 'a'?
// And, is that a complete word, or is that just a prefix?
// Each node will have some sort of flag on it (boolean).

// Example where a 'Trie' might be useful:
// Say, a user was typing a word...
// as soon as the word became an invalid word (ex.. cal, p), underline it, at p.
// Do each lookup from scratch, calls build on each other, we want to keep state within the trie
// Store where we are in the tree, (ex. is 'a' a child of c)
// you can also return a Node reference.  

// INTERVIEW QUESTIONS
// Word validation problems like.. 
// Ex. Walk through this scrabble table and find all the words.
// Ex. Given this list of strings, find all celebrity names.

// QUESTIONS ??
// Why Tries?  Very quick lookups of a particular kind.
// Do you need to each lookup from the root in a trie?
//  - No, keep state, build on past calls, store where we are in the tree.
//  - No, you can keep state within the trie or return Node back to the caller.

// Why are tries a good way to store a set of strings?
// Insert, Delete, and Search are very fast.
// A trie scales well.
// Straightforward to print a string in sorted order using depth-first search
// Sets of sorted symbolic strings.