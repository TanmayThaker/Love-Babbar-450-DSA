//Minimum number of bracket reversals needed to make an expression balanced
//Practice link : https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1
//Video link : https://www.youtube.com/watch?v=-n_CsIL3Ts4


int countRev (string s)
{
    // your code here
    int count=-1;
    if(s.length()&1) return count;
    else
    {
        stack<char> st;
        int c2=0;//count of opening brackets
        int c=0; //count of closing brackets
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(ch=='{')
            {
                st.push(ch);
                c2++;
            }
            else if(ch=='}' and !st.empty() and st.top()=='{')
            {
                st.pop();
                c2--;
            }
            else
            {
                c++; //It is a closing bracket
            }
        }
        if(c&1)
        {
            c=(c/2)+1;
        }
        else 
        {
            c=c/2;
            
        }
        if(c2&1)
        {
            c2=(c2/2)+1;
        }
        
        else
        {
            c2=c2/2;
        }
        count=c+c2;
        return count;
    }
    
    
}