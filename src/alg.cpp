// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
                while (j + 1 < len && arr[j + 1] == arr[j]) j++;
            }
        }
        while (i + 1 < len && arr[i + 1] == arr[i]) i++;
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        
        if (sum == value) {
            int leftCount = 1;
            while (left + 1 < right && arr[left + 1] == arr[left]) {
                leftCount++;
                left++;
            }
            
            int rightCount = 1;
            while (right - 1 > left && arr[right - 1] == arr[right]) {
                rightCount++;
                right--;
            }
            
            count += leftCount * rightCount;
            left++;
            right--;
        }
        else if (sum < value) {
            left++;
        }
        else {
            right--;
        }
    }
    
    return count;
}

int binarySearch(int *arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            while (mid > left && arr[mid - 1] == target) mid--;
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    int i = 0;
    
    while (i < len) {
        int target = value - arr[i];
        if (target < arr[i]) break;
        
        int foundIndex = binarySearch(arr, i + 1, len - 1, target);
        
        if (foundIndex != -1) {
            int countFirst = 1;
            while (i + 1 < len && arr[i + 1] == arr[i]) {
                countFirst++;
                i++;
            }
            
            int countSecond = 1;
            int j = foundIndex;
            while (j + 1 < len && arr[j + 1] == target) {
                countSecond++;
                j++;
            }
            
            count += countFirst * countSecond;
        }
        i++;
    }  
    return count;
}
