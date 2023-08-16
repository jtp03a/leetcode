#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main() {
    int nums[] = {2,7,11,15};

    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int* returnSize = 0;

    int target = 9;

    int* result = twoSum(nums, numsSize, target, returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", *result);
    }

    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *result = malloc(sizeof(int) * 2);

    int sum = 0;
    int i = 0;

    while (sum != target) {
        if (sum + nums[i] > target) {
            continue;
        } else {
            
        }
    }

    return result;    
}