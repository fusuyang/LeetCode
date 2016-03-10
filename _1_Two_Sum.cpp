class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int temp, a = -1, b = -1;//assume that elements of nums are non_negative numbers, -1 indicates there's no solution
		vector<int> vetInt = nums;
		sort(vetInt.begin(), vetInt.end());//sort, O(nlogn)
		for (auto ite = vetInt.begin(); ite != vetInt.end()-1; ++ite) {//find solution, O(nlogn)
			temp = target - *ite;
			if (binary_search(ite + 1, vetInt.end(), temp)) {//binary search, O(logn)
				a = temp;
				b = target - a;//a and b record elements which sum to target
				break;
			}
		}
		if (b != -1) {
			for (temp = 0; nums[temp] != a; ++temp);//find index of a and b in nums
			a = temp;
			for (temp = 0; nums[temp] != b||temp==a; ++temp) {//maybe a equals to b
				if (temp == a)
					continue;
			}
			b = temp;
			if (a > b) {
				swap(a, b);
			}
			return{ a, b };
		} else
		return{ -1, -1 };
    }
};