#include <cmath>
#include <vector>
#include <functional>
#include <iostream>
#include <iomanip>
using namespace std;

template <typename T> class SparseTable {
    using VT = vector<T>;
    using VVT = vector<VT>;
    using func_type = function<T(const T &, const T &)>;

    VVT ST;
    static T default_func(const T &t1, const T &t2) { return max(t1, t2); }

    func_type op;

  public:
    SparseTable(const vector<T> &v, func_type _func = default_func) {
        op = _func;
        int len = v.size(), l1 = ceil(log2(len)) + 1;
        ST.assign(len, VT(l1, 0));
        for (int i = 0; i < len; ++i) {
            ST[i][0] = v[i];
        }
        for (int j = 1; j < l1; ++j) {
            int pj = (1 << (j - 1));
            for (int i = 0; i + pj < len; ++i) {
                ST[i][j] = op(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    void print() {
        for (int i = 0; i < ST.size(); i++) {
            for (int j = 0; j < ST[i].size(); j++) {
                cout << std::setw(2) << ST[i][j] << " ";
            }
            cout << endl;
        }
    }

    T query(int l, int r) {
        int lt = r - l + 1;
        int q = ceil(log2(lt)) - 1;
        return op(ST[l][q], ST[r - (1 << q) + 1][q]);
    }
};
