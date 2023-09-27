#include <stdio.h>
#include <assert.h>
/*

*/
int add(int a, int b) {
    return a + b;
}

int main() {
    // Test case 1: Check if addition works correctly
    int result = add(2, 3);
    assert(result == 5);

    // Test case 2: Check another addition
    result = add(10, 20);
    assert(result == 30);

    // Test case 3: This test will fail, and the program will terminate
    result = add(5, 5);
    if(!(result == 10)){
        fprintf(stderr, "Assertion failed: add(5,5\n)");
        // assert(result == 1);
    }
    

    printf("All tests passed!\n");

    return 0;
}
