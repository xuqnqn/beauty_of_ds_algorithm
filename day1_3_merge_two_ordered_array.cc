/*************************************************************************
      > File Name: day1_3_merge_two_ordered_array.cc
      > Author: Xu Qingqing
      > Mail: xuqnqn@qq.com
      > Created Time: Sun 14 Jul 2019 06:46:10 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

int * merge(const int aa[], int alen, const int bb[], int blen) {

    int * cc = new int[alen + blen];

    int k = 0;
    int i = 0, j = 0;
    while(i < alen && j < blen) {
        if(aa[i] < bb[j]) {
            cc[k++] = aa[i++];
        } else {
            cc[k++] = bb[j++];
        }
    }

    while(i < alen) {
        cc[k++] = aa[i++];
    }

    while(j < blen) {
        cc[k++] = bb[j++];
    }

    return cc;
}

int cmp(const void *a, const void *b) {
    const int aa = *static_cast<const int*> (a);
    const int bb = *static_cast<const int*> (b);

    if(aa < bb) return -1;
    if(aa > bb) return 1;

    return 0;
}

int main(int argc, char **argv, char **env)
{
    int a[] = {2, 4, 27, -8, -9, 5, 8, 10};
    int b[] = {-1, 3, 5, 7, 20, 11};


    int alen = sizeof(a) /sizeof(a[0]);
    int blen = sizeof(b) /sizeof(b[0]);

    std::qsort(a, alen, sizeof(a[0]), cmp);
    std::qsort(b, blen, sizeof(b[0]), cmp);

    int *c = merge(a, alen, b, blen);

    for(int i = 0; i < (alen + blen); i++) {
        cout << c[i] << " ";
    }
    cout << endl;
    delete [] c;


    return 0;
}
