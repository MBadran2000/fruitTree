import Fruits._

//use case class to make copy of a trait or class with some additional features
//make copy easily and can be used in pattern matching to test different cases
case class fruitTreeCase(fruit: Fruit)extends FruitsTree {
  override var root: Fruit = fruit
  override var left: FruitsTree = null
  override var right: FruitsTree = null
}

object Demo {
  def main(args: Array[String]): Unit = {
    val ft = fruitTreeCase(new Apple(130))
    ft.insert(fruit = new Avocado(100))
    ft.insert(fruit = new Blackberries(40))
    ft.insert(fruit = new Avocado(400))
    ft.insert(fruit = new Banana(400))
    ft.insert(fruit = new Avocado(150))
    ft.insert(fruit = new Blackberries(70))
    ft.insert(fruit = new Apple(450))


    ft.Iterate()
    println("increase Avocado by 100")
    ft.magnifyByType("Avocado",100)
    ft.Iterate()
    println("Decrease Apple by 100")
    ft.magnifyByType("Apple",-100)
    ft.Iterate()
    println("find heavier than or equal to 150")
    ft.filterByWeight(150)
    println("find all apples")
    ft.filterByType("Apple")
    println("highest and lowest in tree")
    println(ft.findHeaviest().getWeight())
    println(ft.findLightest().getWeight())


  }
}