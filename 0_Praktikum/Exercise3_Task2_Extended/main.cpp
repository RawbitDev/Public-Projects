#include <iostream>
#include <string>
using namespace std;


//-----------------------------------------
// SETTINGS:

const int CharsPerField = 13;
// [Default is 10 characters]

const string FieldFillChar = " ";
// [Default is " "]

const string EmptyFieldCharDummy = "_";
// [Default is "_"]

const string Columns[] = {"a", "b", "c", "d", "e", "f", "g", "h"};
// [Default is 8 columns (a - h)]
// (Please note: No numbers allowed, because they're reserved for the row informations)

const int Rows = 8;
// [Default is 8 rows]

/*-----------------------------------------
FIGURES NAMES:

    w - Weiß
    s - Schwarz

    K - Koenig
    D - Dame
    L - Laeufer
    S - Springer
    T - Turm
    B - Bauer                            */

const string    wK = "koenig_w",
                wD = "dame_w",
                wL = "laeufer_w",
                wS = "springer_w",
                wT = "turm_w",
                wB = "bauer_w",

                sK = "koenig_s",
                sD = "dame_s",
                sL = "laeufer_s",
                sS = "springer_s",
                sT = "turm_s",
                sB = "bauer_s";

//-----------------------------------------


// Functions Declaration
int ChangeField(string ColumnInput, int RowInput, string input);
int GetColumnPosition(string ColumnInput);
int GetRowPosition(int RowInput);
int ResetSurface();
int OutputSurface();
int MakeMove(string input);

string FillString(string input, string characters);
string ReadField(string ColumnInput, int RowInput);


// Global consts for the size of the array
const int SizeOfColumns = (sizeof(Columns)/sizeof(Columns[0]));

// Global array for the position of the figures
static string GameSurface[Rows][SizeOfColumns] = {};


// Main Function...
int main()
{  
    ResetSurface();
    OutputSurface();

    //ChangeField("a", 1, wK);
    //OutputSurface();

    //cout << ReadField("a", 1) << endl;

    //ChangeField("b", 3, ReadField("a", 1));
    //ChangeField("a", 1, FillString("", EmptyFieldCharDummy));
    //OutputSurface();

    // Siehe TODO Punkte
    // Input Funktion die erst überprüft und dann in Muster aufteilt


    return 0;
}



// Function that moves the value of one field to another
int MakeMove(string input) {
    string OldColumn = "", NewColumn = "";
    int OldRow = -1, NewRow = -1;

    // Input (z.B. b1-c3) aufteilen [TODO]

    // Moveing the value
    ChangeField(NewColumn, NewRow, ReadField(OldColumn, OldRow));
    ChangeField(OldColumn, OldRow, FillString("", EmptyFieldCharDummy));
}


// Function that searches the right x and y position of the array
string ReadField(string ColumnInput, int RowInput)
{
    // Get the int position of the values using an other function
    int ColumnOutput = GetColumnPosition(ColumnInput), RowOutput = GetRowPosition(RowInput);

    // Read the value of the array position
    if ( (ColumnOutput>=0) && (ColumnOutput<=SizeOfColumns) && (RowOutput>=0) && (RowOutput<=Rows) ) {
        return (GameSurface[RowOutput][ColumnOutput]);
    } else {
        return "";
    }
}


// Function that changes value at the right x and y position of the array
int ChangeField(string ColumnInput, int RowInput, string input)
{
    // Get the int position of the values using an other function
    int ColumnOutput = GetColumnPosition(ColumnInput), RowOutput = GetRowPosition(RowInput);

    // Change the value of the array position
    if ( (ColumnOutput>=0) && (ColumnOutput<=SizeOfColumns) && (RowOutput>=0) && (RowOutput<=Rows) ) {
        GameSurface[RowOutput][ColumnOutput] = FillString(input, FieldFillChar);
    } else {
        return 1;
    }
    return 0;
}


// Function that searches the right position of the column array
int GetColumnPosition(string ColumnInput)
{
    // Get the column position of the input
    for (int i=0; i<SizeOfColumns; i++) {
        if (Columns[i] == ColumnInput) {
            return i;
        }
    }
    // Return -1 so nothing will be changed
    return -1;
}


// Function that checks the position of the row
int GetRowPosition(int RowInput)
{
    if (RowInput <= Rows && RowInput >= 0) {
            return (RowInput-1); // Reducing by 1 because arrays start with 0
    }
    // Return -1 so nothing will be changed
    return -1;
}


// Function that fills the string to a defined number of characters with an other char
string FillString(string input, string characters)
{
    string output = "";
    // Add enough chars so all strings have the same length
    for (int i=0; ((input.length()+output.length()) < CharsPerField); i++) {
        output += characters;
    }
    // Add the original input
    output += input;
    return output;
}


// Function that simply resets the whole surface and adds spaceholders with an defined character
int ResetSurface()
{
    // Fill every field with char dummys
    for (int i=0; i<Rows; i++) {
        for (int j=0; j<SizeOfColumns; j++) {
            GameSurface[i][j] = FillString("", EmptyFieldCharDummy);
        }
    }

    // Spielfiguren aufstellen [TODO]

    return 0;
}


// Function that simply outputs the whole surface
int OutputSurface()
{
    // Output the columns
    cout << "" << FillString("", " ");
    for (int i=0; i<SizeOfColumns; i++) {
        cout << FillString(Columns[i], " ") << " ";
    }

    // Output the rows and fields
    for (int i=0; i<Rows; i++) {
        cout << endl << endl << FillString(to_string(i+1), " ") << " ";
        for (int j=0; j<SizeOfColumns; j++) {
            cout << GameSurface[i][j] << " ";
        }
    }
    cout << endl << endl;
    return 0;
}
