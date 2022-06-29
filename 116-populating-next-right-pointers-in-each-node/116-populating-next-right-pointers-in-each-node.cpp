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
    // initially all are NULL;
    Node* connect(Node* root) {
        Node* temp = root;
        while(temp != NULL && temp->left != NULL){
            Node* n = temp;
            while(true){
                n->left->next = n->right;
                if(n->next == NULL)
                    break;
                n->right->next = n->next->left;
                n = n->next;
            }
            temp = temp->left;
        }
        return root;
    }
};