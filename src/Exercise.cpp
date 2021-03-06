#include "Exercise.hpp"

class Exercise {
private:
    char Letter;
    int countWord;
    std::string Sentence;
    std::vector<std::string> BDWord;

public:
    Exercise()
    {
        Clear();
        LoadFromTxt();
    }
    void letterSet(char ch)
    {
        Letter = ch;
    }
    char letterGet()
    {
        return Letter;
    }
    void countWordSet(int a)
    {
        countWord = a;
    }
    int countWordGet()
    {
        return countWord;
    }
    void sentenceSet(std::string str)
    {
        Sentence = str;
    }
    std::string sentenceGet()
    {
        return Sentence;
    }
    void LoadFromTxt()
    {
        std::fstream fin("thirdparty/txt/BDWord.txt", std::ios::in);
        std::string text;
        for (int i = 0; i < 1000; i++) {
            fin >> text;
            BDWord.push_back(text);
        }
        fin.close();
    }
    void RandomLetter()
    {
        srand(time(0));
        char temp = (rand() % 90) + 33;
        letterSet(temp);
    }
    void RandomSentence()
    {
        srand(time(0));
        countWord = (rand() % 4) + 1;
        std::vector<int> posBD;
        for (int i = 0; i < countWord; i++) {
            int pos = rand() % 1000;
            posBD.push_back(pos);
            Sentence += BDWord[posBD[i]] + " ";
        }
        Sentence.erase(Sentence.end() - 1);
    }
    void Clear()
    {
        Letter = ' ';
        countWord = 0;
        Sentence.clear();
    }
    bool CheckAnswer(std::string str = "", char ch = ' ')
    {
        if (Letter != ch)
            return false;
        if (Sentence.compare(str) != 0)
            return false;
        return true;
    }
};