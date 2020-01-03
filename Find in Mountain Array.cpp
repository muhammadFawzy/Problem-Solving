/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray& mountainArr)
    {
        int peak = findPeak(mountainArr, 0, mountainArr.length());

        if (mountainArr.get(peak) == target)
            return peak;
        else if (mountainArr.get(peak - 1) < target && mountainArr.get(peak + 1) < target)
            return -1;
        else if (mountainArr.get(peak - 1) >= target) {
            // going to left hand side
            int index = biSearch(mountainArr, 0, peak, true, target);

            if (index != -1)
                return index;
            else
                return biSearch(mountainArr, peak, mountainArr.length(), false, target);
        }
        else {
            // going to right hand side
            return biSearch(mountainArr, peak, mountainArr.length(), false, target);
        }

        return -1;
    }

    int findPeak(MountainArray& mountainArr, int start, int end)
    {

        int mid = (end + start) / 2;

        if (mountainArr.get(mid) > mountainArr.get(mid - 1) && mountainArr.get(mid) > mountainArr.get(mid + 1)) {
            return mid;
        }

        if (mountainArr.get(mid + 1) > mountainArr.get(mid))
            return findPeak(mountainArr, mid, end); // right hand
        else
            return findPeak(mountainArr, start, mid); // left

        return -1;
    }
    int biSearch(MountainArray& mountainArr, int start, int end, bool asc, int target)
    {

        if (start < end) {
            int mid = (start + end) / 2;

            if (mountainArr.get(mid) == target)
                return mid;

            if (asc) {
                if (mountainArr.get(mid) > target) {
                    // left
                    return biSearch(mountainArr, start, mid, asc, target);
                }
                else {
                    //right
                    return biSearch(mountainArr, mid + 1, end, asc, target);
                }
            }
            else {
                if (mountainArr.get(mid) > target) {
                    // right
                    return biSearch(mountainArr, mid + 1, end, asc, target);
                }
                else {
                    //left
                    return biSearch(mountainArr, start, mid, asc, target);
                }
            }
        }

        return -1;
    }
};
