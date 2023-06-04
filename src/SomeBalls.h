#ifndef SOMEBALLS_H_INCLUDED
#define SOMEBALLS_H_INCLUDED

#include <iostream>
#include <list>
#include "Ball.h"

using namespace std;

class SomeBalls{

    public:

        SomeBalls(int x, int y, int num){
            float duz = x;
            int razmak = 30;
            for(int i=0; i<num; i++){
            lista.push_back(Ball({duz, y},30));
                duz += 60.0;
            }
        }

        ~SomeBalls(){
            lista.clear();
        }


        void makeBalls(int x, int y, int num){
            float duz = x+60.0;
            for(int i=0; i<num; i++){
            lista.push_back(Ball({duz, y},30));
                duz += 60.0;
            }
        }


        std::list<Ball>::iterator it;
        void drawTo1(sf::RenderWindow &window){
            for(Ball b : lista){
                b.drawTo(window);
            }
        }


         void getOne(){
            lista.front().light_color();
        }
        void letOne(){
            lista.front().normal_color();
        }

        void getOne2(){
            lista.back().light_color();
            std::list<Ball>::iterator it = lista.begin();
                lista.pop_back();
            }
        void letOne2(){
            lista.back().normal_color();
        }

        void isprazniListu(int size){
            for(int i=0; i<size-1; i++){
                lista.pop_back();
            }
        }


        void light_color1(){
            for(Ball b : lista){
                b.light_color();
            }
        }


        bool isMouseOver1(sf::RenderWindow &window){
            for(Ball b : lista){
                if(b.isMouseOver(window)){
                    return true;
                }else{
                    return false;
                }
            }
        }

        std::list<Ball> getList(){
            return lista;
        }

        bool isMouseOver(sf::RenderWindow &window){
            for(Ball b : lista){
                return b.isMouseOver(window);
            }
        }

        int prazanRed(){
            if(lista.size()==1){
                return 1;
            }
            else return 0;
        }

        void setOstaoJedan(bool tf){
            ostaoJedan = tf;
        }

    private:
        std::list<Ball> lista;
        int numOfBalls;
        bool ostaoJedan = false;
};


#endif 
