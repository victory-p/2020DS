#include <iostream>
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

void insertion_sort(s_record a[], int n){
    for(int i=1; i<n; i++){
        s_record temp = a[i];
        int j = i-1;

        while((j>=0) && (a[j].s_id > temp.s_id)){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

void bubble_sort(s_record a[], int n){
    s_record temp;

    for(int i=n-1; i>=1; i--){
        for(int j=0; j<i; j++){
            if(a[j].s_id > a[j+1].s_id){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void show_thelist(s_record a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i].s_id << " : " << a[i].name << " : " << a[i].score << endl;
    }
}

int main(){
    s_record s_list[12] = { {"21900013", "Kim ", 6.5}, {"21900136", "Lee ", 8.8 }, {"21900333", "Park", 9.2 }, { "21800442", "Choi", 7.1}, {"21900375", "Ryu ", 5.4  }, {"21700248", "Cho ", 6.3 }, { "21700302", "Jung", 8.3}, {"21800255", "Han ", 6.9  }, {"21800369", "Kang", 6.3 }, { "21900401", "Yang", 9.1}, {"21800123", "Moon", 8.1  }, {"21700678", "Seo ", 7.9 } };
    int n = 12;

    // insertion_sort(s_list, n);
    // bubble_sort(s_list, n);
    // selection_sort(s_list, n);     

    cout << "< The result of the sorting >" << endl;
    show_thelist(s_list, n);

    return 0;
}
