const Express = require('express');
const app = Express();

app.use("/" ,function (req, res, next) {
//   console.log('Time: %d', Date.now())
    res.send("In middleware");
  next()
})

app.get("/", (req, res)=> {
    res.send("Hello World");
})

app.get("/home", (req, res)=>{
    res.send("Home");
})



app.listen(8080);
