void moveZeroes(int* nums, int numsSize)
{
    if (numsSize == 1)
        return;
    int firstZero = -1, next = 0;
    while (next < numsSize)
    {
        if (firstZero >= 0 && nums[next])
        {
            nums[firstZero] = nums[next];
            nums[next] = 0;
            firstZero++;
        }
        else if (firstZero == -1 && !nums[next])
        {
            firstZero = next;
        }       
        next++;
    }
}