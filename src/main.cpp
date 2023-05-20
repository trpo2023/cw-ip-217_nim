#include <SFML/Graphics.hpp>
#include <iostream>

#include "Ball.h"
#include "SomeBalls.h"
#include "Button.h"
#include "player.h"


int main(){

    sf::Font asper;
    if(!asper.loadFromFile("font/Aspergit_Bold.otf")){
        return -1;
    }


    sf::Texture texture;
    if(!texture.loadFromFile("img/nim11.jpg")){
        return -1;
    }
    texture.setSmooth(true);
    texture.setRepeated(true);
    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::Texture texture1;
    if(!texture1.loadFromFile("img/nimFirst.jpg")){
        return -1;
    }
    texture1.setSmooth(true);
    texture1.setRepeated(true);
    sf::Sprite sprite1;
    sprite1.setTexture(texture1);


    //buttons
    Button bt3("Next turn", {120, 30}, 20, sf::Color{253, 251, 212} , sf::Color::Black);
    bt3.setPosition({5, 10});
    bt3.setFont(asper);

    Button bt1("New game", {120, 30}, 20, sf::Color{253, 251, 212} , sf::Color::Black);
    bt1.setPosition({25 , 55});
    bt1.setFont(asper);

    Button bt2("Exit game", {125, 30}, 20, sf::Color{253, 251, 212} , sf::Color::Black);
    bt2.setPosition({650, 450});
    bt2.setFont(asper);

    Button bt10("Reset score", {125, 30}, 20, sf::Color{253, 251, 212} , sf::Color::Black);
    bt10.setPosition({650, 173});
    bt10.setFont(asper);

    Button bt4("Game info", {131, 30}, 20, sf::Color{253, 251, 212} , sf::Color::Black);
    bt4.setPosition({342, 300});
    bt4.setFont(asper);

    Button bt5("Play Classic", {130, 30}, 20, sf::Color{253, 251, 212} , sf::Color::Black);
    bt5.setPosition({265, 200});
    bt5.setFont(asper);

    Button bt6("Exit Game", {130, 30}, 20, sf::Color{253, 251, 212} , sf::Color::Black);
    bt6.setPosition({410, 245});
    bt6.setFont(asper);

    Button bt7("Main Menu", {125, 30}, 20, sf::Color{253, 251, 212} , sf::Color::Black);
    bt7.setPosition({650, 400});
    bt7.setFont(asper);

    Button bt8("Play Reverse", {130, 30}, 20, sf::Color{253, 251, 212} , sf::Color::Black);
    bt8.setPosition({410, 200});
    bt8.setFont(asper);

    Button bt9("  Resume", {130, 30}, 20, sf::Color{253, 251, 212} , sf::Color::Black);
    bt9.setPosition({265, 245});
    bt9.setFont(asper);

    Button bt11("  Skip ", {130, 30}, 20, sf::Color{253, 251, 212} , sf::Color::Black);
    bt11.setPosition({650, 300});
    bt11.setFont(asper);


    SomeBalls *s  = new SomeBalls(8*30, 0, 2);
    SomeBalls *sb = new SomeBalls(6*30, 100, 4);
    SomeBalls *sb1 = new SomeBalls(4*30, 200, 6);
    SomeBalls *sb2 = new SomeBalls(2*30, 300, 8);
    SomeBalls *sb3 = new SomeBalls(0, 400, 10);


    player p1(1);
    player p2(0);


    sf::Text text1;
    text1.setString("Player 1 on move");
    text1.setFont(asper);
    text1.setCharacterSize(17);
    text1.setStyle(sf::Text::Bold);
    text1.setColor(sf::Color{253, 251, 212});
    text1.setPosition({622, 30});

    sf::Text textO1;
    textO1.setFont(asper);
    textO1.setCharacterSize(45);
    textO1.setStyle(sf::Text::Bold);
    textO1.setColor(sf::Color{143, 185, 167});
    textO1.setPosition({200, 200});

    sf::Text text4;
    text4.setFont(asper);
    text4.setCharacterSize(20);
    text4.setStyle(sf::Text::Bold);
    text4.setColor(sf::Color{143, 185, 167});
    text4.setPosition({120, 485});

    sf::Text text5("SCORE ", asper);
    text5.setCharacterSize(25);
    text5.setStyle(sf::Text::Bold);
    text5.setColor(sf::Color{253, 251, 212});
    text5.setPosition({650, 95});

    sf::Text text12("SKIP ", asper);
    text12.setCharacterSize(20);
    text12.setStyle(sf::Text::Bold);
    text12.setColor(sf::Color{253, 251, 212});
    text12.setPosition({650, 235});

    sf::Text text7;
    text7.setFont(asper);
    text7.setCharacterSize(17);
    text7.setStyle(sf::Text::Bold);
    text7.setColor(sf::Color{143, 185, 167});
    text7.setPosition({410, 83});

    sf::Text text8;
    text8.setFont(asper);
    text8.setCharacterSize(16);
    text8.setStyle(sf::Text::Bold);
    text8.setColor(sf::Color{143, 185, 167});
    text8.setPosition({151, 350});

    sf::Text text10("NIM GAME", asper);
    text10.setCharacterSize(80);
    text10.setStyle(sf::Text::Bold);
    text10.setColor(sf::Color{143, 185, 167});
    text10.setPosition({175, 10});

    sf::Text text11;        
    text11.setFont(asper);
    text11.setCharacterSize(35);
    text11.setStyle(sf::Text::Bold);
    text11.setColor(sf::Color{253, 251, 212});
    text11.setPosition({650, 125});

    sf::Text text13;    
    text13.setFont(asper);
    text13.setCharacterSize(25);
    text13.setStyle(sf::Text::Bold);
    text13.setColor(sf::Color{253, 251, 212});
    text13.setPosition({650, 260});


    int ind = 1;
    int indKolona0 = 0;  
    int indKolona1 = 0;
    int indKolona2 = 0;
    int indKolona3 = 0;
    int indKolona4 = 0;
    int gOver = 0;       
    int newG = 0;         
    int indProzora = 0;  
    int game = 0;        
    int misere = 0;       
    int indS = 0;         
    int indTurn = 0;      


    while(game == 0){
        if(indProzora == 0){ 

            sf::RenderWindow window2;
            window2.create(sf::VideoMode(800, 530), "Nim menu", sf::Style::Titlebar | sf::Style::Close);  
            window2.setFramerateLimit(60);
            window2.setKeyRepeatEnabled(false);


            while(window2.isOpen()){

                sf::Event event;
                while(window2.pollEvent(event)){
                    switch(event.type){

                    case sf::Event::Closed:
                    game = 1;
                    window2.close();
                    break;

                    case sf::Event::MouseMoved:
                    if(bt4.isMouseOver(window2)){
                        bt4.setBackColor(sf::Color{118, 93, 105});
                    }else{
                        bt4.setBackColor(sf::Color{253, 251, 212});
                    }
                    if(bt5.isMouseOver(window2)){
                        bt5.setBackColor(sf::Color{118, 93, 105});
                    }else{
                        bt5.setBackColor(sf::Color{253, 251, 212});
                    }
                    if(bt6.isMouseOver(window2)){
                        bt6.setBackColor(sf::Color{118, 93, 105});
                    }else{
                        bt6.setBackColor(sf::Color{253, 251, 212});
                    }
                    if(bt8.isMouseOver(window2)){
                        bt8.setBackColor(sf::Color{118, 93, 105});
                    }else{
                        bt8.setBackColor(sf::Color{253, 251, 212});
                    }
                    if(bt9.isMouseOver(window2)){
                        bt9.setBackColor(sf::Color{118, 93, 105});
                    }else{
                        bt9.setBackColor(sf::Color{253, 251, 212});
                    }
                    break;

                    case sf::Event::MouseButtonPressed:
                    if(bt5.isMouseOver(window2)){
                        if(indS == 1 && newG!=1){
                        text4.setString("Click next to start new game!");
                        textO1.setString(" ");
                        ind = 0;
                        s->isprazniListu(s->getList().size());
                        sb->isprazniListu(sb->getList().size());
                        sb1->isprazniListu(sb1->getList().size());
                        sb2->isprazniListu(sb2->getList().size());
                        sb3->isprazniListu(sb3->getList().size());

                        s->makeBalls(8*30, 0, 1);
                        sb->makeBalls(6*30, 100, 3);
                        sb1->makeBalls(4*30, 200, 5);
                        sb2->makeBalls(2*30, 300, 7);
                        sb3->makeBalls(0, 400, 9);
                        }
                        if(newG == 1){
                            text4.setString("Click NEW GAME and then NEXT");
                            textO1.setString(" ");
                            ind = 0;
                        }
                        indProzora = 1;
                        misere = 0;
                        p1.resetPobjede();
                        p2.resetPobjede();
                        window2.close();
                    }
                    if(bt4.isMouseOver(window2)){
                       text8.setString("GAME INFO: \n"
                    "In Classic variant you have to pick the last dot to win. \n"
                    "In Reverse variant avoid picking the last dot to win. \n"
                    "Dots can only be picked out of one row, \n"
                    "but in that row you can pick as many dots as you want \n"
                    "Whenever you finish your move click NEXT TURN \n"
                    "then the second player goes on. \n"
                    "When the game is finished click NEW GAME \n"
                    "and then NEXT TURN to play again. \n"
                    " HAVE FUN! \n");
                    }
                    if(bt6.isMouseOver(window2)){
                        game = 1;
                        window2.close();
                    }if(bt8.isMouseOver(window2)){
                        if(indS == 1 && newG!=1){
                        text4.setString("Click next to start new game!");
                        textO1.setString(" ");
                        ind = 0;
                        s->isprazniListu(s->getList().size());
                        sb->isprazniListu(sb->getList().size());
                        sb1->isprazniListu(sb1->getList().size());
                        sb2->isprazniListu(sb2->getList().size());
                        sb3->isprazniListu(sb3->getList().size());

                        s->makeBalls(8*30, 0, 1);
                        sb->makeBalls(6*30, 100, 3);
                        sb1->makeBalls(4*30, 200, 5);
                        sb2->makeBalls(2*30, 300, 7);
                        sb3->makeBalls(0, 400, 9);
                        }
                        if(newG == 1){
                            text4.setString("Click NEW GAME and then NEXT");
                            textO1.setString(" ");
                            ind = 0;
                        }
                        p1.resetPobjede();
                        p2.resetPobjede();
                        indProzora = 1;
                        misere = 1;
                        window2.close();
                    }if(bt9.isMouseOver(window2)){
                        indProzora = 1;
                        window2.close();
                    }
                    break;
                }
            }
            window2.clear();
            window2.draw(sprite1);
            bt4.drawTo(window2);
            bt5.drawTo(window2);
            bt6.drawTo(window2);
            bt8.drawTo(window2);
            bt9.drawTo(window2);
            window2.draw(text8);
            window2.draw(text10);
            window2.display();
        }
        }else{ 

            text8.setString(" ");
            indS = 1;

            sf::RenderWindow window;
            window.create(sf::VideoMode(800, 530), "NIM game", sf::Style::Titlebar | sf::Style::Close);
            window.setFramerateLimit(60);
            window.setKeyRepeatEnabled(false);

            while(window.isOpen()){
                sf::Event event;
                while(window.pollEvent(event)){
                    switch(event.type){

                    case sf::Event::Closed:
                    game = 1;
                    window.close();
                    indProzora = 1;
                    break;

                    case sf::Event::MouseMoved:
                    if(s->isMouseOver1(window)){
                        s->getOne();
                    } else {
                        s->letOne();
                    }
                    if(sb->isMouseOver1(window)){
                        sb->getOne();
                    } else {
                        sb->letOne();
                    }
                    if(sb1->isMouseOver1(window)){
                        sb1->getOne();
                    } else {
                        sb1->letOne();
                    }
                    if(sb2->isMouseOver1(window)){
                        sb2->getOne();
                    } else {
                        sb2->letOne();
                    }
                    if(sb3->isMouseOver1(window)){
                        sb3->getOne();
                    } else {
                        sb3->letOne();
                    }
                    if(bt1.isMouseOver(window)){
                        bt1.setBackColor(sf::Color{118, 93, 105});
                    }else{
                        bt1.setBackColor(sf::Color{253, 251, 212});
                    }
                    if(bt2.isMouseOver(window)){
                        bt2.setBackColor(sf::Color{118, 93, 105});
                    }else{
                        bt2.setBackColor(sf::Color{253, 251, 212});
                    }
                    if(bt3.isMouseOver(window)){
                        bt3.setBackColor(sf::Color{118, 93, 105});
                    }else{
                        bt3.setBackColor(sf::Color{253, 251, 212});
                    }
                    if(bt7.isMouseOver(window)){
                        bt7.setBackColor(sf::Color{118, 93, 105});
                    }else{
                        bt7.setBackColor(sf::Color{253, 251, 212});
                    }
                    if(bt10.isMouseOver(window)){
                        bt10.setBackColor(sf::Color{118, 93, 105});
                    }else{
                        bt10.setBackColor(sf::Color{253, 251, 212});
                    }
                    if(bt11.isMouseOver(window)){
                        bt11.setBackColor(sf::Color{118, 93, 105});
                    }else{
                        bt11.setBackColor(sf::Color{253, 251, 212});
                    }
                    break;

                    case sf::Event::MouseButtonPressed:
                    if(sb->prazanRed() == false){
                        if(indKolona1==0 && indKolona2==0 && indKolona3==0 && indKolona4==0){
                            if(sb->isMouseOver1(window)){
                                if(sb->getList().size()>1){
                                    sb->getOne2();
                                    indTurn = 1;
                                }
                                if(sb->getList().size() == 1){
                                    sb->setOstaoJedan(true);
                                }
                                indKolona0 = 1;
                                text4.setString(" ");
                            }
                        } else {
                            text4.setString("Please select dots out of one row");
                        }
                    }
                    if(s->prazanRed() == false){
                        if(s->isMouseOver1(window)){
                            if(indKolona0==0 && indKolona2==0 && indKolona3==0 && indKolona4==0){
                                if(s->getList().size()>1){
                                    s->getOne2();
                                    indTurn = 1;
                                }
                                if(s->getList().size() == 1){
                                    s->setOstaoJedan(true);
                                }
                                indKolona1 = 1;
                                text4.setString(" ");
                            }else {
                                text4.setString("Please select dots out of one row");
                            }
                        }
                    }
                    if(sb1->prazanRed() == false){
                        if(sb1->isMouseOver1(window)){
                            if(indKolona0==0 && indKolona1==0 && indKolona3==0 && indKolona4==0){
                                if(sb1->getList().size()>1){
                                    sb1->getOne2();
                                    indTurn = 1;
                                }
                                if(sb1->getList().size() == 1){
                                    sb1->setOstaoJedan(true);
                                }
                                indKolona2 = 1;
                                text4.setString(" ");
                            }else {
                                text4.setString("Please select dots out of one row");
                            }
                        }
                    }
                    if(sb2->prazanRed() == false){
                        if(indKolona0==0 && indKolona1==0 && indKolona2==0 && indKolona4==0){
                            if(sb2->isMouseOver1(window)){
                                if(sb2->getList().size()>1){
                                    sb2->getOne2();
                                    indTurn = 1;
                                }
                                if(sb2->getList().size() == 1){
                                    sb2->setOstaoJedan(true);
                                }
                                indKolona3 = 1;
                                text4.setString(" ");
                            }else{
                                text4.setString("Please select dots out of one row");
                            }
                        }
                    }
                    if(sb3->prazanRed() == false){
                        if(indKolona0==0 && indKolona1==0 && indKolona2==0 && indKolona3==0){
                            if(sb3->isMouseOver1(window)){
                                if(sb3->getList().size()>1){
                                    sb3->getOne2();
                                    indTurn = 1;
                                }
                                if(sb3->getList().size() == 1){
                                    sb3->setOstaoJedan(true);
                                }
                                indKolona4 = 1;
                                text4.setString(" ");
                            }else{
                                text4.setString("Please select dots out of one row");
                            }
                        }
                    }
                    if(bt1.isMouseOver(window)){
                        if(gOver == 1 && newG ==1){
                            text4.setString("Click next to start new game!");
                            textO1.setString(" ");
                            s->makeBalls(8*30, 0, 1);
                            sb->makeBalls(6*30, 100, 3);
                            sb1->makeBalls(4*30, 200, 5);
                            sb2->makeBalls(2*30, 300, 7);
                            sb3->makeBalls(0, 400, 9);
                            newG = 0;
                            indTurn = 1;
                        }else{
                            text7.setString("Finish this game first");
                        }
                    }
                    if(bt2.isMouseOver(window)){
                        game = 1;
                        window.close();
                        indProzora = 1;
                    }
                    if(bt10.isMouseOver(window)){
                        p1.resetPobjede();
                        p2.resetPobjede();
                        p1.resetSkip();
                        p2.resetSkip();
                    }
                    if(bt3.isMouseOver(window)){
                        if(indTurn == 1){
                        text7.setString(" ");
                        if(newG!=1){
                        if(s->getList().size()>1 || sb->getList().size()>1 || sb1->getList().size()>1 || sb2->getList().size()>1 || sb3->getList().size()>1){
                            p1.moveDone();
                            indKolona0 = 0;
                            indKolona1 = 0;
                            indKolona2 = 0;
                            indKolona3 = 0;
                            indKolona4 = 0;
                            text4.setString(" ");
                            if(ind == 1){
                                ind = 0;
                                text1.setString("Player 2 on move");
                            }else{
                                ind = 1;
                                text1.setString("Player 1 on move");
                            }
                        } else {
                            if(p1.jeNaPotezu() == 1){
                                if(misere == 0){
                                    textO1.setString("PLAYER 1 WINS");
                                    gOver = 1;
                                    p1.setPobjede();
                                    p1.addSkip();
                                } else{
                                    textO1.setString("PLAYER 2 WINS");
                                    gOver = 1;
                                    p2.setPobjede();
                                    p2.addSkip();
                                }
                            }else{
                                if(misere == 0){
                                    textO1.setString("PLAYER 2 WINS");
                                    gOver = 1;
                                    p2.setPobjede();
                                    p2.addSkip();
                                } else{
                                    textO1.setString("PLAYER 1 WINS");
                                    gOver = 1;
                                    p1.setPobjede();
                                    p1.addSkip();
                                }
                            }
                            newG = 1;
                        }
                    }
                        indTurn = 0;
                    }
                    }
                    if(bt7.isMouseOver(window)){
                        window.close();
                        indProzora = 0;
                    }
                    if(bt11.isMouseOver(window)){
                        if(ind==1){
                            if(p1.getSkip() > 0){
                                p1.removeSkip();
                                ind = 0;
                                text1.setString("Player 2 on move");
                            }
                        }else if(ind == 0){
                            if(p2.getSkip() > 0){
                                p2.removeSkip();
                                ind = 1;
                                text1.setString("Player 1 on move");
                            }
                        }
                    }
                    break;
                }
                text11.setString(to_string(p1.getPobjede()) + " : " + to_string(p2.getPobjede()) );
                text13.setString(to_string(p1.getSkip()) + " : " + to_string(p2.getSkip()));
            }

            window.clear();
            window.draw(sprite);
            window.draw(textO1);
            window.draw(text1);
            window.draw(text7);
            window.draw(text4);
            window.draw(text5);
            window.draw(text11);
            window.draw(text12);
            window.draw(text13);
            bt1.drawTo(window);
            bt2.drawTo(window);
            bt10.drawTo(window);
            bt11.drawTo(window);
            bt3.drawTo(window);
            bt7.drawTo(window);
            s->drawTo1(window);
            sb->drawTo1(window);
            sb1->drawTo1(window);
            sb2->drawTo1(window);
            sb3->drawTo1(window);
            window.display();

            }
        }
    }
    delete s;
    delete sb;
    delete sb1;
    delete sb2;
    delete sb3;

    return 0;

}
