#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <map>
#include <iomanip>
#include <ctime>
#include <set>

class Claim {
public:
    std::string policyType;
    int claimID;
    std::tm date;
    double amount;

    Claim(const std::string& policyType, int claimID, const std::tm& date, double amount)
        : policyType(policyType), claimID(claimID), date(date), amount(amount) {}
};

class IClaimManagementSystem {
public:
    virtual void AddClaim(const Claim& claim) = 0;
    virtual void RemoveClaim(int claimID) = 0;
    virtual double CalculateTotalClaimAmount() = 0;
    virtual std::vector<Claim> GetClaimsByPolicyType(const std::string& policyType) = 0;
    virtual ~IClaimManagementSystem() = default;
};

class ClaimsManagementSystem : public IClaimManagementSystem {
protected:
    std::vector<Claim> claims;

public:
    ClaimsManagementSystem() = default;

    void AddClaim(const Claim& claim) override {
        claims.push_back(claim);
    }

    void RemoveClaim(int claimID) override {
        claims.erase(std::remove_if(claims.begin(), claims.end(),
            [claimID](const Claim& claim) { return claim.claimID == claimID; }), claims.end());
    }

    double CalculateTotalClaimAmount() override {
        return std::accumulate(claims.begin(), claims.end(), 0.0,
            [](double sum, const Claim& claim) { return sum + claim.amount; });
    }

    std::vector<Claim> GetClaimsByPolicyType(const std::string& policyType) override {
        if (policyType.empty()) {
            return claims;
        } else {
            std::vector<Claim> result;
            std::copy_if(claims.begin(), claims.end(), std::back_inserter(result),
                [&policyType](const Claim& claim) { return claim.policyType == policyType; });
            return result;
        }
    }

    std::set<std::string> GetAllPolicyTypes() {
        std::set<std::string> policyTypes;
        for (const auto& claim : claims) {
            policyTypes.insert(claim.policyType);
        }
        return policyTypes;
    }
};

std::tm ParseDate(const std::string& dateStr) {
    std::tm tm = {};
    std::istringstream ss(dateStr);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    return tm;
}

int main() {
    ClaimsManagementSystem claimsManagementSystem;
    int num;
    std::cin >> num;
    std::cin.ignore();

    std::vector<std::string> inputOrder;

    // Add claims
    for (int i = 0; i < num; i++) {
        std::string input;
        std::getline(std::cin, input);
        std::istringstream iss(input);
        std::string policyType, dateStr;
        int claimID;
        double amount;
        iss >> policyType >> claimID >> dateStr >> amount;

        std::tm date = ParseDate(dateStr);
        claimsManagementSystem.AddClaim(Claim(policyType, claimID, date, amount));
        inputOrder.push_back(policyType);
    }

    int ID;
    std::cin >> ID;
    std::cin.ignore();

    // Remove claim
    claimsManagementSystem.RemoveClaim(ID);

    // Display claims by policy type
    std::set<std::string> displayedPolicyTypes;
    for (const auto& policyType : inputOrder) {
        if (displayedPolicyTypes.find(policyType) == displayedPolicyTypes.end()) {
            auto claims = claimsManagementSystem.GetClaimsByPolicyType(policyType);
            if (!claims.empty()) {
                displayedPolicyTypes.insert(policyType);
                std::cout << policyType << ":\n";
                for (const auto& claim : claims) {
                    char dateBuf[20];
                    strftime(dateBuf, sizeof(dateBuf), "%Y-%m-%d", &claim.date);
                    std::cout << "Claim ID: " << claim.claimID << " Policy Type: " << claim.policyType
                              << " Date: " << dateBuf << " Amount: $" << claim.amount << "\n";
                }
            }
        }
    }

    // Display total claim amount
    std::cout << "Total Claim Amount: $" << std::fixed << std::setprecision(2) << claimsManagementSystem.CalculateTotalClaimAmount() << "\n";

    // Display count of claims by policy type
    std::map<std::string, int> policyTypeCount;
    for (const auto& policyType : inputOrder) {
        auto claims = claimsManagementSystem.GetClaimsByPolicyType(policyType);
        if(claims.empty() || policyTypeCount.find(policyType) != policyTypeCount.end()){
            continue;
        }
        policyTypeCount[policyType]++;
        std::cout << policyType << ": " << claimsManagementSystem.GetClaimsByPolicyType(policyType).size() << "\n";
    }

    return 0;
}
