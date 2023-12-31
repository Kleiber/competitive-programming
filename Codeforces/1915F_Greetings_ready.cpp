/**
*  Generated by tpp tool
*  File: 1915F_Greetings.cpp
*  Created: 28-12-2023 15:10:05
**/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <numeric>
using namespace std;


long long int inversions;

void merge(vector<int> &A, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    
    int i = left;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= right) {
        if(A[i] <= A[j]) {
            temp[k++] = A[i++];
        } else {
            temp[k++] = A[j++];
            inversions += (mid + 1 - i);
        }
    }

    // Copy the remaining elements of left subarray
    while(i <= mid)
      temp[k++] = A[i++];
    
    // Copy the remaining elements of right subarray
    while(j <= right)
      temp[k++] = A[j++];

    // Copy back the merged elements to original array
    for(k = left; k <= right; k++)
      A[k] = temp[k - left];
}

void mergeSort(vector<int> &A, int left, int right) {
  if(left < right) {
    int mid = (left + right)/2;

    mergeSort(A, left, mid);
    mergeSort(A, mid + 1, right);

    merge(A, left, mid, right);
  }
}

bool order(pair<int,int> p1, pair<int,int> p2) {
  return p1.first < p2.first;
}

int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--) {
      int n;
      cin>>n;

      vector<pair<int, int>> V;
      for(int i = 0; i < n; i++) {
        int a, b;
        cin>>a>>b;
        V.push_back(make_pair(a,b));
      }

      sort(V.begin(), V.end(), order);

      vector<int>A(n);
      for(int i = 0; i < n; i++) A[i] = V[i].second;

      inversions = 0;
      mergeSort(A, 0, n - 1);

      cout<<inversions<<endl;
    }

    return 0;
}
