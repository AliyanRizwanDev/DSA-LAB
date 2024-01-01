#pragma once
#pragma once
#include<iostream>
#define SPACE 10
using namespace std;

class TreeNode {
public:
    double value;
    TreeNode* root;
    TreeNode* left;
    TreeNode* right;
    int color;

    TreeNode() {
        value = 0;
        color = 0;
        root = NULL;
        left = NULL;
        right = NULL;
    }
    TreeNode(double v) {
        value = v;
        left = NULL;
        right = NULL;
    }
};