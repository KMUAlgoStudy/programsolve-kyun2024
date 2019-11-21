#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <regex>
#include <memory>

using namespace std;
using namespace std::string_literals;

class base{
protected:
    string s;
    int n;
public:
    virtual string toString() = 0;
};

class dstr : public base{
public:
    dstr(string s){
        this->s = s;
    }
    dstr(char c){
        this->s = c;
    }
    virtual string toString() override{
        return s;
    }
};

class dint : public base{
public:
    dint(int n){
        this->n = n;
    }
    virtual string toString() override{
        return std::to_string(n);
    }
};

bool check_rand(char c){
    return c>='0' && c<='9';
}

bool check_op(char c){
    return !(c - '+') | !(c - '-') | !(c - '*') | !(c - '/') | !(c - '^');
}

bool check_bra(char c){
    return !(c - '(') | !(c - ')');
}

int main(){
    int i,t,sig;
    vector<unique_ptr<base>> token;
    string s;
    getline(cin,s);
    auto init = [&sig,&t](){
        sig = 1;
        t = 0;
    };
    init();
    for(i=0;i<s.size();i++){
        if(i==0 && s[i] == '-'){
            sig = -1;
        }
        if('0' <= s[i] && s[i] <= '9')
        {
            t = 10*t + (s[i]-'0');
        }
        
        if(check_op(s[i])){
            if(i>0 & !(s[i] - '-') & check_op(s[i-1])){
                sig = -1;
            }
            else{
                token.push_back(make_unique<dint>(sig*t));
                token.push_back(make_unique<dstr>(s[i]));
            }
            init();
        }
        if(s[i] == '('){
            token.push_back(make_unique<dstr>(s[i]));
        }
        if(s[i] == ')'){
            token.push_back(make_unique<dint>(sig*t));
            token.push_back(make_unique<dstr>(s[i]));
        }
    }
    if(check_rand(s.back()))
        token.push_back(make_unique<dint>(sig*t));
    
    for(i=0;i<token.size();i++){
        cout << token[i]->toString() << endl;
    } 
}
  