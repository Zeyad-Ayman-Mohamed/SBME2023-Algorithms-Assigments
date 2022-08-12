#include <vector>
#include <stack>
#include <bits/stdc++.h>
#include <iostream>
#include "my_pq.h"

using namespace std;
int main(int argc, char** argv) {
	int QueueSize;
	int NumberOfOperations;


	cin >> QueueSize >> NumberOfOperations;
	My_PQ pq;
	int input;
	int input2;
	int no1;// number of operations
	for (int i = 0; i < QueueSize ; i++) {
		cin >> input;
		pq.insert(input);
		
	}
	input = 0;
	for (int i = 0; i < NumberOfOperations; i++) {
		cin >> no1;
		if (no1 == 1) {
			cin >> input;
			pq.insert(input);
		}
		else if (no1 == 2) {
			cin >> input>>input2;
			pq.change_priority(input, input2);
		}
		else if (no1 == 3) {
			cin >> input;
			pq.remove(input);
		}
		else if (no1 == 4) {
			pq.extract_max();
		}
		else if (no1 == 5) {
			pq.peek();
			cout << " "<<endl;
		}
		else if (no1 == 6) {
			for (int i = 0; i <= pq.arr.size()-1; i++) {
				int out=pq.arr[i];
				cout << out<<" ";

			}
			pq.arr.clear();

		}
			
		else if (no1 == 7) {
			int size = pq.arr.size();
			cout << size;
			cout << " ";
			cout << endl;
		}




	}
return 0;
}
