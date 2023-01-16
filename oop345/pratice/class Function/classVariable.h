class Horse{
    
    unsigned age;
    unsigned id;
    static unsigned noHorses;
    public:
    

    Horse(unsigned horseAge);
    ~Horse();
    static unsigned howMany();
    void display() const;
};