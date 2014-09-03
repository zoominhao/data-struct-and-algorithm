#include "graph.h"

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
		UndirectedGraphNode head = *nodes[start];
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