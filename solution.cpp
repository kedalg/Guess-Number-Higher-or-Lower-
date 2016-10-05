#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    int getMoneyAmount(int n) {
        if(n==1) return 0;
        if(n==2||n==3) return n-1;;
        int x=n-3,i,k,temp,p,tempa;
        vector<int> a,c;
        vector<vector<int> > b;
        while(x>0){
            a.insert(a.begin(),x);
            x-=4;
        }
        if(a[0]==1||a[0]==2) c.push_back(0);
        else c.push_back(a[0]-2);
        for(i=0;i<a.size();i++) c.push_back(a[i]+2);
        b.push_back(c);
        c.clear();
        for(i=a.size()-1;i>=0;i--){
            for(k=0;k<=i;k++){
                temp=INT_MAX;
                for(p=k;p<k+a.size()-i;p++){
                    tempa=b[p-k][k]>b[a.size()-1-i-p+k][p+1]?b[p-k][k]:b[a.size()-1-i-p+k][p+1];
                    if(tempa+a[p]<temp) temp=tempa+a[p];
                }
                c.push_back(temp);
            }
            b.push_back(c);
            c.clear();
        }
        return b.back().back();
    }
};
