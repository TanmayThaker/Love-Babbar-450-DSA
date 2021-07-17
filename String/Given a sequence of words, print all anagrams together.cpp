//Given a sequence of words, print all anagrams together
//Practice link : https://practice.geeksforgeeks.org/problems/print-anagrams-together/1
//Video solution : https://www.youtube.com/watch?v=K3hlxOhxn9I


vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    // Your Code Here
    map<string,vector<string>> m;
    for(int i=0;i<string_list.size();i++)
    {
        string s = string_list[i];
        sort(s.begin(),s.end());
        m[s].push_back(string_list[i]);
    }
    vector<vector<string>> ans(m.size());
    int idx=0;
    for(auto x:m)
    {
        auto v = x.second; //Here in 'v' we will get a vector
        for(int i=0;i<v.size();i++)
        {
            ans[idx].push_back(v[i]);
        }
        idx++;
    }
    return ans;
}

/*
TC:O(N*MlogM) MlogM for sorting and it is getting sorted for N elements hence TC will be N*MlogM
SC:O(N)
*/