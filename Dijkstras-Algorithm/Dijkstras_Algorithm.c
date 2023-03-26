// C program for Dijkstra's single source shortest path algorithm. 
//The program is for adjacency matrix representation of the graph
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 9

int minDistance(int dist[], bool visited[]) {
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (visited[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void printSolution(int output[]) {
	printf("Vertex \t\t\tDistance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t\t\t %d\n", i, output[i]);
}

void dijkstra(int graph[V][V], int src) {
	int output[V]; 
	bool visited[V]; 

	// Initialize all distances as INFINITY and visited[] as false
	for (int i = 0; i < V; i++)
		output[i] = INT_MAX, visited[i] = false;

	// Distance of source vertex from itself is always 0
	output[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Picking the minimum distance possible from the source to the destination.
		int u = minDistance(output, visited);

		// Mark the picked vertex as it is visited
		visited[u] = true;

		// Update distance value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < V; v++) {
			if (!visited[v] && graph[u][v] && output[u] != INT_MAX && output[u] + graph[u][v] < output[v]) {
				output[v] = output[u] + graph[u][v];
            }
        }
	}
	printSolution(output);
}

int main() {
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
	dijkstra(graph, 0);
	return 0;
}
