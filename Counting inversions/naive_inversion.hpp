#include <iostream>
#include <vector>
using namespace std;

/**
 * implement the naive solution to counting inversions problem
 *
 * @param
 *  a --> 1d array
 *
 * @return
 * the number of inversions in the array
*/
int naive_counting_inversions(vector<int> a) {
    int n = a.size();
    int inversion = 0;
    for (int i = 0; i <= n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[i] > a[j])
                inversion++;
        }
    }
    return inversion;
}
