#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int removeDuplicates(int *nums, int numsSize)
{
    int k = 0;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            k++;
            nums[k] = nums[i];
        }
    }
    return k + 1;
}

int main()
{
    int a[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int numsSize = (int)sizeof(a) / sizeof(int);
    int k = removeDuplicates(a, numsSize);
    printf("%d\n", k);
    for (int i = 0; i < k; i++)
    {
        printf("%d\n", a[i]);
    }
}
