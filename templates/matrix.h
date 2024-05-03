#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

template <typename T, int MAXROWS, int MAXCOLS>
class Matrix
{
private:
    T doubleArray[MAXROWS][MAXCOLS];
    int rows;
    int cols;

public:
    // Constructor
    Matrix(); 

    // Getter Functions
    void printMatrix(); // Print the elements of the matrix

    // Setter Functions
    void setMatrix(T newMatrix[][MAXCOLS]);             // Set the doubleArray to what is sent
    void addMatrix(T matrixToAdd[][MAXCOLS]);            // Add an array to doubleArray
    void addMatrix(Matrix<T, MAXROWS, MAXCOLS> otherMatrix); // Add another matrix to doubleArray

    // Demo Function
    template <typename T1>
    void demoTemplate(T1 array1[][MAXCOLS], T1 array2[][MAXCOLS]);
};

// Constructor definition
template <typename T, int MAXROWS, int MAXCOLS>
Matrix<T, MAXROWS, MAXCOLS>::Matrix()
    : rows(MAXROWS), cols(MAXCOLS)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            doubleArray[i][j] = T(); // Default value for type T (zero for numeric types, empty string for std::string)
        }
    }
}

// Function to print the matrix
template <typename T, int MAXROWS, int MAXCOLS>
void Matrix<T, MAXROWS, MAXCOLS>::printMatrix()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << doubleArray[i][j] << "   ";
        }
        std::cout << std::endl;
    }
}

// Set the doubleArray to the provided matrix
template <typename T, int MAXROWS, int MAXCOLS>
void Matrix<T, MAXROWS, MAXCOLS>::setMatrix(T newMatrix[][MAXCOLS])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            doubleArray[i][j] = newMatrix[i][j];
        }
    }
}

// Add an array to doubleArray
template <typename T, int MAXROWS, int MAXCOLS>
void Matrix<T, MAXROWS, MAXCOLS>::addMatrix(T matrixToAdd[][MAXCOLS])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            doubleArray[i][j] += matrixToAdd[i][j];
        }
    }
}

// Add another matrix to doubleArray
template <typename T, int MAXROWS, int MAXCOLS>
void Matrix<T, MAXROWS, MAXCOLS>::addMatrix(Matrix<T, MAXROWS, MAXCOLS> otherMatrix)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            doubleArray[i][j] += otherMatrix.doubleArray[i][j];
        }
    }
}

// Demo Function Implementation
template <typename T, int MAXROWS, int MAXCOLS>
template <typename T1>
void Matrix<T, MAXROWS, MAXCOLS>::demoTemplate(T1 array1[][MAXCOLS], T1 array2[][MAXCOLS])
{
    setMatrix(array1);
    std::cout << "\nMatrix set to first array" << std::endl;
    printMatrix();

    addMatrix(array2);
    std::cout << "\nMatrix incremented by second array" << std::endl;
    printMatrix();
}

#endif // MATRIX_H
