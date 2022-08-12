#include <iostream>
#include <vector>
using namespace std;

/**
 * implement the divide and conquer solution to counting inversions problem
 *
 * @param
 * a --> 1d array
 *
 * @return
 * the number of inversions in the array
*/
int merge(vector<int>arr, int temp[], int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;

    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];


            inv_count = inv_count + (mid - i);
        }
    }


    while (i <= mid - 1)
        temp[k++] = arr[i++];


    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int _mergeSort(vector<int>arr, int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}
int dandq_counting_inversions(vector<int> a) {



    int n = a.size();
    int temp[n];
    return _mergeSort(a, temp, 0, a.size() - 1);








}