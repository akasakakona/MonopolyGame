#ifndef __CHESSPIECE_H__
#define __CHESSPIECE_H__

using namespace std;
#include <iostream>

class ChessPiece {
    public:

        virtual ~ChessPiece() = default;
        virtual string getName() = 0;
        virtual int getID() = 0;
    protected:
        string name;
        int id;
};

#endif //__CHESSPIECE_H__