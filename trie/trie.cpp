#include "trie.h"

void Trie::Put(std::string key, std::string value)
{
    if (root_ == nullptr)
    {
        root_ = std::make_shared<TrieNode>();
    }
    auto parent_node = root_;
    std::shared_ptr<TrieNode> new_node;

    auto it = key.begin();
    for (; it != key.end() && std::next(it) != key.end(); ++it)
    {
        if (!parent_node->hasChild(*it))
        {

            new_node = std::make_shared<TrieNode>();
            parent_node->node_[*it] = new_node;
            parent_node = new_node;
        }
        else
        {
            parent_node = parent_node->getChildNode(*it);
        }
    }

    auto value_ptr = std::make_shared<std::string>(std::move(value));
    if (key.empty() || !parent_node->hasChild(*it))
    {
        parent_node->node_[*it] = std::make_shared<TrieNodeWithValue>(value_ptr);
        std::cout << "Putting value at:" << parent_node->node_[*it] << std::endl;
    }
    else
    {
        auto node = parent_node->getChildNode(*it);
        parent_node->node_[*it] = std::make_shared<TrieNodeWithValue>(node->node_, value_ptr);
        std::cout << "Putting value at:" << parent_node->node_[*it] << std::endl;
    
    }
}

std::string Trie::Get(std::string key)
{
    if (root_ == nullptr)
    {
        return "";
    }

    for (char &c : key)
    {
        if (!root_->hasChild(c))
        {
            std::cout << "key doesn't exists" << std::endl;
            return "";
        }
        auto node = root_->getChildNode(c);
        if (node == nullptr)
        {
            return "";
        }
    }
    return "not null";
}

void Trie::Remove(std::string key)
{
}