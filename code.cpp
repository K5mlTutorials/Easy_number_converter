#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <conio.h> 

using namespace std;

int toDecimal(const string& number, int base) {
    int result = 0;
    stringstream ss;
    ss << std::hex << number;
    if (base == 2) {
        result = stoi(number, nullptr, 2);
    }
    else if (base == 8) {
        result = stoi(number, nullptr, 8);
    }
    else if (base == 10) {
        result = stoi(number, nullptr, 10);
    }
    else if (base == 16) {
        result = stoi(number, nullptr, 16);
    }
    return result;
}

void displayConversions(int decimalValue) {
    cout << "BIN (2): " << bitset<32>(decimalValue) << endl;
    cout << "OCT (8) : " << oct << decimalValue << endl;
    cout << "DEC (10): " << dec << decimalValue << endl;
    cout << "HEX (16): " << hex << uppercase << decimalValue << endl;
}

int main()
{
    system("cls"); //can be changed to system("clear"); on other OS
    int base;
    string inputNumber;

    cout << "select the number system of your number (2(bin), 8(oct), 10(dec), 16(hex)): ";
    cin >> base;

    if (base != 2 && base != 8 && base != 10 && base != 16) {
        cerr << "wrong number system!" << endl;
        return 1;
    }

    cout << "write the number in " << base << " system: ";
    cin >> inputNumber;

    try {
        int decimalValue = toDecimal(inputNumber, base);
        cout << "\nnumber converts:\n";
        displayConversions(decimalValue);
    }
    catch (...) {
        cerr << "error: wrong number format!" << endl;
    }
    _getch();
    main();
}
