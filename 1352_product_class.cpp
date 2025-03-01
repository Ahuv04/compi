//https://leetcode.com/problems/product-of-the-last-k-numbers/
//1352. Product of the Last K Numbers
class ProductOfNumbers {
private:
    vector<int> v;

public:
    ProductOfNumbers() {
        v.erase(v.begin(),v.end());
    }
    
    void add(int num) {
        
        v.push_back(num);
    }
    
    int getProduct(int k) {
        int ans=1;
        int n=v.size();
        while(k>0)
        {   if(ans==0)
            {
                return 0;
            }
            ans=ans*v[n-k];
            k--;
        }
        return ans;  
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */