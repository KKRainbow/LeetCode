class Solution {
    int max(int a, int b) 
    {
        return a > b ? a : b;
    }

    int min(int a, int b) 
    {
        return a < b ? a : b;
    }

public:
    int maxArea(vector<int>& arr) {
        int l = 0, r = arr.size() - 1, res = 0;
        res = max(res, min(arr[l], arr[r]) * (r - l));

        while (l < r) {
            if (arr[l] < arr[r]) {
                while(l < r && arr[l] < arr[r]) {
                    l++;
                    if (arr[l] > arr[l - 1]) {
                        res = max(res, min(arr[l], arr[r]) * (r - l));
                    }
                }
            }
            else if (arr[r] < arr[l]) {
                while(l < r && arr[r] < arr[l]) {
                    r--;
                    if (arr[r] > arr[r + 1]) {
                        res = max(res, min(arr[l], arr[r]) * (r - l));
                    }
                }
            } else {
                l++;
                r--;
            }
            res = max(res, min(arr[l], arr[r]) * (r - l));
        }
        return res;
    }
};