#ifndef __CHANCECARD_H__
#define __CHANCECARD_H__

using namespace std;
#include "ChessPiece.h"


class ChanceCard : public ChessPiece {
    public:

        ChanceCard();
        
        ~ChanceCard();

        //Returns name
        virtual string getName() {
            return this->name;
        }


    private:
};

#endif //__CHANCECARD_H__