#include <gtest/gtest.h>
#include "../src/generate.hpp"
#include "../src/io.hpp"
#include "../src/sortings.hpp"

TEST(GenerateTest, GenerateArray) {
    const int n = 10;
    const int max_value = 100;
    int arr[n];
    eaa::generate::generate_array(arr, n, max_value);

    for (int i = 0; i < n; ++i) {
        EXPECT_GE(arr[i], 0);
        EXPECT_LT(arr[i], max_value);
    }
}

TEST(GenerateTest, EmptyArray) {
    int arr[] = {};
    const int n = 0;
    const int max_value = 100;
    EXPECT_NO_THROW(eaa::generate::generate_array(arr, n, max_value));
}

TEST(SortTest, EmptyArray) {
    int arr[] = {};
    eaa::shell::shell_sort(arr, 0);
    SUCCEED();
}

TEST(SortTest, SingleElement) {
    int arr[] = {5};
    eaa::shell::shell_sort(arr, 1);
    EXPECT_EQ(arr[0], 5);
}

TEST(SortTest, Standart) {
    int arr[] = {3, 1, 4, 2};
    const int expected[] = {1, 2, 3, 4};
    eaa::shell::shell_sort(arr, 4);
    for (int i = 0; i < 4; ++i) {
        EXPECT_EQ(arr[i], expected[i]);
    }
}

TEST(IOTest, PrintArray) {
    int arr[] = {1, 2, 3};
    testing::internal::CaptureStdout();  
    eaa::io::print_array("Test Array:", arr, 3);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Test Array:\n1 2 3 \n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}