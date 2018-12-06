//nn9, nnnine
//Owen Watts

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
//#include <windows.h>
using namespace std;

COORD coord = { 0,0 }; // this is global variable
//center of axis is set to the top left corner of the screen

/*
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
*/


class Piece
{
private:
    int xpos;
    int ypos;
    //    //int distanceTravelled;
    char colour;
    string pieceNumber;
    int originalx;
    int originaly;
    int goalx;
    int goaly;
public:
    //Piece(int x,int y,char c,int p,int d);
    Piece(int x,int y,char c,string p);
    Piece();
    int getx();
    int gety();
    char getc();
    string getPname();
    //int getd();
    void setx(int x);
    void sety(int y);
    //void setd();
    void pieceDisplay();
    //void asciiPiece();
};

Piece::Piece(int x,int y,char c,string n)
{
    //xpos=0;
    xpos=x;
    //xpos=xpos*5;
    //ypos=0;
    ypos=y;
    //ypos=ypos*3;
    //colour='p';
    colour=c;
    //char extra1[0];
    //itoa(n,extra1,10);
    //pieceNumber="F";
    //pieceNumber=colour+extra1;
    pieceNumber=n;
}

Piece::Piece()
{
    xpos=0;
    ypos=0;
    //distanceTravelled=0;
    colour='f';
    pieceNumber="NO";
    originalx=0;
    originaly=0;
    goalx=5;
    goaly=5;
}

int Piece::getx()
{
    return xpos;
}

int Piece::gety()
{
    return ypos;
}

char Piece::getc()
{
    return colour;
}

string Piece::getPname()
{
    string pname=colour+pieceNumber;
    return pname;
}

void Piece::setx(int x)
{
    xpos=x;
}

void Piece::sety(int y)
{
    ypos=y;
}

void Piece::pieceDisplay()
{
    gotoxy(xpos*5,ypos*3);
    cout<<colour<<pieceNumber<<endl;
}

/*
void Piece::asciiPiece()
{
    system("cls");
    gotoxy(1,9);
    cout<<"  __  ";
    gotoxy(2,9);
    cout<<" (  ) ";
    gotoxy(3,9);
    cout<<"  ||  ";
    gotoxy(4,9);
    cout<<" /__\\ ";
    gotoxy(5,9);
    cout<<"(____)";
    gotoxy(0,33);
}
 */

int diceRoll()
{
    srand(time(NULL));
    ///DICE!
    //create two dice
    int Dice1=0;
    int Dice2=0;
    
    Dice1=(rand()%3)+1;
    Dice2=(rand()%3)+1;
    
    int DiceROLL=Dice1+Dice2;
    //cout<<Dice1<<"  "<<Dice2<<" Sum: "<<DiceROLL<<endl;
    return DiceROLL;
}

void moveQs(Piece Piece1)
{
    gotoxy(0,36);
    int movePX=0;
    int movePY=0;
    cout<<"okay, how many Left or right? -> ";
    cin>>movePX;
    cout<<"and how many Up/Down? -> ";
    cin>>movePY;
}

int genboardstart1(Piece Piece1)
{
    //Piece ()
    system("cls");
    gotoxy(1,1);
    cout << "_______________________________________________________" << endl;
    cout << "|XXXXX|XXXXX|XXXXX|XXXXX|XXXXX|     |     |XXXXX|XXXXX|" << endl;
    cout << "|XXXXX|XXXXX|XXXXX|XXXXX|XXXXX| b1  | b2  |XXXXX|XXXXX| 1" << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
    cout << "|XXXXX|     |     |     |     |BluSt|     |     |XXXXX|" << endl;
    cout << "|XXXXX|     |     |     |     |     |     |     |XXXXX| 2" << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
    cout << "|     |RedSt|XXXXX|XXXXX|     |XXXXX|XXXXX|     |XXXXX|" << endl;
    cout << "| r2  |     |XXXXX|XXXXX|     |XXXXX|XXXXX|     |XXXXX| 3" << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
    cout << "|     |     |XXXXX|XXXXX|     |XXXXX|XXXXX|     |XXXXX|" << endl;
    cout << "| r1  |     |XXXXX|XXXXX|     |XXXXX|XXXXX|     |XXXXX| 4" << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
    cout << "|XXXXX|     |     |     |GOAL |     |     |     |XXXXX|" << endl;
    cout << "|XXXXX|     |     |     |     |     |     |     |XXXXX| 5" << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
    cout << "|XXXXX|     |XXXXX|XXXXX|     |XXXXX|XXXXX|GrnSt|     |" << endl;
    cout << "|XXXXX|     |XXXXX|XXXXX|     |XXXXX|XXXXX|     |  g1 | 6" << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
    cout << "|XXXXX|     |XXXXX|XXXXX|     |XXXXX|XXXXX|     |     |" << endl;
    cout << "|XXXXX|     |XXXXX|XXXXX|     |XXXXX|XXXXX|     |  g2 | 7" << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
    cout << "|XXXXX|     |     |YllSt|     |     |     |     |XXXXX|" << endl;
    cout << "|XXXXX|     |     |     |     |     |     |     |XXXXX| 8" << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
    cout << "|XXXXX|XXXXX|     |     |XXXXX|XXXXX|XXXXX|XXXXX|XXXXX|" << endl;
    cout << "|XXXXX|XXXXX| y2  | y1  |XXXXX|XXXXX|XXXXX|XXXXX|XXXXX| 9" <<endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
    cout << "   1     2     3     4     5     6     7     8     9   ";
    cout<<endl<<endl;
    
    /*
    gotoxy(Piece1.getx(),Piece1.gety());
    cout<<Piece1.getPname();
    */
     
    //moveQs(Piece1);
    
    //GOAL1(Piece1);
    
}

void GOAL1(Piece Piece1)
{
    char g1p='g';
    while (g1p!='p')
    {
        cout<<"put in p to roll -> ";
        cin>>g1p;
        if (g1p=='p')
        {
            int theroll=diceRoll();
            genboardstart1(Piece1);
            Piece1.pieceDisplay();
            gotoxy(0,33);
            cout<<"you rolled a "<<theroll<<endl;
            int sendToY=Piece1.gety()+theroll;
            Piece1.sety(sendToY);
            cout<<"press any key to display the board"<<endl;
            system("pause");
            genboardstart1(Piece1);
            Piece1.pieceDisplay();
            gotoxy(0,33);
            cout<<"DONE"<<endl;
        }
    }
}


///INT MAIN
int main()
{
    Piece Piece1(1,1,'y',"1");
    //srand(time(NULL));
    int i=0;
    
    char p='n';
    while (i<1)
    {
        cout<<endl;
        cout<<"MZê"<<endl;
        cout<<"ENTER LETTER -> ";
        cin>>p;
        
        if (p=='r')
        {
            diceRoll();
        }
        if (p=='e')
        {
            break;
        }
        
        if (p=='b')
        {
            genboardstart1(Piece1);
        }
        
        if (p=='s')
        {
            cout<<"X: "<<Piece1.getx()<<"\nY: "<<Piece1.gety()<<"\nColour: "<<Piece1.getc()<<"\nName: "<<Piece1.getPname()<<endl;
        }
        
        if (p=='d')
        {
            Piece1.pieceDisplay();
        }
        
        if (p=='p')
        {
            GOAL1(Piece1);
        }
    }
    return 0;
}

