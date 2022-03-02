#include "Trie.h"

Trie::Trie()
{
    this->isLeaf = false;

    for (int c = 0; c < CHAR_SIZE; c++)
        this->chars[c] = nullptr;
}

void Trie::Insert(std::string key)
{
    Trie* current = this;
    for (int c = 0; c < key.length(); c++)
    {
        if (current->chars[toupper(key[c]) - 'A'] == nullptr)
            current->chars[toupper(key[c]) - 'A'] = new Trie();

        current = current->chars[toupper(key[c]) - 'A'];
    }

    current->isLeaf = true;
}

bool Trie::Contains(std::string key)
{
    if (this == nullptr)
        return false;

    Trie* current = this;
    for (int c = 0; c < key.length(); c++)
    {
        current = current->chars[toupper(key[c]) - 'A'];

        if (current == nullptr)
            return false;
    }

    return current->isLeaf;
}

/*bool Trie::HaveChildren(Trie const* current)
{
    for (int c = 0; c < CHAR_SIZE; c++)
        if (current->chars[c])
            return true;

    return false;
}

bool Trie::Deletion(Trie*& current, std::string key)
{
    if (current == nullptr)
        return false;

    if (key.length())
    {
        if (current != nullptr && current->chars[key[0]] != nullptr
            && Deletion(current->chars[key[0]], key.substr(1)) && current->isLeaf == false)
        {
            if (!HaveChildren(current))
            {
                delete current;
                current = nullptr;
                return true;
            }
            else
                return false;
        }
    }

    if (key.length() == 0 && current->isLeaf)
    {
        if (!HaveChildren(current))
        {
            delete current;
            current = nullptr;

            return true;
        }

        else
        {
            current->isLeaf = false;

            return false;
        }
    }

    return false;
}*/