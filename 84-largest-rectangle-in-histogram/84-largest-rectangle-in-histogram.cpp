class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
          vector<int> left(n);
         // stores left next smaller boundary idx of each left[i]
          left[0]=-1;
          vector<int> right(n);
         //stores right next smaller boundary idx of each right[i]
          right[n-1]=n;
            
          stack<int> st;
            st.push(0);
          for(int i=1;i<n;i++){
                  while(st.size()>0 && heights[i]<=heights[st.top()]){
                          st.pop();
                  }
                  if(st.empty()) left[i]=-1;
                  else left[i]= st.top();
                  st.push(i);
          }
           
          while (!st.empty())
            st.pop();
            
            st.push(n-1);
             for(int i=n-2;i>=0;i--){
                  while(st.size()>0 && heights[i]<=heights[st.top()]){
                          st.pop();
                  }
                  if(st.empty()) right[i]=n;
                  else{
                          right[i]= st.top();
                  }
                     st.push(i);
          }
            
           // if on ith index, height[i] ko pura lenge toh area aayega
            int maxArea=INT_MIN;
            for(int i=0;i<n;i++){
                    int area= (right[i]-left[i]-1)*heights[i];
                    maxArea=max(area,maxArea);
            }
            return maxArea;
    }
};