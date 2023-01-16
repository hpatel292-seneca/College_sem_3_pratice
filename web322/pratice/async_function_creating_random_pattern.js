// output "A" after a random time between 0 & 3 seconds
function outputA(){
    var randomTime = Math.floor(Math.random() * 3000) + 1;
    return new Promise(function(resolve, reject){
        setTimeout(function(){
                console.log("A");
                resolve("A is completed");
        },randomTime);
    })
    
}

// output "B" after a random time between 0 & 3 seconds
function outputB(){
    var randomTime = Math.floor(Math.random() * 3000) + 1;
    return new Promise(function(resolve, reject){
        setTimeout(function(){
            console.log("B");
            resolve("B is completed");
    },randomTime);
    })
    
}

// output "C" after a random time between 0 & 3 seconds
function outputC(){
    var randomTime = Math.floor(Math.random() * 3000) + 1;

    setTimeout(function(){
        console.log("C");
    },randomTime);
}

// invoke the functions in order

// outputA().then(outputB().then(console.log("New one")));

// outputB().then(outputA());
// Above both one would not work as .then() require function to be passed as argument.
// outputA().then(function(){
//     outputB().then(()=>{outputC();});
// })
// the above will work as i have passed the function in both .then() so the above live will generate "A B c" in sequence

outputA().then(outputB).then(outputC);   // this will print "A B c" in sequence
outputA().then(outputB().then(outputC()));  // this will print "A B c" out-of-sequence