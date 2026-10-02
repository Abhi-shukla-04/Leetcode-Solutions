class Solution(object):
    def generateParenthesis(self, n):
        result = []
        
        def backtrack(open_count, close_count, current_string):
            # Base case: valid combination found
            if open_count == n and close_count == n:
                result.append(current_string)
                return
            
            # Rule 1: Add '(' if we haven't reached the limit
            if open_count < n:
                backtrack(open_count + 1, close_count, current_string + "(")
                
            # Rule 2: Add ')' if there are unmatched '(' available
            if close_count < open_count:
                backtrack(open_count, close_count + 1, current_string + ")")
                
        # Start recursion
        backtrack(0, 0, "")
        
        return result
