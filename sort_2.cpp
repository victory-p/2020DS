#include <iostream>
#define S_SIZE 50
using namespace std;

class s_record{
public :
    string s_id;
    string name;
    double score;
    s_record();
    s_record(string s1, string s2, double n);
};

s_record :: s_record(){
    s_id = "00000000";
    name = "None";
    score = 0;
}

s_record :: s_record(string s1, string s2, double n){
    s_id = s1;
    name = s2;
    score = n;
}
