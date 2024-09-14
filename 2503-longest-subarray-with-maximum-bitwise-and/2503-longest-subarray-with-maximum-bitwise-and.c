int longestSubarray(int* nums, int numsSize) {
    if (numsSize == 1) {
        return 1;
    }
    int maximumBit = nums[0];
    int max = 1;
    int count = 0;
    int i;
    for (i = 1; i < numsSize; i++) {
        if (nums[i] > maximumBit) {
            maximumBit = nums[i];
        }
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == maximumBit) {
            count++;
            if (count > max) {
                max = count;
            }
        } else {
            count = 0;
        }
    }
    return max;
}
