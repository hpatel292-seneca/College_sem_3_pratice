
const path = require("path");
const express = require("express");
const exphbs = require("express-handlebars");
const mongoose = require("mongoose");
const app = express();


// Set up Handlebars.
app.engine('.hbs', exphbs.engine({
    extname: '.hbs',
    defaultLayout: ''
}));

app.set("view engine", ".hbs");

// Set up Body Parser.
app.use(express.urlencoded({ extended: true }));

// Connect to the mongodb
mongoose.connect("mongodb+srv://hpatel292:pass123456@web322ncc.hyzqnhu.mongodb.net/example?retryWrites=true&w=majority", {
    useNewUrlParser: true,
    useUnifiedTopology: true
});

const schema = new mongoose.Schema({
    "nikeName" : {
        "type" : "string",
        "unique" : true
    },
    "fname" : String,
    "lname" : String,
    "age" : {
        "type" : Number,
        "default" : 20
    }
});

const nameModel = mongoose.model("name", schema);



// Add your routes here
// e.g. app.get() { ... }
app.get("/", (req, res) => {
    nameModel.find().then
    (data=>{
        
        let names = data.map(value => value.toObject());
        console.log(names);
        res.render("nameTable", {
            names
        })
    }).catch(err => {console.log("error")});

    
});

// adding name
app.post("/addName", (req, res) => {
    let {nickname, fName, lName, age} = req.body;
    age = parseInt(age);
    const newName = new nameModel({
        nikeName: nickname,
        fname: fName,
        lname: lName,
        age
    })

    newName.save().then
    (() => {console.log("Data added correctly");
            res.redirect("/");
            }
     )
     .catch((err)=>{
        console.log("error");
        res.redirect("/");
     })
})

// update or delete names
app.post("/updateName", (req, res) => {
    let {nickname, fName, lName, age} = req.body;
    // trim() and name.length
    if(fName.trim().length == 0 && lName.trim().length == 0){
        // delete record
        nameModel.deleteOne({nikeName: nickname})
        .then(() => {console.log("record deleted successfully"); res.redirect("/");})
        .catch((err)=>{console.log("error"); res.redirect("/");});
    }
    else{
        // update record
        age = parseInt(age);
        // converting age from string to number and if not a number make it undefined 
        // as if we add a string in a item whose datatype is number, it will broke.
        if (isNaN(age))
            age = undefined;

            nameModel.updateOne({
                nikeName : nickname,
            }, {
                $set: {
                    lname: lName,
                    fname: fName,
                    age
                }
            })
                .then(() => {
                    console.log("Successfully updated the document for: ");
                    res.redirect("/");
                })
                .catch(err => {
                    console.log("Failed to update the document for: ");
                    res.redirect("/");
                });
            
    }
})
// *** DO NOT MODIFY THE LINES BELOW ***

// This use() will not allow requests to go beyond it
// so we place it at the end of the file, after the other routes.
// This function will catch all other requests that don't match
// any other route handlers declared before it.
// This means we can use it as a sort of 'catch all' when no route match is found.
// We use this function to handle 404 requests to pages that are not found.
app.use((req, res) => {
    res.status(404).send("Page Not Found");
});

// This use() will add an error handler function to
// catch all errors.
app.use(function (err, req, res, next) {
    console.error(err.stack)
    res.status(500).send("Something broke!")
});

// Define a port to listen to requests on.
const HTTP_PORT = process.env.PORT || 8080;

// Call this function after the http server starts listening for requests.
function onHttpStart() {
    console.log("Express http server listening on: " + HTTP_PORT);
}
  
// Listen on port 8080. The default port for http is 80, https is 443. We use 8080 here
// because sometimes port 80 is in use by other applications on the machine
app.listen(HTTP_PORT, onHttpStart);