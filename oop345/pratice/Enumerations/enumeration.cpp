#include<iostream>
#include<string>

enum color{red, green, blue, white};

std::ostream& operator<<(std::ostream& ostr, color& a){
    std::string str;

    switch (a)
    {
    case red:
        str = "red";
        break;
    case green:
        str = "green";
        break;
    case blue:
        str = "blue";
        break;
    case white:
        str = "white";
        break;
    
    default:
    str = "none";
        break;
    

    }
    ostr << str;
    return ostr;
}

int main()
{
    color wall, ceiling, door; // define Colour variables
    wall = red;
    ceiling = white;
    door = green;

    std::cout << wall << ' ' << ceiling << ' ' << door << std::endl;
}