#include <bits/stdc++.h>
using namespace std;


// Function to perform heapsort on the given range of elements
void heapsort(vector<int>::iterator begin, vector<int>::iterator end)
{
    make_heap(begin, end + 1);
    sort_heap(begin, end + 1);
}

/**
 * implement introsort algorithm
 *
 * @param
 *  a --> int array to be sorted
 *  begin --> iterator points to the lower index
 *  end --> iterator points to the maximum index
 *  max_depth --> number of maximum recursion depth before changing to heapsort
 *
 * @return
 *
*/

void printvector(std::vector <int> const& a) {
    std::cout << "The vector elements are : ";

    for (int i = 0; i < a.size(); i++)
        std::cout << a.at(i) << ' ';
}

void insertionsort(vector<int>& a,int begin,int end) {

    for (int i = begin-1; i <= end; i++) {
        int j = i;
        while (j > begin && a[j - 1] > a[j]) {
            int temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
        }
    }

}
int  Partition(vector<int>& a, int begin, int end) {
    int pivot, i, temp;

    pivot = a[end];
    i = begin - 1;
    for (int j = begin; j <= end - 1; j++) {
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
    return (i + 1);
}

    int MedianOfThree(vector<int>& ar,int a, int b, int c){
    
        if (ar[a] < ar[b] && ar[b] < ar[c])
            return (b);

        if (ar[a] < ar[c] && ar[c] <= ar[b])
            return (c);

        if (ar[b] <= ar[a] && ar[a] < ar[c])
            return (a);

        if (ar[b] < ar[c] && ar[c] <= ar[a])
            return (c);

        if (ar[c] <= ar[a] && ar[a] < ar[b])
            return (a);

        if (ar[c] <= ar[b] && ar[b] <= ar[a])
            return (b);
    }

void introsort(vector<int> &a, int begin,int end, int max_depth) {
    int size = end-begin+1;
    if (size < 16) {
        insertionsort(a,begin,end);
        return;
    }
    if (max_depth == 0)
    {
        make_heap(a.begin()+begin, a.begin() + end + 1);
        sort_heap(a.begin() + begin, a.begin() + end + 1);
        return;
    }
    int pivot = MedianOfThree(a,begin, begin + size / 2, end);
    int temp = a[pivot];
    a[pivot] = a[end];
    a[end] = temp;
    int partitionPoint = Partition(a, begin, end );
    introsort(a, begin, partitionPoint - 1, max_depth - 1);
    introsort(a, partitionPoint + 1, end, max_depth - 1);



}
