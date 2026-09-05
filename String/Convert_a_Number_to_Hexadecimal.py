class Solution:
    def toHex(self, num):
        if num == 0:
            return "0"

        hex_chars = "0123456789abcdef"

        # Convert negative number to 32-bit two's complement
        if num < 0:
            num = num + (1 << 32)

        result = ""

        while num > 0:
            digit = num & 15
            result = hex_chars[digit] + result
            num = num >> 4

        return result
