class Solution {
public:
    string addBinary(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int carry = 0;
        string ans = "";
        int i = n-1, j = m-1;
        while(i>=0 || j>=0 || carry){
            int sum = 0;
            if(i >= 0)
                sum += str1[i] - '0';
            if(j >= 0)
                sum += str2[j] - '0';
            sum += carry;
            carry = sum / 2;
            int digit = (sum % 2) + 48;
            char char_digit = (char) digit;
            ans += char_digit;
            i--; j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};