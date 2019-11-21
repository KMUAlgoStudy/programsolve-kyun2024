#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <exception>

using namespace std;

bool check_rand(char c)
{
    return c >= '0' && c <= '9';
}

bool check_op(char c)
{
    return !(c - '+') | !(c - '-') | !(c - '*') | !(c - '/') | !(c - '^');
}

bool check_bra(char c)
{
    return !(c - '(') | !(c - ')');
}

int op_level(char c){
    if(c == '+' || c == '-'){
        return 0;
    }
    else if(c == '*' || c == '/'){
        return 1;
    }
    else{
        //Only Brackets
        return 2;
    }
}

bool compare_op(const char c1,const char c2){
    return op_level(c1)>=op_level(c2);
}

int main()
{
    int i;
    vector<string> token,suf_token;
    stack<string> op_st;
    string s, t;
    
    getline(cin, s);

    try
    {
        for (i = 0; i < s.size(); i++)
        {
            if (!(check_bra(s[i]) | check_op(s[i]) | check_rand(s[i])))
            {
                throw "Wrong Character";
            }
            if (i == 0 && s[i] == '-')
            {
                t += s[i];
            }
            else if ('0' <= s[i] && s[i] <= '9')
            {
                t += s[i];
            }
            else if (check_op(s[i]))
            {
                if (i > 0 & !(s[i] - '-') & (check_op(s[i - 1]) | !(s[i - 1] ^ '(')))
                {
                    t += s[i];
                }
                else
                {
                    token.push_back(t);
                    token.push_back(string() + s[i]);
                    t = "";
                }
            }
            else if (s[i] == '(')
            {
                token.push_back(string() + s[i]);
            }
            else if (s[i] == ')')
            {
                token.push_back(t);
                token.push_back(string() + s[i]);
                t = "";
            }
        }
        if (check_rand(s.back()))
            token.push_back(t);
            t = "";

        for (i = 0; i < token.size(); i++)
        {
            cout << token[i] << endl;
        }
        //Calc
        for(i=0;i<token.size();i++){
            if(token[i].size()>1 || (token[i][0] >= '0' && token[i][0] <= '9')){
                suf_token.push_back(token[i]);
            }
            else{
                while(op_st.size()>0){
                    if(op_st.top()[0] != '(' && compare_op(op_st.top()[0],token[i][0])){
                        if(!check_bra(op_st.top()[0]))
                            suf_token.push_back(op_st.top());
                        op_st.pop();
                    }
                    else{
                        break;
                    }
                }
                if(token[i][0] == ')'){
                    while(op_st.top()[0] != '('){
                        suf_token.push_back(op_st.top());
                        op_st.pop();
                    }
                    if(op_st.top() == ""){
                        throw out_of_range("Invalid Token");
                    }
                    else op_st.pop();
                }
                else{
                    op_st.push(token[i]);
                }
                
            }
        }
        while(!op_st.empty()){
            if(!check_bra(op_st.top()[0]))
                suf_token.push_back(s=op_st.top());
            op_st.pop();
        }
        for (i = 0; i < suf_token.size(); i++)
        {
            cout << suf_token[i] << " ";
        }
        cout << endl;
    }
    catch (exception &e)
    {
        cout << "Error\n" << e.what() << endl;
    }
    catch (const char *message)
    {
        cout << message << endl;
    }
    return 0;
}
