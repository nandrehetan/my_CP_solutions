#include <iostream>
#include <string>

bool is_lucky(int X) {
    std::string X_str = std::to_string(X); 
    for (char ch : X_str) { 
        if (ch == '7') { 
            return true;
        }
    }
    return false; 
}

int main() {
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        int X;
        std::cin >> X;
        std::cout << (is_lucky(X) ? "YES" : "NO") << std::endl;
    }
    return 0;
}
