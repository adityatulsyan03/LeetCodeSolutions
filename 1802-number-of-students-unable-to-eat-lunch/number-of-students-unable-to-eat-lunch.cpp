class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> st;
        for(auto i:students){
            st.push(i);
        }
        for(int i=0;i<sandwiches.size();i++){
            int n=st.size();
            bool flag = false;
            while(n--){
                if(sandwiches[i]==st.front()){
                    st.pop();
                    flag = true;
                    break;
                }
                else{
                    int t=st.front();
                    st.pop();
                    st.push(t);
                }
            }
            if(!flag)
                return st.size();
        }
        return 0;
    }
};