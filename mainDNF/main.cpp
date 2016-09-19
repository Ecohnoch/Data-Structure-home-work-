#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Test1{  // input a DNF , output a mainDNF
public:
    bool calLogical(char ch1, char judge, char ch2){
        bool tmp1, tmp2;
        char table[5] = {'p', 'q', 'r', 't', 'f'};
        int bTable[5] = {p, q, r, 1, 0};
        for(int i = 0; i < 5; i++){
            if(ch1 == table[i])
                tmp1 = bTable[i]>=1?true:false;
            if(ch2 == table[i])
                tmp2 = bTable[i]>=1?true:false;
        }

        if(judge == '&')
            return tmp1 && tmp2;
        else
            return tmp1 || tmp2;
    }

    bool calF(char ch1){
        int table[3] = {'p','q','r'};
        int bTable[3] = {p, q, r};
        for(int i = 0; i < 3; i++){
            if(ch1 == table[i])
                return !bTable[i];
        }
        return false;
    }

    char translate(bool t){
        if(t == true) return 't';
        else return 'f';
    }

    bool getRes(string ques){  //recursion func
        int length = ques.length();
        if(length == 1 ){
            if(ques.at(0) == 't')
                return true;
            else if(ques.at(0) == 'f')
                return false;
        }  // quit recursion,, when there is only one char
        else{
            for( int i = 0; i < length - 1; i++){  // main loop
                if(ques.at(i) == '!'){
                    bool tmp = calF(ques.at(i+1));
                    ques.at(i+1) = tmp?'t':'f';
                    ques.erase(i, 1);
                    return getRes(ques);
                }
                if(ques.at(i) == '(' && (ques.at(i+1) == 't'||ques.at(i+1) == 'f') && ques.at(i+2) ==')'){
                    ques.at(i) = ques.at(i+1);
                    ques.erase(i+1, 2);
                    return getRes(ques);
                }
                if(ques.at(i) == '|' || ques.at(i) == '&'){   // hequ and xiqu
                    if((ques.at(i-1) != '(' && ques.at(i-1) != ')') &&
                            (ques.at(i+1) != '(' && ques.at(i+1) != ')')){

                        bool tmp = calLogical(ques.at(i-1), ques.at(i), ques.at(i+1));
                        ques.at(i-1) = translate(tmp);
                        ques.erase(i, 2);    // p | (q & r)
                        return getRes(ques);
                    }
                }
            }
        }
    }

    void test(){
        string ss("p|(!q&r)");
        for(p = 0; p <= 1; p++){
            for(q = 0; q <= 1; q++){
                for(r = 0; r <= 1; r++){
                    res = getRes(ss);
                    if(!res){
                        cout<< p<<" "<<q<<" "<<r<<" "<<res<<" m"<<p<<q<<r<<endl;
                    }else
                        cout<< p<<" "<<q<<" "<<r<<" "<<res<<endl;
                }
            }
        }
    }

private:
    int p, q, r;
    bool res;
};

int main()
{
    Test1 test;
    test.test();
    return 0;
}
