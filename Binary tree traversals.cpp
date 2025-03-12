#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;
struct Node{
  char data;
  Node* left;
  Node* right;
  Node(char c) : data(c), left(NULL), right(NULL) {}
};
void deleteTree(Node* root) {
  if(!root) return;
  deleteTree(root->left);
  deleteTree(root->right);  
  delete root;
}
void postOrder(Node* root, vector<char>& res) {
  if(!root) return;
  postOrder(root->left, res);
  postOrder(root->right, res);
  res.push_back(root->data);
}

Node* buildTree(unordered_map<char, int>& inMap, vector<char>& pre, int& start, int instart, int inend) {
  if(instart > inend) return NULL;
  if(start >= pre.size()) return NULL;
  char value = pre[start++];
  Node* root = new Node(value);

  // use map to find the posiiton of inOrder root
  int index = inMap[value];
    
  root->left = buildTree(inMap ,pre ,start, instart, index - 1);
  root->right = buildTree(inMap ,pre ,start, index + 1, inend);
  return root;
}
int main() {
  int t;
  cin >> t;
  while(t--) {
    unordered_map<char, int> inMap;
    int n;
    cin >> n;
    vector<char> pre(n), in(n);
    for(int i = 0 ; i < n ; i++) {
      cin >> pre[i];
    }
    for(int i = 0 ; i < n ; i++) {
      cin >> in[i];
      inMap[in[i]] = i;
    }
    
    int start = 0;
    Node* root = buildTree(inMap,pre, start, 0, n - 1);
    vector<char> res;
    postOrder(root, res);
    for(int i = 0 ; i < res.size() ; i++) {
      if(i > 0) cout << " ";
      cout << res[i];
    }
    cout << endl;
    deleteTree(root);
  }
  
  return 0;
}