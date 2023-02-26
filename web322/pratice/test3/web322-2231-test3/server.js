/************************************************************************************
*  WEB322 - Test #3 (Winter 2023)
*  I declare that this solution is my own work in accordance with the Seneca Academic
*  Policy. No part of this test has been copied manually or electronically from
*  any other source (including web sites) or distributed to other students.
*  
*  For the questions contained in this file only, you may refer to the web322.ca
*  website and code examples and the lecture slides (from this class).
*  Be careful not to spend too much time looking at these references!
*
*  Name: Harshil Patel
*  Student Email:  hpatel292@myseneca.ca
*  Course/Section: WEB322/NCC
* 
************************************************************************************/

const path = require("path");
const express = require("express");
const exphbs = require('express-handlebars');

// Initialize express with handlebars.
const app = express();

app.engine('.hbs', exphbs({
    extname: '.hbs',
    defaultLayout: ''
}));

app.set('view engine', '.hbs');

// ******** DO NOT CHANGE ANYTHING ABOVE THIS LINE (EXCEPT THE HEADER) ********



// *** PART A - 2 Marks ***
// Create a "GET" route at the default url "/" (eg. http://localhost/)
// and send the handlebars view "home.hbs".  You must pass the array
// to the view.  You will use this array for part B.
app.get("/", function(req,res){
    let dataToShow = [
        { customerId: 2221001, companyName: "Foobar Electronics", isActive: false },
        { customerId: 2221002, companyName: "Chinook Music", isActive: true },
        { customerId: 2221003, companyName: "Contoso Ltd", isActive: true }
    ];
	
	// Insert code here
	res.render("home.hbs", {
        data:dataToShow,
        layout: false
        });
});



// *** PART B - 8 Marks ***
// Modify the HandleBars view called "home.hbs".  In the view file you
// will design a table to display a list of customers.  The view file
// has already been started but you must fill in the blanks.
// An example of the view is available in the file "home-page-example.png"
// located in the root folder.



// ******** DO NOT CHANGE ANYTHING BELOW THIS LINE ********

// A "route" that is invoked if no other paths are matched.
app.use((req, res) => {
    res.status(404).send("Page Not Found");
});

var HTTP_PORT = process.env.PORT || 8080;

function onHttpStart() {
    console.log("Express http server listening on: " + HTTP_PORT);
}

app.listen(HTTP_PORT, onHttpStart);