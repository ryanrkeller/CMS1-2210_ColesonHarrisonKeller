// sources: finding out how to determine length of integer https://stackoverflow.com/questions/1068849/how-do-i-determine-the-number-of-digits-of-an-integer-in-c
#include <stdio.h>

int main(int argc, char *argv[]) {
	unsigned int max_value = 0U;

	if (argc >= 2) {
		if (sscanf(argv[1], "%u", &max_value) != 1) {
			fprintf(stderr, "Invalid upper bound.\n");
			return 1;
		}
	} else {
		printf("Enter the upper bound for the times tables: ");
		if (scanf("%u", &max_value) != 1) {
			fprintf(stderr, "Invalid upper bound.\n");
			return 1;
		}
	}

	if (max_value < 2U) {
		fprintf(stderr, "Upper bound must be at least 2.\n");
		return 1;
	}

	unsigned int max_product = max_value * max_value;
	unsigned int width = 1U;
	unsigned int temp = max_product;
	while (temp >= 10U) {
		temp /= 10U;
		width++;
	}

	printf("%*s", (int)(width + 1U), "");
	for (unsigned int col = 2U; col <= max_value; col++) {
		printf("%*u", (int)(width + 1U), col);
	}
	printf("\n");

	for (unsigned int row = 1U; row <= max_value; row++) {
		printf("%*u", (int)(width + 1U), row);
		for (unsigned int col = 2U; col <= max_value; col++) {
			unsigned int product = row * col;
			printf("%*u", (int)(width + 1U), product);
		}
		printf("\n");
	}

	return 0;
}
