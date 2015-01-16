#include <iostream>
#include <future>
#include <vector>

bool isPrime(int num) {
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    std::vector<std::future<bool>> futures;
    for (int i = 2; i <= 1000; ++i) {
        auto f = std::async(std::launch::async, isPrime, i);
        futures.push_back(std::move(f));
    }
    for (int i = 0; i < 999; ++i) {
        if (futures[i].get() == true) {
            std::cout << i+1 << " is prime" << std::endl;
        }
    }
    return 0;
}
