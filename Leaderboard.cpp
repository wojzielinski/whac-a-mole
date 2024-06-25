#include "Leaderboard.h"
#include <iostream>
#include <algorithm>
// Taken from snake :)

// Constructor - clear, read and sort leaderboard from file
Leaderboard::Leaderboard(const std::string & filename) : FILE(filename)
{
    results.clear();
    read_leaderboard();
    sort_by_points();
}

// Open file containing leaderboard, read results and push them into "results" vector
void Leaderboard::read_leaderboard() {
    std::fstream fs;
    fs.open(FILE,std::fstream::in);
    if(fs.is_open()){
        std::string line;
        Result res;
        std::size_t foundAt;
        while(std::getline(fs, line)){
            if (line.empty()) break;
            foundAt=line.find(' ');
            res.points = stoi(line.substr(0, foundAt), 0, 10);
            res.user = line.substr(foundAt + 1, line.length());
            results.push_back(res);
        }
        fs.close();
    }
}

// Get n-th result as a string
std::string Leaderboard::get_result(int n) {
    if(n >= count_results()) return "-/-";
    std::string resStr;
    return results[n].result_to_string();
}

// Convert Result structure to string
std::string Result::result_to_string() const {
    std::string resStr;
    resStr += std::to_string(points);
    resStr += " ";
    resStr += user;
    return resStr;
}

// Sort leaderboard by points earned
void Leaderboard::sort_by_points() {
    std::sort(results.begin(), results.end(),[](Result & a, Result & b){return a.points>b.points;});
    //sort algorithm docs - https://en.cppreference.com/w/cpp/algorithm/sort
}

// Operator overloading so we can compare Result structures by points
bool Result::operator>(Result & n) const {
    if(this->points > n.points)
        return true;
    return false;
}

// Result constructors
Result::Result(){}
Result::Result(int p, std::string u) {
    points = p;
    user = u;
}

// Add result to results vector, sort it and write to file
void Leaderboard::add_result(int points, std::string user) {
    results.push_back(Result(points, user));
    sort_by_points();
    write_leaderboard();
}

// Count number of results
int Leaderboard::count_results() {
    return results.size();
}

// Write results vector to file
void Leaderboard::write_leaderboard() {
    std::fstream fs;
    fs.open(FILE,std::fstream::out);
    if(fs.is_open()) {
        std::string line;
        for(Result & res : results){
            line = res.result_to_string();
            fs << line;
            fs << std::endl;
        }
    }
}