/*#include <iostream>
#include <string>
#include <unordered_map>

bool canFormPalindrome(const std::string& str) {
    // Folosim un unordered_map pentru a numara de cate ori apare fiecare caracter
    std::unordered_map<char, int> charCount;

    // Numaram de cate ori apare fiecare caracter in sir
    for (char ch : str) {
        charCount[ch]++;
    }

    // Contor pentru numarul de caractere cu aparitii impare
    int oddCount = 0;

    // Verificam numarul de aparitii impare
    for (const auto& pair : charCount) {
        if (pair.second % 2 != 0) {
            oddCount++;
        }
    }

    // Un palindrom poate fi format daca si numai daca avem cel mult un caracter cu aparitii impare
    return oddCount <= 1;
}

int main() {
    std::string str;
    std::cin >> str;

    if (canFormPalindrome(str)) {
        std::cout << "DA" << std::endl;
    }
    else {
        std::cout << "NU" << std::endl;
    }

    return 0;
}*/



#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

pair<bool, string> canFormPalindrome(const string& str) {
    // Folosim un unordered_map pentru a numara de cate ori apare fiecare caracter
    unordered_map<char, int> charCount;

    // Numaram de cate ori apare fiecare caracter în sir
    for (char ch : str) {
        charCount[ch]++;
    }

    // Construim palindromul
    string palindrome;
    char oddChar = '\0'; // Caracterul cu numar impar de aparitii

    // Adaugam caracterele cu aparitii pare de doua ori la palindrom
    for (const auto& pair : charCount) {
        char ch = pair.first;
        int count = pair.second;
        if (count % 2 == 0) {
            palindrome += string(count / 2, ch);
        }
        else {
            if (oddChar == '\0') {
                oddChar = ch; // Retinem primul caracter cu aparitii impare
            }
            else {
                return make_pair(false, ""); // Daca avem mai mult de un caracter cu apariaii impare, nu putem forma palindrom
            }
        }
    }

    // Construim palindromul completand cu caracterele pentru partea opusa
    string secondHalf = palindrome;
    reverse(secondHalf.begin(), secondHalf.end());
    if (oddChar != '\0') {
        palindrome += oddChar;
    }
    palindrome += secondHalf;

    return make_pair(true, palindrome);
}

int main() {
    std::string str;
    std::cin >> str;

    auto result = canFormPalindrome(str);
    if (result.first) {
        cout << "DA" << endl;
        cout << "Palindromul format este: " << result.second << endl;
    }
    else {
        std::cout << "NU" << std::endl;
    }

    return 0;
}

