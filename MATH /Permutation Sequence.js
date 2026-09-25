/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
function getPermutation(n, k) {
    // Precompute factorials up to n and initialize available numbers
    const factorials = [1]; 
    const nums = [];
    
    for (let i = 1; i <= n; i++) {
        factorials.push(factorials[i - 1] * i);
        nums.push(i.toString());
    }
    
    // Convert k to 0-indexed to make the math align perfectly
    k -= 1;
    let result = "";
    
    // Iterate from left to right to determine each digit
    for (let i = n; i > 0; i--) {
        // Find the index of the current digit
        const blockSize = factorials[i - 1];
        const index = Math.floor(k / blockSize);
        
        // Append the digit to the result and remove it from available numbers
        result += nums[index];
        nums.splice(index, 1);
        
        // Update k to be the remainder for the next iteration
        k %= blockSize;
    }
    
    return result;
}

// Example usage:
console.log(getPermutation(3, 3)); // Output: "213"
