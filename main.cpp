#include "Header.h"

using namespace std;

int main() {

    Path My_path;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        pt newone = { i,x,y };
        My_path.add_node(newone);
    }

    My_path.local_search_2();
    double res = My_path.length();
    cout << res << endl;
    My_path.show();

    return 0;
}