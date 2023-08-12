#include <iostream>
#include <array>

using namespace std;

class Matrix
{
private:
    // 定义三乘三的矩阵
    // 这里longlong防止数据溢出
    array<array<long long, 3>, 3> _trans_matrix;

public:
    Matrix();
    Matrix(const Matrix &a_mx);
    ~Matrix() = default;
    Matrix operator*(const Matrix &another);
    Matrix operator=(const Matrix &another);
    // 打印查看结果
    void show(void)
    {
        for (auto &i : _trans_matrix)
        {
            for (auto j : i)
                std::cout << j << ' ';
            std::cout << std::endl;
        }
    }
    void make_zero(void)
    {
        for (auto &i : _trans_matrix)
            i.fill(0);
    }
    // 最后矩阵乘出来的结果只需要第一行的和即可
    // 具体线代推导过程就不写了
    long long value(long long x)
    {
        return _trans_matrix[x][0] + _trans_matrix[x][1] + 2 * _trans_matrix[x][2];
    }
};

Matrix::Matrix() : _trans_matrix{}
{
    /*
    [0, 1, 0]
    [0, 0, 1]
    [1, 1, 1]
    */
    _trans_matrix[0][1] = _trans_matrix[1][2] = 1;
    _trans_matrix[2].fill(1);
}

Matrix::Matrix(const Matrix &a_mx) : _trans_matrix(a_mx._trans_matrix)
{
}

Matrix Matrix::operator*(const Matrix &another)
{
    Matrix tmp;
    // 将tmp中所有的值都设为0
    tmp.make_zero();

    // 矩阵相乘
    for (long long i = 0; i < 3; ++i)
    {
        for (long long j = 0; j < 3; ++j)
        {
            for (long long k = 0; k < 3; ++k)
                tmp._trans_matrix[i][j] = (_trans_matrix[i][j] + (this->_trans_matrix[i][k] * another._trans_matrix[k][j])) % 1000000007;
        }
    }

    return tmp;
}

Matrix Matrix::operator=(const Matrix &another)
{
    for (long long i = 0; i < 3; ++i)
        _trans_matrix[i] = another._trans_matrix[i];

    return *this;
}

Matrix pow(const Matrix &mx, long long n)
{
    // 这是是随便写的，小于0的时候应该不返回mx
    if (n <= 1)
        return mx;

    if (n % 2 == 0)
    {
        // 这里的右移等价于n / 2
        Matrix tmp_matrix = pow(mx, n >> 1);
        return tmp_matrix * tmp_matrix;
    }
    else
        return pow(mx, n - 1) * mx;
}
