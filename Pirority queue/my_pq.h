#ifndef MY_PQ_H
#define MY_PQ_H
#include<iostream>
#include <vector>

#include<bits/stdc++.h> 
using namespace std;

class My_PQ {

public:
    vector<int> arr;
    My_PQ() {}

    My_PQ(vector<int> arr) {
        make_heap(arr.begin(), arr.end());
    }
    int parent(int i) {
        return((i-1)/ 2);
    }
    int leftchild(int i) {
        return(2 * i+1);
    }
    int rightchild(int i) {
        return(2 * i + 2);
    }
    void swap(int first, int second) {
        int temp;
        temp = first;
        first = second;
        second = temp;
    }
    void shiftup(int i) {
        while (i > 0 && (arr[parent(i)] < arr[i])) {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
       
    }
    void shiftdown(int i) {
        int maxindex,left,right;
        maxindex = i;
        left = leftchild(i);
        if ((left <= arr.size()) && (arr[left] > arr[maxindex])) {
            maxindex = left;
        }
        right = rightchild(i);
        if ((right <= arr.size()) && (arr[right] > arr[maxindex])) {
            maxindex = right;
        }
        if (i != maxindex) {
            swap(arr[i], arr[maxindex]);
            shiftdown(maxindex);
        }
        
    }
    
    int  extract_max() {
        int result;
        result = arr[0];
        //arr[0] = arr[arr.size()-1];
        //arr.pop_back();
        //shiftdown(0);
        arr.erase(arr.begin());
        sort(arr.begin(), arr.end(), greater<int>());
        return result;
    }

    void change_priority(int index, int new_priority) {
        //int oldpirority = arr[index];
        //arr[index] = new_priority;
       // if (new_priority > oldpirority) {
        //    shiftup(index);
        //}
       // shiftdown(index);
        arr.erase(arr.begin() + index);
        arr.insert(arr.end(), new_priority);
        sort(arr.begin(), arr.end(), greater<int>());
    }

    void peek() {
        cout << arr[0];
    }

    void insert(int value) {
        //int size = arr.size() + 1;
        //arr[size] = value;
        //arr.push_back(value);
        //shiftup(arr.size()-1);
        arr.insert(arr.end(), value);
        sort(arr.begin(), arr.end(), greater<int>()); 
    }

    void remove(int index) {
        arr.erase(arr.begin() + index);
        //shiftup(index);
        //extract_max();
        sort(arr.begin(), arr.end(), greater<int>());
    }
    
};

#endif