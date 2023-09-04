#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ft_convert_base.c" // Include your code here

int main() {
    char *base_form = "0123456789"; // Valid base
    char *base_to = "01"; // Valid base

    // Test 1: Invalid Base Characters
    char *invalid_base_form = "0123456789+"; // Invalid base
    char *result = ft_convert_base("42", invalid_base_form, base_to);
    if (result == NULL) {
        printf("Test 1: Passed (Invalid Base Characters)\n");
    } else {
        printf("Test 1: Failed (Invalid Base Characters)\n");
    }
    free(result);

    // Test 2: Empty Base String
    char *empty_base = ""; // Empty base
    result = ft_convert_base("42", empty_base, base_to);
    if (result == NULL) {
        printf("Test 2: Passed (Empty Base String)\n");
    } else {
        printf("Test 2: Failed (Empty Base String)\n");
    }
    free(result);

    // Test 3: Null Pointers
    char *null_base = NULL; // NULL pointer
    result = ft_convert_base("42", base_form, null_base);
    if (result == NULL) {
        printf("Test 3: Passed (Null Pointers)\n");
    } else {
        printf("Test 3: Failed (Null Pointers)\n");
    }
    free(result);

    // Test 4: Memory Allocation Failure
    // Simulate a memory allocation failure by using a huge value for 'i'
    char *base_form_large = "0123456789"; // Valid base
    result = ft_convert_base("42", base_form_large, base_to);
    if (result == NULL) {
        printf("Test 4: Passed (Memory Allocation Failure)\n");
    } else {
        printf("Test 4: Failed (Memory Allocation Failure)\n");
    }
    free(result);

    // Test 5: Conversion to Base 1
    char *base_to_one = "1"; // Base 1 (only one character)
    result = ft_convert_base("42", base_form, base_to_one);
    if (result == NULL) {
        printf("Test 5: Passed (Conversion to Base 1)\n");
    } else {
        printf("Test 5: Failed (Conversion to Base 1)\n");
    }
    free(result);

    // Test 6: Conversion to Base 0
    char *base_to_zero = "0"; // Base 0 (only one character)
    result = ft_convert_base("42", base_form, base_to_zero);
    if (result == NULL) {
        printf("Test 6: Passed (Conversion to Base 0)\n");
    } else {
        printf("Test 6: Failed (Conversion to Base 0)\n");
    }
    free(result);

    // Test 7: Negative Bases
    char *base_negative = "-0123456789"; // Negative base
    result = ft_convert_base("42", base_negative, base_to);
    if (result == NULL) {
        printf("Test 7: Passed (Negative Bases)\n");
    } else {
        printf("Test 7: Failed (Negative Bases)\n");
    }
    free(result);

    // Test 8: Large Numbers
    char *base_large = "0123456789"; // Valid base
    result = ft_convert_base("999999999999999999", base_large, base_to);
    if (result != NULL) {
        printf("Test 8: Passed (Large Numbers)\n");
    } else {
        printf("Test 8: Failed (Large Numbers)\n");
    }
    free(result);

    // Test 9: Valid Case
    result = ft_convert_base("42", base_form, base_to);
    if (result != NULL && strcmp(result, "101010") == 0) {
        printf("Test 9: Passed (Valid Case)\n");
    } else {
        printf("Test 9: Failed (Valid Case)\n");
    }
    free(result);

    return 0;
}

