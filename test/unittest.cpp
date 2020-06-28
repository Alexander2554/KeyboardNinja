#include "../src/Menu.cpp"
#include "gtest/gtest.h"
#include <limits.h>
namespace {

TEST(CheckAnswer, CorrectCH)
{
    Exercise exercise;
    exercise.letterSet(' ');
    ASSERT_EQ(true, exercise.CheckAnswer("", ' '));

    exercise.letterSet('A');
    ASSERT_EQ(true, exercise.CheckAnswer("", 'A'));

    exercise.letterSet('z');
    ASSERT_EQ(true, exercise.CheckAnswer("", 'z'));
}
TEST(CheckAnswer, CorrectSentence)
{
    Exercise exercise;
    exercise.sentenceSet("hello");
    ASSERT_EQ(true, exercise.CheckAnswer("hello", ' '));

    exercise.sentenceSet("go back");
    ASSERT_EQ(true, exercise.CheckAnswer("go back", ' '));

    exercise.sentenceSet("collect money");
    ASSERT_EQ(true, exercise.CheckAnswer("collect money", ' '));
}
TEST(CheckAnswer, UnCorrectCH)
{
    Exercise exercise;
    exercise.letterSet(' ');
    ASSERT_NE(true, exercise.CheckAnswer("", 'A'));

    exercise.letterSet(' ');
    ASSERT_NE(true, exercise.CheckAnswer("mom", 'A'));

    exercise.letterSet(' ');
    ASSERT_NE(true, exercise.CheckAnswer("mom", ' '));
}
TEST(CheckAnswer, UnCorrectSentence)
{
    Exercise exercise;
    exercise.sentenceSet("hello");
    ASSERT_NE(true, exercise.CheckAnswer("helo", ' '));

    exercise.sentenceSet("go back");
    ASSERT_NE(true, exercise.CheckAnswer("go  back", ' '));

    exercise.sentenceSet("collect money");
    ASSERT_NE(true, exercise.CheckAnswer(" collect money", ' '));
}
TEST(CheckAnswer, UnCorrectCH2)
{
    Exercise exercise;
    exercise.letterSet(' ');
    ASSERT_NE(true, exercise.CheckAnswer("", '['));

    exercise.letterSet(' ');
    ASSERT_NE(true, exercise.CheckAnswer("", 'z'));

    exercise.letterSet(' ');
    ASSERT_NE(true, exercise.CheckAnswer("", '5'));
}
TEST(CheckAnswer, UnCorrectSentence2)
{
    Exercise exercise;
    exercise.sentenceSet("hello");
    ASSERT_NE(true, exercise.CheckAnswer("", ' '));

    exercise.sentenceSet("go back");
    ASSERT_NE(true, exercise.CheckAnswer("пщ ифсл", ' '));

    exercise.sentenceSet("collect money");
    ASSERT_NE(true, exercise.CheckAnswer("collectmoney", ' '));
}
}