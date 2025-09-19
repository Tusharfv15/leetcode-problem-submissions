class Spreadsheet {
public:
    map<int, vector<int>> spreadsheet;

    Spreadsheet(int rows) {
        for (int i = 1; i <= rows; i++) {
            spreadsheet[i] = vector<int>(26, 0);
        }
    }
    
    void setCell(string cell, int value) {
        char col = cell[0];
        string row = cell.substr(1);
        int numRow = stoi(row);
        int colIdx = col - 'A';
        spreadsheet[numRow][colIdx] = value;
    }
    
    void resetCell(string cell) {
        char col = cell[0];
        string row = cell.substr(1);
        int numRow = stoi(row);
        int colIdx = col - 'A';
        spreadsheet[numRow][colIdx] = 0;
    }

    int getOperandValue(string part) {
        if (isdigit(part[0])) {
            return stoi(part);
        }
        char col = part[0];
        string row = part.substr(1);
        int numRow = stoi(row);
        int colIdx = col - 'A';
        return spreadsheet[numRow][colIdx];
    }
    
    int getValue(string formula) {
        if (formula[0] == '=') formula = formula.substr(1);
        
        size_t plusPos = formula.find('+');
        if (plusPos == string::npos) {
            return getOperandValue(formula);
        }

        string left = formula.substr(0, plusPos);
        string right = formula.substr(plusPos + 1);

        return getOperandValue(left) + getOperandValue(right);
    }
};
