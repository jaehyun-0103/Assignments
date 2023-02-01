#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_VERTICES 50

typedef struct {
    int top;
    int stack[MAX_STACK_SIZE];
}stack_type;
typedef stack_type* stack_type_ptr;

typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
    int n;
    GraphNode* adj_list[MAX_VERTICES];
}GraphType;

void init(stack_type_ptr s) {
    s->top = -1;
}

int is_Empty(stack_type s) {
    return (s.top == -1);
}

int is_Full(stack_type s) {
    return (s.top == MAX_STACK_SIZE - 1);
}

int pop(stack_type_ptr s) {
    if (is_Empty(*s)) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else
        return s->stack[s->top--];
}

void push(stack_type_ptr s, int item) {
    if (is_Full(*s)) {
        fprintf(stderr, "���� ��ȭ ����\n");
        return;
    }
    else
        s->stack[++s->top] = item;
}

void graph_init(GraphType* g) {
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTICES; v++)
        g->adj_list[v] = NULL;
}

void insert_vertex(GraphType* g, int v) {
    if ((g->n) + 1 > MAX_VERTICES) {
        fprintf(stderr, "�׷���: ������ ���� �ʰ�");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int u, int v) {
    GraphNode* node;
    if (u >= g->n || v >= g->n) {
        fprintf(stderr, "���� ��ȣ ����");
        return;
    }
    if (g->adj_list[u] == NULL) {
        node = (GraphNode*)malloc(sizeof(GraphNode));
        node->vertex = v;
        node->link = g->adj_list[u];
        g->adj_list[u] = node;
    }
    else {
        node = g->adj_list[u];
        while (node->link != NULL)
            node = node->link;
        node->link = (GraphNode*)malloc(sizeof(GraphNode));
        node->link->vertex = v;
        node->link->link = NULL;
    }
}

// ��������
int topo_sort(GraphType* g) {
    int i;
    int num = 0;
    stack_type s;
    GraphNode* node;
    int* in_degree = (int*)malloc(g->n * sizeof(int));
    
    init(&s);  
    
    for (i = 0; i < g->n; i++)
        in_degree[i] = 0;
    for (i = 0; i < g->n; i++) {
        node = g->adj_list[i];
        while (node != NULL) {
            in_degree[node->vertex]++;
            node = node->link;
        }
    }
    
    for (i = 0; i < g->n; i++) {
        if (in_degree[i] == 0) {
            push(&s, i);
        }
    }

    while (!is_Empty(s)) {
        int w;
        w = pop(&s);
        printf("���� %d -> ", w);
        node = g->adj_list[w];
        while (node != NULL) {
            in_degree[node->vertex]--;
            if (in_degree[node->vertex] == 0)
                push(&s, node->vertex);
            node = node->link;
        }
        num++;
    }
    free(in_degree);

    if (num == g->n)
        printf("end\n");
    return (num == g->n);
}
int main(void) {
    GraphType g;
    graph_init(&g);
    insert_vertex(&g, 0);
    insert_vertex(&g, 1);
    insert_vertex(&g, 2);
    insert_vertex(&g, 3);
    insert_vertex(&g, 4);
    insert_vertex(&g, 5);
    
    insert_edge(&g, 0, 2); // ���� 0�� ���� ����Ʈ ����
    insert_edge(&g, 0, 3); // ���� 0�� ���� ����Ʈ ����
    insert_edge(&g, 1, 3); // ���� 1�� ���� ����Ʈ ����
    insert_edge(&g, 1, 4); // ���� 1�� ���� ����Ʈ ����
    insert_edge(&g, 2, 3); // ���� 2�� ���� ����Ʈ ����
    insert_edge(&g, 2, 5); // ���� 2�� ���� ����Ʈ ����
    insert_edge(&g, 3, 5); // ���� 3�� ���� ����Ʈ ����
    insert_edge(&g, 4, 5); // ���� 4�� ���� ����Ʈ ����

    topo_sort(&g);
}