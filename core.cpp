#include "core.h"
#include <QFile>
#include <QString>

const char *FileName = "/Users/kiriill/Desktop/Qt\ Projects/BaC/Records.txt";

int Rand(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 9);
    return distrib(gen);
}

void Core::GenNewConstNum() {
    char nums[] = {'1','2','3','4','5','6','7','8','9','0'};
    std::string str = "    ";
    for (int i = 0; i < 20; i++) {
        std::swap(nums[Rand()],nums[Rand()]);
    }
    for (int i = 0; i < 4; i++) {
        constNum_[i] = nums[i];
    }
}

void Core::SetConstNum(const std::string &str) {
    constNum_ = str;
}



Core::Core() {
    GenNewConstNum();
}



void Core::SetNum(const std::string& aNum) {
    bool digit = true;
    for (int i = 0; i < 4; i++) {
        if (!isdigit(aNum[i])) {
              digit = false;
              break;
        }
    }
    if (aNum.size() < 4 || !digit) {
        throw std::runtime_error("incorect num");
    } else {
        num_ = aNum;
        score_++;
    }
}

std::string Core::GetNum() {
    return num_;
}

int8_t Core::GetCows() {
    int8_t ans = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {
                continue;
            }
            if (num_[i] == constNum_[j]) {
                ans++;
                break;
            }
        }
    }
    return ans;
}

int8_t Core::GetBulls() {
    int8_t ans = 0;
    for (int i = 0; i < 4; i++) {
        if (num_[i] == constNum_[i]) {
            ans++;
        }
    }
    return ans;
}

int Core::GetScore() {
    return score_;
}

void Core::NewGame() {
    score_ = 0;
    num_ = "";
    GenNewConstNum();
}

bool Core::IsRecord() {
    std::ifstream fin(FileName);
    int rec = 0;
    for (int i = 0; i < 9; i++)
        fin.ignore('\n', 2);
    fin >> rec;
    fin.close();
    if (rec == 0)
        return true;
    if (rec > GetScore())
        return true;
    else
        return false;
}

void Core::NewRecord(const QString &aName) {
    int rec[10];
    std::string str[10];
    bool adding = false;
    std::ifstream fin(FileName);
    for (int i = 0; i < 10; i++) {
        fin >> rec[i];
        fin >> str[i];
    }
    fin.close();
    for (int i = 0; i < 10; i++) {
        if (GetScore() < rec[i] || rec[i] == 0) {
            adding = true;
        }
        if (adding) {
            for (int j = 8; j > i; j--) {
                rec[j + 1] = rec[j];
                str[j + 1] = str[j];
            }
        }
        if (adding) {
            rec[i] = GetScore();
            str[i] = aName.toStdString();
            break;
        }
    }
    std::ofstream fout(FileName);
    for (int i = 0; i < 10; i++) {
        fout << rec[i] << ' ' << str[i] << '\n';
    }
    fout.close();
}

bool Core::isWinning() {
    if (GetBulls() == 4) {
        return true;
    } else
        return false;
}

std::string Core::GetConstNum() {
    return constNum_;
}
