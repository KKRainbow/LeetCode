class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w, l;
        for (l = (int)sqrt(area); l >= 1; l--) {
            if (area % l == 0) {
                w = area / l;
                return {w, l};
            }
        }
        return {0,0};
    }
};