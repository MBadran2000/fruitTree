import Fruits.Fruit

//singleton object without class
object Filter {
  //used by FruitsTree as delegate
  def filterWeight(fruitsTree: FruitsTree ,Weight:Int):FruitsTree={
    if(fruitsTree == null || fruitsTree.root == null)
      null
    else if (fruitsTree.root.getWeight()<=Weight){
      filterWeight(fruitsTree.right,Weight)
    }
    else{
      val fruitsTreeNew = new FruitsTree {
        override var root: Fruit = fruitsTree.root
        override var left: FruitsTree = filterWeight(fruitsTree.left,Weight)
        override var right: FruitsTree = fruitsTree.right
      }
      fruitsTreeNew
    }
  }

  def filterType(fruitsTree: FruitsTree ,Type:String):FruitsTree={
    if(fruitsTree == null || fruitsTree.root == null)
      null
    else if (fruitsTree.root.toString==Type){
      val fruitsTreeNew = new FruitsTree {
        override var root: Fruit = fruitsTree.root
        override var left: FruitsTree = filterType(fruitsTree.left,Type)
        override var right: FruitsTree = filterType(fruitsTree.right,Type)
      }
      fruitsTreeNew
    }
    else{
      val fruitsTreeLeft = filterType(fruitsTree.left,Type)
      val fruitsTreeRight = filterType(fruitsTree.right,Type)
      if(fruitsTreeLeft==null) {
        fruitsTreeRight
      } else if(fruitsTreeRight==null) {
        fruitsTreeLeft
      }
      else{
        var tree = fruitsTreeLeft
        while (tree.right!=null)
          tree = tree.right
        tree.right = fruitsTreeRight
        fruitsTreeLeft
      }
    }
  }
}
