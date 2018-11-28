#include <iostream>
#include<vector>
using namespace std;
struct matrix
{
    int* data;       // Pointer to 1-D array that will simulate matrix
    int row, col;
};

void createMatrix (int row, int col, int num[], matrix& mat)
{

    mat.row = row;
    mat.col = col;
    mat.data = new int [row * col];
    for (int i = 0; i < row * col; i++)
        mat.data [i] = num [i];
}

ostream& operator<< (ostream& out, matrix mat)
{
    // prints the data of the matrix
    for(int i = 0 ; i < mat.row ; i++)
    {
        out << endl;
        for(int j = 0 ; j < mat.col ; j++)
        {
            out << mat.data[i * mat.col + j] << "  ";
        }
    }
    return out;
}
istream& operator>>(istream& is, matrix& mat)
{
    //takes matrix attributes from user
    cout << "\n\nPlease enter rows and columns: ";
    cin >> mat.row >> mat.col;
    mat.data = new int[mat.row * mat.col];
    for(int i = 0 ; i < mat.row ; i++)
    {
        cout << "\nPlease enter data for row " << i << ": ";
        for(int j = 0 ; j < mat.col ; j++)
        {
            cin >> mat.data[i * mat.col + j];
        }
    }
}

matrix& operator+(matrix mat1, matrix mat2)
{
    // adds two matrices with the same dimensions
    int mat1Dimen = mat1.col*mat1.row;
    int mat2Dimen = mat2.col*mat2.row;
    matrix *mat3 = new matrix;
    mat3->row = mat1.row;
    mat3->col = mat1.col;
    mat3->data =  new int [mat1Dimen];
    if(mat1Dimen==mat2Dimen)
    {
        for(int i =0; i<mat1Dimen; i++)
        {
            mat3->data[i] = mat1.data[i]+mat2.data[i];
        }
    }
    else
    {
        cout<<"Sorry , different dimensions "<<endl;
    }
    return *mat3;
}

matrix& operator-(matrix mat1, matrix mat2)
{
    // subtracts two matrices with the same dimensions
    int mat1Dimen = mat1.col*mat1.row;
    int mat2Dimen = mat2.col*mat2.row;
    matrix *mat3 = new matrix;
    mat3->row = mat1.row;
    mat3->col = mat1.col;
    mat3->data =  new int [mat1Dimen];
    if(mat1Dimen==mat2Dimen)
    {
        for(int i =0; i<mat1Dimen; i++)
        {
            mat3->data[i] = mat1.data[i]-mat2.data[i];
        }
    }
    else
    {
        cout<<"Sorry , different dimensions "<<endl;
    }
    return *mat3;
}

matrix& operator+(matrix mat1,int scalar)
{
    // adds  a specific value to all data elements
    int mat1Dimen = mat1.col*mat1.row;
    matrix *mat2 = new matrix;
    mat2->row = mat1.row;
    mat2->col = mat1.col;
    mat2->data =  new int [mat1Dimen];

    for(int i =0; i<mat1Dimen; i++)
    {
        mat2->data[i] = mat1.data[i]+scalar;

    }

    return *mat2;
}

matrix& operator-(matrix mat1,int scalar)
{
    int mat1Dimen = mat1.col*mat1.row;
    matrix *mat2 = new matrix;
    mat2->row = mat1.row;
    mat2->col = mat1.col;
    mat2->data =  new int [mat1Dimen];

    for(int i =0; i<mat1Dimen; i++)
    {
        mat2->data[i] = mat1.data[i]-scalar;

    }

    return *mat2;
}

matrix& operator*(matrix mat1,int scalar)
{
    //multiplies all data elements by a scalar
    int mat1Dimen = mat1.col*mat1.row;
    matrix *mat2 = new matrix;
    mat2->row = mat1.row;
    mat2->col = mat1.col;
    mat2->data =  new int [mat1Dimen];

    for(int i =0; i<mat1Dimen; i++)
    {
        mat2->data[i] = mat1.data[i]*scalar;

    }

    return *mat2;
}


matrix operator+= (matrix& mat1, matrix mat2)
{
    if(mat1.row==mat2.row && mat1.col==mat2.col)
    {
        for(int i =0; i<mat1.row*mat1.col; i++)
        {
            mat1.data[i] = mat1.data[i]+mat2.data[i];
        }
    }
    else
    {
        cout<<"Sorry , different dimensions "<<endl;
    }
    return mat1;



}

matrix operator-= (matrix& mat1, matrix mat2)
{
    if(mat1.row==mat2.row && mat1.col==mat2.col)
    {
        for(int i =0; i<mat1.row*mat1.col; i++)
        {
            mat1.data[i] = mat1.data[i]-mat2.data[i];
        }
    }
    else
    {
        cout<<"Sorry , different dimensions "<<endl;
    }
    return mat1;



}

matrix operator+= (matrix& mat1, int scalar)
{

    for(int i =0; i<mat1.row*mat1.col; i++)
    {
        mat1.data[i] = mat1.data[i]+scalar;
    }

    return mat1;



}

matrix operator-= (matrix& mat1, int scalar)
{

    for(int i =0; i<mat1.row*mat1.col; i++)
    {
        mat1.data[i] = mat1.data[i]-scalar;
    }

    return mat1;



}

void operator++ (matrix& mat)
{
    // increase all data elements by 1
    for(int i =0; i<mat.row*mat.col; i++)
    {
        mat.data[i] += 1;
    }

}
void operator-- (matrix& mat)
{
    // decrease all data elements by 1
    for(int i =0; i<mat.row*mat.col; i++)
    {
        mat.data[i] -= 1;
    }

}

bool operator== (matrix mat1, matrix mat2)
{
    int c = 0;
    for(int i=0 ; i<mat1.row*mat1.col; i++)
    {

        if(mat1.data[i] != mat2.data[i])
        {
            c++;
        }

    }
    if(c==0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool operator!= (matrix mat1, matrix mat2)
{
    int c = 0;
    for(int i=0 ; i<mat1.row*mat1.col; i++)
    {

        if(mat1.data[i] != mat2.data[i])
        {
            c++;
        }

    }
    if(c==0)
    {
        return false;
    }
    else
    {
        return true;
    }

}

bool isSquare (matrix mat)
{
    if(mat.row==mat.col)
    {
        return true;
    }
    else
    {
        return false;
    }



}

bool isIdentity (matrix mat)
{
    if(!isSquare(mat))
    {
        return false;

    }


    int c=0;


    for(int i =0 ; i<mat.row*mat.col ; i++)
    {
        if(mat.data[i]!=1)
        {
            c++;
        }
    }


    if(c>0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool isSymetric (matrix mat)
{
    if(!isSquare(mat))
    {
        return false;

    }

}


//////////individual task

vector<string> split(string target ,  char delimiter){
    vector<string> words;
    string temp = "";

    for(int i = 0 ; i<target.length() ; i++){
            if(target[i]!=delimiter){
                temp+=target[i];
            }
            else
            {
                words.push_back(temp);
                temp = "";


            }



    }
    return words;








}








int main()
{
/*
    matrix mat1, mat2, mat3, mat4;
    int data1[4] = {1,2,3,4};
    int data2[4] = {5,6,7,8};
    createMatrix(2,2,data1,mat1);
    createMatrix(2,2,data2,mat2);


    cout<<mat1<<endl;
    cout<<"*******"<<endl;
///**<  */    //mat4=transpose(mat1);
//    cout<<mat4;


    //cout<<mat2<<endl;
    //--mat1;
    //cout<<mat1<<endl;
    /*mat3=mat1+mat2;
    mat4 = mat1-mat2;
    cout<<mat3<<endl;
    cout<<mat4+4;
    cout<<mat1*5;
    */
vector <string> vec1 = split("10,20,30,40,50,60,70,80" , ',');

for( const auto& i: vec1){
        cout<<i<<" ";

}
cout<<endl;
vector <string> vec2 = split("do re mi fa so la ti do" , ' ');

for( const auto& i: vec2){
        cout<<i<<" ";

}



}
