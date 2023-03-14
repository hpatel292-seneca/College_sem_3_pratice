

const path = require("path");
const express = require("express");
const exphbs = require("express-handlebars");
const clientSessions = require("client-sessions");
const app = express();

// Add your routes here
// e.g. app.get() { ... }
// static folder
app.use(express.static("static"));

// Setup client-sessions
app.use(clientSessions({
    cookieName: "session", // this is the object name that will be added to 'req'
    secret: "week10example_web322", // this should be a long un-guessable string.
    duration: 2 * 60 * 1000, // duration of the session in milliseconds (2 minutes)
    activeDuration: 1000 * 60 // the session will be extended by this many ms each request (1 minute)
  }));

// Register handlerbars as the rendering engine for views
app.engine(".hbs", exphbs.engine({ extname: ".hbs" }));
app.set("view engine", ".hbs");

// setup body parser
app.use(express.urlencoded({extended: true}));

// actual body part
const user = {
    username: "SampleUserName",
    password: "SamplePassword",
    email: "SampleEmail"
}

app.get("/", (req, res)=>{
    res.redirect("/login");
})

app.get("/login", (req, res)=>{
    res.render("login", {layout: false});
})

app.post("/login", (req, res)=>{
    const username = req.body.username;
    const password = req.body.password;

    if(username === "" || password === "") {
        // Render 'missing credentials'
        return res.render("login", { errorMsg: "Missing credentials.", layout: false });
    }
    else if(username === user.username && password === user.password){
        // this will store session with user
        req.session.user = {
            username: user.username,
            email: user.email
        }
        res.redirect("/dashboard");
    }
        else{
            return res.render("login", { errorMsg: "Incorrect credentials.", layout: false });
        }
    }
);
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