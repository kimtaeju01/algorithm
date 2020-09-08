#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode{
    int x,y,r;
    vector<TreeNode*> children;
};
bool inside(TreeNode* a,TreeNode* b){
    if((b->x-a->x)*(b->x-a->x)+(b->y-a->y)*(b->y-a->y)<a->r*a->r) return true;
    else return false;
}
void maketree(TreeNode* par,TreeNode* cur){
    if(par->children.size()==0){
        par->children.push_back(cur);
        return ;
    }
    int i=0;
    for(i=0;i<par->children.size();i++){
        if(inside(par->children[i],cur)){
            maketree(par->children[i],cur);
            break;
        }
    }
    if(i==par->children.size()){
        par->children.push_back(cur);
        return ;
    }
}
int longest=0;
int height(TreeNode* root){
    vector<int> heights;
    for(int i=0;i<root->children.size();i++)
        heights.push_back(height(root->children[i]));
    if(heights.empty()) return 0;
    sort(heights.begin(),heights.end());
    if(heights.size()>1)
        longest = max(longest,heights[heights.size()-1]+heights[heights.size()-2]+2);
    return heights[heights.size()-1]+1;
}
int solve(TreeNode* root){
    int h = height(root);
    return max(h,longest);
}
int main(){
    TreeNode treelist[8];
    int lis[][3]={{21,15,20},
                  {15,15,10},
                  {32,10,7},
                  {13,12,5},
                  {30,24,5},
                  {32,9,4},
                  {12,12,3},
                  {19,19,2}};
    for(int i=0;i<8;i++){
        treelist[i].x = lis[i][0];
        treelist[i].y = lis[i][1];
        treelist[i].r = lis[i][2];
    }

    for(int i=1;i<8;i++)  maketree(&treelist[0],&treelist[i]);
    height(&treelist[0]);
    cout<<longest;
    return 0;
}

