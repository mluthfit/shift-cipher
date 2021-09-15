/*
Nama  : Muhammad Luthfi Taufiqurrahman
NPM   : 140810190036
Kelas : B
*/

#include <iostream>
#include <string>
#include <stdlib.h>

int modDecrypt(int num) {
  while (num < 0) {
    num += 26;
  }

  return num % 26;
}

std::string encryp(std::string plainText, int key) {
  std::string cipherText = "";
  
  for (int i = 0; i < plainText.length(); i++) {
    int baseChar = 0;
    if (plainText[i] >= 97 && plainText[i] <= 122) baseChar = 97;
    else if (plainText[i] >= 65 && plainText[i] <= 90) baseChar = 65;

    
    if (baseChar != 0) {
      // Shift Cipher Algorithm
      int Z = (int)plainText[i] - baseChar;
      int shift = (Z + key) % 26;

      int addBase = shift + baseChar;
      cipherText += (char)addBase;
    } else {
      cipherText += plainText[i];
    }
  }

  return cipherText;
}

std::string decryp(std::string cipherText, int key) {
  std::string plainText = "";
  
  for (int i = 0; i < cipherText.length(); i++) {
    int baseChar = 0;
    if (cipherText[i] >= 97 && cipherText[i] <= 122) baseChar = 97;
    else if (cipherText[i] >= 65 && cipherText[i] <= 90) baseChar = 65;

    
    if (baseChar != 0) {
      // Shift Cipher Algorithm
      int Z = (int)cipherText[i] - baseChar;
      int shift = modDecrypt(Z - key);

      int addBase = shift + baseChar;
      plainText += (char)addBase;
    } else {
      plainText += cipherText[i];
    }
  }

  return plainText;
}

int main(int argc, char *argv[]) {
  std::string name;
  int key;
  char loop;

  do {
    std::system("cls");
    std::cout << "Nama      : "; std::getline(std::cin >> std::ws, name);
    std::cout << "Key       : "; std::cin >> key;

    std::string encryption = encryp(name, key);
    std::string decryption = decryp(encryption, key);


    std::cout << "Enkripsi  : " << encryption << '\n';
    std::cout << "Dekripsi  : " << decryption << '\n';

    do {
      std::cout << "Apakah akan ingin mengulang? (Y/N) : "; std::cin >> loop;
    } while (loop != 'Y' && loop != 'y' && loop != 'N' && loop != 'n');


  } while(loop == 'Y' || loop == 'y');
  
  return 0;
}