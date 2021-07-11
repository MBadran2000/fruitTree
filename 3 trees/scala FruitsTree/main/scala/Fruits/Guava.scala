package Fruits

class Guava (weight:Int) extends Fruit {
  setWeight(weight)

  override def hiFromType(): Unit = println("hi from Guava, my weight: " + super.getWeight())

  override def toString(): String = "Guava"
}
