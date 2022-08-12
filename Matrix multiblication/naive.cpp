#include <vector>
#include <iostream>
using namespace std;
using std::vector;

/**
 * implement the naive matrix multiplication algorithm
 *
 * @param
 *  a --> a 2d vector
 *  b --> a 2d vector
 *
 * @return
 * the result of a*b "matrix multiplcation"
*/

    vector<vector<int>> naive(vector<vector<int>> a, vector<vector<int>> b) {
        
        vector<vector<int>> r(128, vector<int>(128));
        int rowA = a.size();
        if (rowA == 0) return r;
        int colA = a[0].size();
        if (colA == 0) return r;
        int rowB = b.size();
        if (rowB == 0) return r;
        int colB = b[0].size();
        if (colB == 0) return r;
        r.resize(rowA);
        for (int i = 0; i < rowA; ++i) {
            r[i].resize(colB);
        }
        for (int i = 0; i < rowA; ++i) {
            for (int j = 0; j < colB; ++j) {
                for (int k = 0; k < colA; ++k) {
                    r[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return r;
    }


