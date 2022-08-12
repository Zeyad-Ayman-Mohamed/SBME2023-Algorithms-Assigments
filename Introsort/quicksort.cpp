#include <bits/stdc++.h>
using namespace std;


/**
 * implement quicksort algorithm
 *
 * @param
 *  a --> int array to be sorted
 *  begin --> iterator points to the lower index
 *  end --> iterator points to the maximum index
 *
 * @return
 * void as quicksort is an inplace sorting algorithm
*/
 void print(std::vector <int> const& a) {
    std::cout << "The vector elements are : ";

    for (int i = 0; i < a.size(); i++)
        std::cout << a.at(i) << ' ';
}


int  partition(vector<int> &a,int begin,int end) {
    int pivot,i,temp;
    
    pivot = a[end];
    i = begin - 1;
    for (int  j = begin; j <= end-1; j++) {
        if (a[j] < pivot) {
            i++;
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }

    }
    temp = a[i + 1];
    a[i + 1] = a[end];
    a[end] = temp;
    //int u = i + 1;
    return (i+1);
}
void quicksort(vector<int> &a,int begin,int end) {
    if (begin < end) {
        int  pi = partition(a, begin, end);
        quicksort(a, begin, pi - 1);
        quicksort(a, pi + 1, end);

    }
    

}
