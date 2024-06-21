#include <memory>
#include <map>
#include <string>
#include <iostream>
#include <utility>

class TrieNode;
typedef std::map<char, std::shared_ptr<TrieNode>> Cluster;

class TrieNode
{
public:
    Cluster node_;
    bool is_value_node_{false};

    TrieNode(Cluster node) : node_(std::move(node)) {}

    TrieNode() = default;
    virtual ~TrieNode() = default;

    auto hasChild(char &c) const -> bool
    {
        return node_.find(c) != node_.end();
    }

    auto getChildNode(char &c) const -> std::shared_ptr<TrieNode>
    {
        if (!hasChild(c))
        {
            return nullptr;
        }
        return node_.find(c)->second;
    }
};

class TrieNodeWithValue : public TrieNode
{
public:
    std::shared_ptr<std::string> value_;

    explicit TrieNodeWithValue(std::shared_ptr<std::string> value) : value_(std::move(value))
    {
        this->is_value_node_ = true;
    }

    TrieNodeWithValue(Cluster node, std::shared_ptr<std::string> value) : TrieNode(std::move(node)), value_(std::move(value))
    {
        this->is_value_node_ = true;
    }
};

class Trie
{
public:
    std::shared_ptr<TrieNode> root_{nullptr};

    Trie() = default;

    void Put(std::string key, std::string value);

    std::string Get(std::string key);

    void Remove(std::string key);

    void Visualise();
};
