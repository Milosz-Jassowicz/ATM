
/***

    C++ >= 17

***/


#include <filesystem>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <math.h>
#include <conio.h>
#include <string>
#include <time.h>
#include <map>
#include <fstream>
#include <vector>


using namespace std;
namespace fs = std::filesystem;


//  Sizes
const unsigned int GUIX = 47;
const unsigned int GUIY = 20;


//  Corners
const char cr1 = (char)(218);
const char cr2 = (char)(191);
const char cr3 = (char)(192);
const char cr4 = (char)(217);


///---------------------------------GUI TEMPLATES--------------------------------------------------------------------------------------------------------------------------------------------------

char EmptyGUI[GUIY][GUIX] =
{
//   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35  36  37  38  39  40  41  42  43  44  45  46  47
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',    // 0
    ' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',    // 1
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 2
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 3
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 4
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 5
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 6
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 7
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 8
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 9
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 10
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 11
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 12
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 13
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 14
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 15
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 16
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 17
    ' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',    // 18
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '     // 19
};

char StartGUI[GUIY][GUIX] =
{
//   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35  36  37  38  39  40  41  42  43  44  45  46  47
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',    // 0
    ' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',    // 1
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 2
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ','#','#','#','#','#',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 3
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 4
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 5
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 6
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 7
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 8
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 9
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 10
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 11
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 12
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 13
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 14
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 15
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 16
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 17
    ' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',    // 18
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '     // 19
};

char BankGUI[GUIY][GUIX] =
{
//   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35  36  37  38  39  40  41  42  43  44  45  46  47
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',    // 0
    ' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',    // 1
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 2
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ','#','#','#',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 3
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#','#',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 4
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ','#','#','#','#','#',' ','#',' ','#',' ','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 5
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 6
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 7
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 8
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 9
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 10
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 11
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 12
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 13
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 14
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 15
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 16
    ' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',    // 17
    ' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',    // 18
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '     // 19
};


///---------------------------------GLOBAL VALUES--------------------------------------------------------------------------------------------------------------------------------------------------

string Language = "EN";
fstream Account;
fstream Card;
fstream Casket;
string CardsPath = "Bank\\Cards";
string AccountsPath = "Bank\\Accounts";
string CasketPath = "Casket.txt";
string CurrentPath;
string CurrentAccount;  //  Only for card operation in Bank
string createdAccount;  //  Only to login to new account


///---------------------------------TEXTS----------------------------------------------------------------------------------------------------------------------------------------------------------

map<string, string> insertCardText;
map<string, string> adminText;
map<string, string> backText;
map<string, string> exitText;
map<string, string> finishText;
map<string, string> depositText;
map<string, string> cardNumberText;
map<string, string> depositMoneyText;
map<string, string> insertMoneyText;
map<string, string> moneyInsertedText;
map<string, string> moneyInsertErrorText;
map<string, string> endingText;
map<string, string> TakeOutCardText;
map<string, string> withdrawText;
map<string, string> customText;
map<string, string> withdrawInfoText;
map<string, string> withdrawAmount;
map<string, string> wrongNumberText;
map<string, string> emptyText;
map<string, string> successText;
map<string, string> successDescText;
map<string, string> failureText;
map<string, string> failureDescText;
map<string, string> failureDescText2;
map<string, string> casketMoneyErrorText;


map<string, string> bankText;
map<string, string> enterText;
map<string, string> passwordText;
map<string, string> insertPasswordText;
map<string, string> wrongPasswordText;
map<string, string> accountText;
map<string, string> casketText;
map<string, string> backToBankText;
map<string, string> setMoneyText;
map<string, string> moneySetText;
map<string, string> moneySetErrorText;
map<string, string> insertAccountNumberText;
map<string, string> loginText;
map<string, string> cardsMenuText;
map<string, string> moneyText;
map<string, string> deleteText;
map<string, string> setAccountMoneyText;
map<string, string> moneySetedText;
map<string, string> notEnoughMoneyText;
map<string, string> deleteConfirmText;
map<string, string> cancelText;
map<string, string> sureText;
map<string, string> accountDeletedText;
map<string, string> accountNotDeletedText;
map<string, string> adCardText;
map<string, string> generateCardText;
map<string, string> generateText;
map<string, string> deleteCardText;
map<string, string> selectCardText;
map<string, string> insertCardNumberText;
map<string, string> cardGeneratedText;
map<string, string> cardGenerationFailedText;
map<string, string> cardDeletedText;
map<string, string> cardDeletionFailedText;
map<string, string> cardFinishText;
map<string, string> createText;
map<string, string> WIPAccountText;
map<string, string> AccountText;
map<string, string> FailedAccountText;


///---------------------------------EMPTY FUNCTIONS------------------------------------------------------------------------------------------------------------------------------------------------

void ChangeGUIToStart();
void ChangeGUIToInsertCard();
void PlaceholderAction();
void PlaceholderAction2();
void CardInput();
void PasswordInput();
bool CheckForAccount(string);


///---------------------------------MAIN CLASSES---------------------------------------------------------------------------------------------------------------------------------------------------

class Box{
protected:
    map<string, string> text;
    map<string, string> placeholderText;
    string type;
    Box *T, *R, *B, *L;
    bool centered, visible, secret, frame, selected;
    unsigned int startX, startY, lenX, lenY;
    void (*ButtonAction)();
    void (*ButtonAction2)(string);
    void (*TextLabelAction)(string);

public:
    char** Out;

    Box(){}

    virtual Box* Switch(char side){}

    virtual void setSelect(bool isSelected){}

    virtual string getText(){}

    virtual string getInputedText(){}

    virtual void setText(map<string, string> txt){}

    virtual void inputText(char c){}

    virtual void subInputText(){}

    virtual void clearInput(){}

    virtual void setOutput(){}

    virtual void setOutputText(){}

    virtual void printBox(){}

    virtual int getStartX(){}

    virtual int getStartY(){}

    virtual int getLen(){}

    virtual bool isVisible(){}

    virtual void setVisible(bool _visible){}

    virtual void setT(Box *box){}

    virtual void setR(Box *box){}

    virtual void setB(Box *box){}

    virtual void setL(Box *box){}

    virtual void setPlaceholderText(string placeholder){}

    virtual string getType(){}

    virtual void setButtonAction2(){}

    virtual void doAction(){}

    virtual void setA2(){}

    virtual ~Box(){
        L = nullptr;
        R = nullptr;
        T = nullptr;
        B = nullptr;

        if (Out != nullptr) {
            for (unsigned int i = 0; i < lenY; ++i) {
                delete Out[i];
                Out[i] = nullptr;
            }
            delete[] Out;
            Out = nullptr;
        }
    }
};

class Button : public Box{
private:
    string smallPlaceholderText = "";
    bool a2;
public:
    Button(unsigned int sx,
            unsigned int sy,
            unsigned int lX,
            bool centeredText = true,
            Box* Top = nullptr,
            Box* Right = nullptr,
            Box* Bottom = nullptr,
            Box* Left = nullptr,
            bool _visible = true,
            bool _secret = false,
            bool haveFrame = true)
    {
        a2 = false;
        type = "Button";

        visible = _visible;
        secret = _secret;
        frame = haveFrame;
        selected = false;

        T = Top;
        R = Right;
        B = Bottom;
        L = Left;
        centered = centeredText;

        startX = sx;
        startY = sy;
        lenX = lX;
        lenY = 3;

        Out = new char*[lenY];
        for(unsigned int i=0; i<lenY; i++)
            Out[i] = new char[lenX];
        setOutput();
    }

    Box* Switch(char side){
        switch(side){
        case 'T':
            if(T != nullptr && T->isVisible())
                return T;
            else
                return this;
        case 'R':
            if(R != nullptr && R->isVisible())
                return R;
            else
                return this;
        case 'B':
            if(B != nullptr && B->isVisible())
                return B;
            else
                return this;
        case 'L':
            if(L != nullptr && L->isVisible())
                return L;
            else
                return this;
        default:
            cout<<"ERROR 404 - NO SIDE AS "<<side<<"!"<<endl;
            return this;
        }
    }

    void setSelect(bool isSelected){
        selected = isSelected;
    }

    string getText(){
        return text[Language];
    }

    void setText(map<string, string> txt){
        text = txt;
        setOutputText();
    }

    void setPlaceholderText(string placeholder){
        smallPlaceholderText = placeholder;
    }

    void setOutput(){
        if (Out != nullptr) {
            for (unsigned int i = 0; i < lenY; i++) {
                if (Out[i] != nullptr) {
                    delete[] Out[i];
                    Out[i] = nullptr;
                }
            }
        }
        delete[] Out;
        Out = nullptr;

        Out = new char*[lenY];
        for(unsigned int i=0; i<lenY; i++){
            Out[i] = new char[lenX];
            for(unsigned int j=0; j<lenX; j++){
                if(i==0){
                    if(frame){
                        if(j == 0)
                            Out[i][j] = cr1;
                        else if(j == lenX-1)
                            Out[i][j] = cr2;
                        else{
                            if(secret){
                                if((lenX-j)%2==1)
                                    Out[i][j] = '-';
                                else
                                    Out[i][j] = ' ';
                            }
                            else
                                Out[i][j] = '-';
                        }
                    }
                    else{
                        Out[i][j] = ' ';
                    }
                }
                else if(i==2){
                    if(frame){
                        if(j == 0)
                            Out[i][j] = cr3;
                        else if(j == lenX-1)
                            Out[i][j] = cr4;
                        else{
                            if(secret){
                                if((lenX-j)%2==1)
                                    Out[i][j] = '-';
                                else
                                    Out[i][j] = ' ';
                            }
                            else
                                Out[i][j] = '-';
                        }
                    }
                    else{
                        Out[i][j] = ' ';
                    }
                }
                else{
                    if(j == 0 || j == lenX-1){
                        if(secret || !frame)
                            Out[i][j] = ' ';
                        else
                            Out[i][j] = '|';
                    }
                    else
                        Out[i][j] = ' ';
                }
            }
        }
        setOutputText();
    }

    void setOutputText(){
        int i=0;
        string txt = text[Language], placeholderTxt = smallPlaceholderText;
        int len = txt.length();
        int margin = round((lenX-4 - len)/2);

        for(unsigned int j=2; j<lenX-2; j++)
            Out[1][j] = ' ';

        if(len>0){
            if(centered){
                for(unsigned int j=2+margin; j<lenX-2; j++){
                    if(i<len){
                        Out[1][j] = txt[i];
                        i++;
                    }
                    else
                        Out[1][j] = ' ';
                }
            }
            else{
                for(int j = 2; j<lenX-3; j++){
                    if(i<len){
                        Out[1][j] = txt[i];
                        i++;
                    }
                    else
                        Out[1][j] = ' ';
                }
            }
        }
        else{
            len = placeholderTxt.length();
            if(centered){
                for(unsigned int j=2+margin; j<lenX-2; j++){
                    if(i<len){
                        Out[1][j] = placeholderTxt[i];
                        i++;
                    }
                }
            }
            else{
                for(int j = 2; j<lenX-3; j++){
                    if(i<len){
                        Out[1][j] = placeholderTxt[i];
                        i++;
                    }
                }
            }
        }
    }

    void printBox(){
        if(visible){
            cout << "\033[" << startY << ";" << startX << "H";
            cout << "\033[7m";
            if(selected)
                cout << "\033[44m";
            for(unsigned int i=0; i<lenY; i++){
                for(unsigned int j=0; j<lenX; j++){
                    cout << Out[i][j];
                }
                cout << "\033[1B" << "\033[" << lenX << "D";
            }
            cout << "\033[0m";
        }
    }

    int getStartX(){
        return startX;
    }

    int getStartY(){
        return startY;
    }

    int getLen(){
        return lenX;
    }

    bool isVisible(){
        return visible;
    }

    void setVisible(bool _visible){
        visible = _visible;
    }

    void setT(Box *box){
        T = box;
    }

    void setR(Box *box){
        R = box;
    }

    void setB(Box *box){
        B = box;
    }

    void setL(Box *box){
        L = box;
    }

    string getType(){
        return type;
    }

    void setButtonAction(void (*newAction)()){
        ButtonAction = newAction;
    }

    void setButtonAction2(void (*newAction)(string)){
        ButtonAction2 = newAction;
    }

    void setA2(bool a){
        a2 = a;
    }

    void doAction(){
        if(a2){
            doAction2();
            return;
        }

        ButtonAction();
    }

    void doAction2(){
        ButtonAction2(smallPlaceholderText);
    }

    ~Button(){
        L = nullptr;
        R = nullptr;
        T = nullptr;
        B = nullptr;

        if (Out != nullptr) {
            for (unsigned int i = 0; i < lenY; ++i) {
                delete[] Out[i];
                Out[i] = nullptr;
            }
            delete[] Out;
            Out = nullptr;
        }
    }
};

class TextLabel : public Box{
private:
    string inputedText;
public:
    TextLabel(unsigned int sx,
            unsigned int sy,
            unsigned int lX,
            bool centeredText = true,
            Box* Top = nullptr,
            Box* Right = nullptr,
            Box* Bottom = nullptr,
            Box* Left = nullptr,
            bool _visible = true,
            bool _secret = false,
            bool haveFrame = true)
    {
        type = "TextLabel";

        visible = _visible;
        secret = _secret;
        frame = haveFrame;
        selected = false;

        T = Top;
        R = Right;
        B = Bottom;
        L = Left;
        centered = centeredText;

        startX = sx;
        startY = sy;
        lenX = lX;
        lenY = 3;

        Out = new char*[lenY];
        for(unsigned int i=0; i<lenY; i++)
            Out[i] = new char[lenX];
        setOutput();
    }

    Box* Switch(char side){
        switch(side){
        case 'T':
            if(T != nullptr && T->isVisible())
                return T;
            else
                return this;
        case 'R':
            if(R != nullptr && R->isVisible())
                return R;
            else
                return this;
        case 'B':
            if(B != nullptr && B->isVisible())
                return B;
            else
                return this;
        case 'L':
            if(L != nullptr && L->isVisible())
                return L;
            else
                return this;
        default:
            cout<<"ERROR 404 - NO SIDE AS "<<side<<"!"<<endl;
            return this;
        }
    }

    void setSelect(bool isSelected){
        selected = isSelected;
    }

    string getText(){
        return text[Language];
    }

    string getInputedText(){
        return inputedText;
    }

    void inputText(char c){
        inputedText+=c;
        setOutputText();
    }

    void subInputText(){
        inputedText.pop_back();
        setOutputText();
    }

    void clearInput(){
        inputedText = "";
    }

    void setText(map<string, string> txt){
        text = txt;
    }

    void setOutput(){
        if (Out != nullptr) {
            for (unsigned int i = 0; i < lenY; i++) {
                if (Out[i] != nullptr) {
                    delete[] Out[i];
                    Out[i] = nullptr;
                }
            }
        }
        delete[] Out;

        Out = new char*[lenY];
        for(unsigned int i=0; i<lenY; i++){
            Out[i] = new char[lenX];
            for(unsigned int j=0; j<lenX; j++){
                if(i==0){
                    if(frame){
                        if(j == 0)
                            Out[i][j] = cr1;
                        else if(j == lenX-1)
                            Out[i][j] = cr2;
                        else{
                            if(secret){
                                if((lenX-j)%2==1)
                                    Out[i][j] = '-';
                                else
                                    Out[i][j] = ' ';
                            }
                            else
                                Out[i][j] = '-';
                        }
                    }
                    else{
                        Out[i][j] = ' ';
                    }
                }
                else if(i==2){
                    if(frame){
                        if(j == 0)
                            Out[i][j] = cr3;
                        else if(j == lenX-1)
                            Out[i][j] = cr4;
                        else{
                            if(secret){
                                if((lenX-j)%2==1)
                                    Out[i][j] = '-';
                                else
                                    Out[i][j] = ' ';
                            }
                            else
                                Out[i][j] = '-';
                        }
                    }
                    else{
                        Out[i][j] = ' ';
                    }
                }
                else{
                    if(j == 0 || j == lenX-1){
                        if(secret || !frame)
                            Out[i][j] = ' ';
                        else
                            Out[i][j] = '|';
                    }
                    else
                        Out[i][j] = ' ';
                }
            }
        }
        setOutputText();
    }

    void setOutputText(){
        int i=0;
        string placeholderTxt = placeholderText[Language];
        int len = inputedText.length();
        int margin = round((lenX-4 - len)/2);

        for(unsigned int j=2; j<lenX-2; j++)
            Out[1][j] = ' ';

        if(len>0){
            if(centered){
                for(unsigned int j=2+margin; j<lenX-2; j++){
                    if(i<len){
                        Out[1][j] = inputedText[i];
                        i++;
                    }
                    else
                        Out[1][j] = ' ';
                }
            }
            else{
                for(int j = 2; j<lenX-3; j++){
                    if(i<len){
                        Out[1][j] = inputedText[i];
                        i++;
                    }
                    else
                        Out[1][j] = ' ';
                }
            }
        }
        else{
            len = placeholderTxt.length();
            if(centered){
                for(unsigned int j=2+margin; j<lenX-2; j++){
                    if(i<len){
                        Out[1][j] = placeholderTxt[i];
                        i++;
                    }
                }
            }
            else{
                for(int j = 2; j<lenX-3; j++){
                    if(i<len){
                        Out[1][j] = placeholderTxt[i];
                        i++;
                    }
                }
            }
        }
    }

    void printBox(){
        if(visible){
            cout << "\033[" << startY << ";" << startX << "H";
            cout << "\033[7m";
            if(selected)
                cout << "\033[44m";
            for(unsigned int i=0; i<lenY; i++){
                for(unsigned int j=0; j<lenX; j++){
                    cout << Out[i][j];
                }
                cout << "\033[1B" << "\033[" << lenX << "D";
            }
            cout << "\033[0m";
        }
    }

    int getStartX(){
        return startX;
    }

    int getStartY(){
        return startY;
    }

    int getLen(){
        return lenX;
    }

    bool isVisible(){
        return visible;
    }

    void setVisible(bool _visible){
        visible = _visible;
    }

    void setT(Box *box){
        T = box;
    }

    void setR(Box *box){
        R = box;
    }

    void setB(Box *box){
        B = box;
    }

    void setL(Box *box){
        L = box;
    }

    void setPlaceholderText(map<string, string> placeholder){
        placeholderText = placeholder;
    }

    string getType(){
        return type;
    }

    void setTextLabelAction(void (*newAction)(string)){
        TextLabelAction = newAction;
    }

    void doAction(){
        TextLabelAction(inputedText);
        Sleep(100);
    }

    ~TextLabel(){
        L = nullptr;
        R = nullptr;
        T = nullptr;
        B = nullptr;

        if (Out != nullptr) {
            for (unsigned int i = 0; i < lenY; i++) {
                delete Out[i];
                Out[i] = nullptr;
            }
            delete[] Out;
            Out = nullptr;
        }
    }
};

class TextBox : public Box{
public:
    TextBox(unsigned int sx,
            unsigned int sy,
            unsigned int lX,
            bool centeredText = true,
            Box* Top = nullptr,
            Box* Right = nullptr,
            Box* Bottom = nullptr,
            Box* Left = nullptr,
            bool _visible = true,
            bool _secret = false,
            bool haveFrame = false)
    {
        type = "TextBox";

        visible = _visible;
        secret = _secret;
        frame = haveFrame;
        selected = false;

        T = Top;
        R = Right;
        B = Bottom;
        L = Left;
        centered = centeredText;

        startX = sx;
        startY = sy;
        lenX = lX;
        lenY = 3;

        Out = new char*[lenY];
        for(int i=0; i<lenY; i++)
            Out[i] = new char[lenX];
        setOutput();
    }

    Box* Switch(char side){
        switch(side){
        case 'T':
            if(T != nullptr && T->isVisible())
                return T;
            else
                return this;
        case 'R':
            if(R != nullptr && R->isVisible())
                return R;
            else
                return this;
        case 'B':
            if(B != nullptr && B->isVisible())
                return B;
            else
                return this;
        case 'L':
            if(L != nullptr && L->isVisible())
                return L;
            else
                return this;
        default:
            cout<<"ERROR 404 - NO SIDE AS "<<side<<"!"<<endl;
            return this;
        }
    }

    string getText(){
        return text[Language];
    }

    void setText(map<string, string> txt){
        text = txt;
    }

    void setOutput(){
        if (Out != nullptr) {
            for (unsigned int i = 0; i < lenY; i++) {
                if (Out[i] != nullptr) {
                    delete[] Out[i];
                    Out[i] = nullptr;
                }
            }
        }
        delete[] Out;

        Out = new char*[lenY];
        for(unsigned int i=0; i<lenY; i++){
            Out[i] = new char[lenX];
            for(unsigned int j=0; j<lenX; j++)
                Out[i][j] = ' ';
        }
        setOutputText();
    }

    void setOutputText(){
        int i=0;
        string txt = text[Language], placeholderTxt = placeholderText[Language];
        int len = txt.length();
        int margin = round((lenX-4 - len)/2);

        for(unsigned int j=2; j<lenX-2; j++)
            Out[1][j] = ' ';

        if(len>0){
            if(centered){
                for(unsigned int j=2+margin; j<lenX-2; j++){
                    if(i<len){
                        Out[1][j] = txt[i];
                        i++;
                    }
                    else
                        Out[1][j] = ' ';
                }
            }
            else{
                for(int j = 2; j<lenX-3; j++){
                    if(i<len){
                        Out[1][j] = txt[i];
                        i++;
                    }
                    else
                        Out[1][j] = ' ';
                }
            }
        }
        else{
            len = placeholderTxt.length();
            if(centered){
                for(unsigned int j=2+margin; j<lenX-2; j++){
                    if(i<len){
                        Out[1][j] = placeholderTxt[i];
                        i++;
                    }
                }
            }
            else{
                for(int j = 2; j<lenX-3; j++){
                    if(i<len){
                        Out[1][j] = placeholderTxt[i];
                        i++;
                    }
                }
            }
        }
    }

    void printBox(){
        if(visible){
            cout << "\033[" << startY << ";" << startX << "H";
            cout << "\033[7m";
            if(selected)
                cout << "\033[44m";
            for(unsigned int i=0; i<lenY; i++){
                for(unsigned int j=0; j<lenX; j++){
                    cout << Out[i][j];
                }
                cout << "\033[1B" << "\033[" << lenX << "D";
            }
            cout << "\033[0m";
        }
    }

    int getStartX(){
        return startX;
    }

    int getStartY(){
        return startY;
    }

    int getLen(){
        return lenX;
    }

    bool isVisible(){
        return visible;
    }

    void setVisible(bool _visible){
        visible = _visible;
    }

    void setT(Box *box){
        T = box;
    }

    void setR(Box *box){
        R = box;
    }

    void setB(Box *box){
        B = box;
    }

    void setL(Box *box){
        L = box;
    }

    string getType(){
        return type;
    }

    ~TextBox(){
        L = nullptr;
        R = nullptr;
        T = nullptr;
        B = nullptr;

        if (Out != nullptr) {
            for (unsigned int i = 0; i < lenY; ++i) {
                delete[] Out[i];
                Out[i] = nullptr;
            }
            delete[] Out;
            Out = nullptr;
        }
    }
};

class LangBox : public Box{
private:
    string currentLang = "EN";

public:
    LangBox(unsigned int sx,
            unsigned int sy,
            unsigned int lX,
            bool centeredText = true,
            Box* Top = nullptr,
            Box* Right = nullptr,
            Box* Bottom = nullptr,
            Box* Left = nullptr,
            bool _visible = true,
            bool _secret = false,
            bool haveFrame = true)
    {
        type = "LangBox";
        currentLang = "EN";

        text["EN"] = "EN";
        text["PL"] = "PL";

        visible = _visible;
        secret = _secret;
        frame = haveFrame;
        selected = false;

        T = Top;
        R = Right;
        B = Bottom;
        L = Left;
        centered = centeredText;

        startX = sx;
        startY = sy;
        lenX = lX;
        lenY = 3;

        Out = new char*[lenY];
        for(int i=0; i<lenY; i++)
            Out[i] = new char[lenX];
        setOutput();
    }

    changeLang(){
        if(currentLang == "EN")
            currentLang = "PL";
        else
            currentLang = "EN";

        Language = currentLang;
        setPlaceholderText(currentLang);
        setOutputText();
    }

    Box* Switch(char side){
        switch(side){
        case 'T':
            if(T != nullptr && T->isVisible())
                return T;
            else
                return this;
        case 'R':
            if(R != nullptr && R->isVisible())
                return R;
            else
                return this;
        case 'B':
            if(B != nullptr && B->isVisible())
                return B;
            else
                return this;
        case 'L':
            if(L != nullptr && L->isVisible())
                return L;
            else
                return this;
        default:
            cout<<"ERROR 404 - NO SIDE AS "<<side<<"!"<<endl;
            return this;
        }
    }

    void setSelect(bool isSelected){
        selected = isSelected;
    }

    string getText(){
        return text[Language];
    }

    void setOutput(){
        if (Out != nullptr) {
            for (unsigned int i = 0; i < lenY; i++) {
                if (Out[i] != nullptr) {
                    delete[] Out[i];
                    Out[i] = nullptr;
                }
            }
        }
        delete[] Out;

        Out = new char*[lenY];
        for(unsigned int i=0; i<lenY; i++){
            Out[i] = new char[lenX];
            for(unsigned int j=0; j<lenX; j++){
                if(i==0){
                    if(frame){
                        if(j == 0)
                            Out[i][j] = cr1;
                        else if(j == lenX-1)
                            Out[i][j] = cr2;
                        else{
                            if(secret){
                                if((lenX-j)%2==1)
                                    Out[i][j] = '-';
                                else
                                    Out[i][j] = ' ';
                            }
                            else
                                Out[i][j] = '-';
                        }
                    }
                    else{
                        Out[i][j] = ' ';
                    }
                }
                else if(i==2){
                    if(frame){
                        if(j == 0)
                            Out[i][j] = cr3;
                        else if(j == lenX-1)
                            Out[i][j] = cr4;
                        else{
                            if(secret){
                                if((lenX-j)%2==1)
                                    Out[i][j] = '-';
                                else
                                    Out[i][j] = ' ';
                            }
                            else
                                Out[i][j] = '-';
                        }
                    }
                    else{
                        Out[i][j] = ' ';
                    }
                }
                else{
                    if(j == 0 || j == lenX-1){
                        if(secret || !frame)
                            Out[i][j] = ' ';
                        else
                            Out[i][j] = '|';
                    }
                    else
                        Out[i][j] = ' ';
                }
            }
        }
        setOutputText();
    }

    void setOutputText(){
        int i=0;
        string txt = text[Language], placeholderTxt = placeholderText[Language];
        int len = txt.length();
        int margin = round((lenX-4 - len)/2);

        for(unsigned int j=2; j<lenX-2; j++)
            Out[1][j] = ' ';

        if(len>0){
            if(centered){
                for(unsigned int j=2+margin; j<lenX-2; j++){
                    if(i<len){
                        Out[1][j] = txt[i];
                        i++;
                    }
                    else
                        Out[1][j] = ' ';
                }
            }
            else{
                for(int j = 2; j<lenX-3; j++){
                    if(i<len){
                        Out[1][j] = txt[i];
                        i++;
                    }
                    else
                        Out[1][j] = ' ';
                }
            }
        }
        else{
            len = placeholderTxt.length();
            if(centered){
                for(unsigned int j=2+margin; j<lenX-2; j++){
                    if(i<len){
                        Out[1][j] = placeholderTxt[i];
                        i++;
                    }
                }
            }
            else{
                for(int j = 2; j<lenX-3; j++){
                    if(i<len){
                        Out[1][j] = placeholderTxt[i];
                        i++;
                    }
                }
            }
        }
    }

    void printBox(){
        if(visible){
            cout << "\033[" << startY << ";" << startX << "H";
            cout << "\033[7m";
            if(selected)
                cout << "\033[44m";
            for(unsigned int i=0; i<lenY; i++){
                for(unsigned int j=0; j<lenX; j++){
                    cout << Out[i][j];
                }
                cout << "\033[1B" << "\033[" << lenX << "D";
            }
            cout << "\033[0m";
        }
    }

    int getStartX(){
        return startX;
    }

    int getStartY(){
        return startY;
    }

    int getLen(){
        return lenX;
    }

    bool isVisible(){
        return visible;
    }

    void setVisible(bool _visible){
        visible = _visible;
    }

    void setT(Box *box){
        T = box;
    }

    void setR(Box *box){
        R = box;
    }

    void setB(Box *box){
        B = box;
    }

    void setL(Box *box){
        L = box;
    }

    string getType(){
        return type;
    }

    void doAction(){
        changeLang();
    }

    ~LangBox(){
        L = nullptr;
        R = nullptr;
        T = nullptr;
        B = nullptr;

        if (Out != nullptr) {
            for (unsigned int i = 0; i < lenY; ++i) {
                delete[] Out[i];
                Out[i] = nullptr;
            }
            delete[] Out;
            Out = nullptr;
        }
    }
};

class GUI{
private:
    string name;
    Box** boxes;
    unsigned int box_amount, currentBoxes;
    char GUI_OUT[GUIY][GUIX];
public:
    GUI(){}

    GUI(string GUI_name, unsigned int _box_amount){
        name = GUI_name;
        box_amount = _box_amount;
        currentBoxes = 0;
        boxes = new Box*[box_amount];
        for(int i=0; i<box_amount; i++){
            boxes[i] = nullptr;
        }

        generateGUI();
    }

    GUI& operator=(const GUI& gui){
        name = gui.name;
        box_amount = gui.box_amount;
        currentBoxes = 0;
        boxes = new Box*[box_amount];
        for(int i=0; i<box_amount; i++){
            boxes[i] = nullptr;
        }

        generateGUI();
    }

    string getName(){
        return name;
    }

    void printGUI(){
        cout << "\033[7m";
        for(unsigned int i=0; i<GUIY; i++){
            for(unsigned int j=0; j<GUIX; j++){
                if(GUI_OUT[i][j] == '#')
                    cout << "\033[0;30;40m" << GUI_OUT[i][j] << "\033[0;7m";
                else
                    cout<<GUI_OUT[i][j];
            }
            cout<<endl;
        }
        cout << "\033[0m" << endl;

        for(unsigned int i=0; i<box_amount; i++){
            if(boxes[i]!=nullptr)
                boxes[i]->printBox();
        }
    }

    void UpdateGUI(){
        for(int i=0; i<box_amount; i++)
            boxes[i]->setOutputText();
        printGUI();
    }

    void generateGUI(){
        if(name == "START")
            setStartGUI();
        else if(name == "BANK")
            setBankGUI();
        else{
            for(unsigned int i=0; i<GUIY; i++){
                for(unsigned int j=0; j<GUIX; j++){
                    GUI_OUT[i][j] = EmptyGUI[i][j];
                }
            }
        }
    }

    void adBox(Box *box){
        boxes[currentBoxes] = box;
        currentBoxes++;
        //generateBox(box);
    }

    void setStartGUI(){
        for(unsigned int i=0; i<GUIY; i++){
            for(unsigned int j=0; j<GUIX; j++){
                GUI_OUT[i][j] = StartGUI[i][j];
            }
        }
    }

    void setBankGUI(){
        for(unsigned int i=0; i<GUIY; i++){
            for(unsigned int j=0; j<GUIX; j++){
                GUI_OUT[i][j] = BankGUI[i][j];
            }
        }
    }

    void setBoxVisible(unsigned int boxNumber, bool visible){
        boxes[boxNumber]->setVisible(visible);
        //generateBox(boxes[boxNumber]);
    }

    Box *getBox(int number){
        return boxes[number];
    }

    void setBoxNeighbor(unsigned int boxNumber, char side, Box *box){
        if (boxNumber < currentBoxes) {
            switch (side) {
                case 'T':
                    boxes[boxNumber]->setT(box); break;
                case 'B':
                    boxes[boxNumber]->setB(box); break;
                case 'R':
                    boxes[boxNumber]->setR(box); break;
                case 'L':
                    boxes[boxNumber]->setL(box); break;
                default:
                    cout << "Invalid side!" << endl; break;
            }
        } else {
            cout << "Box number out of range!" << endl;
        }
    }

    void setBoxText(unsigned int boxNumber, map<string, string> txt){
        boxes[boxNumber]->setText(txt);
    }

    void showError(map<string, string> err){
        boxes[2]->setText(err);
    }

    ~GUI(){

        cout<<"Deleting boxes..."<<endl;
        for(unsigned int i=0; i<box_amount; i++){
            cout<<i+1<<"-";
            if(boxes[i]==nullptr)
                cout<<"nullptr!"<<endl;
            else{
                delete boxes[i];
                cout<<"Box deleted!"<<endl;
            }
        }
        delete[] boxes;
        cout<<"Delete complete!"<<endl;
    }
};

///---------------------------------GUIS AND BUTTON------------------------------------------------------------------------------------------------------------------------------------------------

// Current

GUI *currentGUI;
Box *currentBox;

// ATM

GUI *Start;
GUI *InsertCard;
GUI *Choice;
GUI *Deposit;
GUI *Withdraw;
GUI *WithdrawResult;
GUI *CustomWithdraw;
GUI *CustomWithdrawResult;
GUI *TakeOutCard;

// Bank

GUI *Bank;
GUI *Password;
GUI *Admin;
GUI *CasketGUI;
GUI *Login;
GUI *AccountMenu;
GUI *SetMoney;
GUI *DeleteAccountGUI;
GUI *DeleteResult;
GUI *CardsMenu;
GUI *AdCard;
GUI *DeleteCard;
GUI *CardFinish;
GUI* CreateAccount;


///---------------------------------FUNCTIONS------------------------------------------------------------------------------------------------------------------------------------------------------

// CHANGE GUI FUNCTIONS

void ChangeGUIToStart(){

    if (Account.is_open()) {
        Account.close();
    }

    currentGUI = Start;
    currentBox->setSelect(false);
    currentBox = currentGUI->getBox(0);
    currentBox->setSelect(true);
}

void ChangeGUIToInsertCard(){
    currentGUI = InsertCard;
    currentBox->setSelect(false);
    currentBox = currentGUI->getBox(0);
    currentBox->setSelect(true);

    currentGUI->showError(insertCardText);
    currentBox->clearInput();
}

void ChangeGUIToChoice(){
    currentGUI = Choice;
    currentBox->setSelect(false);
    currentBox = currentGUI->getBox(0);
    currentBox->setSelect(true);
}

void ChangeGUIToDeposit(){
    currentGUI = Deposit;
    currentBox->setSelect(false);
    currentBox = currentGUI->getBox(0);
    currentBox->setSelect(true);

    currentGUI->showError(depositMoneyText);
    currentBox->clearInput();
}

void ChangeGUIToTakeOutCard(){
    currentGUI = TakeOutCard;
    currentBox->setSelect(false);
    currentBox = currentGUI->getBox(1);
    currentBox->setSelect(true);
}

void ChangeGUIToWithdraw(){
    currentGUI = Withdraw;
    currentBox->setSelect(false);
    currentBox = currentGUI->getBox(0);
    currentBox->setSelect(true);
}

void ChangeGUIToCustomWithdraw(){
    currentGUI = CustomWithdraw;
    currentBox->setSelect(false);
    currentBox = currentGUI->getBox(0);
    currentBox->setSelect(true);

    currentGUI->showError(withdrawInfoText);
    currentBox->clearInput();
}

void ChangeGUIToWithdrawResult(int ok){
    currentGUI = WithdrawResult;
    currentBox->setSelect(false);
    currentBox = currentGUI->getBox(2);
    currentBox->setSelect(true);

    if(ok == 1){
        currentGUI->setBoxText(0, successText);
        currentGUI->setBoxText(1, emptyText);
    }
    else if(ok == 2){
        currentGUI->setBoxText(0, failureText);
        currentGUI->setBoxText(1, failureDescText);
    }
    else if(ok == 3){
        currentGUI->setBoxText(0, failureText);
        currentGUI->setBoxText(1, failureDescText2);
    }
    else if(ok == 4){
        currentGUI->setBoxText(0, failureText);
        currentGUI->setBoxText(1, casketMoneyErrorText);
    }
}


void ChangeGUIToBank(){
    currentGUI = Bank;
    currentBox->setSelect(false);
    currentBox = currentGUI->getBox(0);
    currentBox->setSelect(true);
}

void ChangeGUIToPassword(){
    currentGUI = Password;
    currentBox->setSelect(false);
    currentBox = currentGUI->getBox(0);
    currentBox->setSelect(true);

    currentGUI->showError(insertPasswordText);
    currentBox->clearInput();
}

void ChangeGUIToAdmin(){
    currentGUI = Admin;
    currentBox->setSelect(false);
    currentBox = currentGUI->getBox(0);
    currentBox->setSelect(true);
}

void ChangeGUIToCasket(){
    currentGUI = CasketGUI;
    currentBox->setSelect(false);
    currentBox = currentGUI->getBox(0);
    currentBox->setSelect(true);

    currentGUI->showError(setMoneyText);
    currentBox->clearInput();
}

void ChangeGUIToLoginGUI(){
    currentGUI = Login;
    currentBox->setSelect(false);
    currentBox = currentGUI->getBox(0);
    currentBox->setSelect(true);

    currentGUI->showError(insertAccountNumberText);
    currentBox->clearInput();
}

void ChangeGUIToAccountMenu(){
    currentGUI = AccountMenu;
    currentBox->setSelect(false);
    currentBox = currentGUI->getBox(0);
    currentBox->setSelect(true);
}

void ChangeGUIToMoney(){
    currentGUI = SetMoney;
    currentBox->setSelect(false);
    currentBox = currentGUI->getBox(0);
    currentBox->setSelect(true);

    currentGUI->showError(setAccountMoneyText);
    currentBox->clearInput();
}

void ChangeGUIToDeleteAccount(){
    currentGUI = DeleteAccountGUI;
    currentBox->setSelect(false);
    currentBox = currentGUI->getBox(0);
    currentBox->setSelect(true);
}

void ChangeGUIToDeleteResult(bool b){
    currentGUI = DeleteResult;
    currentBox->setSelect(false);
    currentBox = currentGUI->getBox(0);
    currentBox->setSelect(true);

    if(b)
        currentGUI->showError(accountDeletedText);
    else
        currentGUI->showError(accountNotDeletedText);
}

void ChangeGUIToCardsMenu(){
    currentGUI = CardsMenu;
    currentBox->setSelect(false);
    currentBox = currentGUI->getBox(0);
    currentBox->setSelect(true);
}

void ChangeGUIToAdCardGUI(){
    currentGUI = AdCard;
    currentBox->setSelect(false);
    currentBox = currentGUI->getBox(0);
    currentBox->setSelect(true);

    currentGUI->showError(generateCardText);
    currentBox->clearInput();
}

void ChangeGUIToDeleteCardGUI(){
    currentGUI = DeleteCard;
    currentBox->setSelect(false);
    currentBox = currentGUI->getBox(0);
    currentBox->setSelect(true);

    currentGUI->showError(insertCardNumberText);
    currentBox->clearInput();
}

void ChangeGUIToCardFinish(){
    currentGUI = CardFinish;
    currentBox->setSelect(false);
    currentBox = currentGUI->getBox(0);
    currentBox->setSelect(true);

    currentGUI->showError(cardFinishText);
}

void ChangeGUIToCreateAccountGUI(){
    currentGUI = CreateAccount;
    currentBox->setSelect(false);
    currentBox = currentGUI->getBox(0);
    currentBox->setSelect(true);

    currentGUI->showError(AccountText);
}


// BANK FUNCTIONS

void accountReopen(){
    Account.close();
    Account.open(CurrentPath, ios::in | ios::out);
}

bool checkForCard(const string& fileName) {
    string searchPath = CardsPath + "\\*";
    WIN32_FIND_DATA fd;
    HANDLE hFind = ::FindFirstFile(searchPath.c_str(), &fd);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                if (fd.cFileName == fileName) {
                    string fullPath = CardsPath + "\\" + fd.cFileName;
                    Account.open(fullPath, ios::in | ios::out);
                    ::FindClose(hFind);
                    CurrentPath = fullPath;
                    return Account.is_open();
                }
            }
        } while (::FindNextFile(hFind, &fd));
        ::FindClose(hFind);
    }
    return false;
}

string getAccountNumber(const string& filePath) {
    ifstream file(filePath);
    string firstLine = "";
    if (file.is_open()) {
        getline(file, firstLine);
        file.close();
    }
    return firstLine;
}

bool OpenAccount(string number) {
    number+=".txt";
    if (checkForCard(number)) {
        string accountNumber = getAccountNumber(CardsPath + "\\" + number);
        //cout<<accountNumber<<endl;
        if (Account.is_open()) {
            Account.close();
        }

        if (CheckForAccount(accountNumber)) {
            return true;
        }
    }
    return false;
}

bool ChangeMoneyOnAccount(int money) {
    if (!Account.is_open()){
        cout<<CurrentPath;
        Account.open(CurrentPath, ios::in | ios::out);
        if (!Account.is_open()){
            cout<<"Unexpected error during opening account! Please reset ATM.";
            Sleep(1000);
            return false;
        }
    }


    string moneyAmount;
    Account >> moneyAmount;

    double accountMoney;
    accountMoney = stod(moneyAmount);

    if (accountMoney + money < 0) {
        return false;
    } else {
        //cout<<endl<<accountMoney<<"+"<<money<<"=";
        accountMoney += money;
        //cout<<accountMoney;
        //Sleep(1000);
        //Account.seekp(0, ios::beg);
        accountReopen();
        Account << accountMoney << endl;

        accountReopen();
        return true;
    }
}

void SetMoneyOnAccount(string amount) {
    //cout<<amount;
    if(!amount.empty()){
        double money = stod(amount);
        if(money >= 0){
            if (!Account.is_open()){
                Account.open(CurrentPath, ios::in | ios::out);
                if (!Account.is_open()){
                    cout<<"Unexpected error during opening account!";
                    exit(12345);
                }
            }
            Account << money << endl;
            accountReopen();
            currentGUI->showError(moneySetedText);
        }
        else
            currentGUI->showError(notEnoughMoneyText);
    }
}

int amountMoneyInCasket(){
    int amount = 0;

    Casket.open(CasketPath, ios::in | ios::out);
    if (!Casket.is_open()){
        return 0;
    }

    Casket.seekg(0, ios::beg);

    string line;
    while (getline(Casket, line)) {
        size_t dash = line.find("-");

        unsigned int lineType = stoi(line.substr(0, dash));
        int lineAmount, finalAmount;
        lineAmount = stoi(line.substr(dash + 1));
        amount += (lineAmount * lineType);
    }

    Casket.close();
    return amount;

}

bool enoughMoneyInCasket(string amount){
    int casket = amountMoneyInCasket();
    double money = stoi(amount);
    if(money>casket)
        return false;
    return true;
}

double accountFunds(){
    string moneyText;
    getline(Account, moneyText);
    cout<<moneyText;
    double money = stod(moneyText);
    accountReopen();
    return money;
}

void changeMoneyInCasket(unsigned int type, int amount) {
    Casket.open(CasketPath, ios::in | ios::out);
    if (!Casket.is_open()){
        return;
    }

    vector<string> lines;
    string line;
    while (getline(Casket, line)) {
        lines.push_back(line);
    }
    Casket.close();

    for (auto& line : lines) {
        size_t dash = line.find("-");
        if (dash != string::npos) {
            unsigned int lineType = stoi(line.substr(0, dash));
            if (type == lineType) {
                int lineAmount = stoi(line.substr(dash + 1));
                int finalAmount = lineAmount + amount;
                line = to_string(type) + "-" + to_string(finalAmount);
            }
        }
    }

    Casket.open(CasketPath, ios::out | ios::trunc);

    for (const auto& line : lines) {
        Casket << line << endl;
    }

    Casket.close();
}

void moneySeted(bool b){
    if(b)
        currentGUI->showError(moneySetText);
    else
        currentGUI->showError(moneySetErrorText);
}

void setMoneyInCasket(string input) {
    size_t dash = input.find("-");
    if(dash != string::npos){
        string x_str = input.substr(0, dash);
        string y_str = input.substr(dash + 1);

        if (!(x_str.empty() || y_str.empty())){
            int type = stoi(x_str),
                amount = stoi(y_str);

            if(amount >= 0 && (type == 10 || type == 20 || type == 50 || type == 100 || type == 200 || type == 500)){
                Casket.open(CasketPath, ios::in | ios::out);
                if (!Casket.is_open()){
                    return;
                }

                vector<string> lines;
                string line;
                while (getline(Casket, line)) {
                    lines.push_back(line);
                }
                Casket.close();

                for (auto& line : lines) {
                    size_t dash = line.find("-");
                    if (dash != string::npos) {
                        unsigned int lineType = stoi(line.substr(0, dash));
                        if (type == lineType) {
                            line = to_string(type) + "-" + to_string(amount);
                        }
                    }
                }

                Casket.open(CasketPath, ios::out | ios::trunc);

                for (const auto& line : lines) {
                    Casket << line << endl;
                }

                Casket.close();

                moneySeted(true);
            }
            else{
                moneySeted(false);
                return;
            }
        }
        else{
            moneySeted(false);
            return;
        }
    }
    else{
        moneySeted(false);
        return;
    }

}

bool withdrawMoney(string money){
    int amount = stoi(money);

    if(amount>accountFunds()){
        return false;
    }
    else{
        int toWithdraw = 0;

        //if(canWithdraw(amount)){
            toWithdraw = amount/500;
            toWithdraw*=(-1);
            changeMoneyInCasket(500, toWithdraw);
            amount += 500*toWithdraw;

            toWithdraw = amount/200;
            toWithdraw*=(-1);
            changeMoneyInCasket(200, toWithdraw);
            amount += 200*toWithdraw;

            toWithdraw = amount/100;
            toWithdraw*=(-1);
            changeMoneyInCasket(100, toWithdraw);
            amount += 100*toWithdraw;

            toWithdraw = amount/50;
            toWithdraw*=(-1);
            changeMoneyInCasket(50, toWithdraw);
            amount += 50*toWithdraw;

            toWithdraw = amount/20;
            toWithdraw*=(-1);
            changeMoneyInCasket(20, toWithdraw);
            amount += 20*toWithdraw;

            toWithdraw = amount/10;
            toWithdraw*=(-1);
            changeMoneyInCasket(10, toWithdraw);
            amount += 10*toWithdraw;
            /*
        }
        else{
            return false;
        }
        */
    }
    if(amount>0)
        return false;
    else{
        int toSub = stoi(money);
        toSub*=(-1);
        ChangeMoneyOnAccount(toSub);
        return true;
    }
}

void removeCard(string number){
    fstream card;
    string cardPath = CardsPath + "\\" + number + ".txt";
    card.open(cardPath, ios::in | ios::out);
    if(card.is_open()){
        int accountNumber;
        card >> accountNumber;
        card.close();
        string::size_type dot = CurrentAccount.find_last_of('.');
        if(accountNumber == stoi(CurrentAccount.substr(0, dot))){
            remove(cardPath.c_str());
            cardFinishText[Language] = cardDeletedText[Language];
            ChangeGUIToCardFinish();
        }
        else{
            cardFinishText[Language] = cardDeletionFailedText[Language];
            ChangeGUIToCardFinish();
        }
    }
    else{
        cardFinishText[Language] = cardDeletionFailedText[Language];
        ChangeGUIToCardFinish();
    }
}

void removeCards(){
    fstream card;
    for (const auto & entry : fs::directory_iterator(CardsPath)){
        string cardPath = entry.path().string();
        card.open(cardPath, ios::in);
        if(card.is_open()){
            int accountNumber;
            card >> accountNumber;
            card.close();
            if(accountNumber == stoi(CurrentAccount))
                remove(cardPath.c_str());
        }
    }
}

void deleteAccount(){
    string accountToDelete = AccountsPath+"\\"+CurrentAccount;
    removeCards();
    Account.close();
    if(remove(accountToDelete.c_str()) == 0)
        ChangeGUIToDeleteResult(true);
    else
        ChangeGUIToDeleteResult(false);
}


// ATM FUNCTIONS

void moneyInserted(bool b){
    if(b)
        currentGUI->showError(moneyInsertedText);
    else
        currentGUI->showError(moneyInsertErrorText);
}

void MoneyInput(string input){
    size_t dash = input.find("-");
    if(dash != string::npos){
        string x_str = input.substr(0, dash);
        string y_str = input.substr(dash + 1);

        if (!(x_str.empty() || y_str.empty())){
            int x = stoi(x_str),
                y = stoi(y_str);

            if (x > 0 && y > 0 && (x == 10 || x == 20 || x == 50 || x == 100 || x == 200 || x == 500)){
                if(ChangeMoneyOnAccount(x*y)){
                    changeMoneyInCasket(x, y);
                    moneyInserted(true);
                }
                else moneyInserted(false);
            }
            else moneyInserted(false);
        }
        else moneyInserted(false);
    }
    else moneyInserted(false);
}

void WithdrawCheck(string amount){
    if(stoi(amount)>0 && stoi(amount)%10 == 0){
        if(enoughMoneyInCasket(amount)){
            if(withdrawMoney(amount))
                ChangeGUIToWithdrawResult(1);
            else
                ChangeGUIToWithdrawResult(2);
        }
        else
            ChangeGUIToWithdrawResult(4);
    }
    else
        ChangeGUIToWithdrawResult(3);
}

void CardInput(string number){

    if(OpenAccount(number)){
        currentGUI->showError(insertCardText);
        ChangeGUIToChoice();
    }
    else{
        currentGUI->showError(wrongNumberText);
    }
}

void PasswordInput(string pass){
    if(pass == "1324")
        ChangeGUIToAdmin();
    else
        currentGUI->showError(wrongPasswordText);
}

bool CheckForAccount(string number){
    number+=".txt";
    string searchPath = AccountsPath + "\\*";
    WIN32_FIND_DATA fd;
    HANDLE hFind = ::FindFirstFile(searchPath.c_str(), &fd);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                if (fd.cFileName == number) {
                    string fullPath = AccountsPath + "\\" + fd.cFileName;
                    Account.open(fullPath, ios::in | ios::out);
                    ::FindClose(hFind);
                    CurrentPath = fullPath;
                    CurrentAccount = number;
                    return Account.is_open();
                }
            }
        } while (::FindNextFile(hFind, &fd));
        ::FindClose(hFind);
    }
    return false;
}

bool LogInAccount(string AccountNumber) {

    if (Account.is_open())
        Account.close();

    if (CheckForAccount(AccountNumber)) {
        return true;
    }
    return false;
}

void AccountInput(string number){

    if(LogInAccount(number)){
        currentGUI->showError(insertAccountNumberText);
        ChangeGUIToAccountMenu();
    }
    else{
        currentGUI->showError(wrongNumberText);
    }
}

void GenerateCard(){
    string newCardNumber = "";
    do{
        newCardNumber = to_string(rand() % 9 + 1);
        for(int i=0; i<5; i++)
            newCardNumber += to_string(rand() % 10);
    } while(checkForCard(newCardNumber));

    fstream newCard;
    newCard.open(CardsPath + "\\" + newCardNumber + ".txt", ios::app);
    if(newCard.is_open()){
        string::size_type dot = CurrentAccount.find_last_of('.');
        newCard << CurrentAccount.substr(0, dot);
        newCard.close();
        cardFinishText[Language] = cardGeneratedText[Language] + newCardNumber;
        ChangeGUIToCardFinish();
    }
    else{
        cardFinishText[Language] = cardGenerationFailedText[Language];
        ChangeGUIToCardFinish();
    }

}

void CreateNewAccount(){
    string newAccountNumber = "";
    do{
        newAccountNumber = to_string(rand() % 9 + 1);
        for(int i=0; i<3; i++)
            newAccountNumber += to_string(rand() % 10);
    } while(CheckForAccount(newAccountNumber));

    fstream newAccount;
    newAccount.open(AccountsPath + "\\" + newAccountNumber + ".txt", ios::app);
    if(newAccount.is_open()){
        newAccount << "1000";
        newAccount.close();
        AccountText[Language] = WIPAccountText[Language] + newAccountNumber;
        createdAccount = newAccountNumber;
        ChangeGUIToCreateAccountGUI();
    }
    else{
        cardFinishText[Language] = FailedAccountText[Language];
        ChangeGUIToCreateAccountGUI();
    }
}

void EnterAccount(){

    if(LogInAccount(createdAccount)){
        currentGUI->showError(insertAccountNumberText);
        ChangeGUIToAccountMenu();
        createdAccount="";
    }
    else{
        currentGUI->showError(wrongNumberText);
    }
}


// Placeholders

void PlaceholderAction(){}
void PlaceholderAction2(string){}


///---------------------------------SETUP---------------------------------------------------------------------------------------------------------------------------------------------------------


// ATM GUIS

void setupStartGUI(){

    Start = new GUI("START", 3);

    Button *insertButton = new Button(16, 10, 17);
    Button *adminButton = new Button(16, 13, 17, true, nullptr, nullptr, nullptr, nullptr, false, true);
    LangBox *lang = new LangBox(35, 10, 6);

    insertButton->setText(insertCardText);
    insertButton->setButtonAction(ChangeGUIToInsertCard);
    insertButton->setOutput();

    adminButton->setText(adminText);
    adminButton->setButtonAction(ChangeGUIToBank);
    adminButton->setOutput();

    Start->adBox(insertButton);
    Start->adBox(adminButton);
    Start->adBox(lang);

    Start->setBoxNeighbor(0, 'B', Start->getBox(1));
    Start->setBoxNeighbor(1, 'T', Start->getBox(0));
    Start->setBoxNeighbor(0, 'R', Start->getBox(2));
    Start->setBoxNeighbor(2, 'L', Start->getBox(0));
}

void setupInsertCardGUI(){
    InsertCard = new GUI("INSERT_CARD", 3);
    TextBox *cardTextBox = new TextBox(6, 6, 37);
    TextLabel *cardTextLabel = new TextLabel(16, 10, 17, false);
    Button *backToStart = new Button(19, 13, 11);

    cardTextBox->setText(insertCardText);
    cardTextBox->setOutput();

    cardTextLabel->setPlaceholderText(cardNumberText);
    cardTextLabel->setTextLabelAction(CardInput);
    cardTextLabel->setOutput();

    backToStart->setText(backText);
    backToStart->setButtonAction(ChangeGUIToStart);
    backToStart->setOutput();

    InsertCard->adBox(cardTextLabel);
    InsertCard->adBox(backToStart);
    InsertCard->adBox(cardTextBox);

    InsertCard->setBoxNeighbor(0, 'B', InsertCard->getBox(1));
    InsertCard->setBoxNeighbor(1, 'T', InsertCard->getBox(0));
}

void setupChoiceGUI(){
    Choice = new GUI("CHOICE", 3);
    Button *withdrawButton = new Button(9, 10, 14);
    Button *depositButton = new Button(26, 10, 14);
    Button *backToStart = new Button(19, 14, 11);

    depositButton->setText(depositText);
    depositButton->setButtonAction(ChangeGUIToDeposit);
    depositButton->setOutput();

    withdrawButton->setText(withdrawText);
    withdrawButton->setButtonAction(ChangeGUIToWithdraw);
    withdrawButton->setOutput();

    backToStart->setText(exitText);
    backToStart->setButtonAction(ChangeGUIToStart);
    backToStart->setOutput();

    Choice->adBox(withdrawButton);
    Choice->adBox(depositButton);
    Choice->adBox(backToStart);

    Choice->setBoxNeighbor(0, 'R', Choice->getBox(1));
    Choice->setBoxNeighbor(1, 'L', Choice->getBox(0));
    Choice->setBoxNeighbor(0, 'B', Choice->getBox(2));
    Choice->setBoxNeighbor(1, 'B', Choice->getBox(2));
    Choice->setBoxNeighbor(2, 'T', Choice->getBox(0));
}

void setupDepositGUI(){
    Deposit = new GUI("DEPOSIT", 4);
    TextBox *depositMoney = new TextBox(6, 6, 37);
    TextLabel *money = new TextLabel(13, 10, 23, false);
    Button *finishButton = new Button(13, 13, 11);
    Button *backButton = new Button(25, 13, 11);

    depositMoney->setText(depositMoneyText);
    depositMoney->setOutput();

    money->setPlaceholderText(insertMoneyText);
    money->setTextLabelAction(MoneyInput);
    money->setOutput();

    finishButton->setText(finishText);
    finishButton->setButtonAction(ChangeGUIToTakeOutCard);
    finishButton->setOutput();

    backButton->setText(backText);
    backButton->setButtonAction(ChangeGUIToChoice);
    backButton->setOutput();

    Deposit->adBox(money);
    Deposit->adBox(finishButton);
    Deposit->adBox(depositMoney);
    Deposit->adBox(backButton);

    Deposit->setBoxNeighbor(0, 'B', Deposit->getBox(1));
    Deposit->setBoxNeighbor(1, 'T', Deposit->getBox(0));
    Deposit->setBoxNeighbor(1, 'R', Deposit->getBox(3));
    Deposit->setBoxNeighbor(3, 'T', Deposit->getBox(0));
    Deposit->setBoxNeighbor(3, 'L', Deposit->getBox(1));
}

void setupTakeOutCardGUI(){

    TakeOutCard = new GUI("TAKE_OUT_CARD", 2);
    TextBox *takeText = new TextBox(13, 9, 23);
    Button *takeOut = new Button(14, 13, 21);

    takeText->setText(endingText);
    takeText->setOutput();

    takeOut->setText(TakeOutCardText);
    takeOut->setButtonAction(ChangeGUIToStart);
    takeOut->setOutput();

    TakeOutCard->adBox(takeText);
    TakeOutCard->adBox(takeOut);
}

void setupWithdrawGUI(){
    Withdraw = new GUI("WITHDRAW", 5);
    Button *w50 = new Button(10, 6, 12, false);
    Button *w100 = new Button(10, 10, 12, false);
    Button *w200 = new Button(27, 6, 12, false);
    Button *custom = new Button(27, 10, 12, false);
    Button *backButton = new Button(19, 14, 11);

    w50->setPlaceholderText("50");
    w50->setText(emptyText);
    w50->setA2(true);
    w50->setButtonAction2(WithdrawCheck);
    w50->setOutput();

    w100->setPlaceholderText("100");
    w100->setText(emptyText);
    w100->setA2(true);
    w100->setButtonAction2(WithdrawCheck);
    w100->setOutput();

    w200->setPlaceholderText("200");
    w200->setText(emptyText);
    w200->setA2(true);
    w200->setButtonAction2(WithdrawCheck);
    w200->setOutput();

    custom->setText(customText);
    custom->setButtonAction(ChangeGUIToCustomWithdraw);
    custom->setOutput();

    backButton->setText(backText);
    backButton->setButtonAction(ChangeGUIToChoice);
    backButton->setOutput();

    Withdraw->adBox(w50);
    Withdraw->adBox(w100);
    Withdraw->adBox(w200);
    Withdraw->adBox(custom);
    Withdraw->adBox(backButton);

    Withdraw->setBoxNeighbor(0, 'R', Withdraw->getBox(2));
    Withdraw->setBoxNeighbor(0, 'B', Withdraw->getBox(1));

    Withdraw->setBoxNeighbor(1, 'R', Withdraw->getBox(3));
    Withdraw->setBoxNeighbor(1, 'T', Withdraw->getBox(0));
    Withdraw->setBoxNeighbor(1, 'B', Withdraw->getBox(4));

    Withdraw->setBoxNeighbor(2, 'L', Withdraw->getBox(0));
    Withdraw->setBoxNeighbor(2, 'B', Withdraw->getBox(3));

    Withdraw->setBoxNeighbor(3, 'T', Withdraw->getBox(2));
    Withdraw->setBoxNeighbor(3, 'L', Withdraw->getBox(1));
    Withdraw->setBoxNeighbor(3, 'B', Withdraw->getBox(4));

    Withdraw->setBoxNeighbor(4, 'T', Withdraw->getBox(1));
}

void setupCustomWithdrawGUI(){
    CustomWithdraw = new GUI("CUSTOM_WITHDRAW", 3);
    TextBox *withdrawInfo = new TextBox(6, 6, 37);
    TextLabel *withdraw = new TextLabel(13, 10, 23, false);
    Button *backButton = new Button(19, 13, 11);

    withdrawInfo->setText(withdrawInfoText);
    withdrawInfo->setOutput();

    withdraw->setPlaceholderText(withdrawAmount);
    withdraw->setTextLabelAction(WithdrawCheck);
    withdraw->setOutput();

    backButton->setText(backText);
    backButton->setButtonAction(ChangeGUIToChoice);
    backButton->setOutput();

    CustomWithdraw->adBox(withdraw);
    CustomWithdraw->adBox(backButton);
    CustomWithdraw->adBox(withdrawInfo);

    CustomWithdraw->setBoxNeighbor(0, 'B', CustomWithdraw->getBox(1));
    CustomWithdraw->setBoxNeighbor(1, 'T', CustomWithdraw->getBox(0));
}

void setupWithdrawResultGUI(){
    WithdrawResult = new GUI("WITHDRAW_RESULT", 3);
    TextBox *result = new TextBox(6, 6, 37);
    TextBox *description = new TextBox(5, 9, 39);
    Button *finishButton = new Button(14, 13, 21);

    finishButton->setText(TakeOutCardText);
    finishButton->setButtonAction(ChangeGUIToStart);
    finishButton->setOutput();

    WithdrawResult->adBox(result);
    WithdrawResult->adBox(description);
    WithdrawResult->adBox(finishButton);
}


// BANK GUIS

void setupBankGUI(){
    Bank = new GUI("BANK", 3);
    Button *enter = new Button(16, 10, 17);
    Button *backToStart = new Button(19, 13, 11);
    LangBox *lang = new LangBox(35, 10, 6);

    enter->setText(enterText);
    enter->setButtonAction(ChangeGUIToPassword);
    enter->setOutput();

    backToStart->setText(backText);
    backToStart->setButtonAction(ChangeGUIToStart);
    backToStart->setOutput();

    Bank->adBox(enter);
    Bank->adBox(backToStart);
    Bank->adBox(lang);

    Bank->setBoxNeighbor(0, 'B', Bank->getBox(1));
    Bank->setBoxNeighbor(0, 'R', Bank->getBox(2));
    Bank->setBoxNeighbor(1, 'T', Bank->getBox(0));
    Bank->setBoxNeighbor(2, 'L', Bank->getBox(0));

}

void setupPasswordGUI(){
    Password = new GUI("PASSWORD", 3);
    TextBox *passwordTextBox = new TextBox(6, 6, 37);
    TextLabel *passwordTextLabel = new TextLabel(16, 10, 17, false);
    Button *backToBank = new Button(19, 13, 11);

    passwordTextBox->setText(insertPasswordText);
    passwordTextBox->setOutput();

    passwordTextLabel->setPlaceholderText(passwordText);
    passwordTextLabel->setTextLabelAction(PasswordInput);
    passwordTextLabel->setOutput();

    backToBank->setText(backText);
    backToBank->setButtonAction(ChangeGUIToBank);
    backToBank->setOutput();

    Password->adBox(passwordTextLabel);
    Password->adBox(backToBank);
    Password->adBox(passwordTextBox);

    Password->setBoxNeighbor(0, 'B', Password->getBox(1));
    Password->setBoxNeighbor(1, 'T', Password->getBox(0));
}

void setupAdminGUI(){
    Admin = new GUI("ADMIN", 3);
    Button *accountButton = new Button(9, 10, 14);
    Button *casketButton = new Button(26, 10, 14);
    Button *backToBank = new Button(19, 14, 11);

    casketButton->setText(casketText);
    casketButton->setButtonAction(ChangeGUIToCasket);
    casketButton->setOutput();

    accountButton->setText(accountText);
    accountButton->setButtonAction(ChangeGUIToLoginGUI);
    accountButton->setOutput();

    backToBank->setText(backToBankText);
    backToBank->setButtonAction(ChangeGUIToBank);
    backToBank->setOutput();

    Admin->adBox(accountButton);
    Admin->adBox(casketButton);
    Admin->adBox(backToBank);

    Admin->setBoxNeighbor(0, 'R', Admin->getBox(1));
    Admin->setBoxNeighbor(1, 'L', Admin->getBox(0));
    Admin->setBoxNeighbor(0, 'B', Admin->getBox(2));
    Admin->setBoxNeighbor(1, 'B', Admin->getBox(2));
    Admin->setBoxNeighbor(2, 'T', Admin->getBox(0));
}

void setupCasketGUI(){
    CasketGUI = new GUI("CASKET", 3);
    TextBox *changeMoney = new TextBox(6, 6, 37);
    TextLabel *money = new TextLabel(13, 10, 23, false);
    Button *finishButton = new Button(18, 13, 13);

    money->setPlaceholderText(insertMoneyText);
    money->setTextLabelAction(setMoneyInCasket);
    money->setOutput();

    finishButton->setText(finishText);
    finishButton->setButtonAction(ChangeGUIToAdmin);
    finishButton->setOutput();

    changeMoney->setText(setMoneyText);
    changeMoney->setOutput();

    CasketGUI->adBox(money);
    CasketGUI->adBox(finishButton);
    CasketGUI->adBox(changeMoney);

    CasketGUI->setBoxNeighbor(0, 'B', CasketGUI->getBox(1));
    CasketGUI->setBoxNeighbor(1, 'T', CasketGUI->getBox(0));
}

void setupLoginGUI(){
    Login = new GUI("PASSWORD", 4);
    TextBox *numberTextBox = new TextBox(6, 6, 37);
    TextLabel *numberTextLabel = new TextLabel(13, 9, 24, false);
    Button *createButton = new Button(13, 12, 11);
    Button *backToBank = new Button(26, 12, 11);

    numberTextBox->setText(insertAccountNumberText);
    numberTextBox->setOutput();

    numberTextLabel->setPlaceholderText(loginText);
    numberTextLabel->setTextLabelAction(AccountInput);
    numberTextLabel->setOutput();

    createButton->setText(createText);
    createButton->setButtonAction(CreateNewAccount);
    createButton->setOutput();

    backToBank->setText(backText);
    backToBank->setButtonAction(ChangeGUIToAdmin);
    backToBank->setOutput();

    Login->adBox(numberTextLabel);
    Login->adBox(backToBank);
    Login->adBox(numberTextBox);
    Login->adBox(createButton);

    Login->setBoxNeighbor(0, 'B', Login->getBox(3));
    Login->setBoxNeighbor(1, 'T', Login->getBox(0));
    Login->setBoxNeighbor(1, 'L', Login->getBox(3));
    Login->setBoxNeighbor(3, 'T', Login->getBox(0));
    Login->setBoxNeighbor(3, 'R', Login->getBox(1));
}

void setupAccountMenuGUI(){
    AccountMenu = new GUI("ACCOUNT_MENU", 4);
    Button *moneyButton = new Button(14, 5, 21);
    Button *cardsMenuButton = new Button(14, 8, 21);
    Button *deleteButton = new Button(14, 11, 21);
    Button *exitButton = new Button(14, 14, 21);

    moneyButton->setText(moneyText);
    moneyButton->setButtonAction(ChangeGUIToMoney);
    moneyButton->setOutput();

    cardsMenuButton->setText(cardsMenuText);
    cardsMenuButton->setButtonAction(ChangeGUIToCardsMenu);
    cardsMenuButton->setOutput();

    deleteButton->setText(deleteText);
    deleteButton->setButtonAction(ChangeGUIToDeleteAccount);
    deleteButton->setOutput();

    exitButton->setText(exitText);
    exitButton->setButtonAction(ChangeGUIToBank);
    exitButton->setOutput();

    AccountMenu->adBox(moneyButton);
    AccountMenu->adBox(cardsMenuButton);
    AccountMenu->adBox(deleteButton);
    AccountMenu->adBox(exitButton);

    AccountMenu->setBoxNeighbor(0, 'B', AccountMenu->getBox(1));
    AccountMenu->setBoxNeighbor(1, 'T', AccountMenu->getBox(0));
    AccountMenu->setBoxNeighbor(1, 'B', AccountMenu->getBox(2));
    AccountMenu->setBoxNeighbor(2, 'T', AccountMenu->getBox(1));
    AccountMenu->setBoxNeighbor(2, 'B', AccountMenu->getBox(3));
    AccountMenu->setBoxNeighbor(3, 'T', AccountMenu->getBox(2));
}

void setupSetMoneyGUI(){
    SetMoney = new GUI("MONEY", 3);
    TextBox *setMoney = new TextBox(6, 6, 37);
    TextLabel *money = new TextLabel(13, 10, 23, false);
    Button *finishButton = new Button(18, 13, 13, true, nullptr, nullptr, nullptr, nullptr, true);

    money->setPlaceholderText(withdrawAmount);
    money->setTextLabelAction(SetMoneyOnAccount);
    money->setOutput();

    finishButton->setText(finishText);
    finishButton->setButtonAction(ChangeGUIToAccountMenu);
    finishButton->setOutput();

    setMoney->setText(setMoneyText);
    setMoney->setOutput();

    SetMoney->adBox(money);
    SetMoney->adBox(finishButton);
    SetMoney->adBox(setMoney);

    SetMoney->setBoxNeighbor(0, 'B', SetMoney->getBox(1));
    SetMoney->setBoxNeighbor(1, 'T', SetMoney->getBox(0));
}

void setupDeleteAccountGUI(){
    DeleteAccountGUI = new GUI("DELETE_ACCOUNT", 3);
    Button *confirm = new Button(18, 10, 13);
    Button *cancel = new Button(18, 13, 13);
    TextBox *sure = new TextBox(10, 7, 29);

    confirm->setText(deleteConfirmText);
    confirm->setButtonAction(deleteAccount);
    confirm->setOutput();

    cancel->setText(cancelText);
    cancel->setButtonAction(ChangeGUIToAccountMenu);
    cancel->setOutput();

    sure->setText(sureText);
    sure->setOutput();

    DeleteAccountGUI->adBox(confirm);
    DeleteAccountGUI->adBox(cancel);
    DeleteAccountGUI->adBox(sure);

    DeleteAccountGUI->setBoxNeighbor(0, 'B', DeleteAccountGUI->getBox(1));
    DeleteAccountGUI->setBoxNeighbor(1, 'T', DeleteAccountGUI->getBox(0));
}

void setupDeleteResultGUI(){
    DeleteResult = new GUI("DELETE_RESULT", 3);
    TextBox *description = new TextBox(5, 9, 37);
    Button *finishButton = new Button(19, 13, 11);
    TextBox *placeholderTextBox = new TextBox(9, 13, 3, true, nullptr, nullptr, nullptr, nullptr, false, true, false);

    finishButton->setText(exitText);
    finishButton->setButtonAction(ChangeGUIToAdmin);
    finishButton->setOutput();

    DeleteResult->adBox(finishButton);
    DeleteResult->adBox(placeholderTextBox);
    DeleteResult->adBox(description);
}

void setupCardsMenuGUI(){
    CardsMenu = new GUI("CARDS_MENU", 3);
    Button *ad = new Button(7, 10, 16);
    Button *del = new Button(26, 10, 16);
    Button *backToMenu = new Button(19, 14, 11);

    ad->setText(adCardText);
    ad->setButtonAction(ChangeGUIToAdCardGUI);
    ad->setOutput();

    del->setText(deleteCardText);
    del->setButtonAction(ChangeGUIToDeleteCardGUI);
    del->setOutput();

    backToMenu->setText(backText);
    backToMenu->setButtonAction(ChangeGUIToAccountMenu);
    backToMenu->setOutput();

    CardsMenu->adBox(ad);
    CardsMenu->adBox(del);
    CardsMenu->adBox(backToMenu);

    CardsMenu->setBoxNeighbor(0, 'R', CardsMenu->getBox(1));
    CardsMenu->setBoxNeighbor(0, 'B', CardsMenu->getBox(2));
    CardsMenu->setBoxNeighbor(1, 'L', CardsMenu->getBox(0));
    CardsMenu->setBoxNeighbor(1, 'B', CardsMenu->getBox(2));
    CardsMenu->setBoxNeighbor(2, 'T', CardsMenu->getBox(0));
}

void setupAdCardGUI(){
    AdCard = new GUI("AD_CARD", 3);
    TextBox *adCardTextBox = new TextBox(6, 6, 37);
    Button *generateCardButton = new Button(16, 10, 17);
    Button *backToAccountMenu = new Button(19, 13, 11);

    adCardTextBox->setText(generateCardText);
    adCardTextBox->setOutput();

    generateCardButton->setText(generateText);
    generateCardButton->setButtonAction(GenerateCard);
    generateCardButton->setOutput();

    backToAccountMenu->setText(backText);
    backToAccountMenu->setButtonAction(ChangeGUIToStart);
    backToAccountMenu->setOutput();

    AdCard->adBox(generateCardButton);
    AdCard->adBox(backToAccountMenu);
    AdCard->adBox(adCardTextBox);

    AdCard->setBoxNeighbor(0, 'B', AdCard->getBox(1));
    AdCard->setBoxNeighbor(1, 'T', AdCard->getBox(0));
}

void setupDeleteCardGUI(){
    DeleteCard = new GUI("INSERT_CARD", 3);
    TextBox *cardTextBox = new TextBox(6, 6, 37);
    TextLabel *cardTextLabel = new TextLabel(16, 10, 17, false);
    Button *backButton = new Button(19, 13, 11);

    cardTextBox->setText(insertCardText);
    cardTextBox->setOutput();

    cardTextLabel->setPlaceholderText(cardNumberText);
    cardTextLabel->setTextLabelAction(removeCard);
    cardTextLabel->setOutput();

    backButton->setText(backText);
    backButton->setButtonAction(ChangeGUIToCardsMenu);
    backButton->setOutput();

    DeleteCard->adBox(cardTextLabel);
    DeleteCard->adBox(backButton);
    DeleteCard->adBox(cardTextBox);

    DeleteCard->setBoxNeighbor(0, 'B', DeleteCard->getBox(1));
    DeleteCard->setBoxNeighbor(1, 'T', DeleteCard->getBox(0));
}

void setupCardFinishGUI(){
    CardFinish = new GUI("CARD_FINISH", 3);
    TextBox *result = new TextBox(5, 9, 37);
    Button *finishButton = new Button(19, 13, 11);
    TextBox *placeholderTextBox = new TextBox(9, 13, 3, true, nullptr, nullptr, nullptr, nullptr, false, true, false);

    finishButton->setText(exitText);
    finishButton->setButtonAction(ChangeGUIToAccountMenu);
    finishButton->setOutput();

    CardFinish->adBox(finishButton);
    CardFinish->adBox(placeholderTextBox);
    CardFinish->adBox(result);
}

void setupCreateAccountGUI(){
    CreateAccount = new GUI("CREATE_ACCOUNT", 3);
    TextBox *createInfo = new TextBox(5, 9, 37);
    Button *enterButton = new Button(19, 13, 11);
    TextBox *placeholderTextBox = new TextBox(9, 13, 3, true, nullptr, nullptr, nullptr, nullptr, false, true, false);

    enterButton->setText(enterText);
    enterButton->setButtonAction(EnterAccount);
    enterButton->setOutput();

    CreateAccount->adBox(enterButton);
    CreateAccount->adBox(placeholderTextBox);
    CreateAccount->adBox(createInfo);
}


// SETUPS

void SETUP_TEXTS(){

// insertCardText
insertCardText["EN"] = "INSERT CARD";
insertCardText["PL"] = "WLOZ KARTE";

// adminText
adminText["EN"] = "ADMIN";
adminText["PL"] = "ADMIN";

// withdrawText
withdrawText["EN"] = "WITHDRAW";
withdrawText["PL"] = "WYPLAC";

// depositText
depositText["EN"] = "DEOPSIT";
depositText["PL"] = "WPLAC";

// exitText
exitText["EN"] = "EXIT";
exitText["PL"] = "WYJDZ";

// backText
backText["EN"] = "BACK";
backText["PL"] = "WROC";

// cardNumberText
cardNumberText["EN"] = "CARD NUMBER";
cardNumberText["PL"] = "NUMER KARTY";

// wrongNumberText
wrongNumberText["EN"] = "INCORRECT NUMBER";
wrongNumberText["PL"] = "NIEPOPRAWNY NUMER";

// depositMoneyText
depositMoneyText["EN"] = "INSERT AMOUNT";
depositMoneyText["PL"] = "PODAJ KWOTE";

// insertMoneyText
insertMoneyText["EN"] = "TYPE-QUANTITY";
insertMoneyText["PL"] = "NOMINAL-ILOSC";

// moneyInsertedText
moneyInsertedText["EN"] = "MONEY DEPOSITED";
moneyInsertedText["PL"] = "WPLACONO PIENIADZE";

// moneyInsertErrorText
moneyInsertErrorText["EN"] = "WRONG INPUT";
moneyInsertErrorText["PL"] = "ZLE WARTOSCI";

// finishText
finishText["EN"] = "FINISH";
finishText["PL"] = "ZAKONCZ";

// endingText
endingText["EN"] = "OPERATION FINISHED";
endingText["PL"] = "OPERACJA ZAKONCZONA";

// customText
customText["EN"] = "CUSTOM";
customText["PL"] = "WLASNE";

// TakeOutCardText
TakeOutCardText["EN"] = "TAKE OUT CARD";
TakeOutCardText["PL"] = "ZABIERZ KARTE";

// withdrawInfoText
withdrawInfoText["EN"] = "INSERT AMOUNT";
withdrawInfoText["PL"] = "PODAJ KWOTE";

// withdrawAmount
withdrawAmount["EN"] = "AMOUNT";
withdrawAmount["PL"] = "WARTOSC";

// successText
successText["EN"] = "OPERATION SUCCESSFUL";
successText["PL"] = "OPERACJA UDANA";

// failureText
failureText["EN"] = "OPERATION FAILED";
failureText["PL"] = "OPERACJA NIEUDANA";

// failureDescText
failureDescText["EN"] = "INSUFFICIENT FUNDS IN THE ACCOUNT";
failureDescText["PL"] = "NIEWYSTARCZAJACE SRODKI NA KONCIE";

// failureDescText2
failureDescText2["EN"] = "WRONG MONEY AMOUNT";
failureDescText2["PL"] = "NIEPRAWIDLOWA ILOSC";

// casketMoneyErrorText
casketMoneyErrorText["EN"] = "INSUFFICIENT FUNDS IN THE CASKET";
casketMoneyErrorText["PL"] = "NIEWYSTARCZAJACE SRODKI W KASETCE";

// bankText
bankText["EN"] = "BANK";
bankText["PL"] = "BANK";

// enterText
enterText["EN"] = "ENTER";
enterText["PL"] = "WEJDZ";

// passwordText
passwordText["EN"] = "PASSWORD";
passwordText["PL"] = "HASLO";

// insertPasswordText
insertPasswordText["EN"] = "INSERT PASSWORD";
insertPasswordText["PL"] = "PODAJ HASLO";

// wrongPasswordText
wrongPasswordText["EN"] = "INCORRECT PASSWORD";
wrongPasswordText["PL"] = "NIEPOPRAWNE HASLO";

// accountText
accountText["EN"] = "ACCOUNTS";
accountText["PL"] = "KONTA";

// casketText
casketText["EN"] = "CASKET";
casketText["PL"] = "KASETKA";

// backToBankText
backToBankText["EN"] = "BACK";
backToBankText["PL"] = "WROC";

// setMoneyText
setMoneyText["EN"] = "SET VALUES";
setMoneyText["PL"] = "USTAW WARTOSCI";

// moneySetText
moneySetText["EN"] = "UPDATED";
moneySetText["PL"] = "USTAWIONO";

// moneySetErrorText
moneySetErrorText["EN"] = "WRONG VALUES";
moneySetErrorText["PL"] = "BLEDNE WARTOSCI";

// insertAccountNumberText
insertAccountNumberText["EN"] = "ENTER ACCOUNT NUMBER";
insertAccountNumberText["PL"] = "PODAJ NUMER KONTA";

// loginText
loginText["EN"] = "ACCOUNT NUMBER";
loginText["PL"] = "NUMER KONTA";

// cardsMenuText
cardsMenuText["EN"] = "MANAGE CARDS";
cardsMenuText["PL"] = "ZARZADZAJ KARTAMI";

// moneyText
moneyText["EN"] = "EDIT BALANCE";
moneyText["PL"] = "EDYTUJ SALDO";

// deleteText
deleteText["EN"] = "DELETE ACCOUNT";
deleteText["PL"] = "USUN KONTO";

// setAccountMoneyText
setAccountMoneyText["EN"] = "SET NEW BALLANCE";
setAccountMoneyText["PL"] = "USTAW NOWE SALDO";

// moneySetedText
moneySetedText["EN"] = "NEW BALLANCE SETED";
moneySetedText["PL"] = "USTAWIONO NOWE SALDO";

// notEnoughMoneyText
notEnoughMoneyText["EN"] = "BALANCE CAN'T BE BELOW 0!";
notEnoughMoneyText["PL"] = "SALDO NIE MOZE BYC MNIEJSZE NIZ 0!";

// deleteConfirmText
deleteConfirmText["EN"] = "CONFIRM";
deleteConfirmText["PL"] = "POTWIERDZ";

// cancelText
cancelText["EN"] = "CANCEL";
cancelText["PL"] = "ANULUJ";

// sureText
sureText["EN"] = "CONFIRM ACCOUNT DELETION";
sureText["PL"] = "POTWIERDZ USUNIECIE KONTA";

// AccountDeletedText
accountDeletedText["EN"] = "ACCOUNT DELETED SUCCESSFULLY";
accountDeletedText["PL"] = "POMYSLNIE USUNIETO KONTO";

// AccountNotDeletedText
accountNotDeletedText["EN"] = "ACCOUNT DELETION FAILED";
accountNotDeletedText["PL"] = "NIE UDALO SIE USUNAC KONTA";

// adCardText
adCardText["EN"] = "AD CARD";
adCardText["PL"] = "DODAJ KARTE";

// generateCardText
generateCardText["EN"] = "GENERATE CARD";
generateCardText["PL"] = "GENERUJ KARTE";

// generateText
generateText["EN"] = "GENERATE";
generateText["PL"] = "GENERUJ";

// deleteCardText
deleteCardText["EN"] = "DELETE CARD";
deleteCardText["PL"] = "USUN KARTE";

// selectCardText
selectCardText["EN"] = "SELECT CARD NUMBER";
selectCardText["PL"] = "WYBIERZ NUMER KARTY";

// insertCardNumberText
insertCardNumberText["EN"] = "SELECT CARD NUMBER";
insertCardNumberText["PL"] = "WYBIERZ NUMER KARTY";

// cardGeneratedText
cardGeneratedText["EN"] = "YOUR NEW CARD'S NUMBER IS ";
cardGeneratedText["PL"] = "NUMER TWOJEJ NOWEJ KARTY TO ";

// cardGenerationFailedText
cardGenerationFailedText["EN"] = "FAILED TO GENERATE CARD";
cardGenerationFailedText["PL"] = "NIE UDALO SIE UTWORZYC KARTY";

// cardDeletedText
cardDeletedText["EN"] = "CARD DELETED";
cardDeletedText["PL"] = "USUNIETO KARTE";

// cardDeletionFailedText
cardDeletionFailedText["EN"] = "FAILED TO DELETE CARD";
cardDeletionFailedText["PL"] = "NIE UDALO SIE USUNAC KARTY";

// cardFinishText
cardFinishText["EN"] = "card generation / deletion result";
cardFinishText["PL"] = "wynik generacji / usuniecia karty";

// createText
createText["EN"] = "CREATE";
createText["PL"] = "STWORZ";

// WIPAccountText
WIPAccountText["EN"] = "YOUR NEW ACCOUNT NUMBER: ";
WIPAccountText["PL"] = "NUMER TWOJEGO NOWEGO KONTA: ";

// AccountText
AccountText["EN"] = "WIP + NUMBER";
AccountText["PL"] = "WIP + NUMER";

// FailedAccountText
FailedAccountText["EN"] = "FAILED TO CREATE ACCOUNT";
FailedAccountText["PL"] = "NIE UDALO SIE ZALOZYC KONTA";


// emptyText
emptyText["EN"] = "";
emptyText["PL"] = "";
}

void SETUP(){
    cout<<"Setting up ATM:"<<endl<<endl;

    srand (time(NULL));

    cout<<"Setting texts:";
    SETUP_TEXTS();
    cout<<" - done"<<endl;

    cout<<"StartGUI";
    setupStartGUI();
    cout<<" - done"<<endl<<"InputCardGUI";
    setupInsertCardGUI();
    cout<<" - done"<<endl<<"ChoiceGUI";
    setupChoiceGUI();
    cout<<" - done"<<endl<<"DepositGUI";
    setupDepositGUI();
    cout<<" - done"<<endl<<"TakeOutCardGUI";
    setupTakeOutCardGUI();
    cout<<" - done"<<endl<<"WithdrawGUI";
    setupWithdrawGUI();
    cout<<" - done"<<endl<<"CustomWithdrawGUI";
    setupCustomWithdrawGUI();
    cout<<" - done"<<endl<<"WithdrawResultGUI";
    setupWithdrawResultGUI();
    cout<<" - done"<<endl;

    cout<<endl<<"Setting up Bank:"<<endl<<endl;

    cout<<"BankGUI";
    setupBankGUI();
    cout<<" - done"<<endl<<"setupPasswordGUI";
    setupPasswordGUI();
    cout<<" - done"<<endl<<"setupAdminGUI";
    setupAdminGUI();
    cout<<" - done"<<endl<<"setupCasketGUI";
    setupCasketGUI();
    cout<<" - done"<<endl<<"setupCasketGUI";
    setupCasketGUI();
    cout<<" - done"<<endl<<"setupLoginGUI";
    setupLoginGUI();
    cout<<" - done"<<endl<<"setupAccountMenuGUI";
    setupAccountMenuGUI();
    cout<<" - done"<<endl<<"setupSetMoneyGUI";
    setupSetMoneyGUI();
    cout<<" - done"<<endl<<"setupDeleteAccountGUI";
    setupDeleteAccountGUI();
    cout<<" - done"<<endl<<"setupDeleteResultGUI";
    setupDeleteResultGUI();
    cout<<" - done"<<endl<<"setupCardsMenuGUI";
    setupCardsMenuGUI();
    cout<<" - done"<<endl<<"setupAdCardGUI";
    setupAdCardGUI();
    cout<<" - done"<<endl<<"setupDeleteCardGUI";
    setupDeleteCardGUI();
    cout<<" - done"<<endl<<"setupCreateAccountGUI";
    setupCardFinishGUI();
    cout<<" - done"<<endl<<"setupCardFinishGUI";
    setupCreateAccountGUI();
    cout<<" - done";

    cout<<"Setting starting values";
    currentGUI = Start;
    currentBox = currentGUI->getBox(0);
    currentBox->setSelect(true);
    cout<<" - done"<<endl;

    cout<<endl<<"Setting up finished";
    system("CLS");
}

void FINISH(){

    cout<< "Closing ATM..."<<endl<<endl;

    // Currents
    currentGUI = nullptr;
    cout << "deleted currentGUI" << endl;
    currentBox = nullptr;
    cout << "deleted currentBox" << endl;

    // ATM
    delete Start;
    cout << "deleted Start" << endl;
    delete InsertCard;
    cout << "deleted InsertCard" << endl;
    delete Choice;
    cout << "deleted Choice" << endl;
    delete Deposit;
    cout << "deleted Deposit" << endl;
    delete Withdraw;
    cout << "deleted Withdraw" << endl;
    delete WithdrawResult;
    cout << "deleted WithdrawResult" << endl;
    delete CustomWithdraw;
    cout << "deleted CustomWithdraw" << endl;
    delete CustomWithdrawResult;
    cout << "deleted CustomWithdrawResult" << endl;
    delete TakeOutCard;
    cout << "deleted TakeOutCard" << endl;

    // Bank
    delete Bank;
    cout << "deleted Bank" << endl;
    delete Password;
    cout << "deleted Password" << endl;
    delete Admin;
    cout << "deleted Admin" << endl;
    delete CasketGUI;
    cout << "deleted CasketGUI" << endl;
    delete Login;
    cout << "deleted Login" << endl;
    delete AccountMenu;
    cout << "deleted AccountMenu" << endl;
    delete SetMoney;
    cout << "deleted SetMoney" << endl;
    delete DeleteAccountGUI;
    cout << "deleted DeleteAccountGUI" << endl;
    delete CardsMenu;
    cout << "deleted CardsMenu" << endl;
    delete AdCard;
    cout << "deleted AdCard" << endl;
    delete DeleteCard;
    cout << "deleted DeleteCard" << endl;
    delete CreateAccount;
    cout << "deleted CreateAccount" << endl;

    // Closing files
    if(Account.is_open())
        Account.close();
    cout << "closed Account" << endl;

    if(Casket.is_open())
        Casket.close();
    cout << "closed Casket" << endl;

    system("cls");

}

///---------------------------------MAIN PROGRAM---------------------------------------------------------------------------------------------------------------------------------------------------

int main(){
    SETUP();

    string backgroundInput = "", admin = "admin", stop = "stop";

    int ic;
    char cc;
    do{
        cout<<"\033[H";
        currentGUI->UpdateGUI();
        cout << "\033[H\033[21B";
        //cout << "[" << backgroundInput << "]    " << endl;

        while(!_kbhit()){}
        ic = _getch();
        cc = ic;
        switch(ic)
        {
        case 224:  // Arrows
            switch (_getch())
            {
            case 72: // Up
                currentBox->setSelect(false);
                currentBox = currentBox->Switch('T');
                currentBox->setSelect(true);
                break;
            case 80: // Down
                currentBox->setSelect(false);
                currentBox = currentBox->Switch('B');
                currentBox->setSelect(true);
                break;
            case 75: // Left
                currentBox->setSelect(false);
                currentBox = currentBox->Switch('L');
                currentBox->setSelect(true);
                break;
            case 77: // Right
                currentBox->setSelect(false);
                currentBox = currentBox->Switch('R');
                currentBox->setSelect(true);
                break;
            default:
                break;
            }
        default:
            if(ic == 13){   //  Enter
                currentBox->doAction();
            }

            else if((ic >= 47 && ic <= 57) || ic == 45){  // 0-9 + -
                if(currentBox->getType() == "TextLabel"){
                    currentBox->inputText(cc);
                }
                else{
                    backgroundInput = backgroundInput + cc;
                }
            }

            else if(ic >= 97 && ic <= 122){ //  a-z
                backgroundInput = backgroundInput + cc;
            }

            else if(ic >= 65 && ic <= 90){ //  A-Z
                backgroundInput = backgroundInput + (char)(ic + 32);
            }

            else if(ic == 8){   //  Backspace
                if(currentBox->getType() == "TextLabel"){
                    if(currentBox->getInputedText().length()>0)
                        currentBox->subInputText();
                }
                else{
                    if(backgroundInput.length()>0)
                        backgroundInput.pop_back();
                }
            }
            break;
        }

        if(backgroundInput == admin){
            if(currentGUI->getName() == "START"){
                if(currentGUI->getBox(1)->isVisible())
                    currentGUI->setBoxVisible(1, false);
                else
                    currentGUI->setBoxVisible(1, true);
                backgroundInput = "";
            }
        }

        else{
            if(!(stop.find(backgroundInput) != string::npos)){
                if(!(admin.find(backgroundInput) != string::npos))
                    backgroundInput = cc;
            }
        }
    }
    while(backgroundInput != "stop");

    FINISH();

    return 0;
}

