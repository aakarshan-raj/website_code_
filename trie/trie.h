#include <memory>
#include <map>

typedef std::map<char, std::shared_ptr<TrieNode>> Cluster;

class TrieNode
{
public:
    Cluster node_;
    bool is_value_node_{false};

    TrieNode(Cluster node) : node_(std::move(node_)) {}

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
        node_.find(c)->second;
    }
};

template <class T>
class TrieNodeWithValue : public TrieNode
{
public:
    std::shared_ptr<T> value_;

    explicit TrieNodeWithValue(std::shared_ptr<T> value) : value_(std::move(value))
    {
        this->is_value_node_ = true;
    }

    TrieNodeWithValue(Cluster node, std::shared_ptr<T> value) : TrieNode(std::move(node)), value_(std::move(value))
    {
        this->is_value_node_ = true;
    }
};

class Trie
{
private:
    std::shared_ptr<TrieNode> root_{nullptr};

public:
    Trie() = default;

    template <class T>
    void Put(std::string &key, T value);

    template <class T>
    T Get(std::string &key);

    void Remove(std::string &key);
};
