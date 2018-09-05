#include <iostream>
#define maxSize 100
#define INF 99999
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

#pragma region 邻接矩阵的定义
typedef struct {
    int no;
    char info;
} VertexType;

typedef struct {
    int edges[maxSize][maxSize];//邻接矩阵定义
    int n, e; //顶点、边
    VertexType vex[maxSize];
} MGraph;
#pragma endregion

#pragma region 邻接表
typedef struct ArcNode {
    int adjvex;
    struct ArcNode *nextarc;
    int info;
} ArcNode;

typedef struct {
    char data;// 顶点信息
    ArcNode *firstarc;
} VNode;

typedef struct {
    VNode adjlist[maxSize];
    int n, e;
} AGraph;
#pragma endregion

int visit[maxSize];//作为顶点的访问标记，初始时所有元素均为 0

void Visit(int v) {
    cout << v << " " << endl;
}

/*
首先从某个顶点v出发，访问该顶点，并标记为已访问过 
然后选取与v邻接的各个未被访问的邻接点 W，并访问之。 
再选取与 W 邻接的未被访问的任意顶点并访问之， 依次
重复进行，当一个顶点的所有邻接顶点都被访问过时，则依次退回到最近被访问过的顶点 
*/
void DFS(AGraph *G, int v) {
    ArcNode *p;
    visit[v] = 1;
    Visit(v); //访问 v 的操作
    p = G -> adjlist[v].firstarc;

    while(p != NULL) {
        if(visit[p -> adjvex] == 0)
            DFS(G, p -> adjvex);

        p = p -> nextarc;
    }
}

//DFS 对比下面的二叉树的先序遍历
/*
void preorder(BTNode *p){
	if(p != NULL){
		visit(p);
		preorder(p -> lchild);
		preorder(p -> rchild)
	}
}
*/

/*可结合二叉树的层次遍历
广度优先：
首先访问起始顶点 v,然后选取与 v 邻接的全部顶点 w1， w2，。。。wn进行访问，
再依次访问与 w1，w2， 。。。wn邻接的全部顶点（已经访问过的除外）
*/

void BFS(AGraph *G, int v, int visit[maxSize]) { //visit array all  element initialize 0
    ArcNode *p;
    int que[maxSize], front = 0 , rear = 0; //队列定义的简单写法
    int j;
    Visit(v);
    visit[v] = 1;
    rear = (rear + 1) % maxSize;// 当前节点 v 进队
    que[rear] = v;

    while(front != rear) {
        front = (front + 1) % maxSize; //顶点出队
        j = que[front];
        p = G -> adjlist[j].firstarc;

        while(p != NULL) {
            if(visit[p -> adjvex] == 0) {
                Visit(p -> adjvex);
                visit[p -> adjvex] = 1;
                rear = (rear + 1) % maxSize;
                que[rear] = p -> adjvex;
            }

            p = p -> nextarc;
        }
    }
}

/*
求不带权无向连通图G中距离顶点v最远的一个顶点
*/
int BFS_2(AGraph *G, int v) {
    ArcNode *p;
    int que[maxSize], front = 0, rear = 0;
    int visit[maxSize];
    int i, j;

    for(i = 0; i < G->n; ++i) visit[i] = 0;

    rear = (rear + 1) % maxSize;
    que[rear] = v;
    visit[v] = 1;

    while(front != rear) {
        front = (front + 1) % maxSize;
        j = que[front];
        p = G -> adjlist[j].firstarc;

        while(p != NULL) {
            if(visit[p -> adjvex] == 0) {
                visit[p -> adjvex] = 1;
                rear = (rear + 1) % maxSize;
                que[rear] = p -> adjvex;
            }

            p = p->nextarc;
        }
    }

    return j;
}

#pragma region 判断无向图G是否是一棵树

void DFS_2(AGraph *G, int v, int &vn, int &en) {
    ArcNode *p;
    visit[v] = 1;
    ++vn;
    p = G -> adjlist[v].firstarc;

    while(p != NULL) {
        ++en;

        if(visit[p -> adjvex] == 0)
            DFS_2(G, p->adjvex, vn, en);

        p = p->nextarc;
    }
}

int GisTree(AGraph *G) {
    int vn = 0, en = 0, i;

    for(i = 0; i < G->n; ++i) {
        visit[i] = 0;
    }

    DFS_2(G, 1, vn, en);

    if(vn == G->n && (G->n - 1) == en / 2)
        return 1;
    else
        return 0;
}
#pragma endregion

//判断顶点 i 和 j （i!=j）是否有路径
int DFSTrave(AGraph *G, int i, int j) {
    int k;

    for(k = 0; k < G -> n; ++k) {
        visit[k] = 0;
    }

    DFS(G, i); //BFS(G,i)

    if(visit[j] == 1)
        return 1;
    else
        return 0;
}

/*最小生成树Prim ,O(n^2) 适用于稠密图
从图中任意取出一个顶点，把它当成一棵树，然后从与这棵树相接的边中选取一条最短（权值最小）
的边，并将这条边及其所连接的顶点也并入这棵树中，此时得到了一颗有两个顶点的树。然后从与
这棵树相接的边中选取一条最短的边，并将这条边及其所连顶点并入当前树中，得到一颗有3个顶点
的树。以此类推，知道所有顶点都被并入树中为止。
*/
void Prim(MGraph g, int v0, int &sum) {
    int lowcost[maxSize], vset[maxSize], v;
    int i, j, k, min;

    v = v0;

    for(i = 0; i < g.n; ++i) {
        lowcost[i] = g.edges[v0][i];
        vset[i] = 0;
    }

    vset[v0] = 1;
    sum = 0;

    for(i = 0; i < g.n - 1; ++i) {
        min = INF;

        for(j = 0; j < g.n; ++j) {
            if(vset[j] == 0 && lowcost[j] < min) {
                min = lowcost[j];
                k = j;
            }
        }

        vset[k] = 1;
        v = k;
        sum += min;

        for(j = 0; j < g.n; ++j) {
            if(vset[j] == 0 && g.edges[v][j] < lowcost[j]) {
                lowcost[j] = g.edges[v][j];
            }
        }
    }
}

#pragma region Kruskal
/*每次找出侯选边中权值最小的边，就将该边并入生成树中，重复此过程直到所有边都被检测完为止。
*/
typedef struct {
    int a, b;
    int w;
} Road;
Road road[maxSize];
int v[maxSize];

int getRoot(int a) {
    while(a != v[a])
        a = a[v];

    return a;
}

void Kruskal(MGraph g, int &sum, Road road[]) {
    int i;
    int N, E, a, b;
    N = g.n;
    E = g.e;
    sum = 0;

    for(i = 0; i < N; ++i)
        v[i] = i;

    //sort(road, E); comment for not implement
    for(i = 0; i < E; ++i) {
        a = getRoot(road[i].a);
        b = getRoot(road[i].b);

        if(a != b) {
            v[a] = b;
            sum += road[i].w;
        }
    }
}
#pragma endregion

#pragma region Dijkstra o(n^2)
void printPath(int path[], int a) {
    int stack[maxSize], top = -1;

    /*下面以叶子节点到根节点的顺序将其入栈*/
    while(path[a] != -1) {
        stack[++top] = a;
        a = path[a];
    }

    stack[++top] = a;

    while(top != -1)
        cout << stack[top--] << " ";

    cout << endl;
}

void Dijkstra(MGraph g, int v, int dist[], int path[]) {
    int set[maxSize];
    int min, i, j, u;

    for(i = 0; i < g.n; ++i) {
        dist[i] = g.edges[v][i];
        set[i] = 0;

        if(g.edges[v][i] < INF)
            path[i] = v;
        else
            path[i] = -1;
    }

    set[v] = 1;
    path[v] = -1;

    for(i = 0; i < g.n - 1; ++i) {
        min = INF;

        for(j = 0; j < g.n; ++j) {
            if(set[j] == 0 && dist[j] < min) {
                u = j;
                min = dist[j];
            }
        }

        set[u] = 1;

        for(j = 0; j < g.n; ++j) {
            if(set[j] == 0 && dist[u] + g.edges[u][j] < dist[j]) {
                dist[j] = dist[u] + g.edges[u][j];
                path[j] = u;
            }
        }
    }
}
#pragma endregion

#pragma region Floyd

void printPath(int u, int v, int path[][maxSize]){
	if(path[u][v] == -1)
	    cout << path[u][v] << endl;
	else{
		int mid = path[u][v];
		printPath(u, mid, path);
		printPath(mid, v, path);						
	} 
}

void Floyd(MGraph g, int Path[][maxSize]) {
    int i, j, k;
    int A[maxSize][maxSize];

    for(i = 0; i < g.n; ++i) {
        for(j = 0; j < g.n; ++j){
        	A[i][j] = g.edges[i][j];
        	Path[i][j] = -1;
        }
    }
    
    for(k = 0; k < g.n; ++k){
    	for(i = 0; i < g.n; ++i){
    		for(j = 0; j < g.n; ++j){
    			if(A[i][j] > A[i][k] + A[k][j]){
    				A[i][j] = A[i][k] + A[k][j];
    				Path[i][j] = k;
    			}
    		}
    	}
    }
}
#pragma endregion


int main(int argc, char *argv[]) {
    cout << "Hello, World!" << endl;
    return 0;
}



















