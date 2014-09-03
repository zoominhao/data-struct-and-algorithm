#pragma once
#include <iostream>
#include <vector>

#include <queue>
#include <stack>

using namespace std;

struct UndirectedGraphNode
{
	int label;
	vector<UndirectedGraphNode*> neighbors;
	UndirectedGraphNode(int x) { label = x;}
};  


const int VN = 5;

class Graph{
public:
	Graph();
	void addEdge(int start, int end, int weight);
	void bfs();
	void dfs();
	void topoSort();
public:
	int edge[VN][VN];
	int inDegree[VN];
};




class GraphTest
{
public:
	// Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors. 
	// OJ's undirected graph serialization: Nodes are labeled uniquely. We use # as a separator for each node, 
	// and , as a separator for node label and each neighbor of the node.
	// As an example, consider the serialized graph {0,1,2#1,2#2,2}. 
	// The graph has a total of three nodes, and therefore contains three parts as separated by #.
	// First node is labeled as 0. Connect node 0 to both nodes 1 and 2. Second node is labeled as 1. Connect node 1 to node 2. 
	// Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle. 
	// Visually, the graph looks like the following: 1 / \ / \ 0 --- 2 / \ \_/ 
	UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node);

	void testBFS( void );
	void testDFS( void );

};