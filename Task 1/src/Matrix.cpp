#include "Matrix.h"
#include<iostream>
Matrix::Matrix()
{
    rows = 0 ;
    columns = 0 ;
}
Matrix::Matrix(int rows, int columns )
{
    this->rows = rows;
    this->columns = columns;
        this->data = new int *[rows];
        for(int i=0;i < rows;i++)
            this->data[i]=new int[columns];
}
//---------------------------------------------
void Matrix::setRows(int x){rows=x;}
void Matrix::setColumns(int y){columns=y;}
int Matrix::getRows(){return rows;}
int Matrix::getColumns(){return columns;}

//----------------------------------------------------
//(Yasser Ashraf Salah El Din ------> 20170331)
Matrix Matrix::operator+(Matrix mat)
{
    if(this->rows == mat.rows && this->columns == mat.columns)
    {
        for(int i = 0; i < this->rows; i++){
            for(int j = 0; j < this->columns; j++)
            {
                this->data[i][j] = mat.data[i][j]+ this->data[i][j];
            }
        }
    }
    else{
        std::cout<<"Not Equal!" <<std::endl;
    }
    return (*this);
}
//------------------------------------------------------------------
Matrix Matrix::operator- (Matrix mat)
{
    if(this->rows == mat.rows && this->columns == mat.columns)
    {
        for(int i = 0; i < this->rows; i++){
            for(int j = 0; j < this->columns; j++)
            {
                this->data[i][j] = this->data[i][j] - mat.data[i][j];
            }
        }
    }
    else{
        std::cout<<"Not Equal!" <<std::endl;
    }
    return (*this);
}
//--------------------------------------------
Matrix Matrix::operator* (Matrix mat)
{
    if(this->columns == mat.rows){
        for(int i = 0; i < this->rows; i++)
        {
            for(int j = 0; j < mat.columns; j++ )
            {
                for( int y = 0; y < this->columns; y++)
                {
                    this->data[i][j]+= (this->data[i][y] * mat.data[y][j]);
                }
            }
        }
    }
    return (*this);
}
//----------------------------------------------------
Matrix Matrix::operator+(int scalar)
{
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->columns; j++)
        {
            this->data[i][j] = this->data[i][j] + scalar;
        }
    }
    return (*this);
}
//------------------------------------------------------
Matrix Matrix::operator-(int scalar)
{
    for(int i = 0; i < this->rows; i++)
    {
        for(int j = 0 ; j < this->columns; j++)
        {
            this->data[i][j] =(this->data[i][j] - scalar);
        }
    }
    return (*this);
}
//------------------------------------------------------
Matrix Matrix::operator*(int scalar)
{
    for(int i = 0; i < this->rows; i++)
    {
        for(int j = 0 ; j < this->columns; j++)
        {
            this->data[i][j] =(this->data[i][j] * scalar);
        }
    }
    return (*this);
}
Matrix Matrix::operator = (Matrix mat)
{
    if(this->rows == mat.rows && this->columns == mat.columns)
    {
        for(int i = 0; i < this->rows; i++){
            for(int j = 0; j < this->columns; j++)
            {
                this->data[i][j] = mat.data[i][j];
            }
        }
    }
    else{std::cout<<"Not EQUAL!"<<std::endl;}
    return (*this);
}
//--------------------------------------------------------
//(Heba Muhammed Ali -----------> 20170329)
bool Matrix::operator== (Matrix mat)
{
    bool status = true;
    if(this->columns == mat.columns && this->rows == mat.rows)
    {
        for(int i = 0; i < this->rows; i++)
        {
            for(int j = 0; j < this->columns; j++)
            {
                if( mat.data[i][j] != this->data[i][j])
                {
                    status = false;
                    return status;
                }
            }
        }
    }
    else{ status = false;}
    return status;
}
//----------------------------------------------
bool Matrix::operator !=(Matrix mat)
{
    bool status = false;
    if(this->columns == mat.columns&& this->rows == mat.rows)
    {
        for(int i = 0; i < this->rows; i++)
        {
            for(int j = 0; j < this->columns; j++)
            {
                if( this->data[i][j] != mat.data[i][j])
                {
                    status = true;
                    return status;
                }
            }
        }
    }
    else{status=true;}
    return status;
}
//--------------------------------------------------------
bool Matrix::isSquare ()
{
    bool status = true;
    if(this->columns != this->rows)
    {
        status = false;
    }
    return status;
}
//----------------------------------------------------------
bool Matrix::isSymetric()
{
    bool status= true;

    if( this->columns == this->rows )
    {
        for(int i = 0; i < this->rows; i++)
        {
            for(int j = 0; j < this->columns; j++)
            {
                if(this->data[i][j] != this->data[j][i])
                {
                    status = false;
                    return status;
                }
            }
        }
    }
    else{status = false;}
    return status;
}
//--------------------------------------------------------------
bool Matrix::isIdentity()
{
    bool status= true;
    if(isSymetric())
    {
        for(int i = 0; i < this->rows; i++)
        {
            for(int j = 0; j < this->columns; j++)
            {
                if(i == j)
                {
                    if(this->data[i][j] != 1)
                    {
                        status = false;
                        return status;
                    }
                }
                else{
                    if(this->data[i][j] != 0)
                    {
                        status = false;
                        return status;
                    }
                }
            }
        }
    }
    else{
        status = false;
        return status;
    }
    return status;
}
//-----------------------------------------------------------
Matrix Matrix::transpose(Matrix mat)
{
    this->rows = mat.rows;
    this->columns = mat.columns;
    int sizee = mat.rows * mat.columns;
    int data[sizee];
    int c = 0;
    for(int i = 0; i < this->rows; i++)
    {
        for(int j = 0; j < this->columns; j++)
        {
            data[c] = this->data[j][i];
            c++;
        }
    }
    int z=0;
    for(int i = 0; i < this->rows; i++)
    {
        for(int j = 0; j < this->columns; j++)
        {
            this-> data[i][j] = data[z];
            z++;
            if(z==sizee){break;}
        }
    }
    return (*this);
}
//-------------------------------------------------------
//(Omar Tarek Abd El Aziz ------> 20170178).
Matrix Matrix::operator+= (Matrix mat)
{
    if(this->rows == mat.rows &&this->columns == mat.columns)
    {
        for(int i = 0; i < this->rows; i++){
            for(int j = 0; j < this->columns; j++){
                this->data[i][j] = this->data[i][j] + mat.data[i][j];
            }
        }
    }
    return (*this);
}
//-------------------------------------------------------
Matrix Matrix::operator+= (int scalar)
{
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->columns; j++){
            this->data[i][j] = (this->data[i][j] + scalar);
        }
    }
    return (*this);
}
//---------------------------------------------------------
Matrix Matrix::operator-= (Matrix mat)
{
    if(this->rows == mat.rows &&this->columns == mat.columns)
    {
        for(int i = 0; i < this->rows; i++){
            for(int j = 0; j < this->columns; j++){
                this->data[i][j] = (this->data[i][j] - mat.data[i][j]);
            }
        }
    }
    return (*this);
}
//-------------------------------------------------------
Matrix Matrix:: operator-=(int scalar)
{
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->columns; j++){
            this->data[i][j] = (this->data[i][j] - scalar);
        }
    }
    return (*this);
}
//----------------------------------------------------------------------------
Matrix Matrix::operator++(int unused)// Add 1 to each element ++mat
{
    for(int i = 0; i < this->rows ; i++)
    {
        for(int j = 0; j < this->columns ; j++)
        {
            this->data[i][j] = ((this->data[i][j]) + 1);
        }
    }
    return (*this);
}
//------------------------------------------------------------------------------
Matrix Matrix::operator--(int unused)// subtract 1 to each element --mat
{
    for(int i = 0; i < this->rows ; i++)
    {
        for(int j = 0; j < this->columns ; j++)
        {
            this->data[i][j] = ((this->data[i][j]) - 1);
        }
    }
    return (*this);
}
//--------------------------------------------------------------------------------*/

