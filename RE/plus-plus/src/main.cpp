#include<iostream>
#include<string>
using namespace std;

void check_password(string password) {
    if (password.length() != 32) {
        std::cout << "[-] Wrong password length!" << std::endl;
        return;
    }

    string part_one = "VSL{";
    string part_two = "}";
    string mid_part = "4n_3x4mple_";

    if (password.substr(0, 4) != part_one) {
        std::cout << "[-] Wrong password!" << std::endl;
        return;
    }

    if (password.substr(31, 1) != part_two) {
        std::cout << "[-] Wrong password!" << std::endl;
        return;
    }

    if (password.substr(4, 11) != mid_part) {
        std::cout << "[-] Wrong password!" << std::endl;
        return;
    }

    if (password[21] != 'r' || password[27] != 'a' || password[16] != '4' || password[24] != 'f' || password[17] != 's' || password[18] != '5' || password[28] != 'c' || password[19] != 'w' || password[20] != '0' || password[22] != 'd' || password[30] != '9' || password[15] != 'p' || password[23] != '_' || password[29] != '0' || password[25] != '4' || password[26] != 'k')
    {
        std::cout << "[-] Wrong password!" << std::endl;
        return;
    }

    std::cout << "[+] Correct password!" << std::endl;
    return;
}

int main() {
    string password;
    std::cout << "Hello, World!" << std::endl;
    std::cout << "[+] Password: " << std::endl;
    std::cout << ">> ";
    std::cin >> password;
    check_password(password);
    return 0;
}
