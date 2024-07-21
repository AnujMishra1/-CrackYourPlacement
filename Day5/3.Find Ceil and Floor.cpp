#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> arr) {
    sort(arr.begin(), arr.end());
    
    int s = 0;
    int e = arr.size() - 1;
    int floor = -1;
    int ceil = -1;
    
    // Finding floor
    while (s <= e) {
        int mid = s + (e - s) / 2;
        
        if (arr[mid] == x) {
            floor = arr[mid];
            break;
        } else if (arr[mid] < x) {
            floor = arr[mid];
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    
    s = 0;
    e = arr.size() - 1;
    
    // Finding ceil
    while (s <= e) {
        int mid = s + (e - s) / 2;
        
        if (arr[mid] == x) {
            ceil = arr[mid];
            break;
        } else if (arr[mid] > x) {
            ceil = arr[mid];
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    
    return {floor, ceil};
}
};

