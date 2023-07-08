class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        vector<int> merged;
        int ptr1 = 0;
        int ptr2 = 0;
        int k = (nums1.size() + nums2.size()) - 1;
        int c = 0;
        while (true)  {
            if(nums1.size() == 0) {
                merged = nums2;
                break;
            }
            else if(nums2.size() ==0) {
                merged = nums1;
                break;
            }


            if(nums1[ptr1] >= nums2[ptr2]) {
                merged.push_back(nums2[ptr2]);
                ptr2+=1;
            }
            else {
                merged.push_back(nums1[ptr1]);
                cout<<"nums1 append"<<ptr1<<endl;
                ptr1+=1;
            }
            if (ptr1 > nums1.size()-1 || ptr2 > nums2.size()-1) {
                break;
            }
        }
        if (ptr1 > nums1.size()-1) {
            merged.insert(merged.end(), nums2.begin()+ptr2, nums2.end());
        }
        else if(ptr2 > nums2.size()-1) {
            merged.insert(merged.end(), nums1.begin()+ptr1, nums1.end());
        }

        if(k % 2 == 1) {
            ans = (merged[k/2] + merged[k/2 + 1])/2.0;
        }
        else {
            ans = merged[k/2];
        }
        return ans;
    }
};