#include<iostream>
#include<vector>
using namespace std;
void knapsackwithrepition(){
	int n;
	int weight;
	int input;
	cout << "please enter number of elements and max weight";
	cin >> n >> weight;
	if (n < 0 || weight < 0) {
		cout << "please enter postive numbers";
		cin >> n;
		cin >> weight;
	}
	vector<int>WeightVector;
	vector<int>ValueVector;
	vector<int>ResultVector;
	for (int i = 0; i <= n - 1; i++) {
		cin >> input;
		WeightVector.push_back(input);
	}
	for (int i = 0; i <= n - 1; i++) {
		cin >> input;
		ValueVector.push_back(input);
	}
	ResultVector.push_back(0);
	int value = 0;
	for (int w = 1; w <= weight; w++) {
		ResultVector.push_back(0);
		for (int i = 0; i <= n - 1; i++) {
			if (WeightVector[i] <= w)
				value = ResultVector[w - WeightVector[i]] + ValueVector[i];
			if (value > ResultVector[w])
				ResultVector[w] = value;

		}
	}
	cout << ResultVector[weight];
}
int main(int argc, char** argv) {
	int n;
	int weight;
	int input;
	
	cin >> n>> weight;

	vector<int>WeightVector;
	vector<int>ValueVector;
	vector<int>ResultVector;
	for (int i = 0; i <= n-1 ; i++) {
		cin >> input;
		WeightVector.push_back(input);
	}
	for (int i = 0; i <= n - 1; i++) {
		cin >> input;
		ValueVector.push_back(input);
	}
	ResultVector.push_back(0);
	int value = 0;
	for (int w = 1; w <= weight; w++) {
		ResultVector.push_back(0);
		for (int i = 0; i <= n-1; i++) {
			if (WeightVector[i] <= w)
				value = ResultVector[w- WeightVector[i]] + ValueVector[i];
			if (value > ResultVector[w])
				ResultVector[w] = value;

		}
	}
	cout << ResultVector[weight];
	
}