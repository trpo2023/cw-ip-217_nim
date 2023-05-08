#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

class Ball{

    public:

        Ball(){
            ball.setRadius(radius);
            ball.setFillColor(sf::Color{242,130,141});
            ball.setPointCount(360);
        }

        Ball(sf::Vector2f position, int rad){
            ball.setRadius(rad);
            ball.setPointCount(360);
            ball.setFillColor(sf::Color{143, 185, 167 });    ///242,130,141
            ball.setOutlineThickness(1);
            ball.setOutlineColor(sf::Color(253,251,212));
            ball.setPosition(position);
        }

        ~Ball(){};

        void setRadius(int rad){
            radius = rad;
        }

        void setPosition(sf::Vector2f pos){
            //ball.setPosition(pos);
            ball.setPosition(pos.x - radius/2, pos.y - radius/2);
        }

        void changePosition(int razmak, int udaljenost){
            position.x += razmak;
            position.y += udaljenost;
        }

        void drawTo(sf::RenderWindow &window){
            window.draw(ball);
        }

        bool isMouseOver(sf::RenderWindow &window){
            int mouseX = sf::Mouse::getPosition(window).x;
            int mouseY = sf::Mouse::getPosition(window).y;

            float ballPosX = ball.getPosition().x;
            float ballPosY = ball.getPosition().y;

            float ballxPosWidth = ball.getPosition().x + ball.getLocalBounds().width;
            float ballyPosHeight = ball.getPosition().y + ball.getLocalBounds().height;

            if(mouseX < ballxPosWidth && mouseX > ballPosX && mouseY < ballyPosHeight && mouseY > ballPosY){
                return true;
            }else{
                return false;
            }
        }

        void light_color(){
            ball.setFillColor(sf::Color{253, 251, 212});   //253, 251, 212    242,130, 141
        }

        void normal_color(){
            ball.setFillColor(sf::Color{118, 93, 105});
        }

        void makeBall(){
            ball.setRadius(60);
            ball.setFillColor(sf::Color::Blue);
        }


        float getX(){
            return position.x;
        }
        float getY(){
            return position.y;
        }


    private:
        sf::CircleShape ball;
        int radius = 15;
        sf::Vector2f position = {0,0};

};

#endif // BALL_H_INCLUDED
