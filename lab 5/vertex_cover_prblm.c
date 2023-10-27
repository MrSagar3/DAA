//  WAP to implement vertex cover problem

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure to represent an undirected graph
typedef struct Graph {
    int V; // Number of vertices
    Node** adjList; // Adjacency list
} Graph;

// Function to create a new graph with V vertices
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjList = (Node**)malloc(V * sizeof(Node*));
    int i;
    for (i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to find the vertex cover using a greedy algorithm
void findVertexCover(Graph* graph) {
    int V = graph->V;
    int visited[V];
    int i,u;
    for (i = 0; i < V; i++) {
        visited[i] = 0;
    }

    for (u = 0; u < V; u++) {
        if (!visited[u]) {
            Node* adjNode = graph->adjList[u];
            while (adjNode != NULL) {
                int v = adjNode->data;
                if (!visited[v]) {
                    visited[u] = 1;
                    visited[v] = 1;
                    break;
                }
                adjNode = adjNode->next;
            }
        }
    }

    printf("Vertex Cover: ");
    for (i = 0; i < V; i++) {
        if (visited[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int V = 7; // Number of vertices in the graph
    printf("Output of Vertex Cover Problem\n");
    Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 6);

    findVertexCover(graph);

    return 0;
}

