#include <gtest/gtest.h>
#include "sort.h"

TEST(random, common1)
{
    Solution solve;
    vector<int> vec = solve.gen_rand_array(10);

    solve.print_vec(vec);
}

TEST(bubble, common1)
{
    Solution solve;
    vector<int> vec = solve.gen_rand_array(20);
    
    bubbleSort(vec);
    // solve.print_vec(vec);

    EXPECT_EQ(solve.judgeSort(vec), true);
}

TEST(bubble, limit1)
{
    Solution solve;
    vector<int> vec = solve.gen_rand_array(1);
    
    bubbleSort(vec);
    // solve.print_vec(vec);

    EXPECT_EQ(solve.judgeSort(vec), true);
}

TEST(bubble, limit2)
{
    Solution solve;
    vector<int> vec = solve.gen_rand_array(0);
    
    bubbleSort(vec);
    // solve.print_vec(vec);

    EXPECT_EQ(solve.judgeSort(vec), true);
}

TEST(selection, limit1)
{
    Solution solve;
    vector<int> vec = solve.gen_rand_array(1);
    
    selectionSort(vec);
    // solve.print_vec(vec);

    EXPECT_EQ(solve.judgeSort(vec), true);
}

TEST(selection, limit2)
{
    Solution solve;
    vector<int> vec = solve.gen_rand_array(0);
    
    selectionSort(vec);
    // solve.print_vec(vec);

    EXPECT_EQ(solve.judgeSort(vec), true);
}

TEST(insert, common1)
{
    Solution solve;
    vector<int> vec = solve.gen_rand_array(100);
    
    insertSort(vec);
    // solve.print_vec(vec);

    EXPECT_EQ(solve.judgeSort(vec), true);
}

TEST(insert, limit1)
{
    Solution solve;
    vector<int> vec = solve.gen_rand_array(1);
    
    insertSort(vec);
    // solve.print_vec(vec);

    EXPECT_EQ(solve.judgeSort(vec), true);
}

TEST(insert, limit2)
{
    Solution solve;
    vector<int> vec = solve.gen_rand_array(1);
    
    insertSort(vec);
    // solve.print_vec(vec);

    EXPECT_EQ(solve.judgeSort(vec), true);
}

TEST(quick, common1)
{
    Solution solve;
    vector<int> vec = solve.gen_rand_array(100);

    quickSort(vec);

    EXPECT_EQ(solve.judgeSort(vec), true);
}

TEST(shell, common1)
{
    Solution solve;
    vector<int> vec = solve.gen_rand_array(100);

    shellSort(vec);

    EXPECT_EQ(solve.judgeSort(vec), true);
}

TEST(merge, common1)
{
    Solution solve;
    vector<int> vec = solve.gen_rand_array(10);

    mergeSort(vec);

    EXPECT_EQ(solve.judgeSort(vec), true);
}

TEST(time, common1)
{
    g_len = 50000;

    double time = cal_time(bubbleSort);
    cout << "bubble sort:\t" << time << endl;
    time = cal_time(insertSort);
    cout << "insert sort:\t" << time << endl;
    time = cal_time(selectionSort);
    cout << "selection sort:\t" << time << endl;
    time = cal_time(quickSort);
    cout << "Quick sort:\t" << time << endl;
    time = cal_time(shellSort);
    cout << "Shell sort:\t" << time << endl;
    time = cal_time(mergeSort);
    cout << "merge sort:\t" << time << endl;
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}