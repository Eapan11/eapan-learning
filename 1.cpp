#include<iostream>
#include<vector>
#include<stdio.h>
#include<windows.h>
using namespace std;


void quickSort(vector<int> &nums, int left, int right) {
    if(left>=right) return;
    int val = rand() % (right-left+1) + left;
    swap(nums[val], nums[right]);
    int count = left;
    for(int i = left; i < right; ++i) {
        if(nums[i] < nums[right]) swap(nums[i], nums[count++]);
    }
    swap(nums[right], nums[count]);
    quickSort(nums, left, count-1);
    quickSort(nums, count+1, right);
}

int main() {
    vector<int> nums = {2, 4, 1, 5, 8};
    for(int i:nums) {
        cout << i << ' ';
    }
    cout <<"\n";
    quickSort(nums, 0, nums.size()-1);
    for(int i:nums) {
        cout << i << ' ';
    }

    return 0;
}
