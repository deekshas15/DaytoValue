#include<bits/stdc++.h>
using namespace std;
int day(int d, int m, int y)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return ( y + y / 4 - y / 100 +y / 400 + t[m - 1] + d -1) % 7;
}

int main(){
    map<string,int> mp;
    int n;
    string arr[7]={"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    cout<<"No of Values: \n";
    cin>>n;
    while(n--){
        string s="0000-00-00";
        int t;
        cin>>s>>t;
        mp[arr[ day(atoi(s.substr(8,2).c_str()), atoi(s.substr(5,2).c_str()), atoi(s.substr(0,4).c_str())) ] ] += t;
    }
    int count=0, start_val=0, end_val=0, index;
    bool empty=false;
    for(int i=0;i<7;i++)
    {
        if(mp[arr[i]]!=0 && empty==false) start_val=mp[arr[i]];
        else if(mp[arr[i]]==0){
            if(empty==false){
                empty=true;
                index=i;
            }
            count++;
        }
        else{
            end_val=mp[arr[i]];
            int avg=(start_val+end_val)/2;
            int cd=avg/(count+2);
            for(int j=index;j<i;j++) mp[arr[j]]=mp[arr[j-1]]+cd;
            count=0;
            empty=false;
        }
    }
     for(int i=0;i<7;i++)
        cout<<arr[i]<<" "<<mp[arr[i]]<<endl;
    
    return 0;
}

