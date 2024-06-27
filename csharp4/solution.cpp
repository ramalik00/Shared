// #include <iostream>
// #include <vector>
// #include <cmath>

// class IEmployeePerformance {
// public:
//     virtual int getEmployeeId() const = 0;
//     virtual int getKpi1() const = 0;
//     virtual int getKpi2() const = 0;
//     virtual int getKpi3() const = 0;
//     virtual int getKpi4() const = 0;
// };

// class EmployeePerformance : public IEmployeePerformance {
// private:
//     int employeeId;
//     int kpi1, kpi2, kpi3, kpi4;

// public:
//     EmployeePerformance(int id, int k1, int k2, int k3, int k4)
//         : employeeId(id), kpi1(k1), kpi2(k2), kpi3(k3), kpi4(k4) {}

//     int getEmployeeId() const override { return employeeId; }
//     int getKpi1() const override { return kpi1; }
//     int getKpi2() const override { return kpi2; }
//     int getKpi3() const override { return kpi3; }
//     int getKpi4() const override { return kpi4; }
// };

// class EvaluateEmployeePerformance {
// public:
//     static std::pair<std::vector<int>, std::vector<int>> EvaluateEmployeePerformanceHelper(const std::vector<EmployeePerformance>& performanceData) {
//         std::vector<int> continueEmployees;
//         std::vector<int> disengageEmployees;

//         for (const auto& employee : performanceData) {
//             int totalKpi = employee.getKpi1() + employee.getKpi2() + employee.getKpi3() + employee.getKpi4();
//             int averageKpi = static_cast<int>(std::ceil(static_cast<double>(totalKpi) / 4));

//             if (averageKpi >= 50) {
//                 continueEmployees.push_back(employee.getEmployeeId());
//             } else {
//                 disengageEmployees.push_back(employee.getEmployeeId());
//             }
//         }

//         return {continueEmployees, disengageEmployees};
//     }
// };

// int main() {
//     int n;
//     std::cin >> n;
//     std::vector<EmployeePerformance> performanceData;

//     for (int i = 0; i < n; ++i) {
//         int id, kpi1, kpi2, kpi3, kpi4;
//         std::cin >> id >> kpi1 >> kpi2 >> kpi3 >> kpi4;
//         performanceData.emplace_back(id, kpi1, kpi2, kpi3, kpi4);
//     }

//     auto result = EvaluateEmployeePerformance::EvaluateEmployeePerformanceHelper(performanceData);
//     const std::vector<int>& continueEmployees = result.first;
//     const std::vector<int>& disengageEmployees = result.second;

//     std::cout << "Continue Employees: ";
//     for (size_t i = 0; i < continueEmployees.size(); ++i) {
//         if (i > 0) std::cout << ", ";
//         std::cout << continueEmployees[i];
//     }
//     std::cout << std::endl;

//     std::cout << "Disengage Employees: ";
//     for (size_t i = 0; i < disengageEmployees.size(); ++i) {
//         if (i > 0) std::cout << ", ";
//         std::cout << disengageEmployees[i];
//     }
//     std::cout << std::endl;

//     return 0;
// }


#include <iostream>
#include <vector>
#include <string>
#include <tuple>

const std::vector<std::string> RANKS = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "JOKER"};
const std::vector<std::string> SUITS = {"♣", "♦", "♥", "♠"};

class Card {
public:
    std::string rank;
    std::string suit;

    Card(std::string r, std::string s = "") : rank(r), suit(s) {}

    std::string toString() const {
        return rank + (suit.empty() ? "" : suit);
    }

    bool operator==(const Card& other) const {
        return rank == other.rank && suit == other.suit;
    }
};

bool isValidHand(const std::vector<Card>& cards) {
    // Implement the logic for isValidHand
    return true;
}

int compareHands(const std::vector<Card>& cards1, const std::vector<Card>& cards2) {
    // Implement the logic for compareHands
    return 0;
}

void runTests() {
    bool allTestsPassed = true;

    std::vector<std::pair<std::vector<Card>, bool>> VALID_HAND_TEST_CASES = {
        {{Card("5", "♦")}, false},
        {{Card("5", "♥"), Card("5", "♥"), Card("5", "♥")}, false},
        {{Card("4", "♥"), Card("5", "♥"), Card("A", "♥"), Card("J", "♠"), Card("5", "♥")}, false},
        {{Card("5", "♥"), Card("5", "♥"), Card("Q", "♥"), Card("Q", "♥"), Card("2", "♠")}, false},
        {{Card("A", "♥"), Card("5", "♦"), Card("3", "♥"), Card("5", "♥"), Card("3", "♥")}, false},
        {{Card("3", "♥"), Card("3", "♥"), Card("A", "♥"), Card("Q", "♥"), Card("5", "♥")}, true},
        {{Card("3", "♦"), Card("3", "♦"), Card("3", "♥"), Card("3", "♥"), Card("5", "♥")}, true},
        {{Card("J", "♦"), Card("10", "♥"), Card("Q", "♠"), Card("9", "♣"), Card("K", "♠")}, true},
        {{Card("5", "♥"), Card("5", "♥"), Card("J", "♥"), Card("5", "♥"), Card("J", "♥")}, true},
        {{Card("A", "♥"), Card("4", "♥"), Card("5", "♥"), Card("3", "♥"), Card("2", "♥")}, true},
        {{Card("5", "♦"), Card("5", "♣"), Card("5", "♥"), Card("5", "♣"), Card("6", "♥")}, true},
        {{Card("5", "♦"), Card("5", "♣"), Card("5", "♥"), Card("K", "♣"), Card("5", "♥")}, true},
        {{Card("5", "♦"), Card("5", "♣"), Card("A", "♥"), Card("5", "♣"), Card("5", "♥")}, true},
        {{Card("5", "♦"), Card("5", "♣"), Card("5", "♥"), Card("5", "♣"), Card("5", "♥")}, true},
    };

    for (const auto& testCase : VALID_HAND_TEST_CASES) {
        if (isValidHand(testCase.first) != testCase.second) {
            std::cout << "Test Failed: ";
            for (const auto& card : testCase.first) {
                std::cout << card.toString() << " ";
            }
            std::cout << "should be " << testCase.second << std::endl;
            allTestsPassed = false;
        }
    }

    std::vector<std::pair<std::vector<Card>, bool>> VALID_HAND_WITH_JOKERS_TEST_CASES = {
        {{Card("JOKER")}, false},
        {{Card("JOKER"), Card("JOKER"), Card("JOKER")}, false},
        {{Card("JOKER"), Card("JOKER"), Card("JOKER"), Card("JOKER"), Card("JOKER")}, true},
        {{Card("JOKER"), Card("5", "♥"), Card("10", "♥"), Card("Q", "♥"), Card("2", "♠")}, false},
        {{Card("JOKER"), Card("5", "♦"), Card("3", "♥"), Card("5", "♥"), Card("3", "♥")}, true},
        {{Card("JOKER"), Card("3", "♦"), Card("3", "♥"), Card("3", "♥"), Card("5", "♥")}, true},
        {{Card("JOKER"), Card("10", "♥"), Card("Q", "♠"), Card("9", "♣"), Card("K", "♠")}, true},
        {{Card("JOKER"), Card("5", "♥"), Card("J", "♥"), Card("5", "♥"), Card("J", "♥")}, true},
        {{Card("JOKER"), Card("4", "♥"), Card("5", "♥"), Card("3", "♥"), Card("2", "♥")}, true},
        {{Card("5", "♦"), Card("JOKER"), Card("5", "♥"), Card("JOKER"), Card("6", "♥")}, true},
        {{Card("5", "♦"), Card("6", "♣"), Card("JOKER"), Card("K", "♣"), Card("JOKER")}, false},
        {{Card("5", "♦"), Card("JOKER"), Card("JOKER"), Card("5", "♣"), Card("5", "♥")}, true},
        {{Card("5", "♦"), Card("9", "♣"), Card("JOKER"), Card("JOKER"), Card("JOKER")}, true},
        {{Card("5", "♦"), Card("6", "♣"), Card("JOKER"), Card("7", "♣"), Card("A", "♥")}, false},
        {{Card("5", "♦"), Card("5", "♣"), Card("JOKER"), Card("4", "♣"), Card("Q", "♥")}, false},
    };

    for (const auto& testCase : VALID_HAND_WITH_JOKERS_TEST_CASES) {
        if (isValidHand(testCase.first) != testCase.second) {
            std::cout << "Test Failed: ";
            for (const auto& card : testCase.first) {
                std::cout << card.toString() << " ";
            }
            std::cout << "should be " << testCase.second << std::endl;
            allTestsPassed = false;
        }
    }

    std::vector<std::tuple<std::vector<Card>, std::vector<Card>, int>> COMPARE_HANDS_TEST_CASES = {
        {{Card("5", "♦")}, {Card("JOKER")}, 0},
        {{Card("JOKER")}, {Card("JOKER")}, 0},
        {{Card("A", "♥"), Card("4", "♥"), Card("5", "♥"), Card("5", "♠"), Card("J", "♥")},
         {Card("4", "♥"), Card("5", "♥"), Card("A", "♥"), Card("J", "♠"), Card("5", "♥")}, 0},
        {{Card("JOKER"), Card("10", "♥"), Card("Q", "♠"), Card("9", "♣"), Card("K", "♠")},
         {Card("JOKER"), Card("10", "♥"), Card("J", "♠"), Card("9", "♣"), Card("7", "♠")}, 1},
        {{Card("5", "♦"), Card("6", "♣"), Card("JOKER"), Card("K", "♣"), Card("JOKER")},
         {Card("5", "♦"), Card("5", "♣"), Card("JOKER"), Card("4", "♣"), Card("Q", "♥")}, 0},
        {{Card("5", "♦"), Card("9", "♣"), Card("JOKER"), Card("JOKER"), Card("JOKER")},
         {Card("5", "♦"), Card("5", "♣"), Card("JOKER"), Card("JOKER", "♣"), Card("Q", "♥")}, 1},
        {{Card("5", "♦"), Card("5", "♣"), Card("JOKER"), Card("JOKER", "♣"), Card("Q", "♥")},
         {Card("5", "♦"), Card("9", "♣"), Card("JOKER"), Card("JOKER"), Card("JOKER")}, -1},
        {{Card("JOKER"), Card("5", "♥"), Card("J", "♥"), Card("K", "♥"), Card("J", "♥")},
         {Card("3", "♥"), Card("3", "♥"), Card("A", "♥"), Card("Q", "♥"), Card("5", "♥")}, 1},
        {{Card("JOKER"), Card("5", "♥"), Card("J", "♥"), Card("K", "♥"), Card("J", "♥")},
         {Card("3", "♥"), Card("K", "♥"), Card("A", "♥"), Card("Q", "♥"), Card("5", "♥")}, 0},
        {{Card("JOKER"), Card("5", "♥"), Card("J", "♥"), Card("K", "♥"), Card("J", "♥")},
         {Card("J", "♥"), Card("K", "♥"), Card("A", "♥"), Card("Q", "♥"), Card("10", "♥")}, 0},
        {{Card("JOKER"), Card("J", "♥"), Card("J", "♥"), Card("J", "♥"), Card("J", "♥")},
         {Card("J", "♥"), Card("J", "♥"), Card("A", "♥"), Card("J", "♥"), Card("J", "♥")}, 1},
        {{Card("JOKER"), Card("JOKER"), Card("JOKER"), Card("JOKER"), Card("JOKER")},
         {Card("K", "♥"), Card("K", "♥"), Card("K", "♥"), Card("K", "♥"), Card("K", "♥")}, 0},
        {{Card("JOKER"), Card("JOKER"), Card("JOKER"), Card("JOKER"), Card("JOKER")},
         {Card("K", "♥"), Card("K", "♥"), Card("K", "♥"), Card("K", "♥"), Card("JOKER")}, 0},
    };

    for (const auto& testCase : COMPARE_HANDS_TEST_CASES) {
        if (compareHands(std::get<0>(testCase), std::get<1>(testCase)) != std::get<2>(testCase)) {
            std::cout << "Test Failed: ";
            for (const auto& card : std::get<0>(testCase)) {
                std::cout << card.toString() << " ";
            }
            std::cout << "should be " << (std::get<2>(testCase) == 1 ? "larger than" : std::get<2>(testCase) == -1 ? "smaller than" : "equal to") << " ";
            for (const auto& card : std::get<1>(testCase)) {
                std::cout << card.toString() << " ";
            }
            std::cout << std::endl;
            allTestsPassed = false;
        }
    }

    if (allTestsPassed) {
        std::cout << "Congrats! All tests passed." << std::endl;
    }
}

int main() {
    runTests();
    return 0;
}

