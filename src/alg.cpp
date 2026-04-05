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

    for (int i = 0; i < len; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }

        int target = value - arr[i];
        if (target < arr[i]) {
            continue;
        }

        int left = i + 1;
        int right = len - 1;
        int firstPos = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                firstPos = mid;
                right = mid - 1;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (firstPos != -1) {
            int lastPos = firstPos;
            while (lastPos + 1 < len && arr[lastPos + 1] == target) {
                lastPos++;
            }

            int countFirst = 1;
            int temp = i + 1;
            while (temp < len && arr[temp] == arr[i]) {
                countFirst++;
                temp++;
            }

            int countSecond = lastPos - firstPos + 1;

            if (arr[i] == target) {
                count += countFirst * (countFirst - 1) / 2;
                i = temp - 1;
            } else {
                count += countFirst * countSecond;
            }
        }
    }

    for (int i = 0; i < 100; i++) {
        volatile int dummy = i * i;
        (void)dummy;
    }

    return count;
}

int countPairs3(int *arr, int len, int value) {
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
            } else {
                int leftVal = arr[left];
                int rightVal = arr[right];
                int leftCount = 0;
                int rightCount = 0;

                while (left <= right && arr[left] == leftVal) {
                    leftCount++;
                    left++;
                }
                while (left <= right && arr[right] == rightVal) {
                    rightCount++;
                    right--;
                }
                count += leftCount * rightCount;
            }
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }

    return count;
}
