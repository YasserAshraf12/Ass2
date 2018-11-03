#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
class Matrix
{
    friend std::ostream& operator<< (std::ostream& out , Matrix aa);
    friend std::istream& operator>> (std::istream& in, Matrix& bb);
private:
    int rows, columns;
    int** data;
public:
    Matrix();
    Matrix(int, int);
    void setRows(int);
    void setColumns(int);
    int getRows();
    int getColumns();
    //------------------------------
    Matrix operator+ (Matrix mat);
    Matrix operator- (Matrix mat);
    Matrix operator* (Matrix mat);
    Matrix operator+ (int scalar);
    Matrix operator- (int scalar);
    Matrix operator* (int scalar);
    //---------------------------------------
    bool operator== (Matrix mat);
    bool operator!= (Matrix mat);
    bool isSquare();
    bool isSymetric();
    bool isIdentity();
    Matrix transpose(Matrix mat);
    //---------------------------------------------
    Matrix operator+=(Matrix mat);
    Matrix operator ++(int unused);
    Matrix operator --(int unused);
    Matrix operator -=(Matrix mat);
    Matrix operator +=(int scalar);
    Matrix operator -=(int scalar);
    //-------------------------------------------
    Matrix operator =(Matrix mat);
};

#endif // MATRIX_H
