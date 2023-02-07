const path = require("path");
const express = require("express");
const exphbs = require('express-handlebars')

const app = express();

// set up hbs as view engine
app.engine('.hbs', exphbs.engine({ extname: '.hbs' }));
app.set('view engine', '.hbs');

// Set up "assets" folder so it is public.
app.use(express.static(path.join(__dirname, "/assets")));

// setup a 'route' to listen on the default url path (http://localhost)
app.get("/", function (req, res) {
    res.send("Home page");
});

// setup another route to listen on /about
app.get("/about", function (req, res) {
    res.render("about", {
        title: "About Us"
    });
});

app.get("/viewData", function(req,res){
    
    var someData = [{
        name: "John",
        age: 23,
        occupation: "developer",
        company: "Scotiabank"
    },
    {
        name: "John",
        age: 23,
        occupation: "developer",
        company: "Scotiabank"
    }];
    res.render('viewDataEach', {
        data: someData,
        layout: false
    })
});

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