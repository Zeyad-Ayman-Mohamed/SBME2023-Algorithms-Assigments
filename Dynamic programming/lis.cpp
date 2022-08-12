#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int legnth;
	int input;
	
	
	cin >> legnth;
	
	vector<int>SequenceVector;
	vector<int>ResultVector(legnth,1);
	for (int i = 0; i <= legnth - 1; i++) {
		cin >> input;
		SequenceVector.push_back(input);
	}
	
	for (int i = legnth - 1; i >= 0; i--) {
		for (int j = i + 1; j <= legnth-1; j++) {
			if (SequenceVector[i] < SequenceVector[j]) {
				ResultVector[i] = max(ResultVector[i], 1 + ResultVector[j]);

			}
		}
	}
	int output;
	output = *max_element(ResultVector.begin(), ResultVector.end());
	cout << output;
}