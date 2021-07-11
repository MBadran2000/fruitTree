package Fruits

class Grapes (weight:Int) extends TinyFruit {
  setWeight(weight)

  override def hiFromType(): Unit = println("hi from Grapes, my weight: " + super.getWeight())

  override def toString(): String = "Grapes"
}
