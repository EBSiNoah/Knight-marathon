#include <iostream>
#include <vector>
#include <string>

using namespace std;

int KnightMove01(string kingdom, string capital, string locate)
{
	vector<char> K(kingdom.begin(),kingdom.end());
	vector<char> C(capital.begin(),capital.end());
	vector<char> L(locate.begin(),locate.end());
	vector<char>::iterator itr;
	int X=0;
	int Y=0;
	bool convert=0;
	vector<int> Ep;
	vector<int> Sp;
	vector<int> Area;
	vector<int> CL;
	vector<int>::iterator numitr;
	int Xl=0;
	int Yl=0;
	int moves=0;
	int count=0;
	int restore=0;
	int loopnum=0;
	
	for(itr=K.begin();itr!=K.end();++itr)
	{
		if(*itr!=' '&&!convert)
		{
			X=X*10+((*itr)-48);
		}
		else if(*itr!=' '&&convert)
		{
			Y=Y*10+((*itr)-48);
		}
		else
		{
			convert=1;
			continue;
		}
	}
	Area.push_back(X);
	Area.push_back(Y);
	X=0;
	Y=0;
	convert=0;
	
	for(itr=C.begin();itr!=C.end();++itr)
	{
		if(*itr!=' '&&!convert)
		{
			X=X*10+((*itr)-48);
		}
		else if(*itr!=' '&&convert)
		{
			Y=Y*10+((*itr)-48);
		}
		else
		{
			convert=1;
			continue;
		}
	}
	Ep.push_back(X);
	Ep.push_back(Y);
	X=0;
	Y=0;
	convert=0;
	
	for(itr=L.begin();itr!=L.end();++itr)
	{
		if(*itr!=' '&&!convert)
		{
			X=X*10+((*itr)-48);
		}
		else if(*itr!=' '&&convert)
		{
			Y=Y*10+((*itr)-48);
		}
		else
		{
			convert=1;
			continue;
		}
	}
	Sp.push_back(X);
	Sp.push_back(Y);
	X=0;
	Y=0;
	convert=0;
	
	Xl=Sp[0]-Ep[0];
	Yl=Sp[1]-Ep[1];
	if(Xl<0)
	{
		Xl*=-1;
	}
	if(Yl<0)
	{
		Yl*=-1;
	}
	++Xl;
	++Yl;
	
	while(count<=Xl)
	{
		restore=count*Yl/Xl;
		if(count*Yl%Xl!=0)
		{
			restore++;
		}
		CL.push_back(restore);
		++count;
		++loopnum;		
	}
	
	while(Xl>2&&Yl>2)	
	{
//		cout<<"before "<<Xl<<" "<<Yl<<endl;
		if(CL[Xl-2]<Yl-1)
		{
			Yl-=2;
			Xl-=1;
		}
		else
		{
			Yl-=1;
			Xl-=2;
		}
		++moves;
//		cout<<"after "<<Xl<<" "<<Yl<<endl;
		++loopnum;
	}

//	cout<<Xl<<" "<<Yl<<endl;
	if(Xl+Yl-2==2)
	{
		moves+=2;
	}
	else if(Xl+Yl-2==1)
	{
		moves+=1;
	}
	else if(Xl+Yl-2>2)
	{
		if(Xl<=2)
		{
			while(Yl>2)
			{
//				cout<<"before "<<Xl<<" "<<Yl<<endl;
				if(Xl==1)
				{
					Yl-=2;
					Xl+=1;
				}
				else
				{
					Yl-=2;
					Xl-=1;
				}
				++moves;
//				cout<<"after "<<Xl<<" "<<Yl<<endl;
				++loopnum;
			}
		}
		else if(Yl<=2)
		{
			while(Xl>2)
			{
//				cout<<"before "<<Xl<<" "<<Yl<<endl;
				if(Yl==1)
				{
					Xl-=2;
					Yl+=1;
				}
				else
				{
					Xl-=2;
					Yl-=1;
				}
				++moves;
//				cout<<"after "<<Xl<<" "<<Yl<<endl;
				++loopnum;
			}
		}
		if(Xl+Yl-2==2)
		{
			moves+=2;
		}
		else if(Xl+Yl-2==1)
		{
			moves+=1;
		}
	}
	cout<<loopnum<<endl;
	return moves;
}

int KnightMove02(int kingdomX, int kingdomY, int capitalX, int capitalY, int locateX, int locateY)
{
	vector<int> Ep;
	vector<int> Sp;
	vector<int> Area;
	vector<int> CL;
	vector<int>::iterator numitr;
	int Xl=0;
	int Yl=0;
	int moves=0;
	int count=0;
	int restore=0;
	
	Area.push_back(kingdomX);
	Area.push_back(kingdomY);
	Ep.push_back(capitalX);
	Ep.push_back(capitalY);
	Sp.push_back(locateX);
	Sp.push_back(locateY);
	
	Xl=Sp[0]-Ep[0];
	Yl=Sp[1]-Ep[1];
	if(Xl<0)
	{
		Xl*=-1;
	}
	if(Yl<0)
	{
		Yl*=-1;
	}
	++Xl;
	++Yl;
	
	while(count<=Xl)
	{
		restore=count*Yl/Xl;
		if(count*Yl%Xl!=0)
		{
			restore++;
		}
		CL.push_back(restore);
		++count;		
	}
	
	while(Xl>2&&Yl>2)	
	{
//		cout<<"before "<<Xl<<" "<<Yl<<endl;
		if(CL[Xl-2]<Yl-1)
		{
			Yl-=2;
			Xl-=1;
		}
		else
		{
			Yl-=1;
			Xl-=2;
		}
		++moves;
//		cout<<"after "<<Xl<<" "<<Yl<<endl;
	}

//	cout<<Xl<<" "<<Yl<<endl;
	if(Xl+Yl-2==2)
	{
		moves+=2;
	}
	else if(Xl+Yl-2==1)
	{
		moves+=1;
	}
	else if(Xl+Yl-2>2)
	{
		if(Xl<=2)
		{
			while(Yl>2)
			{
//				cout<<"before "<<Xl<<" "<<Yl<<endl;
				if(Xl==1)
				{
					Yl-=2;
					Xl+=1;
				}
				else
				{
					Yl-=2;
					Xl-=1;
				}
				++moves;
//				cout<<"after "<<Xl<<" "<<Yl<<endl;
			}
		}
		else if(Yl<=2)
		{
			while(Xl>2)
			{
//				cout<<"before "<<Xl<<" "<<Yl<<endl;
				if(Yl==1)
				{
					Xl-=2;
					Yl+=1;
				}
				else
				{
					Xl-=2;
					Yl-=1;
				}
				++moves;
//				cout<<"after "<<Xl<<" "<<Yl<<endl;
			}
		}
		if(Xl+Yl-2==2)
		{
			moves+=2;
		}
		else if(Xl+Yl-2==1)
		{
			moves+=1;
		}
	}
	return moves;
}

int KnightMove03(string kingdom, string capital, string locate)
{
	vector<char> K(kingdom.begin(),kingdom.end());
	vector<char> C(capital.begin(),capital.end());
	vector<char> L(locate.begin(),locate.end());
	vector<char>::iterator itr;
	int X=0;
	int Y=0;
	bool convert=0;
	vector<int> Ep;
	vector<int> Sp;
	vector<int> Area;
	vector<int> CL;
	vector<int>::iterator numitr;
	int Xl=0;
	int Yl=0;
	int moves=0;
	int count=0;
	int restore=0;
	
	for(itr=K.begin();itr!=K.end();++itr)
	{
		if(*itr!=' '&&!convert)
		{
			X=X*10+((*itr)-48);
		}
		else if(*itr!=' '&&convert)
		{
			Y=Y*10+((*itr)-48);
		}
		else
		{
			convert=1;
			continue;
		}
	}
	Area.push_back(X);
	Area.push_back(Y);
	X=0;
	Y=0;
	convert=0;
	
	for(itr=C.begin();itr!=C.end();++itr)
	{
		if(*itr!=' '&&!convert)
		{
			X=X*10+((*itr)-48);
		}
		else if(*itr!=' '&&convert)
		{
			Y=Y*10+((*itr)-48);
		}
		else
		{
			convert=1;
			continue;
		}
	}
	Ep.push_back(X);
	Ep.push_back(Y);
	X=0;
	Y=0;
	convert=0;
	
	for(itr=L.begin();itr!=L.end();++itr)
	{
		if(*itr!=' '&&!convert)
		{
			X=X*10+((*itr)-48);
		}
		else if(*itr!=' '&&convert)
		{
			Y=Y*10+((*itr)-48);
		}
		else
		{
			convert=1;
			continue;
		}
	}
	Sp.push_back(X);
	Sp.push_back(Y);
	X=0;
	Y=0;
	convert=0;
	
	Xl=Sp[0]-Ep[0];
	Yl=Sp[1]-Ep[1];
	if(Xl<0)
	{
		Xl*=-1;
	}
	if(Yl<0)
	{
		Yl*=-1;
	}
	++Xl;
	++Yl;
	if(Xl>Yl)
	{
		restore=Xl;
		Xl=Yl;
		Yl=restore;
	}
	restore=Xl-Yl;
	if(restore!=0)
	{
		restore*=-1;
		if(2*Xl==Yl-1)
		{
			moves=Xl-1;
			return moves;
		}
		
		if(2*Xl<Yl-Xl-1)//exit
		{
			if(Xl-2>=0)
			{
				moves+=Xl-2;
				while(count<4)
				{
					if((Yl-2*(Xl-2)-count)%4==0)
					{
						break;
					}
					++count;
				}
				Yl=Yl-2*(Xl-2)-1;
				moves+=(Yl-(3+count))/2+count+1;
			}
			else
			{
				while(count<4)
				{
					if((Yl-count)%4==0)
					{
						break;
					}
					++count;
				}
				Yl--;
				moves+=(Yl-(3+count))/2+count+1;
			}			
		}
		else//y-x
		{
			moves+=(Yl-Xl);
			if((2*Xl-Yl-1)%3==0)
			{
				moves+=(2*Xl-Yl-1)/3*2;
			}
			else
			{
				moves+=(2*Xl-Yl-1)/3*2+2;
			}
		}
	}
	else
	{
		if((Xl-1)%3==0)
		{
			moves=(Xl-1)/3*2;
		}
		else
		{
			moves=(Xl-1)/3*2+2;
		}
	}
	return moves;
}

int KnightMove04(int kingdomX, int kingdomY, int capitalX, int capitalY, int locateX, int locateY)
{
	vector<int> Ep;
	vector<int> Sp;
	vector<int> Area;
	vector<int> CL;
	vector<int>::iterator numitr;
	int Xl=0;
	int Yl=0;
	int moves=0;
	int count=0;
	int restore=0;
	
	Area.push_back(kingdomX);
	Area.push_back(kingdomY);
	Ep.push_back(capitalX);
	Ep.push_back(capitalY);
	Sp.push_back(locateX);
	Sp.push_back(locateY);
	
	Xl=Sp[0]-Ep[0];
	Yl=Sp[1]-Ep[1];
	if(Xl<0)
	{
		Xl*=-1;
	}
	if(Yl<0)
	{
		Yl*=-1;
	}
	++Xl;
	++Yl;
	if(Xl>Yl)
	{
		restore=Xl;
		Xl=Yl;
		Yl=restore;
	}
	restore=Xl-Yl;
	if(restore!=0)
	{
		restore*=-1;
		if(2*Xl==Yl-1)
		{
			moves=Xl-1;
			return moves;
		}
		
		if(2*Xl<Yl-Xl-1)//exit
		{
			if(Xl-2>=0)
			{
				moves+=Xl-2;
				while(count<4)
				{
					if((Yl-2*(Xl-2)-count)%4==0)
					{
						break;
					}
					++count;
				}
				Yl=Yl-2*(Xl-2)-1;
				moves+=(Yl-(3+count))/2+count+1;
			}
			else
			{
				while(count<4)
				{
					if((Yl-count)%4==0)
					{
						break;
					}
					++count;
				}
				Yl--;
				moves+=(Yl-(3+count))/2+count+1;
			}			
		}
		else//y-x
		{
			moves+=(Yl-Xl);
			if((2*Xl-Yl-1)%3==0)
			{
				moves+=(2*Xl-Yl-1)/3*2;
			}
			else
			{
				moves+=(2*Xl-Yl-1)/3*2+2;
			}
		}
	}
	else
	{
		if((Xl-1)%3==0)
		{
			moves=(Xl-1)/3*2;
		}
		else
		{
			moves=(Xl-1)/3*2+2;
		}
	}
	return moves;
}

int KnightMove05(string kingdom, string capital, string locate)
{
	vector<char> K(kingdom.begin(),kingdom.end());
	vector<char> C(capital.begin(),capital.end());
	vector<char> L(locate.begin(),locate.end());
	vector<char>::iterator itr;
	int X=0;
	int Y=0;
	bool convert=0;
	vector<int> Ep;
	vector<int> Sp;
	vector<int> Area;
	vector<int> CL;
	vector<int>::iterator numitr;
	int Xl=0;
	int Yl=0;
	int moves=0;
	int count=0;
	int restore=0;
	int a=0;
	int b=0;
	
	for(itr=K.begin();itr!=K.end();++itr)
	{
		if(*itr!=' '&&!convert)
		{
			X=X*10+((*itr)-48);
		}
		else if(*itr!=' '&&convert)
		{
			Y=Y*10+((*itr)-48);
		}
		else
		{
			convert=1;
			continue;
		}
	}
	Area.push_back(X);
	Area.push_back(Y);
	X=0;
	Y=0;
	convert=0;
	
	for(itr=C.begin();itr!=C.end();++itr)
	{
		if(*itr!=' '&&!convert)
		{
			X=X*10+((*itr)-48);
		}
		else if(*itr!=' '&&convert)
		{
			Y=Y*10+((*itr)-48);
		}
		else
		{
			convert=1;
			continue;
		}
	}
	Ep.push_back(X);
	Ep.push_back(Y);
	X=0;
	Y=0;
	convert=0;
	
	for(itr=L.begin();itr!=L.end();++itr)
	{
		if(*itr!=' '&&!convert)
		{
			X=X*10+((*itr)-48);
		}
		else if(*itr!=' '&&convert)
		{
			Y=Y*10+((*itr)-48);
		}
		else
		{
			convert=1;
			continue;
		}
	}
	Sp.push_back(X);
	Sp.push_back(Y);
	X=0;
	Y=0;
	convert=0;
	
	Xl=Sp[0]-Ep[0];
	Yl=Sp[1]-Ep[1];
	if(Xl<0)
	{
		Xl*=-1;
	}
	if(Yl<0)
	{
		Yl*=-1;
	}
	++Xl;
	++Yl;
	
	a=Yl-Xl*0.5;
	b=Yl-Xl*2;
	restore=(2*a-2*b)/3;
	
	moves=Yl-restore-b;
	
	return moves;
}

int KnightMove06(string kingdom, string capital, string locate)//hybrid
{
	vector<char> K(kingdom.begin(),kingdom.end());
	vector<char> C(capital.begin(),capital.end());
	vector<char> L(locate.begin(),locate.end());
	vector<char>::iterator itr;
	int X=0;
	int Y=0;
	bool convert=0;
	vector<int> Ep;
	vector<int> Sp;
	vector<int> Area;
	vector<int> CL;
	vector<int>::iterator numitr;
	int Xl=0;
	int Yl=0;
	int moves=0;
	int count=0;
	int restore=0;
	int loopnum=0;
	
	for(itr=K.begin();itr!=K.end();++itr)
	{
		if(*itr!=' '&&!convert)
		{
			X=X*10+((*itr)-48);
		}
		else if(*itr!=' '&&convert)
		{
			Y=Y*10+((*itr)-48);
		}
		else
		{
			convert=1;
			continue;
		}
	}
	Area.push_back(X);
	Area.push_back(Y);
	X=0;
	Y=0;
	convert=0;
	
	for(itr=C.begin();itr!=C.end();++itr)
	{
		if(*itr!=' '&&!convert)
		{
			X=X*10+((*itr)-48);
		}
		else if(*itr!=' '&&convert)
		{
			Y=Y*10+((*itr)-48);
		}
		else
		{
			convert=1;
			continue;
		}
	}
	Ep.push_back(X);
	Ep.push_back(Y);
	X=0;
	Y=0;
	convert=0;
	
	for(itr=L.begin();itr!=L.end();++itr)
	{
		if(*itr!=' '&&!convert)
		{
			X=X*10+((*itr)-48);
		}
		else if(*itr!=' '&&convert)
		{
			Y=Y*10+((*itr)-48);
		}
		else
		{
			convert=1;
			continue;
		}
	}
	Sp.push_back(X);
	Sp.push_back(Y);
	X=0;
	Y=0;
	convert=0;
	
	Xl=Sp[0]-Ep[0];
	Yl=Sp[1]-Ep[1];
	if(Xl<0)
	{
		Xl*=-1;
	}
	if(Yl<0)
	{
		Yl*=-1;
	}
	++Xl;
	++Yl;
	if(Xl>Yl)
	{
		restore=Xl;
		Xl=Yl;
		Yl=restore;
	}
	
	while(count<=Xl)
	{
		restore=count*Yl/Xl;
		if(count*Yl%Xl!=0)
		{
			restore++;
		}
		CL.push_back(restore);
		++count;
		++loopnum;		
	}
	
	while(Xl>2&&Yl>2)	
	{
//		cout<<"before "<<Xl<<" "<<Yl<<endl;
		if(CL[Xl-2]<Yl-1)
		{
			Yl-=2;
			Xl-=1;
		}
		else
		{
			Yl-=1;
			Xl-=2;
		}
		++moves;
//		cout<<"after "<<Xl<<" "<<Yl<<endl;
		++loopnum;
	}

	if(Yl-Xl==2||Yl-Xl==0)
	{
		moves+=2;
	}
	else if(Yl-Xl==1)
	{
		moves+=1;
	}
	else if(Yl-Xl>2)
	{
		if(Xl==1)
		{
			if((Xl-3)%2==1)
			{
				moves+=(Xl-3)/2+1;
			}
			else
			{
				moves+=(Xl-3)/2;
			}
		}
		else if(Xl==2)
		{
			count=0;
			while(count<4)
			{
				if((Yl-count)%4==0)
				{
					break;
				}
				++count;
			}
			Yl--;
			moves+=(Yl-(3+count))/2+count+1;
		}
	}
//	cout<<Xl<<" "<<Yl<<endl;

	cout<<loopnum<<endl;
	return moves;
}

int KnightMove07(string kingdom, string capital, string locate)
{
	vector<char> K(kingdom.begin(),kingdom.end());
	vector<char> C(capital.begin(),capital.end());
	vector<char> L(locate.begin(),locate.end());
	vector<char>::iterator itr;
	int X=0;
	int Y=0;
	bool convert=0;
	vector<int> Ep;
	vector<int> Sp;
	vector<int> Area;
	vector<int>::iterator numitr;
	int Xl=0;
	int Yl=0;
	int moves=0;
	int count=0;
	int restore=0;
	int loopnum=0;
	int up=0;
	int down=0;
	int i=0;
	int j=0;
	int sum1=0;
	int sum2=0;
	int move[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
	
	for(itr=K.begin();itr!=K.end();++itr)
	{
		if(*itr!=' '&&!convert)
		{
			X=X*10+((*itr)-48);
		}
		else if(*itr!=' '&&convert)
		{
			Y=Y*10+((*itr)-48);
		}
		else
		{
			convert=1;
			continue;
		}
	}
	Area.push_back(X);
	Area.push_back(Y);
	X=0;
	Y=0;
	convert=0;
	
	for(itr=C.begin();itr!=C.end();++itr)
	{
		if(*itr!=' '&&!convert)
		{
			X=X*10+((*itr)-48);
		}
		else if(*itr!=' '&&convert)
		{
			Y=Y*10+((*itr)-48);
		}
		else
		{
			convert=1;
			continue;
		}
	}
	Ep.push_back(X);
	Ep.push_back(Y);
	X=0;
	Y=0;
	convert=0;
	
	for(itr=L.begin();itr!=L.end();++itr)
	{
		if(*itr!=' '&&!convert)
		{
			X=X*10+((*itr)-48);
		}
		else if(*itr!=' '&&convert)
		{
			Y=Y*10+((*itr)-48);
		}
		else
		{
			convert=1;
			continue;
		}
	}
	Sp.push_back(X);
	Sp.push_back(Y);
	X=0;
	Y=0;
	convert=0;
	
	Xl=Sp[0]-Ep[0];
	Yl=Sp[1]-Ep[1];
	if(Xl<0)
	{
		Xl*=-1;
	}
	if(Yl<0)
	{
		Yl*=-1;
	}
	++Xl;
	++Yl;
	int map[Xl][Yl]={0};
	
	while(count<Xl)
	{
		down=count*Yl/Xl-1;
		up=(count+1)*Yl/Xl+1;
		for(int col=0;col<down;++col)
		{
			map[count][col]=0;
			++loopnum;			
		}
		for(;down<up;++down)
		{
			map[count][down]=1;			
			++loopnum;
		}
		for(int col=up;col<Yl;++col)
		{
			map[count][col]=0;
			++loopnum;
		}
		++count;
	}
/*	
	for(int col=0;col<Yl;++col)
	{
		for(int row=Xl-1;row>=0;--row)
		{
			cout<<"|"<<map[row][col];
		}
		cout<<endl;
	}*/
	
	X=Xl;
	Y=Yl;
	
	while(map[0][0]!=0)
	{
		for(i=0;i<8&&restore==0;++i)
		{
			down=(X-move[i][0])*Yl/Xl-1;
			up=(X+1-move[i][0])*Yl/Xl+1;
			sum1=up-down;
			map[X-move[i][0]][Y-move[i][1]]=0;
			for(j=down;j<=up;++j)
			{
				sum2+=map[X-move[i][0]][j];
			}
			restore=sum1-sum2;
			cout<<"down : "<<down<<" up : "<<up<<" sum1 : "<<sum1<<" sum2 : "<<sum2<<" restore : "<<restore<<endl;
			sum2=0;
		}
		X-=move[i][0];
		Y-=move[i][1];
		for(int col=0;col<Yl;++col)
		{	
			for(int row=Xl-1;row>=0;--row)
			{
				cout<<"|"<<map[row][col];
			}
			cout<<endl;
		}
		restore=0;
		cout<<X<<Y<<"next"<<endl;
		++moves;
	}

	return moves;
}

int main(void)
{
	int answer=0;
//	answer=KnightMove01("9 9", "2 2", "7 8");
//	answer=KnightMove01("8 8", "0 0", "7 7");
//	cout<<answer<<endl;
//	answer=KnightMove01("1000 1000", "253 6789", "253 6789");
//	cout<<answer<<endl;
//	answer=KnightMove01("8 1000000000", "3 3", "3 999999999");
//	cout<<answer<<endl;
//	answer=KnightMove01("8 8", "0 0", "1 2");
//	cout<<answer<<endl;
//	answer=KnightMove01("8 8", "0 0", "1 4");
//	cout<<answer<<endl;
//	answer=KnightMove01("8 10", "0 0", "1 8");
//	cout<<answer<<endl;
//	answer=KnightMove01("10 10", "0 0", "8 1");
//	cout<<answer<<endl;
/*	int kingdomX=0;
	int kingdomY=0;
	int capitalX=0;
	int capitalY=0;
	int locateX=0;
	int locateY=0;*/
	string kingdom;
	string capital;
	string locate;
//	cin>>kingdomX>>kingdomY;
//	cin>>capitalX>>capitalY;
//	cin>>locateX>>locateY;
//	answer=KnightMove02(kingdomX, kingdomY, capitalX, capitalY, locateX, locateY);
//	cout<<"start"<<endl;
//	cin>>kingdom;
	getline(cin, kingdom);
//	cout<<"kingdom : "<<kingdom<<endl;
//	cin>>capital;
	getline(cin, capital);
//	cout<<"capital : "<<capital<<endl;
//	cin>>locate;
	getline(cin, locate);
//	cout<<"locate : "<<locate<<endl;
	
	answer=KnightMove07(kingdom, capital, locate);
	cout<<answer<<endl;
	
	return 0;
}
