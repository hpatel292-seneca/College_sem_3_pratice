// making of Objects using object literals
var person = {
    name: "John",
    age: "16",
    occupation: "Computer",
    setName: function(name){this.name = name},
    setAge: function(age){this.age = age},
    getName: function(){return this.name},
    getAge: function(){return this.age},
}

console.log("The person's age is "+person.getAge())
console.log("The person's Name is "+person.getName())

// Making of objects using constructor and class and new keyword

class Person{
    name;
    age;
    occupation;
    constructor(setAge="", setName="", setOccupation=""){
        this.name = setName;
        this.age = setAge;
        this.occupation = setOccupation;
    }
    setName(name){this.name = name};
    setAge(age){this.age = age};
}

var person1 = new Person("12", "Karan");

console.log("The person's Name is "+person1.name);