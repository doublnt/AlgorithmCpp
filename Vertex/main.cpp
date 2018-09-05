#include <iostream>
#define maxSize 100
#define INF 99999
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

#pragma region �ڽӾ���Ķ���
typedef struct {
    int no;
    char info;
} VertexType;

typedef struct {
    int edges[maxSize][maxSize];//�ڽӾ�����
    int n, e; //���㡢��
    VertexType vex[maxSize];
} MGraph;
#pragma endregion

#pragma region �ڽӱ�
typedef struct ArcNode {
    int adjvex;
    struct ArcNode *nextarc;
    int info;
} ArcNode;

typedef struct {
    char data;// ������Ϣ
    ArcNode *firstarc;
} VNode;

typedef struct {
    VNode adjlist[maxSize];
    int n, e;
} AGraph;
#pragma endregion

int visit[maxSize];//��Ϊ����ķ��ʱ�ǣ���ʼʱ����Ԫ�ؾ�Ϊ 0

void Visit(int v) {
    cout << v << " " << endl;
}

/*
���ȴ�ĳ������v���������ʸö��㣬�����Ϊ�ѷ��ʹ� 
Ȼ��ѡȡ��v�ڽӵĸ���δ�����ʵ��ڽӵ� W��������֮�� 
��ѡȡ�� W �ڽӵ�δ�����ʵ����ⶥ�㲢����֮�� ����
�ظ����У���һ������������ڽӶ��㶼�����ʹ�ʱ���������˻ص���������ʹ��Ķ��� 
*/
void DFS(AGraph *G, int v) {
    ArcNode *p;
    visit[v] = 1;
    Visit(v); //���� v �Ĳ���
    p = G -> adjlist[v].firstarc;

    while(p != NULL) {
        if(visit[p -> adjvex] == 0)
            DFS(G, p -> adjvex);

        p = p -> nextarc;
    }
}

//DFS �Ա�����Ķ��������������
/*
void preorder(BTNode *p){
	if(p != NULL){
		visit(p);
		preorder(p -> lchild);
		preorder(p -> rchild)
	}
}
*/

/*�ɽ�϶������Ĳ�α���
������ȣ�
���ȷ�����ʼ���� v,Ȼ��ѡȡ�� v �ڽӵ�ȫ������ w1�� w2��������wn���з��ʣ�
�����η����� w1��w2�� ������wn�ڽӵ�ȫ�����㣨�Ѿ����ʹ��ĳ��⣩
*/

void BFS(AGraph *G, int v, int visit[maxSize]) { //visit array all  element initialize 0
    ArcNode *p;
    int que[maxSize], front = 0 , rear = 0; //���ж���ļ�д��
    int j;
    Visit(v);
    visit[v] = 1;
    rear = (rear + 1) % maxSize;// ��ǰ�ڵ� v ����
    que[rear] = v;

    while(front != rear) {
        front = (front + 1) % maxSize; //�������
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
�󲻴�Ȩ������ͨͼG�о��붥��v��Զ��һ������
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

#pragma region �ж�����ͼG�Ƿ���һ����

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

//�ж϶��� i �� j ��i!=j���Ƿ���·��
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

/*��С������Prim ,O(n^2) �����ڳ���ͼ
��ͼ������ȡ��һ�����㣬��������һ������Ȼ������������ӵı���ѡȡһ����̣�Ȩֵ��С��
�ıߣ����������߼��������ӵĶ���Ҳ����������У���ʱ�õ���һ�����������������Ȼ�����
�������ӵı���ѡȡһ����̵ıߣ����������߼����������㲢�뵱ǰ���У��õ�һ����3������
�������Դ����ƣ�֪�����ж��㶼����������Ϊֹ��
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
/*ÿ���ҳ���ѡ����Ȩֵ��С�ıߣ��ͽ��ñ߲����������У��ظ��˹���ֱ�����б߶��������Ϊֹ��
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

    /*������Ҷ�ӽڵ㵽���ڵ��˳������ջ*/
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



















