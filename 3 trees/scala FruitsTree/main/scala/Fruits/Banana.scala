package Fruits

class Banana (weight:Int) extends Fruit {
  setWeight(weight)

  override def hiFromType(): Unit = println("hi from Banana, my weight: " + super.getWeight())

  override def toString(): String = "Banana"
}
