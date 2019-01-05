class Solution {
public:
    int romanToInt(string s) {
    string pstr;
	int i,num;
	num=0;
	pstr="IVXLCDM";
	for(i=0;s[i];i++){
		if(s[i]==pstr[0]){
			if(s[i+1]==pstr[1]){
				num=num+4;
				i=i+1;
			}else if(s[i+1]==pstr[2]){
				num=num+9;
				i=i+1;
			}else{
				num=num+1;
			}
		}else if(s[i]==pstr[1]){
			num=num+5;
		}else if(s[i]==pstr[2]){
			if(s[i+1]==pstr[3]){
				num=num+40;
				i=i+1;
			}else if(s[i+1]==pstr[4]){
				num=num+90;
				i=i+1;
			}else{
				num=num+10;
			}
		}else if(s[i]==pstr[3]){
			num=num+50;
		}else if(s[i]==pstr[4]){
			if(s[i+1]==pstr[5]){
				num=num+400;
				i=i+1;
			}else if(s[i+1]==pstr[6]){
				num=num+900;
				i=i+1;
			}else{
				num=num+100;
			}
		}else if(s[i]==pstr[5]){
			num=num+500;
		}else if(s[i]==pstr[6]){
			num=num+1000;
		}
	}
	return num; 
    }
};