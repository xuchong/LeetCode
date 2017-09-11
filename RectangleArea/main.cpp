class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x0=max(A,E);
        int y0=max(B,F);
        int x1=min(C,G);
        int y1=min(D,H);
        int area=0;
        if(x0<x1&&y0<y1)
          area=(x1-x0)*(y1-y0);
        return ((D-B)*(C-A)+(H-F)*(G-E)-area);
    }
};
