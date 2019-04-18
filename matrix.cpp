#include <iostream>
#include <string>
#include <fstream>
#include "matrix.hpp"

class DimensionMismatch
{};

//default constructor
Matrix::Matrix()
{
    m = new double*[numRows];
    for(unsigned i = 0; i < numRows; i++)
    {
        m[i] = new double[numColumns];
        for (unsigned j = 0; j < numColumns; ++j)
        {
            m[0][0] = 0;
        }
    }
}

//constructor
Matrix::Matrix(const unsigned nR, const unsigned nC)
{
    numRows = nR;
    numColumns = nC;
    
    m = new double*[numRows];
    for(unsigned i = 0; i < numRows; i++)
    {
        m[i] = new double[numColumns];
        for (unsigned j = 0; j < numColumns; ++j)
        {
            m[i][j] = 0;
        }
    }
}

//constructor that accepts a filename and initializes the matrix
Matrix::Matrix(const std::string& A)
{
    char space;
    std::ifstream in;
    in.open(A);
    if(in.is_open())
    {
        in.ignore();
        in.ignore();
        in >> numColumns >> space >> numRows;
        in.ignore();
        m = new double*[numRows];
        for (unsigned i = 0; i < numRows; ++i)
        {
            m[i] = new double[numColumns];
            for (unsigned j = 0; j < numColumns; ++j)
            {
                in >> m[i][j] >> space;
            }
        }
    }
    else
    {
        std::cerr << "Error opening file" << std::endl;
    }
}

//takes in the number of rows, number of columns and a string containing the
//elements of a matrix and initializes the matrix
Matrix::Matrix(const unsigned nR, const unsigned nC, const std::string& A)
{
    numRows = nR;
    numColumns = nC;
    for(unsigned i = 0; i < numRows; ++i)
        for(unsigned j = 0; j < numColumns; ++j)
            m[i][j] += A[i];
    
}

//destructor
Matrix::~Matrix()
{
    for(unsigned i = 0; i < numRows; i++)
    {
        delete [] m[i];
    }
    delete [] m;
}

//assignment operator
Matrix& Matrix::operator=(const Matrix& A)
{
    numRows = A.numRows;
    numColumns = A.numColumns;
    
    for(unsigned i = 0; i < numRows; ++i)
    {
        for(unsigned j = 0; j < numColumns; ++j)
        {
            m[i][j] = A.m[i][j];
        }
    }
    return *this;
}

//number of rows
unsigned Matrix::NumRows() const
{
    return numRows;
}

//number of columns
unsigned Matrix::NumColumns() const
{
    return numColumns;
}

//returns the size of the matrix
std::string Matrix::Size() const
{
    std::string size = numRows + " x " + numColumns;
    return size;
}

//element access operator
double& Matrix::operator()(const unsigned i, const unsigned j) const
{
    return m[i][j];
}

//multiplies the matrix by a scalar
Matrix operator*(const double c, const Matrix& A)
{
    for(unsigned i = 0; i < A.numRows; ++i)
        for(unsigned j = 0; j < A.numColumns; ++j)
            A.m[i][j] *= c;
    return A;
}

//stream insertion operator
std::ostream& operator<<(std::ostream& out, const Matrix& A)
{
    for(unsigned i = 0; i < A.numRows; ++i)
    {
        out << A.m[i][0];
        for(unsigned j = 1; j < A.numColumns; ++j)
        {
            out << " " << A.m[i][j];
        }
        out << std::endl;
    }
    return out;
}

//multiplies one row by a scalar and then adds that to another row
void Matrix::AddRow(const unsigned rI, const unsigned rJ, const double c)
{
    for(unsigned i = 0; i < numColumns; ++i)
    {
        m[rI][i] = (m[rJ][i] * c) + m[rI][i];
    }
}

//multiplies one row by a scalar
void Matrix::MultRow(const unsigned rI, const double c)
{
    for(unsigned i = 0; i < numColumns; ++i)
    {
        m[rI][i] = m[rI][i] * c;
    }
}

//Takes the sum of two matrices if the dimensions are equal. If the dimensions are
//not equal, it throws an exception. If the element sum is more than 255 it will
//divide the sum by 2.
Matrix operator+(const Matrix& A, const Matrix& B)
{
    Matrix C;
    if(A.numRows != B.numRows || A.numColumns != B.numColumns)
    {
        throw DimensionMismatch();
    }
    else
    {
        for(unsigned i = 0; i < A.numRows; ++i)
            for(unsigned j = 0; j < A.numColumns; ++j)
            {
                if((A.m[i][j] + B.m[i][j]) < 255)
                    C.m[i][j] = A.m[i][j] + B.m[i][j];
                else
                {
                    C.m[i][j] = (A.m[i][j] + B.m[i][j]) / 2;
                }
                
            }
    }
    
    return C;
}

//rotate a matrix 90 degrees clockwise
Matrix Rotate90Clockwise(const Matrix& A)
{
    for(unsigned i = 0; i < A.numRows; ++i)
        for(unsigned j = i + 1; j < A.numColumns; ++j)
        {
            int mat = A.m[i][j];
            A.m[i][j] = A.m[j][i];
            A.m[j][i] = mat;
        }
    for(unsigned i = 0; i < A.numRows; ++i)
        for(unsigned j = 0; j < (A.numColumns/2); ++j)
        {
            int mat = A.m[i][j];
            A.m[i][j] = A.m[i][A.numColumns-1-j];
            A.m[i][A.numColumns-1-j] = mat;
        }
    return A;
}

/*Matrix Blur(const Matrix& A, const int k)
{
    
}*/

//accepts an output filename and saves the matrix to the output file
void Matrix::Save(std::string& filename)
{
    std::ofstream out;
    out.open(filename);
    if(out.is_open())
    {
        m = new double*[numRows];
        for (unsigned i = 0; i < numRows; ++i)
        {
            m[i] = new double[numColumns];
            for (unsigned j = 0; j < numColumns; ++j)
            {
                out << m[i][j] << " ";
            }
        }
    }
}

/*****************************************************************************
 * Function: (Copy) Constructor
 * Description: Constructs a matrix based off the provided one.
 * Parameters:
 *    A - Matrix to copy.
 * Return Value: n/a
 */
Matrix::Matrix(const Matrix& A)
{
   numRows = A.numRows;
   numColumns = A.numColumns;

   m = new double*[numRows];
   for (unsigned i = 0; i < numRows; ++i)
   {
      m[i] = new double[numColumns];
      for (unsigned j = 0; j < numColumns; ++j)
      {
         m[i][j] = A.m[i][j];
      }
   }
}

/*****************************************************************************
 * Function: (Move) Constructor
 * Description: 'Constructs' a matrix based off the provided one.
 * Parameters:
 *    A - Matrix to steal members of.
 * Return Value: n/a
 */
Matrix::Matrix(Matrix&& A)
{
   numRows = std::move(A.numRows);
   numColumns = std::move(A.numColumns);
   m = A.m;
   A.m = nullptr;
}



