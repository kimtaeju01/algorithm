#include<iostream>
#include<cstdlib>
using namespace std;

struct Node{
    int key,priority,size;

    Node* left,*right;
    Node():key(0),left(NULL),right(NULL),priority(rand()),size(1){}
    Node(const int& _key):key(_key),left(NULL),right(NULL),priority(rand()),size(1){}
    void setLeft(Node* newLeft){
        left = newLeft; calcSize();
    }
    void setRight(Node* newRight){
        right = newRight; calcSize();
    }
    void calcSize(){
        size=1;
        if(left) size+=left->size;
        if(right) size+=right->size;
    }
};

typedef pair<Node*,Node*> NodePair;

NodePair split(Node* root, int key){
    if(root==NULL) return NodePair(NULL,NULL);

    if(root->key<key){
        NodePair rs=split(root->right,key);
        root->setRight(rs.first);
        return NodePair(root,rs.second);
    }
    NodePair ls = split(root->left,key);
    root->setLeft(ls.second);
    return NodePair(ls.first,root);
}

Node* insert(Node* root,Node* node){
    if(root==NULL) return node;
    if(root->priority<node->priority){
        NodePair splitted = split(root,node->key);
        node->setLeft(splitted.first);
        node->setRight(splitted.second);
    }
    else if(root->key>node->key)
        root->setLeft(insert(root->left,node));
    else
        root->setRight(insert(root->right,node));
    return root;
}

Node* merge(Node* a,Node* b){
    if(a==NULL) return b;
    if(b==NULL) return a;
    if(a->priority<b->priority){
        b->setLeft(merge(a,b->left));
        return b;
    }
    a->setRight(merge(a->right,b));
    return a;
}

Node* erase(Node* root, int key){
    if(root==NULL) return root;
    if(root->key==key){
        Node* ret = merge(root->left,root->right);
        delete root;
        return ret;
    }
    if(key<root->key)
        root->setLeft(erase(root->left,key));
    else
        root->setRight(erase(root->right,key));
    return root;
}
Node* kth(Node* root,int k){
    if(root->left->size==k) return root;

    if(root->left->size<k) return kth(root->right, k-root->left->size);
    else return kth(root->left,k);
}

int main(){
    Node nodelis[5];
    int shift[5] = {0,1,1,2,3};
    int lis[5]={0};
    for(int i=0;i<5;i++)
        nodelis[i].key = i;
    Node* root = nodelis;
    for(int i=1;i<5;i++)
        root = insert(root,&nodelis[i]);
    for(int i=4;i>=0;i--){
        lis[i] = kth(root,i-shift[i]+1)->key;
        root = erase(root,kth(root,i-shift[i]+1)->key);
    }

    return 0;
}
