//https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/
//3306. Count of Substrings Containing Every Vowel and K Consonants II
class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

    long long atleastK(string word, int k){
        int n=word.size();
        unordered_map<char,int> m;
        int cons=0;
        long long ans=0;
        int left=0;

        for(int i=0;i<n;i++){
            if(isVowel(word[i])){
                m[word[i]]++;
            }
            else{
                cons++;
            }

            while(m.size()==5 && cons>=k){
                ans+=n-i;
                if(isVowel(word[left])){
                    m[word[left]]--;
                    if(m[word[left]]==0){
                        m.erase(word[left]);
                    }
                }
                else{
                    cons--;
                }
                left++;
            }
        }

        return ans;
    }

    long long countOfSubstrings(string word, int k) {
        return atleastK(word, k) - atleastK(word, k+1);
    }
};