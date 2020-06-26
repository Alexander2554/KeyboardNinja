#include "Exercise.cpp"
int main(int argc, char const* argv[])
{
    Exercise exercise;
    exercise.RandomLetter();
    exercise.RandomSentence();
    printf("%c\n", exercise.letterGet());
    std::cout << exercise.sentenceGet() + "\n";
    return 0;
}
