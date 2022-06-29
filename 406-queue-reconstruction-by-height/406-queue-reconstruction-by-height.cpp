class Solution {
public:
    //each person of height h want k ppl to be ahead of him in queue
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        sort(people.begin(),people.end(),cmp);
        //cmp compares 2 blocks of ppl vector 
        vector<vector<int>> ans;
//each person p[h,k] knows ki merse aage aaye hue all ppl have larger/same height
//p wants to stand after k of them (index k),shifting back all piche wale
//pichle walo ke aage choti height wale ke aane se koi frk na pdega        
        for(auto p:people){
            ans.insert(ans.begin()+p[1], p);
            //insert func shifts all piche wale, one step back
            //        (position iterator, value to be inserted)
        }
        return ans;
    }
    //sort the ppl vector first on the basis of decreasing heights
    //for same height, sort on increasing k
    
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0]!=b[0]) return a[0]>b[0]; //decreasing heights me sorting
        else return a[1]<b[1]; //increasing k when same height
    }
};