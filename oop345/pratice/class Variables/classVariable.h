class Horse{
    
    unsigned age;
    unsigned id;
    public:
    static unsigned noHorses;

    Horse(unsigned horseAge);
    ~Horse();

    void display() const;
};

// class Horse
// {
//     unsigned age;             // <-- this is an instance variable
//     unsigned id;              // <-- this is an instance variable
// public:
//     static unsigned noHorses; // <-- this is a class variable

//     Horse(unsigned a);
//     ~Horse();

//     void display() const;
// };
