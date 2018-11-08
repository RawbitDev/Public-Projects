#include <iostream>
#include <string>
using namespace std;


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
int ChangeField(char ColumnInput, char RowInput, string input);
int GetColumnPosition(char ColumnInput);
int GetRowPosition(char RowInput);
int ResetSurface();
int OutputSurface();
int MakeMove(string input);

string FillString(string input, string characters);
string ReadField(char ColumnInput, char RowInput);

void ClearConsoleScreen();


// Global array for the position of the figures
static string GameSurface[8][8] = {};
static char Columns[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};



// Main Function...
int main()
{  
    string input = "";

    ResetSurface();
    OutputSurface();

    while (true) {
        cout << "Bitte Zug eingeben (z.B. b1-c3)" << endl << "(Zum Abbrechen geben Sie exit ein): ";
        getline(cin, input);
        if (input == "exit") {
             return 0;
        } else {
            MakeMove(input);
        }
    }

    return 0;
}



// Function that moves the value of one field to another
int MakeMove(string input) {
    char OldColumn = '0', NewColumn = '0';
    char OldRow = '0', NewRow = '0';

    // Input (z.B. b1-c3) aufteilen [TODO]
    OldColumn = input.at(0);
    OldRow = input.at(1);
    NewColumn = input.at(3);
    NewRow = input.at(4);

    if (((ReadField(OldColumn, OldRow)) != (FillString("", "_"))) && ((ReadField(NewColumn, NewRow)) == (FillString("", "_")))) {
        // Moveing the value
        ChangeField(NewColumn, NewRow, ReadField(OldColumn, OldRow));
        ChangeField(OldColumn, OldRow, FillString("", "_"));
        OutputSurface();
    } else if ((ReadField(OldColumn, OldRow)) == (FillString("", "_"))) {
        cerr << "Fehler: Das ausgewaehlte Feld ist nicht besetzt! Bitte versuchen Sie es erneut." << endl;
    } else if ((ReadField(NewColumn, NewRow)) != (FillString("", "_"))) {
        cerr << "Fehler: Das ausgewaehlte Feld ist nicht besetzt! Bitte versuchen Sie es erneut." << endl;
    } else {
        cerr << "Fehler: Ungueltige Eingabe der Felder! Bitte versuchen Sie es erneut." << endl;
    }

    return 0;
}


// Function that searches the right x and y position of the array
string ReadField(char ColumnInput, char RowInput)
{
    // Get the int position of the values using an other function
    int ColumnOutput = GetColumnPosition(ColumnInput), RowOutput = GetRowPosition(RowInput);

    // Read the value of the array position
    if ( (ColumnOutput>=0) && (ColumnOutput<=8) && (RowOutput>=0) && (RowOutput<=8) ) {
        return (GameSurface[RowOutput][ColumnOutput]);
    } else {
        return "";
    }
}


// Function that changes value at the right x and y position of the array
int ChangeField(char ColumnInput, char RowInput, string input)
{
    // Get the int position of the values using an other function
    int ColumnOutput = GetColumnPosition(ColumnInput), RowOutput = GetRowPosition(RowInput);

    // Change the value of the array position
    if ( (ColumnOutput>=0) && (ColumnOutput<=8) && (RowOutput>=0) && (RowOutput<=8) ) {
        GameSurface[RowOutput][ColumnOutput] = FillString(input, " ");
    } else {
        return 1;
    }
    return 0;
}


// Function that searches the right position of the column array
int GetColumnPosition(char ColumnInput)
{
    // Get the column position of the input
    for (int i=0; i<8; i++) {
        if (Columns[i] == ColumnInput) {
            return i;
        }
    }
    // Return -1 so nothing will be changed
    return -1;
}


// Function that checks the position of the row
int GetRowPosition(char RowInput)
{
    int RowOutput = 0;
    RowOutput = RowInput-48;

    if (RowOutput <= 8 && RowOutput >= 0) {
            return (RowOutput-1); // Reducing by 1 because arrays start with 0
    }
    // Return -1 so nothing will be changed
    return -1;
}


// Function that fills the string to a defined number of characters with an other char
string FillString(string input, string characters)
{
    string output = "";
    // Add enough chars so all strings have the same length
    for (int i=0; ((input.length()+output.length()) < 10); i++) {
        output += characters;
    }
    // Add the original input
    output += input;
    return output;
}


// Function that simply resets the whole surface and adds spaceholders
int ResetSurface()
{
    // Fill every field with char dummys
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            GameSurface[i][j] = FillString("", "_");
        }
    }

    // White figures
    ChangeField('a', '1', wT);
    ChangeField('b', '1', wS);
    ChangeField('c', '1', wL);
    ChangeField('d', '1', wD);
    ChangeField('e', '1', wK);
    ChangeField('f', '1', wL);
    ChangeField('g', '1', wS);
    ChangeField('h', '1', wT);

    // Black figures
    ChangeField('a', '8', sT);
    ChangeField('b', '8', sS);
    ChangeField('c', '8', sL);
    ChangeField('d', '8', sD);
    ChangeField('e', '8', sK);
    ChangeField('f', '8', sL);
    ChangeField('g', '8', sS);
    ChangeField('h', '8', sT);

    // Both figures
    for (int i=0; i<8; i++) {
        ChangeField(Columns[i], '2', wB);
        ChangeField(Columns[i], '7', sB);
    }

    // Outputs the surface using our own function below
    OutputSurface();
    return 0;
}


// Function that simply outputs the whole surface
int OutputSurface()
{
    // Clear the console screen using our own function below
    ClearConsoleScreen();

    string temp = "";
    // Output the columns
    cout << "" << FillString("", " ");
    for (int i=0; i<8; i++) {
        temp = Columns[i];
        cout << string(FillString(temp, " ")) << " ";
    }

    // Output the rows and fields
    for (int i=0; i<8; i++) {
        cout << endl << endl << FillString(to_string(i+1), " ") << " ";
        for (int j=0; j<8; j++) {
            cout << GameSurface[i][j] << " ";
        }
    }
    cout << endl << endl;
    return 0;
}


// Function that "clears" the console output (It simply skips alot of lines)
void ClearConsoleScreen()
{
    for (int i = 0; i <= 10; i++)
      printf("\n\n\n\n\n\n\n\n\n\n");
    }
