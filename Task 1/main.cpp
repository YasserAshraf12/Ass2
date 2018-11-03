#include <iostream>
#include "Matrix.h"
using namespace std;
istream& operator>> (istream& in,  Matrix& mat)
{
    int rows1 = mat.rows;
    int columns1 = mat.columns;
    for(int i = 0;i < rows1; i++)
    {
        for(int j = 0; j < columns1; j++)
        {
            in >> mat.data[i][j];
        }
    }
    return in;
}
//--------------------------------------------
ostream& operator<< (ostream& out, Matrix mat)
{
    int rows1 = mat.rows;
    int columns1 = mat.columns;
    for(int i=0;i < rows1;i++)
    {
        for(int j=0;j < columns1; j++)
        {
            out<< mat.data[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return out;
}

//----------------------------------------------
int main()
{
    int x, y;
    std::cout<<"Please Enter Number of First Matrix Rows and Columns Separated by Spaces:   ";
    std::cin >> x >> y;
    Matrix mat1(x, y);
    std::cout<<"Please Enter Number of Second Matrix Rows and Columns Separated by Spaces:   ";
    std::cin >> x >> y;
    Matrix mat2(x, y);
    cin >> mat1;
    cout <<endl;
    cin>>mat2;
    /*std::cout << endl;
    cout << (mat1 + mat2);
    std::cout << endl;
    cout << (mat1 - mat2);
    std::cout << endl;
    cout<< (mat1 * mat2);
    std::cout << endl;
    cout<< (mat1+= 3);
    std::cout << endl;
    cout<< (mat1-= 3);
    std::cout << endl;
    cout<< (mat1 - 3 );
    std::cout << endl;
    cout<< (mat1 + 3);
    std::cout << endl;
    cout<<(mat1 * 3);
    std::cout << endl;
    (mat1++);
    cout<<(mat1);
    std::cout << endl;
    cout<<(mat1--);
    std::cout << endl;*/
   // mat1 = mat2;
    //cout << mat1;
    //.........

  /*  if(mat1==mat2)
    {
        cout<<"true,the same"<<endl;
    }
    else{cout<<"false,not the same"<<endl;}*/


      /*  if(mat1!=mat2)
    {
        cout<<"true,not the same"<<endl;
    }
    else{cout<<"false, the same"<<endl;}*/

   /*     if(mat1.isSquare())
    {
        cout<<"true,is square"<<endl;
    }
    else{cout<<"false,not square"<<endl;}*/

       /* if(mat1.isSymetric())
    {
        cout<<"true,is symmetric"<<endl;
    }
    else{cout<<"false,not symmetric"<<endl;}*/

       /* if(mat1.isIdentity())
    {
        cout<<"true,is identity"<<endl;
    }
    else{cout<<"false,not identity"<<endl;}*/

        mat1.transpose(mat2);
        //cout << mat2;
        //cout<<endl;
        cout<< mat1;



    return 0;
}
