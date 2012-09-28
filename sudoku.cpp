//########### Aniket Pansare #############//

#include<iostream>
#include<fstream>
using namespace std;
int Inputmat[][9]={7,0,6,3,0,0,5,0,8,
	      0,5,0,0,8,7,0,1,0,
	      8,0,0,4,0,2,0,6,7,
	      0,0,0,0,0,0,6,9,2,
	      0,0,7,0,0,0,8,0,0,
	      3,6,5,0,0,0,0,0,0,
	      4,3,0,7,0,9,0,0,6,
	      0,2,0,8,3,0,0,4,0,
		   5,0,9,0,0,4,1,0,3};

int sudomat[9][9]={0};
int sblock[9][10]={0};
int srow[9][10]={0};
int scol[9][10]={0};

int row=0,col=0,num=1,flag=0;

int checkblock(int r,int c)
{
  if(r<3 && c<3)
    {return 0;}
  if(r<3 && c>=3 && c<6)
    {return 1;}
  if(r<3 && c>=6 && c<9)
    {return 2;}
  if(r>=3 && r<6 && c<3)
    {return 3;}
 if(r>=3 && r<6 && c>=3 && c<6)
    {return 4;}
  if(r>=3 && r<6 && c>=6 && c<9)
    {return 5;}
  if(r>=6 && r<9 && c<3)
    {return 6;}
 if(r>=6 && r<9 && c>=3 && c<6)
    {return 7;}
  if(r>=6 && r<9 && c>=6 && c<9)
    {return 8;}
}


int sudoku()
{
  if(row<9 && row>=0 && flag==0)
    {
      if(sudomat[row][col]!=0)
	{
	   col++;
	      if(col>=9)
		{
		  col=0;
		  row++;
		}
	      sudoku();
	       if(col==0)
		{
		  col=9;
		  row--;
		}
	      col--;
	      
	}
      for(int num=1;num<=9;num++)
	{
	  if(srow[row][num]==0 && scol[col][num]==0 && sblock[checkblock(row,col)][num]==0 && num<10)
	    {
	      sudomat[row][col]=num;
	      srow[row][num]=1; scol[col][num]=1; sblock[checkblock(row,col)][num]=1;
	    
	      col++;
	      if(col>=9)
		{
		  col=0;
		  row++;
		}
	       sudoku();
	      if(col==0)
		{
		  col=9;
		  row--;
		}
	      col--;
	      srow[row][num]=0; scol[col][num]=0; sblock[checkblock(row,col)][num]=0;
	      sudomat[row][col]=0;
      
	    }
	}
    }
  else
    {
      if(flag==0)
	{
      for(int i=0;i<9;i++,cout<<"\n")
	for(int j=0;j<9;j++)
	  cout << sudomat[i][j] << "  ";
	}
      flag=1;
	}
}



int main()
{
  for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
  sudomat[i][j]=Inputmat[i][j];
 

 sudoku();
}
