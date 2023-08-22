#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Stiva {
    private:
        vector< pair < int, int > > st; 
        int maxi;
    public:
        void Push(int x) {
            if (st.size() && x > maxi) {
                maxi = x;
            } else if (st.size() == 0)
                maxi = x;
            st.push_back({ x, maxi });
        }
        void Pop() {
            if (st.size()) {
                st.pop_back();
                maxi = st[(int)st.size() - 1].second;
            }
        }
        int Top() {
            if (st.size())
                return st[(int)st.size() - 1].first;
            return -1;
        }
        int Max() {
            if (st.size())
                return st[(int)st.size() - 1].second;
            return -1;
        }
        int Empty() {
            return st.size() != 0;
        }
};

int main()
{
    Stiva w;
    w.Push(1);
    w.Push(-1);
    w.Push(3);
    w.Push(5);
    cout << w.Top() << " " << w.Max() << "\n"; // afiseaza 1 5
    w.Pop();
    w.Push(4);
    cout << w.Top() << " " << w.Max() << "\n"; // afiseaza 2 4
    return 0;
}