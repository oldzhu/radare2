#include <r_util.h>
#include "minunit.h"

bool test_r_str_scanf(void) {
	char what[3] = {0};
	char who[8] = {0};
	int res = r_str_scanf ("Hello World", "%.s %.s", sizeof (what), what, sizeof (who), who);
	mu_assert_streq (what, "He", "truncated string in custom scanf failed");
	mu_assert_streq (who, "World", "truncated string in custom scanf failed");
	mu_assert_eq (res, 2, "return value for scanf failed");

	strcpy (what, "tr");
	strcpy (who, "trash");
	res = r_str_scanf ("Hello World", "%s %s", what, who);
	mu_assert_streq (what, "", "string scanf fails if no length provided");
	mu_assert_streq (who, "", "string scanf fails if no length given");
	mu_assert_eq (res, 0, "return value for scanf failed");

	ut64 bignum = 0;
	res = r_str_scanf ("0x120000023b2d8000", "0x%Lx", &bignum);
	mu_assert_eq (0x120000023b2d8000, bignum, "portable ut64 scanf failed");
	mu_assert_eq (res, 1, "return value for scanf failed");
	mu_end;
}


bool all_tests(void) {
	mu_run_test (test_r_str_scanf);
	return tests_passed != tests_run;
}

int main(int argc, char **argv) {
	return all_tests ();
}