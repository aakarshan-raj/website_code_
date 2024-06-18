#include "trie.h"

int main()
{
    Trie root = Trie();
    root.root_ = std::make_shared<TrieNode>();
    std::shared_ptr<std::string> data = std::make_shared<std::string>("aakarshan");
    root.root_->node_['a'] = std::make_shared<TrieNodeWithValue>(data);

    auto value_node = std::dynamic_pointer_cast<TrieNodeWithValue>(root.root_->node_['a']);

    std::cout << *value_node->value_ << std::endl;
    return 0;
}