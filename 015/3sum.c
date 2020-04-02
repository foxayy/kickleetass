int partition(int *nums, int low, int high)
{
    int pivot = nums[low];
    while(low < high) {
        while(low < high && nums[high] >= pivot) high--;
        nums[low] = nums[high];
        while(low < high && nums[low] < pivot) low++;
        nums[high] = nums[low];
    }
    nums[low] = pivot;
    return low;
}

int quick_sort(int *nums, int low, int high)
{
    if(low < high) {
        int pivot = partition(nums, low, high);
        quick_sort(nums, low, pivot - 1);
        quick_sort(nums, pivot + 1, high);
    }
    return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if(numsSize == 0 || numsSize == 1 || numsSize == 2) return 0;
    int low = 0, high = 0, count = 0;
    int **result = NULL;
    // sort the array first
    quick_sort(nums, 0, numsSize - 1);
    
    for(int i = 0; i < numsSize - 2; i ++) {
        if(i > 0 && nums[i - 1] == nums[i]) continue;
        low = i + 1;
        high = numsSize - 1;
        while(low < high) {
            if(nums[i] + nums[low] + nums[high] == 0) {
                int *resTmp = (int *)malloc(sizeof(int) * 3);
                resTmp[0] = nums[i];
                resTmp[1] = nums[low];
                resTmp[2] = nums[high];
                if(result == NULL){
                    result = malloc(sizeof(int *));
                    result[count] = resTmp;
                } else {
                    result = realloc(result, sizeof(int *) * (count + 1));
                    result[count] = resTmp;
                }
                count++;
                while(low < numsSize - 1 && nums[low] == nums[low + 1]) low++;
                while(high > 0 && nums[high] == nums[high - 1]) high--;
                low++;
                high--;
            } else if(nums[i] + nums[low] + nums[high] > 0) {
                while(high > 0 && nums[high] == nums[high - 1]) high--;
                high--;
            } else {
                while(low < numsSize - 1 && nums[low] == nums[low + 1]) low++;
                low++;
            }
        }
    }
    *returnSize = count;
    *returnColumnSizes = (int *)malloc(sizeof(int) * count);
    for(int i = 0; i < count; i++) {
        (*returnColumnSizes)[i] = 3;
    }
    return result;
}
