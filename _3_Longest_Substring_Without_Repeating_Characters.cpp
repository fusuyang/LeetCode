//Version 1, using iterator, runtime 20ms
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		auto head = s.begin(), tail = head, temp = head;
		int maxLen = 0, count = 0;
		while (tail != s.end()) {
			temp = find(head, tail, *tail);
			if (temp == tail) {
				++tail;
			} else {
				head=temp+1;
				++tail;
			}
			maxLen = max(maxLen,tail - head);
		}
		return maxLen;
	}
};

//Version 2, using deque, runtime 48ms
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		auto temp = s.begin();
		int maxLen = 0;
		deque<char> subString;
		for (auto c : s) {
			auto temp = find(subString.begin(), subString.end(), c);
			if (temp != subString.end()) {
				subString.erase(subString.begin(), ++temp);
			}
			subString.push_back(c);
			maxLen = max(maxLen, static_cast<int>(subString.size()));
		}
		return maxLen;
	}
};