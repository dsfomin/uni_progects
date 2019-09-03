#ifndef _GRAPH_H
#define _GRAPH_H

#include "List.h"
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

class Edge {
public:
	Edge() {
		a = 0;
		b = 0;
		len = 0;
	}
	Edge(int a, int b, int len) {
		this->a = a;
		this->b = b;
		this->len = len;
	}
	int a = 0;	 // вершина №1
	int b = 0;	 // вершина №2
	int len = 0; // "вес" ребра 
};

class Graph {
public:
	int CountOfVertices = 0; // к-во вершин
	int CountOfEdges = 0; // к-во ребер
	List<Edge> graph; // список ребер графа

	/*void SortGraphByWeightOfEdges();*/
	int GetCountOfEdges() { return CountOfEdges; }
	int GetCountOfVertices() { return CountOfVertices; }
	int GetLenghtOfEdge(int a, int b);
	void TwoVerticesInOne(int a, int b); // вершина с большим значением "входит" с меньшим

	void AddEdge(int a, int b, int len); // добавление 
	void DeleteEdge(int a, int b);
	List<Edge> MinWayDekster();
	bool CheckPlanarity() {}; // проверка планарности
	bool is_new(int _a);
	List<List<int>> bfs(int _fp);
	List<List<int>> dfs();
	List<int> FindNeighbours(int _a);
	/*List<int> PathOfDiametr();*/
	bool EdgeIsValid(int a, int b);
};

ostream& operator<<(ostream& stream, Graph& g) {
	stream << "Вершина №1 Вершина №2 Длина ребра" << endl;
	for (int i = 0; i < g.graph.GetSize(); i++) {
		stream << g.graph[i].a << setw(11) << g.graph[i].b << setw(11) << g.graph[i].len << endl;
	}
	return stream;
}

istream& operator>>(istream& stream, Graph& g) {
	int a, b, len;
	List<int> new_v;
	cout << "Set the count of edges: ";
	stream >> g.CountOfEdges;
	cout << endl;
	for (int i = 0; i < g.CountOfEdges; i++) {
		cout << "Write the vertices of " << i + 1 << " edge and the length of it: ";
		stream >> a >> b >> len;
		if (g.is_new(a))
			new_v.push_back(a);
		if (g.is_new(b))
			new_v.push_back(b);
		g.graph.push_back({ a, b, len });
		cout << endl;
	}
	g.CountOfVertices = new_v.GetSize();
	system("cls");
	return stream;
}

inline int Graph::GetLenghtOfEdge(int a, int b)
{
	bool valid = false;
	for (int i = 0; i < graph.GetSize(); i++) {
		if ((graph[i].a == a && graph[i].b == b) || (graph[i].a == b && graph[i].b == a)) {
			return graph[i].len;
		}
	}
	return valid;
}

bool Graph::EdgeIsValid(int a, int b) {
	for (int i = 0; i < graph.GetSize(); i++) {
		if ((graph[i].a == a && graph[i].b == b) || (graph[i].a == b && graph[i].b == a))
			return true;
	}
	return false;
}

inline void Graph::TwoVerticesInOne(int a, int b) // delete vertice which is bigger and connect its neighbours to another vertice
{
	int l = a > b ? b : a;
	int bg = a < b ? b : a;
	List<int> nl = FindNeighbours(l);
	List<int> nb = FindNeighbours(bg);
	for (int i = 0; i < nb.GetSize(); i++) {
		if (nb[i] == l)
			continue;
		else {
			if (!EdgeIsValid(l, nb[i]))
				AddEdge(l, nb[i], sqrt(GetLenghtOfEdge(nb[i], bg) + GetLenghtOfEdge(l, bg)));
		}
	}
	for (int i = 0; i < nb.GetSize(); i++) {
		DeleteEdge(nb[i], bg);
	}
}

inline void Graph::AddEdge(int a, int b, int len)
{
	if (is_new(a))
		CountOfVertices++;
	if (is_new(b))
		CountOfVertices++;
	graph.insert({ a, b, len }, graph.GetSize());
	CountOfEdges++;
}

inline void Graph::DeleteEdge(int a, int b)
{
	for (int i = 0; i < graph.GetSize(); i++) {
		if ((graph[i].a == a && graph[i].b == b) || (graph[i].a == b && graph[i].b == a))
			graph.removeAt(i);
	}
	if (is_new(a))
		CountOfVertices--;
	if (is_new(b))
		CountOfVertices--;
	CountOfEdges--;
}

bool Graph::is_new(int _a) {
	bool valid = true;
	for (int i = 0; i < graph.GetSize(); i++) {
		if (graph[i].a == _a || graph[i].b == _a)
			valid = false;
	}
	return valid;
}

List<int> Graph::FindNeighbours(int _a) {
	List<int> res;
	for (int i = 0; i < graph.GetSize(); i++) {
		if (graph[i].a == _a)
			res.push_back(graph[i].b);
		if (graph[i].b == _a)
			res.push_back(graph[i].a);
	}
	return res;
}

bool NotExist(List<int> l, int _a) {
	for (int i = 0; i < l.GetSize(); i++) {
		if (l[i] == _a)
			return false;
	}
	return true;
}

List<List<int>> Graph::bfs(int _fp) {
	List<List<int>> res;
	List<int> Neighbours = FindNeighbours(_fp), q, used, tmp_list;
	int it = 0, cs = 0;
	used.push_back(_fp);
	/*res[it].push_back(_fp);*/
	tmp_list.push_back(_fp);
	res.insert(tmp_list, it);
	for (int i = 0; i < Neighbours.GetSize(); i++) {
		q.push_back(Neighbours[i]);
		used.push_back(Neighbours[i]);
	}
	while (q.GetSize() > 0) {
		it++;
		tmp_list.clear();
		cs = q.GetSize();
		for (int i = 0; i < cs; i++) {
			int tmp = q[0];
			q.pop_front();
			Neighbours = FindNeighbours(tmp);
			for (int j = 0; j < Neighbours.GetSize(); j++) {
				if (NotExist(used, Neighbours[j])) {
					q.push_back(Neighbours[j]);
					used.push_back(Neighbours[j]);
				}
			}
			/*res[it].push_back(tmp);*/
			tmp_list.insert(tmp, tmp_list.GetSize());
		}
		res.insert(tmp_list, it);
	}
	return res;
}

//List<int> Graph::PathOfDiametr()
//{
//	int max;
//	for (int i =  1; i <= CountOfVertices; i++) {
//		List<List<int>> bfs_i = bfs(i);
//
//	}
//	
//}

#endif
