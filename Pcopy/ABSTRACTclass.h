#pragma once
#include"Node.h"
class AAVL {
public:
    bool virtual isTreeEmpty() = 0;
    double virtual height(TreeNode*) = 0;
    int virtual getBalanceFactor(TreeNode*) = 0;
    virtual TreeNode* insert(TreeNode*, TreeNode*) = 0;
    virtual TreeNode* minValueNode(TreeNode*) = 0;
    virtual TreeNode* deleteNode(TreeNode*, double) = 0;
    virtual void printPreorder(TreeNode*) = 0;
    virtual void printInorder(TreeNode*) = 0;
    virtual void printPostorder(TreeNode*) = 0;
    virtual void print2D(TreeNode*, int) = 0;
    virtual void printGivenLevel(TreeNode*, double) = 0;
    virtual void printLevelOrderBFS(TreeNode*) = 0;
    virtual TreeNode* iterativeSearch(double) = 0;
    virtual TreeNode* recursiveSearch(TreeNode*, double) = 0;

};