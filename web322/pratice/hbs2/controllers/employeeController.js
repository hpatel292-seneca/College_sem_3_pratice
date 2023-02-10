const express = require('express');
const router = express.Router();

let data = require("../model/employee");
router.get('/', function (req, res) {

    res.render('employee/home', {employees: data.getAllEmployees(),});
});

router.get('/visible', function (req, res){
    
    res.render('employee/visible', {employees: data.getFilteredEmployees(),});
});


module.exports = router;