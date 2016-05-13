#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NOT(a) not[a]
#define OR(a, b) or[a][b]
#define AND(a, b) and[a][b]
#define IMPL(a, b) impl[a][b]

const int PARAMETERS = 3;
int toInt(char x) {
	if (x == '0') return 0;
	if (x == '1') return 1;
	if (x == 'x' || x == 'X') return 2;
	return -1;
}
int not[3];
int or[3][3];
int and[3][3];
int impl[3][3];
int expression(int a, int b, int c) {
	return AND(a, IMPL(IMPL(OR(NOT(b), c), AND(b, c)), NOT(a)));
}
int evaluate(char* x) { // returns 1 if the answer was correct, 0 otherwise
	if (strlen(x) < PARAMETERS) return 0;
	int a = toInt(x[0]);
	int b = toInt(x[1]);
	int c = toInt(x[2]);
	if (expression(a, b, c) != 1) return 0;
	if (a != 2 && expression(2, b, c) == 1) return 0;
	if (b != 2 && expression(a, 2, c) == 1) return 0;
	if (c != 2 && expression(a, b, 2) == 1) return 0;
	return 1;
}
int main(int argc, char** argv) {
	
	
	char a[2];
	char b[2];
	char c[2]; //temporary buffers for reading data from files
	int i;
	FILE* f;
	for (i = 1; i < argc; i+=2) {
		if (strcmp(argv[i], "--not") == 0) {
			f = fopen(argv[i+1], "r");
			if (f == NULL) {
				puts("Blad odczytu pliku\n");
				return 1;
			}
			while (fscanf(f, "%1s %1s", a, b) != EOF)
				not[toInt(a[0])] = toInt(b[0]);
			fclose(f);
		}
		else if (strcmp(argv[i], "--or") == 0) {
			f = fopen(argv[i+1], "r");
			if (f == NULL) {
				puts("Blad odczytu pliku\n");
				return 1;
			}
			while (fscanf(f, "%1s %1s %1s", a, b, c) != EOF)
				or[toInt(a[0])][toInt(b[0])] = toInt(c[0]);
			fclose(f);
		}
		else if (strcmp(argv[i], "--and") == 0) {
			f = fopen(argv[i+1], "r");
			if (f == NULL) {
				puts("Blad odczytu pliku\n");
				return 1;
			}
			while (fscanf(f, "%1s %1s %1s", a, b, c) != EOF)
				and[toInt(a[0])][toInt(b[0])] = toInt(c[0]);
			fclose(f);
		}
		else if (strcmp(argv[i], "--impl") == 0) {
			f = fopen(argv[i+1], "r");
			if (f == NULL) {
				puts("Blad odczytu pliku\n");
				return 1;
			}
			while (fscanf(f, "%1s %1s %1s", a, b, c) != EOF)
				impl[toInt(a[0])][toInt(b[0])] = toInt(c[0]);
			fclose(f);
		}
	} // Data loaded

	char help[] = "\
answer <odp> - podaje odpowiedz\n\
    <odp> to ciag znakow '0', '1' i 'x'. Kazdy kolejny znak odpowiada wartosci kolejnego zdania czastkowego\n\
    w kolejnosci alfabetycznej. Na przyklad 'answer x10' ustawia A = x, B = 1, C = 0\n\
    0 - falsz, 1 - prawda, x - stan nieokreslony\n\
show - wyswietla zagadke\n\
quit - opuszcza gre\n\
help - wyswietla pomoc\n";
	char expr[] = "A and (((~B or C) => (B and C)) => ~A)\n";
	puts("");
	puts("Ponizsze zdanie logiczne jest prawdziwe. Okresl prawdziwosc zdan czastkowych.");
	puts("Jesli zdanie czastkowe nie ma wplywu na cale zdanie, nalezy uzyc stanu nieokreslonego.");
	puts(help);
	puts(expr);
	int quit = 0;
	char answer[50];
	char command[50];
	char argument[50];
	while (quit == 0) {
		putc('>', stdout);
		fgets(answer, 50, stdin);
		int words = sscanf(answer, "%s %s", command, argument);
		if(strcmp(command, "quit") == 0) quit = 1;
		else if (strcmp(command, "help") == 0) puts(help);
		else if (strcmp(command, "show") == 0) puts(expr);
		else if (strcmp(command, "answer") == 0) {
			if (words == 1) puts("Nie podano argumentu dla answer.");
			else if (evaluate(argument)){
				puts("Poprawna odpowiedz.");
				quit = 1;
			}
			else puts("Zla odpowiedz.");
		}
		else puts("Nieznana komenda. 'help' wyswietla pomoc.");
	}
	return 0;
}