/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw10/challenges/radix-sort-4-1/submissions/code/1323301765
 * Title: hw10_1.cpp
 * Abstract: This program conducts the radix sort
 * Author: Jonathan Welham
 * ID: 6781
 * Date: 05/02/2020
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

vector<int> radix(vector<int>list, int count){
    int exponent = pow(10,count);
    vector<vector<int>> v2;
    vector<int> out;

    for(int i = 0; i < 10; i++){
        vector<int> v = {};
        v2.push_back(v);
    }

    for(int i = 0; i < list.size(); i++){
        int x = (list[i]/exponent) % 10;
        v2[x].push_back(list[i]);
    }

    for(int i = 0; i < v2.size(); i++){
        for(int j = 0; j < v2[i].size(); j++){
            out.push_back(v2[i][j]);
        }
    }

    for(int i = 0; i < out.size(); i++){
        cout << out[i] << " ";
    }

    return out;
}

int main(){
    int n;
    int count = 0;

    cin >> n;

    //This was easier to do with vectors solely because of the vector functions
    vector<int> v1;
    int userIn;

    for(int i = 0; i < n; i++){
        cin >> userIn;
        v1.push_back(userIn);
    }

    //Get the max value from the vector
    int max = *max_element(v1.begin(), v1.end());
    string temp = to_string(max);
    int len = temp.length();

    vector<int> answer;

    //Output
    for(int i = 0; i < len; i++){
        answer = radix(v1, i);
        v1 = answer;
        cout << endl;
        count++;
    }
}