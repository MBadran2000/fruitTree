import Fruits._


//fruits Tree has a fruit root with 2 Trees 1 right and 1 left (to use recursion to help in functional programming)
trait FruitsTree {
    var root : Fruit
    var left : FruitsTree
    var right : FruitsTree

    //insert function return type unit (void in java)
    def insert(fruit: Fruit):Unit= root match {
        //****pattern matching****
        //pattern matching one of most used and useful features in scala
        case null=>
            root=fruit
        case _=>
            var tree = this
            while(tree!=null){
                if(tree.root>fruit) {
                    if(tree.left==null){
                        tree.left = new FruitsTree {
                            override var root: Fruit = fruit
                            override var left: FruitsTree = null
                            override var right: FruitsTree = null
                        }
                        tree = null
                    }
                    else {
                        tree = tree.left
                    }
                } else {
                    if(tree.right==null){
                        tree.right = new FruitsTree {
                            override var root: Fruit = fruit
                            override var left: FruitsTree = null
                            override var right: FruitsTree = null
                        }
                        tree = null
                    }
                    else {
                        tree = tree.right
                    }
                }
            }
    }

    //****Delegation****
    //Delegate filter functions to filter object
    val filter = Filter

    //****higher order functions****
    //function take parameter function
    def inorder (fruitsTree: FruitsTree = this , fun: Fruit=>Unit) :Unit = fruitsTree match {
        case null =>
        case _ => {
            inorder(fruitsTree.left,fun)
            fun(fruitsTree.root)
            inorder(fruitsTree.right,fun)
        }
    }

    //function to be given as parameters for other functions
    def printWeight(fruit: Fruit): Unit = println(fruit.getWeight()+" ")

    def addWeight(Weight:Int): Fruit=>Unit = {
        def fun(fruit: Fruit):Unit= fruit.setWeight(fruit.getWeight()+Weight)
        fun
    }

    ///function used after addWeight to reBalance the tree
    def fixTree(): Unit = {
        var newTree = new FruitsTree {
            override var root: Fruit = null
            override var left: FruitsTree = null
            override var right: FruitsTree = null
        }
        def insertInNew(fruit: Fruit):Unit= newTree.insert(fruit)
        newTree.inorder(this,insertInNew)
        this.root= newTree.root
        this.left= newTree.left
        this.right= newTree.right
    }

    //****higher order functions****
    //function is given as parameter

    //function required to implement
    def Iterate() : Unit = inorder(this,printWeight)

    def filterByType(Type:String) : Unit = inorder(filter.filterType(this,Type),printWeight)

    def filterByWeight(Weight:Int) : Unit = inorder(filter.filterWeight(this,  Weight),printWeight)

    def magnifyByType(Type:String, Weight:Int) :Unit = {
        inorder(filter.filterType(this,Type),addWeight(Weight))
        fixTree()
    }

    def findHeaviest() :Fruit= if(this.right==null) this.root else this.right.findHeaviest()

    def findLightest() :Fruit= if(this.left==null) this.root else this.left.findLightest()
}
