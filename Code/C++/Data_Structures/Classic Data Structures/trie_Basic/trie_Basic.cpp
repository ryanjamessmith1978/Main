// Tries.cpp | https://www.youtube.com/watch?v=dOXfffhl4uI

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define NUM_CHARS 256 // ASCII symbols

typedef struct node
{
public:
    bool end; // often called terminal
    node* next[NUM_CHARS];
    
    node()
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
    // Trie.node element call *trie;
    node* trie;

    // TRIE CONSTRUCTOR
    Trie()
    {
        trie = new node();
        for (int i = 0; i < NUM_CHARS; i++)
        {
            trie->next[i] = NULL;
        }

        trie->end = false;
    }

    void insert(std::string word)
    {
        int i = 0;
        node* it = trie; // trie is already a private member, whatever happens to this node it, happens to member, trie.

        while (i < word.size())
        {
            if (it->next[word[i] - 'a'] == NULL) 
            {

                it->next[word[i] - 'a'] = new node();
            }            
            
            it = it->next[word[i] - 'a'];
            i++;
        }

        it->end = true;
    }

    bool search(std::string word)
    {
        int i = 0;
        node* it = trie;
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
        myTrie->insert(w);
    }

    if (myTrie->search("daasi"))
        std::cout << "Found!" << std::endl;
    else
        std::cout << "Not Found!" << std::endl;

    system("pause");
}