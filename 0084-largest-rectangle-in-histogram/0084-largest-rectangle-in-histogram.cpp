class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        stack<int> s;
        int maxarea=0,i=0;
        while(i<n){
            if(s.empty() || arr[s.top()]<=arr[i]){
                s.push(i++);
            }
            else{
                int top=s.top();
                s.pop();
                int area=arr[top]*(s.empty()?i:i-s.top()-1);
                maxarea=max(maxarea,area);

            }
        }
        while(!s.empty()){
            int top=s.top();
            s.pop();
            int area=arr[top]*(s.empty()?n:n-s.top()-1);
            maxarea=max(maxarea,area);
        }
        return maxarea;
    }
};