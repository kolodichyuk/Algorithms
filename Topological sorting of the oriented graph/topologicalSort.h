using namespace std;

struct Graph {
    public:
	vector<vector<int>> vertexs; // graph
	vector<int> tSorted;         // topologically sorted graph
	Graph(const vector<vector<int>>& vertexs) {
		this->vertexs = vertexs;
	}
};

// class which implements topological sorting graph
class TopologicalSort {
    public:
	void Sort(Graph& graph) {
		const int vertexsCount = graph.vertexs.size(); // count vertexs in the graph
		vector<short> state(vertexsCount, 0); // state of the vertexs
		for (int i = 0; i < vertexsCount; i++) {
		    // if the vertex is not passed
		    if (state[i] == 0) {
			bool cyclic = dfs(graph, i, state);
			// if find a loop, then topological sorting is impossible
			if (cyclic) {
			    graph.tSorted.clear();
			    graph.tSorted.push_back(-1);
			    return;
		        }
		    }
	        }
	        reverse(graph.tSorted.begin(), graph.tSorted.end());
	}
    private:
	bool dfs(Graph &graph, short v, vector<short> &state) {
		state[v] = 1; // the vertex is being processed
		for (int i = 0; i < graph.vertexs[v].size(); i++) {
		    int dest = graph.vertexs[v].at(i);
			if (state[dest] == 0) {
			    if (dfs(graph, dest, state))
				return true;
			} else if (state[dest] == 1) 
				return true;
		}
		// if the loop is not found
		state[v] = 2;
		graph.tSorted.push_back(v + 1);
		return false;
	}
};
