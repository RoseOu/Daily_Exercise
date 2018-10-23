class Solution {
public:
    bool isPalindrome(int x) {
	int length,pnum,snum,ynum,res,i,j;
	pnum=x;
	snum=x;
	res=0;
	for(i=0;pnum>0;i++){
		pnum=pnum/10;
	}
	length=i;
	for(i=0,j=length;snum>0;i++,j--){
		ynum=snum%10;
		snum=snum/10;
		res=res+ynum * pow(10,j-1);
		
	}
	if(x==res){
		return true;
	}else{
		return false;
	}
	return 0;
    }
};