#include <iostream>
#include <string>
char postion[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
std::string player1;
std::string player2;
char key = 'x';
bool tie = false;
int digit, row, column;

void functionone()
{

    std::cout << std::endl;
    std::cout << postion[0][0] << "   |" << postion[0][1] << "   |" << postion[0][2] << std::endl;
    std::cout << "____|____|____" << std::endl;
    std::cout << postion[1][0] << "   |" << postion[1][1] << "   |" << postion[1][2] << std::endl;
    std::cout << "____|____|____" << std::endl;
    std::cout << postion[2][0] << "   |" << postion[2][1] << "   |" << postion[2][2] << std::endl;
    std::cout << "____|____|____" << std::endl;
};
void functionTwo()
{
    if (key == 'x')
    {
        std::cout << player1 << " enter x or o postion :";
        std::cin >> digit;
    }
    if (key == '0')
    {
        std::cout << player2 << " enter x or o postion :";
        std::cin >> digit;
    }
    if (digit == 1)
    {
        row = 0;
        column = 0;
    }
    else if (digit == 2)
    {
        row = 0;
        column = 1;
    }
    else if (digit == 3)
    {
        row = 0;
        column = 2;
    }
    else if (digit == 4)
    {
        row = 1;
        column = 0;
    }
    else if (digit == 5)
    {
        row = 1;
        column = 1;
    }
    else if (digit == 6)
    {
        row = 1;
        column = 2;
    }
    else if (digit == 7)
    {
        row = 2;
        column = 0;
    }
    else if (digit == 8)
    {
        row = 2;
        column = 1;
    }
    else if (digit == 9)
    {
        row = 2;
        column = 2;
    }
     else if (digit < 1 || digit > 9)
    {
        std::cout << "invalid input !!! \n";
        std::cout<< "Please enter an input form 1 to 9" << std::endl;
    }
    if (key == 'x' && postion[row][column] != 'x' && postion[row][column] != '0')
    {
        postion[row][column] = 'x';
        key = '0';
        // functionTwo();
    }else if (key == '0' && postion[row][column] != 'x' && postion[row][column] != '0')
    {
        postion[row][column] = '0';
        key = 'x';
        // functionTwo();
    }
    else if(postion[row][column] == 'x' || postion[row][column] == '0')
    {
        std::cout << "Position already taken! Please choose another." << std::endl;
        functionTwo();
    }
}
bool functionthree()
{
    for (int i = 0; i < 3; i++)
    {
        if (postion[i][0] == postion[i][1] && postion[i][1] == postion[i][2] || postion[0][i] == postion[1][i] && postion[1][i] == postion[2][i])
        {
            return true;
        }
    }
    if (postion[0][0] == postion[1][1] && postion[0][0] == postion[2][2] || postion[0][2] == postion[1][1] && postion[0][2] == postion[2][0])
    {
        return true;
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
        {
            if (postion[i][j] != 'x' && postion[i][j] != '0')
            {
                return false;
            }
        }
    }
    tie = true;
    return false;
}
int main()
{
    std::cout << "Enter player1 name :";
    std::cin >> player1;
    std::cout << "Enter player2 name :";
    std::cin >> player2;
    std::cout << "___Welcome to the tick tack toe game___" << std::endl;
    std::cout << "    |     |    " << std::endl;
    std::cout << "____|_____|____" << std::endl;
    std::cout << "    |     |    " << std::endl;
    std::cout << "____|_____|____" << std::endl;
    std::cout << "    |     |    " << std::endl;
    std::cout << "    |     |    " << std::endl;
    std::cout << "To input your X and 0 at various positions!" << std::endl;
    std::cout << "Please use the numberings" << std::endl;
    std::cout << std::endl;
    while (!functionthree())
    {
        functionone();
        functionTwo();
        functionthree();
    }
    if (key == 'x' && tie == false)
    {
        std::cout <<"Congratulations!! "<< player2 << " Wins!!" << std::endl;
    }
    else if (key == '0' && tie == false)
    {
        std::cout <<"Congratulations!! "<< player1 << " Wins!!" << std::endl;
    }
    else
    {
        std::cout << "You Tied !!" << std::endl;
    }
   functionone();
}