/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n= q.size(); //n is size of this level
            while(n>0){
                Node* curr= q.front();
                q.pop();
                if(n==1) curr->next=NULL; //this is last ele of this lvl
                //so iske next me NULL
                else curr->next= q.front();
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                n--;
            }
        }
        return root;
    }
};