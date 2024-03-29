/*************************************************************************************
* WEB322 - 2231 Project
* I declare that this assignment is my own work in accordance with the Seneca Academic
* Policy. No part of this assignment has been copied manually or electronically from
* any other source (including web sites) or distributed to other students.
*
* Student Name  : 
* Student ID    : 
* Course/Section: WEB322 NCC
*
**************************************************************************************/

const path = require("path");
const express = require("express");
const exphbs = require("express-handlebars");
const clientSessions = require("client-sessions");
var mongoose = require("mongoose");
const app = express();

// Set up Handlebars.
app.engine('.hbs', exphbs.engine({
    extname: '.hbs',
    defaultLayout: ''
}));

app.set("view engine", ".hbs");

// body parser for form submission
app.use(express.urlencoded({ extended: true}));
// mongoose connect
mongoose.connect("mongodb+srv://hpatel292:pass123456@web322ncc.hyzqnhu.mongodb.net/example?retryWrites=true&w=majority", {
    useNewUrlParser: true,
    useUnifiedTopology: true
});

const nameSchema = new mongoose.Schema({
    "nickName": {
        "type": String,
        "unique": true
    },
    "fName" : String,
    "lName" : String,
    "age" : {
        "type": Number,
        "default": 20
    }
});

const nameModel = mongoose.model("exampleNames", nameSchema);


// Add your routes here
// e.g. app.get() { ... }
app.get('/', (req, res)=>{
    res.render("home", {layout : false});
})
let errors;
app.get("/viewTable", (req, res)=>{
    nameModel.find().then
    (data=>{
        
        let names = data.map(value => value.toObject());
        console.log(names);
        res.render("viewTable", {
            names,
            errMsg: errors
        })
    }).catch(err => {console.log("error")});
    
})

app.post("/addName", (req, res)=>{
    let {nickName, fName, lName, age} = req.body;
    age = parseInt(age)
    if (nickName === ""){
        errors = "NickName missing";
        res.redirect("/viewTable");
    }
    const newName = new nameModel({
        nickName,
        fName,
        lName,
        age
    })
    newName.save().then(() => {
        console.log("Record added");
        errors = "";
        res.redirect("/viewTable");
    }).catch((err)=>{console.log(err)});

})
app.get('/login', (req, res)=>{
    res.render("login", {layout : false})
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