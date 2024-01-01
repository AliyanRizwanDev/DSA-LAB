#pragma once
#pragma once
#include"Abstract.h"
class AVLTree :public AAVL {
public:
    TreeNode* root;
    AVLTree() {
        root = NULL;
    }
    bool isTreeEmpty() {
        if (root == NULL) {
            return true;
        }
        else {
            return false;
        }
    }
    // Get Height  
    double height(TreeNode* r) {
        if (r == NULL)
            return -1;
        else {
            /* compute the height of each subtree */
            double lheight = height(r->left);
            double rheight = height(r->right);

            /* use the larger one */
            if (lheight > rheight)
                return (lheight + 1);
            else return (rheight + 1);
        }
    }

    // Get Balance factor of node N  
    int getBalanceFactor(TreeNode* n) {
        if (n == NULL)
            return -1;
        return height(n->left) - height(n->right);
    }

    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        // Perform rotation  
        x->right = y;
        y->left = T2;

        return x;
    }

    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        // Perform rotation  
        y->left = x;
        x->right = T2;

        return y;
    }

    TreeNode* insert(TreeNode * k) {
        TreeNode * temp;
        while (k->root->color == 1) {
            if (k->root == k->root->root->right) {
                temp = k->root->root->left;
                if (temp->color == 1) {
                    temp->color = 0;
                    k->root->color = 0;
                    k->root->root->color = 1;
                    k = k->root->root;
                }
                else {
                    if (k == k->root->left) {
                        k = k->root;
                        rightRotate(k);
                    }
                    k->root->color = 0;
                    k->root->root->color = 1;
                    leftRotate(k->root->root);
                }
            }
            else {
                temp = k->root->root->right;

                if (temp->color == 1) {
                    temp->color = 0;
                    k->root->color = 0;
                    k->root->root->color = 1;
                    k = k->root->root;
                }
                else {
                    if (k == k->root->right) {
                        k = k->root;
                        leftRotate(k);
                    }
                    k->root->color = 0;
                    k->root->root->color = 1;
                    rightRotate(k->root->root);
                }
            }
            if (k == root) {
                break;
            }
        }
        root->color = 0;
        return root;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        /* loop down to find the leftmost leaf */
        while (current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    TreeNode* deleteNode(TreeNode* r, double v) {
        // base case 
        if (r == NULL) {
            return NULL;
        }
        // If the key to be deleted is smaller than the root's key, 
        // then it lies in left subtree 
        else if (v < r->value) {
            r->left = deleteNode(r->left, v);
        }
        // If the key to be deleted is greater than the root's key, 
        // then it lies in right subtree 
        else if (v > r->value) {
            r->right = deleteNode(r->right, v);
        }
        // if key is same as root's key, then This is the node to be deleted 
        else {
            // node with only one child or no child 
            if (r->left == NULL) {
                TreeNode* temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL) {
                TreeNode* temp = r->left;
                delete r;
                return temp;
            }
            else {
                // node with two children: Get the inorder successor (smallest 
                // in the right subtree) 
                TreeNode* temp = minValueNode(r->right);
                // Copy the inorder successor's content to this node 
                r->value = temp->value;
                // Delete the inorder successor 
                r->right = deleteNode(r->right, temp->value);
                //deleteNode(r->right, temp->value); 
            }
        }

        int bf = getBalanceFactor(r);
        // Left Left Imbalance/Case or Right rotation 
        if (bf == 2 && getBalanceFactor(r->left) >= 0)
            return rightRotate(r);
        // Left Right Imbalance/Case or LR rotation 
        else if (bf == 2 && getBalanceFactor(r->left) == -1) {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }
        // Right Right Imbalance/Case or Left rotation	
        else if (bf == -2 && getBalanceFactor(r->right) <= -0)
            return leftRotate(r);
        // Right Left Imbalance/Case or RL rotation 
        else if (bf == -2 && getBalanceFactor(r->right) == 1) {
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }

        return r;
    }

    void print2D(TreeNode* r, int space) {
        if (r == NULL) // Base case  1
            return;
        space += SPACE; // Increase distance between levels   2
        print2D(r->right, space); // Process right child first 3 
        cout << endl;
        for (int i = SPACE; i < space; i++) // 5 
            cout << " "; // 5.1  
        cout << r->value << "\n"; // 6
        print2D(r->left, space); // Process left child  7
    }
    void printPreorder(TreeNode* r) //(current node, Left, Right) 
    {
        if (r == NULL)
            return;
        /* first print data of node */
        cout << r->value << " ";
        /* then recur on left sutree */
        printPreorder(r->left);
        /* now recur on right subtree */
        printPreorder(r->right);
    }

    void printInorder(TreeNode* r) //  (Left, current node, Right)
    {
        if (r == NULL)
            return;
        /* first recur on left child */
        printInorder(r->left);
        /* then print the data of node */
        cout << r->value << " ";
        /* now recur on right child */
        printInorder(r->right);
    }
    void printPostorder(TreeNode* r) //(Left, Right, Root)
    {
        if (r == NULL)
            return;
        // first recur on left subtree 
        printPostorder(r->left);
        // then recur on right subtree 
        printPostorder(r->right);
        // now deal with the node 
        cout << r->value << " ";
    }

    /* Print nodes at a given level */
    void printGivenLevel(TreeNode* r, double level) {
        if (r == NULL)
            return;
        else if (level == 0)
            cout << r->value << " ";
        else // level > 0  
        {
            printGivenLevel(r->left, level - 1);
            printGivenLevel(r->right, level - 1);
        }
    }
    void printLevelOrderBFS(TreeNode* r) {
        int h = height(r);
        for (int i = 0; i <= h; i++)
            printGivenLevel(r, i);
    }

    TreeNode* iterativeSearch(double v) {
        if (root == NULL) {
            return root;
        }
        else {
            TreeNode* temp = root;
            while (temp != NULL) {
                if (v == temp->value) {
                    return temp;
                }
                else if (v < temp->value) {
                    temp = temp->left;
                }
                else {
                    temp = temp->right;
                }
            }
            return NULL;
        }
    }

    TreeNode* recursiveSearch(TreeNode* r, double val) {
        if (r == NULL || r->value == val)
            return r;

        else if (val < r->value)
            return recursiveSearch(r->left, val);

        else
            return recursiveSearch(r->right, val);
    }

};