#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printFile(char* fileName) {
	char ch;
	FILE *fp;

	fp = fopen(fileName, "r");

	if (fp == NULL) {
		perror("Error while opening file.\n");
		exit(EXIT_FAILURE);
	}

	printf("the contents of %s are:\n", fileName);

	while( (ch = fgetc(fp)) != EOF) printf("%c", ch);

	fclose(fp);
}

void listDir(char* path) {
	printf("dir %s contains:\n", path);
	DIR *d;
  struct dirent *dir;
  d = opendir(path);
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      printf("%s\n", dir->d_name);
    }
    closedir(d);
  }
}

char* formatTime(double) {

}

void main() {
	clock_t start, end;
	double cpu_time_used;

	start = clock();

	const int NUM_RUNS = 10000;

	for (int i = 0; i < NUM_RUNS; i++) {
		printf("run %d\n", i);
		printf("#################################\n");
		printFile("test.blaa");
		listDir(".");
		printf("#################################\n");
	}

	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	printf("program took %s seconds to complete\n", formatTime(cpu_time_used));

	printf("avg-func run was %s seconds\n", formatTime(cpu_time_used/NUM_RUNS));
}
