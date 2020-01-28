#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#define INPUT_LEN 1023

char* argv[5];
char arg_length[] = "--length";
char arg_length_val[] = "131"; // is independent from input length
char arg_keyed[] = "--keyed";
char arg_keyed_val[] = "77686174732074686520456c7669736820776f726420666f7220667269656e64"; // is independent from input length
char arg_derive_key[] = "--derive-key";
char arg_derive_key_val[] = "BLAKE3 2019-12-27 16:29:52 test vectors context"; // is independent from input length

int __builtin_popcountll(unsigned long long x) {
  int count = 0;
  while (x) {
    if (x & 1ULL) count++;
    x >>=1;
  }
  return count;
}

void test() {

	// Test the default hash.
	printf("Test the default hash.");
  	main(1, argv);

	// Test the extended hash.
	printf("Test the extended hash.");
	argv[1] = arg_length;
  	argv[2] = arg_length_val;
	main(3, argv);

	// Test the default keyed hash.
	printf("Test the extended hash.");
	argv[1] = arg_keyed;
  	argv[2] = arg_keyed_val;
	main(3, argv);

	// Test the extended keyed hash.
	printf("Test the extended keyed hash.");
	argv[1] = arg_keyed;
  	argv[2] = arg_keyed_val;
	argv[3] = arg_length;
  	argv[4] = arg_length_val;
	main(5, argv);

    	// Test the default derive key.
	printf("Test the default derive key.");
	argv[1] = arg_derive_key;
  	argv[2] = arg_derive_key_val;
	main(3, argv);

	// Test the extended derive key.
	printf("Test the extended derive key.");
	argv[1] = arg_derive_key;
  	argv[2] = arg_derive_key_val;
	argv[3] = arg_length;
  	argv[4] = arg_length_val;
	main(5, argv);
}
