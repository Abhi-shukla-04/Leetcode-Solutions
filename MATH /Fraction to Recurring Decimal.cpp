class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";

        string ans;

        // Check sign
        if ((numerator < 0) ^ (denominator < 0))
            ans += "-";

        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);

        // Integer part
        ans += to_string(num / den);

        long long remainder = num % den;

        // No fractional part
        if (remainder == 0)
            return ans;

        ans += ".";

        // remainder -> position in answer
        unordered_map<long long, int> seen;

        while (remainder != 0) {

            // Repeating remainder found
            if (seen.count(remainder)) {
                ans.insert(seen[remainder], "(");
                ans += ")";
                break;
            }

            seen[remainder] = ans.length();

            remainder *= 10;

            ans += to_string(remainder / den);

            remainder %= den;
        }

        return ans;
    }
};
