#ifndef TRIE_H
#define TRIE_H

#include <string>

#define CHAR_SIZE 26

class Trie
{
public:

    Trie();

    void Insert(std::string);
    bool Contains(std::string);
    
    /*bool HaveChildren(Trie const*);
    bool Deletion(Trie*&, std::string);*/

private:
    bool isLeaf;
    Trie* chars[CHAR_SIZE];
};

#endif