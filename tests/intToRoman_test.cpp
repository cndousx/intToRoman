#include <gtest/gtest.h>
#include "../include/solution.h"
#include <iostream>
using namespace std;

TEST(SolutionTest, IntToRomanTest) {
    cout << "start test 整数转罗马数字" << endl;
    Solution solution = Solution();
    EXPECT_EQ(solution.intToRoman(3), "III");
    EXPECT_EQ(solution.intToRoman(4), "IV");
    EXPECT_EQ(solution.intToRoman(9), "IX");
    EXPECT_EQ(solution.intToRoman(58), "LVIII");
    EXPECT_EQ(solution.intToRoman(1994), "MCMXCIV");
    cout << "test end 整数转罗马数字" << endl;
}