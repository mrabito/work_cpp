/*
 *  2017/07/23
 *  �t�@�C�����o�͂̃e�X�g(.txt)
 */

#include <iostream>
#include <fstream> //�t�@�C�������ɕK�v
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
        cout << "�o�̓t�@�C�����I�[�v���ł��܂���\n";
        return 1;   //�߂�l1�Ńv���O�����I��
    }

    fout << 'A';
    fout << "abcdefg\n";
    fout << "ABCDEFG\n";
    fout << 12345 << '\n';

    fout.close();

    fin.open("data.txt");
    if (!fin) {
        cout << "���̓t�@�C�����I�[�v���ł��܂���\n";
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

    cout << "�I������ɂ́A�����L�[����͂��Ă��������B... ";
    getchar();
    return 0;
}