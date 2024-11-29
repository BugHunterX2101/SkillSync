#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <map>

class User {
public:
    std::string name;
    std::string location;
    std::vector<std::string> skillsOffered;
    std::vector<std::string> skillsWanted;
    std::string availability;

    User(std::string n, std::string loc, std::vector<std::string> offered, std::vector<std::string> wanted, std::string avail)
        : name(n), location(loc), skillsOffered(offered), skillsWanted(wanted), availability(avail) {}
};

class SkillShareHub {
private:
    std::vector<User> users;

public:
    void addUser (User user) {
        users.push_back(user);
    }

    std::vector<User> matchUsers(const std::string& skill) { // Use const reference for efficiency
        std::vector<User> matches;
        for (const auto& user : users) {
            if (std::find(user.skillsOffered.begin(), user.skillsOffered.end(), skill) != user.skillsOffered.end()) {
                matches.push_back(user);
            }
        }
        return matches;
    }
};

int main() {
    SkillShareHub hub;
    hub.addUser (User("Alice", "New York", {"Cooking", "Photography"}, {"Gardening"}, "Weekends"));
    hub.addUser (User("Bob", "New York", {"Gardening"}, {"Cooking"}, "Weekdays"));

    std::string skillToMatch = "Cooking";
    std::vector<User> matchedUsers = hub.matchUsers(skillToMatch);

    std::cout << "Users offering " << skillToMatch << ":\n";
    for (const auto& user : matchedUsers) {
        std::cout << user.name << " from " << user.location << "\n";
    }

    return 0;
}