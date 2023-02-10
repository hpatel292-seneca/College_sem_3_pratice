const express = require('express');
const exphbs = require('express-handlebars');
const path = require('path');
const data = require("./model/employee");

const app = express();

let generalControllers = require("./controllers/generalController");
let employeeControllers = require("./controllers/employeeController");
app.engine(".hbs", exphbs.engine({
    extname: ".hbs",
    defaultLayout: 'main',
}));
app.set("view engine", ".hbs");

app.use('/', generalControllers);
app.use('/employees', employeeControllers);


app.listen(8080);