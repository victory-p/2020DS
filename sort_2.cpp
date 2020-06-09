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

void quick_sort(s_record a[], int left, int right){
    s_record pivot, temp;
    int i,j;
    if(left >= right) return;
    i = left;
    j = right + 1;
    pivot = a[left];

    do{
        do{
            i++;
        }while((i <= right) && (a[i].s_id < pivot.s_id));
        do{
            j--;
        }while(a[j].s_id > pivot.s_id);
        if(i<j) swap(a[i], a[j]);
    }while(i<j);
    swap(a[left], a[j]);
    quick_sort(a, left, j-1);
    quick_sort(a, j+1, right);
}
