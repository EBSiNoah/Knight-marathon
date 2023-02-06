#include <vector>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

int knightMarathon(int width, int length, int istwo)
{
	int k=0;
	int m=0;
	int n=0;
	int restore=0;
	int maxnum=0;
	
	if(width>length)
	{
		m=width;
		n=length;
	}
	else
	{
		m=length;
		n=width;
	}
	
	if(m > 2*n - 1)
	{
		if(n == 1 && m == 2)
		{
			k=3;
		}
		else
		{
			maxnum=n-1;
			k = maxnum + 2*((m-(2*n - 1)) / 4) + ((m - (2*n - 1)) % 4);
		}
	}
	else
	{
		if(n == 3 && m == 3)
		{
			k=4;
		}
		else if(n == 2 && m == 2)
		{
			if(istwo == 1)
			{
				k=4;
			}
			else
			{
				k=2;
			}
		}
		else
		{
			restore = (m - (n/2 + 2 - n%2)) / 3;
			k = (n + (n/2 + 2 - n%2 + 3*restore) - 2) / 3 + (m - (n/2 + 2 - n%2)) % 3;
		}
	}
	return k;
}

vector<int> inputTri(vector<char> instr, vector<char> instr2, vector<char> instr3)
{
	int len=0;
	int count=0;
	int restoreF=0;
	int restoreB=0;
	int restoreF2=0;
	int restoreB2=0;
	int restoreF3=0;
	int restoreB3=0;
	int width=0;
	int length=0;
	vector<int> listri;
	vector<char>::iterator itr;
	
	len=instr.size();
	itr=instr.begin();
	while(count<len)
	{
		if(*(itr+count) == char(32))
		{
			break;
		}
		restoreF = static_cast<int>(*(itr+count) - 48) + restoreF*10;
		count++;
	}
	count++;
	while(count<len)
	{
		restoreB = static_cast<int>(*(itr+count) - 48) + restoreB*10;
		count++;
	}
	count=0;
	
	len=instr2.size();
	itr=instr2.begin();
	while(count<len)
	{
		if(*(itr+count) == char(32))
		{
			break;
		}
		restoreF2 = static_cast<int>(*(itr+count) - 48) + restoreF2*10;
		count++;
	}
	count++;
	while(count<len)
	{
		restoreB2 = static_cast<int>(*(itr+count) - 48) + restoreB2*10;
		count++;
	}
	count=0;
	
	len=instr3.size();
	itr=instr3.begin();
	while(count<len)
	{
		if(*(itr+count) == char(32))
		{
			break;
		}
		restoreF3 = static_cast<int>(*(itr+count) - 48) + restoreF3*10;
		count++;
	}
	count++;
	while(count<len)
	{
		restoreB3 = static_cast<int>(*(itr+count) - 48) + restoreB3*10;
		count++;
	}
	count=0;

	width=restoreF2 - restoreF;
	length=restoreB2 - restoreB;
	
	listri.push_back(abs(width) + 1);
	listri.push_back(abs(length) + 1);
	if((restoreF == 1 && restoreB == 1) && (restoreF2 == 0 && restoreB2 == 0))
	{
		listri.push_back(1);
	}
	else if((restoreF == 0 && restoreB == 0) && (restoreF2 == 1 && restoreB2 == 1))
	{
		listri.push_back(1);
	}
	else if((restoreF == 0 && restoreB == restoreB3-1) && (restoreF2 == 1 && restoreB2 == restoreB3-2))
	{
		listri.push_back(1);
	}
	else if((restoreF == 1 && restoreB == restoreB3-2) && (restoreF2 == 0 && restoreB2 == restoreB3-1))
	{
		listri.push_back(1);
	}
	else if((restoreF == restoreF3-1 && restoreB == 0) && (restoreF2 == restoreF3-2 && restoreB2 == 1))
	{
		listri.push_back(1);
	}
	else if((restoreF == restoreF3-2 && restoreB == 1) && (restoreF2 == restoreF3-1 && restoreB2 == 0))
	{
		listri.push_back(1);
	}
	else if((restoreF == restoreF3-1 && restoreB == restoreB3-1) && (restoreF2 == restoreF3-2 && restoreB2 == restoreB3-2))
	{
		listri.push_back(1);
	}
	else if((restoreF == restoreF3-2 && restoreB == restoreB3-2) && (restoreF2 == restoreF3-1 && restoreB2 == restoreB3-1))
	{
		listri.push_back(1);
	}
	else
	{
		listri.push_back(0);
	}
	return listri;
}

void kmsTest()
{
	vector<int> lenset;
	string first = "";
	string second = "";
	string third = "";

	getline(cin,first);
	getline(cin,second);
	getline(cin,third);
	
	vector<char> F(first.begin(),first.end());
	vector<char> S(second.begin(),second.end());
	vector<char> T(third.begin(),third.end());
	
	lenset = inputTri(S,T,F);
	cout<<knightMarathon(lenset[0], lenset[1], lenset[2]);
}

int main(void)
{
	kmsTest();
	return 0;
}
