#ifndef __CHESSPIECE_H__
#define __CHESSPIECE_H__

using namespace std;
#include <iostream>

class ChessPiece {
    public:
        ChessPiece();
        virtual ~ChessPiece();
        virtual string getName() = 0;
        virtual int getID() = 0;
    private:
        string name;
        int id;
};

#endif //__CHESSPIECE_H__