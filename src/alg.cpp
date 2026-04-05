// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
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
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }
            
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
    
    for (int i = 0; i < len; i++) {
        int target = value - arr[i];
        
        int left = i + 1;
        int right = len - 1;
        int firstPos = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                firstPos = mid;
                right = mid - 1;
            }
            else if (arr[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        if (firstPos != -1) {
            int lastPos = firstPos;
            while (lastPos + 1 < len && arr[lastPos + 1] == target) {
                lastPos++;
            }
            count += (lastPos - firstPos + 1);
        }
        
        while (i + 1 < len && arr[i + 1] == arr[i]) {
            i++;
        }
    }
    
    return count;
}
