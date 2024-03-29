#pragma once
#include"Functions.h"
int main() {
    AAVL* obj1;
    AVLTree obj;
    obj1 = &obj;
    int option;
    double val;

    do {
        cout << "What operation do you want to perform? " <<
            " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print/Traversal AVL Tree values" << endl;
        cout << "5. Height of Tree" << endl;
        cout << "6. Clear Screen" << endl;
        cout << "7 for printing preOrder traversal" << endl;
        cout << "8 for printing InOrder traversal" << endl;
        cout << "9 for printing postOrder traversal" << endl;
        cout << "0. Exit Program" << endl;
        cin >> option;
        //Node n1;
        TreeNode* new_node = new TreeNode();

        switch (option) {
        case 0:
            break;
        case 1:
            cout << "AVL INSERT" << endl;
            cout << "Enter VALUE of TREE NODE to INSERT in AVL Tree: ";
            cin >> val;
            new_node->value = val;
            obj.root = obj.insert(obj.root);
            cout << endl;
            break;
        case 2:
            cout << "SEARCH" << endl;
            cout << "Enter VALUE of TREE NODE to SEARCH in AVL Tree: ";
            cin >> val;
            //new_node = obj.iterativeSearch(val);
            new_node = obj.recursiveSearch(obj.root, val);
            if (new_node != NULL) {
                cout << "Value found" << endl;
            }
            else {
                cout << "Value NOT found" << endl;
            }
            break;
        case 3:
            cout << "DELETE" << endl;
            cout << "Enter VALUE of TREE NODE to DELETE in AVL: ";
            cin >> val;
            new_node = obj.recursiveSearch(obj.root, val);
            if (new_node != NULL) {
                obj.root = obj.deleteNode(obj.root, val);
                cout << "Value Deleted" << endl;
            }
            else {
                cout << "Value NOT found" << endl;
            }
            break;
        case 4:
            cout << "PRINT 2D: " << endl;
            obj.print2D(obj.root, 5);
            cout << endl;
            //cout <<"Print Level Order BFS: \n";
            //obj.printLevelOrderBFS(obj.root);
            //cout <<endl;
            //	      cout <<"PRE-ORDER: ";
            //	      obj.printPreorder(obj.root);
            //	      cout<<endl;
            //	      cout <<"IN-ORDER: ";
            //	      obj.printInorder(obj.root);
            //	      cout<<endl;
            //	      cout <<"POST-ORDER: ";
            //	      obj.printPostorder(obj.root);
            break;
        case 5:
            cout << "TREE HEIGHT" << endl;
            cout << "Height : " << obj.height(obj.root) << endl;
            break;
        case 6:
            system("cls");
            break;
        case 7:
            cout << "PrintPreorder" << endl;
            obj.printPreorder(obj.root);
            break;
        case 8:
            cout << "print inOrder" << endl;
            obj.printInorder(obj.root);
            break;
        case 9:
            cout << "print postOrder" << endl;
            obj.printPostorder(obj.root);
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}
