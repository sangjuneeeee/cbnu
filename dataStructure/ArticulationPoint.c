#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

void addEdge(Node** graph, int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = graph[u];
    graph[u] = newNode;
}

void dfs(Node** graph, int* visited, int* artP, int* findV, int* lowV, int v, int parent, int* time) {

    visited[v] = 1;
    findV[v] = lowV[v] = ++(*time);
    int children = 0;
    Node* curr = graph[v];

    while (curr != NULL) {
        int nextV = curr->vertex;
        if (!visited[nextV]) {
            children++;
            dfs(graph, visited, artP, findV, lowV, nextV, v, time);
            lowV[v] = (lowV[v] < lowV[nextV]) ? lowV[v] : lowV[nextV];
            if (parent != -1 && lowV[nextV] >= findV[v]) {
                artP[v] = 1;
            }
        } else if (nextV != parent) {
            lowV[v] = (lowV[v] < findV[nextV]) ? lowV[v] : findV[nextV];
        }
        curr = curr->next;
    }
    if (parent == -1 && children > 1) {
        artP[v] = 1;
    }
}

void getAP() {
    FILE* inputFile = fopen("AP.txt", "r");
    int u, v;
    char cut;
    int numV = 0;

    while (fscanf(inputFile, "(%d,%d)%c", &u, &v, &cut) != EOF) {
        numV = (u > numV) ? u : numV;
        numV = (v > numV) ? v : numV;
    }
    numV++;

    Node** graph = (Node**)malloc(numV * sizeof(Node*));
    int* visited = (int*)malloc(numV * sizeof(int));
    int* artP = (int*)malloc(numV * sizeof(int));
    int* findV = (int*)malloc(numV * sizeof(int));
    int* lowV = (int*)malloc(numV * sizeof(int));

    for (int i = 0; i < numV; i++) {
        graph[i] = NULL;
        visited[i] = 0;
        artP[i] = 0;
        findV[i] = 0;
        lowV[i] = 0;
    }

    fseek(inputFile, 0, SEEK_SET);

    while (fscanf(inputFile, "(%d,%d)%c", &u, &v, &cut) != EOF) {
        addEdge(graph, u, v);
        addEdge(graph, v, u);
    }

    int time = 0;

    for (int i = 0; i < numV; i++) {
        if (!visited[i]) {
            dfs(graph, visited, artP, findV, lowV, i, -1, &time);
        }
    }
//FIXME: printf 주석 해제 후 실행 결과 확인
    // printf("AP: ");
    for (int i = 0; i < numV; i++) {
        if (artP[i]) {
            // printf("%d ", i);
        }
    }
    // printf("\n");

    fclose(inputFile);

    for (int i = 0; i < numV; i++) {
        Node* curr = graph[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(graph);
    free(visited);
    free(artP);
    free(findV);
    free(lowV);
}

int main() {
    getAP();
    return 0;
}