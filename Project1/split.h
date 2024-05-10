// split.h
#ifndef GUARD_split_h
#define GUARD_split_h

#include <algorithm> // find_if()
#include <cctype> // 
#include <string>

using namespace std;

inline bool space(char c) {
    return isspace(c);
}

// �μ��� ������ ���� false, �׷��� �������� true
inline bool not_space(char c) {
    return !isspace(c);
}

template <class Out>
void split(const string& str, Out os) {

    typedef string::const_iterator iter;

    iter i = str.begin();

    // for(iter i = str.begin(); i != str.end(); i++) {}
    while (i != str.end()) {

        i = find_if(i, str.end(), not_space);

        iter j = find_if(i, str.end(), space);

        // [i, j) ������ ���ڸ� ����
        if (i != str.end()) {
            *os++ = string(i, j);
        }

        // i�ݺ��� ��ġ�� j�ݺ����� ��ġ�� ���� 
        i = j;
    }
}

#endif