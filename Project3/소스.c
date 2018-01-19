#include <stdio.h>

#define N 9

void DFS();
void Push(int a[], int *top, int i);
int Pop(int a[], int *top);
void BFS();
int Enqueue(int a[], int *f, int r);
void Dequeue(int a[], int f, int *r, int i);

int check[N] = { 0 };
int Grape[N][N] = { { 0,1,1,1,0,0,0,0,0 },
{ 1,0,0,0,1,0,0,0,0 },
{ 1,0,0,0,0,1,0,0,0 },
{ 1,0,0,0,0,0,0,1,0 },
{ 0,1,0,0,0,1,1,0,0 },
{ 0,0,1,0,1,0,0,1,0 },
{ 0,0,0,0,1,0,0,0,1 },
{ 0,0,0,1,0,1,0,0,1 },
{ 0,0,0,0,0,0,1,1,0 }, };

void main() {
	printf(">BFS\n");
	BFS();
	printf("\n>DFS\n");
	DFS();
}

void DFS() {
	int stack[N];
	int top = -1;
	int i, j, k;
	for (i = 0; i < N; i++) check[i] = 0;
	for (i = 0; i < N; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			Push(stack, &top, i);
			while (!(top<0)) {
				k = Pop(stack, &top);
				printf("%c ", k + 'A');
				for (j = 0; j < N; j++) {
					if (Grape[k][j] == 1) {
						if (check == 0) {
							Push(stack, &top, j);
							check[j] = 1;
						}
					}
				}
			}
		}
	}
}

void Push(int a[], int *top, int i) {
	if ((*top) == (N - 1)) {
		printf("스택 포화 에러\n");
		return;
	}
	else a[++(*top)] = i;
}

int Pop(int a[], int *top) {
	if (top == -1) {
		printf("스택 공백 에러\n");
		exit(1);
	}
	else return a[(*top)--];
}

void BFS() {
	int q[N + 1];
	int f = 0, r = 0;
	int i, j, k;
	for (i = 0; i < N; i++) check[i] = 0;
	for (i = 0; i < N; i++) {
		if (check[i] == 0) {
			Dequeue(q, f, &r, i);
			check[i] = 1;
			while (!(f == r)) {
				k = Enqueue(q, &f, r);
				printf("%c ", k + 'A');
				for (j = 0; j < N; j++) {
					if (Grape[k][j] == 1) {
						if (check == 0) {
							Dequeue(q, f, &r, j);
							check[j] = 1;
						}
					}
				}
			}
		}
	}
}

int Enqueue(int a[], int* f, int r) {
	int i;
	if (*f == r) {
		printf("큐가 포화상태입니다\n");
		exit(1);
	}
	i = a[*f];
	*f = ++(*f) % N;

	return i;
}

void Dequeue(int a[], int f, int* r, int i) {
	if ((*r + 1) % N == f) {
		printf("큐가 공백상태입니다\n");
		exit(1);
	}
	a[*r] = i;
	*r = ++(*r) % N;
}