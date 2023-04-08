/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
// Using DFS or BFS for traversal
// DFS is easier
// Deep copy in cyclic graph may cause infinite loop: Using hash table to stote the mapping
// Author: Huahua
class Solution {
public:
  Node* cloneGraph(Node* node) {
    if (!node) return nullptr;
    unordered_map<Node*, Node*> m;
    function<void(Node*)> dfs = [&](Node* u) {
      m[u] = new Node(u->val);
      for (Node* v : u->neighbors) {
        if (!m.count(v)) dfs(v);
        m[u]->neighbors.push_back(m[v]);
      }
    };
    dfs(node);
    return m[node];
  }
};
