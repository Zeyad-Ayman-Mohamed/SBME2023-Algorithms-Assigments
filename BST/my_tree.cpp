#include <vector>
#include <stack>
#include <bits/stdc++.h>
#include <iostream>
#include "my_tree.h"

using namespace std;
int main(int argc, char** argv) {
	int TreeSize;
	int NumberOfOperations;
	

	cin >> TreeSize >> NumberOfOperations;	
		MyTree<int> tree;
		int input;
		int no1;// number of operations
		for (int i = 0; i <= TreeSize - 1; i++) {
			cin >> input;
			//tree.insert(input);
			tree.elements.push_back(input);
			
		}
		//sort(tree.elements.begin(), tree.elements.end());

		tree.BuildTree(tree.elements);
		//vector <int> treearray;
		//treearray = tree.elements;
		//sort(treearray.begin(), treearray.end());
		//tree.root=tree.BuildTreeBalanced(treearray, 0, TreeSize - 1);
		input = 0;
		for (int i = 0; i <= NumberOfOperations-1; i++) {
			cin >> no1;
			if (no1 == 1) {
				cin >> input;
				tree.insert(input);
			}
			else if (no1 == 2) {
				cin >> input;
				tree.search(tree.root, input);
				cout << " "<<endl;
			}
			else if (no1 == 3) {
				cin >> input;
				if (input == 1) {
					tree.inorder_rec(tree.root);
					cout << endl;
				}
				else if (input == 2) {
					tree.inorder_it();
					cout << endl;
				}
			}
			else if (no1 == 4) {
				cin >> input;
				if (input == 1) {
					tree.preorder_rec(tree.root);
					cout << endl;
				}
				else if (input == 2) {
					tree.preorder_it();
					cout << endl;
				}
			}
			else if (no1 == 5) {
				cin >> input;
				if (input == 1) {
					tree.postorder_rec(tree.root);
					cout << endl;
				}
				else if (input == 2 || input>=2) {
					tree.postorder_it();
					cout << endl;
				}
			}
			else if (no1 == 6) {
				tree.breadth_traversal();
				cout << endl;

			}
			else if (no1 == 7) {
				int size = tree.size(tree.root);
				cout << size<<" "<<endl;
			}




		}
	
}