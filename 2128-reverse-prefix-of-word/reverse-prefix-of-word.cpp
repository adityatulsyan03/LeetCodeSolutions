class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i=0,j=0;
        while(j<word.size() && word[j]!=ch)
            j++;
        while(i<j && j<word.size()){
            swap(word[i],word[j]);
            i++;
            j--;
        }
        return word;
    }
};