class Solution {
public:
    string decodeString(string s) {
    stack<string> chars;
    stack<int> nums;
    string res;
    int num = 0;
    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '[') {
            chars.push(res);
            nums.push(num);
            res = "";
            num = 0;
        } else if (c == ']') {
            string tmp = res;
            res = chars.top();
            chars.pop();
            for (int i = nums.top(); i > 0; i--) res += tmp;
            nums.pop();
        } else {
            res += c;
        }
    }
    return res;
    }
};