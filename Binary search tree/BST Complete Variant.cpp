#include<iostream>
using namespace std;
class tree {
public:
	int value;
	tree* left;
	tree* right;
	tree() {
		value = NULL;
		left = NULL;
		right = NULL;
	}
	tree(int v) {
		value = v;
		left = NULL;
		right = NULL;
	}
};

class BST {
public:
	tree* root;
	BST() {
		root = NULL;
	}
	bool IsEmpty() {
		if (root == NULL) {
			return true;
		}                                                                   //Bool Empty Function
		else{
			return false;
		}	
	}
	void InsertNode(tree* newNode)
	{
		if (IsEmpty() ==true ) {
			root = newNode;
			cout << "the value is inserted as root node" << endl;
		}
		else {
			tree* temp;
			temp = root;
			while (temp != NULL) {
				if (temp->value == root->value) {
					cout << "value Already Exists Enter Another Valid Value" << endl;
					return;
				}
				else if ((temp->value < root->value) && (temp->left == NULL)) {
					temp->left = newNode;
					cout << "value is inserted to the left of tree";

				}
				else if (temp->value < root->value) {
					temp = temp->left;
				}
				else if ((temp->value > root->value) && (temp->right == NULL)) {
					temp->right = newNode;
					cout << "value is inserted to the right of tree";

				}
				else {
					temp = temp->right;
				}
			}
		}
	}
	void preOrder(tree*newNode) {

		cout << newNode->value << endl;
		preOrder(newNode->left);
		preOrder(newNode->right);

	}
	void inOrder(tree* newNode) {

		inOrder(newNode->left);
		cout << newNode->value << endl;
		inOrder(newNode->right);

	}
	void postOrder(tree* newNode) {

		postOrder(newNode->left);
		postOrder(newNode->right);
		cout << newNode->value << endl;
	}

}; int main() {
    BST obj;
    int option, val;

    do {
        cout << "What operation do you want to perform? " <<
            " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print/Traversal BST values" << endl;
        cout << "5. Height of Tree" << endl;
        cout << "6. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;
        //Node n1;
        tree* new_node = new tree();

        switch (option) {
        case 0:
            break;
        case 1:
            cout << "INSERT" << endl;
            cout << "Enter VALUE of TREE NODE to INSERT in BST: ";
            cin >> val;
            new_node->value = val;
           //obj.root=obj.InsertNode( new_node);
            obj.InsertNode(new_node);
            cout << endl;
            break;

        case 2:
            cout << "SEARCH" << endl;
            cout << "Enter VALUE of TREE NODE to SEARCH in BST: ";
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
            cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
            cin >> val;
            new_node = obj.iterativeSearch(val);
            if (new_node != NULL) {
                obj.deleteNode(obj.root, val);
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
            cout << "Print Level Order BFS: \n";
            obj.printLevelOrderBFS(obj.root);
            cout << endl;
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
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}