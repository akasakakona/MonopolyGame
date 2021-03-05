#ifndef __CHESSPIECE_H__
#define __CHESSPIECE_H__

using namespace std;
#include <iostream>

class ChessPiece {
    public:
        ChessPiece();
        virtual ~ChessPiece();
        virtual string getName() = 0;
    private:
        string name;
};

#endif //__CHESSPIECE_H__