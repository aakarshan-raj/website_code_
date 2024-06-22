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
    }
    else
    {
        auto node = parent_node->getChildNode(*it);
        parent_node->node_[*it] = std::make_shared<TrieNodeWithValue>(node->node_, value_ptr);
    }
}

std::string Trie::Get(std::string key)
{
    if (root_ == nullptr)
    {
        return "key doesn't exists";
    }
    auto node = root_;
    for (char &c : key)
    {

        if (!node->hasChild(c))
        {
            return "key doesn't exists";
        }
        node = node->getChildNode(c);
        if (node == nullptr)
        {
            return "key doesn't exists";
        }
    }
    auto node_value = std::dynamic_pointer_cast<TrieNodeWithValue>(node);
    if (node_value->is_value_node_)
    {
        return *node_value->value_;
    }
    return "Key doesn't exists";
}

bool Trie::Remove(std::string key)
{
    if (root_ == nullptr)
    {
        return false;
    }
    auto node = root_;
    for (char &c : key)
    {
        if (!node->hasChild(c))
        {
            return false;
        }
        node = node->getChildNode(c);
        if (node == nullptr)
        {
            return false;
        }
    }
    if (node->is_value_node_)
    {
        node->is_value_node_ = false;
        std::dynamic_pointer_cast<TrieNodeWithValue>(node)->value_ = nullptr;
        return true;
    }
    return false;
}