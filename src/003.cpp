// This problem was asked by Google.

// Given the root to a binary tree, implement serialize(root),
// which serializes the tree into a string, and deserialize(s),
// which deserializes the string back into the tree.

// For example, given the following Node class

// class Node:
//     def __init__(self, val, left=None, right=None):
//         self.val = val
//         self.left = left
//         self.right = right
// The following test should pass:

// node = Node('root', Node('left', Node('left.left')), Node('right'))
// assert deserialize(serialize(node)).left.left.val == 'left.left'

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <assert.h>

using namespace std;

struct Node
{
  string val;
  Node *left, *right;

  Node(string val, Node *left = NULL, Node *right = NULL) : val(val), left(left), right(right) {}
};

string serialize(Node *root)
{
  if (root == NULL)
    return "*";
  return root->val + " " + serialize(root->left) + " " + serialize(root->right);
}

int ind = -1;
vector<string> tokens;
Node *deserialize()
{
  if (tokens[++ind] == "*")
    return NULL;

  Node *node = new Node(tokens[ind]);
  node->left = deserialize();
  node->right = deserialize();

  return node;
}

Node *deserialize(string s)
{
  istringstream iss(s);
  tokens = vector<string>{istream_iterator<string>{iss},
                          istream_iterator<string>{}};
  ind = -1;
  return deserialize();
}

main()
{
  Node *node = new Node("root", new Node("left", new Node("left.left")), new Node("right"));
  assert(deserialize(serialize(node))->left->left->val == "left.left");

  return 0;
}