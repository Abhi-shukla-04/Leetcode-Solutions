var minimumDeletions = function(nums) {
    let minIdx = 0;
    let maxIdx = 0;

    for (let i = 1; i < nums.length; i++) {
        if (nums[i] < nums[minIdx]) minIdx = i;
        if (nums[i] > nums[maxIdx]) maxIdx = i;
    }

    const left = Math.min(minIdx, maxIdx);
    const right = Math.max(minIdx, maxIdx);
    const n = nums.length;

    return Math.min(
        right + 1,
        n - left,
        left + 1 + n - right
    );
};
