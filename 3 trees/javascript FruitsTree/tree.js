var Fruit ={
    weight = 0,
    name : "name",
    type : "fruit",
    setweight: function(){
        this.weight=0;
    },
    setName : function (name){
        this.name=name;
    },
    setType : function(type){
        this.type = type;
    }, 
    getweight : function(){
        return this.weight;
    },
    getname : function(){
        return this.name;
    },getType : function(){
        return this.type;
    },
    
};


var tiny ={
    Shape : function(){
        return "small";
    },
};
var meduim ={
    Shape : function(){
        return "meduim";
    },
};var large ={
    Shape : function(){
        return "large";
    },
};var circular ={
    Shape : function(){
        return "circular";
    },
};var berry ={
    Shape : function(){
        return "berry";
    },
};var oval ={
    Shape : function(){
        return "oval";
    },
};



var orange = Object.create(Fruit);
(orange.setweight() = function() { 
    this.weight = 190;
}), 
orange.setweight();
orange.setName("orange");
orange.setType(meduim.Shape() +" "+ circular.Shape());

var apple = Object.create(Fruit);
(apple.setweight() = function() {
    this.weight = 150;
}),
apple.setweight();
apple.setName("apple");
apple.setType(meduim.Shape() +" "+ oval.Shape());
 
var grape = Object.create(Fruit);
(grape.setweight() = function() {
    this.weight =25 ;
}),
grape.setweight();
grape.setName("grape");
grape.setType(tiny.Shape() +" "+ circular.Shape());

var mango = Object.create(Fruit);
(mango.setweight() = function() {
    this.weight =200 ;
}),
mango.setweight();
mango.setName("mango");
mango.setType(meduim.Shape() +" "+ oval.Shape());

var watermelon = Object.create(Fruit);
(watermelon.setweight() = function() {
    this.weight = 7000;
}),
watermelon.setweight();
watermelon.setName("watermelon");
watermelon.setType(large.Shape() +" "+ circular.Shape());

var bear = Object.create(Fruit);
(bear.setweight() = function() {
    this.weight = 170;
}),
bear.setweight();
bear.setName("bear");
bear.setType(meduim.Shape() +" "+ oval.Shape());

var pineapple = Object.create(Fruit);
(pineapple.setweight() = function() {
        this.weight =2000 ;
}),
pineapple.setweight();
pineapple.setName("pineapple");
pineapple.setType(big.Shape() +" "+ oval.Shape()); 

var blueberries = Object.create(Fruit);
(blueberries.setweight() = function() {
    this.weight =20 ;
}),
blueberries.setweight();
blueberries.setName("blueberries");
blueberries.setType(tiny.Shape() +" "+ berry.Shape());

var gooseberries = Object.create(Fruit);
(gooseberries.setweight() = function() {
    this.weight =15 ;
}),
gooseberries.setweight();
gooseberries.setName("gooseberries");
gooseberries.setType(tiny.Shape() +" "+ berry.Shape());

var elderberries = Object.create(Fruit);
(elderberries.setweight() = function() {
    this.weight = 40;
}),
elderberries.setweight();
elderberries.setName("elderberries");
elderberries.setType(tiny.Shape() +" "+ berry.Shape());

var blackberries = Object.create(Fruit);
(blackberries.setweight() = function() {
    this.weight = 30;
}),
blackberries.setweight();
blackberries.setName("blackberries");
blackberries.setType(tiny.Shape() +" "+ berry.Shape());

var guava = Object.create(Fruit);
(guava.setweight() = function() {
    this.weight =130 ;
}),
guava.setweight();
guava.setName("guava");
guava.setType(meduim.Shape() +" "+ oval.Shape());

var banana = Object.create(Fruit);
(banana.setweight() = function() {
    this.weight = 110;
}),
banana.setweight();
banana.setName("banana");
banana.setType(meduim.Shape() +" "+ oval.Shape());

var strawberry = Object.create(Fruit);
(strawberry.setweight() = function() {
    this.weight = 70;
}),
strawberry.setweight();
strawberry.setName("strawberry");
strawberry.setType(tiny.Shape() +" "+ oval.Shape());


var BST = function (value) {
    var root = Object.create(BST.prototype);
    root.value = value ;
    root.right=undefined;
    root.left=undefined; 
    return root;
}; 

BST.prototype.display = function (x){
    console.log("\n"+"Name: "+x.value.getname() +"\n"+"Type: "+x.value.getType()+"\n"+"Weight: "+x.value.getweight());
};

BST.prototype.include = function (t){
    if (this.getType === t ){return true ;}
    else {return false;}
}


BST.prototype.insert = function(value){
    var newNode = BST(value);
    function place (n){
        if(n.value.weight < value.weight && n.right === undefined){
            n.right=newNode;
        }
        else if(n.value.weight<value.weight){
            place(n.right);
        }
        else if(n.value.weight > value.weight && n.left === undefined){
            n.left=newNode;
        }
        else if(n.value.weight>value.weight){
            place(n.left);
        }
    }
    place(this);
};

BST.prototype.inorder = function(fn) {
    function check(x){if(x===undefined) {return;} 
    check(x.left);
    fn(x);
    check(x.right);
    }
    check(this);  
};

BST.prototype.iterate = function(){
    this.inorder(it);
    function it(x){
        if (x===undefined){return;}
        BST.prototype.display(x);
    }
};

BST.prototype.filterByType = function(type){
    this.inorder(fType);
    function fType(x){
        if (x===undefined){return;}
        if(x.value.type.include(type)){
            BST.prototype.display(x);
        }
    }
};

BST.prototype.filterByWeight = function(weight){
    this.inorder(fWeight);
    function fWeight(x){
        if (x===undefined){return;}
        if(x.value.weight>weight ){
            BST.prototype.display(x);
        }
    }
};

BST.prototype.magnifyByType = function (type,weight){
    const fruits = [];
    this.inorder(magType);
    function magType(x){
        if (x===undefined) {return;}
        if (x.value.type.include(type)){
            var result = x.value.getweight() + weight;
            x.value.setweight(result);
        }
    fruits.push(x.value);
    }
    var y = BST(fruits[0]);
    for (i=1; i<fruits.length; i++){
        y.insert(fruits[i]);
    }
    return y ;
};

var rot =this;
BST.prototype.findHeaviest= function(){   
        if (rot === undefined){return;}
        if (rot.right === undefined){
            BST.prototype.display(rot);
        }
        else {rot=rot.right; 
          this.findHeaviest();}   
    }
;

var ret =this;
BST.prototype.findlightest= function(){   
        if (ret === undefined){return;}
        if (ret.left === undefined){
            BST.prototype.display(ret);
        }
        else {ret=ret.left; 
          this.findlightest();}   
    }
;

var x = BST(orange);
x.insert(apple);
x.insert(pineapple);
x.insert(watermelon);
x.insert(blackberries);
x.insert(bear);
x.insert(gooseberries);
x.insert(grape);
x.insert(guava);
x.insert(mango);
x.insert(banana);
x.insert(strawberry);

x.findHeaviest();
