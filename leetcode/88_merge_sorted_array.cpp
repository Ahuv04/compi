//88. Merge Sorted Array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        if(n==0){
            return;
        }
        if(m==0){
            for(int i=0;i<nums2.size();i++)
            {   nums1[i]=nums2[i];

            }
            return;
        }
        int j=0;
        int tsize=0;
        int tcurr=0;
        for(int i=0;i<nums1.size();i++)
        {   if(i<m)
            {
                if(tsize==tcurr)
                {   if(nums2[j]<nums1[i])
                    {   temp.push_back(nums1[i]);
                        tsize++;
                        nums1[i]=nums2[j];
                        j++;
                    }
                }
                else if(j>=n)
                {   temp.push_back(nums1[i]);
                    tsize++;
                    nums1[i]=temp[tcurr];
                    tcurr++;
                }
                else
                {   if(nums2[j]<nums1[i] && nums2[j]<temp[tcurr])
                    {
                        temp.push_back(nums1[i]);
                        tsize++;
                        nums1[i]=nums2[j];
                        j++;
                    }
                    else{
                    temp.push_back(nums1[i]);
                    tsize++;
                    nums1[i]=temp[tcurr];
                    tcurr++;
                    }
                }
            }

            else{           
                if(tsize<=tcurr)
                {   nums1[i]=nums2[j];
                    j++;
                }
                else if(j>=n)
                {   
                    nums1[i]=temp[tcurr];
                    tcurr++;
                }
                else
                {   if(nums2[j]<temp[tcurr])
                    {
                        nums1[i]=nums2[j];
                        j++;
                    }
                    else{
                    nums1[i]=temp[tcurr];
                    tcurr++;
                    }
                }
            }
        }   
    }
};
