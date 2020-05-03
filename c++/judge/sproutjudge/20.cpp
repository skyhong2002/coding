//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

#pragma GCC optimise("O2", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int MAXA = 99999, MAXN = 91092083;
	int cnt, act, tar, max, aloca, bloca, c;

	cin >> max >> cnt;

	int s[max];

	for(int i = 0; i < max; i++)
	{
		s[i] = i + 1;
	}

	for(int j = 0; j < cnt; j++){

		cin >> act >> tar;

		if (act == 0) 
		{	
			for(int i = 0; i < max; i++)
			{
				if(tar == s[i])
				{
					s[i] = 0;
					break;
				}
			}
			
		}
		else if (act == 1)
		{
			aloca = 0;
			bloca = 0;
			c = 0;
			for(int i = 0; i < max; i++)
			{
				if(tar == s[i])
				{
					aloca = i;
					break;
				}
			}

			if(aloca != 0)
			{
				for(int i = aloca - 1; i >= 0; i--)
				{
					if(s[i] != 0)
					{
						bloca = i;
						break;
					}
				}

				c = s[aloca];
				s[aloca] = s[bloca];
				s[bloca] = c;
			}

		}

	}

	for(int i = 0; i < max; i++)
	{
		if (s[i] != 0) cout << s[i];
		if (i == max - 1) 
		{
			cout << "\n";
			break;
		}
		if (s[i] != 0) cout << " ";
	}
	
    return 0;
}




/*

#pragma GCC optimise("O2", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int MAXA = 99999, MAXN = 91092083;
	int cnt, act, tar, max, aloca, bloca, c;

	cin >> max >> cnt;


	int s[max];

	for(int i = 0; i < max; i++)
	{
		s[i] = i + 1;
	}

	for(int j = 0; j < cnt; j++){

		cin >> act >> tar;

		if (act == 0) 
		{	
			for(int i = 0; i < max; i++)
			{
				if(tar == s[i])
				{
					s[i] = 0;
					break;
				}
			}
			
		}
		else if (act == 1)
		{
			aloca = 0;
			bloca = 0;
			c = 0;
			for(int i = 0; i < max; i++)
			{
				if(tar == s[i])
				{
					aloca = i;
					break;
				}
			}

			if(aloca != 0)
			{
				for(int i = aloca - 1; i >= 0; i--)
				{
					if(s[i] != 0)
					{
						bloca = i;
						break;
					}
				}

				c = s[aloca];
				s[aloca] = s[bloca];
				s[bloca] = c;
			}

		}

	}

	for(int i = 0; i < max; i++)
	{
		if (s[i] != 0) cout << s[i];
		if (i == max - 1) 
		{
			cout << "\n";
			break;
		}
		if (s[i] != 0) cout << " ";
	}
	
    return 0;
}



*/