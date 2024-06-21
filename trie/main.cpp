#include "trie.h"

int main()
{
    Trie root = Trie();

    root.Put("abc", "alphabet");
    root.Put("a", "alphabetx");
    root.Put("ab", "alphabety");
    root.Put("b", "alphabetz");

    std::cout << root.Get("abc") << std::endl;
    std::cout << root.Get("ab") << std::endl;
    std::cout << root.Get("a") << std::endl;
    std::cout << root.Get("b") << std::endl;

    return 0;
}