#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int RSA(int base, int exponent, int modulus)
{
    if (modulus == 1)
    {
        return 0;
    }
    int result = 1;
    base = base % modulus;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1; /* So, exponent >> 1 means shifting all bits in the variable exponent to the right by one position.
         This is equivalent to dividing the value of exponent by 2, discarding any remainder,
         and storing the result back into exponent. It's essentially a quick way to perform integer division by 2.
        For example, if exponent initially holds the value 8(binary : 1000), after exponent = exponent >> 1;,
         exponent will hold the value 4(binary : 0100). */
        base = (base * base) % modulus;
    }
    return result;
}

main()
{
    int privateKeyExponent = 53;
    int modulus = 299;

    ifstream txtFile("encrypted-text.txt");
    ofstream decryptedFile("decrypted-text.txt");

    vector<int> encryptedCharacters;
    int input;
    while (txtFile >> input)
    {
        encryptedCharacters.push_back(input);
    }

    for (int character : encryptedCharacters)
    {
        int resultingNumber = RSA(character, privateKeyExponent, modulus);
        decryptedFile << static_cast<char>(resultingNumber);
    }
    return 0;
}