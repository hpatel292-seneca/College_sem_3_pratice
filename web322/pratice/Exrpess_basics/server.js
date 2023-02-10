const express = require('express');

const app = express();

const onHttpStart = function(){
    console.log("Server is running");
}

app.get('/', (req, res)=>{
    res.send("Hello world ");
})

app.get("/header", (req, res)=>{
    res.send("Hello world from '/header'");
})
app.get('/add', (req, res)=>{
    res.send("Hello World from '/add' route");
})

app.use(function (req, res, next) {
    console.log('Time: %d', Date.now())
    next()
  })
app.use((req, res)=>{
    res.send("error 404");
})
app.listen(8080, onHttpStart);