#pragma once
#include<iostream>
#define SPACE 10
using namespace std;

class TreeNode {
public:
    double value;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        value = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(double v) {
        value = v;
        left = NULL;
        right = NULL;
    }
};