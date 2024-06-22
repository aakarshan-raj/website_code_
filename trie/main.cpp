#include "trie.h"

int main()
{
    Trie root = Trie();

    root.Put("abc", "alphabet");
    root.Put("a", "alphabetx");
    root.Put("ab", "alphabety");
    root.Put("b", "alphabetz");

    std::cout << root.Get("abc") << std::endl;
    std::cout << root.Remove("abc") << std::endl;
    std::cout << root.Get("abc") << std::endl;

    return 0;
}