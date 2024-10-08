#define max(a, b) (a > b ? a : b)
int lengthOfLIS(int* nums, int numsSize){
    int i, j;
    int *dp = (int*)malloc(sizeof(int) * numsSize);
    for (i = 0; i < numsSize; i++)
        dp[i] = 1;
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < i; j++) {
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int lis = dp[0];
    for (i = 1; i < numsSize; i++)
        lis = max(lis, dp[i]);
    return lis;
}