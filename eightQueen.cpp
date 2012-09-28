#include<iostream>
#include<fstream>
using namespace std;

int row[10]={0};
int col[10]={0};
int diag1[18]={0};
int diag2[18]={0};
int board[10][10]={0};
int i=0;

int eightQueen()
{
  if(i<9)
    {
      for(int j=0;j<9;j++)
	{
	  if(row[i]!=1 && col[j]!=1 && diag1[8+j-i]!=1 && diag2[i+j]!=1)
	    {
	      
	      board[i][j]=1;
	      row[i]=1; col[j]=1; diag1[8+j-i]=1; diag2[i+j]=1;
	      i++;
	      eightQueen();
	      i--;
	       board[i][j]=0;
	      row[i]=0; col[j]=0; diag1[8+j-i]=0; diag2[i+j]=0;

	      
	    }

	}
    }
  else
    {
      for(int k=0;k<9;k++)
       	{
	  std::cout << "\n";
	  for(int l=0;l<9;l++)
	    {
	      std::cout << board[k][l]<<"  ";
	    }
	  
	}
      cout<<"\n\n";
    }

}

int main()
{
  
  eightQueen();

}
