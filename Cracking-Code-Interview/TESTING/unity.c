// #include "unity.h"
// #include "my_math.h" // The code being tested

void setUp(void) {
    // Set up any necessary resources or test data
}

void tearDown(void) {
    // Clean up resources
}

void test_add_positive_numbers(void) {
    TEST_ASSERT_EQUAL_INT(5, add(2, 3)); // Check if add(2, 3) == 5
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_add_positive_numbers);

    return UNITY_END();
}
