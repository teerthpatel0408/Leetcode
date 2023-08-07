class Solution {
public:
    int computeArea(int a, int b, int c, int d, int e, int f, int g, int h) {
        int s1=(c-a)*(d-b);
        int s2=(g-e)*(h-f);
        if(a>=g || c<=e || d<=f || b>=h){
            return s1+s2;
        }
        return s1-(min(g,c)-max(a,e))*(min(d,h)-max(b,f))+s2;
    }
};