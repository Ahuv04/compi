//https://leetcode.com/problems/substring-with-concatenation-of-all-words/
//30. Substring with Concatenation of All Words

//two solutions with time execceeded
class Solution {
    // This is the reference map.
    std::unordered_map<std::string, unsigned int> map;
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        std::vector<int> result;

        // Length of each word in words.
        unsigned int length = words[0].size();

        // Initializing the reference map.
        map.clear();
        for (const std::string& word : words)
            map[word]++;

        // Iterate for each offset
        // As many times as the number of characters in each word.
        for (unsigned int offset = 0; offset < length; ++offset) {
            // Sliding window size.
            unsigned int size = 0;
            // Sliding window memory.
            std::unordered_map<std::string, unsigned int> seen;

            // Iterate over the string, with the step equals to length.
            for (unsigned int i = offset; i + length <= s.size(); i += length) {
                // This is the word we're going to check.
                std::string sub = s.substr(i, length);

                // If the word is absent in the reference map,
                // we clear the sliding window and move on.
                auto itr = map.find(sub);
                if (itr == map.end()) {
                    seen.clear();
                    size = 0;
                    continue;
                }

                // Increase the number of occurrences
                // of the word in seen map.
                ++seen[sub];
                ++size;

                // To make sure the sliding window is valid,
                // we need to check only the recent occurrence
                // against the reference,
                // because previous occurrences
                // were checked on previous iterations.
                while (seen[sub] > itr->second) {
                    // If the occurrences amount exceeds
                    // the reference amount,
                    // we shrink the window from the left until
                    // the window becomes valid again.

                    // A word at the beginning of the current sliding window.
                    std::string first = s.substr(i - (size - 1) * length, length);

                    // Remove the occurrence from the window,
                    // shrinking it from the left.
                    --seen[first];
                    --size;
                }
                
                // If we used all words from the words array,
                // we have found the correct spot
                // and we need to calculate the beginning
                // index of the current sliding window.
                if (size == words.size())
                    result.push_back(i - (size - 1) * length);
            }
        }

        return result;
    }
};

/*
time limit execeeded
class Solution {
public:

    bool strHelper(string s, unordered_map<string,int> m, int total, int ws){
        string h;
        for(int i=0;i<s.size();i+=ws)
        {   h=s.substr(i,ws);
             if(m.find(h)==m.end() || --m[h]<0)
             {
                return false;
             }
        }
        return true;

    }


    vector<int> findSubstring(string s, vector<string>& words) {

        int total=words.size()*words[0].size();
        vector<int> ans;
        if(words.empty() || s.empty() || s.size()<total) return ans;
        unordered_map<string, int> m;

        for(string str: words)
        {
            m[str]++;
        }

        for(int i=0; i+total<=s.size();i++)
        {   if(strHelper(s.substr(i,total), m, total, words[0].size()))
            {   ans.push_back(i);}
        }

        return ans;
    }
};
*/

/*
//time limit execceeded
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int total=words.size()*words[0].size();
        vector<int> ans;
        if(s.size()<total) return ans;
        sort(words.begin(),words.end());
        
        for(int i=0;i+total<=s.size();i++)
        {   vector<string> temp;
            for(int j=i;j<i+total;j+=words[0].size()){
                temp.push_back(s.substr(j,words[0].size()));
            }
            sort(temp.begin(),temp.end());
            if(temp==words)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
*/