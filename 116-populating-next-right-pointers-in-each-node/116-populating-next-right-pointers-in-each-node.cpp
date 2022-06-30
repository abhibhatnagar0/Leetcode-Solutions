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
        Node* par=root;
        while(par!=NULL){
            Node *dummy= new Node(-1); //dummy always before par ka left child
            Node* temp= dummy; //temp will traverse children level below parents
            while(par!=NULL){ //for each level
                if(par->left!=NULL){
                    temp->next=par->left;
                    temp=temp->next;
                }
                if(par->right!=NULL){
                    temp->next=par->right;
                    temp=temp->next;
                }
                par=par->next; //parents connection done before
            }
            //kisi level me par has become null
            par=dummy->next; //for next level
        }
        return root;
    }
};