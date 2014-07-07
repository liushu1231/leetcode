

#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    void stringTrim(string &s){
        size_t left = 0;
        size_t right = s.length()-1;
         while(s[left] == ' ' && left < s.length())
        {
            left++;
        }
        while(s[right] == ' ' && right >= 0)
        {
            right--;
        }
        if(left > right)
        {
            s = "";
            return;
        }
        else
        {
            s = s.substr(left,right-left+1);
            string::iterator it  = s.begin();
            for( it == s.begin(); it != s.end(); it++)
            {
                if ( *it == ' ' && *(it+1) == ' '){
                    s.erase(it);
                    it --;
                }
            }
        }
    }
    void reverseWordsHelper(string& s)
    {
        int i = 0;
        char temp;
        for(i = 0; i < s.length()/2; i++)
        {

            temp = s[i];
            s[i] = s[s.length()-i-1];
            s[s.length()-i-1] = temp;
        }
    }
    void reverseWords(string &s) {
        if(s.length() == 0)
            return;
            
        stringTrim(s);
        
        //reverse each word
        size_t pos = 0;
        size_t pos_new = 0;
        
        //reverse the whole sentence
        if( (pos_new = s.find(' ',pos)) == string::npos)
            return;
        
        reverseWordsHelper(s);

        char temp;
        while(pos_new != string::npos)
        {
            int len = pos_new - pos;
            for(int i = 0; i < len/2; i++ )
            {
                temp = s[pos + i];
                s[pos+i] = s[pos + len-i-1];
                s[pos + len-i-1] = temp;
            }
            pos = pos_new+1;
            pos_new = s.find(' ',pos+1);
        }
    }
};