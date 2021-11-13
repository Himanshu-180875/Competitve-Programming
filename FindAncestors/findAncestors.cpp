struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};

class Solution{
  public:
  bool findAncestors(struct Node *root, int target, vector<int> &v){
      if(root==NULL){
             
             return false;
         }
         if(root->data ==target){
             return true;
         }
         if(findAncestors(root->left,target,v) || findAncestors(root->right,target,v) ){
             v.push_back(root->data);
             return true;
         }
         return false;
  }
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target)
    {
         // Code here
         vector<int> anc;
         
         findAncestors(root, target,anc);
         return anc;
    }
};