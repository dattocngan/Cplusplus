#include <iostream>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;
struct SinhVien
{
    string stt;
    string name, lop, bday;
    float gpa;
};
void nhap(struct SinhVien *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int k = i + 1;
        a[i].stt = to_string(k);
        if (a[i].stt.size() == 1)
            a[i].stt.insert(0, "00");
        else if (a[i].stt.size() == 2)
            a[i].stt.insert(0, "0");
        a[i].stt.insert(0, "B20DCCN");
        scanf("\n");
        getline(cin, a[i].name);
        cin >> a[i].lop >> a[i].bday >> a[i].gpa;
    }
}
void birthday(string &s)
{
    if (s[2] != '/')
        s.insert(0, "0");
    if (s[5] != '/')
        s.insert(3, "0");
}
void solve_name(string &s)
{
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
    stringstream ss(s);
    string token, s0;
    while (ss >> token)
    {
        token[0] -= 32;
        s0 += token;
        s0 += ' ';
    }
    s = s0;
}
bool can_swap(struct SinhVien a, struct SinhVien b)
{
    return a.gpa > b.gpa;
}
void sapxep(struct SinhVien *a, int n)
{
    sort(a, a + n, can_swap);
}
void in(struct SinhVien *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        solve_name(a[i].name);
        birthday(a[i].bday);
        cout << a[i].stt << " " << a[i].name << a[i].lop << " " << a[i].bday << " ";
        cout << fixed << setprecision(2) << a[i].gpa << endl;
    }
}
int main()
{
    struct SinhVien ds[50];
    int N;
    cin >> N;
    nhap(ds, N);
    sapxep(ds, N);
    in(ds, N);
    return 0;
}