//https://leetcode.com/problems/container-with-most-water/
//11. Container With Most Water
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let s=0;
    let o=height.length-1;
    let ans=0;
    
    while(s!=o)
    {   ans=Math.max(ans,(Math.min(height[s],height[o])*(o-s)));
        if(height[s]<height[o])
        {   s+=1;}
        else{
            o-=1;
        }
    }
    return ans;
};