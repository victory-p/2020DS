#include <iostream>
using namespace std;

class node{
public:
    string name;
    double score;
    node *left, *right;
    void set_data(string s, double n);
};

void node :: set_data(string s, double n){
    name = s;
    score = n;
}

class my_tree{
public:
    int node_count;
    node *root;
    my_tree();
    int insert_root(node t);
    int insert_left(string tname, node t);
    int insert_right(string tname, node t);

    double score_sum();
    double score_average();
    void print_data_inorder();
    void print_data_preorder();
    void print_data_postorder();
};
