// https://github.com/kraxx/42_C_Exam_Intermediate/blob/master/5/count_island.c

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define LIM 100000

int errorCheck(char buf[LIM], int size, int width, int height) {

	if (size / height != width) {
		write(1, "\n", 1);
		return 0;
	}

	for (int i = 0; i < size; i++) {
		if (buf[i] != '.' && buf[i] != 'X' && buf[i] != '\n')
			return 0;
	}
	
	return 1;
}

void floodFill(char buf[LIM], int size, int width, int height, int i, char replacer) {

	buf[i] = replacer;

	if ((i > width) && (buf[i - width] == 'X'))
		floodFill(buf, size, width, height, i - width, replacer);

	if ((i < size - width - 1) && buf[i + width] == 'X')
		floodFill(buf, size, width, height, i + width, replacer);

	if (i && (i % width > 0) && buf[i - 1] == 'X')
		floodFill(buf, size, width, height, i - 1, replacer);

	if (i && (i % width < width - 1) && buf[i + 1] == 'X')
		floodFill(buf, size, width, height, i + 1, replacer);
}

void countIsland(char* file) {
	
	char buf[LIM] = {0};
	int fd = open(file, O_RDONLY);

	int size = read(fd, buf, LIM);
	if (size < 0) {
		write(1, "\n", 1);
		return;
	}

	int width = 1;
	for (int i = 0; buf[i] != '\n'; i++)
		width++;

	int height = size / width;

	if (!errorCheck(buf, size, width, height))
		return;

	char replacer = '0';
	for (int i = 0; i < size; i++) {
		if (buf[i] == 'X') {
			floodFill(buf, size, width, height, i, replacer);
			replacer++;
		}
	}
	write(1, buf, size);
}

int main(int ac, char* av[]) {
	if (ac == 2)
		countIsland(av[1]);
	return 0;
}

