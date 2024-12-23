
#include <iostream>
using namespace std;

struct ViolationNode {
    string violation;
    ViolationNode* next;
    ViolationNode(string violation) : violation(violation), next(nullptr) {}
};

struct TreeNode
{
    string carNumber;
    ViolationNode* violations;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string number, string violation)
        : carNumber(number), violations(new ViolationNode(violation)), left(nullptr), right(nullptr) {}
};

class TrafficDB_BinaryTree {
    TreeNode* root;


    void addViolation(TreeNode* node, string violation) {
        ViolationNode* newNode = new ViolationNode(violation);
        newNode->next = node->violations;
        node->violations = newNode;
    }


    TreeNode* add(TreeNode* node, const string& carNumber, const string& vioaltion) {
        if (!node) {
            return new TreeNode(carNumber, vioaltion);
        }

        if (carNumber < node->carNumber) {
            node->left = add(node->left, carNumber, vioaltion);
        }
        else if (carNumber > node->carNumber) {
            node->right = add(node->right, carNumber, vioaltion);
        }
        else {
            addViolation(node, vioaltion);
        }
        return node;
    }


    void Print(TreeNode* node) const {
        if (!node) {
            return;
        }
        Print(node->left);
        cout << node->carNumber << ": ";
        ViolationNode* current = node->violations;
        while (current) {
            cout << current->violation << " ";
            current = current->next;
        }
        cout << "=======================" << endl;
        Print(node->right);
    }

    TreeNode* find(TreeNode* node, const string& carNumber) {
        if (!node) {
            return nullptr;
        }
        if (carNumber < node->carNumber) {
            return find(node->left, carNumber);
        }
        else if (carNumber > node->carNumber) {
            return find(node->right, carNumber);
        }
        return node;
    }

    void printbyCarNumber(string& carNumber) {
        TreeNode* node = find(root, carNumber);
        if (node) {
            cout << node->carNumber << ": ";
            ViolationNode* current = node->violations;
            while (current) {
                cout << current->violation << " ";
                current = current->next;
            }
            cout << endl;
        }
        else {
            cout << "2347" << endl;
        }

    }

    void printinRange(TreeNode* root, string& carNumber1, string& carNumber2) {
        if (!root) {
            return;
        }
        if (root->carNumber >= carNumber1 && root->carNumber <= carNumber2) {
            cout << root->carNumber << ": ";
            ViolationNode* current = root->violations;
            while (current) {
                cout << current->violation << " ";
                current = current->next;
            }
            cout << endl;
        }
        printinRange(root->left, carNumber1, carNumber2);
        printinRange(root->right, carNumber1, carNumber2);
    }

    
};


int main()
{

}

