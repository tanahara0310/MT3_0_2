#include "MyMath.h"
#include <Novice.h>

const char kWindowTitle[] = "LC1A_16_タナハラ_コア_タイトル";

//==============================
// 関数定義
//==============================

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

    // ライブラリの初期化
    Novice::Initialize(kWindowTitle, 1280, 720);

    // キー入力結果を受け取る箱
    char keys[256] = { 0 };
    char preKeys[256] = { 0 };

    //==============================
    // 変数初期化
    //==============================

    Matrix4x4 m1 = {
        3.2f, 0.7f, 9.6f, 4.4f,
        5.5f, 1.3f, 7.8f, 2.1f,
        6.9f, 8.0f, 2.6f, 1.0f,
        0.5f, 7.2f, 5.1f, 3.3f
    };

    Matrix4x4 m2 = {
        4.1f, 6.5f, 3.3f, 2.2f,
        8.8f, 0.6f, 9.9f, 7.7f,
        1.1f, 5.5f, 6.6f, 0.0f,
        3.3f, 9.9f, 8.8f, 2.2f
    };

    Matrix4x4 resultAdd = Add(m1, m2);
    Matrix4x4 resultSubtract = Subtract(m1,m2);
    Matrix4x4 resultMultiply = Multiply(m1, m2);
    Matrix4x4 inversM1 = Inverse(m1);
    Matrix4x4 inversM2 = Inverse(m2);
    Matrix4x4 transposeM1 = Transpose(m1);
    Matrix4x4 transposeM2 = Transpose(m2);
    Matrix4x4 identity = MakeIdentity4x4();

    // ウィンドウの×ボタンが押されるまでループ
    while (Novice::ProcessMessage() == 0) {
        // フレームの開始
        Novice::BeginFrame();

        // キー入力を受け取る
        memcpy(preKeys, keys, 256);
        Novice::GetHitKeyStateAll(keys);

        ///
        /// ↓更新処理ここから
        ///

        ///
        /// ↑更新処理ここまで
        ///

        ///
        /// ↓描画処理ここから
        ///

        //加算
        Novice::ScreenPrintf(0, 0, "Add");
        MatrixScreenPrintf(16, 16, resultAdd);

        // 減算
        Novice::ScreenPrintf(0, 16 * 6, "Subtract");
        MatrixScreenPrintf(16, kRowHeight * 6, resultSubtract);

        // 乗算
        Novice::ScreenPrintf(0, 16 * 13, "Multiply");
        MatrixScreenPrintf(16, kRowHeight * 12, resultMultiply);

        // 逆行列
        Novice::ScreenPrintf(0, 16 * 20, "InverseM1");
        MatrixScreenPrintf(0, kRowHeight * 18, inversM1);

        // 逆行列
        Novice::ScreenPrintf(0, 16 * 27, "InverseM2");
        MatrixScreenPrintf(0, kRowHeight * 24, inversM2);

        // 転置行列
        Novice::ScreenPrintf(300, 0, "TransposeM1");
        MatrixScreenPrintf(300, kRowHeight, transposeM1);

        Novice::ScreenPrintf(300, 16 * 6, "TransposeM2");
        MatrixScreenPrintf(300, kRowHeight * 6, transposeM2);

        // 単位行列
        Novice::ScreenPrintf(300, 16 * 13, "Identity");
        MatrixScreenPrintf(300, kRowHeight * 12, identity);

        ///
        /// ↑描画処理ここまで
        ///

        // フレームの終了
        Novice::EndFrame();

        // ESCキーが押されたらループを抜ける
        if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
            break;
        }
    }

    // ライブラリの終了
    Novice::Finalize();
    return 0;
}
