class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        // making u_map to keep track of every string present in the ideas
        unordered_map<string, int> mp;
        for(string x: ideas)
            mp[x] = 1;
        
        int ans = 0;
        for(int i=0; i<ideas.size(); i++)
        {
            for(int j=0; j<ideas.size(); j++)
            {
                if(i != j)
                {
                    // making separate strings
                    string first = ideas[i];
                    string second = ideas[j];
                    
                    // swapping them 
                    char c = first[0];
                    first[0] = second[0];
                    second[0] = c;
                    
                    // checking if the two strings are present
                    // in the ideas or not, if not increase
                    // 'ans' variable by 1 and return it
                    if(mp[first] == 0 && mp[second] == 0)
                        ans++;
                }
            }
        }
        
        return ans;
    }
};