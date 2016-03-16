/**
 *PROBLEM: 
 *There are two sorted arrays nums1 and nums2 of size m and n respectively. 
 *Find the median of the two sorted arrays. The overall run time complexity 
 *should be O(log (m+n)).
 */

class Solution {
public:
	using vii = vector<int>::iterator;
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size1 = nums1.size();
		int size2 = nums2.size();
		int k = (size1 + size2) / 2;
		findKth(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), k);
		double result = 0;
		if ((size1 + size2) % 2 == 0) //when size1+size2 is even, median is (kth +(k+1)th)/2
			result = (*findKth(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), k)
					 + *findKth(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), k + 1)) / 2.0;
		else //when size1+size2 is odd, median is (k+1)th
			result = *findKth(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), k + 1);
		return result;
	}
private:
	vii findKth(vii beg1, vii end1, vii beg2, vii end2, int k) { //find kth number of two sorted container, k <= size1+size2
		if (end1 - beg1 > end2 - beg2)
			return findKth(beg2, end2, beg1, end1, k);
		int size1 = end1 - beg1;
		int size2 = end2 - beg2;
		if (size1 == 0)
			return beg2 + k - 1;
		if (k == 1)
			return *beg1<*beg2 ? beg1 : beg2;
		int k1 = min(k / 2, size1);
		int k2 = k - k1;
		if (*(beg1 + k1-1) == *(beg2 + k2-1)) {
			return beg1 + k1-1;
		}
		else if (*(beg1 + k1-1) < *(beg2 + k2-1)) {
			return findKth(beg1+k1, end1, beg2, end2, k-k1);
		}
		else {
			return findKth(beg1, end1, beg2+k2, end2, k-k2);
		}
	}
};