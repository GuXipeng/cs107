#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *lsearch(void *key, void *base, int n,
		int elem_size, int (*cmp)(void *, void *));

int intcmp(void *elem1, void *elem2);
int str_cmp(void *elem1, void *elem2);

int main(void)
{
	int a[] = {1, 2, 3, 5, 6, 7, 8};
	char *notes[] = {"Ab", "F#", "B", "6b", "D"};
	int f = 8;
	char *f_note = "Ab";
	char **found = lsearch(&f_note, notes, 5,
			sizeof(char **), str_cmp);
	int *result = NULL;
	result = lsearch(&f, a, 7, sizeof(int), intcmp);
	if (result == NULL) {
		printf("not found in a[]\n");
	}
	else {
		long addr = (int) result;
		printf("result is:%d\n addr is %x\n", *result, addr);
	}

	if (found == NULL) {
		printf("not found in notes[]\n");
	} else {
		printf("found %s\n", *found);
	}
	return 0;
}

void *lsearch(void *key, void *base, int n,
		int elem_size, int (*cmp)(void *, void *))
{
	int i;
	for (i = 0;i < n;i++) {
		void *elem_addr = (char *)base + i * elem_size;
		if (cmp(key, elem_addr) == 0)
			return elem_addr;
	}

	return NULL;
}

int intcmp(void *elem1, void *elem2)
{
	int *ip1 = elem1;
	int *ip2 = elem2;

	return *ip1 - *ip2;
}

int str_cmp(void *elem1, void *elem2)
{
	char *s1 = *(char **)elem1;
	char *s2 = *(char **)elem2;

	return strcmp(s1, s2);
}

