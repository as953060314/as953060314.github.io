// Problem#: 1073
// Submission#: 5229236
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
using namespace std;
int result=0;

void dfs(int i,int m,int sum,int num,int p[][2] );

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    while(n--){
        int m;
        cin>>m;
        int p[m][2];
        for(int i=0;i<m;i++){
            cin>>p[i][0];
            cin>>p[i][1];
        }
        dfs(0,m,0,p[0][0],p);
        cout<<result<<endl;
        result=0;
    }
}

void dfs(int i,int m,int sum,int num,int p[][2]){
    if(result!=0&&sum>result) return;
    if(i==m-1){
            sum+=p[i][1]*(num+10);
            result=(sum<result)||result==0?sum:result;
            return;
    }
    if(p[i][1]*10<=num*(p[i+1][1]-p[i][1])){
        int temp=sum+p[i][1]*(num+10);
        dfs(i+1,m,temp,p[i+1][0],p);
        return;
    }
    else {
        int temp=sum+p[i][1]*(num+10);
        dfs(i+1,m,temp,p[i+1][0],p);
        dfs(i+1,m,sum,p[i+1][0]+num,p);
    }

    return;
}
