//https://leetcode.com/problems/permutation-sequence/
//60. Permutation Sequence
class Solution {
public:
int fact(int n){

     return (n==0) || (n==1) ? 1 : n* fact(n-1);
}
    string getPermutation(int n, int k) {
        vector<int> arr(n,0);
        for(int i=0;i<n;i++)
        {   arr[i]=i+1;}
        k=k-1;
        int fac=fact(n-1);
        int temp=k/fac;
        int temp2=k%fac;
        int n_copy=n-1;
        string ans;
        while(n_copy>=0)
        {   
            ans.append(to_string(arr[temp]));
            arr.erase(arr.begin()+(temp));
            if(n_copy==0)
                break;
            fac/=n_copy;
            n_copy-=1;
            temp=temp2/fac;
            temp2=temp2%fac;
        }
        return ans;
    }
};