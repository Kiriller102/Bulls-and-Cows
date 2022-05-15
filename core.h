#ifndef CORE_H
#define CORE_H
#include <random>
#include <exception>
#include <fstream>
#include <QString>
#include <string>

class Core {
public:
    Core();

    std::string GetConstNum();

    void SetNum(const std::string&);

    std::string GetNum();

    int8_t GetCows();

    int8_t GetBulls();

    int GetScore();

    void NewGame();

    bool IsRecord();

    void NewRecord(const QString&);

    bool isWinning();

    void GenNewConstNum();

    void SetConstNum(const std::string&);

private:
    unsigned score_;
    std::string constNum_;
    std::string num_;
};

#endif // CORE_H
