#include <bits/stdc++.h>
using namespace std;

void swap(int x,vector <int> &a, vector <int> &b)
{
    int temp = a[x];
    a[x] = b[x];
    b[x] = temp;
}

void rotate(vector <int> &a, vector <int> &b )
{
    int temp1 = a[0],temp2 = b[0];
    a.erase(a.begin());
    b.erase(b.begin());
    a.push_back(temp1);
    b.push_back(temp2);
}


int main() {
	int n;
	cin>>n;
	vector <int> uh(n),lh(n);
	
	for(int i = 0 ; i < n ; i++)
	{
	    cin>>uh[i]>>lh[i];
	}
	
	int cursecs = 0, minsecs = -1;
	int sum1 = accumulate(uh.begin(),uh.end(),0);
	int sum2 = accumulate(lh.begin(),lh.end(),0);
	
    if(sum1%2 == 0 && sum2%2 == 0)
    {
    	    cout<<"0";
    	    return 0;
    }
    else if(n==1)
    {
    	    if(uh[0]%2==0 && lh[0]%2==0)
    	    {    cout<<"0";return 0; }
    	    else
    	    {    cout<<"-1";return 0;}
    }
    else
    {       
	
    	for(int j = 0; j < n ; j++)
    	{   int secs = 0;
    	    vector <int> local_uh=uh;
    	    vector <int> local_lh=lh;
    	    for(int i = 0; i<n ; i++)
        	{
        	   swap(i,local_uh,local_lh);
        	   secs++;
        	   if(accumulate(local_uh.begin(),local_uh.end(),0)%2 == 0 && accumulate(local_lh.begin(),local_lh.end(),0)%2 ==0 )
        	       break;
            }
        	if(accumulate(local_uh.begin(),local_uh.end(),0)%2 == 0 && accumulate(local_lh.begin(),local_lh.end(),0)%2 ==0)
        	   cursecs = secs;
        	else
        	{   cout<<"-1";
        	    return 0;
        	}
    	    if(minsecs > cursecs || minsecs == -1)
    	        minsecs = cursecs;
    	    rotate(uh,lh);
    	}
    	cout<<minsecs;
    }
	
	
	return 0;
}
