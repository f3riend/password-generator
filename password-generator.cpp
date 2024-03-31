#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string generate(int length)
{
    std::string characters = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    string password;

    for (int i = 0; i < length; i++)
    {
        password += characters[rand() % characters.size()];
    }

    return password;
}

int main(int argc, char const *argv[])
{
    srand(time(nullptr));

    int length;
    cout << "Enter password length: ";
    cin >> length;

    cin.ignore();

    while (true)
    {
        cout << "\nPress Enter to generate a new password (or enter a new length to change password length, 'q' to quit): ";
        string input;
        getline(cin, input);

        if (input.empty())
        {
            string generatedPassword = generate(length);
            cout << generatedPassword << endl;
        }
        else if (input == "q" || input == "Q")
        {
            cout << "Exiting..." << endl;
            break;
        }
        else
        {
            
            int newLength = stoi(input);
            if (newLength > 0)
            {
                length = newLength;
                cout << "Password length updated to " << length << endl;
            }
            else
            {
                cout << "Invalid length. Please enter a positive integer." << endl;
            }
        }
    }

    return 0;
}
