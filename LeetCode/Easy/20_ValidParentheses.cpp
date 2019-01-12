class Solution {
public:
    bool isValid(string s) {
        int i;
        string lstr="([{",rstr=")]}";
        char str;
        stack <char> st;
        for(i=0;s[i];i++){
            if(s[i] == lstr[0] or s[i] == lstr[1] or s[i] == lstr[2]){
                st.push(s[i]);
            }else if(s[i] == rstr[0] or s[i] == rstr[1] or s[i] == rstr[2]){
                if(st.empty()){
                    return false;
                }else{
                    str=st.top();
                    st.pop();
                    if(str==lstr[0] && s[i]==rstr[0] || str==lstr[1] && s[i]==rstr[1] || str==lstr[2] && s[i]==rstr[2]){
                        continue;
                    }else{
                        return false;
                    }
                }
            }
        }
        if(st.empty()){
            return true;
        }else{
            return false;
        }
    }
};