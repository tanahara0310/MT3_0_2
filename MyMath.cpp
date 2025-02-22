#include "MyMath.h"
#include <Novice.h>
#include <math.h>
#include <assert.h>

// ベクトルの加算
Vector3 Add(const Vector3& v1, const Vector3& v2)
{
    return { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };
}

// ベクトルの減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2)
{
    return { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z };
}

// ベクトルのスカラー倍
Vector3 Multiply(float scalar, const Vector3& v)
{
    return { scalar * v.x, scalar * v.y, scalar * v.z };
}

// ベクトルの内積
float Dot(const Vector3& v1, const Vector3& v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// ベクトルの長さ
float Length(const Vector3& v)
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

// ベクトルの正規化
Vector3 Normalize(const Vector3& v)
{
    float length = Length(v);
    return { v.x / length, v.y / length, v.z / length };
}

//================================================
// 4x4行列関数
//================================================

//行列の加法
Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2)
{
    Matrix4x4 result;

    result.m[0][0] = m1.m[0][0] + m2.m[0][0];
    result.m[0][1] = m1.m[0][1] + m2.m[0][1];
    result.m[0][2] = m1.m[0][2] + m2.m[0][2];
    result.m[0][3] = m1.m[0][3] + m2.m[0][3];

    result.m[1][0] = m1.m[1][0] + m2.m[1][0];
    result.m[1][1] = m1.m[1][1] + m2.m[1][1];
    result.m[1][2] = m1.m[1][2] + m2.m[1][2];
    result.m[1][3] = m1.m[1][3] + m2.m[1][3];

    result.m[2][0] = m1.m[2][0] + m2.m[2][0];
    result.m[2][1] = m1.m[2][1] + m2.m[2][1];
    result.m[2][2] = m1.m[2][2] + m2.m[2][2];
    result.m[2][3] = m1.m[2][3] + m2.m[2][3];

    result.m[3][0] = m1.m[3][0] + m2.m[3][0];
    result.m[3][1] = m1.m[3][1] + m2.m[3][1];
    result.m[3][2] = m1.m[3][2] + m2.m[3][2];
    result.m[3][3] = m1.m[3][3] + m2.m[3][3];

    return result;
}

// 行列の減法
Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2)
{
    Matrix4x4 result;

    result.m[0][0] = m1.m[0][0] - m2.m[0][0];
    result.m[0][1] = m1.m[0][1] - m2.m[0][1];
    result.m[0][2] = m1.m[0][2] - m2.m[0][2];
    result.m[0][3] = m1.m[0][3] - m2.m[0][3];
                                
    result.m[1][0] = m1.m[1][0] - m2.m[1][0];
    result.m[1][1] = m1.m[1][1] - m2.m[1][1];
    result.m[1][2] = m1.m[1][2] - m2.m[1][2];
    result.m[1][3] = m1.m[1][3] - m2.m[1][3];
                                
    result.m[2][0] = m1.m[2][0] - m2.m[2][0];
    result.m[2][1] = m1.m[2][1] - m2.m[2][1];
    result.m[2][2] = m1.m[2][2] - m2.m[2][2];
    result.m[2][3] = m1.m[2][3] - m2.m[2][3];
                                
    result.m[3][0] = m1.m[3][0] - m2.m[3][0];
    result.m[3][1] = m1.m[3][1] - m2.m[3][1];
    result.m[3][2] = m1.m[3][2] - m2.m[3][2];
    result.m[3][3] = m1.m[3][3] - m2.m[3][3];

    return result;
}

// 行列の積
 Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2)
{
     Matrix4x4 result;

      for (int i = 0; i < 4; ++i) { // 行

         for (int j = 0; j < 4; ++j) { // 列

             //初期化
             result.m[i][j] = 0; 

             for (int k = 0; k < 4; ++k) { // 積の計算
                 result.m[i][j] += m1.m[i][k] * m2.m[k][j];
             }
         }
     }

     return result;
 }

 Matrix4x4 Inverse(const Matrix4x4& m)
 {
     Matrix4x4 result;
     float det;

     // 各要素の余因子を直接計算
     float cof[4][4];

     cof[0][0] = m.m[1][1] * (m.m[2][2] * m.m[3][3] - m.m[2][3] * m.m[3][2]) - m.m[1][2] * (m.m[2][1] * m.m[3][3] - m.m[2][3] * m.m[3][1]) + m.m[1][3] * (m.m[2][1] * m.m[3][2] - m.m[2][2] * m.m[3][1]);

     cof[0][1] = -(m.m[1][0] * (m.m[2][2] * m.m[3][3] - m.m[2][3] * m.m[3][2]) - m.m[1][2] * (m.m[2][0] * m.m[3][3] - m.m[2][3] * m.m[3][0]) + m.m[1][3] * (m.m[2][0] * m.m[3][2] - m.m[2][2] * m.m[3][0]));

     cof[0][2] = m.m[1][0] * (m.m[2][1] * m.m[3][3] - m.m[2][3] * m.m[3][1]) - m.m[1][1] * (m.m[2][0] * m.m[3][3] - m.m[2][3] * m.m[3][0]) + m.m[1][3] * (m.m[2][0] * m.m[3][1] - m.m[2][1] * m.m[3][0]);

     cof[0][3] = -(m.m[1][0] * (m.m[2][1] * m.m[3][2] - m.m[2][2] * m.m[3][1]) - m.m[1][1] * (m.m[2][0] * m.m[3][2] - m.m[2][2] * m.m[3][0]) + m.m[1][2] * (m.m[2][0] * m.m[3][1] - m.m[2][1] * m.m[3][0]));

     cof[1][0] = -(m.m[0][1] * (m.m[2][2] * m.m[3][3] - m.m[2][3] * m.m[3][2]) - m.m[0][2] * (m.m[2][1] * m.m[3][3] - m.m[2][3] * m.m[3][1]) + m.m[0][3] * (m.m[2][1] * m.m[3][2] - m.m[2][2] * m.m[3][1]));

     cof[1][1] = m.m[0][0] * (m.m[2][2] * m.m[3][3] - m.m[2][3] * m.m[3][2]) - m.m[0][2] * (m.m[2][0] * m.m[3][3] - m.m[2][3] * m.m[3][0]) + m.m[0][3] * (m.m[2][0] * m.m[3][2] - m.m[2][2] * m.m[3][0]);

     cof[1][2] = -(m.m[0][0] * (m.m[2][1] * m.m[3][3] - m.m[2][3] * m.m[3][1]) - m.m[0][1] * (m.m[2][0] * m.m[3][3] - m.m[2][3] * m.m[3][0]) + m.m[0][3] * (m.m[2][0] * m.m[3][1] - m.m[2][1] * m.m[3][0]));

     cof[1][3] = m.m[0][0] * (m.m[2][1] * m.m[3][2] - m.m[2][2] * m.m[3][1]) - m.m[0][1] * (m.m[2][0] * m.m[3][2] - m.m[2][2] * m.m[3][0]) + m.m[0][2] * (m.m[2][0] * m.m[3][1] - m.m[2][1] * m.m[3][0]);

     cof[2][0] = m.m[0][1] * (m.m[1][2] * m.m[3][3] - m.m[1][3] * m.m[3][2]) - m.m[0][2] * (m.m[1][1] * m.m[3][3] - m.m[1][3] * m.m[3][1]) + m.m[0][3] * (m.m[1][1] * m.m[3][2] - m.m[1][2] * m.m[3][1]);

     cof[2][1] = -(m.m[0][0] * (m.m[1][2] * m.m[3][3] - m.m[1][3] * m.m[3][2]) - m.m[0][2] * (m.m[1][0] * m.m[3][3] - m.m[1][3] * m.m[3][0]) + m.m[0][3] * (m.m[1][0] * m.m[3][2] - m.m[1][2] * m.m[3][0]));

     cof[2][2] = m.m[0][0] * (m.m[1][1] * m.m[3][3] - m.m[1][3] * m.m[3][1]) - m.m[0][1] * (m.m[1][0] * m.m[3][3] - m.m[1][3] * m.m[3][0]) + m.m[0][3] * (m.m[1][0] * m.m[3][1] - m.m[1][1] * m.m[3][0]);

     cof[2][3] = -(m.m[0][0] * (m.m[1][1] * m.m[3][2] - m.m[1][2] * m.m[3][1]) - m.m[0][1] * (m.m[1][0] * m.m[3][2] - m.m[1][2] * m.m[3][0]) + m.m[0][2] * (m.m[1][0] * m.m[3][1] - m.m[1][1] * m.m[3][0]));

     cof[3][0] = -(m.m[0][1] * (m.m[1][2] * m.m[2][3] - m.m[1][3] * m.m[2][2]) - m.m[0][2] * (m.m[1][1] * m.m[2][3] - m.m[1][3] * m.m[2][1]) + m.m[0][3] * (m.m[1][1] * m.m[2][2] - m.m[1][2] * m.m[2][1]));

     cof[3][1] = m.m[0][0] * (m.m[1][2] * m.m[2][3] - m.m[1][3] * m.m[2][2]) - m.m[0][2] * (m.m[1][0] * m.m[2][3] - m.m[1][3] * m.m[2][0]) + m.m[0][3] * (m.m[1][0] * m.m[2][2] - m.m[1][2] * m.m[2][0]);

     cof[3][2] = -(m.m[0][0] * (m.m[1][1] * m.m[2][3] - m.m[1][3] * m.m[2][1]) - m.m[0][1] * (m.m[1][0] * m.m[2][3] - m.m[1][3] * m.m[2][0]) + m.m[0][3] * (m.m[1][0] * m.m[2][1] - m.m[1][1] * m.m[2][0]));

     cof[3][3] = m.m[0][0] * (m.m[1][1] * m.m[2][2] - m.m[1][2] * m.m[2][1]) - m.m[0][1] * (m.m[1][0] * m.m[2][2] - m.m[1][2] * m.m[2][0]) + m.m[0][2] * (m.m[1][0] * m.m[2][1] - m.m[1][1] * m.m[2][0]);



     // 行列式の計算
     det = m.m[0][0] * cof[0][0] + m.m[0][1] * cof[0][1] + m.m[0][2] * cof[0][2] + m.m[0][3] * cof[0][3];

     // 行列式が 0 の場合は逆行列なし
     assert(det != 0.0f);

     // 逆行列の計算
     float invDet = 1.0f / det;
     for (int i = 0; i < 4; ++i) {
         for (int j = 0; j < 4; ++j) {
             result.m[j][i] = cof[i][j] * invDet;
         }
     }

     return result;
 }

 //転置行列
 Matrix4x4 Transpose(const Matrix4x4& m)
 {
     Matrix4x4 result;

     result.m[0][0] = m.m[0][0];
     result.m[0][1] = m.m[1][0];
     result.m[0][2] = m.m[2][0];
     result.m[0][3] = m.m[3][0];
                      
     result.m[1][0] = m.m[0][1];
     result.m[1][1] = m.m[1][1];
     result.m[1][2] = m.m[2][1];
     result.m[1][3] = m.m[3][1];
                      
     result.m[2][0] = m.m[0][2];
     result.m[2][1] = m.m[1][2];
     result.m[2][2] = m.m[2][2];
     result.m[2][3] = m.m[3][2];
                      
     result.m[3][0] = m.m[0][3];
     result.m[3][1] = m.m[1][3];
     result.m[3][2] = m.m[2][3];
     result.m[3][3] = m.m[3][3];

     return result;

 }
 Matrix4x4 MakeIdentity4x4()
 {
     Matrix4x4 result;

     result.m[0][0] = 1.0f;
     result.m[0][1] = 0.0f;
     result.m[0][2] = 0.0f;
     result.m[0][3] = 0.0f;

     result.m[1][0] = 0.0f;
     result.m[1][1] = 1.0f;
     result.m[1][2] = 0.0f;
     result.m[1][3] = 0.0f;

     result.m[2][0] = 0.0f;
     result.m[2][1] = 0.0f;
     result.m[2][2] = 1.0f;
     result.m[2][3] = 0.0f;

     result.m[3][0] = 0.0f;
     result.m[3][1] = 0.0f;
     result.m[3][2] = 0.0f;
     result.m[3][3] = 1.0f;

     return result;
 }
 //
// Matrix4x4 Transpose(const Matrix4x4& m)
//{
//    return Matrix4x4();
//}
//
// Matrix4x4 MakeIdentity4x4()
//{
//    return Matrix4x4();
//}

// デバッグ用関数
void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix)
{

    for (int row = 0; row < 4; ++row) {
        for (int column = 0; column < 4; ++column) {
            Novice::ScreenPrintf(x + column * kColumnWidth, y + row * kRowHeight, "%6.02f", matrix.m[row][column]);
        }
    }
}
