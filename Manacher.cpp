#include<iostream>
#include<limits.h>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int Manacher(string s) {
		vector<char> p_arr = P_arr(s);
		vector<int> length(p_arr.size());
		int R = -1;
		int index = -1;
		int Max = INT_MIN;
		for (int i = 0; i < p_arr.size(); i++) {
			length[i] = R > i ? min(length[2 * index - i], R - i) : 1;
			while (i + length[i]<p_arr.size() && i - length[i]>-1) {
				if (p_arr[i + length[i]] == p_arr[i - length[i]]) {
					length[i]++;
				}
				else {
					break;
				}
			}
			if (i + length[i] > R) {
				R = i + length[i];
				index = i;
			}
			Max = max(Max, length[i]);
		}
		return Max - 1;
	}
	vector<char> P_arr(string s) {
		vector<char> res(s.size() * 2 + 1);
		int index = 0;
		for (int i = 0; i < res.size(); i++) {
			res[i] = (i & 1) == 0 ? '#' : s[index++];
		}
		return res;
	}
};
int main() {
	string str1 = "abc1234321ab";
	Solution s;
	cout << s.Manacher(str1);
	return 0;
}