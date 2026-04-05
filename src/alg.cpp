// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value)
{
    int count = 0;

    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] + arr[j] == value)
                count++;
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value)
{
    int left = 0;
    int right = len - 1;
    int count = 0;

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum == value)
        {
            if (arr[left] == arr[right])
            {
                int k = right - left + 1;
                count += k * (k - 1) / 2;
                break;
            }

            int l_val = arr[left], r_val = arr[right];
            int l_count = 0, r_count = 0;
            while (left < len && arr[left] == l_val)
            {
                l_count++;
                left++;
            }

            while (right >= 0 && arr[right] == r_val)
            {
                r_count++;
                right--;
            }
            count += l_count * r_count;
        }
        else if (sum < value)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return count;
}

int binarySearch(int *arr, int left, int right, int target)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}


int countPairs3(int *arr, int len, int value)
{
    int count = 0;

    for (int i = 0; i < len; i++)
    {
        int target = value - arr[i];

        int idx = binarySearch(arr, i + 1, len - 1, target);

        if (idx != -1)
        {
            int left = idx;
            int right = idx;

            while (left > i && arr[left - 1] == target)
                left--;

            while (right < len - 1 && arr[right + 1] == target)
                right++;

            count += (right - left + 1);
        }
    }

    return count;
}
