#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>

class CensusData {
public:
    int SSN;
    int FamilySize;
    std::string Occupation;
    int Income;
};

class CalculateOccupationStats {
public:
    std::unordered_map<std::string, std::tuple<int, int, int, int>> CalculateStats(const std::vector<std::string>& censusData, const std::vector<std::string>& uniqueOccupations) {
        std::unordered_map<std::string, std::tuple<int, int, int, int>> stats;

        for (const auto& occupation : uniqueOccupations) {
            std::vector<CensusData> data;

            for (const auto& cd : censusData) {
                std::stringstream ss(cd);
                std::string item;
                std::vector<std::string> items;

                while (std::getline(ss, item, ',')) {
                    items.push_back(item);
                }

                if (items[2] == occupation) {
                    CensusData entry;
                    entry.FamilySize = std::stoi(items[1]);
                    entry.Income = std::stoi(items[3]);
                    data.push_back(entry);
                }
            }

            if (!data.empty()) {
                int minIncome = std::min_element(data.begin(), data.end(), [](const CensusData& a, const CensusData& b) { return a.Income < b.Income; })->Income;
                int maxIncome = std::max_element(data.begin(), data.end(), [](const CensusData& a, const CensusData& b) { return a.Income < b.Income; })->Income;
                int minFamilySize = std::min_element(data.begin(), data.end(), [](const CensusData& a, const CensusData& b) { return a.FamilySize < b.FamilySize; })->FamilySize;
                int maxFamilySize = std::max_element(data.begin(), data.end(), [](const CensusData& a, const CensusData& b) { return a.FamilySize < b.FamilySize; })->FamilySize;

                stats[occupation] = std::make_tuple(minIncome, maxIncome, minFamilySize, maxFamilySize);
            } else {
                // If there are no data entries for this occupation, we can set default values or skip it
                stats[occupation] = std::make_tuple(0, 0, 0, 0);
            }
        }

        return stats;
    }
};

int main() {
    int numOfCensus;
    std::cin >> numOfCensus;
    std::cin.ignore();

    std::vector<std::string> censusData(numOfCensus);
    for (int i = 0; i < numOfCensus; ++i) {
        std::getline(std::cin, censusData[i]);
    }

    int numOfUniqueOccupations;
    std::cin >> numOfUniqueOccupations;
    std::cin.ignore();

    std::vector<std::string> uniqueOccupations(numOfUniqueOccupations);
    for (int i = 0; i < numOfUniqueOccupations; ++i) {
        std::getline(std::cin, uniqueOccupations[i]);
    }

    CalculateOccupationStats statsCalculator;
    auto stats = statsCalculator.CalculateStats(censusData, uniqueOccupations);

    for (const auto& occupation : uniqueOccupations) {
        const auto& stat = stats[occupation];
        std::cout << occupation << ": (" 
                  << std::get<0>(stat) << ", " 
                  << std::get<1>(stat) << ", " 
                  << std::get<2>(stat) << ", " 
                  << std::get<3>(stat) << ")" << std::endl;
    }

    return 0;
}
