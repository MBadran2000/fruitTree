package Fruits

class Watermelon (weight:Int) extends LargeFruit {
  setWeight(weight)

  override def hiFromType(): Unit = println("hi from Watermelon, my weight: " + super.getWeight())

  override def toString(): String = "Watermelon"
}
