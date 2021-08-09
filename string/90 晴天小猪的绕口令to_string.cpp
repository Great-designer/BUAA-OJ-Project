#include<iostream>

using namespace std;

int main()
{
    int t;
    int n;
    cin >> t;
    string a;
    string ans;
    while(t--)
	{
        cin >> n >> a;
        ans="";
        int count=1;
		char cur=0;
		int i; 
        for(i=0;i<n;++i)
		{
            if(a[i]!=cur)
			{
                if(cur)
				{
					ans+=to_string(count)+cur;
				}
                count=1;
				cur=a[i];
            }
            else
			{
				count++;
			}
        }
        if(cur)
		{
			ans+=to_string(count)+cur;
		}
        cout << ans << endl;
    }
    return 0;
}
