class Solution {
public:
    bool chk(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
        int d1=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
        int d2=(x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);
        int d3=(x4-x1)*(x4-x1)+(y4-y1)*(y4-y1);
        if(((d1==d2)&&(d3==2*d2))||((d2==d3)&&(d1==2*d2))||((d3==d1)&&(d2==2*d1)))return true;
        else return false;
           }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        int x1=p1[0],y1=p1[1],x2=p2[0],y2=p2[1],x3=p3[0],y3=p3[1],x4=p4[0],y4=p4[1];
        if(((x1==x2)&&(y1==y2))||((x1==x3)&&(y1==y3))||((x1==x4)&&(y1==y4))||((x2==x3)&&(y2==y3))||((x2==x4)&&(y2==y4))||((x3==x4)&&(y3==y4)))return false;
        bool a=chk(x1,y1,x2,y2,x3,y3,x4,y4);
        bool b=chk(x2,y2,x3,y3,x4,y4,x1,y1);
        bool c=chk(x3,y3,x4,y4,x1,y1,x2,y2);
        bool d=chk(x4,y4,x1,y1,x2,y2,x3,y3);
        if(a&&b&&c&&d)return true;
        else return false;
        
    }
};