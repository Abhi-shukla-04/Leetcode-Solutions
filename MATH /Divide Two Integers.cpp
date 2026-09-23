
class Solution {
public:
    int divide(int dividend, int divisor) {

        // Overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine sign
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long to avoid overflow
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long quotient = 0;

        while (a >= b) {

            long long temp = b;
            long long multiple = 1;

            // Double divisor using bit shifting
            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }

            // Subtract the largest possible multiple
            a -= temp;
            quotient += multiple;
        }

        // Apply sign
        if (negative) {
            quotient = -quotient;
        }

        // Clamp to 32-bit range
        if (quotient > INT_MAX) {
            return INT_MAX;
        }

        if (quotient < INT_MIN) {
            return INT_MIN;
        }

        return (int)quotient;
    }
};
