//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int upperbound(vector<int>&cnt, int elem)
    {
        int s = 0, e = cnt.size() - 1, ans=-1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (cnt[mid] == elem)
            {
                ans = mid;
                s = mid + 1;
            }
            else if (cnt[mid] > elem)
            {
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        if(ans==-1)
        return s;
        else
        return ans;
    }
    vector<int> kthSmallestNum(int n, vector<vector<int>> &range, int q, vector<int> &queries)
    {
        
        vector<int> cnt, ans;
        for (int i = 0; i < range.size(); i++)
        {
            int cnt1 = range[i][0];
            int cnt2 = range[i][1];
            int num = cnt2 - cnt1 + 1;
            cnt.push_back(num);
        }

        for (int i = 1; i < cnt.size(); i++)
        {
            cnt[i] += cnt[i - 1];
        }

        for (int i = 0; i < queries.size(); i++)
        {
            int elem = queries[i];
            if(elem>cnt[cnt.size()-1])
            {
                ans.push_back(-1);
            }
            else
            {
            int index = upperbound(cnt, elem);
           // cout<<index<<"  ";
            if (index > 0)
                elem -= cnt[index - 1];
            for (int j = range[index][0]; j <= range[index][1]; j++)
            {
                elem--;
                if (elem == 0)
                {
                    ans.push_back(j);
                    break;
                }
            }}
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    // int t = 1;
    // // cin>>t;
    // while (t--)
    // {
        int n;
        cin >> n;
        vector<vector<int>> range(n, vector<int>(2, 0));
        for (int i = 0; i < n; i++)
        {
            cin >> range[i][0] >> range[i][1];
        }
        int q;
        cin >> q;
        vector<int> queries;
        for (int i = 0; i < q; i++)
        {
            int x;
            cin >> x;
            queries.push_back(x);
        }
        Solution ob;
        vector<int> ans = ob.kthSmallestNum(n, range, q, queries);
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    // }
    return 0;
}

// } Driver Code Ends