
// sources: borrowed inspiration from https://stackoverflow.com/questions/29435348/display-an-int-number-in-hexadecimal-with-leading-zeros
#include <stdio.h>

int main(int argc, char *argv[]) {
	unsigned long long value = 0ULL;
	unsigned int digits = 8U;

	if (argc >= 2) {
		if (sscanf(argv[1], "%llu", &value) != 1) {
			fprintf(stderr, "Invalid decimal value.\n");
			return 1;
		}

		if (argc >= 3) {
			unsigned int parsed_digits = 0U;
			if (sscanf(argv[2], "%u", &parsed_digits) != 1) {
				fprintf(stderr, "Invalid digit count.\n");
				return 1;
			}
			digits = parsed_digits;
		}
	} else {
		printf("Enter a decimal value: ");
		if (scanf("%llu", &value) != 1) {
			fprintf(stderr, "Invalid decimal value.\n");
			return 1;
		}

		printf("Enter digit count (8 or 16): ");
		if (scanf("%u", &digits) != 1) {
			fprintf(stderr, "Invalid digit count.\n");
			return 1;
		}
	}

	if (digits != 8U && digits != 16U) {
		fprintf(stderr, "Digit count must be 8 or 16.\n");
		return 1;
	}

	if (digits == 8U) {
		unsigned int value32 = (unsigned int)value;
		printf("0x%08X\n", value32);
	} else {
		printf("0x%016llX\n", value);
	}

	return 0;
}
