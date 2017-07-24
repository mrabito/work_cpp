/*
 *  2017/07/23
 *  ファイル入出力のテスト(.txt)
 */

#include <iostream>
#include <fstream> //ファイル処理に必要
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    char ch;
    char ss[80];
    int dt;

    fout.open("data.txt");
    if (!fout) {
        cout << "出力ファイルをオープンできません\n";
        return 1;   //戻り値1でプログラム終了
    }

    fout << 'A';
    fout << "abcdefg\n";
    fout << "ABCDEFG\n";
    fout << 12345 << '\n';

    fout.close();

    fin.open("data.txt");
    if (!fin) {
        cout << "入力ファイルをオープンできません\n";
        return 1;
    }

    fin >> ch;
    cout << ch << '\n';

    fin >> ss;
    cout << ss << '\n';
    fin >> ss;
    cout << ss << '\n';

    fin >> dt;
    cout << dt << '\n';

    fin.close();

    cout << "終了するには、何かキーを入力してください。... ";
    getchar();
    return 0;
}