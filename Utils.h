#pragma once

#include <iostream>

class Utils {
public:
    static Utils* instance() {
        static Utils instance;
        return &instance;
    }

    inline void UpdateProgress(float progress) {
        int barWidth = 70;

        std::cout << "[";
        int pos = barWidth * progress;
        for (int i = 0; i < barWidth; ++i) {
            if (i < pos) std::cout << "=";
            else if (i == pos) std::cout << ">";
            else std::cout << " ";
        }
        std::cout << "] " << int(progress * 100.0) << " %\r";
        std::cout.flush();
    }

private:
    Utils() = default;
    Utils(const Utils&) = delete;
    Utils& operator=(const Utils&) = delete;
    Utils(Utils&&) = delete;
    Utils& operator=(Utils&&) = delete;
    ~Utils() = default;
};
