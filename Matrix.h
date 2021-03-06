#include "stdafx.h" 
#include <iostream> 
#include <fstream> 

using namespace std;
template<class T>
class Matrix
{

public:
	Matrix();
	Matrix(int lines, int columns);
	Matrix(const Matrix& obj);
	void read_matrix(std::string s);
	Matrix operator+(const Matrix& array1);
	Matrix operator * (const Matrix& array);
	T* operator [](int i);
	T* operator [](int i) const;
	template<class T> friend ostream& operator<< (ostream& f, const Matrix<T>& a); 
	template<class T> friend istream& operator>> (istream& f, const Matrix<T>& a);
	Matrix<T>& operator=(const Matrix& a);
	bool operator==(const Matrix& a) const;
	int columns() const;
	int lines() const;
	void reset();

private:
	int _lines;
	int _columns;
	T ** mas;

};
template<class T>
Matrix<T>::Matrix() : _lines(0), _columns(0), mas(nullptr)
{}
template<class T>
Matrix<T>::Matrix(int lines, int columns) : _lines(lines), _columns(columns)
{
	mas = new T*[_lines];
	for (int i = 0; i < _lines; i++)
	{
		_mas[i] = new T[_columns];
		for (int j = 0; j < _columns; j++)
		{
			mas[i][j] = (T)(rand()%10);
		}
	}
}
template<class T>
Matrix<T>::Matrix(const Matrix& obj) : _lines(obj._lines), _columns(obj._columns)
{
	mas = new T*[_lines];

	for (int i = 0; i < _lines; i++)
	{
		mas[i] = new T[_columns];
		for (int j = 0; j < _columns; j++)
			mas[i][j] = obj.mas[i][j];
	}
}
template<class T>
void Matrix<T>::read_matrix(std::string s)
{
	ifstream fin(s);
	for (int i = 0; i < _lines; i++)
		for (int j = 0; j < _columns; j++)
			fin >> mas[i][j];
	fin.close();

}

template<class T>
int Matrix<T>::columns() const
{
	return(_columns);
}
template<class T>
int Matrix<T>::lines() const
{
	return(_lines);
}
template<class T>
void Matrix<T>::reset()
{
	for (int i = 0; i < _lines; i++)
		for (int j = 0; j < _columns; j++)
			mas[i][j] = 0;
}
template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix& a)
{
	if (this == &a)
		return (*this);
	if (mas)
	{		for (int i = 0; i < _lines; i++)
			delete mas[i];
		delete[] mas;
	}
	_lines = a._lines;
	_columns = a._columns;
	mas = new T*[_lines];
	for (int i = 0; i < _lines; i++)
	{
		mas[i] = new T[_columns];
		for (int j = 0; j < _columns; j++)
			mas[i][j] = a.mas[i][j];

	}
	return (*this);
}
template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix& array1)
{
	if (array1._lines != _lines || array1._columns != _columns)
		throw std::invalid_argument("size mismatch");
	Matrix result(*this);
	for (int i = 0; i < _lines; i++)
		for (int j = 0; j < _columns; j++)
			result.mas[i][j] += array1.mas[i][j];
	return result;
}
template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix& array)
{
	if (array._columns != _lines )
		throw std::invalid_argument("size mismatch");
	Matrix result(_lines, array.columns());
	result.reset();
	for (int i = 0; i < _lines; i++)
		for (int j = 0; j < array.columns(); j++)
			for (int t = 0; t < _columns; t++)
				result.mas[i][j] += mas[i][t] * array.mas[t][j];
	return result;
}
template<class T>
T * Matrix<T>::operator [] (int i)
{
	if (i>_lines || i<0)
		throw std::invalid_argument("invalid_argument");
	if ((i - 1)<0) exit(0);
	T *temp = new T[_columns];
	for (int j = 0; j < _columns; j++)
		temp[j] = mas[i - 1][j];
	return(temp);

}
template<class T>
T * Matrix<T>::operator [] (int i) const
{
	if (i>_lines || i<0)
		throw std::invalid_argument("invalid_argument");
	if ((i - 1)<0) exit(0);
	int *temp = new T[_columns];
	for (int j = 0; j < _columns; j++)
		temp[j] = mas[i - 1][j];
	return(temp);

}
template<class T>
ostream& operator<<(ostream& f, const Matrix<T>& a)
{
	for (int i = 0; i < a._lines; i++)
	{
		for (int j = 0; j < a._columns; j++)
		{
			f << a.mas[i][j];
			f << " ";
		}
		f << "\n";
	}
	return f;
}
template<class T> 
istream& operator>> (istream& f, const Matrix<T>& a)
{
	for (int i = 0; i < a._lines; i++)
	{
		for (int j = 0; j < a._columns; j++)
		{
			f >> a.mas[i][j];
		}
	
	}
	return f;
}
template<class T>
bool Matrix<T>::operator==(const Matrix& a) const
{
	if ((a._lines != _lines) || (a._columns != _columns))
		throw std::invalid_argument("size mismatch");
	for (int i = 0; i < a._lines; i++)
	{
		for (int j = 0; j < a._columns; j++)
			if (a.mas[i][j] != this->mas[i][j])
				return false;
	}
	return true;
}