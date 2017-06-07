#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> horseMoves;

bool isValidPath(vector<vector<int>> board, int x, int y)
{
	return x>=0 && x<board.size() && y>=0 && y<board.size() && !board[x][y];
}

vector<vector<int>> posibleMoves(vector<vector<int>> board, vector<int> pos)
{
	vector< vector<int>> newPositions;
	int newX, newY;
	for( vector<int> move: horseMoves)
	{
		newX=pos[0]+move[0];
		newY=pos[1]+move[1];
		if(isValidPath(board,newX,newY))
		{
			vector<int> newPos;
			newPos.push_back(newX);
			newPos.push_back(newY);
			newPositions.push_back(newPos);
		}
	}
	return newPositions;
}

vector<int> bestOption(vector<vector<int>> board, vector<vector<int>> candidates )
{
	vector<int> weights(candidates.size(),0);
	for(int i=0;i<candidates.size();i++)
	{
		weights[i]= posibleMoves(board,candidates[i]).size();
	}
	int minIndex=-1;
	int min=1e9;
	if (candidates.size()==1)
	{
		min=weights[0];
		minIndex=0;
		return candidates[minIndex];
	}
	for(int i=0;i<candidates.size();i++)
	{
		if(weights[i]<min and weights[i]!=0)
		{
			min=weights[i];
			minIndex=i;
		}
	}
	vector<int>a;
	if (minIndex!=-1)
	{
		return candidates[minIndex];
	}
	else return a;
}

int main()
{
	horseMoves={ {1,2} ,{2,1}, {-1,-2}, {-2,-1}, {-1,2}, {1,-2}, {-2,1}, {2,-1} };
	vector<vector<int>> board;
	int size=0;
	cout<<"Inserte el lado del tablero: ";
	cin>>size;
	for(int i=0;i<size;i++)
	{
		vector<int> row;
		for(int j=0;j<size;j++)
			row.push_back(0);
		board.push_back(row);
	}

	vector<int> pos(2,0);
	int step=1;
	vector<vector<int>> candidates;
	bool isOver=false;
	while(step-1!=(board.size()*board.size()) and !isOver)
	{
		board[pos[0]][pos[1]]=step;
		step++;
		candidates=posibleMoves(board,pos);
		if(bestOption(board,candidates).size())
		{
			pos=bestOption(board,candidates);
		}
		else isOver=true;
	}

	for(int i=0;i<board.size();i++)
	{
		for(int j=0;j<board.size();j++)
		{
			cout<<board[i][j]<<"\t";
		}
		cout<<"\n\n";
	}
}