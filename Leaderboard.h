#ifndef WHAC_A_RAT_LEADERBOARD_H
#define WHAC_A_RAT_LEADERBOARD_H
#include <vector>
#include <string>
#include <fstream>

struct Result {
    int points;
    std::string user;
    bool operator>(Result & n) const;
    Result();
    Result(int p, std::string u);
    [[nodiscard]] std::string result_to_string() const;
};

class Leaderboard {
    const std::string FILE;
    std::vector<Result> results;

    void read_leaderboard();
    void write_leaderboard();
    void sort_by_points();
    int count_results();
public:
    explicit Leaderboard(const std::string & filename);
    std::string get_result(int n);
    void add_result(int points, std::string user);
};


#endif //WHAC_A_RAT_LEADERBOARD_H