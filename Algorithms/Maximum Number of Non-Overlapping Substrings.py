class Solution(object):
    def maxNumOfSubstrings(self, s):
        # Step 1: Find the first and last occurrence of each character
        L = {}
        R = {}
        for i, char in enumerate(s):
            if char not in L:
                L[char] = i
            R[char] = i
            
        valid_intervals = []
        
        # Step 2: Find all valid intervals
        for char in set(s):
            start = L[char]
            end = R[char]
            i = start
            is_valid = True
            
            while i <= end:
                # If a character inside our current window has its first occurrence
                # before our starting point, this window is invalid.
                if L[s[i]] < start:
                    is_valid = False
                    break
                # Expand the end of the window if necessary
                end = max(end, R[s[i]])
                i += 1
                
            if is_valid:
                valid_intervals.append((start, end))
                
        # Step 3: Sort intervals to maximize count and minimize length
        # Sort primarily by end position (ascending)
        # Sort secondarily by start position (descending) to prefer shorter strings
        valid_intervals.sort(key=lambda x: (x[1], -x[0]))
        
        # Step 4: Greedily pick non-overlapping intervals
        res = []
        last_end = -1
        
        for start, end in valid_intervals:
            # If the current interval starts after the last added interval ends
            if start > last_end:
                res.append(s[start:end+1])
                last_end = end
                
        return res
