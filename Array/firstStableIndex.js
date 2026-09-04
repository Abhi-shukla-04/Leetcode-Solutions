var firstStableIndex = function(nums, k) {
    const n = nums.length;

    const suffixMin = new Array(n);
    suffixMin[n - 1] = nums[n - 1];

    // Build suffix minimum
    for (let i = n - 2; i >= 0; i--) {
        suffixMin[i] = Math.min(nums[i], suffixMin[i + 1]);
    }

    // Find first stable index
    let prefixMax = nums[0];

    for (let i = 0; i < n; i++) {
        prefixMax = Math.max(prefixMax, nums[i]);

        if (prefixMax - suffixMin[i] <= k) {
            return i;
        }
    }

    return -1;
};
