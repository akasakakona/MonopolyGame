#ifndef __CHANCECARD_H__
#define __CHANCECARD_H__

using namespace std;
#include "ChessPiece.h"


class ChanceCard : public ChessPiece {
    public:

        ChanceCard(string name, int id) {
            this->name = name;
            this->id = id;
        }
        
        ~ChanceCard();

        //Returns name - in other words description of card
        virtual string getName() {
            return this->name;
        }

        //Returns ID
        virtual int getID() {
            return this->id; 
        }


    private:
        
};

#endif //__CHANCECARD_H__