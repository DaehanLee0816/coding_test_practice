#include <iostream>
#include <vector>
using namespace std;

void BFS(vector<vector<int>> &tree, int tree_lvl, int &node_lvl) {
    if (node_lvl == tree_lvl) {
        node_lvl--;
        return;
    }
    
    for (int pos = 0; pos <= node_lvl; pos++) {
        if (tree[node_lvl+1][pos] > tree[node_lvl+1][pos+1]) {
            tree[node_lvl][pos] += tree[node_lvl+1][pos];
        } else {
            tree[node_lvl][pos] += tree[node_lvl+1][pos+1];
        }
    }
    node_lvl--;
    return;
}

int main()
{
    int lvl;
    cin >> lvl;
    
    vector<vector<int>> tree;
    for (int i = 0; i < lvl; i++) {
        vector<int> i_th_node;
        tree.push_back(i_th_node);
        for (int j = 0; j <= i; j++) {
            int j_th_val;
            cin >> j_th_val;
            tree[i].push_back(j_th_val);
        }
    }
    int tree_lvl = lvl-1;
    int node_lvl = lvl-1;
    
    while (node_lvl >=0) {
        BFS(tree, tree_lvl, node_lvl);
    }
    cout << tree[0][0];
    return 0;
}