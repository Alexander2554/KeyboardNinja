#include "Exercise.hpp"

class Exercise {
private:
    char Letter;
    std::string OutLetter;
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
    void outLetterSet(std::string str)
    {
        OutLetter = str;
    }
    std::string outLetterGet()
    {
        return OutLetter;
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
        std::fstream fin("thirdparty/TXT/BDWord.txt", std::ios::in);
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
        int CountWord = (rand() % 4) + 1;
        std::vector<int> posBD;
        for (int i = 0; i < CountWord; i++) {
            int pos = rand() % 1000;
            posBD.push_back(pos);
            Sentence += BDWord[posBD[i]] + " ";
        }
    }
    void Clear()
    {
        Letter = ' ';
        OutLetter.clear();
        Sentence.clear();
    }
    bool CheckAnswer(std::string str = "", char ch = ' ')
    {
        if (Letter != ch)
            return false;
        if (Sentence.compare(str))
            return false;
        return true;
    }
};