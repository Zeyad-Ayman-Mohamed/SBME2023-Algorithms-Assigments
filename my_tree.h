#ifndef MY_TREE_H
#define MY_TREE_H

#include <vector>
#include <stack>
#include <bits/stdc++.h>
using namespace std;


//template <class T>

template <class T>
class MyTree {

private:
    struct Node {
        T data;
        Node* left;
        Node* right;
    };
    Node* insert(T x, Node* t)
    {
        if (t == NULL)
        {
            t = new Node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if (x < t->data)
            t->left = insert(x, t->left);
        else if (x > t->data)
            t->right = insert(x, t->right);
        count++;
        return t;
        
    }
    Node* BuildTreeBalanced(vector<T> elements, int start, int end) {
        //Node* n = root;
        Node* n;
        n = new Node;
        sort(elements.begin(), elements.end());
        if (start > end)
            return NULL;
        int mid,data;
        mid = (start + end) / 2;
        data = elements[mid];
        n->data = data;
        //n->left = NULL;
        //n->right = NULL;
        n->left = BuildTreeBalanced(elements, start, mid - 1);
        n->right = BuildTreeBalanced(elements, mid + 1, end);
        return n;
    }

public:
    Node* root;
    int count = 0;
    vector<T> elements;
    MyTree() {
        root = NULL;
    }

    MyTree(vector<T> elements) {
        

        
    }
    /**Node BuildTreeBalanced(vector<T> elements, int left, int right) {
         Node* n = root;
        sort(elements.begin(), elements.end());
        if (left > right)
            return NULL;
        int mid;
        mid = (left + right) / 2;
        n->data = elements[mid];
        n->left = MyTree(elements, left, mid - 1);
        n->right = MyTree(elements, mid + 1, right);
        return n;
    }*/
    void BuildTree(vector<T> elements) {
        int end = elements.size() - 1;
        root = BuildTreeBalanced(elements, 0, end);
    }
    bool search(Node* n, T key) {
        n = root;
        while (n != NULL) {
            // pass right subtree as new tree
            if (key > n->data)
                n = n->right;

            // pass left subtree as new tree
            else if (key < n->data)
                n = n->left;
            else {
                cout << 1;
                return true; }
                 // if the key is found return 1
        }
        cout << 0;
        return false;
    }

    void insert(T key) {
        
        root= insert(key, root);
        



    }

    void inorder_rec(Node* n) {
        if (n == NULL)
            return;
        inorder_rec(n->left);
        cout << n->data<<" ";
        inorder_rec(n->right);




    }

    void preorder_rec(Node* n) {
        if (n ==NULL)
            return;
        cout << n->data << " ";
        preorder_rec(n->left);
        preorder_rec(n->right);
    }

    void postorder_rec(Node* n) {
        if (n == NULL)
            return;
        postorder_rec(n->left);
        postorder_rec(n->right);
        cout << n->data<<" ";
    }

    void inorder_it() {
        Node* temp = root;
        stack<Node*> stack;
        while (temp != NULL || !stack.empty()) {
            if (temp != NULL) {
                stack.push(temp);
                temp = temp->left;
            }
            else {
                temp = stack.top();
                stack.pop();
                cout << temp->data<<" ";
                temp = temp->right;
            }
        }
    }


    void preorder_it() {
        Node* temp = root;
        stack<Node*> stack;
        while (temp != NULL || !stack.empty()) {
            if (temp != NULL) {
                cout << temp->data<< " ";
                if (temp->right != NULL)
                    stack.push(temp->right);

                temp = temp->left;
            }
            if (!stack.empty()) {
                temp = stack.top();
                stack.pop();
            }
        }
    }

    void postorder_it() {
        Node* temp = root;
        //stack<Node*> stack;
        if (root == NULL)
            return;

        // Create two stacks
        stack<Node*> s1, s2;

        // push root to first stack
        s1.push(temp);
        Node* node;

        // Run while first stack is not empty
        while (!s1.empty()) {
            // Pop an item from s1 and push it to s2
            node = s1.top();
            s1.pop();
            s2.push(node);

            // Push left and right children
            // of removed item to s1
            if (node->left)
                s1.push(node->left);
            if (node->right)
                s1.push(node->right);
        }

        // Print all elements of second stack
        while (!s2.empty()) {
            node = s2.top();
            s2.pop();
            cout << node->data << " ";
        }
    }

    void breadth_traversal() {
        Node* temp = root;
        if (temp == NULL)
            return;
        queue<Node*> q;

        // Enqueue Root and initialize height
        q.push(temp);

        while (q.empty() == false) {
            // Print front of queue and remove it from queue
            Node* node = q.front();
            cout << node->data << " ";
            q.pop();

            /* Enqueue left child */
            if (node->left != NULL)
                q.push(node->left);

            /*Enqueue right child */
            if (node->right != NULL)
                q.push(node->right);
        }
    }

    int size(Node* node) {
         //node = root;
        if (node == NULL)
            return 0;
        else
           return(size(node->left) + 1 + size(node->right));
        
    }
};



#endif
