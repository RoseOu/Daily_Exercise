class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    int num,i,j;
	string astr,bstr,res="";
    if(strs.size()!=0){
        astr=strs[0];
    }else{
        return "";
    }
	for(i=0;astr[i];i++){
		for(j=1;j<strs.size();j++){
			bstr=strs[j];
			if(bstr[i]!=astr[i]){
				break;
		    }
		}
		if(j>=strs.size()){
			res=res+astr[i];
		}else{
            break;
        }
	}
	return res;
    }
};