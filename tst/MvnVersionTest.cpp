#include "gtest/gtest.h"
#include "MvnVersion.h"

TEST(MvnVersion, test_aliases) {
    EXPECT_EQ(*new MvnVersion("1.0-alpha1"), *new MvnVersion("1.0-a1"));
    EXPECT_EQ(*new MvnVersion("1.0-beta1"), *new MvnVersion("1.0-b1"));
    EXPECT_EQ(*new MvnVersion("1.0-milestone1"), *new MvnVersion("1.0-m1"));
    EXPECT_EQ(*new MvnVersion("1.0-rc1"), *new MvnVersion("1.0-cr1"));
}

TEST(MvnVersion, test_different_final_releases) {
    EXPECT_EQ(*new MvnVersion("1.0-ga"), *new MvnVersion("1.0"));
    EXPECT_EQ(*new MvnVersion("1.0-final"), *new MvnVersion("1.0"));
    EXPECT_EQ(*new MvnVersion("1.0"), *new MvnVersion("1.0.0"));
}

TEST(MvnVersion, test_case_insensitive) {
    EXPECT_EQ(*new MvnVersion("1.0ALPHA1"), *new MvnVersion("1.0-a1"));
    EXPECT_EQ(*new MvnVersion("1.0Alpha1"), *new MvnVersion("1.0-a1"));
    EXPECT_EQ(*new MvnVersion("1.0AlphA1"), *new MvnVersion("1.0-a1"));
    EXPECT_EQ(*new MvnVersion("1.0BETA1"), *new MvnVersion("1.0-b1"));
    EXPECT_EQ(*new MvnVersion("1.0MILESTONE1"), *new MvnVersion("1.0-m1"));
    EXPECT_EQ(*new MvnVersion("1.0RC1"), *new MvnVersion("1.0-cr1"));
    EXPECT_EQ(*new MvnVersion("1.0GA"), *new MvnVersion("1.0"));
    EXPECT_EQ(*new MvnVersion("1.0FINAL"), *new MvnVersion("1.0"));
    EXPECT_EQ(*new MvnVersion("1.0-SNAPSHOT"), *new MvnVersion("1-snapshot"));
}

TEST(MvnVersion, test_separators) {
    EXPECT_EQ(*new MvnVersion("1.0alpha1"), *new MvnVersion("1.0-a1"));
    EXPECT_EQ(*new MvnVersion("1.0alpha-1"), *new MvnVersion("1.0-a1"));
    EXPECT_EQ(*new MvnVersion("1.0beta1"), *new MvnVersion("1.0-b1"));
    EXPECT_EQ(*new MvnVersion("1.0beta-1"), *new MvnVersion("1.0-b1"));
    EXPECT_EQ(*new MvnVersion("1.0milestone1"), *new MvnVersion("1.0-m1"));
    EXPECT_EQ(*new MvnVersion("1.0milestone-1"), *new MvnVersion("1.0-m1"));
    EXPECT_EQ(*new MvnVersion("1.0rc1"), *new MvnVersion("1.0-cr1"));
    EXPECT_EQ(*new MvnVersion("1.0rc-1"), *new MvnVersion("1.0-cr1"));
    EXPECT_EQ(*new MvnVersion("1.0ga"), *new MvnVersion("1.0"));
    // unequal separator
    EXPECT_EQ(*new MvnVersion("1.0alpha.1"), *new MvnVersion("1.0-a1"));
}

TEST(MvnVersion, test_dash_and_period) {
    EXPECT_EQ(*new MvnVersion("1-0.ga"), *new MvnVersion("1.0"));
    EXPECT_EQ(*new MvnVersion("1.0-final"), *new MvnVersion("1.0"));
    EXPECT_EQ(*new MvnVersion("1-0-ga"), *new MvnVersion("1.0"));
    EXPECT_EQ(*new MvnVersion("1-0-final"), *new MvnVersion("1-0"));
    EXPECT_EQ(*new MvnVersion("1-0"), *new MvnVersion("1.0"));
}

TEST(MvnVersion, test_greater_than) {
    EXPECT_GT(*new MvnVersion("1.0alpha2"), *new MvnVersion("1.0-a1"));
    EXPECT_GT(*new MvnVersion("1.0.1alpha-1"), *new MvnVersion("1.0-a1"));
    EXPECT_GT(*new MvnVersion("1.0beta1"), *new MvnVersion("1.0.0-a1"));
    EXPECT_GT(*new MvnVersion("1.0"), *new MvnVersion("1.0-b1"));
    EXPECT_GT(*new MvnVersion("1.0.1"), *new MvnVersion("1.0"));
    EXPECT_GT(*new MvnVersion("1.0milestone-1"), *new MvnVersion("1.0-a1"));
    EXPECT_GT(*new MvnVersion("1.0rc1"), *new MvnVersion("1.0-b1"));
    EXPECT_GT(*new MvnVersion("1.0sp"), *new MvnVersion("1.0"));
    EXPECT_GT(*new MvnVersion("1.0ga"), *new MvnVersion("0.1"));
}

TEST(MvnVersion, test_less_than) {
    EXPECT_LT(*new MvnVersion("1.0-a1"), *new MvnVersion("1.0alpha2"));
    EXPECT_LT(*new MvnVersion("1.0-a1"), *new MvnVersion("1.0.1alpha-1"));
    EXPECT_LT(*new MvnVersion("1.0.0-a1"), *new MvnVersion("1.0beta1"));
    EXPECT_LT(*new MvnVersion("1.0-b1"), *new MvnVersion("1.0"));
    EXPECT_LT(*new MvnVersion("1.0-final"), *new MvnVersion("1.0.1"));
    EXPECT_LT(*new MvnVersion("1.0-a1"), *new MvnVersion("1.0milestone-1"));
    EXPECT_LT(*new MvnVersion("1.0-b1"), *new MvnVersion("1.0rc1"));
    EXPECT_LT(*new MvnVersion("1.0"), *new MvnVersion("1.0sp"));
    EXPECT_LT(*new MvnVersion("0.1"), *new MvnVersion("1.0ga"));
}