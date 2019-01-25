#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
}Position;


void init(Position*, int);
void affi(Position*);

int main(void)
{
	Position p1;
	init(&p1,2);
	affi(&p1);
	return 1;
}

void init(Position* p, int i)
{
	p->x = i;
	p->y = i;
}

void affi(Position * p)
{
	printf("x=%d y=%d", (*p).x, (*p).y);
	// printf("x=%d y=%d", p->x, p->y);
}