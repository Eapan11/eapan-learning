#include<iostream>
#include<vector>
#include<numeric>
#include<cmath>
using namespace std;
int N = 100;

double funtion_X(vector<double> nums) {
    double result = 0;
    for(int i = 1; i <=nums.size()/2; ++i) {
        result += (100*pow(pow(nums[2*i-2], 2) - nums[2*i-1], 2) + pow(nums[2*i-2] - 1, 2));
    }
    return result;
}
double funtion_gg(vector<double> gradient) {
    double result = 0;
    for(double i:gradient) {
        result += i*i;
    }
    return result;
}
vector<double> lineSearch(vector<double> &nums) {
    int n = nums.size();
    //f(x) = sum(100*(x^2_(2i-1)-x(2i))^2 + (x_(2i-1) - 1)^2), i = 1,2,...,n/2
    //f'(x) = ...
    //while(||f(k+1)-f(k)||<epsilon)
    int t = 0;
    int c = 0.02;
    while(t<10000) {
        cout << funtion_X(nums);
        vector<double> gradient;
        //calculate the gradient of f(x):
        for(int i = 1; i <=n/2; ++i) {
            double g_odd = 400*(pow(nums[2*i-2], 2) - nums[2*i-1])*nums[2*i-1-1] + 2*(nums[2*i-2] - 1);
            double g_even = 200*(nums[2*i-1] - pow(nums[2*i-2], 2));
            gradient.push_back(g_odd);
            gradient.push_back(g_even);
        }
        //if the value has converged?
        double g_sum = 0;
        for(auto i:gradient) {
            g_sum += abs(i);
        }
        if(g_sum/n < 0.00001) break; //break if ...

        double alpha = 1;
        vector<double> nums_pre(nums);
        // double f_x = funtion_X(nums);
        for(int i = 0; i < n; ++i) {
            nums[i] -= alpha*gradient[i];
            // cout << nums[i] << ' '; 
        }
        cout << "\n";
        while(funtion_X(nums)-funtion_X(nums_pre) > -c*alpha*funtion_gg(gradient)) {
            alpha /= 2;
            // cout << "?\n";
            for(int i = 0; i < n; ++i) {
                nums[i] = nums_pre[i] - alpha*gradient[i];
            }
        }

        t++;
    }
    return nums;
}
int main() {
    vector<double> nums(N, 0);
    lineSearch(nums);
    for(double i:nums) {
        cout << i << ' '; 
    }
    return 0;
}