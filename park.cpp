#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;


vector<vector<int>> parkrange(vector<vector<int>>& intervals, int start, int end) {
    if (intervals.size() == 0) {
        return {};
    }
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    int index = start;
    for (int i = 0; i < intervals.size(); ++i) {
        int l = intervals[i][0];
        int r = intervals[i][1];
        if(r<=start || index>=end) continue;
        else if(l>=end) merged.push_back({index, end});
        else {
            if (l <= index) {
                index = r;
            }
            else {
                merged.push_back({index, l});
                index = r;
            }
        }
    }
    if(index < end) merged.push_back({index, end});
    return merged;
}
int main() {
    vector<vector<int>> intervals = {{1,3},{2,9},{8,16},{15,18}};
    vector<vector<int>> result = parkrange(intervals, 1, 19); //result:[0,1]&[6,8]&[10,15]&[18,20]
    for(auto i:result) {
        cout << i[0] << " " << i[1] << "\n";
    }
    return 0;
}