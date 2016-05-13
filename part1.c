#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int c = atoi(argv[3]);
	int d = atoi(argv[4]);
	int e = atoi(argv[5]);
	int f = atoi(argv[6]);
	if (a < b && c < d || e == f && (b % c == 0 || d % e == 0)) puts("1");
	else puts("0");
	return 0;
}
