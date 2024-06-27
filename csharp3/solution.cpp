#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class IExam {
public:
    virtual int CheckExam(const std::vector<std::string>& correctAnswers, const std::vector<std::string>& studentAnswers) = 0;
};

class Exam : public IExam {
public:
    int CheckExam(const std::vector<std::string>& correctAnswers, const std::vector<std::string>& studentAnswers) override {
        int score = 0;
        int successiveCorrect = 0;
        int successiveIncorrect = 0;

        for (size_t i = 0; i < correctAnswers.size(); ++i) {
            if (studentAnswers[i] == "") {
                // Blank answer earns +0 points
                successiveCorrect = 0;
                successiveIncorrect = 0;
            }
            else if (studentAnswers[i] == correctAnswers[i]) {
                successiveCorrect++;
                successiveIncorrect = 0;
                score += 4 + (successiveCorrect - 1) * 2; // Each successive correct answer earns +2 points more than the previous
            }
            else {
                successiveIncorrect++;
                successiveCorrect = 0;
                score -= 1 + (successiveIncorrect - 1); // Each successive incorrect answer deducts 1 point less than the previous
            }
        }

        int maxScore = correctAnswers.size() * 4;
        if (score < 0) return 0;
        if (score > maxScore) return maxScore;
        return score;
    }
};

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(); // Ignore the newline character after the number

    std::string correctAnswersInput;
    std::string studentAnswersInput;

    std::getline(std::cin, correctAnswersInput);
    std::getline(std::cin, studentAnswersInput);

    std::vector<std::string> correctAnswers;
    std::vector<std::string> studentAnswers;

    std::stringstream correctStream(correctAnswersInput);
    std::stringstream studentStream(studentAnswersInput);
    std::string answer;

    while (correctStream >> answer) {
        correctAnswers.push_back(answer);
    }

    while (studentStream >> answer) {
        studentAnswers.push_back(answer);
    }

    Exam exam;
    int score = exam.CheckExam(correctAnswers, studentAnswers);
    std::cout << "Score: " << score << std::endl;

    return 0;
}
