#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Resource {
public:
    string resourceName;
    int quantity;
    double unitCost;
    Resource() { }  // default constructor
    Resource(string resourceName, int quantity, double unitCost)
         { 
                this->resourceName = resourceName;
                this->quantity = quantity;
                this->unitCost = unitCost;
         }
};

class Requisition {
private:
    map<string, Resource> resourceDatabase;
    vector<Resource> finalRequisition;

public:
    Requisition(vector<Resource> resources) {
        for(auto &resource : resources) {
            resourceDatabase[resource.resourceName] = resource;
        }
    }

    void addResource(string resourceName, int quantity) {
        auto found = resourceDatabase.find(resourceName);
        if (found != resourceDatabase.end()) {
            int addQuantity = min(quantity, found->second.quantity);
            found->second.quantity -= addQuantity;

            auto it = find_if(finalRequisition.begin(), finalRequisition.end(),
                              [&resourceName](const Resource& r) {
                                    return r.resourceName == resourceName;
                              });
                              
            if (it != finalRequisition.end()) {
                it->quantity += addQuantity;
            } else {
                finalRequisition.emplace_back(resourceName, addQuantity, found->second.unitCost);
            }
        }
        else {
            //cout << "Resource '" << resourceName << "' not found in database." << endl;
        }
    }

    void removeResource(string resourceName, int quantity) {
        auto it = find_if(finalRequisition.begin(), finalRequisition.end(),
                          [&resourceName](const Resource& r) {
                                return r.resourceName == resourceName;
                          });
                              
        if (it != finalRequisition.end()) {
            int removeQuantity = min(quantity, it->quantity);
            it->quantity -= removeQuantity;

            auto found = resourceDatabase.find(resourceName);
            if (found != resourceDatabase.end()) {
                found->second.quantity += removeQuantity;
            } else {
                resourceDatabase[resourceName] = Resource(resourceName, removeQuantity, it->unitCost);
            }

            if (it->quantity == 0) {
                finalRequisition.erase(it);
            }
        } else {
            //cout << "Resource '" << resourceName << "' not found in requisition." << endl;
        }
    }

    vector<Resource> getResources() {
        sort(finalRequisition.begin(), finalRequisition.end(),
              [](const Resource& a, const Resource& b) {
                    return a.resourceName < b.resourceName;
              });
        return finalRequisition;
    }

    double getTotalCost() {
        double totalCost = 0;
        for(const auto& resource : finalRequisition) {
            totalCost += resource.quantity * resource.unitCost;
        }
        return totalCost;
    }
};

int main() {
    int n;
    cin >> n;

    vector<Resource> resources;
    string resourceInput;
    for (int i = 0; i < n; i++) {
        string resourceName;
        int quantity;
        double unitCost;

        cin >> resourceName >> quantity >> unitCost;
        Resource res = Resource(resourceName, quantity, unitCost);
        resources.push_back(res);
    }

    Requisition requisition(resources);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        string action, resourceName;
        int quantity;

        cin >> action >> resourceName >> quantity;

        if (action == "Add") {
            requisition.addResource(resourceName, quantity);
        }
        else if (action == "Remove") {
            requisition.removeResource(resourceName, quantity);
        }
    }

    double totalCost = requisition.getTotalCost();
    cout << "Total Cost: " << totalCost << endl;

    vector<Resource> finalRequisition = requisition.getResources();
    cout << "Resources in Requisition:" << endl;
    for (const auto& resource : finalRequisition) {
        cout << "Resource Name: " << resource.resourceName << ", Quantity: " << resource.quantity << ", Unit Cost: " << resource.unitCost << endl;
    }

    return 0;
}
