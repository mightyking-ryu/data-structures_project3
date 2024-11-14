#include <random>
#include <vector>
#include <algorithm>
#include <bitset>

#include "rbtree.hpp"
#include "../tests/rbtree_test_util.hpp"

int main(int argc, char *argv[]) {
    std::vector<int> xs{};
    RBTree<int> rbtree{};
    size_t N = 10;

    for (auto i = 1; i <= N; i++)
        xs.emplace_back(i);

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(xs.begin(), xs.end(), g);

    for (auto i : xs) {
        rbtree.insert(i);
        // std::cout << rbtree << '\n';
    }

    // std::cout << (test_left_lean(rbtree) ? "true\n" : "false\n");
    // std::cout << (test_black_balance(rbtree) ? "true\n" : "false\n");

    std::cout << rbtree << '\n';

    std::shuffle(xs.begin(), xs.end(), g);

#if 0
    for (auto i = 0; i < N; i++) {
        rbtree.remove_max();
        std::cout << rbtree << '\n';
    }

    // for (auto i = 0; i < N / 3; i++) {
    //     rbtree.remove_min();
    //     std::cout << rbtree << '\n';
    // }
#else
    for (auto x : xs) {
        std::cout << "try remove " << x << '\n';
        rbtree.remove(x);
        std::cout << rbtree << '\n';
    }
#endif

    return 0;
}
