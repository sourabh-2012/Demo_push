#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int t,ct,d,ns,i,l,j,s,ans;
    string p;
    int a[32];
    cin>>t;
    for(ct=1;ct<=t;++ct){
        cin>>d>>p;
        ns=s=ans=0;
        j=1;
        l=p.length();
        for(i=0;i<l;++i){
            if(p[i]=='S'){
                ++ns;
                a[i]=j;
                s+=j;
            }
            else j<<=1;
        }
        cout<<"Case #"<<ct<<": ";
        if(ns>d){
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        i=l-1;
        while(s>d){
            while(p[i]!='C')--i;
            for(j=i+1;j<l;++j){
                if(p[j]=='S'){
                    ++ans;
                    s-=a[j];
                    a[j]>>=1;
                    s+=a[j];
                }
                if(s<=d)break;
            }
            --i;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
