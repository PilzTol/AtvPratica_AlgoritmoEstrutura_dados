#include "graph.h"
#include "heap.h"

#include <queue>

using namespace std;

// Cria array do tipo T com tamanho "size" e inicializa com valor "def"
template<class T>
T* array(int size, T def) {
	T *arr = new T[size];
	for (int i = 0; i < size; i++)
		arr[i] = def;
	return arr;
}

Graph::Graph(int nVert) {
	this->nVert = nVert;
	this->adj = new list<Edge> [nVert];
}

Graph::~Graph() {
	delete[] adj;
}

int Graph::size() {
	return nVert;
}

// Cria��o da aresta src --> dst
void Graph::edge(int src, int dst, int w) {
    if (src < 0 || src >= nVert || dst < 0 || dst >= nVert) {
        throw std::invalid_argument("Invalid vertex");
    }
    adj[src].push_back(Edge(src, dst, w));
}


int Graph::degree(int vtx) {
    if (vtx < 0 || vtx >= nVert) {
        throw std::invalid_argument("Invalid vertex");
    }
    return adj[vtx].size();
}


list<int> Graph::neighbors(int src) {
    if (src < 0 || src >= nVert) {
        throw std::invalid_argument("Invalid vertex");
    }
    list<int> result;
    for (Edge e : adj[src]) {
        result.push_back(e.dst);
    }
    return result;
}


int Graph::weight(int src, int dst) {
    if (src < 0 || src >= nVert || dst < 0 || dst >= nVert) {
        throw std::invalid_argument("Invalid vertex");
    }
    for (Edge e : adj[src]) {
        if (e.dst == dst) {
            return e.weight;
        }
    }
    return -1;
}


void Graph::print() {
	for (int i = 0; i < this->size(); i++) {
		int d = this->degree(i);

		cout << i << "(" << d << "): ";

		list<int> nei = this->neighbors(i);
		for (int dst : nei) {
			int w = this->weight(i, dst);
			cout << dst << "[" << w << "]; ";
		}

		cout << endl;
	}
}

bool Graph::isConnected() {
    int *group = new int[nVert];
    for (int i = 0; i < nVert; i++) {
        group[i] = i;
    }

    for (int i = 0; i < nVert; i++) {
        for (Edge e : adj[i]) {
            int srcGroup = group[e.src];
            int dstGroup = group[e.dst];
            if (srcGroup != dstGroup) {
                for (int j = 0; j < nVert; j++) {
                    if (group[j] == dstGroup) {
                        group[j] = srcGroup;
                    }
                }
            }
        }
    }

    int firstGroup = group[0];
    for (int i = 1; i < nVert; i++) {
        if (group[i] != firstGroup) {
            delete[] group;
            return false;
        }
    }

    delete[] group;
    return true;
}


// -------- PRAT 10 --------------//

// Busca em profundidade
list<int> Graph::dfs(int src) {
	list<int> result;
	int * visited = array(nVert, 0);

	DFS(src, visited, result);

	delete [] visited;
	return result;
}

// Busca em profundidade
void Graph::DFS(int src, int *visited, list<int> &result) {
    visited[src] = true;
    result.push_back(src);
    for (Edge e : adj[src]) {
        int v = e.dst;
        if (!visited[v]) {
            DFS(v, visited, result);
        }
    }
}

// Busca em largura
list<int> Graph::bfs(int src) {
	list<int> result;
	int * visited = array(nVert, 0);

	BFS(src, visited, result);

	delete [] visited;
	return result;
}

// Busca em largura
void Graph::BFS(int src, int *visited, list<int> &result) {
    queue<int> q;
    visited[src] = true;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);
        for (Edge e : adj[u]) {
            int v = e.dst;
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}


list<int> Graph::spf(int src, int dst) {
	int *dist = array(nVert, 99999);// array de dist�ncias acumuladas; 99999 = INF
	int *prev = array(nVert, -1);			// array de v�rtices anteriores
											//   cont�m menores caminhos
	dist[src] = 0;

	// Cria o heap (m�nimo) baseado na dist�ncia
	Heap<int> pq(nVert, dist);

	while (!(pq.empty())) {
		int node = pq.dequeue();	// pega n� com menor dist�ncia acumulada

		for (Edge e : adj[node]) {
			int v = e.dst;				// n� vizinho
			int w = e.weight;			// peso da aresta

			int D = dist[node] + w;			// nova dist�ncia

			if (D < dist[v]) {				// menor que antiga?
				prev[v] = node;				// atualize anterior
				dist[v] = D;				// atualize dist�ncia
				pq.decrease(v);				// atualize o heap (PQ)
			}
		}
	}

	list<int> result;						// menor caminho

	path(dst, prev, result);				// extrair caminho em result

	delete[] dist;
	delete[] prev;

	return result;
}

void Graph::path(int dst, int *prev, list<int> &result) {
    int current = dst;
    while (current != -1) {
        result.push_front(current);
        current = prev[current];
    }
}


