#include <iostream>
using namespace std;


const int MAX_E = 100;
const int MAX_V = 100;
const int INF = 1000;


int numOfVertex, numOfEdge;
int capacity[MAX_E], onEnd[MAX_E], nextEdge[MAX_E], edgeCount;
int firstEdge[MAX_V], visited[MAX_V];


int min(int a, int b) {
    if (a <= b) {
        return a;
    }
    else {
        return b;
    }
}

void addEdge(int u, int v) {
    // Прямое ребро
    onEnd[edgeCount] = v;                   // на конце прямого v
    nextEdge[edgeCount] = firstEdge[u];     // добавляем в начало списка для u
    firstEdge[u] = edgeCount;               // теперь начало списка - новое ребро
    capacity[edgeCount++] = 1;            // устанавливаем пропускную способность
    // Обратное ребро
    onEnd[edgeCount] = u;                   // на конце обратного u
    nextEdge[edgeCount] = firstEdge[v];     // добавляем в начало списка для v
    firstEdge[v] = edgeCount;               // теперь начало списка - новое ребро
    capacity[edgeCount++] = 1;          // устанавливаем пропускную способность
}

int findFlow(int u, int flow, int destinationVertex) {
    if (u == destinationVertex) return flow; // возвращяем полученный минимум на пути
    visited[u] = true;
    for (int edge = firstEdge[u]; edge != -1; edge = nextEdge[edge]) {
        int to = onEnd[edge];
        if (!visited[to] && capacity[edge] > 0) {
            int minResult = findFlow(to, min(flow, capacity[edge]), destinationVertex); // ищем поток в поддереве
            if (minResult > 0) {                    // если нашл
                capacity[edge] -= minResult;   // у прямых ребер вычетаем поток
                capacity[edge ^ 1] += minResult;   // к обратным прибавляем
                return minResult;
            }
        }
    }
    return 0; // если не нашли поток из этой вершины вернем 0
}

int searchMaxFlow(int sourceVertex, int destinationVertex) {

    fill(visited, visited + MAX_V, false);


    int maxFlow = 0;
    int iterationResult = 0;
    while ((iterationResult = findFlow(sourceVertex, INF, destinationVertex)) > 0) {
        fill(visited, visited + MAX_V, false);
        maxFlow += iterationResult;
    }
    // Выводим максимальный поток
    cout << maxFlow << endl;
    return maxFlow;
}

int main() {
    fill(firstEdge, firstEdge + MAX_V, -1);     // -1 означает ребра нет
    cin >> numOfVertex >> numOfEdge;            // считываем количество вершин и ребер
   /* int sourceVertex, destinationVertex;*/

    for (int i = 0, u, v; i < numOfEdge; i++) {
        cin >> u >> v;
        addEdge(u, v);
    }
    int capacity2[MAX_E];
    memcpy(capacity2, capacity, sizeof(capacity2));


    // Нахождение максимального потока
    int ans = INF;
    for (int s = 0; s < numOfVertex; ++s){
        for (int t = s + 1; t < numOfVertex; ++t) {
            std::cout << s << "  " << t << "     ";
            int flow = searchMaxFlow(s, t);
            ans = min(ans, flow);
            memcpy(capacity, capacity2, sizeof(capacity2));
        }
    }
    std::cout << "\n Result: " << ans << "\n";
    return 0;
}