#include <iostream>
#include <deque>
#include <map>
#include <string>

class ViewerCounter {
private:
    int window;
    std::map<std::string, std::deque<int>> counter;

public:
    ViewerCounter(int window) : window(window) {
        counter["guest"] = std::deque<int>();
        counter["follower"] = std::deque<int>();
        counter["subscriber"] = std::deque<int>();
    }

    void join(int t, const std::string& v) {
        counter[v].push_back(t);
    }

    int get_viewers(int t, const std::string& v) {
        int l = t - window;
        int r = t;
        std::deque<int> new_queue;
        int result = 0;

        while (!counter[v].empty()) {
            int time = counter[v].front();
            counter[v].pop_front();

            if (l <= time && time <= r) {
                result++;
            }

            if (l < time) {
                new_queue.push_back(time);
            }
        }

        counter[v] = new_queue;
        return result;
    }
};

int main() {
    ViewerCounter counter(10);
    counter.join(1, "subscriber");
    counter.join(1, "guest");
    counter.join(2, "follower");
    counter.join(2, "follower");
    counter.join(2, "follower");
    counter.join(3, "follower");

    std::cout << counter.get_viewers(10, "subscriber") << std::endl;  // Returns 1
    std::cout << counter.get_viewers(10, "guest") << std::endl;       // Returns 1
    std::cout << counter.get_viewers(10, "follower") << std::endl;    // Returns 4
    std::cout << counter.get_viewers(13, "follower") << std::endl;    // Returns 1

    return 0;
}
