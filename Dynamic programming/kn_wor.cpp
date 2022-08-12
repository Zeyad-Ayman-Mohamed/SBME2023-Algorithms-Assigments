#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main(int argc, char** argv) {
	int n;
	int weight;
	int input;
	
	cin >> n >> weight;
	
	vector<int>WeightVector;
	vector<int>ValueVector;
	
	vector<vector<int>> ResultVector(n+1, vector<int>(weight+1, 0));
	for (int i = 0; i <= n - 1; i++) {
		cin >> input;
		WeightVector.push_back(input);
	}
	for (int i = 0; i <= n - 1; i++) {
		cin >> input;
		ValueVector.push_back(input);
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= weight; j++) {
			ResultVector[i][j] = ResultVector[i-1][j];
			if (j >= WeightVector[i-1]) {
				ResultVector[i][j] = max(ResultVector[i][j], ValueVector[i-1] + ResultVector[i - 1][j - WeightVector[i-1]]);
			}
		}
	}
	cout << ResultVector[n][weight];
}