/**
 * class Compare {
 *     public:
 *     static int cmp(int a, int b);
 * };
 * You can use Compare::cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
private:
    int comparation (int nuts_or_bolts, bool isNuts, int pivot) {
        if (isNuts) return Compare::cmp(nuts_or_bolts, pivot);
        else return -(Compare::cmp(pivot, nuts_or_bolts));
    }
    int partition(vector<int> &nuts_or_bolts, bool isNuts, int left, int right, int pivot) {
        int pre = left;
        for (int j = left; j < right; ++j) {
            if (comparation(nuts_or_bolts[j], isNuts, pivot) == -1) {
                swap(nuts_or_bolts[pre], nuts_or_bolts[j]);
                pre++;
            }
            else if (comparation(nuts_or_bolts[j], isNuts, pivot) == 0) {
                swap(nuts_or_bolts[right], nuts_or_bolts[j]);
                j--;
            }
        }
        swap(nuts_or_bolts[right], nuts_or_bolts[pre]);
        return pre;
    }
    
    void sort_helper (vector<int> &nuts, vector<int> &bolts, int left, int right) {
        if (left >= right) return;
        int idx = partition(nuts, true, left, right, bolts[right]);
        partition (bolts, false, left, right, nuts[idx]);
        sort_helper (nuts, bolts, left, idx-1);
        sort_helper (nuts, bolts, idx+1, right);
    }
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @return: nothing
     */
    void sortNutsAndBolts(vector<int> &nuts, vector<int> &bolts) {
        // write your code here
        int len = nuts.size();
        sort_helper(nuts, bolts, 0, len-1);
    }
};
