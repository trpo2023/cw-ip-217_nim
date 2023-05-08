#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class player{

public:

    player(){};

    player(int np){
        pobjede=0;
        naPotezu = np;
        zavrsio = 0;
        skip = 0;
    }

    void moveDone(){
        if (naPotezu==1){
            naPotezu = 0;
        }
        else {
            naPotezu = 1;
        }
    }

    int jeNaPotezu(){
        return naPotezu;
    }

    int getNaPotezu(){
        return getNaPotezu();
    }

    void setPobjede(){
        pobjede++;
    }
    void resetPobjede(){
        pobjede = 0;
    }
    int getPobjede(){
        return pobjede;
    }

    void addSkip(){
        skip++;
    }
    void removeSkip(){
        skip--;
    }
    void resetSkip(){
        skip = 0;
    }
    int getSkip(){
        return skip;
    }



private:
    int pobjede;
    int skip;
    int naPotezu;
    int zavrsio;
    sf::Text text;

};

#endif // PLAYER_H_INCLUDED
