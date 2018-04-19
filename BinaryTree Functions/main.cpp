#include <iostream>
#include <cstdlib>

using namespace std;

struct BST_node {
    BST_node *parent;
    BST_node *left;
    BST_node *right;
    int val;
};

void printLVR(BST_node *root) {         //inorder
    if (root != NULL) {
        printLVR(root->left);
        cout << root->val << " ";
        printLVR(root->right);
    }
}

void printVLR(BST_node *root) {          //preorder
    if (root != NULL) {
        cout << root->val << " ";
        printVLR(root->left);
        printVLR(root->right);
    }
}

void printLRV(BST_node *root) {         //postorder
    if (root != NULL) {
        printLRV(root->left);
        printLRV(root->right);
        cout << root->val << " ";
    }
}

void printRVL(BST_node *root) {      //malejaco
    if (root != NULL) {
        printRVL(root->right);
        cout << root->val << " ";
        printRVL(root->left);
    }
}

void prettyPrinter(BST_node *root, int spaces) {
    if (root != NULL) {
        prettyPrinter(root->right, spaces + 8);

        for (int i = 0; i < spaces; i++) cout << " ";
        cout << root->val << endl << endl;

        prettyPrinter(root->left, spaces + 8);
    }
}

void RecursionInsert(BST_node *&root, BST_node *parent, int value) {
    if (root == NULL) {
        root = new BST_node;
        root->val = value;
        root->left = root->right = NULL;
        root->parent = parent;
    } else {
        if (value < root->val) {
            RecursionInsert(root->left, root, value);
        } else {
            RecursionInsert(root->right, root, value);
        }
    }
}

void IterationInsert(BST_node *&root, int value) {
    BST_node *element = new BST_node;
    element->val = value;
    element->left = element->right = element->parent = NULL;

    if (root == NULL) root = element;

    else {
        BST_node *p = root, *r;

        while (p != NULL) {
            r = p;
            if (value < p->val) p = p->left;
            else p = p->right;
        }
        if (value < r->val) r->left = element;
        else r->right = element;
        element->parent = r;
    }
}

BST_node *Searching(BST_node *root, int value) {
    if (root == NULL) exit(0);
    while (root != NULL and root->val != value) {
        if (value < root->val) root = root->left;
        else root = root->right;
    }
    return root;
}

BST_node *max(BST_node *root) {
    if (root == NULL) exit(0);
    while (root->right) root = root->right;
    return root;
}

BST_node *min(BST_node *root) {
    if (root == NULL) exit(0);
    while (root->left) root = root->left;
    return root;
}

BST_node *predecessor(BST_node *root) {
    if (root->left != NULL) {
        root = root->left;
        while (root->right != NULL) root = root->right;

        return root;
    }
    while (root->parent != NULL and root->parent->left == root) root = root->parent;

    return root->parent;
}

BST_node *successor(BST_node *root) {
    if (root->right != NULL) {
        root = root->right;
        while (root->left != NULL) root = root->left;

        return root;
    }
    while (root->parent != NULL and root->parent->right == root) root = root->parent;

    return root->parent;
}

void removeleaf(BST_node *&root, BST_node *element) {
    if (root == NULL or element == NULL) return;

    BST_node *p, *r;
    if (element->right == NULL or element->left == NULL) p = element;
    else p = predecessor(element);

    if (p->right != NULL) r = p->right;
    else r = p->left;

    if (r != NULL) r->parent = p->parent;

    if (p->parent == NULL) root = r;
    else if (p == p->parent->left) p->parent->left = r;
    else p->parent->right = r;

    if (p != element) element->val = p->val;
}

void leftRotate(BST_node *&root, BST_node *r) {
    BST_node *p = r->right;
    r->right = p->left;

    if (p->left != NULL) p->left->parent = r;

    p->parent = r->parent;

    if (r->parent == NULL) root = p;
    else if (r == r->parent->left) r->parent->left = p;
    else r->parent->right = p;

    p->left = r;
    r->parent = p;
}

void rightRotate(BST_node *&root, BST_node *x) {
    BST_node *y = x->left;
    x->left = y->right;

    if (y->right != NULL) y->right->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL) root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;

    y->right = x;
    x->parent = y;
}

void freeBST(BST_node *&root) {

        if (root!=NULL) {
            freeBST(root->left);
                freeBST(root->right);
            removeleaf(root,root);
        }

}



int main() {
    BST_node *root = NULL;

    return 0;
}