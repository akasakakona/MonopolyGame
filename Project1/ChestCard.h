#ifndef __CHESTCARD_H__
#define __CHESTCARD_H__

using namespace std;
#include "ChessPiece.h"


class ChestCard : public ChessPiece {
    public:

        ChestCard(string name, int id) {
            this->name = name;
            this->id = id;
        }
        
        ~ChestCard(){}

        //Returns name
        virtual string getName() {
            cout << "calling getName" << endl;
            return this->name;
        }

        //Returns ID
        virtual int getID() {
            return this->id;
        }


    private:
        
};

#endif //__CHESTCARD_H__