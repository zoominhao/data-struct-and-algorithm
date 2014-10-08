#include "graph.h"
#include <string>

#include <map>

UndirectedGraphNode* GraphTest::cloneGraph( UndirectedGraphNode* node )
{
	if (node == NULL)
	{
		return NULL;
	}

	vector<UndirectedGraphNode*> nodes;
	map<UndirectedGraphNode*, UndirectedGraphNode*> map;

	//clone nodes
	nodes.push_back(node);
	map.insert(pair<UndirectedGraphNode*, UndirectedGraphNode*>(node, new UndirectedGraphNode(node->label)));

	size_t start = 0;
	while (start < nodes.size())
	{
		UndirectedGraphNode head = *nodes[start++];
		for (size_t i = 0; i < head.neighbors.size(); ++i)
		{
			UndirectedGraphNode* neighbour = head.neighbors[i];
			if(map.count(neighbour) == 0)
			{
				map.insert(pair<UndirectedGraphNode*, UndirectedGraphNode*>(neighbour, new UndirectedGraphNode(neighbour->label)));
				nodes.push_back(neighbour);
			}
		}
	}

	//clone neighbours
	for (size_t i = 0; i < nodes.size(); ++i)
	{
		UndirectedGraphNode* newNode = map[nodes[i]];
		for (size_t j = 0; j < nodes[i]->neighbors.size(); ++j)
		{
			newNode->neighbors.push_back(map[nodes[i]->neighbors[j]]);
		}
		
	}
	return map[node];
}

void GraphTest::testBFS( void )
{
	// 0->1->2
	//  ->3->4
	Graph myGraph;
	myGraph.addEdge(0,1,1);
	myGraph.addEdge(1,2,1);
	myGraph.addEdge(0,3,1);
	myGraph.addEdge(3,4,1);
	myGraph.bfs();
}

void GraphTest::testDFS( void )
{
	// 0->1->2
	//  ->3->4
	Graph myGraph;
	myGraph.addEdge(0,1,1);
	myGraph.addEdge(1,2,1);
	myGraph.addEdge(0,3,1);
	myGraph.addEdge(3,4,1);
	myGraph.dfs();
}

vector<vector<string>> GraphTest::partition( string s )
{
	vector<vector<string>> rst;
	vector<string> path;

	helper(s, path, 0, rst);
	return rst;
}

bool GraphTest::isPalindrome( string s )
{
	int start = 0;
	int end = s.length() - 1;
	while(start < end)
	{
		if(s.at(start) != s.at(end))
		{
			return false;
		}
        start++;
		end--;
	}

	return true;
}

void GraphTest::helper( string s, vector<string> path, int pos, vector<vector<string>> result )
{
	if(pos == s.length())
	{
		result.push_back(path);
		return;
	}

	for (int i = pos + 1; i <= s.length(); ++i)
	{
		string prefix = s.substr(pos, i);
		if(!isPalindrome(prefix))
		{
			continue;
		}
		path.push_back(prefix);
		helper(s, path, i, result);
		path.pop_back();
	}
}

int GraphTest::ladderLength( string start, string end, set<string> dict )
{
    if (dict.size() == 0)
    {
		return 0;
    }

	queue<string> que;
	que.push(start);
	dict.erase(start);
	int length = 1;

	while(!que.empty())
	{
		int count = que.size();
		for (int i = 0; i < count; ++i)
		{
			string current = que.front();
			que.pop();
			for (char c = 'a'; c <= 'z'; c++)
			{
				for (int j = 0; j < current.length(); j++)
				{
					if(c == current.at(j))
					{
						continue;
					}
					string tmp = current;
				    tmp[j] = c;
					if(tmp == end)
					{
						return length + 1;
					}
					if(dict.find(tmp) != dict.end())
					{
						que.push(tmp);
						dict.erase(tmp);
					}
				}
			}

		}
		length++;
	}
	return 0;
}

vector<vector<string>> GraphTest::findLadders( string start, string end, set<string> dict )
{
	vector<vector<string>>  result;
	return result;
}




vector<vector<string> > GraphTest::solveNQueens( int n )
{
	vector<vector<string>>  rst;
	if(n <= 0)
	{
		return rst;
	}
	vector<int> cols;
	search(n, cols, rst);
	return rst;
}

void GraphTest::search( int n, vector<int> cols, vector<vector<string>> result )
{
	if (cols.size() == n)
	{
		result.push_back(drawChessBoard(cols));
		return;
	}
	for (int col = 0; col < n; col++)
	{
		if(!isValid(cols, col))
		{
			 continue;
		}
		cols.push_back(col);
		search(n, cols, result);
		cols.pop_back();

	}
}

bool GraphTest::isValid( vector<int> cols, int col )
{
	int row = cols.size();
	for (int i = 0; i < row; ++i)
	{
		//same column
		if(cols[i] == col)
		{
			return false;
		}
		//left-top to right-bottom
		if (i - cols[i] == row - col)
		{
			return false;
		}
		// right-top to left-bottom
		if (i + cols[i] == row + col)
		{
			return false;
		}
	}
	return true;
}

vector<string> GraphTest::drawChessBoard( vector<int> cols )
{
	vector<string> chessboard(cols.size(), "");
	for(int i = 0; i < cols.size(); ++i)
	{
		for (int j = 0; j < cols.size(); ++j)
		{
			if(j == cols[i])
			{
				chessboard[i] += "Q";
			}
			else
			{
				chessboard[i] += ".";
			}
		}
	}
	return chessboard;
}

int GraphTest::totalNQueens( int n )
{
	int sum = 0;
	int* usedColumns = new int[n];
	placeQueen(usedColumns, n, 0, sum);
	return sum;
}

void GraphTest::placeQueen( int* usedColumns, int n, int row, int& sum)
{
	if(row == n)
	{
       sum++;
	   return;
	}

	for (int i = 0; i < n; i++)
	{
		if (isValid2(usedColumns, row, i))
		{
			usedColumns[row] = i;
			placeQueen(usedColumns, n, row + 1, sum);
		}
	}
}

bool GraphTest::isValid2( int* usedColums, int row, int col )
{
	for (int i = 0; i < row; ++i)
	{
		if(usedColums[i] == col)
		{
			return false;
		}
		if ((row - i) == abs(col - usedColums[i]))
		{
			return false;
		}
	}
	return true;
}

Graph::Graph(){
	for(int i = 0; i < VN; ++i){
		for(int j = 0; j < VN; ++j){
			edge[i][j] = INT_MAX;
		}
	}
	for(int i = 0; i < VN; ++i)
		inDegree[i] = 0;
}

void Graph::addEdge(int start, int end, int weight){
	edge[start][end] = weight;//if unordered, we should add symmetric edge
	inDegree[end]++;
}

void Graph::bfs()
{
	bool visited[VN] = {false};
	queue<int> myQueue;

	for(int i = 0; i < VN; ++i)
	{
		if(!visited[i])
		{
			myQueue.push(i);
			visited[i] = true;

			while(!myQueue.empty())
			{
				int cur = myQueue.front();
				cout<<cur <<" ";
				myQueue.pop();
				for(int j = 0; j < VN; ++j)
				{
					if(edge[cur][j] != INT_MAX && !visited[j])
					{
						myQueue.push(j);
						visited[j] = true;
					}
				}
			}
		}
	}
}
/*
void Graph::dfs(){
	bool visited[VN] = {false};

	stack<int> stk;
	for(int i = 0; i < VN; ++i){
		if(!visited[i]){
			stk.push(i);
			while(!stk.empty()){
				int c = stk.top();
				stk.pop();
				visited[c] = true;
				cout<<c <<" ";

				for(int j = 0; j < VN; ++j){
					if(edge[c][j] != INT_MAX && !visited[j]){
						stk.push(j);
					}
				}
			}
		}
	}
}*/

void Graph::dfs()
{
	bool visited[VN] = { false };
	stack<int> myStack;
	for(int i = 0; i < VN; ++i)
	{
		if(!visited[i])
		{
			myStack.push(i);
			visited[i] = true;

			while(!myStack.empty())
			{
				int cur = myStack.top();
				cout<<cur<<" ";
				myStack.pop();
				for(int j = 0; j < VN; ++j)
				{
					if(edge[cur][j] != INT_MAX && !visited[j])
					{
						myStack.push(j);
						visited[j] = true;
					}
				} 
			}
		}
	}
}