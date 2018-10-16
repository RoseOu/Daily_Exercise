class Solution {
public:
    int reverse(int x) {
        long int num,pnum,ynum,res=0,i,length=0;
        if(x<0){
            num=x*(-1);
        }else{
            num=x;
        }
        pnum=num;
        while(pnum>0){
            pnum=pnum/10;
            length=length+1;
        }
        pnum=num;
        for(i=length;pnum>0;i--){
            ynum=pnum%10;
            pnum=pnum/10;
            res=res+ynum*pow(10,i-1);
        }
        if(x<0){
            res=res*(-1);
        }
        if(res<-1*pow(2,31)||res>pow(2,31)-1){
            return 0;
        }
        return res;
    }
};