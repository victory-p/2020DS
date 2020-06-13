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

void adjust(s_record a[], int troot, int size){
    string tmpkey;
    int child;
    s_record temp;

    temp = a[troot];
    tmpkey = a[troot].s_id;
    child = troot * 2;

    while(child <= size){
        if((child < size) && (a[child].s_id < a[child+1].s_id)) child++;
        if(tmpkey > a[child].s_id) break;
        else{
            a[child/2] = a[child];
            child *= 2;
        }
    }
    a[child/2] = temp;
}

void heap_sort(s_record a[], int n){
    int i;
    s_record b[S_SIZE], temp;
    
    for(i=0; i<n; i++){
        b[i+1] = a[i];
    }
    for(i=n/2; i>0; i--){
        adjust(b,i,n);
    }
    for(i=n-1; i>0; i--){
        temp = b[1];
        b[1] = b[i+1];
        b[i+1] = temp;
        adjust(b, 1, i);
    }
    for(i=0; i<n; i++){
        a[i] = b[i+1];
    }
}

void merge(s_record a[], s_record b[], int n1, int n2, int n3, int n4){
    int i, j, k, t;
    i = n1;
    j = n3;
    k = n1;

    while((i<=n2) && (j<=n4)){
        if(a[i].s_id <= a[j].s_id) b[k++] = a[i++];
        else b[k++] = a[j++];
    }

    if(i>n2){
        for(t=j; t<=n4; t++){
            b[t] = a[t];
        }
    }
    else{
        for(t=i; t<=n2; t++){
            b[k+t-i] = a[t];
        }
    }
}

void show_thelist(s_record a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i].s_id << " : " << a[i].name << " : " << a[i].score << endl;
    }
}
